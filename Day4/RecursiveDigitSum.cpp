#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the superDigit function below.
long long int findSumOfDigitsGivenInString(string n){
    long long int numberOfDigits = n.size();
    long long int sum = 0;
    for(long long int i=0; i<numberOfDigits; i++){
        int a = (int)n[i]-48;
        sum +=a;
    }
    return sum;
}

long long int findSumOfDigits(long long int n){
    long long int sum = 0;
    while(n!=0){
        sum += n%10;
        n = n/10;
    }
    return sum;
}

long long int findNextSuperDigit(long long int n){
    if(n<=9) return n;
    long long int sumOfDigits = findSumOfDigits(n);
    return findNextSuperDigit(sumOfDigits);
}

int superDigit(string n, int k) {
    if(n.size() == 1 && k==1)return (n.at(0)-'0');
    long long int sumOfDigitsGivenInString = findSumOfDigitsGivenInString(n);
    long long int num = (sumOfDigitsGivenInString*k);
    int nextSuperDigit = findNextSuperDigit(num);
    return nextSuperDigit;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    string n = nk[0];

    int k = stoi(nk[1]);

    int result = superDigit(n, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
