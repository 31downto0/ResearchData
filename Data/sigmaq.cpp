#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "AmericanPut.h"

using namespace std;




int main(int argc, char *argv[])
{
  /*
   *t - expiration time [.05,1]
   *s - stock price
   *k - strike price
   *n - height of binomial tree
   *r - risk free rate of interest[.005,.1]
   *sigma - volatility [.05,.65]
   *q - dividend [0,.05]
   */


  double k = 150;
  double r = .05;
  double q = .02;
  double sigma = .3;
  double t = .5;
  int n = 100;


  double percentage;

  
  ofstream fs;
  fs.open("sigmaqr05t5.txt");

  r = .005;
  t = .05;
  
  for(sigma = .05; sigma <= .65; sigma += .1) {
    for(q = 0; q <= .05; q += .001) {
      percentage = deltafinder(k,r,q,sigma,t,0,150,n);
      fs << sigma << "\t" << q << "\t" << percentage << endl;
      cout << "q:\t" << q << "\tsigma:\t" << sigma << "\tr:\t" << r << "\tt:\t" << t << "\tpercentage:\t" << percentage << endl;
    }
  }
  
  fs.close();
  fs.open("sigmaqr05t100.txt");

  r = .005;
  t = 1;

  for(sigma = .05; sigma <= .65; sigma += .1) {
    for(q = 0; q <= .05; q += .001) {
      percentage = deltafinder(k,r,q,sigma,t,0,150,n);
      fs << sigma << "\t" << q << "\t" << percentage << endl;
      cout << "q:\t" << q << "\tsigma:\t" << sigma << "\tr:\t" << r << "\tt:\t" << t << "\tpercentage:\t" << percentage << endl;
    }
  }

  fs.close();
  fs.open("sigmaqr10t5.txt");

  r = .1;
  t = .05;

  for(sigma = .05; sigma <= .65; sigma += .1) {
    for(q = 0; q <= .05; q += .001) {
      percentage = deltafinder(k,r,q,sigma,t,0,150,n);
      fs << sigma << "\t" << q << "\t" << percentage << endl;
      cout << "q:\t" << q << "\tsigma:\t" << sigma << "\tr:\t" << r << "\tt:\t" << t << "\tpercentage:\t" << percentage << endl;
    }
  }
      
  fs.close();
  fs.open("sigmaqr10t100.txt");

  r = .1;
  t = 1;

  for(sigma = .05; sigma <= .65; sigma += .1) {
    for(q = 0; q <= .05; q += .001) {
      percentage = deltafinder(k,r,q,sigma,t,0,150,n);
      fs << sigma << "\t" << q << "\t" << percentage << endl;
      cout << "q:\t" << q << "\tsigma:\t" << sigma << "\tr:\t" << r << "\tt:\t" << t << "\tpercentage:\t" << percentage << endl;
    }
  }     
  fs.close();



  cout << "All finished." << endl;
    
  return 0;
}



