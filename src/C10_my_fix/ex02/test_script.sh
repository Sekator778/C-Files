#!/bin/bash

# Compile the program
make all

# Check if compilation was successful
if [ ! -f ft_tail ]; then
  echo "Compilation failed."
  exit 1
fi

# Create some test files
echo "This is a test file with several lines of text." > test_file1.txt
echo "Another test file to verify ft_tail functionality." > test_file2.txt

# Test 1: Display last 10 bytes of a file
echo "Test 1: Displaying last 10 bytes of test_file1.txt"
./ft_tail -c 10 test_file1.txt > result1.txt
tail -c 10 test_file1.txt > expected1.txt
diff result1.txt expected1.txt && echo "Test 1 passed" || echo "Test 1 failed"

# Test 2: Display last 20 bytes of a file
echo "Test 2: Displaying last 20 bytes of test_file2.txt"
./ft_tail -c 20 test_file2.txt > result2.txt
tail -c 20 test_file2.txt > expected2.txt
diff result2.txt expected2.txt && echo "Test 2 passed" || echo "Test 2 failed"

# Test 3: Handling multiple files
echo "Test 3: Displaying last 5 bytes of both files"
./ft_tail -c 5 test_file1.txt test_file2.txt > result3.txt
{ tail -c 5 test_file1.txt; tail -c 5 test_file2.txt; } > expected3.txt
diff result3.txt expected3.txt && echo "Test 3 passed" || echo "Test 3 failed"

# Test 4: Handling stdin input
echo "Test 4: Handling stdin"
echo "Some random text" | ./ft_tail -c 4 > result4.txt
echo "Some random text" | tail -c 4 > expected4.txt
diff result4.txt expected4.txt && echo "Test 4 passed" || echo "Test 4 failed"

# Test 5: Illegal arguments
echo "Test 5: Illegal arguments"
./ft_tail -c illegal test_file1.txt > result5.txt 2>&1
if grep -q "illegal" result5.txt; then
  echo "Test 5 passed"
else
  echo "Test 5 failed"
fi

# Clean up
make fclean
rm test_file1.txt test_file2.txt result*.txt expected*.txt

echo "All tests completed."
