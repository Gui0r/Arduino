#include <iostream>

int main() {
    double salarios[5];
    std::cout << "Digite os salários dos 5 funcionários:\n";
    for (int i = 0; i < 5; ++i) {
        std::cin >> salarios[i];
    }

    for (int i = 0; i < 5; ++i) {
        double salarioBruto = salarios[i];
        
        // Cálculo do INSS
        double inss;
        if (salarioBruto <= 1212.00) {
            inss = salarioBruto * 0.075;
        } else if (salarioBruto <= 2427.35) {
            inss = salarioBruto * 0.09;
        } else if (salarioBruto <= 3641.03) {
            inss = salarioBruto * 0.12;
        } else if (salarioBruto <= 7087.22) {
            inss = salarioBruto * 0.14;
        } else {
            inss = 7087.22 * 0.14; // Teto do INSS
        }

        double salarioBaseIR = salarioBruto - inss;

        // Cálculo do IR
        double ir;
        if (salarioBaseIR <= 1903.98) {
            ir = 0;
        } else if (salarioBaseIR <= 2826.65) {
            ir = (salarioBaseIR - 1903.98) * 0.075;
        } else if (salarioBaseIR <= 3751.05) {
            ir = (2826.65 - 1903.98) * 0.075 + (salarioBaseIR - 2826.65) * 0.15;
        } else if (salarioBaseIR <= 4664.68) {
            ir = (2826.65 - 1903.98) * 0.075 + (3751.05 - 2826.65) * 0.15 + (salarioBaseIR - 3751.05) * 0.225;
        } else {
            ir = (2826.65 - 1903.98) * 0.075 + (3751.05 - 2826.65) * 0.15 + (4664.68 - 3751.05) * 0.225 + (salarioBaseIR - 4664.68) * 0.275;
        }

        double salarioLiquido = salarioBruto - inss - ir;

        std::cout << "Salário bruto: " << salarioBruto << "\n";
        std::cout << "Desconto INSS: " << inss << "\n";
        std::cout << "Base para IR: " << salarioBaseIR << "\n";
        std::cout << "Desconto IR: " << ir << "\n";
        std::cout << "Salário líquido: " << salarioLiquido << "\n";
        std::cout << "--------------------------\n";
    }

    return 0;
}
