#include<iostream>
#include <vector>
#include <algorithm>
#include<string>
using namespace std;
class Test {
	friend ostream& operator<<(ostream& cout, Test& p);
public:
	mutable int m_a;
	int num;
	Test() { cout << "Test�Ĺ��캯��..." << endl; }
	Test(int x) { num = x;
	cout << "Test����������..." << endl;
	}
	~Test() { cout << "Test����������..." << endl; }

	//int getDebug() { return this->debug; }
	void func() {};//Ҳ��������Ķ��󡣳�Ա�����ǹ�ͬ�ģ���this��ָ�򱻵��õĳ�Ա������������
	void showdebug() {
		if (this == NULL) return;
		cout << "debug=" << debug << endl;
	}
	void change(int x) const //const�Ӻ�����Ϊ������thisָ�룬��ָ��ָ���ֵ�����޸ģ�
	{
		m_a = x;
		//this->age = x;

	}
	Test& addde(Test& T) {
		this->debug = T.debug;
		return *this;
	}
	/*Test operator+(Test& t) {
	Test temp;
	temp.num = this->num + t.num;
	return temp;
}*/
	//������ֻ�ܵ��ó�����

	//�������ڲ��ܸı��Ա���ԣ����Ҫ�ı�ͼ�mutable
	Test operator<<(Test& t) {
		cout << t.num << endl;
	}
private:
	int debug;
	int age;
	int m_b;
	static int val;//��̬��������Ķ���
};
class building {
	friend void globle(building* build);
	friend  class goodbay;
private:
	string mbad_room;
public:
	string msitting_room;
	building() {
		mbad_room = "����";
		msitting_room = "����";
		cout << "building consduction" << endl;
	}
	building(const building& bb) {
		cout << "building�������캯������" << endl;
		this->mbad_room = bb.mbad_room;
		this->msitting_room = bb.mbad_room;
	}

};
class goodbay {
public:
	building* build;
	void visit() {
		// ʵ�� visit ����
		cout << "visit ���ڷ��� " << build->msitting_room << endl;
	}
	void visit2() {
		cout << "visit2 ���ڷ��� " << build->mbad_room << endl; // ����Ԫ����
	}
	goodbay() {
		build = new building;
	}
	~goodbay() {
		delete build;
	}
};
void globle(building* build) {//ȫ�ֺ�������Ԫ
	cout << "���ڷ���" << build->msitting_room << endl;
	cout << "���ڷ���" << build->mbad_room << endl;//�޷����ʣ���Ҫ�ų���Ԫ
}
int val = 1;
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>>result;
		if (nums.size() < 3) return result;
		sort(nums.begin(), nums.end());
		for (size_t i = 0; i < nums.size() - 2; ++i) {
			if (i > 0 && nums[i] == nums[i - 1] && nums[i - 2]) continue;
			//int left=i+1;
			 //right=nums.size()-1;
			for (int left = i + 1; left < nums.size() - 1; ++left) {
				for (int right = left + 1; right < nums.size() - 1; ++right)
					while (nums[left] != nums[right] && nums[left] + nums[right] == -nums[i])
						result.push_back({ nums[i], nums[left], nums[right] });
			}

		}
		return result;
	}
};
Test operator+(Test& t1,Test& t2) {
	Test temp;
	temp.num = t1.num + t2.num;
	return temp;
}
class MyInteger {
public:
	
	MyInteger() {
		m_num = 0;
		m_heigth = NULL;
	}
	MyInteger(int x,int height) {
		m_num = x;
		m_heigth =new int(height);
	}
	MyInteger(MyInteger& MM) {
		this->m_num = MM.m_num;
		m_heigth = new int(*MM.m_heigth);
	 }
	int* m_heigth;
	int m_num;
	//����ǰ��++�����
	MyInteger & operator++() {
		m_num ++;
		return *this;
	}
	//���غ���++�����
	//���ܷ������ã���Ϊtemp�Ǿֲ��������ᱻ�ͷ�
	MyInteger operator++(int) {//int��������ǰ����
		//�ȼ�¼��ʱ���
		MyInteger temp = *this;

		//�� ����
		m_num++;
		//��󷵻ؼ�¼ֵ
		
		return temp;
	}
	MyInteger& operator=(MyInteger& M) {
		//�������ṩǳ����
		//Ӧ�����ж������Ƿ��ڶ�������������ͷŸɾ���Ȼ�����
		if (m_heigth != NULL) {
			delete m_heigth;
			m_heigth = NULL;
		}
		//���
		m_heigth = new int(*M.m_heigth);
		return *this;
	}
	bool operator==(MyInteger& M1) {
		if (*this->m_heigth == *M1.m_heigth && this->m_num == M1.m_num)
			return true;
		 return false;
	}
	bool operator!=(MyInteger& M1) {
		if (this->m_heigth == M1.m_heigth && this->m_num == M1.m_num)
			return false;
		return true;
	}
};
class myprint {
public:
	
	void operator()(string test){//���������������ʳƷº���

		cout << test << endl;}

};
class Myadd {
public:

	int operator()(int num1,int num2) {//���������������ʳƷº���

		return num1 + num2;
	}

};
void Myprint(string test) {
	cout << test << endl;
}
ostream& operator<<(ostream& cout, const MyInteger& p) {
	cout << p.m_num;
	return cout;
}
ostream & operator<<( ostream& cout,Test& p)
{
	cout << "num=" << p.num << endl;
	cout << "num=" << p.m_b << endl;//����Ԫ
	return cout;
}


class BasePage {//����̳и��࣬������󴴽�ʱ��Ҳ����ø��๹�캯��������ͬ��
public:
	BasePage() {
		m_a = 100;
		cout << "BasePage���캯����" << endl;
	}
	~BasePage() {
		cout << "BasePage����������" << endl;
	}
	void header()
	{
		//cout << " ������ͷ����" << endl;
	}
	void footer()
	{
		//cout << "�������ġ�����" << endl;
	}
	void left() {
		//cout << "left������" << endl;
	}
	void func() {
		cout << "����func������" << endl;
	}
	void func(int x) {

		cout << "����func(int x)������" << endl;
	}
	static void fun() {
		cout<<"����static---fun()������" << endl;
	}
	static void fun(int x) {
		cout << "����static---fun()������" << endl;
	}
	int m_a;
	static int m_A;
protected:
	int m_b;
private:
	int m_c;//˽�г�Աֻ�Ǳ������ˣ����ǻ�̳���ȥ
};
int BasePage::m_A = 11;

class Java :public BasePage {//����Ĺ����ͱ������䣬˽���޷�����
public:
	Java() {
		m_a = 200;
		cout << "Java���캯����" << endl;
	}
	~Java() {
		cout << "Java����������" << endl;
	}
	void func() {
		cout << "Java��func������" << endl;
	}
	static void fun() {
		cout << "Java����static---fun()������" << endl;
	}
	 void content() {
		
		 m_a = 10;
		 m_b = 10;
		 //m_c = 10;
	}
	 int m_J;
	 int m_a;
	 static int m_A;

};
int Java::m_A = 12;
void fun1() {
	Java J1;
	J1.m_a = 10;
	//J1.m_b = 10;

//��������������һ�������������еķǾ�̬��Ա���ᱻ�̳У������˽�б������ˣ�����ȷʵ�����̳���
	cout << "size of Java =" << sizeof(Java) << endl;
}
class python :protected BasePage {//����Ĺ�����Ϊ�˱�����˽���޷�����
public:
	python() {
		cout << "python���캯����" << endl;
	}
	~python() {
		cout << "python����������" << endl;
	}
	void content() {
		m_a = 10;
		m_b = 10;
		//m_c = 10;
	}
};
void fun2() {
	python p1;
	//p1.m_a = 10;
	//p1, m_b = 10;
}
class Cplus :private BasePage {//����Ĺ����ͱ��������˽�У������˽�б�ɲ��ɷ���
public:
	Cplus() {
		cout << "Cplusn���캯����" << endl;
	}
	~Cplus() {
		cout << "Cplus����������" << endl;
	}
	void content() {
		m_a = 10;
		m_b = 10;
		//m_c = 10;
	}
};
void fun3(){
	/*m_a = 10;
	m_b = 10;*/
}
class Base0 {//�����
public:
	int ma;
	virtual void speak() {//�麯��
		cout << "������˵��" << endl;
	}
};
class Base1:public Base0 {//��̳�
public:
	int m1;
	Base1() {

	}
	 void speak() {//�麯��
		cout << "Сè��˵��" << endl;
	}

};
class Base2 : public Base0 {
public:
	int m2;
	int m1;
	void speak() {
		cout << "С����˵��" << endl;
	}
	Base2() {

	}

};
class Son :public Base2, public Base1 {
public:
	Son() {
		m3 = 300;
		m4 = 400;
	}
	int m3;
	int m4;

};
void test02() {
	const Test t3;//������ֻ�ܵ��ó�����
	//t3.showdebug();
	t3.change(1);
	t3.m_a = 2;
	//t3.age = 3;
}
void test03() {
	building meme;
	globle(&meme);
}
void test04() {
	goodbay buy;
	buy.visit();
}
void test05() {
	Test t4(5);
	cout << t4 << endl;
}
void test06() {
	MyInteger M1;
	cout << ++M1 << endl;
	cout << ++(++M1) << endl;
}
void test07() {
	MyInteger M2(0, 0);
	cout << M2++ << endl;
	cout << ++(++M2) << endl;
}
void test08() {
	MyInteger M3(0, 18);
	MyInteger M2(0, 0);
	MyInteger M1;
	M1 = M2 = M3;
	cout << *M1.m_heigth << "  " << *M2.m_heigth << endl;

}
void test09() {
	MyInteger M2(0, 0);
	MyInteger M1(0, 0);
	M1 = M2;
	if (M2 == M1) {
		cout << "M1��M2���" << endl;
	}

}
void test10() {
	myprint mypr;
	mypr("hello world");
	Myprint("hello 1");
	Myadd add;
	cout << add(10, 12) << endl;
	//������������Myadd()
	cout << Myadd()(100, 100) << endl;
}
void test11() {
	cout << "javaҳ��" << endl;
	Java j1;
	j1.content();
	j1.footer();
	j1.header();
	j1.left();

}
void test12() {
	Java J1;
	cout << "J1��m_a=" << J1.m_a << endl;//ͬ����Ա��Ӧ����
cout << "J1��m_a=" << J1.BasePage::m_a << endl;//���ôӸ���̳е�ͬ����ԱҪ��������
	J1.func();
	J1.BasePage::func();
	//��������е���ͬ������ô�����ͬ�������ᱻ��������
	//J1.func(100);
	J1.BasePage::func(100);
}
void test13() {
	Java J1;
	//ͨ���������
	cout << "java��m_A=" << J1.m_A << endl;
	cout << "Base��m_A=" << J1.BasePage::m_A << endl;
	//ͨ����������
	cout << "java��m_A=" << Java::m_A << endl;
	//��һ��::����ͨ��������ʽ���ʣ��ڶ���::������ʸ�����������
	cout << "Base��m_A=" << Java::BasePage::m_A << endl;
	//ͨ���������
	J1.fun();
	J1.BasePage::fun();
	//ͨ����������
	Java::fun();
	Java::BasePage::fun();

	//��������е���ͬ������ô�����ͬ�������ᱻ��������,��Ҫ��������
	Java::BasePage::fun(100);
}
void test14() {
	Son s;
	cout << "sizeof Son=" <<sizeof(s)<< endl;
	//cout << s.m1 << endl;������
	cout << s.Base1::m1 << endl;
}
void test15() {
	Son s;
	//s.ma = 18; ��̳У�ma����ȷ
	s.Base1::ma = 18;
	s.Base2::ma = 28;
	//���μ̳У���������ӵ����ͬ���ݣ���Ҫ����������
	cout << "s.Base1::ma =" << s.Base1::ma << endl;
	cout << "s.Base2::ma =" << s.Base2::ma << endl;
	//�����������֪����ֻҪ��һ�ݾ����ˣ����μ̳е������������ݣ���Դ�˷�
	//����̳п��Խ������

}
void dospeak(Base0& animal) {//������ַ�ڱ���׶ξ�ȷ����
	//�����ִ��è˵���������������ַ�Ͳ�����ǰ�󶨣���Ҫ�����н׶ΰ�
	//���麯��ʵ�ֵ�ַ���
	animal.speak();
}
//��̬��̬(����ʱȷ����ַ)��������
//1.�м̳й�ϵ
//2.������д�����麯��
//��̬��̬ʹ��
//����ָ��������ã�ִ���������
void test21() {
	Base1 cat;
	dospeak(cat);//����˵��
}
int main(void) {
	//auto_ptr<Test>test(new Test);
	//shared_ptr<int> sp1;
	//shared_ptr<int> sp2(new int(2));
	//shared_ptr<int> sp3(sp2);
	//shared_ptr<int> sp4 = make_shared<int>(*sp2);
	////int* p;
	//cout << "sp1	use_count() = " << sp1.use_count() << endl;
	//sp2 = nullptr;
 //   //sp1.reset(p);
	////cout << (*sp1) << endl;
	//
	//cout << "sp2	use_count() = " << sp2.use_count() << endl ;
	////cout << test.get();
	////cout << (*test).getDebug();
	//unique_ptr<string>s1(new string("aaaa"));
	//unique_ptr<string>s2(new string("bbbbb"));
	//s1 = move(s2);					
	//unique_ptr<string> s3(move(s2));
	//Test*temp=test.release();
	//delete temp;

	//int a[4] = { 1, 2, -3, 5 };
	//vector<int> nums(a, a + 4); // ����̬����ת��Ϊvector
	//Solution sulo;
	//vector<vector<int>> result = sulo.threeSum(nums);
	//for (const auto& triplet : result) {
	//	for (int num : triplet) {
	//		std::cout << num << " ";
	//	}
	//	std::cout << std::endl;
	//}

	Test t1(11);
	//cout << "size of t1=" << sizeof(t1) << endl;
	Test t2(10);
	//t2.addde(t1).addde(t1);
	//test03();
	
	Test t3=t1+t2;
	//cout << t3.num<<endl ;
	//test05();
	//test07();
	//test08();
	//test09();
	//test10();
	//test11();
	//test12();
	//test13();
	//test14();
	test21();
	return 0;
}



//class Solution {
//public:
//    string convert(string s, int numRows) {
//        char** p = new char* [numRows];
//        int j = 0;
//        int nums = 0;
//        int k = 0;
//        string result;
//        for (int i = 0; i < numRows; i++)
//        {
//            p[i] = new char[s.size()];
//            for (int j = 0; j < s.size(); j++)
//                p[i][j] = '0';
//        }
//
//        while (nums <= s.size()) {
//            if (numRows - 1 == 0 || j % (numRows - 1) == 0) {
//                k = numRows - 1;
//                for (int i = 0; i < numRows; i++) {
//                    p[i][j] = s[nums++];
//                }
//                j++;
//            }
//            else {
//                k--;
//                p[k][j] = s[nums++];
//                j++;
//            }
//            for (int i = 0; i < numRows; i++) {
//                for (int j = 0; j < s.size(); j++) {
//                    if (p[i][j] != '0')
//                    {
//                        result += p[i][j];
//
//                    }
//                }
//            }
//        }
//        for (int i = 0; i < numRows; i++) {
//            delete[] p[i];
//        }
//        delete[] p;
//
//
//        return result;
//    }
//};



//while (x != 0) {
//	if (result<INT_MIN / 10 || result>INT_MAX / 10) return 0;
//	int g = x % 10;
//	x /= 10;
//	result = g + result * 10;
//}