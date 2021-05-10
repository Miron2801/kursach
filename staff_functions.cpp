#include <iostream>
#include "File_system.cpp"

using namespace std;
class menu {
    public:
        void memu(int code){
			cout << '\n';
			switch (code)
					{
					case 0:
						cout << "Выход";
						break;
					case 1:{
							FileSystem FS("data/data.bin");
							cout << FS.ScanPerson();
							break;
						}
					case 2:{
							FileSystem FS("data/data.bin");
							cout << FS.delete_person();
							break;	
							}
					case 3:
						{
							FileSystem FS("data/data.bin");
							FS.GetPersonsFromFile();
							break;
						}
					case 4:
						{
							FileSystem FS("data/data.bin");
							cout << FS.countLines();
							break;
						}
					default:
						cout << "Ошибка ввода повторите ввод";
						break;
					}     
	        }
		void echo_menu(){			
			cout << '\n';
			cout << "\033[32m1: Добавление информации в файл;\033[0m"<< "\n";
			cout << "\033[33m2: Удаление информации из файла;\033[0m"<< "\n";
			cout << "\033[34m4: КРедактирование записей\033[0m"<< "\n";

			cout << "\033[34m3: Вывод людей в файле;\033[0m"<< "\n";
			cout << "\033[34m4: Колличество записей в файле;\033[0m"<< "\n";
			cout << "\033[34m4: Колличество записей в файле;\033[0m"<< "\n";


			cout << "\033[31m0: выход;\033[0m"<< "\n";
			cout << "Введите код: >> " ;
		}

};
