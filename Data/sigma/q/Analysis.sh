#!/bin/bash
i=1
while [  $i -lt 6 ]; do
	echo i is $i
	echo "f(x) = c*(1/(x*sqrt(2*pi)*a))*exp(-(log(x)-b)**2/(2*a**2)); a = 2; b = 3; c = -1; fit f(x) \"$i.txt\" via a,b" | gnuplot
	let i=i+1
done

