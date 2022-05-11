# Pairing-Heap

Pairing Heap este o structura de date derivata din Min/Max Heap. Este mai eficienta, avand Inserarea, Determinarea Minimului/Maximului si 'Join ul' in O(1), iar Stergerea Minimului/Maximului in O(logn). 

Eficienta acestei structuri reiese din constructia acesteia: in locul celebrului vector, unde fii lui v[i] sunt v[2 * i] si v[2 * i + 1], de data aceasta Heapul este reprezentat doar de radacina. Un pointer la radacina. 

Regula de constructie este urmatoarea: fiecare nod, inclusiv radacina, contine 3 valori: un intreg care reprezinta valoarea stocata si doi Pointeri: unul catre cel mai din stanga fiu, si unul la fratele din dreapta.
