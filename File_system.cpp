#include "models.cpp"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class FileSystem {
    public:
        FILE *file = NULL;
        char *FileName;
        int count_users = 0;
        FileSystem(char* file_name){
                file = fopen(file_name, "ab+");
                FileName = file_name;
        } 

        ~FileSystem()
	    {
            fclose(file);
        }

        int  countLines()
        {

                                FILE *file2_R = NULL;
                                file2_R = fopen(FileName, "rb");
                                if (file2_R == NULL) {
                                        printf("Файл не существует\n");
                                        return -1;
                                        };
                                
                                unsigned long position = ftell(file2_R); 
                                int count_students = 0;
                                while (1){
                                                person Student;
                                                
                                                fread(&Student, sizeof(person), 1, file2_R);
                                                if(ftell(file2_R) == position)
                                                    break;
                                                fseek(file2_R , position + sizeof(person), SEEK_SET );
                                                if(ftell(file2_R) == position)
                                                    break;
                                                position = ftell(file2_R);
                                                count_students++;
                                            }
                                        
                fclose(file2_R);  
                count_users = count_students;
                return count_students;       
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

                fwrite(&Student, sizeof(person), 1, file);


            return 0;
        }
        int GetPersonFromFile(){
                cout << "+--------------------------------------------------------------------------------------+" << '\n';
                
                FILE *file2_R = NULL;
                file2_R = fopen(FileName, "rb");
                if (file2_R == NULL) {
                        printf("Файл не существует\n");
                        return -1;
                        };
                
                unsigned long position = ftell(file2_R); 
                    while (1){
                        person Student;
                        
                        fread(&Student, sizeof(person), 1, file2_R);
                        if(ftell(file2_R) == position)
                            break;
                        EchoStudent(Student); 
                        fseek(file2_R , position + sizeof(person), SEEK_SET );
                        if(ftell(file2_R) == position)
                            break;
                        position = ftell(file2_R);
                    }
                
                fclose(file2_R);        
            return 0;
            
        }
};
