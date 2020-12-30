#include <iostream>
#include <vector>
#include <fstream>
#include <deque>
#include <algorithm>
using namespace std;

int main(){
	unsigned long long int target = 0;
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
					match++;
					break;
				}
			}
		}
		if (match == 0) {
			target = numbers[i];
			cout << "This one right here chief: " << target << endl;
			break;
		}
		else {
			preamble.pop_front();
			preamble.push_back(numbers[i]);
		}
	}
	vector<unsigned long long int> myvec;
	int i = 0;
	unsigned long long int total = 0;
	do {
		total = 0;
		int j = i;
		myvec.clear();
		while (j < numbers.size() -1) {
			total += numbers[j];
			myvec.push_back(numbers[j]);
			j++;
			if (total == target)
				break;
		}
		i++;
	} while (total != target);
	sort(myvec.begin(),myvec.end());
	unsigned long long int encrypt_weak = myvec[myvec.size() - 1] + myvec[0];
	cout << encrypt_weak;
}