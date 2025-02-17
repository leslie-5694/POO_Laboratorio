#include <iostream>
using namespace std;

// Clase base Vehiculo
class Vehiculo {
private:
    string marca;
    string modelo;
    double precio;

public:
    Vehiculo(string _marca, string _modelo, double _precio) : marca(_marca), modelo(_modelo), precio(_precio) {}

    virtual void mostrarInfo() {
        cout << "Vehículo: " << marca << " Modelo: " << modelo << ", Precio: $" << precio;
    }

    // Métodos get y set para encapsulamiento
    string getMarca() { return marca; }
    string getModelo() { return modelo; }
    double getPrecio() { return precio; }
};

// Clases derivadas
class Automovil : public Vehiculo {
private:
    int numPuertas;
public:
    Automovil(string _marca, string _modelo, double _precio, int _numPuertas)
        : Vehiculo(_marca, _modelo, _precio), numPuertas(_numPuertas) {
    }

    void mostrarInfo() override {
        Vehiculo::mostrarInfo();
        cout << ", Puertas: " << numPuertas << endl;
    }
};

class Motocicleta : public Vehiculo {
private:
    int cilindrada;
public:
    Motocicleta(string _marca, string _modelo, double _precio, int _cilindrada)
        : Vehiculo(_marca, _modelo, _precio), cilindrada(_cilindrada) {
    }

    void mostrarInfo() override {
        Vehiculo::mostrarInfo();
        cout << ", Cilindrada: " << cilindrada << "cc" << endl;
    }
};

class Camioneta : public Vehiculo {
private:
    double capacidadCarga;
public:
    Camioneta(string _marca, string _modelo, double _precio, double _capacidadCarga)
        : Vehiculo(_marca, _modelo, _precio), capacidadCarga(_capacidadCarga) {
    }

    void mostrarInfo() override {
        Vehiculo::mostrarInfo();
        cout << ", Capacidad de carga: " << capacidadCarga << " toneladas" << endl;
    }
};

// Clase Cliente
class Cliente {
private:
    string nombre;
    int edad;
public:
    Cliente(string _nombre, int _edad) : nombre(_nombre), edad(_edad) {}

    void comprarVehiculo(Vehiculo& v) {
        cout << "Cliente " << nombre << " ha comprado un " << v.getMarca() << " " << v.getModelo() << "." << endl;
    }
};

// Funcion principal
int main() {
    Automovil auto1("Toyota", "Corolla", 25000, 4);
    Motocicleta moto1("Yamaha", "R1", 18000, 1000);
    Camioneta camion1("Ford", "Ranger", 30000, 1.5);
    Cliente cliente1("Juan", 35);

    // Mostrar información de los vehículos
    auto1.mostrarInfo();
    moto1.mostrarInfo();
    camion1.mostrarInfo();

    // Simular la compra
    cliente1.comprarVehiculo(auto1);

    return 0;
}


