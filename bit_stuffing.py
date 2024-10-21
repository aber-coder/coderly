def bit_stuffing(buff):
    flag = "_01111110_"
    count = 0
    res = ""

    for bit in buff:
        if bit == "1":
            count += 1
        else:
            count = 0
        res += bit
        if count == 5:
            res += "0"
            count = 0

    res = flag + res + flag
    return res


buff = "11111111110"

res = bit_stuffing(buff)
print(res)