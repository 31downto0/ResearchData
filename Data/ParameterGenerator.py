#!/usr/bin/python
import random

outputfile = "paramsNorm.txt"
fo = open(outputfile, "w")

for i in xrange(0,1000000):
	k = random.gauss(100,10)
	s = random.gauss(30,5)
	r = (random.random() * (.1 - .005)) + .005
	t = (random.random() * .95) + .05
	q = random.random() * .05
	sigma = (random.random() * .6) + .05
	fo.write(str(s) + '\t' + str(k) + '\t' + str(r) + '\t' + str(q) + '\t' + str(sigma) + '\t' + str(t) + '\n')

fo.close()
print "all done"