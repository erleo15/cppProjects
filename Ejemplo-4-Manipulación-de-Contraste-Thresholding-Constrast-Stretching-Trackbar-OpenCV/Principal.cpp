
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

int umbral = 0, m = 128, k = 5;
Mat imagenThreshold;
Mat imagen;
Mat imagenContrast;

void functionTrack(int v, void *p){
    cout << "v: " << v << " umbral: " << umbral << endl;

    threshold(imagen, imagenThreshold, umbral, 255, 0);
    imshow("Imagen Threshold", imagenThreshold);
}

int sigmoideo(int v){
    double vd = v;
    double r = 255.0*(1.0/(1.0+exp(-((double)k/100.0)*(vd-((double)m)))));
    //double r = 255.0*((sqrt(6.28)*((double)k)))*exp(-((vd-((double)m))*(vd-((double)m)))/(2.0*((double)k*k)));
    
    int res = r;
    //cout << "res: " << res << " r: " << r << endl;
    return res;
}


void functionTrack2(int v, void *p){
    int pixel = 0;
    int pixelm = 0;
    for (int i=0;i<imagen.rows;i++){
        for(int j=0;j<imagen.cols;j++){
            pixel = imagen.at<uchar>(i,j);
            pixelm = sigmoideo(pixel);
            imagenContrast.at<uchar>(i,j) = pixelm;
        }
    }

    imshow("Imagen CS", imagenContrast);
}



int main(int argc, char *argv[]){
    
    imagen = imread("./catedral-san-basilio.jpg", IMREAD_GRAYSCALE);
    resize(imagen, imagen, Size(),0.5, 0.5);
    
    namedWindow("Imagen", WINDOW_AUTOSIZE);
    namedWindow("Imagen Threshold", WINDOW_AUTOSIZE);
    namedWindow("Imagen CS", WINDOW_AUTOSIZE);
    
    createTrackbar("Threshold","Imagen", &umbral, 255, functionTrack, NULL);
    
    createTrackbar("M","Imagen", &m, 255, functionTrack2, NULL);
    createTrackbar("K","Imagen", &k, 100, functionTrack2, NULL);

    threshold(imagen, imagenThreshold, umbral, 255, 0);
    imagenContrast = Mat::zeros(Size(imagen.cols, imagen.rows), CV_8UC1);
    
    imshow("Imagen", imagen);
    imshow("Imagen Threshold", imagenThreshold);
    imshow("Imagen CS", imagenContrast);

    waitKey(0);
    
    destroyAllWindows();
    
    return 0;
}

