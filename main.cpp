#include <iostream>
#include <vector>
using namespace std;

void PrintOutput(vector<int> &v) {
    for(int i = 0; i < v.size(); i++) {
        cout << 1 << "/" << v[i];
        if(i+1 < v.size())
            cout << "+";
    }
    cout << endl;
}

void FindOddFractors(int d, vector< pair<vector<int>, int> > &oddFactors) {
    vector<int> temp;
    cout << d << endl;
    for(int i = 3; i <= d; i = i + 2) {
        //bool exists = false;
        temp.clear();
        int t = d;
        for(int j = i; j <= t && t > 1; j= j+2) {
            if ((t % j == 0) && ((t / j) % 2 == 1)) {
                //exists = true;
                //t = t / j;
                temp.push_back(j);
                //temp.push_back(k);
            }
        }
        if(temp.size() != 1)
            oddFactors.push_back(pair<vector<int>, int>(temp, d));
    }
}

pair<int, int> SumOfUnitFactors(pair<vector<int>, int> &v) {
    pair<int, int> p;
    int sum = 0;
    for(int i = 0; i < v.first.size(); i++) {
        sum += (v.second/v.first[i]);
    }
    p.first = sum;
    p.second = v.second;
    return p;
}

void PrintFractions(int n, int d) {
    vector< pair<vector<int>, int> > factors;
    //Find the factors of denominator which are odd numbers.
    FindOddFractors(105, factors);

    //Find the sum of unit fractions of factors.
    for(int i = 0; i < factors.size(); i++) {
        pair<int, int> p = SumOfUnitFactors(factors[i]);
        if(p.first == n && p.second == d) {
            PrintOutput(factors[i].first);
            return;
        }
    }
    cout << "Not Present" << endl;
}


int main() {
    cout << "Hello, World!" << endl;
    int numerator, denominator;
    cin >> numerator >> denominator;
    PrintFractions(numerator, denominator);
    return 0;
}