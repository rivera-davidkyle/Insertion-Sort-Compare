#include <chrono>
#include <iostream>
#include <stdio.h>
using namespace std;
using namespace std::chrono;

int ARR_SIZE = 1000;
double NUM_TEST_CASES = 10000;
int RANGE_F = 0;
int RANGE_C = 1000;

void insertionSortRecursive(int* arr, int n)
{
    if (n <= 1)
    {
        return;
    }
    insertionSortRecursive(arr, n-1);
    int last = arr[n-1];
    int j = n-2;
    while (j >= 0 && arr[j] > last)
    {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = last;
}

void insertionSort(int array[], int arrSize){
    for (int i = 1; i < arrSize; i++){
        int key = array[i];
        int j = i - 1;
        while ((j >= 0) && (array[j] > key)){
            array[j + 1]  = array[j];
            j -= 1;
        }
        array[j+1] = key;
    }
}

int* generateArr(int n)
{
    int *arr = new int[n];
    for(int i=0; i < n; i++)
    {
        int num_rng = rand() % RANGE_C + RANGE_F;
        arr[i] = num_rng;
    }
    return arr;
}

double test_is_recursive(double test_cases)
{
    double size = ARR_SIZE;
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

   auto sum = 0;
   static unsigned seed = time(NULL);
   for(int i = 0; i < test_cases; i++)
   {
       srand (seed++);
       int* test = generateArr(size);
       
       auto t1 = high_resolution_clock::now();
       insertionSortRecursive(test, size);
       auto t2 = high_resolution_clock::now();
       
        double duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
        sum += duration;
        
   }
   double avg = sum/test_cases;
   return avg;
}

double test_is_iterative(double test_cases)
{
    double size = ARR_SIZE;
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

   auto sum = 0;
   static unsigned seed = time(NULL);
   for(int i = 0; i < test_cases; i++)
   {
       srand (seed++);
       int* test = generateArr(size);
       
       auto t1 = high_resolution_clock::now();
       insertionSort(test, size);
       auto t2 = high_resolution_clock::now();
       
        double duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
        sum += duration;
        
   }
   double avg = sum/test_cases;
   return avg;
}

int main()
{
   double insertion_recursive_avg = test_is_recursive(NUM_TEST_CASES);
   double insertion_avg = test_is_iterative(NUM_TEST_CASES);
   cout << "Number of Test Cases = " << NUM_TEST_CASES << endl;
   cout << "Array Size per Test Case = " << ARR_SIZE << endl << endl;

   cout << "Insertion Sort (Recursive) average time: " << insertion_recursive_avg << " microseconds" << endl;
   cout << "Insertion Sort (Iterative) average time: " << insertion_avg << " microseconds" << endl;

    return 0;
}