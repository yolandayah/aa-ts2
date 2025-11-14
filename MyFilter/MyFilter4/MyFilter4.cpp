//  Yolanda Alejo Huerta

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgcodecs.hpp>

#include <iostream>

using namespace cv;
using namespace std;

struct Colorcluster
{
	float R;
	float G;
	float B;
	float mR;
	float mG;
	float mB;
	float t;
};

int N = 10;
ColorCluster Cl[10];

void my_segmentation(Mat& frame, Mat & result)
{
	unsigned char* ptr_in  = frame.ptr();
	unsigned char* ptr_out = result.ptr();

	for (int k = 0; k < N; k++)
	{
		Cl[k].mB = 0;
		Cl[k].mG = 0;
		Cl[k].mR = 0;
		Cl[k].t = 0;
	}

	for (int j = 0; j < frame.rows; j++)
	{
		for (int i = 0; i < frame.cols; i++)
		{
			unsigned char B = ptr_in[j * frame.cols * 3 + i * 3];
			unsigned char G = ptr_in[j * frame.cols * 3 + i * 3 + 1];
			unsigned char R = ptr_in[j * frame.cols * 3 + i * 3 + 2];

			int I = (B + G + R) / 3;

			ptr_out[j * frame.cols * 3 + i*3    ] = I;
			ptr_out[j * frame.cols * 3 + i*3 + 1] = I;
			ptr_out[j * frame.cols * 3 + i*3 + 2] = I;
		}
	}

	// calcular promedios
	for (int k = 0; k < N; k++)
	{
		Cl[k].mB = Cl[k].B / Cl[k].t;
		Cl[k].mG = Cl[k].G / Cl[k].t;
		Cl[k].mR = Cl[k].R / Cl[k].t;
		Cl[k].t = 0;
	}
}

int process(VideoCapture& capture) {

	string window_name_1 = "Salida";
	string window_name_2 = "Camara";

	namedWindow(window_name_1, WINDOW_KEEPRATIO);
	namedWindow(window_name_2, WINDOW_KEEPRATIO);

	Mat frame, result;

	for (;;) {

		// Captur la imagen
		capture >> frame;

		if (frame.empty()) {
			break;
		}

		result = frame.clone();

		my_segmentation(frame, result);

		imshow(window_name_1, frame);
		imshow(window_name_2, result);

		char key = (char)waitKey(30); // Espera 30 milisegundos

		switch (key) {
			case 'q':
			case 'Q':
			case 27:  // Tecla de Esc  (Escape)
				return 0;

			default:
				break;
		}
	}

	return 0;
}

int main()
{
	VideoCapture capture;
	capture.open(0);

	if (!capture.isOpened())
	{
		cerr << "*** Error a la hora de abrir la camara ***" << endl;
		return 1;
	}

	process(capture);

	return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
/*
 * Editor modelines  -  https://www.wireshark.org/tools/modelines.html
 *
 * Local variables:
 * c-basic-offset: 8
 * tab-width: 8
 * indent-tabs-mode: t
 * End:
 *
 * vi: set shiftwidth=8 tabstop=8 noexpandtab:
 * :indentSize=8:tabSize=8:noTabs=false:
 */

