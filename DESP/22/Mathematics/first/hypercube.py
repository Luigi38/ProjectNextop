import turtle as t
import math
import cmath

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

a4 = 16
write_text(0.1, 4.5, "a^4 = " + str(a4))

'''
x^4=a^4
t=x^2

t^2=a^4
t=+-a^2
x^2=+-a^2

x^2=-a^2) x=+-ai
x^2=a^2) x=+-a
'''

t_1 = cmath.sqrt(a4)
t_2 = -cmath.sqrt(a4)

a = cmath.sqrt(t_1) # real +
b = -cmath.sqrt(t_1) # real -
c = cmath.sqrt(t_2) # imag +
d = -cmath.sqrt(t_2) # imag -

draw_line(a.real, a.imag, c.real, c.imag)
draw_line(c.real, c.imag, b.real, b.imag)
draw_line(b.real, b.imag, d.real, d.imag)
draw_line(d.real, d.imag, a.real, a.imag)

# 두 점 사이의 거리 공식 이용
distance1 = get_distance(a.real, a.imag, c.real, c.imag)
distance2 = get_distance(c.real, c.imag, b.real, b.imag)
distance3 = get_distance(b.real, b.imag, d.real, d.imag)
distance4 = get_distance(d.real, d.imag, a.real, a.imag)

# 컴퓨터는 소수점 저장 문제가 있으므로 5자리까지 식별
distance1 = round(distance1, 5)
distance2 = round(distance2, 5)
distance3 = round(distance3, 5)
distance4 = round(distance4, 5)

# 정사각형 판별
is_square = distance1 == distance2 and distance2 == distance3 and distance3 == distance4 and distance4 == distance1
write_text(0.1, 4.4, "is square = " + str(is_square))

if is_square:
    S = distance1 ** 2
    write_text(0.1, 4.3, "S = " + str(round(S, 2)))

t.done()