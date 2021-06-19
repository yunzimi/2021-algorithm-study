val = int(input())

for i in range(val) :
    for j in range(val) :
        if (i <= j) : print("*", end="")
        else : print(" ", end="")
    print()