import numpy as np
import matplotlib.pyplot as plt

def DFT(x):
    N=len(x)
    X=[]
    for k in range (N):
        sum_val=0+0j
        for n in range (N):
            angle=-2*np.pi*k*n/N
            w=complex(np.cos(angle),np.sin(angle))
            sum_val+=x[n]*w
        X.append(sum_val)   
    return X

Fs=50
N=50

f1=13
f2=5.6

x = [np.sin(2 * np.pi * f1 * n / Fs) + 
     np.sin(2 * np.pi * f2 * n / Fs)
     for n in range(N)]

X = DFT(x)
print("performed DFT of the given signal:")
for k in range(N):
    print(f"X[{k}] = {X[k]}")
for k in range (N):
    if abs(X[k]) > 10:
        print(f"magnitude of X[{k}] = {abs(X[k])}")


magnitudes = [abs(val) for val in X]

plt.figure()
plt.plot(x)
plt.title("Time Domain Signal")
plt.xlabel("n")
plt.ylabel("Amplitude")


plt.figure()
plt.stem(range(N), magnitudes)
plt.title("DFT Magnitude Spectrum")
plt.xlabel("k (frequency index)")
plt.ylabel("Magnitude")
plt.show()