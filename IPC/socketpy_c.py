#!/bin/usr/python3

# -*- encode:utf-8 -*-

import socket


if __name__ == "__main__":
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    host = socket.gethostname()
    port = 4000
    client.connect((host, port))
    client.send(input("input: ").encode())

    client.close()
