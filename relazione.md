# Relazione breve — Esercitazione 1

Nome e cognome:

Matricola:

Turno:

## 1. Velocità e posizione

Perché, in questo problema, Eulero produce la velocità esatta ai tempi discreti
ma non la posizione esatta?

**Risposta:**

## 2. Aggiornamento simultaneo

Perché è opportuno calcolare `y_next` e `v_next` prima di assegnarli a `y` e
`v`? Quale metodo si otterrebbe usando subito la nuova velocità nella posizione?

**Risposta:**

## 3. Convergenza

Riporta l'errore finale per `DT = 0.2`, `0.1`, `0.05` e `0.025`, mantenendo
`t_final = 1 s`. Che relazione osservi fra errore e passo temporale?

| DT | N | errore finale |
|---:|---:|---:|
| 0.2 | 5 | |
| 0.1 | 10 | |
| 0.05 | 20 | |
| 0.025 | 40 | |

**Commento:**

Stima l'ordine osservato usando due punti consecutivi:

\[
p=\frac{\log(E_1/E_2)}{\log(\Delta t_1/\Delta t_2)}.
\]

**Ordine stimato:**

## 4. Grafico

Inserisci qui il grafico consegnato:

![Convergenza del metodo di Eulero](convergenza.png)

Il grafico è compatibile con una convergenza del primo ordine? Motiva la
risposta usando la pendenza del fit.

**Risposta:**
