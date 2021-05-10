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
                if (changer > count_users | changer < 0){
                        cout << "Повторите ввод данные некорректны\n";
                        goto redo_act;
                }

  
                
                FILE *file_edit = NULL;
                file_edit = fopen("data/data_buff.bin", "wb");
                fseek(file2_R, 0, SEEK_SET);

                unsigned long int pos_r = ftell (file2_R);
                unsigned long int pos_w = ftell(file_edit);
                for (int i=0; i < count_users; i++){
                        person_model Student;

                        fread(&Student, sizeof(person_model), 1, file2_R);
                        if(ftell(file2_R) == pos_r)
                            break;
                        if(i == changer){
                                 fseek(file2_R , pos_r + sizeof(person_model), SEEK_SET );
                                 pos_r = ftell(file2_R);
                                 continue;
                        }

                        fwrite(&Student, sizeof(person_model), 1, file_edit);
                        fseek(file_edit , pos_w + sizeof(person_model), SEEK_SET );
                        fseek(file2_R , pos_r + sizeof(person_model), SEEK_SET );
                        pos_r = ftell(file2_R);
                        pos_w = ftell(file_edit);


                }
                fclose(file2_R);
                fclose(file_edit);
                remove(FileName);
                rename("data/data_buff.bin", FileName );
                cout <<"успех\n";
            return 0;
        }
        int edit_record(){


               FILE *file2_R = NULL;
                file2_R = fopen(FileName, "rb");
                if (file2_R == NULL) {
                        printf("Файл не существует\n");
                        };

redo_act1:      fseek(file2_R, 0, SEEK_SET);
                unsigned long position = ftell(file2_R);
                count_users = countLines(); 
                system("clear");

                 for (int i=0; i < count_users; i++){
                        person_model Student;

                        fread(&Student, sizeof(person_model), 1, file2_R);
                        if(ftell(file2_R) == position)
                            break;
                        EchoStudent_not_full(i, Student);
                        fseek(file2_R , position + sizeof(person_model), SEEK_SET );
                        position = ftell(file2_R);
                }
                cout << "Какого пользовтеля изменить? \033[31m-1 - отмена \033[0m>> \033[33m";
                int changer = 0;
                cin >> changer;
                cout << "\033[0m\n";
                if(changer == -1){
                        cout << "Выход\n";
                        return -1;
                }
                if (changer > count_users){
                        cout << "Повторите ввод данные некорректны\n";
                        goto redo_act1;
                }
            
                fseek(file2_R , 0, SEEK_SET );
                unsigned long int pos_r = ftell (file2_R);
                person_model Student_to_edit;

                for (int i=0; i < count_users; i++){
                        fread(&Student_to_edit, sizeof(person_model), 1, file2_R);
                        if(ftell(file2_R) == pos_r)
                            break;
                        if(i == changer){
                                 fseek(file2_R , pos_r + sizeof(person_model), SEEK_SET );
                                 pos_r = ftell(file2_R);
                                 cout << "\n\033[32mВыбран студент: \033[0m\n";
                                 EchoStudent(Student_to_edit);
                                 break;
                        }

                        fseek(file2_R , pos_r + sizeof(person_model), SEEK_SET );
                        pos_r = ftell(file2_R);


                }
                char witch;
reenter_y_n:    cout << "Продолжить редактирование ? y/n>> \033[31m";
                cin >> witch;
                cout <<  "\033[0m";
                if(witch == 'n'){
                        goto redo_act1;
                }
                if(witch != 'y'){
                    cout << "Ошибка ввода повтор\n";
                    goto reenter_y_n;
                }
                cout << "Редактирование..... 0 для пропсука параметра 1 для редактирования\n";
                int editpos;

                    printf("Имя студента >> \033[32m");
                    cin >> editpos;
                    printf("\033[0m");                

                    if(editpos == 1){
                            printf("Введите имя студента >> \033[32m");
                            scanf("%s", Student_to_edit.FIO.Name); 
                            printf("\033[0m\n");
                    }

                    printf("Фамилию студента >> \033[32m ");
                    cin >> editpos;
                    printf("\033[0m");                

                    if(editpos == 1){
                                printf("Введите Фамилию студента >> \033[32m ");
                                scanf("%s", Student_to_edit.FIO.Family);
                                printf("\033[0m\n");
                    }     
                               
                    printf("Отчество студента >>  \033[32m");
                    cin >> editpos;
                    printf("\033[0m");  
                    if(editpos == 1){
                        printf("Введите Отчество студента >>  \033[32m");
                        scanf("%s", Student_to_edit.FIO.Sec_name); 
                        printf("\033[0m\n");
                    }

                    printf("день рождения студента >>  \033[32m");
                    cin >> editpos;
                    printf("\033[0m");  
                    if(editpos == 1){
                        printf("Введите день рождения студента >>  \033[32m");
                        scanf("%d",&Student_to_edit.Date_birth.day); 
                        printf("\033[0m\n");
                    }

                    printf("месяц рождения студента >>  \033[32m");
                    cin >> editpos;
                    printf("\033[0m");  
                    if(editpos == 1){
                        printf("Введите Омесяц рождения студента >> \033[32m");
                        scanf("%d",&Student_to_edit.Date_birth.mounth); 
                        printf("\033[0m\n");
                    }

                    printf("год рождения студента >> \033[32m");
                    cin >> editpos;
                    printf("\033[0m");  
                    if(editpos == 1){
                        printf("Введите год рождения студента >>  \033[32m");
                        scanf("%d",&Student_to_edit.Date_birth.year);
                        printf("\033[0m\n");
                    }


                    printf("гендерную принадлежность студента >>  \033[32m");
                    cin >> editpos;
                    printf("\033[0m");  
                    if(editpos == 1){
                        printf("Введите гендерную принадлежность студента >>  \033[32m");
                        scanf("%s", Student_to_edit.Gender);  
                        printf("\033[0m\n");
                    }

                    printf("год поступления в учебное заведение студента >> \033[32m");
                    cin >> editpos;
                    printf("\033[0m");  
                    if(editpos == 1){
                        printf("Введите год поступления в учебное заведение студента >>  \033[32m");
                        scanf("%d",&Student_to_edit.inst.YearAdmission);
                        printf("\033[0m\n");
                    }


                    printf("название института студента >> \033[32m");
                    cin >> editpos;
                    printf("\033[0m");  
                    if(editpos == 1){
                        printf("Введите название института студента >>  \033[32m");
                        scanf("%s", Student_to_edit.inst.institut); 
                        printf("\033[0m\n");
                    }

                    printf("кафедру студента >> \033[32m");
                    cin >> editpos;
                    printf("\033[0m");  
                    if(editpos == 1){
                        printf("Введите кафедру студента >> \033[32m");
                        scanf("%s", Student_to_edit.inst.kafedra);
                        printf("\033[0m\n");
                    }

                    printf("учебную группу студента >> \033[32m");
                    cin >> editpos;
                    printf("\033[0m");  
                    if(editpos == 1){
                        printf("Введите название института студента >>  \033[32m");
                        scanf("%s", Student_to_edit.inst.StudyGroup);
                        printf("\033[0m\n");
                    }

                    printf("номер зачетной книги студента >> \033[32m");
                    cin >> editpos;
                    printf("\033[0m");  
                    if(editpos == 1){
                        printf("Введите номер зачетной книги студента >>  \033[32m");
                        scanf("%s", Student_to_edit.inst.CreditNumber);
                        printf("\033[0m\n");
                    }
                EchoStudent(Student_to_edit);

                FILE *file_edit = NULL;
                file_edit = fopen("data/data_buff.bin", "wb");
                fseek(file2_R, 0, SEEK_SET);
                fseek(file_edit, 0, SEEK_SET);
                unsigned long int pos_w = ftell(file_edit);
                pos_r = ftell (file2_R);
                pos_w = ftell (file_edit);
                for (int i=0; i < count_users; i++){
                        person_model Student;
                        fread(&Student, sizeof(person_model), 1, file2_R);
                        if(ftell(file2_R) == pos_r)
                            break;
                        if(i == changer)
                                 fwrite(&Student_to_edit, sizeof(person_model), 1, file_edit);
                        else
                                 fwrite(&Student, sizeof(person_model), 1, file_edit);
                        
                        fseek(file_edit , pos_w + sizeof(person_model), SEEK_SET );
                        fseek(file2_R , pos_r + sizeof(person_model), SEEK_SET );
                        pos_r = ftell(file2_R);
                        pos_w = ftell(file_edit);


                }
                fclose(file2_R);
                fclose(file_edit);
                remove(FileName);
                rename("data/data_buff.bin", FileName );            
                cout <<"успех\n";
            return 0;

        }
};
