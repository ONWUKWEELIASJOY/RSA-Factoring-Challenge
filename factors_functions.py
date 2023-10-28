#!/usr/bin/python3
import math

def trial_division(n):
    if n % 2 == 0:
        print(f"{n}={n//2}*{2}")
        return
    
    f = 3
    while f * f <= n:
        if n % f == 0:
            print(f"{n}={n//f}*{f}")
            return
        else:
            f += 2

    print(f"{n}={n}*{1}")

# Example usage
if __name__ == '__main__':
    trial_division(42)
