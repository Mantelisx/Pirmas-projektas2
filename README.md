
### Pirmas projektas 

# v0.1 #
1. Pagal užduoties reikalavimus realizuota programa, kuri nuskaito vartotojų įvedamus reikiamus duomenis (struktūros elementus). 
2. Baigus duomenų įvedimą, suskaičiuoja galutinį balą ir juos pateikia į ekraną, kur galutinis apskaičiuotas balas pateikiamas dviejų skaičių po kablelio tikslumu. 
3. Vietoj vidurkio galima pasirinkti medianą, kad apskaičiuoti galutinį pažymį (galutinis = vidurkis0,4 + egzaminas0,6). 
4. Galima įrašyti namų darbus tol, kol neparašomas 0 arba įvedamas maksimalus pažymių skaičius. Yra galimybė pasirinkti automatinį pažymių generavimą arba rankinį įrašymą. 
5. Taip pat yra dvi versijos, viena saugo mokinių duomenis (tame tarpe ir pažymių) dinaminiame masyve, kita vektoriuje.
    
# v0.2 #

1. Pridėtas skaitymas iš failo.

# v0.3 #

1. Pridėtas „exception handling“
2. Atskiri header failai

# v0.4 #

1. Failų generavimas.
2. Duomenų apdorojimas (paskirstymas į du failus)
3. Greičio analizė

![irodymai](https://user-images.githubusercontent.com/92160605/159172288-2f21b626-b2d3-4611-ab93-0c51ac8d016f.png)
![irodymai2](https://user-images.githubusercontent.com/92160605/159172290-fa7dc32f-3177-423e-87a1-94c72b994a5a.png)

# v0.5 #

### Vector vs List vs Deque ###

PC specs:

|  CPU |  HDD |  RAM|
|---|---|---|
| Intel Core i5-6600K 3.50 GHz  | Seagate BarraCuda 1TB 7200rpm | 12 GB DDR4 2666Mhz  |

Testuota programos greitis atskirai naudojant: Vector, List, Deque.
Gauti rezultatai:

### 1 bandymas ###
![VectorListDeque1](https://user-images.githubusercontent.com/92160605/160690477-ac960d0c-336e-4076-b183-a448f2735686.png)

### 2 bandymas ###
![VectorListDeque2](https://user-images.githubusercontent.com/92160605/160690498-152e6466-ace7-4e76-9803-56ffd0822c74.png)

1 Bandymo metu konteinerių greičio pozicijos išlieka panašios. T.y. lėčiausias - List, vidutinis - Vector, Greičiausias - Deque (10mln.). 
2 Bandymo metu duomenų nuskaitymo greitis supanašėjo, rūšiavimo pozicijos išliko tos pačios, tik Vector artimesnis List pagal greitį (10mln.). 
Pastaba: Rikiavimas Listo dažnai buvo greitesnis nei kitų konteinerių, todėl galėjo įtakoti bendrą programos laiką.

### Parametrai 2 bandymu ###

Sistemos parametrai maždaug buvo panašūs.
![VectorListDeque3](https://user-images.githubusercontent.com/92160605/160690587-ad291cae-799b-4e5e-83ac-f04a9613f5e0.png)


### Išvada ###

List konteineris pasižymi lėtesniu greičiu duomenų nuskaityme ir rūšiavime(10mln.), tuo tarpu Vector ir Deque greitesni(Deque didesnėje bandymų dalyje gavosi greičiausias).

# v1.0 #

Visiems trims konteinerių tipams (vector, list ir deque) išmatuota programos veikimo sparta priklausomai nuo studentų dalijimo į dvi kategorijas strategijos:

1 strategija: Bendro studentai konteinerio (vector, list ir deque tipų) skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius: "vargšiukų" ir "kietiakų". Tokiu būdu tas pats studentas yra dvejuose konteineriuose: bendrame studentai ir viename iš suskaidytų (vargšiukai arba kietiakai).

2 strategija: Bendro studentų konteinerio (vector, list ir deque) skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį: "vargšiukai". Tokiu būdu, jei studentas yra vargšiukas, jį turime įkelti į naująjį "vargšiukų" konteinerį ir ištrinti iš bendro studentai konteinerio. Po šio žingsnio studentai konteineryje liks vien tik kietiakai.

3 strategija: Bendro studentų konteinerio (vector, list ir deque) skaidymas (rūšiavimas) panaudojant du konteinerius: "vargšiukai", "kietekai". Tokiu būdu, jei studentas yra vargšiukas, jį turime įkelti į naująjį "vargšiukų" konteinerį, po įkėlimo bendras studentų konteineris priskiriamas kietiakams. Po šio žingsnio studentai konteineryje liks vien tik kietiakai.

Bandymų rezultatai:

![VectorListDeque1versija](https://user-images.githubusercontent.com/92160605/163723303-8eb9508f-62f7-4b26-89a9-0a167ac54483.png)

### Išvada ###

2 strategija su List ir Deque konteineriais pasižymėjo greitesniu atlikimu, tačiau su Vector konteineriu labai ilgai užtruko. Lėčiausiai pasirodė 1 strategija.

# Įdiegimo instrukcija #

1. Per linux terminalą nueiname iki projekto failų vietos.
2. Terminale rašome << make main >> (tik tekstą, be << >> ženklų).
3. Terminale rašome paleidimo komandą << ./main >> (be << >> ženklų).

Jei norite kompiliuoti tik Circle.cpp į terminalą rašykite << make circle >> (be << >> ženklų).
Jei norite ištrinti visus failus, kurie baigiasi (xxxxx.o) ir main paleidžiamąjį failą rašykite << make clean >> (be << >> ženklų).

Jei norite generuoti failą, reiks Circle.cpp faile void veiksmaisufailu funkcijoje pasirašyti tokį kodą: (generuotifailus("failo pavadinimas", 10, 7); veiksmaisufailu2("failo pavadinimas");), jei ne pridedamas 100000 įrašų failas.

![ubuntu](https://user-images.githubusercontent.com/92160605/163725742-0d1186ed-5072-452c-bc7f-defa6239a213.png)


# Naudojimo instrukcija #

Po Įdiegimo 3 žingsnio ( ./main ):

1. Sekame programoje pateikiamus žingsnius.


# v1.1 #

![paveikslas](https://user-images.githubusercontent.com/92160605/166116134-f3f9b684-2cc5-4715-a79a-c6371d3704e4.png)

![paveikslas](https://user-images.githubusercontent.com/92160605/166116149-7e63bf65-ee5c-4be6-894b-d4000f0e555e.png)


