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
struct person{
        struct FIO FIO;
        struct Date_birth Date_birth;
        struct inst inst;
        char Gender[8];
        struct sessions sessions[9];
};
int EchoStudent(struct person student){
    int exit_code = 0;
    if(!((student.Date_birth.day >= 1) & (student.Date_birth.day  <= 31))) 
        cout << "неверная дата рождения\n";
    if(!((student.Date_birth.mounth >= 1) & (student.Date_birth.mounth <= 12))) 
        cout << "неверная дата рождения\n";

    cout << "|" << student.FIO.Family << " "<< student.FIO.Name << " "<<student.FIO.Sec_name << "|";
    cout << student.Date_birth.day<< "." << student.Date_birth.mounth << "." <<student.Date_birth.year << "|";
    cout << student.Gender << "|";
    cout << student.inst.YearAdmission << "|" << student.inst.institut << "|" << student.inst.kafedra << "|";
    cout << student.inst.StudyGroup << "|" << student.inst.CreditNumber<<"|\n";
    cout << "+--------------------------------------------------------------------------------------+" << '\n';
     
    return exit_code;
}    

// int main()
// {
//     person person;
//     person.FIO.Name[0] = 'q';
//     person.FIO.Family[0] = 'q';
//     person.FIO.Sec_name[0] = 'q';
//     person.Date_birth.day = 28;
//     person.Date_birth.mounth = 31;
//     person.Date_birth.year = 2003;
//     person.inst.УearAdmission = 2020;
//     person.inst.institut[0] = 'K';
//     person.inst.kafedra[0]  = 'K';
//     person.inst.StudyGroup[0] = 'F';
//     person.inst.CreditNumber[0] = 'q';
//     person.Gender[0] = 'q';
//     person.sessions[0].subj[0].mark = 5;
//     person.sessions[0].subj[0].name[0] = 'q';
//     person.sessions[0].subj[1].mark = 5;
    
//     EchoStudent(person);

//     return 0;

// }
