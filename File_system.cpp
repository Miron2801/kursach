#define MAX_COLLUMS_IN_FILE 80

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
            file = fopen(FileName, "r");
            FileName = file_name;
        }
        	
        ~FileSystem()
	    {
            fclose(file);
        }

        int  countLines()
        {
               int CountLines;
               int ch, pre = EOF; 
               while ( ( ch = fgetc(file) ) != EOF ) { 
                        pre = ch; 
                        if ( ch == '\n' ) 
                                CountLines++;
                    
                        }
            
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
                    scanf("%d",&Student.inst.УearAdmission); 
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

                EchoStudent(Student);

            return 0;
        }
        int GetPersonFromFile(){
            person Student;
            fscanf(file,"%s%s%s%d%d%d%s%d%s%s%s%s",
               Student.FIO.Name,
               Student.FIO.Family,
               Student.FIO.Sec_name,
               &Student.Date_birth.day,
               &Student.Date_birth.mounth,
               &Student.Date_birth.year,
               Student.Gender,
               &Student.inst.УearAdmission,
               Student.inst.institut,
               Student.inst.kafedra,
               Student.inst.StudyGroup,
               Student.inst.CreditNumber
               );

            EchoStudent(Student);
            return 0;
            
        }
};
