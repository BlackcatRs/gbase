#!/usr/bin/env python3

result = 0
decimal = 27
binary = []


result = decimal
rest_of_division = 0

while result != 1:
    result = int(result/2)
    binary.append(decimal-(result*2))
    decimal = result

# binary.insert(0, 1)
binary.reverse()

print(binary)
