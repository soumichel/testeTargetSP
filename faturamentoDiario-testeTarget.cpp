#include <iostream>
#include <fstream>
#include <vector>
#include <json/json.h> // Inclua manualmente jsoncpp (pesquise jsoncpp GitHub) para manipulação de JSON
#include <limits>

using namespace std;

int main() {
    string fileName = "dados.json";

    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo JSON!" << endl;
        return 1;
    }

    Json::Value jsonData;
    Json::CharReaderBuilder readerBuilder;
    JSONCPP_STRING parseErrors;
    bool parsingSuccessful = Json::parseFromStream(readerBuilder, file, &jsonData, &parseErrors);
    file.close();

    if (!parsingSuccessful) {
        cerr << "Erro ao analisar o arquivo JSON: " << parseErrors << endl;
        return 1;
    }

    double minValue = numeric_limits<double>::max();
    double maxValue = numeric_limits<double>::min();
    double totalValue = 0.0;
    int countNonZeroDays = 0;

    for (const auto& entry : jsonData) {
        double value = entry["valor"].asDouble();
        if (value > 0.0) {
            if (value < minValue) minValue = value;
            if (value > maxValue) maxValue = value;
            totalValue += value;
            countNonZeroDays++;
        }
    }

    if (countNonZeroDays == 0) {
        cerr << "Nenhum dado de faturamento para calcular a média." << endl;
        return 1;
    }

    double averageValue = totalValue / countNonZeroDays;
    int countAboveAverage = 0;

    for (const auto& entry : jsonData) {
        double value = entry["valor"].asDouble();
        if (value > averageValue) {
            countAboveAverage++;
        }
    }

    cout << "Menor valor de faturamento: " << minValue << endl;
    cout << "Maior valor de faturamento: " << maxValue << endl;
    cout << "Número de dias com faturamento acima da média: " << countAboveAverage << endl;

    return 0;
}
