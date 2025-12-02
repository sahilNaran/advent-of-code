ans = 0
with open("input.txt") as file:
    for line in file:
        l, w, h = map(int, line.split("x"))
        around = 2 * min(l + w, w + h, h + l)
        ans += around + l * w * h
print(ans)
