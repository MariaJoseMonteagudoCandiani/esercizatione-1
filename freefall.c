#include <errno.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define G 9.81
#define Y0 100.0
#define V0 0.0

/* TODO: implementate queste due funzioni prendendo ispirazione da eco.c
 * (esercitazione 0). Scrivete il risultato in *value e restituite 1 se
 * la conversione e' valida, 0 altrimenti. */
int parse_double(char *text, double *value)
{
    return 0;
}

int parse_int(char *text, int *value)
{
    return 0;
}

double exact_position(double t)
{
    return Y0 + V0 * t - 0.5 * G * t * t;
}

double exact_velocity(double t)
{
    return V0 - G * t;
}

/* Aggiorna posizione e velocita' tramite i puntatori, usando per entrambi
 * i calcoli lo stato iniziale del passo. Restituisce 1 se il passo e' pronto. */
int euler_step(double dt, double *y, double *v)
{
    /* TODO: sostituisci i segnaposto con il passo di Eulero esplicito,
     * ritorna 1 per segnalare che il passo e' implementato. */
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Uso: %s DT N\n", argv[0]);
        return 2;
    }

    double dt = 0.0;
    int steps = 0;
    if (!parse_double(argv[1], &dt) || !parse_int(argv[2], &steps)) {
        fprintf(stderr, "Errore: DT deve essere un numero reale e N un intero.\n");
        return 2;
    }
    if (dt <= 0.0 || steps <= 0) {
        fprintf(stderr, "Errore: DT e N devono essere positivi.\n");
        return 2;
    }

    double y = Y0;
    double v = V0;

    printf("# t y_euler v_euler y_exact v_exact error_y\n");
    for (int step = 0; step < steps; ++step) {
        if (!euler_step(dt, &y, &v)) {
            fprintf(stderr, "Il passo numerico e' da completare in euler_step.\n");
            return EXIT_FAILURE;
        }

        /* TODO: implementa il calcolo del tempo */
        double t = -1.;
        double y_exact = exact_position(t);
        double v_exact = exact_velocity(t);
        double error_y = fabs(y - y_exact);

        printf("%.6f %.6f %.6f %.6f %.6f %.6f\n",
               t, y, v, y_exact, v_exact, error_y);
    }

    return 0;
}
