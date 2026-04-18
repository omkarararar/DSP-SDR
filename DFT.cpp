#define _USE_MATH_DEFINES

#include <vector>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

/*
    DFT FORMULA:
    X[m] = sum_{n=0}^{N-1}  x[n] * e^(-j*2*pi*m*n/N)

    where:
    - X[m] is the m-th frequency component
    - x[n] is the n-th time-domain sample
    - N is the total number of samples
    - represent in cos sin also
*/

vector<complex<double>> DFT(vector<double> x){
    int n=x.size();
    vector<complex<double>> X(n);
    for(int i=0;i<n;i++){
        complex<double> sum(0,0);
        for(int j=0;j<n;j++){
            double angle=-2*M_PI*i*j/n;
            complex<double> w(cos(angle),sin(angle));
            sum+=x[j]*w;
        }
        X[i]=sum;
    }
    return X;
}

int main(){
    int n;
    cout<<"no. of samples:"<<endl;
    cin>>n;
    vector<double> sig(n);
    cout<<"enter signal samples:"<<endl;
    for(int i=0;i<n;i++){
        cin>>sig[i];
    }
    vector<complex<double>> X = DFT(sig);
    cout<<"performed DFT of the given signal:"<<endl;
    for(int i=0;i<n;i++){
        cout<<"X["<<i<<"] = "<<X[i]<<endl;
    }
}