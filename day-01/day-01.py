from collections import Counter


def read_data():
    left, right = [], []
    with open('input.txt') as f:
        for line in f.readlines():
            x, y = map(int, line.rstrip().split())
            left.append(x)
            right.append(y)
    return left, right


def part_1():
    left, right = read_data()
    left.sort()
    right.sort()
    return sum(abs(x - y) for x, y in zip(left, right))


def part_2():
    left, right = read_data()
    right_counts = Counter(right)
    return sum(x * right_counts.get(x, 0) for x in left)


if __name__ == '__main__':
    print(part_1())
    print(part_2())
