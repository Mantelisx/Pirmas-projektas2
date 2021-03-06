#pragma once
#ifndef _DLL_H_
#define _DLL_H_

#include <iostream>
#include <stdio.h>
#include <windows.h>

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


#ifdef DLL_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif


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



class zmogus {
protected:
    string vardas, pavarde;
public:
    std::string getVardas() const { return vardas; }
    std::string getPavarde() const { return pavarde; }

    virtual void setVardas(string vardas) = 0;
    virtual void setPavarde(string pavarde) = 0;

    zmogus(string vard = "", string pavard = "") : vardas{ vard }, pavarde{ pavard } {}
};





class data : public zmogus {
private:
    int egz;
    vector <int> nd;
    double rez, mediana;
public:
    data(string vard = "", string pavard = "") : egz(0), nd(0), rez(0.0), mediana(0.0), zmogus{ vard, pavard }  { }  // default konstruktorius
    //data() : egz(0) { }  // default konstruktorius

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
        zmogus::vardas = that.vardas;
        zmogus::pavarde = that.pavarde;
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
            zmogus::vardas = that.vardas;
            zmogus::pavarde = that.pavarde;
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
        nd.clear();
    }

    // kiti metodai

    // vardo keitimas
    void changeVardas(string newVardas)
    {
        zmogus::vardas = newVardas;
    }

    // pavardes keitimas
    void changePavarde(string newPavarde)
    {
        zmogus::pavarde = newPavarde;
    }

    // egzamino ?vertinimo keitimas
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

    // rezultat? sud?tis
    data operator + (const data& b) {
        data rezult;
        rezult.rez = rez + b.rez;
        rezult.mediana = mediana + b.mediana;
        return rezult;
    }


    friend bool operator>(const data& a, const data& b);
    friend bool operator<(const data& a, const data& b);
    friend bool operator>=(const data& a, const data& b);
    friend bool operator<=(const data& a, const data& b);
    friend bool operator==(const data& a, const data& b);
};





extern "C"
DLL_API void ivestis(data& temp);
extern "C"
DLL_API void isved(const data& temp);
extern "C"
DLL_API void isvedmediana(const data& temp);
extern "C"
DLL_API void ivestis1(data& temp, int kiek);
extern "C"
DLL_API bool isNumber(const string& s);
extern "C"
DLL_API void veiksmaisufailu();
void ivestisfailas(const data& temp);
void isvedfailas(const data& temp);

extern "C"
DLL_API void trycatch(string& a);

void generuotifailus(string& failopavadinimas, int kiek, int nd);
void veiksmaisufailu2(string test);

vector<data> skirtstykStudentus(vector<data>& studentai);

void pirmastrategija(vector<data> studentai, vector<data>& kieti, vector<data>& minksti);
vector<data> antrastrategija(vector<data>& studentai);
bool Mazesnis(const data& a);
void tobulinta(vector<data>& studentai, vector<data>& minksti);


extern "C"
DLL_API void NumberList();

#endif

