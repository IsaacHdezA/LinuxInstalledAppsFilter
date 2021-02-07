// Programa para separar las cosas que tengo instaladas en esta computadora.
#include <iostream>
#include <cstdio>
#include <cstring>

void limpiarArchivo( FILE *, const char * );
int contarRenglones( FILE * );

using namespace std;

int main( void ) {
	
	// Descomentar si se quiere introducir nombre manualmente.
	// char archivoOld[100];
	// char archivoNew[100];
	// 
	// // Abrimos los archivos de instalaciones originales.
	// cout << "Nombre del archivo de instalaciones antiguo: ";	cin.get( archivoOld, 100 );
	// FILE *instalacionesOld = fopen( archivoOld, "r" );		cin.ignore();

	// cout << "Nombre del archivo de instalaciones nuevo: ";	cin.get( archivoNew, 100 );
	// FILE *instalacionesNew = fopen( archivoNew, "r" );		cin.ignore();
	
	// Si se hace manual, comentar hasta antes del if.
	const char *archivoOld = "Old/instaladosSnapOld.txt";
	const char *archivoNew = "New/instaladosSnapNew.txt";

	// Abrimos los archivos de instalaciones originales.
	FILE *instalacionesOld = fopen( archivoOld, "r" );
	FILE *instalacionesNew = fopen( archivoNew, "r" );

	if( instalacionesOld && instalacionesNew ) {
		const char *salidaOld = "Old/Clean/instalacionesOldClean.txt";
		const char *salidaNew = "New/Clean/instalacionesNewClean.txt";

		// Creamos nuevos archivos sin información innecesaria (sólo se necesita el nombre).
		limpiarArchivo( instalacionesOld, salidaOld );
		limpiarArchivo( instalacionesNew, salidaNew );

		// Cerramos los archivos originales.
		fclose( instalacionesOld );
		fclose( instalacionesNew );

		// Comparando los archivos con sólo los nombres.
		instalacionesOld = fopen( salidaOld, "r" );
		instalacionesNew = fopen( salidaNew, "r" );

		// Creamos un nuevo archivo con la diferencia.
		const char *salida3 = "instalacionesResume.txt";
		FILE *resume = fopen( salida3, "w" );

		// Contamos los renglones de los archivos y posteriormente los regresamos al inicio.
		int renOld = contarRenglones( instalacionesOld ), renNew = contarRenglones( instalacionesNew );
		rewind( instalacionesOld ); rewind( instalacionesNew );

		// El primer ciclo trabaja con el archivo antiguo, compara cada palabra con cada una del nuevo archivo.
		for( int i = 0; i < renOld; i++ ) {
			int coincidencias = 0;
			char cadArOld[1000], cadArNew[1000];
			fgets( cadArOld, 1000, instalacionesOld );

			// Comparando una palabra del archivo antiguo con cada una del nuevo.
			for( int j = 0; j < renNew; j++ ) {
				fgets( cadArNew, 1000, instalacionesNew );

				if( strcmp( cadArOld, cadArNew ) == 0 ) coincidencias++;
			}

			// Si no aparece en el nuevo, lo incluimos en la lista de cosas no instaladas.
			if( coincidencias == 0 ) fprintf( resume, "%s", cadArOld );

			// Regresamos al inicio del archivo nuevo para comparar la siguiente palabra del antiguo.
			rewind( instalacionesNew );
		}

		// Cerramos todos los archivos.
		fclose( instalacionesOld );
		fclose( instalacionesNew );
		fclose( resume );

	} else cout << "El archivo no se puede abrir o no existe." << endl;

	return 0;
}

void limpiarArchivo( FILE *archivo, const char *output ) {
	FILE *cleanInstal = fopen( output, "w" );
	char lecturaAr[1000];

	while( fgets( lecturaAr, 1000, archivo ) ) {
		char *nuevaCad;
		nuevaCad = strtok( lecturaAr, " \t/\n" );

		// Guardando salida en nuevo archivo.
		fprintf( cleanInstal, "%s\n", nuevaCad );
	}

	fclose( cleanInstal );
}

int contarRenglones( FILE *archivo ) {
	int ren = 0;
	char cad[1000];
	while( fgets( cad, 1000, archivo ) && cad[0] != '\n' ) ren++;

	return ren;
}
