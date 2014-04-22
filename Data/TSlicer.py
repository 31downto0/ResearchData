#!/usr/bin/python

inputfile = "SmartSigmaTDE.txt"

fo = open(inputfile, "r")
data = fo.readlines()
fo.close()
i = 1
while i <= 2000:
	outputfile = "t1/" + str(i) + ".txt"
	print outputfile
	fo = open(outputfile, "w")
	for line in data:
		s = line.split('\t')
		if len(s) == 3:
			n = float(s[0])
			vol = float(s[1])
			perc = float(s[2])
			if abs(n-(i/1000.0)) < .001:
				fo.write(str(vol) + '\t' + str(perc) + '\n')
	i += 50
	fo.close()
