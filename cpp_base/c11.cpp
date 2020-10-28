#include "main.h"
#include <typeinfo>
#include <string>    
#include <random>
#include <functional>
#include <chrono>
#include <regex>

using namespace std;

#if defined(__GXX_EXPERIMENTAL_CXX0X__) && (__cplusplus >= 201703L)

#else

#endif

constexpr int calculate_multiply_100(int a)
{
	return a * 100;
}
void fun1(int& n1, int& n2, const int& n3)
{
	std::cout << "In function: n1[" << n1 << "]    n2[" << n2 << "]    n3[" << n3 << "]" << std::endl;
	++n1; // 增加存储于函数对象的 n1 副本
	++n2; // 增加 main() 的 n2
	//++n3; // 编译错误
	std::cout << "In function end: n1[" << n1 << "]     n2[" << n2 << "]     n3[" << n3 << "]" << std::endl;
}
void c11_test1()
{
	int *p = nullptr;
	int *p2 = NULL;
	int *p3 = 0;
	int *p4 = (int *)((void *)0);
	//int *p5 = (void *)0; wrong
	if (p == nullptr) cout << "p" << endl;
	if(p == NULL) cout << "p NULL" << endl;
	auto r = typeid(p).name();

	const int a = 1;
	int b = 2;
	constexpr int a2 = a;
	//constexpr int a3 = b; wrong
	constexpr int a4 = calculate_multiply_100(a);

	typedef double db;
	using db2 = double;
	db2 d1 = 1.23456789;
	typedef int(*f1)(int);
	using f2 = int(*)(int); // using -> typedef

	auto a5 = calculate_multiply_100(a);
	decltype(a5) a6 = 10;

	int arr[5] = { 1,2,3,4,5 };
	for (auto i : arr)
	{
		cout << i << endl;
	}

	string s1 = to_string(100);
	string s2 = to_string(d1);
	double d2 = stod(s2);

	random_device rd;
	for (int i = 0; i < 5; i++)
	{
		cout << rd() << endl;
	}
	
	int n1 = 1, n2 = 1, n3 = 1;
	function<void()> f3 = bind(fun1, n1, std::ref(n2), std::cref(n3));
	f3();

	chrono::duration<double> du1;
	cout << "duration is " << du1.count() << std::endl;
	auto ch1 = chrono::system_clock::now();

	// atomic

	std::string text = "Date:2017-10-10";
	std::string pattern = "Date.(\\d{4})-(\\d{2}-(\\d{2}))";
	std::regex express(pattern);

	// static_assert(sizeof(void *) == 4, "64-bit code generation is not supported.");
	// static_assert(sizeof(void *) == 8, "32-bit code generation is not supported.");

	cout << endl;
}


void c11_test2()
{
	using t = tuple<int, char, double>;
	t t1 = { 1, 'a', 1.0 };
	t t2 = make_tuple(2, 's', 2.0);

	std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7 };
	v.push_back(1);
	std::cout << "before shrink_to_fit: " << v.capacity() << std::endl;
	v.shrink_to_fit();
	std::cout << "after shrink_to_fit: " << v.capacity() << std::endl;

	cout << endl;
}

class A {
	int data;
public:
	A() = default;
	~A() = default;
	A(int _data) :data(_data) {}
};
void c11_test3()
{
	A a1;
	A a2(1);
	cout << endl;
}

void c11_test4()
{
	auto f1 = [](int a, int b) {return a + b; };
	int a1 = f1(1, 2);
	cout << endl;
}

void foo(std::shared_ptr<int> i)
{
	(*i)++;
}
void c11_test5()
{
	auto pointer = std::make_shared<int>(10);
	foo(pointer);
	std::cout << *pointer << std::endl; // 11
	std::cout << pointer << std::endl; // 11

	auto pointer2 = pointer; // 引用计数+1
	auto pointer3 = pointer; // 引用计数+1
	int *p = pointer.get(); // 这样不会增加引用计数
	std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl; // 3
	std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl; // 3
	std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl; // 3

	pointer2.reset();
	std::cout << "reset pointer2:" << std::endl;
	std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl; // 2
	std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl; // 0, pointer2 已 reset
	std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl; // 2
	pointer3.reset();
	std::cout << "reset pointer3:" << std::endl;
	std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl; // 1
	std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl; // 0
	std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl; // 0, pointer3 已 reset

	//std::unique_ptr<int> p1 = std::make_unique<int>(10); // added in C++14
	// std::weak_ptr
	cout << endl;
}

void c11_test()
{
    cout << "entry c++ 11 practice" << endl;
	int index = 4;
	switch (index)
	{
	case 0: c11_test1(); break;
	case 1: c11_test2(); break;
	case 2: c11_test3(); break;
	case 3: c11_test4(); break;
	case 4: c11_test5(); break;
	default:break;
	}
	cout << "quit c++ 11 practice" << endl;
}