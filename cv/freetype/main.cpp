#include "main.h"
#include <ft2build.h> 
#include FT_FREETYPE_H 

void test1()
{
	FT_Library library;
	int error = FT_Init_FreeType(&library);
	if(error)
	{
		
	}
}

int main(int argc, char** argv)
{
	cout << "entry freetype practice" << endl;
	int index = 0;
	switch (index)
	{
	case 0: test1(); break;
	default:break;
	}
	cout << "quit freetype practice" << endl;
    return 0;
}