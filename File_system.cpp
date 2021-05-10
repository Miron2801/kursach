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
                count_users = countLines();

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
                        EchoStudent(Student); 
                        fseek(file2_R , position + sizeof(person_model), SEEK_SET );
                        position = ftell(file2_R);


                }
                
                fclose(file2_R);        
            return 0;
            
        }
        int delete_person(){
                FILE *file2_R = NULL;
                file2_R = fopen(FileName, "rb");
                if (file2_R == NULL) {
                        printf("Файл не существует\n");
                        };
                unsigned long position = ftell(file2_R);
                count_users = countLines(); 
                system("clear");
               // cout << "Какого пользовтеля удалить?"
redo_act:       for (int i=0; i < count_users; i++){
                        person_model Student;

                        fread(&Student, sizeof(person_model), 1, file2_R);
                        if(ftell(file2_R) == position)
                            break;
                        EchoStudent_not_full(i, Student);
                        fseek(file2_R , position + sizeof(person_model), SEEK_SET );
                        position = ftell(file2_R);
                }
                cout << "Какого пользовтеля удалить? -1 - отмена >> ";
                int changer = 0;
                cin >>changer;
                if(changer == -1){
                        cout << "Выход\n";
                        return -1;
                }
                if (changer > count_users){
                        cout << "Повторите ввод данные некорректны\n";
                        goto redo_act;
                }

  
                
                FILE *file_edit = NULL;
                file_edit = fopen("data/dara2.bin", "wb");
                fseek(file2_R, 0, SEEK_SET);
                position = ftell(file2_R);

                for (int i=0; i < count_users; i++){
                        person_model Student;

                        fread(&Student, sizeof(person_model), 1, file2_R);
                        if(ftell(file2_R) == position)
                            break;
                        
                        fwrite(&Student, sizeof(person_model), 1, file_edit);
                        fseek(file_edit , position + sizeof(person_model), SEEK_SET );

                        fseek(file2_R , position + sizeof(person_model), SEEK_SET );
                        position = ftell(file2_R);


                }
            fclose(file_edit);

            return 0;
        }
};
