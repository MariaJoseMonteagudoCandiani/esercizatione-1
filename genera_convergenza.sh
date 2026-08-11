#!/usr/bin/env bash

set -euo pipefail

program="${1:-./freefall}"

if [[ ! -x "$program" ]]; then
    echo "Errore: eseguibile non trovato: $program" >&2
    exit 2
fi

printf '# dt error\n'

for case_spec in "0.2 5" "0.1 10" "0.05 20" "0.025 40"; do
    read -r dt steps <<<"$case_spec"

    final_line="$($program "$dt" "$steps" | awk '/^FINAL / { line = $0 } END { print line }')"
    error="$({ printf '%s\n' "$final_line"; } | awk '{
        for (i = 1; i <= NF; ++i) {
            if ($i ~ /^error=/) {
                split($i, field, "=")
                print field[2]
                exit
            }
        }
    }')"

    if [[ -z "$error" ]]; then
        echo "Errore: campo error non trovato per DT=$dt, N=$steps" >&2
        exit 1
    fi

    printf '%.6f %.6f\n' "$dt" "$error"
done
