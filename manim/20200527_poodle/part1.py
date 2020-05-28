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

        
class S1(Scene):
    def generate_plaintext(self, n):
        return TextMobject(hex(ss[n])[2:10])

    def generate_plaintext_groups(self, n):
        rs = []
        for i in range(n):
            s = ss[i]#random.randint(10000000000, 100000000000)
            rs.append(TextMobject(hex(s)[2:10]))
            if i != 0:
                rs[i].next_to(rs[i-1], RIGHT*0.01)
        return rs

    def showGrid(self):
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

    def construct(self):
        self.showGrid()
        
        title = TextMobject("CBC mode encryption")
        title.to_edge(UP)
        self.add(title)

        plaintext = TextMobject("Plaintext ")
        plaintext.to_edge(UP)
        plaintext.shift(DOWN)
        plaintext.to_edge(LEFT)

        pts = VGroup(*self.generate_plaintext_groups(3))
        pts.next_to(plaintext)
        self.play(FadeIn(plaintext))
        self.wait(1)
        self.play(FadeIn(pts))
        self.wait(1)
        self.play(ApplyMethod(plaintext.shift, DOWN))
        self.play(ApplyMethod(pts[0].shift, DOWN + RIGHT))
        self.play(ApplyMethod(pts[1].shift, DOWN + 3*RIGHT))
        self.play(ApplyMethod(pts[2].shift, DOWN + 5*RIGHT))
        self.wait(1)

        iv = TextMobject("Initialization Vectors")
        ivs = TextMobject("IV: ")
        ivs.next_to(pts[0], DOWN)
        ivs.to_edge(LEFT)
        self.play(FadeIn(iv))
        self.play(Transform(iv, ivs))
        ivss = self.generate_plaintext(3)
        ivss.next_to(ivs, RIGHT)
        ivss.to_edge(LEFT)
        self.play(FadeIn(ivss))

        def xor(x, y, radius=0.2):
            r1 = Circle(radius=radius)
            r1.move_arc_center_to([x,  y, 0.        ])
            rx1 = Line([x, y+radius, 0], [x, y-radius, 0])
            rx2 = Line([x-radius, y, 0], [x-radius, y, 0])
            return VGroup(r1, rx1, rx2)

        xor1 = xor(-2.5, 0)
        xor2 = xor(1.4, 0)
        xor3 = xor(5.5, 0)

        rec1 = Rectangle(width=1.5, height=0.8)
        rec1.next_to(xor1, DOWN*3)
        rat1 = TextMobject("AES")
        rat1.shift([-2.5,-1.3,0])
        rec2 = Rectangle(width=1.5, height=0.8)
        rec2.next_to(xor2, DOWN*3)
        rat2 = TextMobject("AES")
        rat2.shift([1.45,-1.3,0])
        rec3 = Rectangle(width=1.5, height=0.8)
        rec3.next_to(xor3, DOWN*3)
        rat3 = TextMobject("AES")
        rat3.shift([5.5,-1.3,0])
        c1 = self.generate_plaintext(2)
        c1.next_to(rec1, DOWN*3)
        c1.to_edge(DOWN)
        c2 = self.generate_plaintext(2)
        c2.next_to(rec2, DOWN*3)
        c2.to_edge(DOWN)
        c3 = self.generate_plaintext(2)
        c3.next_to(rec3, DOWN*3)
        c3.to_edge(DOWN)

        l11 = Line(ivss, xor1)
        l12 = Line([-2.5, 1, 0], xor1)
        l13 = Line(xor1, [-2.5, -0.95, 0])
        l14 = Line([-2.5, -1.85, 0], [-2.5, -3, 0])

        self.play(GrowArrow(l11))
        self.play(GrowArrow(l12))
        self.add(xor1)
        self.wait(1)
        self.play(GrowArrow(l13))
        self.play(FadeIn(VGroup(rec1, rat1)))
        self.play(GrowArrow(l14))
        self.play(FadeIn(c1))

        pl21 = Polyline([[-1.5, -3.25], [-0.5, -3.25], [-0.5, 0], [1.2, 0]])
        pl21.play(self)
        l22 = Line([1.4, 1, 0], xor2)
        l23 = Line(xor2, [1.4, -0.95, 0])
        l24 = Line([1.4, -1.85, 0], [1.4, -3, 0])

        self.play(GrowArrow(l22))
        self.add(xor2)
        self.wait(1)
        self.play(GrowArrow(l23))
        self.play(FadeIn(VGroup(rec2, rat2)))
        self.play(GrowArrow(l24))
        self.play(FadeIn(c2))

        pl21 = Polyline([[2.5, -3.25], [3.5, -3.25], [3.5, 0], [5.3, 0]])
        pl21.play(self)

        l32 = Line([5.5, 1, 0], xor3)
        l33 = Line(xor3, [5.5, -0.95, 0])
        l34 = Line([5.5, -1.85, 0], [5.5, -3, 0])

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
