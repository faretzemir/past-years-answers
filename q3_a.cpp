#include <iostream>

using namespace std;

template <typename T>
T average(T* arr, int size){
    T avg = 0;
    for (int i=0; i< size; i++){
        avg += arr[i];
    }
    avg = avg / size;
    return avg;
}


int main(){

    //int array[5] = {1, 2, 3, 4, 5};
    float arr[3] = {1.2, 3.3, 5.5};
    cout << average(arr, 3);

    return 0;

}