#!/bin/usr/python3
# -*- encoding:utf-8 -*-
from fastapi import FastAPI
# from cppnlp import model
from pydantic import BaseModel


class Nlp_Context(BaseModel):
    title: str = None
    content: str = None
    cid: str = None
    type: str = None
    is_debug: bool = False


app = FastAPI()


@app.get("/")
def read_root():
    return {"Hello": "World"}


@app.post("/")
def read_root(item: Nlp_Context):
    # model.predict() 接入模型
    return item