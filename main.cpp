#include <iostream>
#include <random>
#include <assert.h>
#include <string.h>

using namespace std;

#define MIN 100
#define MAX 500

mt19937 rng;

int generateRandomInt(int min, int max);
void printArray(int *array, size_t size);
void heapsort(int* array, size_t size);
bool validate(int* array, size_t size);

int main(int argc, char *argv[]) {
    rng.seed(random_device()());
    cout << "===========================================================" << endl;
    cout << "\tHeapsort Practice" << endl;
    cout << "===========================================================" << endl << endl;

    const int numberOfElements = generateRandomInt(MIN, MAX);
    int *numbers = new int[numberOfElements];
    for (int i = 0; i < numberOfElements; i++) {
        numbers[i] = generateRandomInt(0, 100);
    }

    printArray(numbers, numberOfElements);
    heapsort(numbers, numberOfElements);
    printArray(numbers, numberOfElements);
    assert(validate(numbers, numberOfElements) && "The sort is not ordering all the elements");

    system("read");
    return EXIT_SUCCESS;
}

int generateRandomInt(int min, int max) {
    uniform_int_distribution<mt19937::result_type> distribution(min, max); 
    return distribution(rng);
}

void printArray(int *array, size_t size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void maxheap(int* array, size_t size, int root_pos){
    int largest_pos=root_pos;
    int left_pos = (2*root_pos+1) ;
    int right_pos = (2*root_pos+2);

    if (left_pos <size&& array[left_pos] > array[largest_pos]) largest_pos = left_pos;
    if (right_pos<size && array[right_pos] > array[largest_pos]) largest_pos = right_pos;

    if (largest_pos!=root_pos){
        int temp=array[largest_pos];
        array[largest_pos]=array[root_pos];
        array[root_pos]=temp;
        
        maxheap(array, size, largest_pos); 
    }
}


void heapsort(int* array, size_t size) {
    int pos = size/2-1;
    while (pos>=0) maxheap(array, size, pos), --pos;

    pos = size-1;
    while (pos>=0){
        int temp=array[pos];
        array[pos]=array[0];
        array[0]=temp;

        maxheap(array, pos, 0);
        --pos;
    }
}

bool validate(int* array, size_t size) {
    for (int i = 0; i < size - 1; i++) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}