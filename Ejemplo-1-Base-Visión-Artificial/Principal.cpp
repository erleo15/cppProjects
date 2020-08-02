
#include <iostream>
#include <cstdlib>

//#include <opencv2/opencv.hpp>

#include <opencv2/core/core.hpp> // Define los objetos matemáticos que me permiten representar las imágenes
#include <opencv2/highgui/highgui.hpp> // Crear ventanas y manejar la interfaz gráfica de usuario
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/video/video.hpp>
#include <opencv2/videoio/videoio.hpp>

using namespace cv;
using namespace std;

int main(int argc, char *argv[]){
    
    Mat imagen = imread("./catedral-san-basilio.jpg");
    Mat gris;
    
    //En OpenCV las imágenes RGB tienen intercambiado el canal Rojo con el Azul por nomenclatura y aspectos históricos del desarrollo de la herramienta
    cvtColor(imagen,gris,COLOR_BGR2GRAY);
    namedWindow("Imagen", WINDOW_AUTOSIZE);
    namedWindow("Gris", WINDOW_AUTOSIZE);
    
    imshow("Imagen", imagen);
    imshow("Gris", gris);
    
    waitKey(0);
    
    destroyAllWindows();
    
    return 0;
}
