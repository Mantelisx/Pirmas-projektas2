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

struct data {
    string vardas, pavarde;
    int egz = 0;
    vector<int> nd;
    double rez = 0, mediana = 0;

};

void ivestis(data& temp);
void isved(const data& temp);
void isvedmediana(const data& temp);
void ivestis1(data& temp, int kiek);
bool isNumber(const string& s);
void nuskaitymas();
void ivestisfailas(const data& temp);
void isvedfailas(const data& temp);

void eil_po_eil(std::string read_vardas, std::string write_vardas, vector<data>& sarasas);
bool compare_pavarde(const string& a, const string& b);
void trycatch(string& a);