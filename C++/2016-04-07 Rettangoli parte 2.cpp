#include <cstdlib>
#include <iostream>
using namespace std;
struct Student
{
char name[20];
char familyName[20];
int grade;
};
int main(int argc, char *argv[])
{
    const int MAX_LINE_LENGHT=26;
    char riga[MAX_LINE_LENGHT];    
    ifstream ifs;
    ifs.open("voti.txt");
    int i=atoi("10");
    cout<<i<<endl;
    ifs.getline(riga,MAX_LINE_LENGHT);
    while(!ifs.eof())
    {
        cout<<riga<<endl;
        ifs.getline(riga,MAX_LINE_LENGHT);
    }    
    system("PAUSE");
    return EXIT_SUCCESS;
}
