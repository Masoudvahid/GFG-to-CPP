from googlesearch import search
from bs4 import BeautifulSoup
import requests
import os
import glob


# Search for a keyword in google using site:geeksforgeeks.org
keyword = input("Enter a keyword to search: ")
keyword += " code site:geeksforgeeks.org"
file = open("search_results/Links.txt", 'w')
urls = search(keyword)
for url, index in zip(urls, range(1, 10)):
    file.write(url + '\n')
    print(str(index) + ') ' + url.replace('https://www.geeksforgeeks.org/', '').replace('/', '').replace('-', ' '))

# Scrape in the resulting websites
# Read and save webpage from website
file = open("search_results/Links.txt", 'r')
link_index = int(input("Enter link index: "))
index = 1
for link in file:
    if index == link_index:
        URL = link
    index += 1

page = requests.get(URL.replace('\n', '')).text
# Read HTML file
soup = BeautifulSoup(page, 'lxml')
index = 0
# Empty the directory
files = glob.glob('search_results/Codes/*.txt')
for f in files:
    os.remove(f)
# Create files
for code_container in soup.find_all('div', class_='container'):
    file = open("search_results/Codes/code" + str(index) + ".txt", 'a')
    for lines_of_code in code_container.find_all('div'):
        file.write(lines_of_code.text + "\n")
    file.close()
    index += 1
    
