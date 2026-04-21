#include <iostream>
#include <thread>
#include <windows.h>
#include <vector>
#include <string>
#include <random>
#include <bits/stdc++.h>

using namespace std;

vector<string> v1;
vector<string> v2;
vector<string> v3;
vector<string> v4;
vector<string> v5;
vector<string> v6;

vector<string> writeout;

string generateRandomString(int length)
{
    // Define the list of possible characters
    const string CHARACTERS
        = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

    // Create a random number generator
    random_device rd;
    mt19937 generator(rd());

    // Create a distribution to uniformly select from all
    // characters
    uniform_int_distribution<> distribution(
        0, CHARACTERS.size() - 1);

    // Generate the random string
    string random_string;
    for (int i = 0; i < length; ++i) {
        random_string
            += CHARACTERS[distribution(generator)];
    }

    return random_string;
}

    //  Function to simplify threads
void fillVector(vector<string> v, int size, int amount){
    for(int i = 0; i < amount; i++){
        v.push_back(generateRandomString(size));
    }
    
}

int main(int argc, char const *argv[])
{
    int stringSize = 0, stringAmount = 0;
    cout<<"===        RANDOM LETTER SORTER VIA THREADS        ==="<<endl;
    cout<<"String size: ";
    cin>>stringSize;
    cout<<"Amount of strings per vector (6 vectors): ";
    cin>>stringAmount;
            //  All 6 threads
    thread t1(fillVector, v1, stringSize, stringAmount);
    thread t2(fillVector, v2, stringSize, stringAmount);
    thread t3(fillVector, v3, stringSize, stringAmount);
    thread t4(fillVector, v4, stringSize, stringAmount);
    thread t5(fillVector, v5, stringSize, stringAmount);
    thread t6(fillVector, v6, stringSize, stringAmount);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();

    writeout.insert(writeout.end(), v1.begin(), v1.end());
    writeout.insert(writeout.end(), v2.begin(), v2.end());
    writeout.insert(writeout.end(), v3.begin(), v3.end());
    writeout.insert(writeout.end(), v4.begin(), v4.end());
    writeout.insert(writeout.end(), v5.begin(), v5.end());
    writeout.insert(writeout.end(), v6.begin(), v6.end());

    sort(writeout.begin(), writeout.end());

    for(auto v : writeout){
        cout<<v<<endl;
    }

    //      FAILING

    return 0;
}
