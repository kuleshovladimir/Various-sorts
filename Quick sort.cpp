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

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int main() {
    ofstream f("/Users/kuleshovladimir/Desktop/Programming/Sorts/Quick sort/Quick sort.csv", ios::out);
    for (int n = 1; n < 10000; n += 50) {
        auto t1 = std::chrono::high_resolution_clock::now();
        int N = n;
        int array[N];

        for (int i = 0; i < N; i++) {
            array[i] = rand_uns(-50, 50);
        }

        quickSort(array, 0, n-1);

        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();

        f << duration << endl;
    }

    return 0;
}