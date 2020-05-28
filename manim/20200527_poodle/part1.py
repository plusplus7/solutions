from manimlib.imports import *
import random

ss = [1231231231,5645612456,7855566757, 13123123123]
class Polyline():
    def __init__(self, dots):
        self.lines = []
        for i in range(1, len(dots)):
            self.lines.append(Line([dots[i-1][0], dots[i-1][1], 0], [dots[i][0], dots[i][1], 0]))
    
    def play(self, scene):
        for line in self.lines:
            scene.play(GrowArrow(line))

def xor(x, y, radius=0.2):
    r1 = Circle(radius=radius)
    r1.move_arc_center_to([x,  y, 0.        ])
    rx1 = Line([x, y+radius, 0], [x, y-radius, 0])
    rx2 = Line([x-radius, y, 0], [x+radius, y, 0])
    return VGroup(r1, rx1, rx2)

def show_grid(self):
    for i in range(-10, 10):
        t = Line([i, 50, 0], [i, -50, 0])
        t.set_width(0.1)
        if (i+20)%2 == 1:
            t.set_color(RED)
        else:
            t.set_color(BLUE)
        self.add(t)

    for i in range(-10, 10):
        t = Line([50, i, 0], [-50, i, 0])
        if (i+20)%2 == 1:
            t.set_color(RED)
        else:
            t.set_color(BLUE)
        self.add(t)

def generate_plaintext_groups(n):
    rs = []
    for i in range(n):
        s = ss[i]#random.randint(10000000000, 100000000000)
        rs.append(TextMobject(hex(s)[2:10]))
        if i != 0:
            rs[i].next_to(rs[i-1], RIGHT*0.01)
    return rs

def generate_plaintext(n):
    return TextMobject(hex(ss[n])[2:10])

class S1(Scene):

    def construct(self):
        #show_grid(self)
        
        title = TextMobject("CBC mode encryption")
        title.to_edge(UP)
        self.add(title)

        plaintext = TextMobject("Plaintext ")
        plaintext.to_edge(UP)
        plaintext.shift(DOWN)
        plaintext.to_edge(LEFT)

        pts = VGroup(*generate_plaintext_groups(3))
        pts.next_to(plaintext)
        self.play(FadeIn(plaintext))
        self.wait(1)
        self.play(FadeIn(pts))
        self.wait(1)

        self.play(ApplyMethod(pts[0].shift, RIGHT)
                    ,(ApplyMethod(pts[1].shift, 3*RIGHT))
                    ,(ApplyMethod(pts[2].shift, 5*RIGHT)))
        self.wait(1)

        iv = TextMobject("Initialization Vectors")
        ivs = TextMobject("IV: ")
        ivs.to_edge(LEFT)
        ivs.shift([-0.1, 0.6, 0])
        self.play(FadeIn(iv))
        self.play(Transform(iv, ivs))
        ivss = generate_plaintext(3)
        ivss.next_to(ivs, RIGHT)
        self.play(FadeIn(ivss))

        

        xor1 = xor(-2.5, 0.5)
        xor2 = xor(1.4, 0.5)
        xor3 = xor(5.5, 0.5)

        rec1 = Rectangle(width=1.5, height=0.8)
        rec1.next_to(xor1, DOWN*4)
        rat1 = TextMobject("AES")
        rat1.shift([-2.5,-1.1,0])
        rec2 = Rectangle(width=1.5, height=0.8)
        rec2.next_to(xor2, DOWN*4)
        rat2 = TextMobject("AES")
        rat2.shift([1.45,-1.1,0])
        rec3 = Rectangle(width=1.5, height=0.8)
        rec3.next_to(xor3, DOWN*4)
        rat3 = TextMobject("AES")
        rat3.shift([5.5,-1.1,0])
        c1 = generate_plaintext(2)
        c1.next_to(rec1, DOWN*3)
        c1.to_edge(DOWN)
        c2 = generate_plaintext(2)
        c2.next_to(rec2, DOWN*3)
        c2.to_edge(DOWN)
        c3 = generate_plaintext(2)
        c3.next_to(rec3, DOWN*3)
        c3.to_edge(DOWN)

        l11 = Line(ivss, xor1)
        l12 = Line([-2.5, 2, 0], xor1)
        l13 = Line(xor1, [-2.5, -0.6, 0])
        l14 = Line([-2.5, -1.5, 0], [-2.5, -3, 0])

        self.play(GrowArrow(l11))
        self.play(GrowArrow(l12))
        self.add(xor1)
        self.wait(1)
        self.play(GrowArrow(l13))
        self.play(FadeIn(VGroup(rec1, rat1)))
        self.play(GrowArrow(l14))
        self.play(FadeIn(c1))

        pl21 = Polyline([[-1.5, -3.25], [-0.5, -3.25], [-0.5, 0.5], [1.2, 0.5]])
        pl21.play(self)
        l22 = Line([1.4, 2, 0], xor2)
        l23 = Line(xor2, [1.4, -0.6, 0])
        l24 = Line([1.4, -1.5, 0], [1.4, -3, 0])

        self.play(GrowArrow(l22))
        self.add(xor2)
        self.wait(1)
        self.play(GrowArrow(l23))
        self.play(FadeIn(VGroup(rec2, rat2)))
        self.play(GrowArrow(l24))
        self.play(FadeIn(c2))

        pl21 = Polyline([[2.5, -3.25], [3.5, -3.25], [3.5, 0.5], [5.3, 0.5]])
        pl21.play(self)

        l32 = Line([5.5, 2, 0], xor3)
        l33 = Line(xor3, [5.5, -0.6, 0])
        l34 = Line([5.5, -1.5, 0], [5.5, -3, 0])

        self.play(GrowArrow(l32))
        self.add(xor3)
        self.wait(1)
        self.play(GrowArrow(l33))
        self.play(FadeIn(VGroup(rec3, rat3)))
        self.play(GrowArrow(l34))
        self.play(FadeIn(c3))

        ciphertext = TextMobject("Ciphertext")
        ciphertext.to_edge(DOWN)
        ciphertext.to_edge(LEFT)
        ciphertext.shift([0, -0.125, 0])
        self.play(FadeIn(ciphertext))

        self.wait(10)

class S2(Scene):
    def construct(self):
        show_grid(self)

        title = TextMobject("ECB mode encryption")
        title.to_edge(UP)
        self.add(title)

        plaintext = TextMobject("Plaintext ")
        plaintext.to_edge(UP)
        plaintext.shift(DOWN)
        plaintext.to_edge(LEFT)

        pts = VGroup(*generate_plaintext_groups(3))
        pts.next_to(plaintext)
        self.play(FadeIn(plaintext))
        self.wait(1)
        self.play(FadeIn(pts))
        self.wait(1)

        self.play(ApplyMethod(pts[0].shift, RIGHT)
                    ,(ApplyMethod(pts[1].shift, 3*RIGHT))
                    ,(ApplyMethod(pts[2].shift, 5*RIGHT)))
        self.wait(1)
        recs = []
        for i in range(3):
            t = TextMobject("AES")
            t.bg = SurroundingRectangle(t,width=1.5, height=0.8, color=WHITE)
            recs.append(VGroup(t,t.bg))

        recs[0].shift([-2.5, 0, 0])
        recs[1].shift([1.5, 0, 0])
        recs[2].shift([5.5, 0, 0])

        self.play(GrowArrow(Line([-2.5, 2, 0], [-2.5, 0.5, 0])),
                    GrowArrow(Line([1.5, 2, 0], [1.5, 0.5, 0])),
                    GrowArrow(Line([5.5, 2, 0], [5.5, 0.5, 0])))
        self.play(FadeIn(recs[0]), FadeIn(recs[1]), FadeIn(recs[2]))


        ciphertext = TextMobject("Ciphertext ")
        ciphertext.to_edge(DOWN)
        ciphertext.shift(UP)
        ciphertext.to_edge(LEFT)
              
        cts = VGroup(*generate_plaintext_groups(3))
        cts.next_to(ciphertext)
        cts[0].shift(RIGHT)
        cts[1].shift(3*RIGHT)
        cts[2].shift(5*RIGHT)

        self.play(FadeIn(ciphertext))
        self.wait(1)

        self.play(GrowArrow(Line([-2.5, -0.5, 0], [-2.5, -2, 0])),
                    GrowArrow(Line([1.5, -0.5, 0], [1.5, -2, 0])),
                    GrowArrow(Line([5.5, -0.5, 0], [5.5, -2, 0])))
        self.play(FadeIn(cts[0]), FadeIn(cts[1]), FadeIn(cts[2]))
        self.wait(1)
        self.play(ApplyMethod(ciphertext.shift, DOWN)
                    ,(ApplyMethod(cts[0].shift, DOWN+LEFT))
                    ,(ApplyMethod(cts[1].shift, DOWN+3*LEFT))
                    ,(ApplyMethod(cts[2].shift, DOWN+5*LEFT)))

        self.wait(10)
            

class S15(Scene):
    def construct(self):
        show_grid(self)
        
        title = TextMobject("CBC mode decryption")
        title.to_edge(UP)
        self.add(title)

        ciphertext = TextMobject("Ciphertext")
        ciphertext.to_edge(UP)
        ciphertext.shift(DOWN)
        ciphertext.to_edge(LEFT)

        pts = VGroup(*generate_plaintext_groups(3))
        pts.next_to(ciphertext)
        self.play(FadeIn(ciphertext))
        self.wait(1)
        self.play(FadeIn(pts))
        self.wait(1)

        self.play(ApplyMethod(pts[0].move, [-2.5, 2.2, 0])
                    ,(ApplyMethod(pts[1].move, [1.5, 2.2, 0]))
                    ,(ApplyMethod(pts[2].move, [5.5, 2.2, 0])))
        self.wait(1)
        l11 = Line([-2.5, 2, 0], [-2.5, 1, 0])

        xor1 = xor(-2.5, -1)
        xor2 = xor(1.5, -1)
        xor3 = xor(5.5, -1)
        rec1 = Rectangle(width=1.5, height=0.8)
        rec1.shift([-2.5,0.5,0])
        rat1 = TextMobject("AES")
        rat1.shift([-2.5,0.5,0])
        self.play(FadeIn(VGroup(rec1, rat1)))
    
        
        self.play(GrowArrow(l11))

        rec2 = Rectangle(width=1.5, height=0.8)
        rec2.next_to(xor2, DOWN*4)
        rat2 = TextMobject("AES")
        rat2.shift([1.45,0.9,0])
        rec3 = Rectangle(width=1.5, height=0.8)
        rec3.next_to(xor3, DOWN*4)
        rat3 = TextMobject("AES")
        rat3.shift([5.5,0.9,0])

        iv = TextMobject("Initialization Vectors")
        ivs = TextMobject("IV: ")
        ivs.to_edge(LEFT)
        ivs.shift([-0.1, -0.6, 0])
        self.play(FadeIn(iv))
        self.play(Transform(iv, ivs))
        ivss = generate_plaintext(3)
        ivss.next_to(ivs, RIGHT)
        self.play(FadeIn(ivss))

        l12 = Line(ivss, xor1)
        l13 = Line([-2.5, -1.1, 0], xor1)
        c1 = generate_plaintext(2)
        c1.next_to(rec1, DOWN*3)
        c1.to_edge(DOWN)
        l14 = Line(xor1, c1)
        self.play(FadeIn(c1))
        """

        
        c2 = generate_plaintext(2)
        c2.next_to(rec2, DOWN*3)
        c2.to_edge(DOWN)
        c3 = generate_plaintext(2)
        c3.next_to(rec3, DOWN*3)
        c3.to_edge(DOWN)


        self.play(GrowArrow(l11))
        self.play(GrowArrow(l12))
        self.add(xor1)
        self.wait(1)
        self.play(GrowArrow(l13))
        self.play(FadeIn(VGroup(rec1, rat1)))
        self.play(GrowArrow(l14))

        pl21 = Polyline([[-1.5, -3.25], [-0.5, -3.25], [-0.5, 0.5], [1.2, 0.5]])
        pl21.play(self)
        l22 = Line([1.4, 2, 0], xor2)
        l23 = Line(xor2, [1.4, -0.6, 0])
        l24 = Line([1.4, -1.5, 0], [1.4, -3, 0])

        self.play(GrowArrow(l22))
        self.add(xor2)
        self.wait(1)
        self.play(GrowArrow(l23))
        self.play(FadeIn(VGroup(rec2, rat2)))
        self.play(GrowArrow(l24))
        self.play(FadeIn(c2))

        pl21 = Polyline([[2.5, -3.25], [3.5, -3.25], [3.5, 0.5], [5.3, 0.5]])
        pl21.play(self)

        l32 = Line([5.5, 2, 0], xor3)
        l33 = Line(xor3, [5.5, -0.6, 0])
        l34 = Line([5.5, -1.5, 0], [5.5, -3, 0])

        self.play(GrowArrow(l32))
        self.add(xor3)
        self.wait(1)
        self.play(GrowArrow(l33))
        self.play(FadeIn(VGroup(rec3, rat3)))
        self.play(GrowArrow(l34))
        self.play(FadeIn(c3))

        ciphertext = TextMobject("Ciphertext")
        ciphertext.to_edge(DOWN)
        ciphertext.to_edge(LEFT)
        ciphertext.shift([0, -0.125, 0])
        self.play(FadeIn(ciphertext))

        self.wait(10)
       """

        self.wait(10)

class S3(Scene):
    def construct(self):
        show_grid(self)

        title = TextMobject("Padding oracle attack on CBC encryption")
        title.to_edge(UP)
        self.add(title)