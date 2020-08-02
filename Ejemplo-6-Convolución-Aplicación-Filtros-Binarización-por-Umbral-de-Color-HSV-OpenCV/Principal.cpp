
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
Mat frameHSV, binarizada;

int hmin = 0, hmax = 180, smin = 0, smax = 255, vmin = 0, vmax = 255;

void functionTrack(int v, void *p){

    inRange(frameHSV, Scalar(hmin,smin,vmin), Scalar(hmax,smax,vmax), binarizada);
    imshow("Binarizada", binarizada);    
}

int main(int argc, char *argv[]){
    
    Mat imagen = imread("./catedral-san-basilio.jpg");
    resize(imagen, imagen, Size(),0.5, 0.5);
    Mat gris;
    
    cvtColor(imagen, gris, COLOR_BGR2GRAY);

    double porcentaje = 0.2;
    
    int total = ((int) (porcentaje * gris.rows * gris.cols));
    int px = 0, py = 0;
    cout << "Total: " << total << endl;
    
    Mat copiaRuido = gris.clone();
    Mat copiaFiltro;
    
    srand(time(nullptr));
    
    while(total>0){
        px = (rand() % gris.cols);
        py = (rand() % gris.rows);
        
        copiaRuido.at<uchar>(py,px) = 255;
        total--;
    }
    
    medianBlur(copiaRuido, copiaFiltro, 3);
    //medianBlur(copiaFiltro, copiaFiltro, 1);

    namedWindow("Original", WINDOW_AUTOSIZE);
    namedWindow("Ruido - Sal", WINDOW_AUTOSIZE);
    namedWindow("Filtro Mediana", WINDOW_AUTOSIZE);
    
    imshow("Original", gris);
    imshow("Ruido - Sal", copiaRuido);
    imshow("Filtro Mediana", copiaFiltro);

    waitKey(0);
    destroyAllWindows();
    
    
    VideoCapture video("/home/vlarobbyk/Descargas/Car.mkv");
    
    if(video.isOpened()){
        Mat frame;

        namedWindow("Video",WINDOW_AUTOSIZE);
        namedWindow("HSV",WINDOW_AUTOSIZE);
        namedWindow("Binarizada",WINDOW_AUTOSIZE);
        createTrackbar("H-Min","Video", &hmin, 180, functionTrack, NULL);
        createTrackbar("S-Min","Video", &smin, 255, functionTrack, NULL);
        createTrackbar("V-Min","Video", &vmin, 255, functionTrack, NULL);
        
        createTrackbar("H-Max","Video", &hmax, 180, functionTrack, NULL);
        createTrackbar("S-Max","Video", &smax, 255, functionTrack, NULL);
        createTrackbar("V-Max","Video", &vmax, 255, functionTrack, NULL);
        
        
        while(3==3){
            video >> frame;
            
            if(!frame.empty()){
                resize(frame, frame, Size(640,480));
                cvtColor(frame, frameHSV, COLOR_BGR2HSV);
                
                inRange(frameHSV, Scalar(hmin,smin,vmin), Scalar(hmax,smax,vmax), binarizada);
                
                imshow("Video", frame);
                imshow("HSV", frameHSV);
                imshow("Binarizada", binarizada);
                
                if(waitKey(170)==27)
                    break;
            }else
                break;
        }
    }
    
    destroyAllWindows();
    
    
    return 0;
}
