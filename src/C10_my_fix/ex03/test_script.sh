#!/bin/bash

# Compile the program
make all

# Check if compilation was successful
if [ ! -f ft_hexdump ]; then
  echo "Compilation failed."
  exit 1
fi

# Create test files
echo "This is a test file." > test_file1.txt
dd if=/dev/zero of=test_file2.bin bs=16 count=1

# Test 1: Basic hex dump of text file
echo "Test 1: Hex dump of test_file1.txt"
./ft_hexdump test_file1.txt > result1.txt
hexdump -C test_file1.txt > expected1.txt
diff result1.txt expected1.txt && echo "Test 1 passed" || echo "Test 1 failed"

# Test 2: Hex dump of binary file
echo "Test 2: Hex dump of binary file test_file2.bin"
./ft_hexdump test_file2.bin > result2.txt
hexdump -C test_file2.bin > expected2.txt
diff result2.txt expected2.txt && echo "Test 2 passed" || echo "Test 2 failed"

# Test 3: Handling multiple files
echo "Test 3: Hex dump of both files"
./ft_hexdump test_file1.txt test_file2.bin > result3.txt
{ hexdump -C test_file1.txt; hexdump -C test_file2.bin; } > expected3.txt
diff result3.txt expected3.txt && echo "Test 3 passed" || echo "Test 3 failed"

# Test 4: Handling stdin input
echo "Test 4: Handling stdin"
echo "Stdin input test" | ./ft_hexdump > result4.txt
echo "Stdin input test" | hexdump -C > expected4.txt
diff result4.txt expected4.txt && echo "Test 4 passed" || echo "Test 4 failed"

# Clean up
make fclean
rm test_file1.txt test_file2.bin result*.txt expected*.txt

echo "All tests completed."
