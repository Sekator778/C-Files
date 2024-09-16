#!/bin/bash

# Create test files
echo "Hello, World!" > test1.txt
echo -n "No newline at the end" > test2.txt
echo "This is another test file with more content.\nIt spans multiple lines." > test3.txt

# Test 1: Display file content
echo "Test 1: Display file content (test1.txt)"
echo "Expected Output: Hello, World!"
echo "Actual Output:"
./ft_cat test1.txt
echo ""

# Test 2: Display file content without a newline at the end
echo "Test 2: Display file content without a newline (test2.txt)"
echo "Expected Output: No newline at the end"
echo "Actual Output:"
./ft_cat test2.txt
echo ""

# Test 3: Display multiple files
echo "Test 3: Display multiple files (test1.txt, test2.txt, test3.txt)"
echo "Expected Output: Contents of all three files"
echo "Actual Output:"
./ft_cat test1.txt test2.txt test3.txt
echo ""

# Test 4: Handle non-existent file
echo "Test 4: Handle non-existent file (nonexistent.txt)"
echo "Expected Output: Error message about nonexistent.txt"
echo "Actual Output:"
./ft_cat nonexistent.txt
echo ""

# Test 5: Read from standard input
echo "Test 5: Read from standard input (type input and press Ctrl+D)"
echo "Expected Output: Repeats what you type"
echo "Actual Output:"
echo "Type something and press Ctrl+D:"
./ft_cat
echo ""

# Test 6: Too many arguments (this is optional since we don’t handle options)
echo "Test 6: Too many arguments (not applicable)"
echo "This is not necessary as we're not handling specific arguments."

# Clean up: Delete the test files
rm -f test1.txt test2.txt test3.txt
