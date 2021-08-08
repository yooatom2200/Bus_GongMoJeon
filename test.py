import requests
r = requests.post("http://220.69.209.30:3801/items", data='{"apple": "world"}')
print(r.text)
