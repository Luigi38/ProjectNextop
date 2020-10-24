class Test:
    a: int
    b: str

    def __init__(self, a: int, b: str):
        self.a = a
        self.b = b

def main():
    test = Test(100, "just testing")
    print(f"{test.a},{test.b}")

main()