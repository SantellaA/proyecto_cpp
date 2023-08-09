/*
	Id.Programa: *nombre*
	Autores......: *integrantes*
	Fecha......: Agosto-2023
	Consigna.: Dados 2 valores enteros y distintos emitir cartel apropiado
	               que informe el mayor entre ellos.
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Definición de estructuras de datos
struct Especialidad {
    char nombre[20];
};

struct Medico {
    char apellidoNombre[20];
    char nroMatricula[7];
    char nombreEspecialidad[20];
    char turno; // 'M', 'T' o 'N'
};

struct Turno{
    char nombreEspecialidad[20];
    int dia; // Día del mes (1-31)
    int hora; // Hora en formato HHMM (800-1930)
    char obraSocial[15];
    char nroCredencial[7];
};

struct SolicitudTurno {
    char apellidoNombre[20];
    int edad;
    char obraSocial[15];
    char nroMatricula[9];
    char nombreEspecialidad[20];
    int dia; // Día del mes (1-31)
    char turno; // 'M', 'T' o 'N'
};

void LeeMedicos(ifstream &archivoMedicos, Medico* medicos[], int &numMedicos) {
    if (!archivoMedicos.is_open()) {
        cout << "Error al abrir el archivo Medicos.Txt" << endl;
        return;
    }

    numMedicos = 0;
    while (archivoMedicos >> medicos[numMedicos]->apellidoNombre
                           >> medicos[numMedicos]->nroMatricula
                           >> medicos[numMedicos]->nombreEspecialidad
                           >> medicos[numMedicos]->turno) {
        numMedicos++;
    }
}

void LeeEspecialidad(ifstream &archivoEspecialidades, Especialidad* especialidades[], int &numEspecialidades) {
    if (!archivoEspecialidades.is_open()) {
        cout << "Error al abrir el archivo Especialidades.Txt" << endl;
        return;
    }

    numEspecialidades = 0;
    while (archivoEspecialidades >> especialidades[numEspecialidades]->nombre) {
        numEspecialidades++;
    }
}

void LeeTurnos(ifstream archivoTurnos, Turno* turnos[], int &numTurnos) {
    if (!archivoSolicitudes.is_open()) {
        cout << "Error al abrir el archivo SolicitudTurnos.Txt" << endl;
        return;
    }

    numTurnos = 0;
    while (archivoTurnos   >> turnos[numSolicitudes]->apellidoNombre
                           >> turnos[numSolicitudes]->edad
                           >> turnos[numSolicitudes]->obraSocial
                           >> turnos[numSolicitudes]->nroMatricula
                           >> turnos[numSolicitudes]->nombreEspecialidad
                           >> turnos[numSolicitudes]->dia
                           >> turnos[numSolicitudes]->turno) {
        numTurnos++;
    }
}

void LeeSolicitudes(ifstream archivoSolicitudes, SolicitudTurno* solicitudes[], int &numSolicitudes) {
    if (!archivoSolicitudes.is_open()) {
        cout << "Error al abrir el archivo SolicitudTurnos.Txt" << endl;
        return;
    }

    numSolicitudes = 0;
    while (archivoSolicitudes >> solicitudes[numSolicitudes]->apellidoNombre
                               >> solicitudes[numSolicitudes]->edad
                               >> solicitudes[numSolicitudes]->obraSocial
                               >> solicitudes[numSolicitudes]->nroMatricula
                               >> solicitudes[numSolicitudes]->nombreEspecialidad
                               >> solicitudes[numSolicitudes]->dia
                               >> solicitudes[numSolicitudes]->turno) {
        numSolicitudes++;
    }
}

void ProcMedicos(){}

void ProcEspecialidad(){}

void ProcTurnos(){}

void ProcSolicitudes(){}

int main() {
    //Declarar las variables utilizadas.
    Especialidad* especialidades[20];
    Medico* medicos[100];
    vector<Turno*> turnos;
    vector<SolicitudTurno*> solicitudes;

    int numEspecialidades = 0;
    int numMedicos = 0;
    int numTurnos = 0;

    //Abrir todos los archivos.
    ifstream archivoMedicos("Archivos/Medicos.Txt");
    ifstream archivoEspecialidades("Archivos/Especialidades.Txt");
    ifstream archivoTurnos("Archivos/TurnosDiaHora.Txt");



    ProcMedicos(archivoMedicos, medicos, numMedicos); // Descarga archivo Medicos.
    ProcEspecialidad(archivoEspecialidades, especialidades, numEspecialidades);  // Descarga archivo Especialidades.
    ProcTurnos(archivoTurnos, turnos, numTurnos);  // Descarga archivo TurnosDiaHora.
    //LstTurnos(        ); // Lista ord. x Especialidades, Días y Turnos del vuelco del archivo TurnosDiasHora.
    ProcSolicitudes(       ); // Descarga archivo SolicitudesTurnos y lista líneas de las solicitudes.
    //LstTurnos(        ); // Lista ord. x Especialidades, Días y Turnos Actualizado con las SolicitudesTurnos.

    //Cerrar todos los archivos
    archivoMedicos.close();
    archivoEspecialidades.close();
    archivoSolicitudes.close();

    return 0;
}
