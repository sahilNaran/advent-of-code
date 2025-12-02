line = ""
with open("input.txt") as file:
    line = file.read().strip()


def getDir(c):
    if c == "^":
        return (0, -1)
    elif c == ">":
        return (1, 0)
    elif c == "v":
        return (0, 1)
    return (-1, 0)


me = (0, 0)
houses = {(0, 0)}
for c in line:
    dir = getDir(c)
    me = (me[0] + dir[0], me[1] + dir[1])
    houses.add(me)

print(len(houses))
