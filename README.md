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
