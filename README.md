# Množinové operácie v jazyku C

Tento program implementuje základné množinové operácie v jazyku C, ako sú prienik a zjednotenie množín.

# Množina

Množina je v programe definovaná pomocou novo-vytvorenej štruktúry
MNOŽINA, ktorej prvky sú:

1. veľkosť množiny
2. prvky množiny

# Použitie

## Množinové operácie

Program slúži na vykonávanie množinovej operácie prieniku a zjednotenia na fixných množinách definovaných v kóde, rovnako aj na
náhodne vygenerovaných množinách.

## Priemer počtu vykonaných operácií

Program vykonáva aj zisťovanie priemerného počtu množinových operácií pre rôzne veľkosti množín.

## Tabuľka

Súčasťou je aj tabuľka vytvorená v jazyku python, na vizualizáciu počtu množinových operácií, pri rôznej dĺžke množín. Naším cieľom je na nej lepšie porozumieť efektivite nášho kódu, jeho rýchlosti a implementácií.

# Otázka efektivity

Graf zobrazujúci závislosť medzi veľkosťou množiny a počtom vykonaných porovnaní má aktuálne kvadratickú formu.
Prirodzene sa nám naskytá otázka, ako zefektívniť náš program, aby výstup bol lineárny? To je naša práca na najbližšie
riadky programu

# Linearita funkcie prienik()

_Vykonávanie funkcie prienik v lineárnom čase_ bolo dosiahnuté vykonávaním porovnávaní
prvkou 2 množín, iterovanie ktorými priebiehalo súbežne. Najprv boli prvky v oboch množinách
zoradané vzostupne. Následne sa porovnali prvky na rovnakej (t.j. nultej pozícií), v prípade
ak boli rovnaké, našiel sa prvok, ktorý majú spoločný (v oboch sme sa posunuli ďalej, pokračovali sme). V prípade, ak prvok v jednej bol väčší, ako prvok v druhej, tá druhá ju musela "dobehnúť", preto sme sa posunuli iba v druhej množine a v prvej sme zostali "stáť". Tento algoritmus pokračoval, pokiaľ sme nenarazili na koniec jednej z množín (čo zabezpečuje správne nastavený cyklus for).
