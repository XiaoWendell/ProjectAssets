# coding=gbk
"""
���ߣ�����
���ںţ���ת������
@ʱ��  : 2022/2/3 2:24
Ⱥ��428335755
"""
import requests
from lxml import etree
import time
import os
def mkdir(path):

    # ȥ����λ�ո�
    path = path.strip()
    # ȥ��β�� \ ����
    path = path.rstrip("\\")

    isExists = os.path.exists(path)

    # �жϽ��
    if not isExists:
        os.makedirs(path)

        print(path + ' �����ɹ�')
        return True
    else:
        # ���Ŀ¼�����򲻴���������ʾĿ¼�Ѵ���
        print(path + ' Ŀ¼�Ѵ���')
        return False


# ����Ҫ������Ŀ¼
path = "ͼƬ\\"
# ���ú���
mkdir(path)

url='https://www.huya.com/g/4079/'
header={
 'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_13_3) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/65.0.3325.162 Safari/537.36'
}
response=requests.get(url=url,headers=header)#��������
# print(response.text)
data=etree.HTML(response.text)#ת��Ϊhtml��ʽ
# print(data)
image_url=data.xpath('//a//img//@data-original')
image_name=data.xpath('//a//img[@class="pic"]//@alt')
# print(image_url)
for ur,name in zip(image_url,image_name):
    url=ur.replace('?imageview/4/0/w/338/h/190/blur/1','')
    title=name+'.jpg'
    response = requests.get(url=url, headers=header)  # �ڴ˷����µ�����
    with open(path+title,'wb') as f:
        f.write(response.content)
    print("���سɹ�" + name)
    time.sleep(2)
