num = int(input())

a = num / 10
b = num % 10
c = int(a + b)
count = 0

while True:
    if c < 10:
        a = b
        b = c
        c = a + b
        count += 1
    else:
        a = b
        b = c % 10
        c = a + b
        count += 1

    if a * 10 + b == num:
        break

print(count)
