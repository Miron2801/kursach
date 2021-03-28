#include <iostream>
using namespace std;
class menu {
    public:
        void memu(int code){
			switch (code)
					{
					case 0:
						cout << "Выход";
						break;
					case 1:
						cout << "Red";
						break;
					case 2:
						cout << "Pink";
						break;
					case 3:
						cout << "Blue";
						break;
					default:
						cout << "Ошибка ввода повторите ввод";
						break;
					}     
	        }
		void echo_menu(){
			cout << "\n";
			cout << "\033[31m0: выход;\033[0m"<< "\n";
			cout << "\033[32m1: функция 1;\033[0m"<< "\n";
			cout << "\033[33m2: функция 2;\033[0m"<< "\n";
			cout << "\033[34m3: функция 3;\033[0m"<< "\n";
			cout << "Введите код: >> " ;

		}

};
