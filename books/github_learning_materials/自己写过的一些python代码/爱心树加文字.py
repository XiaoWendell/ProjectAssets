# coding=gbk
"""
���ߣ�����
���ںţ���ת������
@ʱ��  : 2022/2/3 0:47
Ⱥ��428335755
"""
import turtle
import random

def love(x, y):  # ��(x,y)��������lalala
    lv = turtle.Turtle()
    lv.hideturtle()
    lv.up()
    lv.goto(x, y)  # ��λ��(x,y)

    def curvemove():  # ��Բ��
        for i in range(20):
            lv.right(10)
            lv.forward(2)

    lv.color('red', 'pink')
    lv.speed(10000000)
    lv.pensize(1)
    # ��ʼ������lalala
    lv.down()
    lv.begin_fill()
    lv.left(140)
    lv.forward(22)
    curvemove()
    lv.left(120)
    curvemove()
    lv.forward(22)
    lv.write("˼˼", font=("Arial", 12, "normal"), align="center")  # д�ϱ�׵��˵�����
    lv.left(140)  # ���긴λ
    lv.end_fill()


def tree(branchLen, t):
    if branchLen > 5:  # ʣ����֦̫��Ҫ�����ݹ�
        if branchLen < 20:  # �����֦ʣ�೤�Ƚ϶������
            t.color("green")
            t.pensize(random.uniform((branchLen + 5) / 4 - 2, (branchLen + 6) / 4 + 5))
            t.down()
            t.forward(branchLen)
            love(t.xcor(), t.ycor())  # ��������turtle������
            t.up()
            t.backward(branchLen)
            t.color("brown")
            return
        t.pensize(random.uniform((branchLen + 5) / 4 - 2, (branchLen + 6) / 4 + 5))
        t.down()
        t.forward(branchLen)
        # ���µݹ�
        ang = random.uniform(15, 45)
        t.right(ang)
        tree(branchLen - random.uniform(12, 16), t)  # ���������С����
        t.left(2 * ang)
        tree(branchLen - random.uniform(12, 16), t)  # ���������С����
        t.right(ang)
        t.up()
        t.backward(branchLen)

myWin = turtle.Screen()
t = turtle.Turtle()
t.hideturtle()
t.speed(1000)
t.left(90)
t.up()
t.backward(200)
t.down()
t.color("brown")
t.pensize(32)
t.forward(60)
tree(100, t)
myWin.exitonclick()