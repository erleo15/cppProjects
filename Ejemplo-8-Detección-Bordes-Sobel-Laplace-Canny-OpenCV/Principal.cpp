
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
    
    resize(imagen, imagen, Size(), 0.75, 0.75);
    
    Mat gris;
    Mat bordes;
    Mat grisBlur;
    Mat bordesLaplace;
    Mat bordesCanny;
    
    Mat sobelHorizontal;
    Mat sobelVertical;
    
    Mat sobelCombinado;
    
    // Siempre se recomenda aplicar un filtro de suavizado antes de detectar bordes
    cvtColor(imagen, gris, COLOR_BGR2GRAY);
    GaussianBlur(gris, grisBlur, Size(3,3), 2);  
    
    int thresh = 70;
    Canny(grisBlur, bordesCanny, thresh, thresh*3, 3);
    
    Laplacian(grisBlur, bordesLaplace, CV_8UC1, 3);

    Sobel(grisBlur, sobelHorizontal, CV_8UC1, 1, 0, 3);
    Sobel(grisBlur, sobelVertical, CV_8UC1, 0, 1, 3);
    
    addWeighted(sobelHorizontal, 0.5, sobelVertical, 0.5, 0, sobelCombinado);
    
    namedWindow("Original", WINDOW_AUTOSIZE);
    namedWindow("Gaussian Blur", WINDOW_AUTOSIZE);
    namedWindow("Gris", WINDOW_AUTOSIZE);
    namedWindow("Bordes Laplace", WINDOW_AUTOSIZE);
    namedWindow("Bordes Canny", WINDOW_AUTOSIZE);
    
    namedWindow("Sobel X", WINDOW_AUTOSIZE);
    namedWindow("Sobel Y", WINDOW_AUTOSIZE);
    namedWindow("Sobel Combinado", WINDOW_AUTOSIZE);

    imshow("Original", imagen);
    imshow("Gaussian Blur", grisBlur);
    imshow("Gris", gris);
    imshow("Bordes Laplace", bordesLaplace);
    imshow("Bordes Canny", bordesCanny);
    
    imshow("Sobel X", sobelHorizontal);
    imshow("Sobel Y", sobelVertical);
    imshow("Sobel Combinado", sobelCombinado);

    waitKey(0);
    destroyAllWindows();
    
    VideoCapture video("/home/vlarobbyk/Descargas/Car.mkv");
    
    if(video.isOpened()){
        Mat frame;
        namedWindow("Original", WINDOW_AUTOSIZE);
        namedWindow("Canny", WINDOW_AUTOSIZE);
        
        while(3==3){
            video >> frame;
            resize(frame, frame, Size(640, 480));
            cvtColor(frame, gris, COLOR_BGR2GRAY);
            GaussianBlur(gris, grisBlur, Size(3,3), 2);  
            Canny(grisBlur, bordesCanny, thresh, thresh*3, 3);
            
            imshow("Original", frame);
            imshow("Canny", bordesCanny);
            
            if(waitKey(23)==27)
                break;
        }
    }

   destroyAllWindows();
    
    return 0;
}
