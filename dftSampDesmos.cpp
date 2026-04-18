#define _USE_MATH_DEFINES
#include <vector>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

// DFT Function
vector<complex<double>> DFT(vector<double> x){
    int n = x.size();
    vector<complex<double>> res(n);

    for(int i = 0; i < n; i++){
        complex<double> sum(0,0);

        for(int j = 0; j < n; j++){
            double angle = -2 * M_PI * i * j / n;
            complex<double> w(cos(angle), sin(angle));
            sum += x[j] * w;
        }

        res[i] = sum;
    }

    return res;
}

/*
f1, f2 -> signal frequencies
fs -> sampling frequency
duration -> signal duration in seconds
N -> number of samples = duration * fs
*/
vector<double> generateSignal(double f1, double f2, double fs, double duration){
    int N = fs * duration;
    vector<double> signal(N);

    for(int n = 0; n < N; n++){
        double t = n / fs;  // time

        signal[n] = sin(2 * M_PI * f1 * t) + sin(2 * M_PI * f2 * t);
    }

    return signal;
}

int main(){
    double f1 = 10, f2 = 15;
    double fs = 50;       // change this to test aliasing -> nyquist criterion
    double duration = 2;

    vector<double> signal = generateSignal(f1, f2, fs, duration);

    //  TIME DOMAIN OUTPUT (for Desmos)
    cout << "Time Domain (t, x):" << endl;
    for(int n = 0; n < signal.size(); n++){
        double t = n / fs;
        cout << '(' << t << "," << signal[n] << ')' << endl;
    }

    cout << endl;

    //  DFT
    vector<complex<double>> X = DFT(signal);

    //  FREQUENCY DOMAIN OUTPUT (for Desmos)
    // cout << "Frequency Domain (f, |X|):" << endl;
    // for(int k = 0; k < X.size(); k++){
    //     double freq = k * fs / X.size();
    //     cout << '(' << freq << "," << abs(X[k]) << ')' << endl;
    // }

    return 0;
}