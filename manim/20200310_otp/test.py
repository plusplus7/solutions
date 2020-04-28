from manimlib.imports import *

class S1(Scene):
    def construct(self):
        t_password_cn = TextMobject("一次性密码")
        t_password_en = TextMobject("One Time Password")

        t_password_cn.scale(1.5)
        t_password_cn.next_to(t_password_en, UP)
        self.play(
            FadeIn(t_password_cn, run_time=3),
            Write(t_password_en, run_time=3),
        )
        self.wait(2)
        self.play(
            FadeOut(t_password_cn, run_time=3),
            FadeOut(t_password_en, run_time=3),
        )

        numbers = ["491823", "123955", "546347", "958191", "190150", "595821"]
        t_numbers = []
        for number in numbers:
            t_numbers.append(TextMobject(number))

        self.add(t_numbers[0])
        self.wait(2)
        for i in range(1, len(t_numbers)):
            self.play(Transform(t_numbers[0], t_numbers[i]))
            self.wait(2)

        self.wait(3)

class S2(Scene):
    def construct(self):
        t_otp = TextMobject("HOTP: HMAC-based One-time Password")
        t_otp.to_edge(UP)
        self.add(t_otp)
        t_hmac_full = TextMobject("hash-based message authentication code")
        t_hmac_full.scale(0.85)
        t_hmac_short = TextMobject("HMAC")
        t_hmac_short.scale(0.85)
        t_hmac_full.to_edge(UP)
        t_hmac_short.to_edge(UP)
        t_hmac_full.shift(DOWN)
        t_hmac_short.shift(DOWN)

        t_hmac_equal = TextMobject("=")
        t_hmac_equal.scale(0.85)
        t_hmac_formula_left = TextMobject("(Secret Key, Counter)",
            tex_to_color_map={"Secret Key": RED, "Counter": YELLOW}
        )
        t_hmac_formula_left.scale(0.85)

        self.wait(2)
        self.add(t_hmac_full)
        self.wait(3)
        self.play(Transform(t_hmac_full, t_hmac_short))
        self.wait(1)
        self.play(ApplyMethod(t_hmac_full.to_edge, LEFT))
        t_hmac_formula_left.next_to(t_hmac_full)
        t_hmac_equal.next_to(t_hmac_formula_left)
        self.play(FadeIn(t_hmac_formula_left))
        self.wait(1)
        self.play(FadeIn(t_hmac_equal))
        self.wait(1)

        import hmac
        import hashlib
        hasher = hmac.new(b"plusplus7", b"plusplus7", hashlib.sha1)
        hash_bytes = bytearray(hasher.digest())
        hash_bytebin_rawstr = ""
        for i in hash_bytes:
            hash_bytebin_rawstr = hash_bytebin_rawstr + hex(i)[2:]
        t_hash_bytebin_rawstr = TextMobject(hash_bytebin_rawstr)
        t_hash_bytebin_rawstr.scale(0.85)

        t_hash_bytebin = []
        for i in hash_bytes:
            t_hash_bytebin_str = TextMobject(hex(i)[2:])
            t_hash_bytebin_str.scale(0.85)
            t_hash_bytebin.append(t_hash_bytebin_str)

        #t_index = TextMobject(hex(hash_bytes[-1])[2:])
        #t_index.scale(0.85)
        #t_index.set_color(RED)

        t_hash_bytebin[0].to_edge(LEFT)
        t_hash_bytebin[0].shift(1.5* UP)

        t_hash_bytebin_rawstr.shift(1.5*UP)

        for i in range(1, len(t_hash_bytebin)):
            t_hash_bytebin[i].next_to(t_hash_bytebin[i-1], 0.5*RIGHT)

        self.add(t_hash_bytebin_rawstr)
        self.wait(2)
        self.play(Transform(t_hash_bytebin_rawstr, VGroup(*t_hash_bytebin)))
        self.add(VGroup(*t_hash_bytebin))
        self.remove(t_hash_bytebin_rawstr)

        self.play(ApplyMethod(t_hash_bytebin[-1].shift, 2*DOWN))
        self.wait(0.5)
        self.play(ApplyMethod(t_hash_bytebin[-1].shift, 9*LEFT))
        self.wait(0.5)
#        self.play(ApplyMethod(VGroup(*t_hash_bytebin[:-1]).shift, 1.5*RIGHT))

#        self.play(ApplyMethod(t_hash_bytebin[-1].shift, UP+RIGHT))
        self.wait(1)
 #       t_index.next_to(t_hash_bytebin[-1], 4*DOWN)
        t_index = t_hash_bytebin[-1].copy()
        t_index.set_color(RED)
 #       a_arrow = Arrow(t_hash_bytebin[-1].get_bottom(), t_index.get_top())
 #       self.play(GrowArrow(a_arrow))
 #       self.wait(1)
 #       self.play(FadeIn(t_index))
 #       self.wait(1)

        t_ord_right = TextMobject(" \& 0f = ")
        t_ord_right.scale(0.85)
        t_ord_result = TextMobject(str(hash_bytes[-1]&(0xf)))
        t_ord_result.scale(0.85)

        t_ord_right.next_to(t_index, RIGHT)
        t_ord_result.next_to(t_ord_right, RIGHT)

        self.play(FadeIn(t_ord_right))
        self.wait(0.5)
        self.play(FadeIn(t_ord_result))
        self.wait(0.5)
        
        t_ord_comma = TextMobject(":")
        t_ord_comma.next_to(t_ord_result, RIGHT)
        self.play(FadeIn(t_ord_comma))
        self.wait(0.5)

        offset = hash_bytes[-1]&(0xf)
        t_codes = []
        t_codes_arrow = []
        codes = ""
        for i in range(4):
            mob = TextMobject(str(hex(hash_bytes[offset+i])[2:]))
            mob.scale(0.85)
            codes = codes + str(hex(hash_bytes[offset+i])[2:])
            if i == 0:
                mob.next_to(t_ord_comma, 0.5*RIGHT)
            else:
                mob.next_to(t_codes[i-1], 0.5*RIGHT)

            t_codes.append(mob)
            t_codes_arrow.append(Arrow(t_hash_bytebin[offset+i].get_bottom(), mob.get_top()))

        for i in range(4):
            self.play(GrowArrow(t_codes_arrow[i]))
            self.add(t_codes[i])
            self.wait(0.5)

        t_ord_codes = TextMobject(codes)
        t_ord_codes.scale(0.85)
        t_ord_codes_right = TextMobject("\& 7fffffff=")
        t_ord_codes_right.scale(0.85)
        t_ord_codes_ord = TextMobject(str(int(codes, 16)&0x7fffffff))
        t_ord_codes_ord.scale(0.85)

        t_ord_codes.next_to(t_codes[1], 4*DOWN)
        t_ord_codes_arrow = Arrow(t_codes[1].get_bottom(), t_ord_codes.get_top())
        self.play(GrowArrow(t_ord_codes_arrow))
        self.play(FadeIn(t_ord_codes))
        self.wait(0.5)
        t_ord_codes_right.next_to(t_ord_codes, 0.5*RIGHT)
        self.play(FadeIn(t_ord_codes_right))

        t_ord_codes_ord.next_to(t_ord_codes_right, RIGHT)
        self.play(FadeIn(t_ord_codes_ord))

        t_dec_codes = TextMobject(str(int(codes, 16)&0x7fffffff))
        t_dec_codes.scale(0.85)
        t_dec_codes.next_to(t_ord_codes_ord, 4*DOWN)
        t_dec_codes_mod = TextMobject("\%")
        t_dec_codes_mod.scale(0.85)
        t_dec_codes_mod.next_to(t_dec_codes, RIGHT)
        t_dec_codes_right = TexMobject("10^6")
        t_dec_codes_right.scale(0.85)
        t_dec_codes_right.next_to(t_dec_codes_mod, RIGHT)
        t_dec_codes_equal = TextMobject("=")
        t_dec_codes_equal.scale(0.85)
        t_dec_codes_equal.next_to(t_dec_codes_right, RIGHT)
        t_dec_codes_result = TextMobject("%06d" % ((int(codes, 16)&0x7fffffff)%1000000))
        t_dec_codes_result.scale(0.85)
        t_dec_codes_result.next_to(t_dec_codes_equal, RIGHT)

        t_ord_codes_arrow = Arrow(t_ord_codes_ord.get_bottom(), t_dec_codes.get_top())
        self.play(GrowArrow(t_ord_codes_arrow))

        self.play(FadeIn(t_dec_codes))
        self.play(FadeIn(t_dec_codes_mod))
        self.play(FadeIn(t_dec_codes_right))
        self.play(FadeIn(t_dec_codes_equal))
        self.play(FadeIn(t_dec_codes_result))
        self.wait(3)

