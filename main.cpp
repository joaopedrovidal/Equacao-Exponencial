#include <iostream>
#include <cmath>

using namespace std;


double calcularTempoResfriamento(double deltaT, double ta, double t0, double k) {
    if (ta >= t0) {
        throw invalid_argument("A temperatura ambiente (TA) deve ser menor que a temperatura inicial (T0).");
    }
    if (k <= 0) {
        throw invalid_argument("A constante k deve ser maior que zero.");
    }


    double t = - (1 / k) * log((ta - deltaT) / (ta - t0));
    return t;
}

int main() {

    double deltaT, ta, t0, k;

    cout << "Digite o valor da variacao de temperatura deltaT (C): ";
    cin >> deltaT;

    cout << "Digite a temperatura ambiente TA (C): ";
    cin >> ta;

    cout << "Digite a temperatura inicial T0 (C): ";
    cin >> t0;

    cout << "Digite a constante k (por minuto): ";
    cin >> k;

    try {
        double tempoResfriamento = calcularTempoResfriamento(deltaT, ta, t0, k);
        cout << "O tempo necessario para atingir a diferenca de temperatura deltaT e: " << tempoResfriamento << " minutos" << endl;
    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }

    return 0;
}
