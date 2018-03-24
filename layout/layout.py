# -*- coding: utf-8 -*- 
from random import randint as rand
import callibring as cal



Alphabet_rus = cal.InitAlphabet( ord(u'а'), ord('я') )
Alphabet_eng=""

callibring = input("callibring(y): ?")
if callibring == "y":
	Alphabet_eng = cal.Callibring(Alphabet_rus)
else:
	Alphabet_eng = {'ы': 's', 'у': 'e', 'р': 'h', 'г': 'u', 'х': '[', 'н': 'y', 'ш': 'i', 'о': 'j', 'е': 't', 'т': 'n', 'ь': 'm', 'с': 'c', 'я': 'z', 'ч': 'x', 'э': "'", 'щ': 'o', 'ж': ';', 'б': ',', 'в': 'd', 'ъ': ']', 'и': 'b', 'к': 'r', 'п': 'g', 'ц': 'w', 'й': 'q', 'ф': 'a', 'л': 'k', 'а': 'f', 'д': 'l', 'м': 'v', 'ю': '.', 'з': 'p'}


def GetRandPhrase(len_phrase , f=Alphabet_rus , s=Alphabet_eng ):
	eng = ""
	rus = ""
	while len_phrase:
		rand_char= rand(0,len(f))
		try:
			eng+=s[ f[rand_char:rand_char+1]  ]
		except Exception:
			continue
		rus+=f[rand_char:rand_char+1]
		len_phrase = len_phrase - 1
	return eng , rus

def SwapVar(a,b):
#	tmp = a
#	a = b
#	b = tmp
	return b, a

def Main():
	errors=0
	succefuly=0

	eng_to_rus = input("Eng_To_Rus? Y: ")
	len_of_phrase = input("Len(16): ")
	

	while True:
		try:
			if  int(len_of_phrase) <= 0 : len_of_phrase = 16
		except Exception:
			len_of_phrase = 16
		no_correct, correct = GetRandPhrase( int(len_of_phrase) )
		if eng_to_rus != "Y":
			correct, no_correct = SwapVar(correct, no_correct)

		your = input("Write is correctly " + no_correct + ": " )
		if your == correct:
			print ("Yeah!")
			succefuly = succefuly + 1
		else:
			print ("Loser: " + your + "!=" + correct)
			errors = errors + 1
		print ("Errors: "+str(errors)+"\n"+"succefuly: "+str(succefuly))
Main()
