# -*- coding: utf-8 -*-
import argparse


def CaculatePi(number):
    number1 = number+10
    b = 10**number1
    x1 = b*4//5
    x2 = b // -239
    he = x1+x2
    number *= 2
    for i in range(3, number, 2):
        x1 //= -25
        x2 //= -57121
        x = (x1+x2) // i
        he += x
        pai = he*4
        pai //= 10**10
    return pai


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("len", type=int, default=10,
                        help="display a square of a given number")
    args = parser.parse_args()
    # print(args.len)
    result = CaculatePi(args.len)
    # print(result)
