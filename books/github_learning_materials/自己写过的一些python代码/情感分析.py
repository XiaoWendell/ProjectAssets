# coding=gbk
"""
���ߣ�����
@ʱ��  : 2021/8/29 21:30
Ⱥ��970353786
"""
'''
�û���Ҫ����Senta��ɶԸ��ļ�����з���Ԥ�⣬ֻ�������ļ������ļ����ݴ��list��list��ÿ��Ԫ���Ǵ�Ԥ����ӡ�
'''
with open("test.txt", 'r') as f:
    try:
        test_text = []
        for line in f:
            test_text.append(line.strip())
    except:
            print('��ȡʧ��')
print(test_text)
''':cvar
����Ԥѵ��ģ��,����볢������ģ�ͣ�ֻ��Ҫ����Module�е�name��������.
'''
import paddlehub as hub
senta = hub.Module(name="senta_bilstm")
#Ԥ��
input_dict = {"text": test_text}
results = senta.sentiment_classify(data=input_dict)

for result in results:
    print(result)