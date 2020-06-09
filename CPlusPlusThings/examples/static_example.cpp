#include <iostream>
#include<string>
using namespace std;

class Apple
{
public:
	static int i;

	Apple()
	{
		// Do nothing
		std::cout << "init" << endl;
	};
	~Apple()
	{
		std::cout << "del" << endl;
	}
	static std::string ping(){
		return string{"pong"};
	}
	static int pong(){
		return Apple::i;
	}
};
int Apple::i = 0;
int main()
{
	if (true)
	{
		static Apple obj1;
		Apple obj2;
		obj1.i = 2;
		obj2.i = 3;
		cout << obj1.i << " " << obj2.i;
	}

	// prints value of i
	cout<<"return"<<endl;
	cout<<Apple::pong()<<endl;
	return 0;
}