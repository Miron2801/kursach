#include "models.cpp"
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;
class FileSystem {
    public:
        FILE *file;
        char *FileName;

        FileSystem(char* file_name){
            file = fopen(file_name, "r");
            FileName = file_name;
        }
        	
        ~FileSystem()
	    {
            fclose(file);
        }

        int  countLines()
        {
               int CountLines = 0;
               int ch, pre = EOF; 
               while ( ( ch = fgetc(file) ) != EOF ) { 
                                  pre = ch; 
                                  if ( ch == '\n' ) 
                                              CountLines++;
                        }
                fclose(file);
                file = fopen(FileName, "r");
            
            return CountLines;
        }
        int ScanPerson(){
                person Student;
                printf("Введите имя студента >> \033[32m");
                    scanf("%s", Student.FIO.Name); 
                    printf("\033[0m");
                printf("Введите Фамилию студента >> \033[32m ");
                    scanf("%s", Student.FIO.Family);
                    printf("\033[0m");                
                printf("Введите Отчество студента >>  \033[32m");
                    scanf("%s", Student.FIO.Sec_name); 
                    printf("\033[0m");
                printf("Введите день рождения студента >>  \033[32m");
                    scanf("%d",&Student.Date_birth.day); 
                    printf("\033[0m");
                printf("Введите месяц рождения студента >>  \033[32m");
                    scanf("%d",&Student.Date_birth.mounth); 
                    printf("\033[0m");
                printf("Введите год рождения студента >>  \033[32m");
                    scanf("%d",&Student.Date_birth.year);
                    printf("\033[0m");
                printf("Введите гендерную принадлежность студента >>  \033[32m");
                    scanf("%s", Student.Gender);  
                    printf("\033[0m");
                printf("Введите год поступления в учебное заведение студента >>  \033[32m");
                    scanf("%d",&Student.inst.YearAdmission); 
                    printf("\033[0m");
                printf("Введите название института студента >>  \033[32m");
                    scanf("%s", Student.inst.institut); 
                    printf("\033[0m");
                printf("Введите кафедру студента >>  \033[32m");
                    scanf("%s", Student.inst.kafedra); 
                    printf("\033[0m");
                printf("Введите учебную группу студента >>  \033[32m");
                    scanf("%s", Student.inst.StudyGroup); 
                    printf("\033[0m");
                printf("Введите номер зачетной книги студента >>  \033[32m");
                    scanf("%s", Student.inst.CreditNumber); 
                    printf("\033[0m\n");
                FILE *file2 = NULL;
                file2 = fopen("data.bin", "wb");
                fwrite(&Student, sizeof(person), 1, file2);
                fclose(file2);

                //EchoStudent(Student);

            return 0;
        }
        int GetPersonFromFile(){
                char *estr;

                int cnt_lines = countLines();
                char buf[256];
                person Student;
                cout << "+--------------------------------------------------------------------------------------+" << '\n';
                
                FILE *file2 = NULL;
                file2 = fopen("data.bin", "rb");
                fread(&Student, sizeof(person), 1, file2);
                EchoStudent(Student);         
            return 0;
            
        }
};
