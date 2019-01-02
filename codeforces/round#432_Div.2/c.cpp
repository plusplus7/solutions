#include <iostream>
#include <string>
#include<stdlib.h>
#include <sstream>
using namespace std;
class stack
{
private:
	int arr[500];
	int counter = -1;
public:
	void push(int i)
	{
		counter++;
		arr[counter] = i;
	}
	void query()
	{
		if (counter == -1)
		{
			cout << "this is empty!"<<endl;
		}
		else
		{
			for (int i = counter; i > -1; i--)
			{
				cout << arr[i] << endl;
			}
			counter = -1;
		}
	}
	void pop()
	{
		if (counter == -1)
		{
			cout << "this is empty!" << endl;
		}
		else
		{
			cout << arr[counter]<<endl;
			counter--;
		}
	}
	void init()
	{
		for (int i = 0; i < 500; i++)
		{
			arr[i] = 0;
		}
	}
};
int main()
{
	stack s;
	int t;
	int counter = 0, num = 0;
	string a;
	s.init();
	cin >> t;
	while (counter <= t)
	{
		getline(cin,a);
		string aa;
		if (a.find("push") != -1)
		{
			stringstream ss;
			aa = a.substr(a.find(" ") + 1, a.size() - 1);
			ss << aa;
			ss >> num;
			s.push(num);
		}
		if (a.find("pop") != -1)
		{
			s.pop();
		}
		if (a.find("query") != -1)
		{
			s.query();
		}
		counter++;
	}
}
