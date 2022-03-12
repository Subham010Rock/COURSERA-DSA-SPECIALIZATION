#include <iostream>

long pisano(long m)
{
    if(m==2)
        return 4;
    long prev = 0;
    long curr = 1;
    long res = 0;
 
    for(int i = 0; i < m * m; i++)
    {
        long temp = 0;
        temp = curr;
        curr = (prev + curr) % m;
        prev = temp;
 
        if (prev == 0 && curr == 1)
            return res = i + 1;
    }
    //return res;
}

long long get_fibonacci_huge_fast(long long n, long long m) {
    long long pisano_length=pisano(m);
    n=n%pisano_length;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%m;
    }

    return current % m;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
