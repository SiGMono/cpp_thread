// 2024.05.24  --------- <thread> testy ---------
// ----------------------------------------------

#include <iostream>
#include <thread>
#include <windows.h>
using namespace std;

void func1();
void func2();
void func3();

int main()
{    
    //func1();
    //func2();
    cout << endl << endl;

    thread t1 {func1};
    thread t2 {func2};
    thread t3 {func3};

    t1.join();
    t2.join();
    t3.join();


    cout << endl << endl << "END" << endl;

    for (int x = 0; x < 500; x++) {
        cout << "x";
        Sleep(10);
    }
    //t1.join();


    //cin.get();
    return 0;
}

// ----------------------------------------------

void func1() {
    for (int x = 0; x < 100; x++) {
        cout << "_";
        Sleep(100);
    }
    
}

void func2() {
    for (int x = 0; x < 100; x++) {
        cout << "|";
        Sleep(60);
    }
}

void func3() {
    for (int x = 0; x < 100; x++) {
        cout << "o";
        Sleep(30);
    }
}