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

vector<string> writeout = {};

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

    //  Functions to simplify threads (For some reason having just one function is a problem...)
void fillVector1(int size, int amount){
    for(int i = 0; i < amount; i++){
        v1.push_back(generateRandomString(size));
    } 
}
void fillVector2(int size, int amount){
    for(int i = 0; i < amount; i++){
        v2.push_back(generateRandomString(size));
    } 
}
void fillVector3(int size, int amount){
    for(int i = 0; i < amount; i++){
        v3.push_back(generateRandomString(size));
    } 
}
void fillVector4(int size, int amount){
    for(int i = 0; i < amount; i++){
        v4.push_back(generateRandomString(size));
    } 
}
void fillVector5(int size, int amount){
    for(int i = 0; i < amount; i++){
        v5.push_back(generateRandomString(size));
    } 
}
void fillVector6(int size, int amount){
    for(int i = 0; i < amount; i++){
        v6.push_back(generateRandomString(size));
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
            //  Creation of all 6 threads
    thread t1(fillVector1, stringSize, stringAmount);
    thread t2(fillVector2, stringSize, stringAmount);
    thread t3(fillVector3, stringSize, stringAmount);
    thread t4(fillVector4, stringSize, stringAmount);
    thread t5(fillVector5, stringSize, stringAmount);
    thread t6(fillVector6, stringSize, stringAmount);
    
            //  Each of the threads is used to fill up their respective vectors
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();

    cout<<"Sort all 6 vectors toghether or separately? (T/S): ";
    string check;
    while(true){
        cin>>check;
        if(check == "T"){
                    //  Combining each of the 6 vectors into one
            writeout.insert(writeout.end(), v1.begin(), v1.end());
            writeout.insert(writeout.end(), v2.begin(), v2.end());
            writeout.insert(writeout.end(), v3.begin(), v3.end());
            writeout.insert(writeout.end(), v4.begin(), v4.end());
            writeout.insert(writeout.end(), v5.begin(), v5.end());
            writeout.insert(writeout.end(), v6.begin(), v6.end());

            sort(writeout.begin(), writeout.end()); //  Sorting

            for(auto i : writeout){     //Writing
                cout<<i<<endl;
            }
            return 0;
        }
        if(check == "S"){
            sort(v1.begin(), v1.end());
            sort(v2.begin(), v2.end());
            sort(v3.begin(), v3.end());
            sort(v4.begin(), v4.end());
            sort(v5.begin(), v5.end());
            sort(v6.begin(), v6.end());
            for(int i = 0; i < stringAmount; i++){
                cout<<"v1: ["<<v1.at(i)<<"]";
                cout<<" v2: ["<<v2.at(i)<<"]";
                cout<<" v3: ["<<v3.at(i)<<"]";
                cout<<" v4: ["<<v4.at(i)<<"]";
                cout<<" v5: ["<<v5.at(i)<<"]";
                cout<<" v6: ["<<v6.at(i)<<"]"<<endl;
            }
            return 0;
        }
    }
    return 0;
}
