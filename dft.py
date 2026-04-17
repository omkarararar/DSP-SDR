import numpy as np

def DFT(x):
    N = len(x)
    X = []

    for k in range(N):
        sum_val = 0 + 0j  # complex number

        for n in range(N):
            angle = -2 * np.pi * k * n / N
            w = complex(np.cos(angle), np.sin(angle))

            sum_val += x[n] * w

        X.append(sum_val)

    return X


# main
N = int(input("no. of samples: "))

print("enter signal samples:")
x = list(map(float, input().split()))

X = DFT(x)

print("performed DFT of the given signal:")
for k in range(N):
    print(f"X[{k}] = {X[k]}")

for k in range (N):
    print(f"magnitude of X[{k}] = {abs(X[k])}")
