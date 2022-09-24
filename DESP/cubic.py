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

a3 = 27
write_text(0.1, 4.5, "a^3 = " + str(a3))

'''
x^3=a^3
x^3-a^3=0

(x-a)(x^2+ax+a^2)=0
x=a or x^2+ax+a^2=0

x^2+ax+a^2=0
(-a+-sqrt(a^2-4a^2)/2)
(-a+-sqrt(-3a^2)/2)

x = a or
x = -a-sqrt(-3a^2)/2 or
x = -a+sqrt(-3a^2)/2
'''
a = a3 ** (1/3) # real
b = (-a - cmath.sqrt(-3 * (a ** 2))) / 2 # imag -
c = (-a + cmath.sqrt(-3 * (a ** 2))) / 2 # imag +

draw_line(a.real, a.imag, b.real, b.imag)
draw_line(a.real, a.imag, c.real, c.imag)
draw_line(b.real, b.imag, c.real, c.imag)

# 두 점 사이의 거리 공식 이용
distance1 = get_distance(a.real, a.imag, b.real, b.imag)
distance2 = get_distance(a.real, a.imag, c.real, c.imag)
distance3 = get_distance(b.real, b.imag, c.real, c.imag)

# 컴퓨터는 소수점 저장 문제가 있으므로 5자리까지 식별
distance1 = round(distance1, 5)
distance2 = round(distance2, 5)
distance3 = round(distance3, 5)

# 정삼각형 판별
is_equilateral_triangle = distance1 == distance2 and distance2 == distance3 and distance3 == distance1
write_text(0.1, 4.4, "is equilateral triangle = " + str(is_equilateral_triangle))

if is_equilateral_triangle:
    S = (distance1 ** 2) * 3/4
    write_text(0.1, 4.3, "S = " + str(round(S, 2)))

t.done()