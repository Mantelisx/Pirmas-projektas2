#include <iostream>
#include <iomanip>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

struct data{
    string vardas, pavarde;
    int nd[10]={0}, egz=0;
    double rez=0;
};

void ivestis(data& temp);
void isved(data& temp);
bool check_number(string str);  // tikrina ar numeris

int main()
{
    setlocale(LC_ALL, "Lithuanian");
    data A;
    data* mas = new data[3];
    int mok = 3;

    for(int i =0; i<mok; i++){
        ivestis(mas[i]);
    }

    cout << std::left << std::setw(10) << "Vardas " << std::setw(10) << "Pavardė " << std::setw(10) << "Galutinis (Vid.) " << endl;
    cout << "---------------------------------------------------------------- " << endl;

   for(int i = 0; i<mok; i++){
    isved(mas[i]);
   }

    delete[] mas;
    system("pause");
    //return 0;
}




void ivestis(data& temp){
    int n = 3;
    double vidurkis = 0;
    cout << "Iveskite varda: "; cin >> temp.vardas;
    cout << "Iveskite pavarde: "; cin >> temp.pavarde;
    for(int i = 0; i < n; i++){
        cout << "Iveskite " << i + 1 << " - a pazymi: ";
        cin >> temp.nd[i];
        vidurkis += temp.nd[i];
    }
    vidurkis = vidurkis/n;
    cout << "Iveskite egzamino ivertinima: "; cin >> temp.egz;
    temp.rez=vidurkis*0.4+temp.egz*0.6;
}

void isved(data& temp){
    cout << std::left << std::setw(10) << temp.vardas << " " << std::setw(10) << temp.pavarde;
    cout << std::setw(10) << std::fixed << std::setprecision(2) <<temp.rez << " " << endl;
}


