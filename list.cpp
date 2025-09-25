#include <iostream>
using namespace std;

const int MAX = 1000; 

struct ArrayList {
    int arr[MAX];  
    int size;      

    ArrayList() { size = 0; }

    int get(int i) {
        if (i < 0 || i >= size) {
            cout << "Vi tri khong hop le\n";
            return -1;
        }
        return arr[i];
    }

    void addFirst(int x) {
        if (size >= MAX) return;
        for (int i = size; i > 0; i--) arr[i] = arr[i - 1];
        arr[0] = x;
        size++;
    }

    void addLast(int x) {
        if (size >= MAX) return;
        arr[size] = x;
        size++;
    }

    void insertAt(int x, int i) {
        if (i < 0 || i > size || size >= MAX) return;
        for (int j = size; j > i; j--) arr[j] = arr[j - 1];
        arr[i] = x;
        size++;
    }

    void removeFirst() {
        if (size == 0) return;
        for (int i = 0; i < size - 1; i++) arr[i] = arr[i + 1];
        size--;
    }

    void removeLast() {
        if (size == 0) return;
        size--;
    }

    void removeAt(int i) {
        if (i < 0 || i >= size) return;
        for (int j = i; j < size - 1; j++) arr[j] = arr[j + 1];
        size--;
    }

    void traverse() {
        for (int i = 0; i < size; i++) cout << arr[i] << " ";
        cout << endl;
    }

    void traverseReverse() {
        for (int i = size - 1; i >= 0; i--) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    ArrayList L;
    L.addFirst(10);    
    L.addLast(20);     
    L.insertAt(15, 1); 

    cout << "Danh sach: ";
    L.traverse();

    L.removeAt(1);     
    cout << "Sau khi xoa tai vi tri 1: ";
    L.traverse();

    cout << "Duyet nguoc: ";
    L.traverseReverse();

    return 0;
}
