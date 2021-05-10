#include <iostream>
using namespace std;

struct Date_birth{
    int day = -1;
    int mounth = -1;
    int year =-1;
};






struct inst{
    char institut[10];
    char kafedra[10];
    int YearAdmission = 0;
    char StudyGroup[20];
    char CreditNumber[7];
};
struct subject{
    char name[25];
    int mark = -1;
};
struct sessions{
    struct subject subj[10];
};
struct FIO{
        char Name[20];
        char Family[20];
        char Sec_name[20];
};
struct person_model{
        struct FIO FIO;
        struct Date_birth Date_birth;
        struct inst inst;
        char Gender[8];
        struct sessions sessions[9];
};
int EchoStudent(person_model student){
    //if(!(student.Date_birth.day ==-1 && student.Date_birth.mounth==-1 && student.Date_birth.year == -1)){
                int exit_code = 0;
                //if(!((student.Date_birth.day >= 1) & (student.Date_birth.day  <= 31))) 
                //    cout << "неверная дата рождения\n";
              //  if(!((student.Date_birth.mounth >= 1) & (student.Date_birth.mounth <= 12))) 
                  //  cout << "неверная дата рождения\n";

                cout << "|" << student.FIO.Family << " "<< student.FIO.Name << " "<<student.FIO.Sec_name << "|";
                cout << student.Date_birth.day<< "." << student.Date_birth.mounth << "." <<student.Date_birth.year << "|";
                cout << student.Gender << "|";
                cout << student.inst.YearAdmission << "|" << student.inst.institut << "|" << student.inst.kafedra << "|";
                cout << student.inst.StudyGroup << "|" << student.inst.CreditNumber<<"|\n";
                cout << "+--------------------------------------------------------------------------------------+" << '\n';
    //}

    return 0;
}    
int EchoStudent_not_full(int counter, person_model student){
                if(!(student.Date_birth.day ==-1 && student.Date_birth.mounth==-1 && student.Date_birth.year == -1)){
                    int exit_code = 0;
               
                cout << "+-------------------------------------------------+" << '\n';

                cout << "|" << counter << ") "<< student.FIO.Family << " "<< student.FIO.Name << " "<<student.FIO.Sec_name << "|";
                cout << student.Date_birth.day<< "." << student.Date_birth.mounth << "." <<student.Date_birth.year << "|\n";
                cout << "+-------------------------------------------------+" << '\n';
    }
    return 0;
}