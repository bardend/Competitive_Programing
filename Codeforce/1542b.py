for _ in range(int(input())):
    n,a,b = map(int, input().split())

    num = 1
    ok = 0

    while num <= n:
        if (n-num)%b == 0 :
            ok = 1
        num *= a
        if a == 1 :
            break
    if ok:
        print("Yes")
    else :
        print("No")
