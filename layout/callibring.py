# -*- coding: utf-8 -*- 
def InitAlphabet(from_,to_):
	returns = u""
	while from_ != to_+1:
		returns+=chr( from_ )
		if from_>to_: from_ = from_ - 1
		else: from_ = from_ + 1
	return returns

def Callibring(alph):
	returns = {}
	for letter in alph:
		correct = input("Write your letter in normal("+letter+"): ")
		returns[letter]=correct
	return returns



