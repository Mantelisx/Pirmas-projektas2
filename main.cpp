#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using std::cout; 
using std::cin;
using std::endl;
using std::string;

const int C = 10;

struct data{
    string vardas, pavarde;
    int nd[C]={0}, egz=0;
    double rez=0, mediana=0;
    std::vector<int>v;
};

void ivestis(data& temp);
void isved(data& temp);
void isvedmediana(data& temp);
void rikiuok(int M[], int n);
void ivestis1(data& temp);

int main()
{
    setlocale(LC_ALL, "Lithuanian");
    data A;
    data* mas = new data[3];
    int mok = 3;
    int a;
    cout << "---------------------------------------------------------------- " << endl;
    cout << "Ar norite, kad pazymius programa generuotu atsitiktinai? 1 – Taip, 0 – Ne" << endl;
    cin >> a;
    if(!a){

    cout << "Rasykite 0, jei pazymiai baigiasi" << endl;
    for(int i =0; i<mok; i++){
        ivestis(mas[i]);
    }

    cout << "---------------------------------------------------------------- " << endl;
    cout << "Jei norite Vidurkio: rasykite – 1, jei norite Medianos rasykite – 0 " << endl;

    cin >> a;

    if (a==1){
        cout << std::left << std::setw(10) << "Vardas " << std::setw(10) << "Pavardė " << std::setw(10) << "Galutinis (Vid.) " << endl;
        cout << "---------------------------------------------------------------- " << endl;
            for(int i = 0; i<mok; i++){
                isved(mas[i]);
            }
    }
    else{
        cout << std::left << std::setw(10) << "Vardas " << std::setw(10) << "Pavardė " << std::setw(10) << "Galutinis (Med.) " << endl;
        cout << "---------------------------------------------------------------- " << endl;
            for(int i = 0; i<mok; i++){
                isvedmediana(mas[i]);
            }
    }

    }
    else {

    for(int i =0; i<mok; i++){
        ivestis1(mas[i]);
    }

    cout << "---------------------------------------------------------------- " << endl;
    cout << "Jei norite Vidurkio: rasykite – 1, jei norite Medianos rasykite – 0 " << endl;

    cin >> a;

    if (a==1){
        cout << std::left << std::setw(10) << "Vardas " << std::setw(10) << "Pavardė " << std::setw(10) << "Galutinis (Vid.) " << endl;
        cout << "---------------------------------------------------------------- " << endl;
            for(int i = 0; i<mok; i++){
                isved(mas[i]);
            }
    }
    else{
        cout << std::left << std::setw(10) << "Vardas " << std::setw(10) << "Pavardė " << std::setw(10) << "Galutinis (Med.) " << endl;
        cout << "---------------------------------------------------------------- " << endl;
            for(int i = 0; i<mok; i++){
                isvedmediana(mas[i]);
            }
    }
    }


    delete[] mas;
    system("pause");
    //return 0;
}




void ivestis(data& temp){
    int n=0;
    int k=1;
    double vidurkis = 0;
    int paz[C];

    cout << "Iveskite varda: "; cin >> temp.vardas;
    cout << "Iveskite pavarde: "; cin >> temp.pavarde;
    while(k){    //
        cout << "Iveskite " << n + 1 << " - a pazymi: ";
        cin >> temp.nd[n];  k = temp.nd[n];
            // laikinas masyvas medianai skaiciuoti
        vidurkis += temp.nd[n];
        if(temp.nd[n]!=0) {
                paz[n] = temp.nd[n];            //darbas su masyvu
                temp.v.push_back(temp.nd[n]);   //darbas su vektoriais
                n++;
        }
    }
    vidurkis = vidurkis/n;
    cout << "Iveskite egzamino ivertinima: "; cin >> temp.egz;  paz[n]=temp.egz;
    temp.rez=vidurkis*0.4+temp.egz*0.6;

    // medianos skaiciavimas
    rikiuok(paz, n+1);
    if ((n+1)%2==1){
        temp.mediana=paz[(n+1)/2];
    }
    else{
       temp.mediana=(paz[(n+1)/2] + paz[((n+1)/2)-1])/2.0;
    }
}

void ivestis1(data& temp){
    int n=0;
    int k=1;
    double vidurkis = 0;
    int paz[C];
    srand((unsigned) time(0));

    cout << "Iveskite varda: "; cin >> temp.vardas;
    cout << "Iveskite pavarde: "; cin >> temp.pavarde;
    cout << "pazymiai: " << endl;
    for(int i = 0; i<10; i++){    //
        temp.nd[i] = (rand() % 10) + 1;
        cout << temp.nd[i] << " " ;
        vidurkis += temp.nd[i];
           //darbas su masyvu
                temp.v.push_back(temp.nd[i]);   //darbas su vektoriais
                n++;

    }

    vidurkis = vidurkis/n;
    temp.egz=(rand() % 10) + 1;
    cout << endl;
    cout << "Egzaminas: " << temp.egz << endl;

    temp.rez=vidurkis*0.4+temp.egz*0.6;

    // medianos skaiciavimas
    rikiuok(temp.nd, n+1);
    if ((n+1)%2==1){
        temp.mediana=temp.nd[(n+1)/2];
    }
    else{
       temp.mediana=(temp.nd[(n+1)/2] + temp.nd[((n+1)/2)-1])/2.0;
    }
}

void isved(data& temp){
    cout << std::left << std::setw(10) << temp.vardas << " " << std::setw(10) << temp.pavarde;
    cout << std::setw(10) << std::fixed << std::setprecision(2) <<temp.rez << " " << endl;
}

void isvedmediana(data& temp){
    cout << std::left << std::setw(10) << temp.vardas << " " << std::setw(10) << temp.pavarde;
    cout << std::setw(10) << std::fixed << std::setprecision(2) <<temp.mediana << " " << endl;
}

void rikiuok(int M[], int n){
    int t;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(M[i]>M[j])
			{
				t=M[i];
				M[i]=M[j];
				M[j]=t;
			}
		}
	}
}

