from manimlib.imports import *

ss = [1231231231,5645612456,7855566757, 13123123123]
class Polyline():
    def __init__(self, dots):
        self.lines = []
        for i in range(1, len(dots)):
            self.lines.append(Line([dots[i-1][0], dots[i-1][1], 0], [dots[i][0], dots[i][1], 0]))
    
    def play(self, scene):
        for line in self.lines:
            scene.play(GrowArrow(line))

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

def p3(x, y):
    return [x, y, 0]

def gline(x1, y1, x2, y2):
    return Line([x1, y1, 0], [x2, y2, 0])

class S1(Scene):

    def construct(self):
        show_grid(self)

        def desktop(x, y):
            pc = SVGMobject("desktop")
            pc.scale(0.5)
            pc.move_to(p3(x, y))
            return pc
            
        pca = desktop(-6, 3)
        pcb = desktop(-6, -2)
        pcs = desktop(6, -1)
        pcs.set_color(BLUE)
        pcc = desktop(-4.5, 0.5)
        pcc.set_color(BLUE)

        def router(x, y):
            r = SVGMobject("router")
            r.move_to(p3(x, y))
            r.scale(0.5)
            return r

        r1 = router(-1, 2)
        r2 = router(-0.5, -1.5)
        r3 = router(2, 3)
        r4 = router(2.25, -2)
        r5 = router(3.5, -0.5)
        rs = VGroup(r1, r2, r3, r4, r5)

        def cloud(x, y):
            c = SVGMobject("cloud")
            c.move_to(p3(x, y))
            c.scale(0.4)
            return c

        c1 = cloud(0.75, 2)
        c2 = cloud(-1.5, 0)
        c3 = cloud(2.5, 1)
        c4 = cloud(1, -1)
        c5 = cloud(-3.5, 2.5)
        c6 = cloud(-3.5, -2.5)
        cs = VGroup(c1, c2, c3, c4)
        csp = VGroup(c5, c6)

        cc = Circle(radius=3.3)
        cc.set_color(WHITE)
        cc.move_to(p3(1, 0.5))

        self.play(Write(rs), FadeIn(cc), FadeIn(cs))

        lr = []
        lr.append(Line(pca, c5))
        lr.append(Line(pcb, c6))
        lr.append(Line(c5, r1))
        lr.append(Line(c6, r2))
        lr.append(Line(c1, r1))
        lr.append(Line(c1, r3))
        lr.append(Line(c3, r3))
        lr.append(Line(c3, r5))
        lr.append(Line(c2, r2))
        lr.append(Line(c4, r2))
        lr.append(Line(c4, r4))
        lr.append(Line(c3, r4))
        lr.append(Line(c2, r1))

        lat1 = TextMobject("延迟 > 300 ms")
        lat1.scale(0.6)
        lat1.set_color(RED)
        lat1.move_to(p3(6, -3))
        lat2 = TextMobject("延迟 < 50 ms")
        lat2.scale(0.6)
        lat2.set_color(GREEN)
        lat2.move_to(p3(-5.5, -3.5))

        pcst = TextMobject("游戏服务器")
        pcstex = TextMobject("(海外)")
        pcst.scale(0.6)
        pcstex.scale(0.6)
        pcst.move_to(p3(6, -1.75))
        pcstex.next_to(pcst, DOWN)
        pcat = TextMobject("主机A")
        pcat.scale(0.6)
        pcat.move_to(p3(-6, 2.25))
        pcbt = TextMobject("主机B")
        pcbt.scale(0.6)
        pcbt.move_to(p3(-6, -2.75))

        internet = TextMobject("因特网")
        internet.move_to(p3(1, 0.75))

        self.play(
            GrowArrow(lr[4]),GrowArrow(lr[5]),GrowArrow(lr[6]), GrowArrow(lr[7]),GrowArrow(lr[8]),GrowArrow(lr[9]),GrowArrow(lr[10]), GrowArrow(lr[11]),
            GrowArrow(lr[12]),
            GrowArrow(Line(c4, r1))
            )
        self.play(FadeIn(internet))

        self.play(Write(pca), Write(pcb))
        self.play(FadeIn(pcat), FadeIn(pcbt))
        self.play(FadeIn(csp))
        self.play(GrowArrow(lr[0]),
                  GrowArrow(lr[1]))
        self.play(GrowArrow(lr[2]),
                  GrowArrow(lr[3]))
        self.play(Write(pcs))
        self.play(FadeIn(pcst), FadeIn(pcstex))
        lr.append(Line(pcs, r5))
        self.play(GrowArrow(lr[13]))
        for i in range(5):
            self.play(
                    ApplyMethod(lr[0].set_color, RED), ApplyMethod(lr[1].set_color, RED), ApplyMethod(lr[2].set_color, RED),
                    ApplyMethod(lr[3].set_color, RED), ApplyMethod(lr[4].set_color, RED), ApplyMethod(lr[5].set_color, RED),
                    ApplyMethod(lr[6].set_color, RED), ApplyMethod(lr[7].set_color, RED), ApplyMethod(lr[8].set_color, RED),
                    ApplyMethod(lr[9].set_color, RED), ApplyMethod(lr[10].set_color, RED), ApplyMethod(lr[11].set_color, RED),
                    ApplyMethod(lr[13].set_color, RED)
            )
            if i == 3:
                self.play(FadeIn(lat1))
            self.play(
                    ApplyMethod(lr[0].set_color, WHITE), ApplyMethod(lr[1].set_color, WHITE), ApplyMethod(lr[2].set_color, WHITE),
                    ApplyMethod(lr[3].set_color, WHITE), ApplyMethod(lr[4].set_color, WHITE), ApplyMethod(lr[5].set_color, WHITE),
                    ApplyMethod(lr[6].set_color, WHITE), ApplyMethod(lr[7].set_color, WHITE), ApplyMethod(lr[8].set_color, WHITE),
                    ApplyMethod(lr[9].set_color, WHITE), ApplyMethod(lr[10].set_color, WHITE), ApplyMethod(lr[11].set_color, WHITE),
                    ApplyMethod(lr[13].set_color, WHITE)
            )
        

        self.wait(1)
        self.play(FadeOut(lat1))
        self.play(FadeOut(pcst), FadeOut(pcstex))
        self.play(FadeOut(pcs), FadeOut(lr[13]))

        self.wait(3)

        lr.append(Line(pcc, c2))
        self.play(FadeIn(pcc))
        self.play(GrowArrow(lr[14]))

        for i in range(5):
            self.play(
                ApplyMethod(lr[0].set_color, GREEN), ApplyMethod(lr[1].set_color, GREEN), ApplyMethod(lr[2].set_color, GREEN),
                ApplyMethod(lr[3].set_color, GREEN), ApplyMethod(lr[14].set_color, GREEN),
                ApplyMethod(lr[12].set_color, GREEN), ApplyMethod(lr[8].set_color, GREEN)
            )
            if i == 3:
                self.play(FadeIn(lat2))
            self.play(
                ApplyMethod(lr[0].set_color, WHITE), ApplyMethod(lr[1].set_color, WHITE), ApplyMethod(lr[2].set_color, WHITE),
                ApplyMethod(lr[3].set_color, WHITE), ApplyMethod(lr[14].set_color, WHITE),
                ApplyMethod(lr[12].set_color, WHITE), ApplyMethod(lr[8].set_color, WHITE)
            )

        self.wait(1)
        self.play(FadeOut(lat2))
        self.wait(5)


class S2(Scene):

    def construct(self):
        #show_grid(self)

        def desktop(x, y):
            pc = SVGMobject("desktop")
            pc.move_to(p3(x, y))
            return pc
            
        pcs = desktop(0,3)
        pcs.set_color(BLUE)
        def rectangle(w, h, c=BLACK, text=None, o=1):
            rect = Rectangle(
                width=w,
                height=h,
                fill_color=c,
                fill_opacity=o,
            )
            if text == None:
                return rect
            t = TextMobject(text)
            t.set_color(BLACK)
            return VGroup(rect, t)

        rec1 = rectangle(5.25, 4, o=0)
        rec2 = rectangle(5.25, 4, o=0)
        rec1.move_to(p3(-3.5, -1))
        rec2.move_to(p3(3.5, -1))
        r10 = rectangle(3.5, 0.75, text="N2N/Edge", c=WHITE)
        r11 = rectangle(3.5, 0.75, text="TAP设备", c=BLUE)
        r12 = rectangle(3.5, 0.75, text="应用", c=GOLD)
        r20 = rectangle(3.5, 0.75, text="N2N/Edge", c=WHITE)
        r21 = rectangle(3.5, 0.75, text="TAP设备", c=BLUE)
        r22 = rectangle(3.5, 0.75, text="应用", c=GOLD)
        ts = TextMobject("N2N 核心节点")
        ts.scale(0.7)
        ts.move_to(p3(0,1.7))
        
#        r10 = rectangle(3.5, 0.75, text="N2N/Edge", c=WHITE)
#        r11 = rectangle(3.5, 0.75, text="TAP device", c=BLUE)
#        r12 = rectangle(3.5, 0.75, text="Application", c=GOLD)
#        r20 = rectangle(3.5, 0.75, text="N2N/Edge", c=WHITE)
#        r21 = rectangle(3.5, 0.75, text="TAP device", c=BLUE)
#        r22 = rectangle(3.5, 0.75, text="Application", c=GOLD)
        r10.move_to(p3(-3.5, 0.4))
        r11.move_to(p3(-3.5, -1.0))
        r12.move_to(p3(-3.5, -2.4))
        r20.move_to(p3(3.5, 0.4))
        r21.move_to(p3(3.5, -1.))
        r22.move_to(p3(3.5, -2.4))

        self.play(FadeIn(pcs), FadeIn(ts))
        self.play(FadeIn(rec1), FadeIn(rec2))
        self.play(FadeIn(r10), FadeIn(r20))
        self.play(FadeIn(r11), FadeIn(r21))
        self.play(FadeIn(r12), FadeIn(r22))

        self.play(GrowArrow(Arrow(p3(-4.5,-2.25), p3(-4.5, -1.10))))
        self.wait(1)
        self.play(GrowArrow(Arrow(p3(-4.5, -0.85), p3(-4.5, 0.25))))
        self.wait(1)
        self.play(GrowArrow(Arrow(p3(-3.5,0.6), pcs)))
        self.wait(1)
        self.play(GrowArrow(Arrow(pcs, p3(3.5,0.6))))
        self.wait(1)
        self.play(GrowArrow(Arrow(p3(4.5, 0.25), p3(4.5,-0.85))))
        self.wait(1)
        self.play(GrowArrow(Arrow(p3(4.5, -1.10), p3(4.5,-2.2))))
        self.wait(1)

        self.play(GrowArrow(Arrow(p3(2.5, -2.25), p3(2.5, -1.10))))
        self.wait(1)
        self.play(GrowArrow(Arrow(p3(2.5, -0.85), p3(2.5, 0.25))))
        self.wait(1)
        self.play(GrowArrow(Arrow(p3(4.5,0.6), p3(2, 2.5))))
        self.wait(1)
        self.play(GrowArrow(Arrow(p3(-2, 2.5), p3(-4.5,0.6))))
        self.wait(1)
        self.play(GrowArrow(Arrow(p3(-2.5,0.25), p3(-2.5, -0.85))))
        self.wait(1)
        self.play(GrowArrow(Arrow(p3(-2.5,-1.10), p3(-2.5, -2.2))))
        self.wait(1)

        self.play(GrowArrow(Arrow(p3(1.45, -0.85), p3(1.75, -0.85))), GrowArrow(DashedLine(p3(-1.75,-0.85), p3(1.75, -0.85))))
        self.play(GrowArrow(Arrow(p3(-1.45, -1.15), p3(-1.75,-1.15))), GrowArrow(DashedLine(p3(1.75, -1.15), p3(-1.75,-1.15))))
        self.wait(1)