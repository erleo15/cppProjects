
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

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
    
    Mat imagen = imread("original.png", IMREAD_GRAYSCALE);
    Mat catedral = imread("Gris.pgm", IMREAD_GRAYSCALE);
    Mat catedralErosion;
    
    Mat imgErosion;
    Mat imgDilatacion;
    Mat imgClosing;
    
    Mat imgClosingEspecial;
    
    Mat elemento = getStructuringElement(MORPH_CROSS, Size(3, 3)); //MORPH_RECT, MORPH_ELLIPSE
    
    erode(imagen, imgErosion, elemento);
    dilate(imagen, imgDilatacion, elemento);
    
    // dst=closeEspeciañ(src,element)=erode(dilate(dilate(src,element)))
    dilate(imagen, imgClosingEspecial, elemento);
    dilate(imgClosingEspecial, imgClosingEspecial, elemento);
    erode(imgClosingEspecial, imgClosingEspecial, elemento);
    
    erode(catedral, catedralErosion, elemento);
    
    morphologyEx(imagen, imgClosing, MORPH_CLOSE, elemento); // MORPH_OPEN, MORPH_GRADIENT, MORPH_BLACKHAT, MORPH_TOPHAT
    
    namedWindow("Original", WINDOW_AUTOSIZE);
    namedWindow("Erosión", WINDOW_AUTOSIZE);
    namedWindow("Dilatación", WINDOW_AUTOSIZE);
    namedWindow("Closing", WINDOW_AUTOSIZE);
    namedWindow("Closing Especial", WINDOW_AUTOSIZE);
    namedWindow("Catedral", WINDOW_AUTOSIZE);
    namedWindow("Catedral Erosion", WINDOW_AUTOSIZE);
    
    imshow("Original", imagen);
    imshow("Erosión", imgErosion);
    imshow("Dilatación", imgDilatacion);
    imshow("Closing", imgClosing);
    imshow("Closing Especial", imgClosingEspecial);
    imshow("Catedral", catedral);
    imshow("Catedral Erosion", catedralErosion);
    
    waitKey(0);
    
    
    return 0;
}
