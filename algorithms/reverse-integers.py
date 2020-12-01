def reverse(x: int) -> int:
    reversed_num = 0
    neg = False
    if x < 0:
        neg = True
        x = x*(-1)
    while x > 0:
        reversed_num = reversed_num*10 + x%10
        x = x//10
    return -reversed_num if neg else reversed_num
