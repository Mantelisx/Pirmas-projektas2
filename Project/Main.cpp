#include "Circle.h"



int main()
{
    //ofstream rf("rez.txt");
   // rf << "labas" << endl;

    setlocale(LC_ALL, "Lithuanian");
    int mok = 0;    // nustatomas mokiniu skaicius
    vector<data> sarasas;
    data laik;
    string abc;
    string dar;
    
    /*
    // testavimas
    data d1;
    cout << "getVardas: " << d1.getVardas() << endl;
    d1.changeVardas("labas");
    data d2 = d1;
    //d2.setVardas("labas2");
    //d1 = d2;
    cout << "getVardas labas: " << d1.getVardas() << endl;
    cout << "getVardas labas2: " << d2.getVardas() << endl;
    cout << "--------------------------------" << endl;
    d1.setRez(10.0);
    d2.setRez(5.0);
    data d3 = d1+d2;
    cout << "d1 + d2 " << d3.getRez() << endl;
    cout << "d1 + d2 " << (d1+d2).getRez() <<endl;
    cout << "d1 + d2 Mediana " << d3.getMediana() << endl;
    cout << "d1 > d2 " << (d1 > d2) << endl;
    cout << "d1 < d2 " << (d1 < d2) << endl;
    cout << "d1 >= d2 " << (d1 >= d2) << endl;
    cout << "d1 <= d2 " << (d1 <= d2) << endl;
    cout << "d1 == d2 " << (d1 == d2) << endl;

    */

    cout << "---------------------------------------------------------------- " << endl;

    cout << "Jei norite, kad duomenis skaitytu is failo ? 1, jei paciam ivesti ? 0" << endl;
    trycatch(abc);
    // cin >> abc;
    // while ((abc != "1") && (abc != "0")) {
    //     cout << "Ivedete blogai, veskite dar karta " << endl;
    //     cin >> abc;
    // }
    if (abc == "1") {
        veiksmaisufailu();
        //eil_po_eil("kursiokai.txt", "rez.txt", sarasas);
       // generuotifailus();
    }
    
    else {

        do {
            mok++;
            sarasas.reserve(mok);
            cout << "Ar norite kad " << mok << " -am(ai) mokiniui(-ei) pazymiai butu generuojami atsitiktinai? (bet koks simbolis) - taip, 0 - ne" << endl;
            cin >> abc;
            if (abc == "0") {
                ivestis(laik);
                sarasas.push_back(laik);
            }
            else {
                cout << "Kiek nd pazymiu turi mokinys? (max - " << C << " )" << endl;
                cin >> abc;
                while (!(isNumber(abc)) || (std::stoi(abc) > C || std::stoi(abc) < 0)) {
                    cout << "Ivedete blogai, veskite dar karta " << endl;
                    cin >> abc;
                }
                ivestis1(laik, std::stoi(abc));
                sarasas.push_back(laik);
            }
            cout << "Ar norite prideti dar viena mokini? (bet koks simbolis) - taip, 0 - ne" << endl;
            cin >> dar;
        } while (dar != "0");


        cout << "---------------------------------------------------------------- " << endl;
        cout << "Jei norite Vidurkio: rasykite ? 1, jei norite Medianos rasykite ? 0 " << endl;

        cin >> abc;

        while ((abc != "1") && (abc != "0")) {
            cout << "Ivedete blogai, veskite dar karta " << endl;
            cin >> abc;
        }


        if (abc == "1") {
            cout << std::left << std::setw(10) << "Vardas " << std::setw(10) << "Pavarde " << std::setw(10) << "Galutinis (Vid.) " << endl;
            cout << "---------------------------------------------------------------- " << endl;
            for (const auto& el : sarasas) {
                isved(el);
            }
        }

        else if (abc == "0") {
            cout << std::left << std::setw(10) << "Vardas " << std::setw(10) << "Pavarde " << std::setw(10) << "Galutinis (Med.) " << endl;
            cout << "---------------------------------------------------------------- " << endl;
            for (const auto& el : sarasas) {
                isvedmediana(el);
            }
        }
    }
    sarasas.clear();
    // df.close();     // uzdaromas duomenu failas
     //rf.close();     // uzdaromas rezultatu failas
    system("pause");
    return 0;
}
