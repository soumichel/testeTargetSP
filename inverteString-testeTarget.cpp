#include <iostream>
#include <string>

using namespace std;

void inverterString(string& str) {
    int n = str.length();
    for (int i = 0; i < n / 2; ++i) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

int main() {
    string minhaString;
    
    cout << "Digite a string para inverter: ";
    getline(cin, minhaString);
    
    inverterString(minhaString);
    
    cout << "String invertida: " << minhaString << endl;
    
    return 0;
}
