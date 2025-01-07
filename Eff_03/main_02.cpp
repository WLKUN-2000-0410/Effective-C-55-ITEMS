#include <iostream>
#include <vector>
class MyClass {
private:
	int value;
	std::string name;
public:
	MyClass(int v, const std::string n)
		:value(v)
		, name(n)
	{}

	//1.非const成员函数,可以修改对象状态
	void setValue(const int &v) {
		value = v;
	}
	void setValue(const std::string& n) {
		name = n;
	}

	//1.const成员函数，不可修改对象状态
	const int & getValue() const {
		return value;
	}
	std::string getName() const {
		return name;
	}

	void display() const {
		std::cout << "Name  " << name << ", Value  "  << value << std::endl;
	}

};

//3.方便以pass by reference-to-const的方式传递对象
void printObject(const MyClass & obj) {
	obj.display();
}

int main()
{
	MyClass obj1(10, "wang");
	obj1.display();

	obj1.setValue(100);
	obj1.display();

	const MyClass obj2(20, "li");
	//obj2.getName("wang");      //2.error const对象不能调用非const成员函数
	obj2.getName();                     //2.no error 调用的是const成员函数

	printObject(obj2);

	system("pause");
}