#!/bin/usr/python3
# -*- encoding:utf-8 -*-
from fastapi import FastAPI
# from cppnlp import model
from pydantic import BaseModel
import cppanalyse


class Nlp_Context(BaseModel):
    title: str = None
    content: str = None
    cid: str = None
    type: str = None
    is_debug: str = None

    def __dict__(self):
        return {
            "title": self.title,
            "content": self.content,
            "cid": self.cid,
            "type": self.type,
            "is_debug": self.is_debug
        }


app = FastAPI()


@app.get("/")
def read_root():
    return {"Hello": "World"}


@app.post("/")
def read_root(item: Nlp_Context):
    # model.predict() 接入模型
    return cppanalyse.predict(dict(item))
