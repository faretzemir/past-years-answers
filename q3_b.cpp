#include <iostream>

using namespace std;

template <typename T>
class MyArray{
    private:
        int size;
        T* pArray;
    public:
        MyArray(){}

        MyArray(int s){
            size = s;
            pArray = new T[size];
        }

        void setArray(int pos, T val){
            pArray[pos] = val;
        }

        void getArray(){
            cout << endl;
            for(int i = 0; i < size; i++){
                cout << "Value at position " << i << ": " << pArray[i] << endl;
            }
        }
};

int main(){

    // instantiate int_array object of class array<int> with size 2
    MyArray< int > int_array(2);
    // set value to a first element
    int_array.setArray(0,3);
    // set value to a second element
    int_array.setArray(1,4);
    // call to array class member function to display array elements
    int_array.getArray();

    // instantiate float_array object of class array<float> with size 2
    MyArray< float > float_array(2);
    // set value to a first element
    float_array.setArray(0,3.9);
    // set value to a second element
    float_array.setArray(1,2.9);
    float_array.getArray();
    cout << endl;

    return 0;

}