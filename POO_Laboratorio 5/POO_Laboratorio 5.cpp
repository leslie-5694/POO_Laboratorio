#include <iostream>
#include <vector>
#include <limits> // Para limpiar el buffer en caso de error
#include <sstream>

using namespace std;

class Producto {
private:
    string nombre;
    int codigo;
    float precio;
    int stock;

public:
    Producto(string nom, int cod, float prec, int stk)
        : nombre(nom), codigo(cod), precio(prec), stock(stk) {
    }

    void mostrar() {
        cout << "Código: " << codigo << ", Producto: " << nombre
            << ", Precio: Q" << precio << ", Stock: " << stock << endl;
    }

    int obtenerCodigo() { return codigo; }
    int obtenerStock() { return stock; }

    void actualizarStock(int cantidad) {
        if (cantidad > stock) {
            cout << "No hay suficiente stock disponible." << endl;
        }
        else {
            stock -= cantidad;
            cout << "Stock actualizado. Nuevo stock: " << stock << endl;
        }
    }

    float obtenerValor() { return stock * precio; }
};

void limpiarBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void agregarProducto(vector<Producto>& inventario) {
    string nombre;
    int codigo, stock;
    float precio;

    cout << "Ingrese el nombre del producto: ";
    cin.ignore(); // Evita problemas con getline
    getline(cin, nombre);

    cout << "Ingrese el código: ";
    cin >> codigo;
    if (cin.fail()) { limpiarBuffer(); return; } // Validación de entrada

    cout << "Ingrese el precio: ";
    cin >> precio;
    if (cin.fail()) { limpiarBuffer(); return; }

    cout << "Ingrese la cantidad en stock: ";
    cin >> stock;
    if (cin.fail()) { limpiarBuffer(); return; }

    inventario.push_back(Producto(nombre, codigo, precio, stock));
}

void mostrarInventario(vector<Producto>& inventario) {
    if (inventario.empty()) {
        cout << "No hay productos en el inventario." << endl;
        return;
    }
    for (Producto& producto : inventario) {
        producto.mostrar();
    }
}

void buscarProducto(vector<Producto>& inventario) {
    int codigo;
    cout << "Ingrese el código del producto a buscar: ";
    cin >> codigo;
    if (cin.fail()) { limpiarBuffer(); return; }

    for (Producto& producto : inventario) {
        if (producto.obtenerCodigo() == codigo) {
            cout << "Producto encontrado: ";
            producto.mostrar();
            return;
        }
    }
    cout << "Producto no encontrado." << endl;
}

void actualizarStock(vector<Producto>& inventario) {
    int codigo, cantidad;

    cout << "Ingrese el código del producto a actualizar: ";
    cin >> codigo;
    if (cin.fail()) { limpiarBuffer(); return; }

    for (Producto& producto : inventario) {
        if (producto.obtenerCodigo() == codigo) {
            cout << "Ingrese la cantidad a restar del stock: ";
            cin >> cantidad;
            if (cin.fail()) { limpiarBuffer(); return; }

            producto.actualizarStock(cantidad);
            return;
        }
    }
    cout << "Producto no encontrado." << endl;
}

void calcularValorTotal(vector<Producto>& inventario) {
    float total = 0;
    for (Producto& producto : inventario) {
        total += producto.obtenerValor();
    }
    cout << "Valor total del inventario: Q" << total << endl;
}

int main() {
    vector<Producto> inventario;
    int opcion;

    do {
        cout << "\nSistema de Inventario\n";
        cout << "1. Agregar producto\n";
        cout << "2. Mostrar inventario\n";
        cout << "3. Buscar producto por código\n";
        cout << "4. Actualizar stock\n";
        cout << "5. Calcular valor total del inventario\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        if (cin.fail()) { // Validar entrada inválida
            limpiarBuffer();
            cout << "Entrada inválida. Intente de nuevo.\n";
            continue;
        }

        switch (opcion) {
        case 1: agregarProducto(inventario); break;
        case 2: mostrarInventario(inventario); break;
        case 3: buscarProducto(inventario); break;
        case 4: actualizarStock(inventario); break;
        case 5: calcularValorTotal(inventario); break;
        case 6: cout << "Saliendo del programa...\n"; break;
        default: cout << "Opción no válida, intente de nuevo.\n";
        }
    } while (opcion != 6);

    return 0;
}