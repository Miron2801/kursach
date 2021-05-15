#include <iostream>
#include "File_system.cpp"
#include <unistd.h>

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
					case 3:{
							FileSystem FS("data/data.bin");
							cout << FS.ы();
							break;	
							}
					case 4:
						{
							FileSystem FS("data/data.bin");
							FS.edit_record();
							break;
						}
					case 5:
						{
							FileSystem FS("data/data.bin");
							FS.GetPersonsFromFile();
							break;
						}
					case 6:
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
			cout << "\033[35m3: Вывод табеля о студенте;\033[0m"<< "\n";
			cout << "\033[34m4: Редактирование записей\033[0m"<< "\n";
			cout << "\033[34m5: Вывод людей в файле;\033[0m"<< "\n";
			cout << "\033[34m6: Колличество записей в файле;\033[0m"<< "\n";			
			cout << "\033[31m0: выход;\033[0m"<< "\n";
			cout << "Введите код: >> " ;
		}

};
