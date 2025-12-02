ans = 0
with open("input.txt") as file:
    for line in file:
        l, w, h = map(int, line.split("x"))
        paper = 2 * l * w + 2 * w * h + 2 * h * l
        area = min(l * w, w * h, h * l)
        ans += paper + area
print(ans)
