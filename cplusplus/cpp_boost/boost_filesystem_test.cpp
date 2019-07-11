#include"main.h"
#include <boost/filesystem.hpp>
#include <boost/regex.hpp>

using namespace std;
using namespace boost::filesystem;

void traverse_files()
{
	path dir{ "D:/dataset/test_image" };
	boost::filesystem::path old_cpath = boost::filesystem::current_path();
	boost::regex pattern{ "^.*?\\.(jpg|jpeg|png)$" };
	for (directory_iterator iter{ dir }, end{}; iter != end; ++iter)
	{
		//string s = (iter->path() / "name.png").generic_string();
		string s = (iter->path()).generic_string();
		string name = iter->path().filename().generic_string();
		bool flag = false;
		if (boost::regex_match(name, pattern))
		{
			flag = true;
		}
		cout << s << ", " << name << ", " << flag << endl;
	}
	cout << endl;
}

void file_operate()
{
	string srcPath = "D:\\temp\\aaa/img_7.jpg";
	string dstPath = "D:\\temp\\qqq/img_7.jpg";
	rename(srcPath, dstPath);
	cout << endl;
}

void boost_filesystem_test()
{
	cout << "entry c++ boost filesystem practice" << endl;
	int index = 1;
	switch (index)
	{
	case 0: traverse_files(); break;
	case 1: file_operate(); break;
	default:break;
	}
}