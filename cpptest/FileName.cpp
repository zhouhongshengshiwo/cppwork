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
	Test() { cout << "Test的构造函数..." << endl; }
	Test(int x) { num = x;
	cout << "Test的析构函数..." << endl;
	}
	~Test() { cout << "Test的析构函数..." << endl; }

	//int getDebug() { return this->debug; }
	void func() {};//也不属于类的对象。成员函数是共同的，用this：指向被调用的成员函数所属对象
	void showdebug() {
		if (this == NULL) return;
		cout << "debug=" << debug << endl;
	}
	void change(int x) const //const加后面是为了修饰this指针，让指针指向的值不可修改；
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
	//常对象只能调用常函数

	//常函数内不能改变成员属性，如果要改变就加mutable
	Test operator<<(Test& t) {
		cout << t.num << endl;
	}
private:
	int debug;
	int age;
	int m_b;
	static int val;//静态不属于类的对象
};
class building {
	friend void globle(building* build);
	friend  class goodbay;
private:
	string mbad_room;
public:
	string msitting_room;
	building() {
		mbad_room = "卧室";
		msitting_room = "客厅";
		cout << "building consduction" << endl;
	}
	building(const building& bb) {
		cout << "building拷贝构造函数调用" << endl;
		this->mbad_room = bb.mbad_room;
		this->msitting_room = bb.mbad_room;
	}

};
class goodbay {
public:
	building* build;
	void visit() {
		// 实现 visit 方法
		cout << "visit 正在访问 " << build->msitting_room << endl;
	}
	void visit2() {
		cout << "visit2 正在访问 " << build->mbad_room << endl; // 加友元才行
	}
	goodbay() {
		build = new building;
	}
	~goodbay() {
		delete build;
	}
};
void globle(building* build) {//全局函数做友元
	cout << "正在访问" << build->msitting_room << endl;
	cout << "正在访问" << build->mbad_room << endl;//无法访问，需要放成友元
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
	//重载前置++运算符
	MyInteger & operator++() {
		m_num ++;
		return *this;
	}
	//重载后置++运算符
	//不能返回引用，因为temp是局部变量，会被释放
	MyInteger operator++(int) {//int用于区分前后置
		//先记录当时结果
		MyInteger temp = *this;

		//后 递增
		m_num++;
		//最后返回记录值
		
		return temp;
	}
	MyInteger& operator=(MyInteger& M) {
		//编译器提供浅拷贝
		//应该先判断属性是否在堆区，如果有先释放干净，然后深拷贝
		if (m_heigth != NULL) {
			delete m_heigth;
			m_heigth = NULL;
		}
		//深拷贝
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
	
	void operator()(string test){//用起来很像函数，故称仿函数

		cout << test << endl;}

};
class Myadd {
public:

	int operator()(int num1,int num2) {//用起来很像函数，故称仿函数

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
	cout << "num=" << p.m_b << endl;//用友元
	return cout;
}


class BasePage {//子类继承父类，子类对象创建时，也会调用父类构造函数，析构同理
public:
	BasePage() {
		m_a = 100;
		cout << "BasePage构造函数！" << endl;
	}
	~BasePage() {
		cout << "BasePage析构函数！" << endl;
	}
	void header()
	{
		//cout << " （公共头部）" << endl;
	}
	void footer()
	{
		//cout << "帮助中心···" << endl;
	}
	void left() {
		//cout << "left———" << endl;
	}
	void func() {
		cout << "父类func被调用" << endl;
	}
	void func(int x) {

		cout << "父类func(int x)被调用" << endl;
	}
	static void fun() {
		cout<<"父类static---fun()被调用" << endl;
	}
	static void fun(int x) {
		cout << "父类static---fun()被调用" << endl;
	}
	int m_a;
	static int m_A;
protected:
	int m_b;
private:
	int m_c;//私有成员只是被隐蔽了，但是会继承下去
};
int BasePage::m_A = 11;

class Java :public BasePage {//父类的公共和保护不变，私有无法访问
public:
	Java() {
		m_a = 200;
		cout << "Java构造函数！" << endl;
	}
	~Java() {
		cout << "Java析构函数！" << endl;
	}
	void func() {
		cout << "Java类func被调用" << endl;
	}
	static void fun() {
		cout << "Java子类static---fun()被调用" << endl;
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

//父类三个，子类一个，父类中所有的非静态成员都会被继承，父类的私有被隐藏了，但是确实·被继承了
	cout << "size of Java =" << sizeof(Java) << endl;
}
class python :protected BasePage {//父类的公共变为了保护，私有无法访问
public:
	python() {
		cout << "python构造函数！" << endl;
	}
	~python() {
		cout << "python析构函数！" << endl;
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
class Cplus :private BasePage {//父类的公共和保护变成了私有，父类的私有变成不可访问
public:
	Cplus() {
		cout << "Cplusn构造函数！" << endl;
	}
	~Cplus() {
		cout << "Cplus析构函数！" << endl;
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
class Base0 {//虚基类
public:
	int ma;
	virtual void speak() {//虚函数
		cout << "动物在说话" << endl;
	}
};
class Base1:public Base0 {//虚继承
public:
	int m1;
	Base1() {

	}
	 void speak() {//虚函数
		cout << "小猫在说话" << endl;
	}

};
class Base2 : public Base0 {
public:
	int m2;
	int m1;
	void speak() {
		cout << "小狗在说话" << endl;
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
	const Test t3;//常对象只能调用常函数
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
		cout << "M1和M2相等" << endl;
	}

}
void test10() {
	myprint mypr;
	mypr("hello world");
	Myprint("hello 1");
	Myadd add;
	cout << add(10, 12) << endl;
	//匿名函数对象Myadd()
	cout << Myadd()(100, 100) << endl;
}
void test11() {
	cout << "java页面" << endl;
	Java j1;
	j1.content();
	j1.footer();
	j1.header();
	j1.left();

}
void test12() {
	Java J1;
	cout << "J1的m_a=" << J1.m_a << endl;//同名成员对应调用
cout << "J1的m_a=" << J1.BasePage::m_a << endl;//调用从父类继承的同名成员要加作用域
	J1.func();
	J1.BasePage::func();
	//如果子类中调用同名，那么父类的同名函数会被子类隐藏
	//J1.func(100);
	J1.BasePage::func(100);
}
void test13() {
	Java J1;
	//通过对象访问
	cout << "java的m_A=" << J1.m_A << endl;
	cout << "Base的m_A=" << J1.BasePage::m_A << endl;
	//通过类名访问
	cout << "java的m_A=" << Java::m_A << endl;
	//第一个::代表通过类名方式访问，第二个::代表访问父类作用域下
	cout << "Base的m_A=" << Java::BasePage::m_A << endl;
	//通过对象访问
	J1.fun();
	J1.BasePage::fun();
	//通过类名访问
	Java::fun();
	Java::BasePage::fun();

	//如果子类中调用同名，那么父类的同名函数会被子类隐藏,需要加作用域
	Java::BasePage::fun(100);
}
void test14() {
	Son s;
	cout << "sizeof Son=" <<sizeof(s)<< endl;
	//cout << s.m1 << endl;二义性
	cout << s.Base1::m1 << endl;
}
void test15() {
	Son s;
	//s.ma = 18; 多继承，ma不明确
	s.Base1::ma = 18;
	s.Base2::ma = 28;
	//菱形继承，两个父类拥有相同数据，需要作用域区分
	cout << "s.Base1::ma =" << s.Base1::ma << endl;
	cout << "s.Base2::ma =" << s.Base2::ma << endl;
	//这份数据我们知道，只要有一份就行了，菱形继承导致数据有两份，资源浪费
	//用虚继承可以解决问题

}
void dospeak(Base0& animal) {//函数地址在编译阶段就确定了
	//如果想执行猫说话，那这个函数地址就不能提前绑定，需要在运行阶段绑定
	//用虚函数实现地址晚绑定
	animal.speak();
}
//动态多态(运行时确定地址)满足条件
//1.有继承关系
//2.子类重写父类虚函数
//动态多态使用
//父类指针或者引用，执行于类对象
void test21() {
	Base1 cat;
	dospeak(cat);//动物说话
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
	//vector<int> nums(a, a + 4); // 将静态数组转换为vector
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