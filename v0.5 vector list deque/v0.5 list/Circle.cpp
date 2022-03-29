#include "Circle.h"
/*
bool compare_pavarde(const string &a, const string &b) {
    if (a.pavarde == b.pavarde) return a.vardas < b.vardas;
    return a.pavarde < b.pavarde;
}
*/


list<data> skirtstykStudentus(list<data>& studentai) {
    list<data> kieti, minksti;
    for (const auto& stud : studentai)
        if (stud.rez < 5)
            minksti.push_back(stud);
        else
            kieti.push_back(stud);
    studentai = kieti;
    return minksti;
}

void generuotifailus(string & failopavadinimas, int kiek, int nd) {

   // cout << "Iveskite kiek norite studentu duomenu: " << endl;
    //int kiek;
   // int nd;
   // cin >> kiek;
    string failas;
    if (failopavadinimas == "") {
        failas = "failas" + std::to_string(kiek) + ".txt";
    }
    else failas = failopavadinimas;
    
    ofstream rf(failas);

   // const char* cstr = failas.data();

   // cout << "Iveskite kiek norite, kad studentai turetu nd pazymiu: " << endl;
  //  cin >> nd;

    std::mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
    int_distribution dist(1, 10);


    string ndskaicius = "ND";
    string vardas = "Vardas";
    string pavarde = "Pavarde";

    // failo sudarymas
    auto start = hrClock::now();    // pradedamas skaiciavimas

    rf << std::left << std::setw(15) << "Vardas" << std::right << std::setw(15)  << "Pavarde" ;
    for (int i = 0; i < nd; i++) {
        rf << std::right << std::setw(15) << ndskaicius + std::to_string(i+1) ;
    }
    rf << std::right << std::setw(15) << "Egz." << endl;
    
    for (int i = 0; i < kiek; i++) {
        rf << std::left << std::setw(15) << vardas + std::to_string(i + 1) << std::right << std::setw(15) << pavarde + std::to_string(i + 1);
        for (int j = 0; j < nd; j++) {
            rf << std::right << std::setw(15) << dist(mt);
        }
        rf << std::right << std::setw(15) << dist(mt); if (i+1 != kiek ) rf << endl;    // if sakinys, kad isvengti papildomo nuskaitymo kai pabaigoje failo endline ideda
    }
    
    auto end = hrClock::now();
    std::chrono::duration<double> diff = end - start; // Skirtumas (s)
    std::cout << "Failo sudarymas is " << kiek << " studentu uztruko: " << diff.count() << " s\n";
   

   // remove(cstr);
    failopavadinimas = failas;

    rf.close();
    cout << "failas uzdarytas" << endl;
}

void veiksmaisufailu2(string test) {
    
    /*
    rf << std::left << std::setw(15) << "Vardas " << std::setw(15) << "Pavarde " << std::setw(15) << "Galutinis (Vid.) " << std::setw(15) << "Galutinis (Med.) " << endl;
    rf << "---------------------------------------------------------------- " << endl;
    */
     data temp;
     data nulinis;

     ifstream df(test);
     // ofstream rf("rez_"+test);
     ofstream fiveormore("rez_fiveormore_list" + test);
     ofstream lessthanfive("rez_lessthanfive_list" + test);
     
    int paz=0;
    double vidurkis = 0;
    // vector<data> sarasas;

    list<data> moreoreqfive;
    list<data> lessfive;

    string sw;  // zodis
    int kiekyra = 0;  // kiek is viso  yra elementu

    while ((df.peek() != '\n') && (df >> sw)) {
        kiekyra++;
    }

    auto start = hrClock::now();    // pradedamas skaiciavimas
    while (!df.eof()) {

        //  cout << kiekyra;

          //nuskaitymas
        df >> temp.vardas >> temp.pavarde;
        //cout << "vardas: " << temp.vardas << endl;
        for (int i = 0; i < kiekyra - 3; i++) {
            df >> paz;
            temp.nd.push_back(paz);
            vidurkis += paz;
        }
        df >> temp.egz;

       

        if (temp.nd.size() != 0) vidurkis = vidurkis / (kiekyra - 3);
        else vidurkis = 0;

        temp.rez = vidurkis * 0.4 + temp.egz * 0.6;
        vidurkis = 0;

        //mediana
        sort(temp.nd.begin(), temp.nd.begin() + temp.nd.size());
        if (temp.nd.size() % 2 == 1) {
            temp.mediana = temp.nd[temp.nd.size() / 2] * 0.4 + temp.egz * 0.6;
        }
        else {
            temp.mediana = ((temp.nd[temp.nd.size() / 2] + temp.nd[(temp.nd.size() / 2) - 1]) / 2.0) * 0.4 + temp.egz * 0.6;
        }

        moreoreqfive.push_back(temp);
        /*
        if (temp.rez >= 5) {
            moreoreqfive.push_back(temp);
        }
        else if (temp.rez < 5) {
            lessfive.push_back(temp);
        }
        */
       // cout << "suksirste i vektorius" << endl;

        //temp.nd.clear();
        temp = nulinis;
    }


    auto end = hrClock::now();
    std::chrono::duration<double> diff = end - start; // Skirtumas (s)
    std::cout << "Failo nuskaitymas is " << test << " uztruko: " << diff.count() << " s\n";

    df.close();



   

    //rikiavimas

   // std::sort(sarasas.begin(), sarasas.end(), compare_pavarde);
    //pagal pavarde
    /*
    std::sort(sarasas.begin(), sarasas.end(), [](data a, data b) {
        if (a.pavarde == b.pavarde) return a.vardas < b.vardas;
        return a.pavarde < b.pavarde;
        });
        */
        //pagal varda
        /*
        std::sort(sarasas.begin(), sarasas.end(), [](data a, data b) {
            if (a.vardas == b.vardas) return a.pavarde < b.pavarde;
            return a.vardas < b.vardas;
            });
            */
            //pagal pazymius
    /*
    std::sort(sarasas.begin(), sarasas.end(), [](data a, data b) {
        if (a.rez == b.rez) return a.pavarde < b.pavarde;
        return a.rez < b.rez;
        });
        */
    
    start = hrClock::now();    // pradedamas skaiciavimas
    moreoreqfive.sort([](data a, data b) {
        if (a.rez == b.rez) return a.pavarde < b.pavarde;
        return a.rez < b.rez;
        });
 /*
    std::sort(moreoreqfive.begin(), moreoreqfive.end(), [](data a, data b) {
        if (a.rez == b.rez) return a.pavarde < b.pavarde;
        return a.rez < b.rez;
        });
    //cout << "sort1" << endl;

    std::sort(lessfive.begin(), lessfive.end(), [](data a, data b) {
        if (a.rez == b.rez) return a.pavarde < b.pavarde;
        return a.rez < b.rez;
        });
   // cout << "sort2" << endl;
*/
    end = hrClock::now();
    diff = end - start; // Skirtumas (s)
    cout << test << " Irasu rusiavimas didejimo tvarka su sort uztruko: "   << diff.count() << " s\n";
    




    start = hrClock::now();    // pradedamas skaiciavimas

    lessfive = skirtstykStudentus(moreoreqfive);

    end = hrClock::now();
    diff = end - start; // Skirtumas (s)
    std::cout << test << " Failo skirtsymas i minkstus ir kietus uztruko: " << diff.count() << " s\n";




    //isvedimas
    /*
    for (const auto& el : sarasas) {
        rf << std::left << std::setw(15) << el.vardas << " " << std::setw(15) << el.pavarde;
        rf << std::setw(15) << std::fixed << std::setprecision(2) << el.rez << std::setw(15) << std::fixed << std::setprecision(2) << el.mediana << " " << endl;
    }
    */







    start = hrClock::now();    // pradedamas skaiciavimas

    // isvedimas >=5 galutinis pazymys
    fiveormore << std::left << std::setw(15) << "Vardas " << std::setw(15) << "Pavarde " << std::setw(15) << "Galutinis (Vid.) " << std::setw(15) << "Galutinis (Med.) " << endl;
    fiveormore << "---------------------------------------------------------------- " << endl;
    for (const auto& el : moreoreqfive) {
        if (el.rez >= 5) {
            fiveormore << std::left << std::setw(15) << el.vardas << " " << std::setw(15) << el.pavarde;
            fiveormore << std::setw(15) << std::fixed << std::setprecision(2) << el.rez << std::setw(15) << std::fixed << std::setprecision(2) << el.mediana << " " << endl;
        }
    }

    end = hrClock::now();
    diff = end - start; // Skirtumas (s)
    cout << test << " Irasu studentu, kuriu galutinis balas >=5, irasymo i faila laikas: " << diff.count() << " s\n";

    fiveormore.close();
    moreoreqfive.clear();
   // cout << "daugiau arba lygu 5 iems" << endl;


    start = hrClock::now();    // pradedamas skaiciavimas

    // isvedimas <5 galutinis pazymys
    lessthanfive << std::left << std::setw(15) << "Vardas " << std::setw(15) << "Pavarde " << std::setw(15) << "Galutinis (Vid.) " << std::setw(15) << "Galutinis (Med.) " << endl;
    lessthanfive << "---------------------------------------------------------------- " << endl;
    for (const auto& el : lessfive) {
        if (el.rez < 5) {
            lessthanfive << std::left << std::setw(15) << el.vardas << " " << std::setw(15) << el.pavarde;
            lessthanfive << std::setw(15) << std::fixed << std::setprecision(2) << el.rez << std::setw(15) << std::fixed << std::setprecision(2) << el.mediana << " " << endl;
        }
    }

    end = hrClock::now();
    diff = end - start; // Skirtumas (s)
    cout << test << " Irasu studentu, kuriu galutinis balas <5, irasymo i faila laikas: " << diff.count() << " s\n";

    lessthanfive.close();
    lessfive.clear();
   // cout << "maziau uz 5 is" << endl;


    //rf.close();
     //sarasas.clear();
    
   // cout << "---------------------------------------------------------------- " << endl;
}

void veiksmaisufailu() {
   // string tikrinti;
   // string test = "testas.txt";

   // veiksmaisufailu2("failas100000.txt");
   
   // do{ 
   //     cout << "rasykite bet koki simbolá, jei norite generuoti faila arba 0, jei nenorite testi." << endl;
   //     cin >> tikrinti; 
   //     if (tikrinti != "0") {
           // auto st = hrClock::now();
          //  generuotifailus(test);
         //   auto st = hrClock::now();
           // cout << test << endl;
          //  veiksmaisufailu2(test);
        
   // generuotifailus(test, 10, 7);
   // veiksmaisufailu2(test);

            auto st = hrClock::now();
            veiksmaisufailu2("failas1000.txt");
            auto end = hrClock::now();
            std::chrono::duration<double> difff = end - st; // Skirtumas (s)
            cout << endl;
            cout << "failas1000.txt" <<" Irasu, visas programos sugaiğtas laikas: " << difff.count() << " s\n\n";
            cout << "---------------------------------------------------------------- " << endl;
            system("pause");

            st = hrClock::now();
            veiksmaisufailu2("failas10000.txt");
            end = hrClock::now();
            difff = end - st; // Skirtumas (s)
            cout << endl;
            cout << "failas10000.txt" << " Irasu, visas programos sugaiğtas laikas: " << difff.count() << " s\n\n";
            cout << "---------------------------------------------------------------- " << endl;
            system("pause");

            st = hrClock::now();
            veiksmaisufailu2("failas100000.txt");
            end = hrClock::now();
            difff = end - st; // Skirtumas (s)
            cout << endl;
            cout << "failas100000.txt" << " Irasu, visas programos sugaiğtas laikas: " << difff.count() << " s\n\n";
            cout << "---------------------------------------------------------------- " << endl;
            system("pause");
    
            st = hrClock::now();
            veiksmaisufailu2("failas1000000.txt");
            end = hrClock::now();
            difff = end - st; // Skirtumas (s)
            cout << endl;
            cout << "failas1000000.txt" << " Irasu, visas programos sugaiğtas laikas: " << difff.count() << " s\n\n";
            cout << "---------------------------------------------------------------- " << endl;
            system("pause");

            st = hrClock::now();
            veiksmaisufailu2("failas10000000.txt");
            end = hrClock::now();
            difff = end - st; // Skirtumas (s)
            cout << endl;
            cout << "failas10000000.txt" << " Irasu, visas programos sugaiğtas laikas: " << difff.count() << " s\n\n";
            cout << "---------------------------------------------------------------- " << endl;
            system("pause");
    
          //  auto end = hrClock::now();
         //   std::chrono::duration<double> difff = end - st; // Skirtumas (s)
          //  cout << endl;
          // cout << test <<" Irasu, visas programos sugaiğtas laikas: " << difff.count() << " s\n\n";
          //  cout << "---------------------------------------------------------------- " << endl;
            
    //    }
   // } while (tikrinti != "0");

    



}


bool isNumber(const string& s) {

    for (char const& ch : s) {
        if (std::isdigit(ch) == 0)
            return false;
    }
    return true;
}

void ivestis(data& temp) {
    int n = 0;
    int k = 1;
    double vidurkis = 0;
    string s1;
    temp.nd.clear();
    cout << "Iveskite varda: "; cin >> temp.vardas;
    cout << "Iveskite pavarde: "; cin >> temp.pavarde;
    cout << "Rasykite 0, jei pazymiai baigiasi (max nd pazymiu yra " << C << " )" << endl;

    temp.nd.reserve(1);
    while (k && (n < C)) {    //

        cout << "Iveskite " << n + 1 << " - a pazymi: ";
        // cin >> temp.nd[n];
        cin >> s1;
        //s1 = std::to_string(temp.nd[n]);// pavercia i stringa
        if (isNumber(s1) && !(std::stoi(s1) > 10 || std::stoi(s1) < 0)) {
            // temp.nd[n] = std::stoi(s1);     // konvertuoja string i int tipa
            if (std::stoi(s1) == 0) {
                k = 0;
            }
            else {
                temp.nd.push_back(std::stoi(s1));
                vidurkis += temp.nd.back();
            }
        }
        else {
            //temp.nd[n] = 10;
            temp.nd.push_back(10);
            vidurkis += temp.nd.back();
            cout << "galimai ivedete ne numeri arba netinkama pazymi todel " << n + 1 << " mokiniui(-ei) jis buvo pakeistas i 10" << endl;
        }


        if (k != 0) {
            n++;
            temp.nd.reserve(n + 1);
        }
    }


    if (temp.nd.size() != 0) {
        vidurkis = vidurkis / n;
    }
    else vidurkis = 0;



    cout << "Iveskite egzamino ivertinima: "; //cin >> temp.egz;
    cin >> s1;
    if (isNumber(s1) && !(std::stoi(s1) > 10 || std::stoi(s1) < 0)) {
        temp.egz = std::stoi(s1);
    }
    else {
        temp.egz = 10;
        cout << "galimai ivedete ne numeri arba netinkama egzamino pazymi todel " << n + 1 << " mokiniui(-ei) jis buvo pakeistas i 10" << endl;
    }
    temp.rez = vidurkis * 0.4 + temp.egz * 0.6;

    // medianos skaiciavimas
    if (temp.nd.size() == 0) {
        temp.mediana = temp.egz * 0.6;
    }
    else {
        sort(temp.nd.begin(), temp.nd.begin() + n);
        //temp.nd.size() vietoj n
        if (temp.nd.size() % 2 == 1) {
            temp.mediana = temp.nd[temp.nd.size() / 2] * 0.4 + temp.egz * 0.6;
        }
        else {
            temp.mediana = ((temp.nd[temp.nd.size() / 2] + temp.nd[(temp.nd.size() / 2) - 1]) / 2.0) * 0.4 + temp.egz * 0.6;
        }
    }

    //return temp;
}

void ivestis1(data& temp, int kiek) {
    // int n=0;
    double vidurkis = 0;
    srand((unsigned)time(0));
    if (kiek > 0) {
        temp.nd.reserve(kiek);
    }

    cout << "Iveskite varda: "; cin >> temp.vardas;
    cout << "Iveskite pavarde: "; cin >> temp.pavarde;
    cout << "pazymiai: " << endl;
    for (int i = 0; i < kiek; i++) {    //C
        temp.nd[i] = (rand() % 10) + 1; // pazymiai nuo 1 iki 10
        cout << temp.nd[i] << " ";
        vidurkis += temp.nd[i];
        // n++;

    }

    if (kiek != 0) {
        vidurkis = vidurkis / kiek;
    }
    else vidurkis = 0;

    temp.egz = (rand() % 10) + 1;
    cout << endl;
    cout << "Egzaminas: " << temp.egz << endl;

    temp.rez = vidurkis * 0.4 + temp.egz * 0.6;

    // medianos skaiciavimas
    if (kiek > 0) {
        sort(temp.nd.begin(), temp.nd.begin() + kiek);
        if (kiek % 2 == 1) {
            temp.mediana = temp.nd[kiek / 2] * 0.4 + temp.egz * 0.6;
        }
        else {
            temp.mediana = ((temp.nd[kiek / 2] + temp.nd[(kiek / 2) - 1]) / 2.0) * 0.4 + temp.egz * 0.6;
        }
    }
    else temp.mediana = temp.egz * 0.6;
}

void ivestisfailas(data& temp) {
    cout << "labas" << endl;
}

void isved(const data& temp) {
    cout << std::left << std::setw(10) << temp.vardas << " " << std::setw(10) << temp.pavarde;
    cout << std::setw(10) << std::fixed << std::setprecision(2) << temp.rez << " " << endl;
}

void isvedmediana(const data& temp) {
    cout << std::left << std::setw(10) << temp.vardas << " " << std::setw(10) << temp.pavarde;
    cout << std::setw(10) << std::fixed << std::setprecision(2) << temp.mediana << " " << endl;
}

void isvedfailas(const data& temp) {
    cout << std::left << std::setw(10) << temp.vardas << " " << std::setw(10) << temp.pavarde;
    cout << std::setw(10) << std::fixed << std::setprecision(2) << temp.rez << std::setw(10) << std::fixed << std::setprecision(2) << temp.mediana << " " << endl;
}

void trycatch(string& a) {
    cin >> a;
    do {
        try {
            if (cin.fail()) {
                throw std::runtime_error("Irasete netinkamai\n");
            }
        }
        catch (const std::runtime_error& e) {
            std::wcout << e.what();
            std::wcin.clear();
            std::wcin.ignore(256, '\n');
            cout << "Iveskite is naujo: " << endl;
            cin >> a;
        }
    } while (std::cin.fail() == true);
}

void eil_po_eil(std::string read_vardas, std::string write_vardas, vector<data>& sarasas) {
    data laikinas;
    std::vector<std::string> splited;
    std::string eil;
    std::string abcas;
    std::stringstream my_buffer;
    string paz;
    double vidurkis = 0;
    int n = 1;
   // int nd;
    //----------------------------------------------------------------------
   // auto start = std::chrono::high_resolution_clock::now(); auto st = start;
    std::ifstream open_f(read_vardas);
    std::ofstream out_f(write_vardas);

    out_f << std::left << std::setw(10) << "Vardas " << std::setw(10) << "Pavarde " << std::setw(10) << "Galutinis (Vid.) " << std::setw(10) << "Galutinis (Med.) " << endl;
    out_f << "---------------------------------------------------------------- " << endl;
    while (open_f) {
        if (!open_f.eof()) {
            std::getline(open_f, eil);
            splited.push_back(eil);
            my_buffer.str(eil);
            //cout << eil << endl;
            // nuskaitymas
            my_buffer >> laikinas.vardas >> laikinas.pavarde;
            cout << laikinas.vardas << " " << laikinas.pavarde << " ";
            for (int i = 0; i < 15; i++) {
                my_buffer >> paz;
                cout << paz << " ";
            }


            cout << endl;



        }
        else break;
    }

    open_f.close();
    // auto end = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double> diff = end - start; // Skirtumas (s)
    // std::cout << "Failo nuskaitymas tesiai á eiluèiø vektoriø uştruko: " << diff.count() << " s\n";
     //------------------------------------------------------------------------ 
    // start = std::chrono::high_resolution_clock::now();

    // for (std::string a : splited) out_f << a << endl;

    out_f.close();

    // end = std::chrono::high_resolution_clock::now();
    // diff = end - start; // Skirtumas (s)
    // std::cout << "Failo árağymas eilutemis iğ eiluèiø vektoriaus uştruko: " << diff.count() << " s\n";
    splited.resize(0);
    //sarasas.resize(0);

   // diff = std::chrono::high_resolution_clock::now() - st; // Skirtumas (s)
   // std::cout << "Visas sugaiğtas laikas: " << diff.count() << " s\n\n";
}


