def _fac(n):
    ret = 1
    if n<=1:
        return ret
    for i in range(2,n+1):
        ret = ret*i
    return ret
print(_fac(2))