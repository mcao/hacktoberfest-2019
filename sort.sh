#!/bin/bash

# 1. add unique (we hope) string to all non-header lines
# 2. remove all newlines
# 3. add a newline before our headers
# 4. sort all the lines
# 5. replace our unique (we still hope) string with newlines

perl -pe 's/^(?!####)/xxxxx/g' CONTRIBUTORS.md | tr -d '\n' | perl -pe 's/####/\n####/g' | sort | perl -pe 's/xxxxx/\n/g'

