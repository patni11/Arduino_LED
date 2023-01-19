
from bs4 import BeautifulSoup as bs
import requests

def get_lyrics(name):
    URL = 'https://www.google.com/'
    source = requests.get(URL).text
    response=requests.post(URL,'lyrics of song')
    soup = bs(response.text,'lxml')
    print(soup)
    
get_lyrics('shubh')    