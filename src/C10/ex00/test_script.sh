#!/bin/bash

# Create test files
echo "1 2 3" > test         # File with content and newline
echo -n "4 5 6" > test_no_newline   # File without trailing newline

# Test 1: Valid File
echo "Test 1: Valid File"
echo "Expected Output: 1 2 3"
echo "Actual Output:"
./ft_display_file test
echo ""

# Test 2: File without newline
echo "Test 2: File without newline"
echo "Expected Output: 4 5 6"
echo "Actual Output:"
./ft_display_file test_no_newline
echo ""

# Test 3: Missing argument
echo "Test 3: Missing argument"
echo "Expected Output: File name missing."
echo "Actual Output:"
./ft_display_file
echo ""

# Test 4: Too many arguments
echo "Test 4: Too many arguments"
echo "Expected Output: Too many arguments."
echo "Actual Output:"
./ft_display_file test test_no_newline
echo ""

# Test 5: Nonexistent file
echo "Test 5: Nonexistent file"
echo "Expected Output: Cannot read file."
echo "Actual Output:"
./ft_display_file nonexistent_file
echo ""

# Clean up: Delete the test files
rm -f test test_no_newline
