#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // Valores de faturamento por estado
    double spValue = 67836.43;
    double rjValue = 36678.66;
    double mgValue = 29229.88;
    double esValue = 27165.48;
    double outrosValue = 19849.53;

    double totalValue = spValue + rjValue + mgValue + esValue + outrosValue;

    // Calcular o percentual de representação de cada estado
    double spPorcentagem = (spValue / totalValue) * 100;
    double rjPorcentagem = (rjValue / totalValue) * 100;
    double mgPorcentagem = (mgValue / totalValue) * 100;
    double esPorcentagem = (esValue / totalValue) * 100;
    double outrosPorcentagem = (outrosValue / totalValue) * 100;

    // Exibir os resultados com precisão de 2 casas decimais
    cout << fixed << setprecision(2);

    cout << "Percentual de representação por estado:" << endl;
    cout << "SP: " << spPorcentagem << "%" << endl;
    cout << "RJ: " << rjPorcentagem << "%" << endl;
    cout << "MG: " << mgPorcentagem << "%" << endl;
    cout << "ES: " << esPorcentagem << "%" << endl;
    cout << "Outros: " << outrosPorcentagem << "%" << endl;

    return 0;
}
