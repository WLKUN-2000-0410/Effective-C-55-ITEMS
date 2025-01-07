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

	//1.��const��Ա����,�����޸Ķ���״̬
	void setValue(const int &v) {
		value = v;
	}
	void setValue(const std::string& n) {
		name = n;
	}

	//1.const��Ա�����������޸Ķ���״̬
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

//3.������pass by reference-to-const�ķ�ʽ���ݶ���
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
	//obj2.getName("wang");      //2.error const�����ܵ��÷�const��Ա����
	obj2.getName();                     //2.no error ���õ���const��Ա����

	printObject(obj2);

	system("pause");
}