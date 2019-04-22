import os
import requests
import urllib.request
import time
import re
import string
from bs4 import BeautifulSoup

#Python webscraper program that allows user to input a url or text document for analysis.
#Script cleans the text, then sends it to c++ program for analysis.

# Menu for User
decision = "0"
while(decision != "4"):
	print("------------------------------------")
	print("1. URL from BBC")
	print("2. File Document")
	print("3. Text String")
	print("4. Exit")
	print("------------------------------------")
	decision = input('Please enter selection: ')
	if(decision == "1"):
		# URL Code
		
		# Storing the article
		url = input('Please input the BBC URL:')
		response = requests.get(url)

		soup = BeautifulSoup(response.content, "html.parser")

		article_string = ""
		for p in soup.find_all('p'):
			article_string += p.text.strip()

		article_string.split()

		# Pre-Processing
		article_string1 = article_string.lower()
		article_string2 = re.sub(r'\d +', '', article_string1)
		final = article_string2.translate(str.maketrans('', '', string.punctuation))

		# Writing to text file
		text_file = open("Output.txt", "w")
		text_file.write(final)
		text_file.close()

		# Calling C++ Script
		cmd = "a.exe Pos_Words.txt Neg_Words.txt Output.txt"
		os.system(cmd)
	elif(decision == "2"):
		filename = input("Please enter the filename (txt included):")

		file = open(filename, "r")
		text_string1 = file.read()
		
		# Pre-Processing
		text_string1 = text_string.lower()
		text_string2 = re.sub(r'\d +', '', text_string1)
		final = text_string2.translate(str.maketrans('', '', string.punctuation))

		# Writing to text file
		text_file = open("Output.txt", "w")
		text_file.write(final)
		text_file.close()

		# Calling C++ Script
		cmd = "a.exe Pos_Words.txt Neg_Words.txt Output.txt"
		os.system(cmd)
	elif(decision == "3"):
		text_string = input("Please enter the string you would like to calculate:")

		# Pre-Processing
		text_string1 = text_string.lower()
		text_string2 = re.sub(r'\d +', '', text_string1)
		final = text_string2.translate(str.maketrans('','',string.punctuation))

		# Writing to text file
		text_file = open("Output.txt", "w")
		text_file.write(final)
		text_file.close()

		# Calling C++ Script
		cmd = "a.exe Pos_Words.txt Neg_Words.txt Output.txt"
		os.system(cmd)
	elif(decision == "4"):
		break
	else:
		print("Invalid Choice!")


