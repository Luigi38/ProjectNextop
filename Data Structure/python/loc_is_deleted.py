def delete(v: list, loc: int):
    for i in range(loc, len(v) - 1):
        v[i] = v[i + 1]

    v.pop()

def main():
    v = [1, 2, 3]

    loc = int(input())
    delete(v, loc)

    for x in v:
        print(x)

main()