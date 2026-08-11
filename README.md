# Esercitazione 1 — Caduta libera con il metodo di Eulero

In questa esercitazione integrerai numericamente il moto verticale di un corpo
in caduta libera e confronterai il risultato con la soluzione analitica.

## Obiettivi

- compilare un programma conforme allo standard C17;
- leggere e validare argomenti dalla riga di comando;
- implementare un passo del metodo di Eulero esplicito;
- confrontare una soluzione numerica con quella esatta;
- osservare come l'errore cambia al diminuire del passo temporale;
- produrre e consegnare dati numerici e un grafico di convergenza log-log.

## Modello fisico

Trascurando la resistenza dell'aria,

\[
\frac{dy}{dt}=v, \qquad \frac{dv}{dt}=-g,
\]

con

\[
y(0)=100\ \mathrm{m}, \qquad v(0)=0, \qquad
g=9.81\ \mathrm{m\,s^{-2}}.
\]

La soluzione esatta è

\[
y(t)=y_0+v_0t-\frac{1}{2}gt^2, \qquad v(t)=v_0-gt.
\]

## Compito

Completa il blocco marcato `TODO` in `freefall.c`. Per un passo temporale
`dt`, il metodo di Eulero esplicito usa i valori al tempo corrente per calcolare
entrambi i valori al passo successivo.

Usa due variabili temporanee (`y_next` e `v_next`): non aggiornare `y` prima di
aver calcolato anche `v_next`.

Non cambiare:

- il nome del sorgente e dell'eseguibile;
- i valori di `G`, `Y0` e `V0`;
- l'interfaccia da riga di comando;
- il formato dell'output descritto sotto.

## Compilazione ed esecuzione

```console
make
./freefall DT N
```

`DT` è il passo temporale positivo e `N` è il numero positivo di passi. Per
esempio:

```console
./freefall 0.1 10
```

Il programma deve terminare con codice `2` se gli argomenti sono assenti o non
validi. Gli errori vanno scritti su `stderr`.

## Formato dell'output

La prima riga e la riga riassuntiva finale devono avere esattamente questa
forma:

```text
# t y_euler v_euler y_exact v_exact error_y
...
FINAL t=1.000000 y=95.585500 v=-9.810000 error=0.490500
```

Tutti i numeri sono stampati con sei cifre dopo il punto decimale. Tra le due
righe devono comparire gli stati da `0` a `N`, quindi `N + 1` righe numeriche.

## Verifiche consigliate

```console
make clean
make
./freefall 0.1 10
./freefall 0.05 20
```

Confronta l'errore finale delle ultime due esecuzioni. A tempo finale fissato,
cosa succede quando dimezzi `DT`?

## File dati e grafico di convergenza

Dopo aver completato e verificato il programma, esegui:

```console
make plot
```

Il comando esegue `freefall` mantenendo il tempo finale a `T = 1 s` e usando
quattro passi temporali. Deve produrre:

- `convergenza.dat`, con due colonne: `dt` ed errore finale sulla posizione;
- `convergenza.png`, grafico log-log dell'errore in funzione di `dt`.

Il file dati deve iniziare con questa intestazione:

```text
# dt error
```

Controlla che il grafico abbia assi e unità di misura leggibili, una legenda e
la pendenza del fit. I due file prodotti fanno parte della consegna. Non
modificare manualmente `convergenza.dat`: Classroom 50 lo rigenererà
indipendentemente dall'eseguibile e confronterà i valori.

## Relazione breve

Completa `relazione.md`. Il codice e la relazione devono essere inclusi nel
commit consegnato.

## Consegna

```console
git status
git add freefall.c relazione.md convergenza.dat convergenza.png
git commit -m "Completa esercitazione 1"
git push
```

Se il corso usa la modalità di consegna esplicita di Classroom 50, esegui poi
anche:

```console
gh student submit
```

Se il comando non è disponibile nel Codespace, usa un tag manuale:

```console
submission_tag="submit/$(date -u +%Y%m%dT%H%M%SZ)"
git tag "$submission_tag"
git push origin "$submission_tag"
```
