# Taccuino — Caduta libera

Componenti del gruppo (nome, cognome e username GitHub di entrambi):
Maria Jose Monteagudo Candiani (@MariaJoseMonteagudoCandiani)

Contributo di ciascuno e come abbiamo controllato insieme il lavoro:
Maria Jose Monteagudo Candiani:** Sviluppo completo del codice in freefall.c (funzioni parse_double, parse_int, euler_step e gestione del tempo nel main), esecuzione dei test e stesura della relazione.

## Preparazione: conversione degli argomenti

Quali controlli abbiamo aggiunto alle funzioni viste nell'esercitazione 0:

Input validi e non validi provati, risultati e codici di uscita:

## Step 1: prima della simulazione

La mia previsione e il motivo:

All'inizio di un intervallo di tempo conosciamo la posizione e la velocità iniziali. Mi aspetto che al primo passo, partendo da fermo (velocità iniziale uguale a zero), la posizione calcolata con il metodo di Eulero esplicito non cambi e rimanga pari al valore iniziale y0. Il motivo è che la formula per la nuova posizione usa la velocità dell'inizio del passo, che essendo zero annulla lo spostamento. La posizione numerica quindi non coinciderà con quella esatta, che invece inizia subito a diminuire a causa dell'accelerazione di gravità. Per la velocità invece mi aspetto un risultato esatto, poiché l'accelerazione g è costante e la sua variazione lineare viene integrata senza errori dal metodo. Se usassi la velocità appena aggiornata per la posizione, passerei al metodo di Eulero-Cromer e la posizione cambierebbe già al primo passo.

Un passo calcolato a mano:
Con dati iniziali y0 = 100.0 m, v0 = 0.0 m/s, g = 9.81 m/s^2 e passo temporale dt = 0.1 s:
- Tempo al primo passo: t = 0.1 s
- Nuova posizione numerica: y1 = y0 + v0 * dt = 100.0 + 0.0 * 0.1 = 100.000000 m
- Nuova velocità numerica: v1 = v0 - g * dt = 0.0 - 9.81 * 0.1 = -0.981000 m/s
- Posizione esatta: y_exact = 100.0 + 0.0 * 0.1 - 0.5 * 9.81 * (0.1)^2 = 99.950950 m
- Velocità esatta: v_exact = 0.0 - 9.81 * 0.1 = -0.981000 m/s
- Errore sulla posizione: error_y = |100.0 - 99.950950| = 0.049050 m

## Step 1: la prova

Comando, risultato atteso e risultato osservato:
- **Comando eseguito:** `./freefall 0.1 10`
- **Risultato atteso:** Una tabella di 10 righe con la prima riga a t = 0.1 s contenente y_euler = 100.000000, v_euler = -0.981000, y_exact = 99.950950, v_exact = -0.981000 ed error_y = 0.049050.
- **Risultato osservato:** Il programma compila senza errori ed esegue esattamente i 10 passi richiesti. I valori stampati alla prima riga coincidono al millesimo con il calcolo a mano svolto nella previsione.

Che cosa ho verificato? Che cosa resta incerto?
Ho verificato che il parsing degli argomenti funziona correttamente scartando input non validi e che il passo di Eulero esplicito aggiorna la posizione in ritardo rispetto alla velocità, accumulando un errore sulla posizione che cresce nel tempo. Resta incerto come varia quantitativamente questo errore globale al variare della dimensione del passo temporale dt e come si comporta su simulazioni di durata più lunga.

Commit discusso e osservazione ricevuta al checkpoint:
Commit completato dopo l'implementazione e la verifica dello Step 1. L'osservazione principale è che la precisione di stampa a 6 cifre decimali (%.6f) potrebbe nascondere errori molto piccoli per dt molto piccoli; in tal caso si raccomanda l'uso della notazione scientifica (%.6e).

## Step 2: progettare un confronto

La domanda a cui risponde il confronto:
In che modo la scelta del passo temporale dt influenza l'errore finale sulla posizione al termine della simulazione?

Che cosa vario, che cosa mantengo costante e perché:
**Vario:** Il passo temporale dt (ad esempio confrontando dt = 0.1, dt = 0.05 e dt = 0.01).
- **Mantengo costante:** Il tempo totale di simulazione T_totale = N * dt (ad esempio T_totale = 1.0 s, adeguando di conseguenza il numero di passi N = T_totale / dt) e le condizioni iniziali (y0 = 100.0 m, v0 = 0.0 m/s).
- **Motivo:** È necessario mantenere costante il tempo totale per poter confrontare l'errore accumulato nello stesso istante fisico finale.

Misura dell'errore scelta e unità:
La misura dell'errore scelta è l'errore assoluto sulla posizione all'ultimo passo di simulazione (t = T_totale), espresso in metri (m), ricavato dalla sesta colonna (error_y) dell'ultima riga stampata.

## Step 2: evidenze e interpretazione

![Dati di convergenza](convergenza.png)

Comandi per ottenere i dati e procedura per riprodurre il grafico:

Come abbiamo stimato l'esponente e come interpretiamo i dati:

Una prova aggiuntiva scelta da me (ipotesi, comando, dati o figura):

Quale risultato mi avrebbe fatto cambiare idea?

## Conclusione

Che cosa posso sostenere e in quale intervallo di validità:

Un limite, un risultato inatteso o una domanda ancora aperta:
