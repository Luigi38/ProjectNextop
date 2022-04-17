towers = {
    'A': [1, 2, 3],
    'B': [],
    'C': []
}

def hanoi_tower(n: int, fro: str, tmp: str, to: str):
    if n != 1:
        hanoi_tower(n - 1, fro, to, tmp)
        towers[to].append(towers[fro].pop())
        hanoi_tower(n - 1, tmp, fro, to)
    else:
        towers[to].append(towers[fro].pop())

def main():
    hanoi_tower(3, 'A', 'B', 'C')

    for key in towers:
        for x in towers[key]:
            print(f"{key}: {x}")

main()