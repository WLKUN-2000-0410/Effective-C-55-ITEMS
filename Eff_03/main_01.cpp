////��ʾiterator��const
//#include <iostream>
//#include <vector>
//int main()
//{
//	//01
//	std::cout << "Hello W" << std::endl;
//	std::vector<int> vec = { 1,2,3,4,5 };
//	std::vector<int>::const_iterator const_it = vec.begin();
//	const_it++;
//	std::cout <<*const_it << std::endl;    //ָ���ǿ��Ըı��
//	//*const_it = 10;								   //error ֵ�ǲ����Ըı��
//
//
//	//02
//	const std::vector<int>::iterator it = vec.begin();
//	*it+=10;                                              //ֵ�ǿ��Ըı��
//	//it++;                                                //error ָ���ǲ��ɸı��
//	std::cout << *it << std::endl;
//
//
//	system("pause");
//
//}