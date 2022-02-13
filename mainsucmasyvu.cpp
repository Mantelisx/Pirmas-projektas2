#include <iostream>
#include <iomanip>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

const int C = 10;

struct data{
    string vardas, pavarde;
    int nd[C]={0}, egz=0;
    double rez=0, mediana=0;
};

void ivestis(data& temp);
void isved(data& temp);
void isvedmediana(data& temp);
void rikiuok(int M[], int n);

int main()
{
    setlocale(LC_ALL, "Lithuanian");
    data A;
    data* mas = new data[3];
    int mok = 3;
    cout << "---------------------------------------------------------------- " << endl;
    cout << "Rasykite 0, jei pazymiai baigiasi" << endl;
    for(int i =0; i<mok; i++){
        ivestis(mas[i]);
    }

    cout << "---------------------------------------------------------------- " << endl;
    cout << "Jei norite Vidurkio: rasykite – 1, jei norite Medianos rasykite – 0 " << endl;
    int a;
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
                paz[n] = temp.nd[n];
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

