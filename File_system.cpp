#include "models.cpp"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;
class FileSystem {
    public:
        FILE *file = NULL;
        char *FileName;
        int count_users = 0;
        std::list<person_model> Students;

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
                                                person_model Student;
                                                
                                                fread(&Student, sizeof(person_model), 1, file2_R);
                                                if(ftell(file2_R) == position)
                                                    break;
                                                fseek(file2_R , position + sizeof(person_model), SEEK_SET );
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
                person_model Student;
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

                fwrite(&Student, sizeof(person_model), 1, file);


            return 0;
        }
        int GetPersonsFromFile(){
                cout << "+--------------------------------------------------------------------------------------+" << '\n';
                
                FILE *file2_R = NULL;
                file2_R = fopen(FileName, "rb");
                if (file2_R == NULL) {
                        printf("Файл не существует\n");
                        };
                unsigned long position = ftell(file2_R);
                count_users = countLines(); 
                for (int i=0; i < count_users; i++){
                        person_model Student;

                        fread(&Student, sizeof(person_model), 1, file2_R);
                        if(ftell(file2_R) == position)
                            break;
                        Students.push_back(Student);
                        EchoStudent(Student); 
                        fseek(file2_R , position + sizeof(person_model), SEEK_SET );
                        position = ftell(file2_R);


                }
                
                fclose(file2_R);        
            return 0;
            
        }
        int delete_person(){

            return 0;
        }
};
