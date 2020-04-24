from bs4 import BeautifulSoup, SoupStrainer
import requests

url = "http://latemar.science.unitn.it/segue/index.php?&action=site&site=2019Programmazione2&section=432&page="

page = requests.get(url)    
data = page.text
soup = BeautifulSoup(data)

for link in soup.find_all('a'):
    print(link.get('href'))
