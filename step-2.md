# Step 2 — Che cosa significa migliorare la previsione?

Ripartite dal commit discusso al checkpoint. Ora dovete sostenere con dati una
risposta alla domanda: **come cambia l'affidabilità della previsione quando
cambi il passo temporale?**

## Domande stimolo

- Due simulazioni con passi diversi stanno necessariamente rispondendo alla
  stessa domanda fisica? Che cosa devi tenere invariato per confrontarle?
- Quale misura distinguerebbe un errore piccolo da un accordo solo apparente
  nel grafico delle traiettorie?
- Quale dipendenza dell'errore dal passo prevedi? Che rappresentazione dei dati
  ti permetterebbe di distinguere previsioni diverse?
- Una sola coppia di simulazioni basta? Quale dato aggiuntivo renderebbe più
  convincente o smentirebbe la tua conclusione?
- Ridurre indefinitamente il passo è sempre utile? Come riconosceresti un limite
  della stampa dei numeri rispetto a un limite del metodo?

## Progettare e realizzare il confronto

Concordate nella coppia il confronto e annotatelo in `relazione.md` prima
di eseguire le simulazioni. Scegliete un tempo finale comune e almeno quattro
passi temporali; per ogni passo scegliete un numero intero di iterazioni che
raggiunga quel tempo. Documentate i comandi utilizzati.