## coding=gbk
"""
���ߣ�����
���ںţ���ת������
@ʱ��  : 2022/2/3 0:47
Ⱥ��428335755
"""
import time
import threading
import requests

def test1(arg1):
    # print("��������1")
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/63.0.3239.132 Safari/537.36 QIHU 360SE'
    }

    url = 'https://api.iyk0.com/chp/'
    resp = requests.get(url=url, headers=headers).json()
    bo = resp['txt']
    with open('4.txt', 'a') as f:
        f.write('\n' + bo)
    time.sleep(2)
    # print("��������1")

def test2(arg2):
    # print("��������2")
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/63.0.3239.132 Safari/537.36 QIHU 360SE'
    }

    url = 'https://api.iyk0.com/chp/'
    resp = requests.get(url=url, headers=headers).json()
    bo = resp['txt']
    with open('4.txt', 'a') as f:
        f.write('\n' + bo)
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/63.0.3239.132 Safari/537.36 QIHU 360SE'
    }

    url = 'https://api.iyk0.com/twqh/'
    resp = requests.get(url=url, headers=headers)
    data=resp.text
    with open('4.txt', 'a') as f:
        f.write('\n' + data)
    time.sleep(2)
    # print("��������2")

def main():
    start_time = time.time()
    t1 = threading.Thread(target=test1,args=("ONE",))
    t2 = threading.Thread(target=test2,args=("TWO",))
    t1.start()
    t2.start()

    # �ȴ��������߳̽����ٽ������߳�
    t1.join()
    t2.join()

    end_time = time.time()
    total_time = end_time - start_time
    print("��������������ܺ�ʱΪ��{}".format(total_time))

while True:
    main()
