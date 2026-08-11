set terminal pngcairo size 1000,700 enhanced font "Sans,12"
set output "convergenza.png"

set title "Convergenza del metodo di Eulero"
set xlabel "Passo temporale, dt [s]"
set ylabel "Errore sulla posizione a T = 1 s [m]"
set logscale xy
set grid xtics ytics mxtics mytics
set key left top

f(x) = a * x**p
a = 5.0
p = 1.0
set fit quiet
fit f(x) "convergenza.dat" using 1:2 via a,p

set label 1 sprintf("pendenza p = %.3f", p) at graph 0.07,0.88

plot "convergenza.dat" using 1:2 with points pointtype 7 pointsize 1.5 \
        title "dati numerici", \
     f(x) with lines linewidth 2 title sprintf("fit: errore = a dt^{p}, p=%.3f", p)
