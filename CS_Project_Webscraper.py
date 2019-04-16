import requests
import urllib.request
import time
from bs4 import BeautifulSoup

# url_prompt = input('Please input the article URL:')
url = 'http://www.bbc.com/travel/story/20190414-living-in-a-country-that-thinks-green'
response = requests.get(url)

soup = BeautifulSoup(response.content, "html.parser")

article = []
count = 0
for p in soup.find_all('p'):
    article.append(p.text)

print(article,'\n\n')

print(article[0])
