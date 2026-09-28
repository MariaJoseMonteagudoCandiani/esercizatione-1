# Esercitazione 1 — Quanto puoi fidarti di una caduta simulata?

Lavorate **in gruppi di due**, con un unico repository e una relazione comune.
Ricevete un programma C già organizzato: dovrete implementare le conversioni
degli argomenti, il passo numerico e il calcolo del tempo.

## Accettare l'esercitazione in Classroom 50

Entrambi dovete essere iscritti alla classroom e aver accettato l'invito
all'organizzazione GitHub del corso. Il docente vi assegna allo stesso gruppo.
Aprite il link dell'esercitazione e premete **Accept assignment**: il primo
componente che accetta crea il repository, il secondo accede allo stesso.
Se non risultate in un gruppo, avvisate il docente prima di procedere.

Da **Open repository**, copiate l'URL e clonate ciascuno il repository del
gruppo sul proprio computer. Non clonate il template del docente.
Verificate con `git remote -v` che entrambi usiate lo stesso remoto.
Prima di lavorare, a copia locale pulita, eseguite `git pull`; concordate chi
modifica ciascun file e condividete gli avanzamenti con commit e push.
Alternate chi scrive e chi controlla: entrambi devono saper spiegare codice e prove.

## Il sistema

L'asse $Y$ è orientato verso l'alto. Trascuriamo la resistenza dell'aria:

$$
\dot y=v,\qquad \dot v=-g,\qquad
y_0=100\;\mathrm m,\quad v_0=0,\quad g=9.81\;\mathrm{m\,s^{-2}}.
$$

Il riferimento analitico è

$$
y(t)=y_0+v_0t-\tfrac12gt^2,\qquad v(t)=v_0-gt.
$$

## Step 1 — Un algoritmo da mettere alla prova

In `freefall.c` trovate i segnaposto di `parse_double` e
`parse_int`: implementatele prendendo ispirazione da `leggi_reale`
e `leggi_intero` già viste in `eco.c` nell'esercitazione 0. Qui le funzioni
devono scrivere il risultato attraverso il puntatore `value` e restituire
`1` se l'input è valido, `0` altrimenti. Usate `strtod` e `strtol`, controllando
`errno`, che sia stato letto un numero e che non rimangano caratteri estranei.
Le funzioni si occupano solo della conversione, il controllo che `DT` e `N` siano 
positivi è già nel `main`.
Provate anche testo non numerico, numeri seguiti da caratteri estranei,
zero e valori negativi.

Il template compila già, ma le conversioni restituiscono sempre `0`:
anche con argomenti validi, il programma segnala un errore e termina con
codice `2`. I parametri non ancora usati possono generare avvisi del compilatore.

Completate poi `euler_step(double dt, double *y, double *v)` con **Eulero
esplicito**. La funzione modifica direttamente posizione e velocità tramite
i puntatori e restituisce `1` quando il passo è implementato. Per calcolare
entrambi gli aggiornamenti usate lo stato all'inizio del passo: fate attenzione
a non usare un valore già aggiornato. Il segnaposto restituisce `0`, quindi
il programma segnala che il passo è incompleto e termina con un errore.

Completate anche il calcolo di `t` nel ciclo di `main`, sostituendo il valore
provvisorio `-1.`. La stampa avviene **dopo** il passo numerico: quando
`step` vale zero, il sistema è già avanzato di un intervallo `dt`.
Il tempo deve corrispondere allo stato appena calcolato, così da confrontarlo
con la soluzione esatta allo stesso istante.

Prima di eseguire il codice, scrivete una previsione in `relazione.md`.

- Quali informazioni sul moto possiedi all'inizio di un intervallo? Come
  potrebbero permetterti di stimare lo stato alla fine?
- Che cosa ti aspetti dopo il primo passo, partendo da fermo? La posizione
  calcolata dal metodo deve coincidere con quella esatta?
- Il confronto con la soluzione esatta dà lo stesso esito per posizione e
  velocità? Come potresti spiegarlo?
- Se usassi una velocità appena aggiornata per calcolare la posizione, avresti
  ancora lo stesso algoritmo? Quale prova distinguerebbe i due casi?
. 
Registrate il commit di proseguire allo [step 2](step-2.md).

## Interfaccia comune

Lavorate in locale nella copia clonata del repository del gruppo. Usate gli
strumenti installati sul computer oppure l'ambiente del repository
`ambiente-docker`, montando la cartella locale dell'esercitazione.

Una volta completate le funzioni richieste:

```sh
make
./freefall 0.1 10
./freefall 0.1 10 > traiettoria.dat
```

La sintassi è `./freefall DT N`: `DT` è il passo temporale positivo,
`N` il numero intero positivo di passi. Se una conversione restituisce `0`
oppure `dt <= 0.0` o `steps <= 0`, `main` termina con codice `2`.
Se `euler_step` restituisce `0`, il programma termina con un errore.
Non usate nell'analisi i dati di un'esecuzione interrotta.
Per le simulazioni usate valori finiti: non sono previsti controlli specifici
su `nan`, `inf` o sugli overflow durante il calcolo.

Mantenete nome del programma, costanti e formato dell'output:

```text
# t y_euler v_euler y_exact v_exact error_y
```

Una volta completati i TODO, seguono `N` righe, una dopo ciascun passo:
la prima è a `t = DT`, l'ultima a `t = N * DT`. Lo stato iniziale a `t = 0`
non viene stampato e non c'è una riga riassuntiva separata.
`error_y`, nella sesta colonna, è l'errore assoluto sulla posizione in metri.
Per l'errore al tempo finale leggete la sesta colonna dell'ultima riga.
I valori hanno sei cifre decimali: un errore stampato come zero può essere
sotto la risoluzione dell'output, come correggeresti?

## Consegna

Consegnate `freefall.c`, `relazione.md` e `plot.png`,
più gli eventuali script e dati necessari alle vostre prove aggiuntive.
Indicate nella relazione nomi e username GitHub di entrambi e il contributo
di ciascuno. La consegna è **una sola per gruppo**, dopo entrambi gli step.
Prima della consegna, riunite tutti i contributi nel branch predefinito e
verificate insieme il commit finale. Un componente esegue:

```sh
git status
git diff
git add freefall.c relazione.md plot.png
git commit -m "commento"
git push
```

Includete nel commit anche gli eventuali script e dati aggiuntivi; per i file
ignorati seguite le indicazioni dello step 2.

L'assignment usa **A tagged commit**: il push ordinario condivide il lavoro,
la consegna richiede un tag. Dopo il push, lo stesso componente esegue:

```sh
submission_tag="submit/$(date -u +%Y%m%dT%H%M%SZ)"
git tag "$submission_tag"
git push origin "$submission_tag"
```

Il tag include solo modifiche già registrate in un commit. Per una correzione,
fate un nuovo commit, push e un nuovo tag: non spostate quello precedente.

Entrambi controllate **Group submission** in Classroom 50 e verificate su
GitHub che il tag punti al commit concordato. Gli eventuali test automatici
sono configurati dal docente; compilare non certifica il risultato fisico.

Riferimento: [guida studenti di Classroom 50](https://github.com/foundation50/classroom50/wiki/Web-Student-Guide).
