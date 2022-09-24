import turtle as t
import cmath
import math

# 직선 그리기
def draw_line(x1, y1, x2, y2):
    # (1, 1) 이라면 좌표는 (100, 100)
    t.up()
    t.goto(x1 * 100, y1 * 100)
    t.down()
    t.goto(x2 * 100, y2 * 100)

# 텍스트 쓰기
def write_text(x, y, text):
    t.up()
    t.goto(x * 100, y * 100)
    t.down()
    t.write(text)

# 좌표축 그리기
def draw_axis():
    draw_line(-5, 0, 5, 0)
    draw_line(0, -5, 0, 5)

# 눈금 그리기
def draw_scale():
    i = -5

    while i <= 5:
        draw_line(i, -0.05, i, 0.05)
        draw_line(-0.05, i, 0.05, i)

        if i != 0:
            write_text(i-0.1, -0.2, i)
            write_text(0.07, i-0.05, i)

        i += 1

# 두 점 사이의 거리 공식
def get_distance(x1, y1, x2, y2):
    return math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)

t.speed(0)
t.hideturtle()

draw_axis()
draw_scale()



t.done()