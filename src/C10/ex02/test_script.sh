#!/bin/bash

# Create test files
echo "This is a test file with some content." > test1.txt
echo "1234567890" > test2.txt
echo "The quick brown fox jumps over the lazy dog." > test3.txt
echo "" > empty_file.txt

# Test 1: Display last 10 bytes of a single file (test1.txt)
echo "Test 1: Display last 10 bytes of test1.txt"
echo "Expected Output: some content."
echo "Actual Output:"
./ft_tail -c 10 test1.txt
echo ""

# Test 2: Display last 5 bytes of test2.txt
echo "Test 2: Display last 5 bytes of test2.txt"
echo "Expected Output: 67890"
echo "Actual Output:"
./ft_tail -c 5 test2.txt
echo ""

# Test 3: Display last 15 bytes of test3.txt
echo "Test 3: Display last 15 bytes of test3.txt"
echo "Expected Output: over the lazy dog."
echo "Actual Output:"
./ft_tail -c 15 test3.txt
echo ""

# Test 4: Display last 30 bytes of multiple files (test1.txt, test2.txt, test3.txt)
echo "Test 4: Display last 30 bytes of multiple files"
echo "Expected Output: last 30 bytes of each file"
echo "Actual Output:"
./ft_tail -c 30 test1.txt test2.txt test3.txt
echo ""

# Test 5: Handle non-existent file
echo "Test 5: Handle non-existent file (nonexistent.txt)"
echo "Expected Output: Error message about nonexistent.txt"
echo "Actual Output:"
./ft_tail -c 10 nonexistent.txt
echo ""

# Test 6: Handle empty file
echo "Test 6: Handle empty file (empty_file.txt)"
echo "Expected Output: No output (since the file is empty)"
echo "Actual Output:"
./ft_tail -c 10 empty_file.txt
echo ""

# Test 7: Handle a file smaller than requested bytes (test2.txt, requesting 20 bytes)
echo "Test 7: Handle a file smaller than requested bytes"
echo "Expected Output: 1234567890"
echo "Actual Output:"
./ft_tail -c 20 test2.txt
echo ""

# Test 8: Handle invalid byte count (negative value)
echo "Test 8: Handle invalid byte count (-5)"
echo "Expected Output: Error: Invalid byte count"
echo "Actual Output:"
./ft_tail -c -5 test1.txt
echo ""

# Test 9: Handle zero byte count
echo "Test 9: Handle zero byte count"
echo "Expected Output: Error: Invalid byte count"
echo "Actual Output:"
./ft_tail -c 0 test1.txt
echo ""

# Test 10: Handle invalid usage (missing byte argument)
echo "Test 10: Handle invalid usage (missing byte argument)"
echo "Expected Output: Usage error message"
echo "Actual Output:"
./ft_tail -c test1.txt
echo ""

# Clean up: Delete the test files
rm -f test1.txt test2.txt test3.txt empty_file.txt