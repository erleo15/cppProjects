
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
    
    //Mat imagen = imread("radiografia.jpg", IMREAD_GRAYSCALE);
    //Mat imagen = imread("angiografia.jpg", IMREAD_GRAYSCALE);
    Mat imagen = imread("tacs.jpg", IMREAD_GRAYSCALE);    
///////////////////////////////////////////////////////////// mascara 37x37
    Mat imgErosion37;
    Mat imgDilatacion37;
    Mat imgtophat37;
    Mat imgblackhat37;
    Mat operacion37; 
    int escata = 20;
    int escata1 = 40;
    int escata2 = 20;

    Mat elemento = getStructuringElement(MORPH_CROSS, Size(escata, escata)); //MORPH_RECT, MORPH_ELLIPSE
    erode(imagen, imgErosion37, elemento);
    dilate(imagen, imgDilatacion37, elemento);
    morphologyEx(imagen, imgtophat37, MORPH_TOPHAT, elemento);
    morphologyEx(imagen, imgblackhat37, MORPH_BLACKHAT, elemento);
    operacion37=imagen+(imgtophat37-imgblackhat37);  
    namedWindow("Original-20", WINDOW_AUTOSIZE);
    resize(imagen,imagen,Size(imagen.cols/2,imagen.rows/2));
    resize(imgErosion37,imgErosion37,Size(imgErosion37.cols/2,imgErosion37.rows/2));
    resize(imgDilatacion37,imgDilatacion37,Size(imgDilatacion37.cols/2,imgDilatacion37.rows/2));
    resize(imgtophat37,imgtophat37,Size(imgtophat37.cols/2,imgtophat37.rows/2));
    resize(imgblackhat37,imgblackhat37,Size(imgblackhat37.cols/2,imgblackhat37.rows/2));
    resize(operacion37,operacion37,Size(operacion37.cols/2,operacion37.rows/2));
    namedWindow("Erosión-20", WINDOW_AUTOSIZE);
    namedWindow("Dilatación-20", WINDOW_AUTOSIZE);
    namedWindow("Tophat-20", WINDOW_AUTOSIZE);
    namedWindow("BlackHat-20", WINDOW_AUTOSIZE);
    namedWindow("Imagen Original + (Top Hat – Black Hat)-20", WINDOW_AUTOSIZE);
    imshow("Original-20", imagen);
    imshow("Erosión-20", imgErosion37);
    imshow("Dilatación-20", imgDilatacion37);
    imshow("Tophat-20", imgtophat37);
    imshow("BlackHat-20", imgblackhat37);
    imshow("Imagen Original + (Top Hat – Black Hat)-20", operacion37);
    
//////////////////////////////////////////////////////// mascara 50x50
/*
    Mat imgErosion50;
    Mat imgDilatacion50;
    Mat imgtophat50;
    Mat imgblackhat50;
    Mat operacion50; 
    Mat elemento2 = getStructuringElement(MORPH_CROSS, Size(escata1, escata1)); //MORPH_RECT, MORPH_ELLIPSE
    erode(imagen, imgErosion50, elemento2);
    dilate(imagen, imgDilatacion50, elemento2);
    morphologyEx(imagen, imgtophat50, MORPH_TOPHAT, elemento2);
    morphologyEx(imagen, imgblackhat50, MORPH_BLACKHAT, elemento2);
    operacion50=imagen+(imgtophat50-imgblackhat50);  
    namedWindow("Erosión-40", WINDOW_AUTOSIZE);
    namedWindow("Dilatación-40", WINDOW_AUTOSIZE);
    namedWindow("Tophat-40", WINDOW_AUTOSIZE);
    namedWindow("BlackHat-40", WINDOW_AUTOSIZE);
    namedWindow("Imagen Original + (Top Hat – Black Hat)-40", WINDOW_AUTOSIZE);
    imshow("Erosión-40", imgErosion50);
    imshow("Dilatación-40", imgDilatacion50);
    imshow("Tophat-40", imgtophat50);
    imshow("BlackHat-40", imgblackhat50);
    imshow("Imagen Original + (Top Hat – Black Hat)-40", operacion50);



//////////////////////////////////////////////////////// mascara 20x20
    Mat imgErosion20;
    Mat imgDilatacion20;
    Mat imgtophat20;
    Mat imgblackhat20;
    Mat operacion20; 
    Mat elemento3 = getStructuringElement(MORPH_CROSS, Size(escata2, escata2)); //MORPH_RECT, MORPH_ELLIPSE
    erode(imagen, imgErosion20, elemento3);
    dilate(imagen, imgDilatacion20, elemento3);
    morphologyEx(imagen, imgtophat20, MORPH_TOPHAT, elemento3);
    morphologyEx(imagen, imgblackhat20, MORPH_BLACKHAT, elemento3);
    operacion20=imagen+(imgtophat20-imgblackhat20);  
    namedWindow("Erosión-20", WINDOW_AUTOSIZE);
    namedWindow("Dilatación-20", WINDOW_AUTOSIZE);
    namedWindow("Tophat-20", WINDOW_AUTOSIZE);
    namedWindow("BlackHat-20", WINDOW_AUTOSIZE);
    namedWindow("Imagen Original + (Top Hat – Black Hat)-20", WINDOW_AUTOSIZE);
    imshow("Erosión-20", imgErosion20);
    imshow("Dilatación-20", imgDilatacion20);
    imshow("Tophat-20", imgtophat20);
    imshow("BlackHat-20", imgblackhat20);
    imshow("Imagen Original + (Top Hat – Black Hat)-20", operacion20);
   **/
   waitKey(0);
    
    
    return 0;
}