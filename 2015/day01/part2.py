pos = 1
line = ""
ans = 0

with open("input.txt") as file:
    line = file.read().strip()

for c in line:
    if c == "(":
        ans += 1
    else:
        ans -= 1
    if ans == -1:
        print(pos)
        break
    pos += 1
