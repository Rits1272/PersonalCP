def BinarySearch(x):
    l, r = -1, n
    while r-l > 1:
        m = (l+r)//2
        if a[m] < x:
            l = m
        else:
            r = m
    return r != n and a[r] == x
