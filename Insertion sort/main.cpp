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

int main() {
    ofstream f("/Users/kuleshovladimir/Desktop/Programming/Sorts/Insertion sort/Insertion sort Reverse.csv", ios::out);
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

        for (int j = 2; j < N; j++) {
            int per = arrayReverse[j];
            int i = j - 1;
            while(i > 0 and arrayReverse[i] > per){
                arrayReverse[i + 1] = arrayReverse[i];
                i--;
            }
            arrayReverse[i + 1] = per;
        }

        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();

        f << duration << endl;
    }

    return 0;
}
