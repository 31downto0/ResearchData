#!/usr/bin/python

inputfile = "sigma.txt"

fo = open(inputfile, "r")
data = fo.readlines()
fo.close()
i = 5
while i <= 500:
	outputfile = "sigma/" + str(i) + ".txt"
	print outputfile
	fo = open(outputfile, "w")
	for line in data:
		s = line.split('\t')
		if len(s) == 3:
			n = float(s[0])
			vol = float(s[1])
			perc = float(s[2])
			if abs(n-(i/100.0)) < .01:
				fo.write(str(vol) + '\t' + str(perc) + '\n')
	i += 5
	fo.close()
