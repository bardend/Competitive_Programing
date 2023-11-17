wnt = 100

def num_d(x):
    ret = 0
    while x:
        ret += 1
        x //= 10
    return ret

def get_up(x):
    return x // (10 ** max(num_d(x) - wnt, 0))

def get_dow(x):
    return x % 1000

def rec_up(n, k):
    if k == 0:
        return 1
    ret = rec_up(n, k // 2)
    ret = get_up(ret * ret)
    if k & 1:
        ret = get_up(ret * n)
    return ret

def rec_dow(n, k):
    if k == 0:
        return 1
    ret = rec_dow(n, k // 2)
    ret = get_dow(ret * ret)
    if k & 1:
        ret = get_dow(ret * n)
    return ret

t = int(input())

for tt in range(1, t + 1):
    n, k = map(int, input().split())

    fn = rec_up(n, k)
    sn = rec_dow(n, k)

    fn = fn // (10 ** (num_d(fn) - 3))
    print(f"Case {tt}: {fn} ", end='')
    nlen = num_d(sn)
    if nlen == 0:
        print("000")
    elif nlen == 1:
        print("00", end='')
    elif nlen == 2:
        print("0", end='')
    print(sn)
