#include <iostream>

using namespace std;
void func()
{
	//printf("%s\n",__func__);
	cout<< __func__ << endl;
}
void func2()
{
	//printf("%s\n",__FUNCTION__);
	cout << __FUNCTION__ << endl;
}
void func3()
{
	//printf("%s\n",__PRETTY_FUNCTION__);
	cout << __PRETTY_FUNCTION__ << endl;
}
int main()
{
	func();
	func2();
	func3();
	return 0;
}

	
