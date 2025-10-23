#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

int main() {
    std::cout << std::fixed << std::setprecision(2);

    int N;
    std::cout << "Introduce numero de empleados a procesar: ";
    if (!(std::cin >> N) || N <= 0) {
        std::cerr << "Numero invalido. Saliendo.\n";
        return 1;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    const double WEEKS_PER_MONTH = 4.33;

    for (int i = 0; i < N; ++i) {
        std::string nombre;
        double horas, tarifa;

        std::cout << "\nEmpleado " << (i+1) << ":\n";
        std::cout << "  Nombre: ";
        std::getline(std::cin, nombre);
        if (nombre.empty()) {
            std::cout << "  Nombre vacio, use 'Empleado" << (i+1) << "'.\n";
            nombre = "Empleado" + std::to_string(i+1);
        }

        std::cout << "  Horas trabajadas (semanales): ";
        while (!(std::cin >> horas) || horas < 0.0) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "  Horas invalidas. Introduce un numero >= 0: ";
        }

        std::cout << "  Tarifa por hora (euros): ";
        while (!(std::cin >> tarifa) || tarifa < 0.0) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "  Tarifa invalida. Introduce un numero >= 0: ";
        }

        std::cin.ignore(10000, '\n');

        double horas_normales = std::min(horas, 35.0);
        double horas_extra = std::max(0.0, horas - 35.0);

        double pago_normal = horas_normales * tarifa;
        double pago_extra  = horas_extra     * tarifa * 1.5;
        double bruto_semanal = pago_normal + pago_extra;

        double bruto_mensual = bruto_semanal * WEEKS_PER_MONTH;
        double impuesto_mensual = 0.0;
        if (bruto_mensual > 2000.0) {
            double resto = bruto_mensual - 2000.0;
            double tramo1 = std::min(resto, 220.0);            
            double tramo2 = std::max(0.0, resto - 220.0);      
            impuesto_mensual = tramo1 * 0.20 + tramo2 * 0.30;
        }

        double impuesto_semanal = impuesto_mensual / WEEKS_PER_MONTH;
        double neto_semanal = bruto_semanal - impuesto_semanal;

        // Salida
        std::cout << "\n--- Recibo semanal: " << nombre << " ---\n";
        std::cout << "Horas normales: " << horas_normales << " h\n";
        std::cout << "Horas extra   : " << horas_extra << " h\n";
        std::cout << "Bruto semanal : " << bruto_semanal << " €\n";
        std::cout << "Impuesto sem. : " << impuesto_semanal << " €\n";
        std::cout << "Neto semanal  : " << neto_semanal << " €\n";
        std::cout << "-------------------------------\n";
    }

    return 0;
}
