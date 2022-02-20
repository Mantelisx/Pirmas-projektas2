#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iterator>
#include <algorithm>

//#include <stdio.h>
//#include <ctype.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::sort;

const int C = 10;

struct data{
    string vardas, pavarde;
    int nd[C]={0}, egz=0;
    double rez=0, mediana=0;
    //std::vector<int>v;
};

void ivestis(data& temp);
void isved(const data& temp);
void isvedmediana(const data& temp);
void rikiuok(int M[], int n);
void ivestis1(data& temp);

bool isNumber(const string& s)
{
    for (char const &ch : s) {
        if (std::isdigit(ch) == 0)
            return false;
    }
    return true;
 }

int main()
{
    setlocale(LC_ALL, "Lithuanian");
    int mok = 3;    // nustatomas mokiniu skaicius
    //data* mas = new data[mok];
    vector<data> sarasas;
    data laik;
    sarasas.reserve(mok);
    string abc;
    cout << "---------------------------------------------------------------- " << endl;
    cout << "Ar norite, kad pazymius programa generuotu atsitiktinai? 1 – Taip, 0 – Ne" << endl;
    cin >> abc;

    if(isNumber(abc)){

        if(abc=="0"){
            cout << "Rasykite 0, jei pazymiai baigiasi (max nd pazymiu yra 10)" << endl;
            for(int i =0; i<mok; i++){
                ivestis(laik);
                sarasas.push_back(laik);
            }

    cout << "---------------------------------------------------------------- " << endl;
    cout << "Jei norite Vidurkio: rasykite – 1, jei norite Medianos rasykite – 0 " << endl;

    cin >> abc;

            if(isNumber(abc)){

                if (abc=="1"){
                    cout << std::left << std::setw(10) << "Vardas " << std::setw(10) << "Pavarde " << std::setw(10) << "Galutinis (Vid.) " << endl;
                    cout << "---------------------------------------------------------------- " << endl;
                    for(const auto &el : sarasas){
                        isved(el);
                    }
                }

                else if(abc=="0"){
                    cout << std::left << std::setw(10) << "Vardas " << std::setw(10) << "Pavarde " << std::setw(10) << "Galutinis (Med.) " << endl;
                    cout << "---------------------------------------------------------------- " << endl;
                    for(const auto &el : sarasas){
                        isvedmediana(el);
                    }
                }
            }
            else cout << "galbut ivedete raide, is naujo paleiskite programa" << endl;

        }

        else if(abc=="1"){

            for(int i =0; i<mok; i++){
                ivestis1(laik);
                sarasas.push_back(laik);
            }

            cout << "---------------------------------------------------------------- " << endl;
            cout << "Jei norite Vidurkio: rasykite – 1, jei norite Medianos rasykite – 0 " << endl;

            cin >> abc;

            //////////////////////////////
            if(isNumber(abc)){

                if (abc=="1"){
                    cout << std::left << std::setw(10) << "Vardas " << std::setw(10) << "Pavarde " << std::setw(10) << "Galutinis (Vid.) " << endl;
                    cout << "---------------------------------------------------------------- " << endl;
                    for(const auto &el : sarasas){
                        isved(el);
                    }
                }
                else if(abc=="0"){
                    cout << std::left << std::setw(10) << "Vardas " << std::setw(10) << "Pavarde " << std::setw(10) << "Galutinis (Med.) " << endl;
                    cout << "---------------------------------------------------------------- " << endl;
                    for(const auto &el : sarasas){
                        isvedmediana(el);
                    }
                }
                else cout << "galbut ivedete raide (ar ne ta skaiciu), is naujo paleiskite programa" << endl;
            }
            else cout << "galbut ivedete raide, is naujo paleiskite programa" << endl;
        }
        else cout << "galbut ivedete raide (ar ne ta skaiciu), is naujo paleiskite programa" << endl;

    }

    else {
        cout << "ivesta blogai, leiskite programa is naujo (patikrinkite gal irasete raide)" << endl;
    }



    //delete[] mas;
    sarasas.clear();
    system("pause");
    return 0;
}




void ivestis(data& temp){
    int n=0;
    int k=1;
    double vidurkis = 0;
    string s1;

    cout << "Iveskite varda: "; cin >> temp.vardas;
    cout << "Iveskite pavarde: "; cin >> temp.pavarde;
    while(k && n < C){    //

        cout << "Iveskite " << n + 1 << " - a pazymi: ";
       // cin >> temp.nd[n];
        cin >> s1;
        //s1 = std::to_string(temp.nd[n]);// pavercia i stringa
        if(isNumber(s1) && !(std::stoi(s1) > 10 || std::stoi(s1) < 0) ){
            temp.nd[n] = std::stoi(s1);     // konvertuoja string i int tipa
        }
        else {
            temp.nd[n] = 10;
            cout << "galimai ivedete ne numeri arba netinkama pazymi todel " << n + 1 << " mokiniui(-ei) jis buvo pakeistas i 10" << endl;
        }

        k = temp.nd[n];
        vidurkis += temp.nd[n];

        if(temp.nd[n]!=0) {
            n++;
        }
    }


    if(n!=0){
        vidurkis = vidurkis/n;
    }
    else vidurkis = 0;



    cout << "Iveskite egzamino ivertinima: "; //cin >> temp.egz;
    cin >> s1;
    if (isNumber(s1) && !(std::stoi(s1) > 10 || std::stoi(s1) < 0)){
        temp.egz = std::stoi(s1);
    }
    else {
        temp.egz = 10;
        cout << "galimai ivedete ne numeri arba netinkama egzamino pazymi todel " << n + 1 << " mokiniui(-ei) jis buvo pakeistas i 10" << endl;
    }
    temp.rez=vidurkis*0.4+temp.egz*0.6;

    // medianos skaiciavimas
    rikiuok(temp.nd, n);
    if (n%2==1){
        temp.mediana=temp.nd[n/2]*0.4+temp.egz*0.6;
    }
    else{
       temp.mediana=((temp.nd[n/2] + temp.nd[(n/2)-1])/2.0)*0.4+temp.egz*0.6;
    }
}

void ivestis1(data& temp){
    int n=0;
    double vidurkis = 0;
    srand((unsigned) time(0));

    cout << "Iveskite varda: "; cin >> temp.vardas;
    cout << "Iveskite pavarde: "; cin >> temp.pavarde;
    cout << "pazymiai: " << endl;
    for(int i = 0; i<10; i++){    //C
        temp.nd[i] = (rand() % 10) + 1; // pazymiai nuo 1 iki 10
        cout << temp.nd[i] << " " ;
        vidurkis += temp.nd[i];
        n++;

    }

    vidurkis = vidurkis/n;
    temp.egz=(rand() % 10) + 1;
    cout << endl;
    cout << "Egzaminas: " << temp.egz << endl;

    temp.rez=vidurkis*0.4+temp.egz*0.6;

    // medianos skaiciavimas
    rikiuok(temp.nd, n);
    if (n%2==1){
        temp.mediana=temp.nd[n/2]*0.4+temp.egz*0.6;
    }
    else{
       temp.mediana=((temp.nd[n/2] + temp.nd[(n/2)-1])/2.0)*0.4+temp.egz*0.6;
    }
}

void isved(const data& temp){
    cout << std::left << std::setw(10) << temp.vardas << " " << std::setw(10) << temp.pavarde;
    cout << std::setw(10) << std::fixed << std::setprecision(2) <<temp.rez << " " << endl;
}

void isvedmediana(const data& temp){
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
