#define _USE_MATH_DEFINES
#include <vector>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

vector<complex<double>> DFT(vector<double> x){
    int n=x.size();
    vector<complex<double>> res(n);
    for(int i=0;i<n;i++){
        complex<double> sum(0,0);
        for(int j=0;j<n;j++){
            double angle=-2*M_PI*i*j/n;
            complex<double> w(cos(angle),sin(angle));
            sum+=x[j]*w;
        }
        res[i]=sum;
    }
    return res;
}


/*
f-> signal freq
fs-> sampling freq
durations-> signal duration in seconds
N-> number of samples = duration*fs
*/
vector<double> generateSignal(double f1,double f2, double fs, double duration){
    int N=duration*fs;
    vector<double> signal(N);
    for(int n=0;n<N;n++){
        double t=n/fs;  //actual time at which the nth sample is taken
        signal[n]=sin(2*M_PI*f1*t) + sin(2*M_PI*f2*t);  //generating 2 sine wave signal
    }
    return signal;
} 

int main(){
    double f1,f2,fs,duration;
    f1=10,f2=15;fs=3;duration=5; // aliasing will occur as fs<2f -> fs<2*f

    vector<double> signal=generateSignal(f1,f2,fs,duration);
    vector<complex<double>> x=DFT(signal);
    cout<<"DFT of the generated signal:"<<endl;
    for(int i=0;i<x.size();i++){
        cout<<"X["<<i<<"] = "<<x[i]<<endl;
    }
    return 0;
}