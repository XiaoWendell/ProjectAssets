# coding=gbk
"""
���ߣ�����
���ںţ���ת������
@ʱ��  : 2022/2/3 0:35
Ⱥ��428335755
"""
from pynput.mouse import Button, Controller
from pynput.keyboard import Key, Controller
import time

def input(content):

    keyboard = Controller()  # ��ʼ���Ƽ���
    keyboard.type(content)  # content
    # �س�����������Ϣ������ͻس�ֻ��ѡһ�֣���ֹ��������
    keyboard.press(Key.enter)


# �����winϵͳ������ѡ��ʹ�õ�����ܣ��������д���������ڷ��Ͱ�ť�ϣ�
def click():  # ���������Ϣ
    # ������Ӧ�Ŀ�
    mouse = Controller()  # ��ʼ�������
    mouse.press(Button.left)  # ��ס������
    mouse.release(Button.left)  # �ſ�������


# number��ʾ��Ҫ����������Ϣ��content��ʾ���͵�����
def main(number, content):
    # ��ʱ��ͣ5s������������촰���������ͣ���ڷ��Ͱ�ť��
    time.sleep(5)
    for i in range(number):  # ��ѭ���������㷢�Ͷ�������Ϣ
        input(content+str(i))
        # ͨ�������ť������
        # click()
        # ���ʱ��
        time.sleep(0.6)


if __name__ == '__main__':
    main(100, "��ը�����ˣ����䣡����")
