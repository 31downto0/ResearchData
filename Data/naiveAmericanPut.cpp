#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <ctime>
#include "AmericanPut.h"

#define COUNT 10000
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
  
  double s;
  double k;
  double r;
  double q;
  double sigma;
  double t;

  double percentage;

  int n = 500;

  int i = 0;
  
  ifstream infile("paramsNorm.txt");
  
  clock_t time;
  time = clock();
  
  while(infile >> s >> k >> r >> q >> sigma >> t) {
    if(i < COUNT) {
      percentage = AmericanPut(s,k,r,q,sigma,t,n);
      i++;
    } else {
      break;
    }
  }

  time = clock() - time;

  cout << "Elapsed Time:\t" << time << endl;
  infile.close();
    
  return 0;
}



