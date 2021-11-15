#include <iostream>
#include <chrono>
#include <random>
#include <fstream>

using namespace std;

int rand_uns(int min, int max) {
    unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
    static default_random_engine e(seed);
    uniform_int_distribution<int> d(min, max);
    return d(e);
}

void swap(int *a, int *b){
    int l;
    l = *a;
    *a = *b;
    *b = l;
}

int main() {
    ofstream f("/Users/kuleshovladimir/Desktop/Programming/Sorts/Bubble sort1/Bubble sort1 Reverse.csv", ios::out);
    for (int n = 1; n < 10000; n += 50) {
        int N = n;
        int array[N];
        int arrayOk[N];
        int arrayReverse[N];

        for (int i = 0; i < N; i++) {
            array[i] = rand_uns(-50, 50);
        }

        for (int i = 0; i < N; i++) {
            arrayOk[i] = i;
        }

        for (int i = N - 1; i > -1; i--) {
            arrayReverse[i] = i;
        }

        auto t1 = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < N; i++) {
            int count = 0;
            for (int j = 0; j < N; j++) {
                if (arrayReverse[j + 1] < arrayReverse[j]) {
                    swap(arrayReverse + j + 1, arrayReverse + j);
                    count++;
                }
            }
            if (count == 0) {
                continue;
            }
        }

        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();

        f << duration << endl;
    }

    return 0;
}