# coding=gbk
"""
���ߣ�����
���ںţ���ת������
@ʱ��  : 2022/2/3 2:10
Ⱥ��428335755
"""
import os


def test_cmd():
    radio_list = ["https://www.bilibili.com/video/BV1EW411G7hp?from=search&seid=17441052249913049501",
                  ]#�Զ�����Ƶ����

    for i in range(len(radio_list)):
        try:
            show_cmd = "you-get -i " + radio_list[i]
            print(show_cmd)
            os.system(show_cmd)
            print("��ʼ���أ�" + radio_list[i])

            download_cmd = "you-get --format=flv " + radio_list[i]
            print(download_cmd)
            res = os.system(download_cmd)
            print(res)
            print(radio_list[i] + "�������")
        except Exception:
            print("��" + str(i) + "����Ƶ���س����˴���")
            print("�����ǣ�" + radio_list[i])


if __name__ == '__main__':
    test_cmd()

