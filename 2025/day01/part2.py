start = 50
ans = 0

with open("input.txt") as file:
    for line in file:
        dir = line[0]
        amount = int(line[1:])

        if dir == "L":
            if start == 0:
                ans += amount // 100
            elif amount >= start:
                ans += 1 + (amount - start) // 100
            start -= amount
        else:
            ans += (start + amount) // 100
            start += amount
        start = start % 100

print(ans)
