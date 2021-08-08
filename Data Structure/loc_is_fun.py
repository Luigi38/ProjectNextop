v = [1, 2, 3]

def insert(item: int, loc: int):
    v.append(0)
    for i in range(len(v) - 2, loc - 1, -1):
        v[i + 1] = v[i]

    v[loc] = item

def main():
    item = int(input())
    loc = int(input())

    insert(item, loc)

    for i in range(0, len(v)):
        print(v[i])

main()