# coding=gbk
"""
���ߣ�����
@ʱ��  : 2021/8/29 22:10
Ⱥ��970353786
"""
#��ȡ����
with open("ci.txt", 'r') as f:
    test_text = []
    for line in f:
        test_text.append(line.strip())
print(test_text)
#����ģ��
import paddlehub as hub
module = hub.Module(name="lac")
## Ԥ��
results = module.lexical_analysis(texts=test_text)

for result in results:
    print(result)