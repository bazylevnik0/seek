import sys
import requests
from bs4 import BeautifulSoup

URL = "http://" + sys.argv[1]
page = requests.get(URL,headers={"Host": "www.google.com"})


soup = BeautifulSoup(page.content, "html.parser")

title = soup.title.get_text().lower()
temp = ""
counter = 0
for el in title:
    if (el == 'a'):
         temp += "crimson\n"
         counter += 1 
    if (el == 'b'):
         temp += "orange\n"
         counter += 1 
    if (el == 'c'):
         temp += "olive\n"
         counter += 1 
    if (el == 'd'):
         temp += "yellow\n"
         counter += 1 
    if (el == 'e'):
         temp += "lawn green\n"
         counter += 1 
    if (el == 'f'):
         temp += "medium spring green\n"
         counter += 1 
    if (el == 'g'):
         temp += "light green\n"
         counter += 1 
    if (el == 'h'):
         temp += "aqua\n"
         counter += 1 
    if (el == 'i'):
         temp += "aqua marine\n"
         counter += 1 
    if (el == 'j'):
         temp += "dodger blue\n"
         counter += 1 
    if (el == 'k'):
         temp += "midnight blue\n"
         counter += 1 
    if (el == 'l'):
         temp += "blue violet\n"
         counter += 1 
    if (el == 'm'):
         temp += "dark violet\n"
         counter += 1 
    if (el == 'n'):
         temp += "violet\n"
         counter += 1 
    if (el == 'o'):
         temp += "hot pink\n"
         counter += 1 
    if (el == 'p'):
         temp += "bisque\n"
         counter += 1
    if (el == 'r'):
         temp += "saddle brown\n"
         counter += 1 
    if (el == 's'):
         temp += "sandy brown\n"
         counter += 1 
    if (el == 't'):
         temp += "misty rose\n"
         counter += 1 
    if (el == 'u'):
         temp += "mint cream\n"
         counter += 1 
    if (el == 'v'):
         temp += "lavender\n"
         counter += 1 
    if (el == 'w'):
         temp += "floral white\n"
         counter += 1 
    if (el == 'x'):
         temp += "gray\n"
         counter += 1 
    if (el == 'y'):
         temp += "gainsboro\n"
         counter += 1 
    if (el == 'z'):
         temp += "white smoke\n"
         counter += 1 
    
temp = sys.argv[1] + '\n' + str(counter) + '\n' + temp
print(temp)

text_file = open("temp.txt", "w")
text_file.write(temp)
text_file.close()