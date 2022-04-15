
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
