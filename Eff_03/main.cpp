#include <iostream>
#include <string>

//For 2025.1.7.01_char&作为返回值
class TextBlock {
public:
	TextBlock(std::string str)
		: text(str)
	{
		
	}
	char & operator[](int index) {
		return text[index];
	}
	void move(int dx, int dy) {
		x += dx; // 修改 x 坐标
		y += dy; // 修改 y 坐标
	}
	// 获取 x 坐标
	int & getX()  {
		return x;
	}

	// 获取 y 坐标
	int & getY()  {
		return y;
	}
	/*char & operator[](int index) const{
		return text[index];               //报错
	}*/
	//提供一个常量版本用于常量对象通过下标读取内容
	//报错的原因是 常量版本的 operator[] 返回了 char&（引用类型），
	//而不是 char（值类型）。在 const 成员函数中，你只能访问类的 const 成员，
	//而返回一个 char& 会导致尝试修改原始数据，从而违反了 const 的语义。

	//v2
	//返回的是副本, 每次都会拷贝
	//char  operator[](int index) const{
	//	return text[index];
	//}

	//v3
	//返回的是引用,避免拷贝
	//返回值只加 & 错误,因为会被认为想去根据修改内容, 故加上const表明不会修改内容 
	const char& operator [] (int index) const 
	{ 
		return text[index];
	}



private:
	std::string text;
	int x = 0;
	int y = 0;

};

int main() {
	TextBlock tb("hello");
	std::cout << tb[0] << std::endl;
	const TextBlock ctb("world");
	std::cout << ctb[0] << std::endl;  //v1:报错,常量对象不能访问非常量数据
									   //v2:成功,加上了const版本
	TextBlock p("point");
	p.move(1, 1);
	std::cout << p.getX() << " " << p.getY() << std::endl;

    system("pause");                   //等待用户按键
	return 0;
}
