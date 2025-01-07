#include <iostream>
#include <string>

//For 2025.1.7.01_char&��Ϊ����ֵ
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
		x += dx; // �޸� x ����
		y += dy; // �޸� y ����
	}
	// ��ȡ x ����
	int & getX()  {
		return x;
	}

	// ��ȡ y ����
	int & getY()  {
		return y;
	}
	/*char & operator[](int index) const{
		return text[index];               //����
	}*/
	//�ṩһ�������汾���ڳ�������ͨ���±��ȡ����
	//�����ԭ���� �����汾�� operator[] ������ char&���������ͣ���
	//������ char��ֵ���ͣ����� const ��Ա�����У���ֻ�ܷ������ const ��Ա��
	//������һ�� char& �ᵼ�³����޸�ԭʼ���ݣ��Ӷ�Υ���� const �����塣

	//v2
	//���ص��Ǹ���, ÿ�ζ��´��
	//char  operator[](int index) const{
	//	return text[index];
	//}

	//v3
	//���ص�������,���⿽��
	//����ֵֻ�� & ����,��Ϊ�ᱻ��Ϊ��ȥ�����޸�����, �ʼ���const���������޸����� 
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
	std::cout << ctb[0] << std::endl;  //v1:����,���������ܷ��ʷǳ�������
									   //v2:�ɹ�,������const�汾
	TextBlock p("point");
	p.move(1, 1);
	std::cout << p.getX() << " " << p.getY() << std::endl;

    system("pause");                   //�ȴ��û�����
	return 0;
}
