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

