#include <iostream>
#include <string>
using namespace std;

int main() {
    string nombre;
    string nombreMaslargo = "";
    int validos = 0;
    int vacios = 0;
    int cortos = 0;
    int conEspacio = 0;
    int totalVocales = 0;

    while (true) {
        cout << "Nombre o FIN: ";
        getline(cin, nombre);

        //1 detectar FIN y terminar el ciclo
        if (nombre == "FIN") {
            break;
        }
        //2 validar entrada vacia
        if (nombre.empty()) {
            vacios++;
            continue;
        }
        //3 validar la longitud minima
        if (nombre.length() < 3) {
            cortos++;
            continue;
        }
        //4 contar nombres valido y si contiene espacio
        validos++;
        if (nombre.find(' ') != string::npos) {
        conEspacio++;
        }
        //5 recorer caracteres con for y contar vocales
       for (char c : nombre) {
            char minC = tolower(static_cast<unsigned char>(c));
            if (minC == 'a' || minC == 'e' || minC == 'i' || minC == 'o' || minC == 'u') {
                totalVocales++;
            }
        }
        //6 actualizar nombre mas largo cuando corresponda
if (nombre.length() > nombreMaslargo.length()) {
            nombreMaslargo = nombre;
        }
    }
        //7 mostrar resummen final
        cout << "\n--- RESUMEN ---" << endl;
    cout << "Validos: " << validos << endl;
    cout << "Vacios: " << vacios << endl;
    cout << "Cortos: " << cortos << endl;
    cout << "Con espacio: " << conEspacio << endl;
    cout << "Total vocales: " << totalVocales << endl;

    if (validos > 0) {
        cout << "Mas largo: " << nombreMaslargo << " (" << nombreMaslargo.length() << " chars)" << endl;
    } else {
        cout << "Mas largo: No se ingresaron nombres validos." << endl;
    }

    return 0;
}
