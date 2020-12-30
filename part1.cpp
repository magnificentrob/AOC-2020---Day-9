#include <iostream>
#include <vector>
#include <fstream>
#include <deque>
#include <algorithm>
using namespace std;
//26134589
int main()
{
    ifstream input;
    input.open("input.txt");
    int preamble_size = 25;
    vector<unsigned long long int> numbers;
    deque<unsigned long long int> preamble;
    unsigned long long int a;
    while (!input.eof()) {
        input >> a;
        numbers.push_back(a);
    }
    input.close();
    for (int i = 0; i < preamble_size; i++) {
        preamble.push_back(numbers[i]);
    }

    for (int i = preamble_size; i < numbers.size(); i++) {
        int match = 0;
        for (int j = 0; j < preamble_size; j++) {
            unsigned long long int x;
            if (numbers[i] > preamble[j]) {
                x = numbers[i] - preamble[j];
                deque<unsigned long long int> searchable = preamble;
                searchable.erase(searchable.begin() + j);
                deque<unsigned long long int>::iterator it;
                it = find(searchable.begin(), searchable.end(), x);
                if (it != searchable.end()) {
                    cout << preamble[j] << " " << x << " " << numbers[i] << endl;
                    match++;
                    break;
                }
            }
        }
        if (match == 0) {
            cout << "This one right here chief: " << numbers[i] << endl;
            break;
        }
        else {
            preamble.pop_front();
            preamble.push_back(numbers[i]);
        }
        cout << endl;
    }
}