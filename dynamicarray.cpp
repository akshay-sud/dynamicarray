#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

template<class T>
class dynamicArray {
    T* base;
    int used = 0;
    int size = 10;
public:
    dynamicArray(int);
    void resize();
    void allocate(int);
    void pop();
    void push(T&);
    void set(T&);
    T get(int);
    T begin();
    T end();
    int length();
    int capacity();
    int getUsed();
    void setUsed(int);
    int getSize();
    void setSize(int);
};

template<class T>
dynamicArray<T>::dynamicArray(int c) {
    allocate(c);
}

template<class T>
void dynamicArray<T>::resize() {
    T* ptemp = new T [size*2];
    for (int i = 0; i < used; i++) {
        ptemp[i] = base[i];
    }
    delete [] base;
    base = ptemp;
    int x = capacity();
    x = x *2;
    setSize(x);
}

template<class T>
void dynamicArray<T>::allocate(int c) {
    setSize(c);
    base = new T [c];
}

template<class T>
void dynamicArray<T>::pop() {

    for (int i = 1; i < used; i++) {
        base[i - 1] = base[i];
        if (i == used - 2) {
            used--;
        }
        if (used == 0) {
            cout << "The value of variable 'used' is 0" << endl;
            cout << "" << endl;
        }
    }
}

template<class T>
void dynamicArray<T>::push(T& item) {
    set(item);
}

template<class T>
void dynamicArray<T>::set(T& item) {
    if (used == size) {
        resize();
    }
    else {
    base[used] = item;
    used++;
    }
}

template<class T>
T dynamicArray<T>::get(int c) {
    return base[c];
}

template<class T>
T dynamicArray<T>::begin() {
    return base[0];
}

template<class T>
T dynamicArray<T>::end() {
    return base[used - 1];
}

template<class T>
int dynamicArray<T>::length() {
    return used;
}

template<class T>
int dynamicArray<T>::capacity() {
    return size;
}

template<class T>
int dynamicArray<T>::getUsed() {
    return used;
}

template<class T>
void dynamicArray<T>::setUsed(int c) {
    used = c;
}

template<class T>
int dynamicArray<T>::getSize() {
    return size;
}

template<class T>
void dynamicArray<T>::setSize(int c) {
    size = c;
}

int main()
{
dynamicArray<string> xyz(10);
string line;

ifstream infile;
infile.open("words.txt");
while (!infile.eof()) {
    getline(infile, line);
    xyz.push(line);
}
infile.close();

cout << "the number of array elements is: " << xyz.getUsed() << endl;
cout << "We will now display the array: " << endl;
for (int i = 0; i < xyz.getUsed() + 1; i++) {
    cout << xyz.get(i) << endl;
}

//a lot of the above doesn't display due to cmd line display restrictions, only part of the array is seen printed due to this

cout << "" << endl;
cout << "The first string in the array is: ";
cout << xyz.begin() << endl;
cout << "The third string in the array is: ";
cout << xyz.get(2) << endl;
cout << "The last string in the array is: ";
cout << xyz.end() << endl;
cout << "The length of this array is: ";
cout << xyz.length() << endl;
cout << "Now we will remove the last string and return the 2nd to last string: ";
xyz.pop();
cout << xyz.end() << endl;
cout << "The length of this array is now: ";
cout << xyz.length() << endl;
cout << "The capacity of this array is: ";
cout << xyz.capacity() << endl;
    return 0;
}
