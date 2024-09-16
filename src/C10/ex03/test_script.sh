#!/bin/bash

# Create test file
echo "This is a simple test." > test1.txt
echo "1234567890" > test2.txt
echo -n -e "\x01\x02\x03\x04\xff" > binaryfile.bin

# Test 1: Simple text file (test1.txt)
echo "Test 1: Hexdump of test1.txt"
./ft_hexdump test1.txt
echo ""

# Test 2: Another simple text file (test2.txt)
echo "Test 2: Hexdump of test2.txt"
./ft_hexdump test2.txt
echo ""

# Test 3: Binary file (binaryfile.bin)
echo "Test 3: Hexdump of binaryfile.bin"
./ft_hexdump binaryfile.bin
echo ""

# Test 4: Handle non-existent file
echo "Test 4: Handle non-existent file"
./ft_hexdump nonexistent.txt
echo ""

# Clean up: Remove test files
rm -f test1.txt test2.txt binaryfile.bin
