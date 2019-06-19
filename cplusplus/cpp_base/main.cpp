#include<iostream>

using namespace std;

void fun_pointer_test()
{
	void(*time_set_call)(unsigned char *p, int n) = NULL;
	if (time_set_call)
	{

	}
	int *a = NULL;
	if (a)
	{

	}
	cout << endl;
}

int main(int argc, char** argv)
{
    cout << "entry c++ base practice" << endl;
	int index = 0;
	switch (index)
	{
	case 0:fun_pointer_test(); break;
	default:break;
	}
	cout << "quit c++ base practice" << endl;
    return 0;
}