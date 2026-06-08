#!/bin/bash

status=true
SOLVER="./gauss"

INPUT_CSV="itest_in.csv"
OUTPUT_CSV="itest_out.csv"
EXPECTED_CSV="itest_exp.csv"

echo "A,B,C" > $INPUT_CSV
echo "2,1,5" >> $INPUT_CSV
echo "1,-1,1" >> $INPUT_CSV

echo "A,B" > $EXPECTED_CSV
echo "2.000000" >> $EXPECTED_CSV
echo "1.000000" >> $EXPECTED_CSV

$SOLVER $INPUT_CSV > $OUTPUT_CSV 2>/dev/null

if ! cmp -s "$OUTPUT_CSV" "$EXPECTED_CSV"; then
    status=false
    echo "Integration test: FAILED"
else
    echo "Integration test: PASSED"
fi

rm -f $INPUT_CSV $OUTPUT_CSV $EXPECTED_CSV
$status