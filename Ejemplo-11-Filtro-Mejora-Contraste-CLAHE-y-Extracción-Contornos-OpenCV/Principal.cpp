
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

Mat canny;
Mat catedralGris;
int _threshold = 243;
int modo = 0;
Mat contornos;
vector<vector<Point> > contornosPuntos;
vector<Vec4i> jerarquia;


void functionTrack(int v, void *p){
    Canny(catedralGris, canny, _threshold, _threshold*2);
    findContours(canny, contornosPuntos, jerarquia, modo, CHAIN_APPROX_SIMPLE);
    contornos = Mat::zeros(Size(catedralGris.cols, catedralGris.rows), CV_8UC3);
    
    for(int i=0;i<contornosPuntos.size();i++)
        drawContours(contornos, contornosPuntos, i, Scalar(1,1,233), 1, LINE_8, jerarquia, 2);
    
    imshow("Canny", canny);
    imshow("Contornos", contornos);
}


int main(int argc, char *argv[]){
    
    Mat catedral = imread("catedral-san-basilio.jpg");
    Mat oscura = imread("imagen_oscura.png", IMREAD_GRAYSCALE);
    Mat catedralLAB;
    Mat catedralCLAHE;    
    Mat oscuraCLAHE;
    
    Mat canalL;
    
    resize(catedral, catedral, Size(), 0.75, 0.75);
    cvtColor(catedral, catedralLAB, COLOR_BGR2Lab);
    
    vector<Mat> canales;
    split(catedralLAB, canales);
    
    Ptr<CLAHE> clahe = createCLAHE();
    clahe->setClipLimit(7);
    clahe->apply(oscura, oscuraCLAHE);
    
    clahe->apply(canales[0], canalL);
    canalL.copyTo(canales[0]);
    
    merge(canales, catedralCLAHE);
    
    cvtColor(catedralCLAHE, catedralCLAHE, COLOR_Lab2BGR);

    namedWindow("Catedral", WINDOW_AUTOSIZE);
    namedWindow("Catedral CLAHE", WINDOW_AUTOSIZE);
    
    namedWindow("Oscura", WINDOW_AUTOSIZE);
    namedWindow("Oscura CLAHE", WINDOW_AUTOSIZE);

    
    imshow("Catedral", catedral);
    imshow("Catedral CLAHE", catedralCLAHE);
    imshow("Oscura", oscura);
    imshow("Oscura CLAHE", oscuraCLAHE);

    
    waitKey(0);
    
    destroyAllWindows();
    
    cvtColor(catedral, catedralGris, COLOR_BGR2GRAY);
    contornos = Mat::zeros(Size(catedralGris.cols, catedralGris.rows), CV_8UC3);

    namedWindow("Gris", WINDOW_AUTOSIZE);
    namedWindow("Canny", WINDOW_AUTOSIZE);
    
    Canny(catedralGris, canny, _threshold, _threshold*3);
    
    createTrackbar("Threshold Canny", "Gris", &_threshold, 255, functionTrack, NULL);
    createTrackbar("Modo Contornos", "Gris", &modo, 3, functionTrack, NULL);
    
    // RETR_TREE
    
    findContours(canny, contornosPuntos, jerarquia, modo, CHAIN_APPROX_SIMPLE);
    
    // Ejemplo 1)acceso manual a los contornos
    /*
    cout << "Total Contornos: " << contornosPuntos.size() << endl;
    for(int i=0;i<contornosPuntos[13].size();i++){
        cout << contornosPuntos[13][i] << endl;
        circle(contornos, contornosPuntos[13][i], 1, Scalar(10, 177, 177), 1);
    }
    */
    
    // Ejemplo 2) mandar a dibujar el contorno que ocupa la posición 27
    drawContours(contornos, contornosPuntos, 27, Scalar(1,1,233), 1, LINE_8, jerarquia, 0);
    
    // Ejemplo 3) mandar a dibujar todos los contornos
    for(int i=0;i<contornosPuntos.size();i++)
        drawContours(contornos, contornosPuntos, i, Scalar(1,1,233), 1, LINE_8, jerarquia, 2);
    
    imshow("Gris", catedralGris);
    imshow("Canny", canny);
    imshow("Contornos", contornos);
    
    waitKey(0);
    
    return 0;
}
