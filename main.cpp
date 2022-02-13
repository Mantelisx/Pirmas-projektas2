#include <iostream>
#include <iomanip>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

struct data{
    string vardas, pavarde;
    int nd[5]={0}, egz=0;
    double rez=0;
};

void ivestis(data& temp);
void isved(data& temp);

int main()
{
    data A;
    data* mas = new data[3];

    for(int i =0; i<3; i++){
        ivestis(mas[i]);
    }

   // ivestis(A);
   // isved(A);

   for(int i = 0; i<3; i++){
    isved(mas[i]);
   }

    delete[] mas;
    system("pause");
    //return 0;
}

void ivestis(data& temp){
    int n = 3;
    cout << "Iveskite varda: "; cin >> temp.vardas;
    cout << "Iveskite pavarde: "; cin >> temp.pavarde;
    for(int i = 0; i < n; i++){
        cout << "Iveskite " << i + 1 << " - a pazymi: ";
        cin >> temp.nd[i];
    }
    cout << "Iveskite egzamino ivertinima: "; cin >> temp.egz;
}

void isved(data& temp){
    cout << std::left << std::setw(10) << temp.vardas << " " << std::setw(10) << temp.pavarde;
    for(int i = 0; i < 3; i++) cout << " " << std::setw(10) << temp.nd[i];
    cout << temp.egz << endl;
