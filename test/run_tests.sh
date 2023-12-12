#!/bin/bash

echo "Running Basic Test..."
cat test_basic.txt | ./organized

echo "Running Deletion Test..."
cat test_deletion.txt | ./organized

echo "Running Sorting Test..."
cat test_sorting.txt | ./organized

echo "Running Full Test..."
cat test_full.txt | ./organized
