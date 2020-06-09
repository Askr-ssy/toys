#!/usr/bin/sh
python3 -m grpc_tools.protoc -I=../protos --grpc_python_out=./ --python_out=./ ./../protos/helloworld.proto
# protoc -I=../protos --grpc_python_out=. --python_out=. ../protos/helloworld.proto