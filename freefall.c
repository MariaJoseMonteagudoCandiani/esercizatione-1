#include <errno.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#if !defined(__STDC_VERSION__) || __STDC_VERSION__ < 201710L
#error "Questo programma richiede C17 o una versione successiva."
#endif

static const double G = 9.81;
static const double Y0 = 100.0;
static const double V0 = 0.0;
static const long MAX_STEPS = 10000000L;

static int parse_positive_double(const char *text, double *value)
{
    char *end = NULL;
    errno = 0;
    const double parsed = strtod(text, &end);

    if (errno != 0 || end == text || *end != '\0' || !isfinite(parsed) || parsed <= 0.0) {
        return 0;
    }

    *value = parsed;
    return 1;
}

static int parse_positive_steps(const char *text, long *value)
{
    char *end = NULL;
    errno = 0;
    const long parsed = strtol(text, &end, 10);

    if (errno != 0 || end == text || *end != '\0' || parsed <= 0L || parsed > MAX_STEPS) {
        return 0;
    }

    *value = parsed;
    return 1;
}

static void print_state(long step, double dt, double y, double v)
{
    const double t = (double)step * dt;
    const double y_exact = Y0 + V0 * t - 0.5 * G * t * t;
    const double v_exact = V0 - G * t;
    const double error_y = fabs(y - y_exact);

    printf("%.6f %.6f %.6f %.6f %.6f %.6f\n",
           t, y, v, y_exact, v_exact, error_y);
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Uso: %s DT N\n", argv[0]);
        return 2;
    }

    double dt = 0.0;
    long steps = 0L;
    if (!parse_positive_double(argv[1], &dt) || !parse_positive_steps(argv[2], &steps)) {
        fprintf(stderr, "Errore: DT deve essere positivo e N un intero tra 1 e %ld.\n",
                MAX_STEPS);
        return 2;
    }

    double y = Y0;
    double v = V0;

    puts("# t y_euler v_euler y_exact v_exact error_y");
    for (long step = 0L; step <= steps; ++step) {
        print_state(step, dt, y, v);

        if (step < steps) {
            /* TODO: implementare qui un passo del metodo di Eulero esplicito.
             * Calcolare entrambi i nuovi valori prima di modificare y e v. */
            const double y_next = y;
            const double v_next = v;

            y = y_next;
            v = v_next;
        }
    }

    const double t_final = (double)steps * dt;
    const double y_exact_final = Y0 + V0 * t_final - 0.5 * G * t_final * t_final;
    const double error_final = fabs(y - y_exact_final);

    printf("FINAL t=%.6f y=%.6f v=%.6f error=%.6f\n",
           t_final, y, v, error_final);

    return 0;
}
