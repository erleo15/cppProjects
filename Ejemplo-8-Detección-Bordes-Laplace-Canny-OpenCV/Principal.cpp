
#include <iostream>
#include <cstdlib>
#include <ctime>

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
    
    Mat imagen = imread("./Rosa-Bonheur-Lion-in-a-Mountainous-Landscape.jpeg");
    Mat gris;
    Mat bordes;
    Mat grisBlur;
    Mat bordesLaplace;
    Mat bordesCanny;
    
    // Siempre se recomenda aplicar un filtro de suavizado antes de detectar bordes
    cvtColor(imagen, gris, COLOR_BGR2GRAY);
    GaussianBlur(gris, grisBlur, Size(3,3), 2);  
    
    int thresh = 70;
    Canny(grisBlur, bordesCanny, thresh, thresh*3, 3);
    
    Laplacian(grisBlur, bordesLaplace, CV_8UC1, 3);

    
    
    namedWindow("Original", WINDOW_AUTOSIZE);
    namedWindow("Gaussian Blur", WINDOW_AUTOSIZE);
    namedWindow("Gris", WINDOW_AUTOSIZE);
    namedWindow("Bordes Laplace", WINDOW_AUTOSIZE);
    namedWindow("Bordes Canny", WINDOW_AUTOSIZE);

    imshow("Original", imagen);
    imshow("Gaussian Blur", grisBlur);
    imshow("Gris", gris);
    imshow("Bordes Laplace", bordesLaplace);
    imshow("Bordes Canny", bordesCanny);
    

    waitKey(0);
    destroyAllWindows();
   
    
    return 0;
}
