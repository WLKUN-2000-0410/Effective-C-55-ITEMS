////演示iterator和const
//#include <iostream>
//#include <vector>
//int main()
//{
//	//01
//	std::cout << "Hello W" << std::endl;
//	std::vector<int> vec = { 1,2,3,4,5 };
//	std::vector<int>::const_iterator const_it = vec.begin();
//	const_it++;
//	std::cout <<*const_it << std::endl;    //指向是可以改变的
//	//*const_it = 10;								   //error 值是不可以改变的
//
//
//	//02
//	const std::vector<int>::iterator it = vec.begin();
//	*it+=10;                                              //值是可以改变的
//	//it++;                                                //error 指向是不可改变的
//	std::cout << *it << std::endl;
//
//
//	system("pause");
//
//}