#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <random>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::sort;

const int C = 10;

struct data{
    string vardas, pavarde;
    int nd[C] = {0}, egz=0;
    double rez=0, mediana=0;

};

void ivestis(data& temp);
void isved(const data& temp);
void isvedmediana(const data& temp);
void rikiuok(int M[], int n);
void ivestis1(data& temp, int kiek);
bool isNumber(const string& s);


int main()
{
    setlocale(LC_ALL, "Lithuanian");
    int mok = 0;    // nustatomas mokiniu skaicius
    vector<data> sarasas;
    data laik;
    string abc;
    string dar;

    cout << "---------------------------------------------------------------- " << endl;

            do{
                mok++;
                sarasas.reserve(mok);
                cout << "Ar norite kad " << mok << " -am(ai) mokiniui(-ei) pazymiai butu generuojami atsitiktinai? (bet koks simbolis) - taip, 0 - ne" << endl;
                cin >> abc;
                if(abc == "0"){
                    ivestis(laik);
                    sarasas.push_back(laik);
                }
                else {
                    cout << "Kiek nd pazymiu turi mokinys? (max - " << C << " )" << endl;
                    cin >> abc;
                    while(!(isNumber(abc)) || (std::stoi(abc) > 10 || std::stoi(abc) < 0) ){
                        cout << "Ivedete blogai, veskite dar karta " << endl;
                        cin >> abc;
                    }
                    ivestis1(laik, std::stoi(abc));
                    sarasas.push_back(laik);
                }
                cout << "Ar norite prideti dar viena mokini? (bet koks simbolis) - taip, 0 - ne" << endl;
                cin >> dar;
                }while(dar!="0");


    cout << "---------------------------------------------------------------- " << endl;
    cout << "Jei norite Vidurkio: rasykite – 1, jei norite Medianos rasykite – 0 " << endl;

    cin >> abc;

    while((abc!="1")&&(abc!="0")){
        cout << "Ivedete blogai, veskite dar karta " << endl;
        cin >> abc;
    }


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

    sarasas.clear();
    system("pause");
    return 0;
}


bool isNumber(const string& s){

    for (char const &ch : s) {
        if (std::isdigit(ch) == 0)
            return false;
    }
    return true;
 }

void ivestis(data& temp){
    int n=0;
    int k=1;
    double vidurkis = 0;
    string s1;

    cout << "Iveskite varda: "; cin >> temp.vardas;
    cout << "Iveskite pavarde: "; cin >> temp.pavarde;
    cout << "Rasykite 0, jei pazymiai baigiasi (max nd pazymiu yra " << C << " )" << endl;

   // temp.nd.reserve(1);
    while(k && n < C){    //

        cout << "Iveskite " << n + 1 << " - a pazymi: ";
       // cin >> temp.nd[n];
        cin >> s1;
        //s1 = std::to_string(temp.nd[n]);// pavercia i stringa
        if(isNumber(s1) && !(std::stoi(s1) > 10 || std::stoi(s1) < 0) ){
            temp.nd[n] = std::stoi(s1);     // konvertuoja string i int tipa
            //temp.nd.push_back(std::stoi(s1));
        }
        else {
            temp.nd[n] = 10;
            //temp.nd.push_back(10);
            cout << "galimai ivedete ne numeri arba netinkama pazymi todel " << n + 1 << " mokiniui(-ei) jis buvo pakeistas i 10" << endl;
        }

        k = temp.nd[n];
        vidurkis += temp.nd[n];
      //  k = temp.nd.back();
       // vidurkis += temp.nd.back();

        if(temp.nd[n]!=0) {
            n++;
           // temp.nd.reserve(n+1);
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
   // sort(temp.nd.begin(), temp.nd.begin()+n);
    if (n%2==1){
        temp.mediana=temp.nd[n/2]*0.4+temp.egz*0.6;
    }
    else{
       temp.mediana=((temp.nd[n/2] + temp.nd[(n/2)-1])/2.0)*0.4+temp.egz*0.6;
    }
}

void ivestis1(data& temp, int kiek){
   // int n=0;
    double vidurkis = 0;
    srand((unsigned) time(0));
   // temp.nd.reserve(kiek);

    cout << "Iveskite varda: "; cin >> temp.vardas;
    cout << "Iveskite pavarde: "; cin >> temp.pavarde;
    cout << "pazymiai: " << endl;
    for(int i = 0; i<kiek; i++){    //C
        temp.nd[i] = (rand() % 10) + 1; // pazymiai nuo 1 iki 10
        cout << temp.nd[i] << " " ;
        vidurkis += temp.nd[i];
       // n++;

    }

    if(kiek!=0){
        vidurkis = vidurkis/kiek;
    }
    else vidurkis = 0;

    temp.egz=(rand() % 10) + 1;
    cout << endl;
    cout << "Egzaminas: " << temp.egz << endl;

    temp.rez=vidurkis*0.4+temp.egz*0.6;

    // medianos skaiciavimas
    rikiuok(temp.nd, kiek);
    //sort(temp.nd.begin(), temp.nd.begin()+kiek);
    if (kiek%2==1){
        temp.mediana=temp.nd[kiek/2]*0.4+temp.egz*0.6;
    }
    else{
       temp.mediana=((temp.nd[kiek/2] + temp.nd[(kiek/2)-1])/2.0)*0.4+temp.egz*0.6;
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
