start = 50
ans = 0

with open("input.txt") as file:
    for line in file:
        dir = line[0]
        amount = int(line[1:])

        if dir == "L":
            start -= amount
        else:
            start += amount

        start = start % 100
        if start == 0:
            ans += 1

print(ans)
