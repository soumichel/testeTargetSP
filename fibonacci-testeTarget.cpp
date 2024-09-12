#include <iostream>
using namespace std;

bool pertenceFibonacci(int numero) {
    int a = 0, b = 1, proximo = 0;
    
    if (numero == 0 || numero == 1) return true;
    
    while (proximo <= numero) {
        proximo = a + b;
        a = b;
        b = proximo;
        if (proximo == numero) return true;
    }
    
    return false;
}

int main() {
    int numero;
    cout << "Informe um número: ";
    cin >> numero;
    
    if (pertenceFibonacci(numero)) {
        cout << "O número " << numero << " pertence à sequência de Fibonacci.\n";
    } else {
        cout << "O número " << numero << " NÃO pertence à sequência de Fibonacci.\n";
    }

    return 0;
}
