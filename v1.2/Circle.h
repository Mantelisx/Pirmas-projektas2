#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <random>

#include <sstream> 
#include <chrono>

#include <cstdio>   //failui trinti

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::sort;
using std::ifstream;
using std::ofstream;

const int C = 50;
const string duom = "kursiokai.txt";
const string rez = "rez.txt";

using hrClock = std::chrono::high_resolution_clock;
typedef std::uniform_int_distribution<int>  int_distribution;

/*
struct data {
    string vardas="", pavarde="";
    int egz = 0;
    vector<int> nd;
    double rez = 0, mediana = 0;

};
*/
/*
class data {
public:
    string vardas = "", pavarde = "";
    int egz = 0;
    vector<int> nd;
    double rez = 0, mediana = 0;
};
*/

class data {
    private:
	    string vardas, pavarde;
	    int egz;
	    vector<int> nd;
	    double rez, mediana;
    public:
        data() : vardas(""), pavarde(""), egz(0), nd(0), rez(0.0), mediana (0.0)  { }  // default konstruktorius
        //data() : egz(0) { }  // default konstruktorius

        std::string getVardas() const { return vardas; }    
        std::string getPavarde() const { return pavarde; }  
        int getEgzaminas() const { return egz; }  
        const std::vector<int>& getNd() const { return nd; }
        std::vector<int>& getNd() { return nd; }
        double getRez() const { return rez; }  
        double getMediana() const { return mediana; }  

        void setVardas(string vardas) { this->vardas = vardas; }
        void setPavarde(string pavarde) { this->pavarde = pavarde; }
        void setEgzaminas(int egz) { this->egz = egz; }
        void setNd(vector<int> nd) { this->nd = nd; }
        void setRez(double rez) { this->rez = rez; }
        void setMediana(double mediana) { this->mediana = mediana; }

        // 1. copy constructor
        data(const data& that)
        {
            this->vardas = that.vardas;
            this->pavarde = that.pavarde;
            this->egz = that.egz;
            this->nd = that.nd;
            this->rez = that.rez;
            this->mediana = that.mediana;
        }

        // 2. copy assignment operator
        data& operator=(const data& that)
        {
            if (this != &that)
            {
                this->vardas = that.vardas;
                this->pavarde = that.pavarde;
                this->egz = that.egz;
                this->nd = that.nd;
                this->rez = that.rez;
                this->mediana = that.mediana;
            }
            return *this;
        }

        // 3. destructor
        ~data()
        {

        }

        // kiti metodai

        // vardo keitimas
        void changeVardas(string newVardas)
        {
            this->vardas = newVardas;
        }

        // pavardes keitimas
        void changePavarde(string newPavarde)
        {
            this->pavarde = newPavarde;
        }

        // egzamino ávertinimo keitimas
        void changeEgz(int newEgz)
        {
            this->egz = newEgz;
        }

        // nd rinkinio keitimas
        void changeNd(vector<int> newNd)
        {
            this->nd = newNd;
        }

        // rezultato keitimas
        void changeRez(double newRez)
        {
            this->rez = newRez;
        }

        // medianos keitimas
        void changeMediana(double newMediana)
        {
            this->mediana = newMediana;
        }

        // rezultatø sudëtis
        data operator + (const data& b) {
            data rezult;
            rezult.rez = rez + b.rez;
            rezult.mediana = mediana + b.mediana;
            return rezult;
        }

};

void ivestis(data& temp);
void isved(const data& temp);
void isvedmediana(const data& temp);
void ivestis1(data& temp, int kiek);
bool isNumber(const string& s);
void veiksmaisufailu();
void ivestisfailas(const data& temp);
void isvedfailas(const data& temp);

//void eil_po_eil(std::string read_vardas, std::string write_vardas, vector<data>& sarasas);
//bool compare_pavarde(const string& a, const string& b);
void trycatch(string& a);

void generuotifailus(string& failopavadinimas, int kiek, int nd);
void veiksmaisufailu2(string test);

vector<data> skirtstykStudentus(vector<data>& studentai);

void pirmastrategija(vector<data> studentai, vector<data>& kieti, vector<data>& minksti);
vector<data> antrastrategija(vector<data>& studentai);
bool Mazesnis(const data& a);
void tobulinta(vector<data>& studentai, vector<data>& minksti);