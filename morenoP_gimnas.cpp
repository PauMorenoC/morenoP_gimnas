#include <iostream>

using namespace std;

class Tarifa {
private:
    string nomTarifa;
    double preuMensual;

public:
    Tarifa() : nomTarifa("Basica"), preuMensual(0.0) {}

    Tarifa(const string& nom, double preu)
        : nomTarifa(nom), preuMensual(preu) {
    }

    double getPreuMensual() const {
        return preuMensual;
    }
    string getNomTarifa() const {
        return nomTarifa;
    }

    void setPreuMensual(double preu) {
        preuMensual = preu;
    }
    void setNomTarifa(const string& nom) {
        nomTarifa = nom;
    }
};

class Soci {
protected:
    int idSoci;
    string nom;
    Tarifa tarifa;

public:
    Soci(int id, const string& nomSoci, const Tarifa& tarifaSoci)
        : idSoci(id), nom(nomSoci), tarifa(tarifaSoci) {
    }

    double calcularQuota() const {
        return tarifa.getPreuMensual();
    }

    void mostrarInfo() const {
        cout << "ID: " << idSoci
            << " | Nom: " << nom
            << " | Tarifa: " << tarifa.getNomTarifa()
            << " | Quota Final: " << calcularQuota() << " EUR"
            << endl;
    }
};

class SociVIP : public Soci {
private:
    double descompteEntrenador;

public:
    SociVIP(int id, const string& nomSoci, const Tarifa& tarifaSoci, double descompte)
        : Soci(id, nomSoci, tarifaSoci), descompteEntrenador(descompte) {
    }

    double calcularQuota() const {
        double preuBase = tarifa.getPreuMensual();
        return preuBase - (preuBase * (descompteEntrenador / 100));
    }

    void mostrarInfo() const {
        cout << "ID: " << idSoci
            << " | Nom: " << nom << " (VIP)"
            << " | Tarifa: " << tarifa.getNomTarifa()
            << " | Descompte Entrenador: " << descompteEntrenador << "%"
            << " | Quota Final: " << calcularQuota() << " EUR"
            << endl;
    }
};

int main() {
    Tarifa tarifaEstandard("Gimnas Full Access", 45.0);
    Tarifa tarifaPremium("Gimnas + Spa", 60.0);

    Soci sociNormal(101, "Pau", tarifaEstandard);
    SociVIP sociVip(102, "Miquel", tarifaPremium, 20.0);

    cout << "--- SISTEMA DE GESTIO ---" << endl << endl;

    sociNormal.mostrarInfo();
    sociVip.mostrarInfo();

}