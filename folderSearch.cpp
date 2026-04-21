#include <iostream>
#include <thread>
#include <windows.h>
#include <vector>
#include <string>
#include <random>

using namespace std;

vector<string> v1;
vector<string> v2;
vector<string> v3;
vector<string> v4;
vector<string> v5;
vector<string> v6;

string generateRandomString(int length)
{
    // Define the list of possible characters
    const string CHARACTERS
        = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuv"
          "wxyz0123456789";

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


int main(int argc, char const *argv[])
{
    int stringSize = 0, stringAmount = 0;
    cout<<"===        RANDOM LETTER SORTER VIA THREADS        ==="<<endl;
    cout<<"String size: ";
    cin>>stringSize;
    cout<<"Amount of strings per vector (6 vectors): "<<endl;
    cin>>stringAmount;
    for(int i = 0; i < stringAmount; i++){
        v1.push_back(generateRandomString(stringSize));
        v2.push_back(generateRandomString(stringSize));
        v3.push_back(generateRandomString(stringSize));
        v4.push_back(generateRandomString(stringSize));
        v5.push_back(generateRandomString(stringSize));
        v6.push_back(generateRandomString(stringSize));
    }
    return 0;
}
