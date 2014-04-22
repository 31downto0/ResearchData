#!/usr/bin/python


inputfile = "fit.log"
fo = open(inputfile, "r")
print inputfile + " opened."
data = fo.readlines()
fo.close()
outputfile = "AB.txt"
writeme = False
counter = 1
fo = open(outputfile, "w")
for line in data:
	s = line.split()
	if len(s) > 3:
		first = str(s[0])
		second = str(s[1])
		third = str(s[2])
		if first == 'a':
			if third != '2':
				tempA = third
		if first == 'b':
			if third != '3':
				tempB = third
		if first == 'c':
				if third != '-1':
					fo.write(str(counter/1000.0) + '\t' + tempA + '\t' + tempB + '\t' + third + '\n')
					counter+=50
fo.close()
