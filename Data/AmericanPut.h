#ifndef _AmericanPut_h
#define _AmericanPut_h
#include <iostream>
#include <cmath>

using namespace std;

double AmericanPut(double stock, double strike, double interestRate, double dividend, double volatility,double time, int count)
{
	double exercise;
	
	//variables for stepping through tree
	double deltaT = time/count;
	double up = exp(volatility * sqrt(deltaT));

	double p0 = (up * exp(-interestRate * deltaT) - exp(-dividend * deltaT)) * up / (pow(up, 2) - 1);
	double p1 = exp(-interestRate * deltaT) - p0;

	//initial values at time T
	int i = 0;
	double p[count];
	for(i = 0; i <= count; i++) {
		p[i] = strike - stock * pow(up, 2*i - count);
		if(p[i] < 0) {
			p[i] = 0;
		}	
	}

	//move to earlier times
	int j = count-1;
	for(j = count-1; j >= 0; j--){
		for(i = 0; i <= j; i++){
			p[i] = p0 * p[i] + p1 * p[i+1];
			exercise = strike - stock * pow(up, 2*i-j);
			if(p[i] < exercise) {
				p[i] = exercise;
			}	
		}
	}

	return p[0];
}
double deltafinder(double k, double r, double q, double sigma, double t, double begin, double end, int n){
  char c;
  //cout << "begin:\t" << begin << "\tend:\t" << end << endl;
  double delta = (begin + end) / 2.0;
  //cout << "delta:\t" << delta << endl;
  double price = AmericanPut(delta, k, r, q, sigma, t, n);
  double percentage = (delta - k) / k;
  double pricePercentage = price / k;
  //cout << "Price:\t" << pricePercentage << "\tPercentage:\t" << percentage << endl;
  if(abs(begin - end) < .000000001){
    /*cout << "Sigma\t" << sigma << "\tInterest Rate\t" << r << endl;
    cout << "Returning\t" << percentage << endl;
    do{
      cout << "Move on? (y/n)" << endl;
      cin >> c;
    } while (c != 'y');*/
    return percentage;
  } else {
    if(pricePercentage == abs(percentage)){
      /*cout << "Sigma\t" << sigma << "\tTime\t" << t << endl;
      cout << "Price Percentage == Percentage:\t" << percentage << endl;
      do{
      cout << "Move on? (y/n)" << endl;
      cin >> c;
    } while (c != 'y');*/
      return deltafinder(k, r, q, sigma, t, delta, end, n);
    } else {
      /*cout << "Sigma\t" << sigma << "\tTime\t" << t << endl;
      cout << "Price Percentage != Percentage:\t" << percentage << endl;
      do{
      cout << "Move on? (y/n)" << endl;
      cin >> c;
    } while (c != 'y');*/
      return deltafinder(k, r, q, sigma, t, begin, delta, n);
    }
  }
}

double quickPut(double s, double k, double r, double q, double t, double sigma, int n) {

  if((((s - k) / k) <= 1.5*sqrt(r) - 1) && (((s - k) / k) <= 1/(sigma + 12 * q + .75) - 1.75)) {
    return k - s;
  } else {
    return AmericanPut(s,k,r,q,sigma,t,n);
  }
}
#endif
