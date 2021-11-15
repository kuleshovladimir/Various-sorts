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
    ofstream f("/Users/kuleshovladimir/Desktop/Programming/Sorts/Coctail shaking sort/Coctail shaking sort.csv", ios::out);
    for (int n = 1; n < 10000; n += 50) {
        auto t1 = std::chrono::high_resolution_clock::now();
        int N = n;
        int array[N];

        for (int i = 0; i < N; i++) {
            array[i] = rand_uns(-50, 50);
//        cout << array[i] << " ";
        }
//    cout << "массив до" << "\n";

        int control = n - 1;
        int left  = 0;
        int right = n - 1;
        do {
            for (int i = left; i < right; i++) {
                if (array[i] > array[i + 1]) {
                    swap(array[i], array[i + 1]);
                    control = i;
                }
            }
            right = control;
            for (int i = right; i > left; i--) {
                if (array[i] < array[i - 1]) {
                    swap(array[i], array[i - 1]);
                    control = i;
                }
            }
            left = control;
        } while (left < right);

        for (int i = 0; i < N; i++) {
//        cout << array[i] << " ";
        }
//    cout << "массив после" << "\n";
        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();

        f << duration << endl;
    }

    return 0;
}