//  Yolanda Alejo Huerta

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgcodecs.hpp>

#include <iostream>

using namespace cv;
using namespace std;

void my_segmentation(Mat& frame, Mat & result)
{
	unsigned char* ptr_in  = frame.ptr();
	unsigned char* ptr_out = result.ptr();

	for (int j = 0; j < 100; j++)
	{
		for (int i = 0; i < 100; i++)
		{
			//unsigned char R = ptr_in[j +i];
			ptr_out[j + i] = 0;
		}
	}
}

int process(VideoCapture& capture) {

	string window_name = "Captura de Video";

	namedWindow(window_name, WINDOW_KEEPRATIO);

	Mat frame, result;

	for (;;) {

		// Captur la imagen
		capture >> frame;

		if (frame.empty()) {
			break;
		}

		imshow(window_name, frame);

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

