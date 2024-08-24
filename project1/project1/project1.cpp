#include<iostream>
#include<functional>
using namespace std;

int (*func_ptr)(int);

int func(int a)
{
    std::cout << "func: " << a << endl;
    return a;
}

void f(int n1, int n2, int n3, const int& n4, int n5) {
    std::cout << n1 << ' ' << n2 << ' ' << n3 << ' ' << n4 << ' ' << n5 << std::endl;
}

template<typename T>
T fun2(T a) {
    return a + 2;
}

struct my_add {
    int operator()(int x) {
        return x + 9;
    }
};

struct Foo
{
    static void func11()
    {
        std::cout << "static void func1......" << std::endl;
    }
    static void func12(int val)
    {
        std::cout << "static void func1( val " << val << "......" << std::endl;
    }

    void func2(int val)
    {
        std::cout << "void func2(val " << val << ")......" << std::endl;
    }

};

int main()
{
    // 1. 包装函数
    std::function<int(int)>  f1 = func;
    f1(66);
    std::cout << sizeof(f1) << std::endl;

    // 2. 包装函数指针
    func_ptr = func;
    func_ptr(88);

    // 3. 包装模板函数
    f1 = fun2<int>;
    f1(688);

    // 4. 包装仿函数
    f1 = my_add();
    std::cout << f1(87) << std::endl;

    // 5. 包装lambda 函数
    auto tmp_func = [](int a)->int
        {
            return a;
        };

    f1 = tmp_func;
    std::cout << f1(8888) << std::endl;


    // 6 包装静态函数
    std::function<void(void)> f61 = Foo::func11;
    f61();

    std::function<void(int)>  f62 = Foo::func12;
    f62(666);


    // 7 包装类成员函数
    Foo foo;
    std::function<void(int)> f7 = std::bind(&Foo::func2, foo, std::placeholders::_1);
    f7(888);


    // bind
    auto f2 = std::bind(f, std::placeholders::_3, std::placeholders::_2, std::placeholders::_1, 4, 5);
    f2(3, 2, 1);
    std::function<void(int, int, int)> ff = f2;
    ff(3, 2, 1);
    std::cout << "------ main end ------" << std::endl;

    return 0;
}