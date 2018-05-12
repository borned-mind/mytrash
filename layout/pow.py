#!/usr/bin/env python
import hashlib as gash
import sys as sas

def HashingSha(What):
	return gash.sha1( What ).hexdigest()

def FindPattern(Pattern, What, StartNonce=0):
	while HashingSha( What+str(StartNonce) ).find(Pattern) != 0:
		StartNonce=StartNonce+1
		pass
	print( HashingSha( What+str(StartNonce) ) + " is " + What+str(StartNonce) )
        return StartNonce #, What

def Main():
	if len(sas.argv) != 3:
		print ( sas.argv[0] + " %Pattern% %What%" )
		return None
	for byte in sas.argv[1]:
		b = ord(byte)
		if (b < 48 or b > 57) and ( b < ord('a') or b > ord('f') ):
			print(sas.argv[1]+" is not correct pattern")
			return None

	IsNonce=FindPattern(sas.argv[1], sas.argv[2])
	print ("Is nonce: "+str(IsNonce) )

Main()
