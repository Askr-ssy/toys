import sys
import os
import time
read_path = "/tmp/server_in.pipe"
write_path = "/tmp/server_out.pipe"
 
try:
    # 创建命名管道
    os.mkfifo( write_path )
    os.mkfifo( read_path )
except OSError as e:
    # 如果命名管道已经创建过了，那么无所谓
    print("mkfifo error")


read_stream = os.open(read_path,os.O_RDONLY)
write_stream = os.open(write_path,os.O_SYNC | os.O_CREAT | os.O_RDWR)

while True:
    s = os.read(read_stream,1024)
    if len(s) == 0:
        time.sleep(1)
        continue
    print(s,type(s))
    os.write(write_stream,s)