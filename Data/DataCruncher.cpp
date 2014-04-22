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
   *t - expiration time
   *s - stock price
   *k - strike price
   *n - height of binomial tree
   *r - risk free rate of interest
   *sigma - volatility
   *q - dividend
   */
  double k = 150;
  double r = .05;
  double q = .02;
  double sigma = .3;
  double t = .5;
  int n = 500;

  string filename = "sigma/t.txt";

  double percentage;
  double prevPercentage;
  double outsidestep = .05;
  double insidestep = .000001;
  double dPercentage;
  
  ofstream fs;
  fs.open("sigma/t.txt");
  
  
  for(t = .001; t <= 2; t += .05) {
    for(sigma = .05; sigma <= 5; sigma += outsidestep){
      cout << "t:\t" << t << "\tVolatility:\t" << sigma  << endl;
      for(int i = 0; i < 2; i++){
      	if(i == 1){
      	  percentage = deltafinder(k,r,q,sigma,t,0,150,n);
      	  dPercentage = (percentage - prevPercentage) / insidestep;
      	  fs << t << "\t" << sigma << "\t" << dPercentage << endl;
      	} else {
      	  percentage = deltafinder(k,r,q,sigma-insidestep,t,0,150,n);
      	  prevPercentage = percentage;
      	}
      }
    }
  }
   
  
    
    fs.close();

    filename = "sigma/r.txt";
   
    
    fs.open("sigma/r.txt");
    
    k = 150;
    r = .05;
    q = .02;
    sigma = .3;
    t = .5;
    n = 500;
    
    for(r = .001; r <= 2; r += .05) {
      for(sigma = .05; sigma <= 5; sigma += outsidestep){
        cout << "r:\t" << r << "\tVolatility:\t" << sigma  << endl;
        for(int i = 0; i < 2; i++){
          if(i == 1){
            percentage = deltafinder(k,r,q,sigma,t,0,150,n);
            dPercentage = (percentage - prevPercentage) / insidestep;
            fs << r << "\t" << sigma << "\t" << dPercentage << endl;
          } else {
            percentage = deltafinder(k,r,q,sigma-insidestep,t,0,150,n);
            prevPercentage = percentage;
          }
        }
      }
    }

    fs.close();

    filename = "sigma/q.txt";


    
    fs.open("sigma/q.txt");
    
    k = 150;
    r = .05;
    q = .02;
    sigma = .3;
    t = .5;
    n = 500;
    
    for(q = 0; q <= .5; q += .01) {
      for(sigma = .05; sigma <= 5; sigma += outsidestep){
        cout << "q:\t" << q << "\tVolatility:\t" << sigma  << endl;
        for(int i = 0; i < 2; i++){
          if(i == 1){
            percentage = deltafinder(k,r,q,sigma,t,0,150,n);
            dPercentage = (percentage - prevPercentage) / insidestep;
            fs << q << "\t" << sigma << "\t" << dPercentage << endl;
          } else {
            percentage = deltafinder(k,r,q,sigma-insidestep,t,0,150,n);
            prevPercentage = percentage;
          }
        }
      }
    }

    fs.close();


    filename = "q/sigma.txt";

  
    fs.open("q/sigma.txt");
    
    k = 150;
    r = .05;
    q = .02;
    sigma = .3;
    t = .5;
    n = 500;

    outsidestep = .01;
    
    for(sigma = .05; sigma <= 5; sigma += .05) {
      for(q = 0; q <= .5; q += outsidestep){
        cout << "Volatility:\t" << sigma << "\tDividend Rate:\t" << q  << endl;
        for(int i = 0; i < 2; i++){
          if(i == 1){
            percentage = deltafinder(k,r,q,sigma,t,0,150,n);
            dPercentage = (percentage - prevPercentage) / insidestep;
            fs << sigma << "\t" << q << "\t" << dPercentage << endl;
          } else {
            percentage = deltafinder(k,r,q,sigma-insidestep,t,0,150,n);
            prevPercentage = percentage;
          }
        }
      }
    }

    fs.close();

    filename = "q/t.txt";

    
    fs.open("q/t.txt");
    
    k = 150;
    r = .05;
    q = .02;
    sigma = .3;
    t = .5;
    n = 500;
  
    for(t = .001; t <= 2; t += .05) {
      for(q = 0; q <= .5; q += outsidestep){
        cout << "t:\t" << t << "\tDividend Rate:\t" << q  << endl;
        for(int i = 0; i < 2; i++){
          if(i == 1){
            percentage = deltafinder(k,r,q,sigma,t,0,150,n);
            dPercentage = (percentage - prevPercentage) / insidestep;
            fs << t << "\t" << q << "\t" << dPercentage << endl;
          } else {
            percentage = deltafinder(k,r,q,sigma-insidestep,t,0,150,n);
            prevPercentage = percentage;
          }
        }
      }
    }

    fs.close();

    filename = "q/r.txt";

    
    fs.open("q/r.txt");
    
    k = 150;
    r = .05;
    q = .02;
    sigma = .3;
    t = .5;
    n = 500;
  
    for(r = .001; r <= 2; r += .05) {
      for(q = 0; q <= .5; q += outsidestep){
        cout << "r:\t" << r << "\tDividend Rate:\t" << q  << endl;
        for(int i = 0; i < 2; i++){
          if(i == 1){
            percentage = deltafinder(k,r,q,sigma,t,0,150,n);
            dPercentage = (percentage - prevPercentage) / insidestep;
            fs << r << "\t" << q << "\t" << dPercentage << endl;
          } else {
            percentage = deltafinder(k,r,q,sigma-insidestep,t,0,150,n);
            prevPercentage = percentage;
          }
        }
      }
    }

    fs.close();

    filename = "r/sigma.txt";

    

    fs.open("r/sigma.txt");
    
    k = 150;
    r = .05;
    q = .02;
    sigma = .3;
    t = .5;
    n = 500;
  
    for(sigma = .05; sigma <= 5; sigma += .05) {
      for(r = .001; r <= 2; r += outsidestep){
        cout << "Volatility:\t" << sigma << "\tr:\t" << r << endl;
        for(int i = 0; i < 2; i++){
          if(i == 1){
            percentage = deltafinder(k,r,q,sigma,t,0,150,n);
            dPercentage = (percentage - prevPercentage) / insidestep;
            fs << sigma << "\t" << r << "\t" << dPercentage << endl;
          } else {
            percentage = deltafinder(k,r,q,sigma-insidestep,t,0,150,n);
            prevPercentage = percentage;
          }
        }
      }
    }

    fs.close();

    filename = "r/t.txt";

    
  
    fs.open("r/t.txt");
    
    k = 150;
    r = .05;
    q = .02;
    sigma = .3;
    t = .5;
    n = 500;
  
    for(t = .0001; t <= 2; t += .05) {
      for(r = .001; r <= 2; r += outsidestep){
        cout << "t:\t" << t << "\tr:\t" << r << endl;
        for(int i = 0; i < 2; i++){
          if(i == 1){
            percentage = deltafinder(k,r,q,sigma,t,0,150,n);
            dPercentage = (percentage - prevPercentage) / insidestep;
            fs << t << "\t" << r << "\t" << dPercentage << endl;
          } else {
            percentage = deltafinder(k,r,q,sigma-insidestep,t,0,150,n);
            prevPercentage = percentage;
          }
        }
      }
    }

    fs.close();

    filename = "r/q.txt";

    

    fs.open("r/q.txt");
    
    k = 150;
    r = .05;
    q = .02;
    sigma = .3;
    t = .5;
    n = 500;
  
    for(q = 0; q <= .5; q += .01) {
      for(r = .001; r <= 2; r += outsidestep){
        cout << "q:\t" << q << "\tr:\t" << r << endl;
        for(int i = 0; i < 2; i++){
          if(i == 1){
            percentage = deltafinder(k,r,q,sigma,t,0,150,n);
            dPercentage = (percentage - prevPercentage) / insidestep;
            fs << q << "\t" << r << "\t" << dPercentage << endl;
          } else {
            percentage = deltafinder(k,r,q,sigma-insidestep,t,0,150,n);
            prevPercentage = percentage;
          }
        }
      }
    }

    fs.close();

    filename = "t/sigma.txt";

    
    
    fs.open("t/sigma.txt");
    
    k = 150;
    r = .05;
    q = .02;
    sigma = .3;
    t = .5;
    n = 500;
  
    for(sigma = .05; sigma <= 5; sigma += .05) {
      for(t = .001; t <= 2; t += outsidestep){
        cout << "Volatility:\t" << sigma << "\tt:\t" << t << endl;
        for(int i = 0; i < 2; i++){
          if(i == 1){
            percentage = deltafinder(k,r,q,sigma,t,0,150,n);
            dPercentage = (percentage - prevPercentage) / insidestep;
            fs << sigma << "\t" << t << "\t" << dPercentage << endl;
          } else {
            percentage = deltafinder(k,r,q,sigma-insidestep,t,0,150,n);
            prevPercentage = percentage;
          }
        }
      }
    }

    fs.close();

    filename = "t/r.txt";

    
  
    fs.open("t/r.txt");
    
    k = 150;
    r = .05;
    q = .02;
    sigma = .3;
    t = .5;
    n = 500;
  
    for(r = .001; r <= 2; r += .05) {
      for(t = .001; t <= 2; t += outsidestep){
        cout << "r:\t" << r << "\tt:\t" << t << endl;
        for(int i = 0; i < 2; i++){
          if(i == 1){
            percentage = deltafinder(k,r,q,sigma,t,0,150,n);
            dPercentage = (percentage - prevPercentage) / insidestep;
            fs << r << "\t" << t << "\t" << dPercentage << endl;
          } else {
            percentage = deltafinder(k,r,q,sigma-insidestep,t,0,150,n);
            prevPercentage = percentage;
          }
        }
      }
    }

    fs.close();

    filename = "t/q.txt";

    
  
    fs.open("t/q.txt");
    
    k = 150;
    r = .05;
    q = .02;
    sigma = .3;
    t = .5;
    n = 500;
  
    for(q = 0; q <= .5; q += .01) {
      for(t = .001; t <= 2; t += outsidestep){
        cout << "q:\t" << q << "\tt:\t" << t << endl;
        for(int i = 0; i < 2; i++){
          if(i == 1){
            percentage = deltafinder(k,r,q,sigma,t,0,150,n);
            dPercentage = (percentage - prevPercentage) / insidestep;
            fs << q << "\t" << t << "\t" << dPercentage << endl;
          } else {
            percentage = deltafinder(k,r,q,sigma-insidestep,t,0,150,n);
            prevPercentage = percentage;
          }
        }
      }
    }

    fs.close();



  cout << "All finished." << endl;
    
  return 0;
}



