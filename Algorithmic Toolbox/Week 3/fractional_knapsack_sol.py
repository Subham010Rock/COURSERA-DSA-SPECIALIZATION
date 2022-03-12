# Uses python3
import sys

def get_optimal_value(capacity, weights, values):
    value = 0.
    # write your code here
    d={}
    for i in range(len(weights)):
        d[values[i]/weights[i]]=weights[i]
    for i,j in sorted(d.items(),key=lambda x:x[0],reverse=True):
        if(capacity==0):
            return value
        m=min(j,capacity)
        value+=m*i
        capacity-=m

    return value


if __name__ == "__main__":
    data = list(map(int, sys.stdin.read().split()))
    n, capacity = data[0:2]
    values = data[2:(2 * n + 2):2]
    weights = data[3:(2 * n + 2):2]
    opt_value = get_optimal_value(capacity, weights, values)
    print("{:.4f}".format(opt_value))
