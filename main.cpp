#include "iostream"
#include "staff_functions.cpp"
using namespace std;

int main()
{
        int code = 0;
        menu Menu;
        Menu.echo_menu();
        cin >> code;
        Menu.memu(code);
        cout << '\n';
        while (code) {
            Menu.echo_menu();
            cin >> code;
            Menu.memu(code);
            cout << '\n';
        }
        return 0;
} 