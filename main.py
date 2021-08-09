#uvicorn, FastAPI 동작용
from fastapi import Request, FastAPI
from pydantic import BaseModel
import json

app = FastAPI()

data = {}

@app.get("/")
async def root(request: Request):
    global data
    return data

@app.post("/items")
async def items(request: Request):
    global data
    data = await request.json()
    return data

@app.get("/info/")
async def info(request: Request):
    return "송희령 공모전 준비"