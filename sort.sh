#!/bin/bash
perl -pe 's/^(?!####)/xxxxx/g' CONTRIBUTORS.md | tr -d '\n' | perl -pe 's/####/\n####/g' | sort | perl -pe 's/xxxxx/\n/g' > CONTRIBUTORS_sorted.md

