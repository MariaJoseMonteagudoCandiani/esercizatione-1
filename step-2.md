# Step 2 — Che cosa significa migliorare la previsione?

Ripartite dal commit discusso al checkpoint. Ora dovete sostenere con dati una
risposta alla domanda: **come cambia l'affidabilità della previsione quando
cambi il passo temporale?**

## Domande stimolo

- Due simulazioni con passi diversi stanno necessariamente rispondendo alla
  stessa domanda fisica? Che cosa devi tenere invariato per confrontarle?
  Per confrontare simulazioni con passi diversi dobbiamo mantenere costanti il tempo finale totale di simulazione (T = N * dt) e le condizioni iniziali (y0 = 100.0 m, v0 = 0.0 m/s). Solo così le simulazioni rispondono alla stessa domanda fisica nello stesso istante temporale.
- Quale misura distinguerebbe un errore piccolo da un accordo solo apparente
  nel grafico delle traiettorie?
  Distanza tra grafico e misura esatta:** In un grafico le traiettorie possono sembrare sovrapposte a causa della scala. La misura che distingue un errore reale è l'errore assoluto sulla posizione error_y = |y_euler - y_exact| ricavato numericamente nell'ultima riga.
- Quale dipendenza dell'errore dal passo prevedi? Che rappresentazione dei dati
  ti permetterebbe di distinguere previsioni diverse?
  Poiché il metodo di Eulero esplicito è del primo ordine, mi aspetto che l'errore finale sulla posizione sia direttamente proporzionale a dt (se dimezzo dt, l'errore finale si dimezza). La rappresentazione ideale per verificare questa previsione è un grafico in scala logaritmica (log-log) dell'errore in funzione di dt.
- Una sola coppia di simulazioni basta? Quale dato aggiuntivo renderebbe più
  convincente o smentirebbe la tua conclusione?
  Una sola coppia di simulazioni non basta per confermare una legge di scala. Utilizzare almeno 4 passi temporali diversi permette di verificare la pendenza della retta nel grafico log-log e confermare la pendenza unitaria tipica del primo ordine.
- Ridurre indefinitamente il passo è sempre utile? Come riconosceresti un limite
  della stampa dei numeri rispetto a un limite del metodo?
Reducere il passo indefinidamente non è sempre utile. Il primo limite è la risoluzione della stampa: con la formattazione %.6f, un errore inferiore a 0.0000005 m viene stampato come zero. Inoltre, passi estremamente piccoli aumentano il numero di operazioni portando all'accumulo dell'errore di arrotondamento in punto flotante (round-off error).
## Progettare e realizzare il confronto

Concordate nella coppia il confronto e annotatelo in `relazione.md` prima
di eseguire le simulazioni. Scegliete un tempo finale comune e almeno quattro
passi temporali; per ogni passo scegliete un numero intero di iterazioni che
raggiunga quel tempo. Documentate i comandi utilizzati.
```bash
./freefall 0.2 5 > traiettoria_dt02.dat
./freefall 0.1 10 > traiettoria_dt01.dat
./freefall 0.05 20 > traiettoria_dt05.dat
./freefall 0.01 100 > traiettoria_dt01_01.dat

Scegliamo un tempo finale comune **T_totale = 1.0 s** e testiamo 4 passi temporali diversi (dt = 0.2 s, dt = 0.1 s, dt = 0.05 s, dt = 0.01 s), regolando il numero di passi N = T_totale / dt.
