
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
    
    // Cómo crear una imagen vacía (con valores en negro)
    Mat grisManual = Mat::zeros(Size(imagen.cols, imagen.rows), CV_8UC1);
    
    cout << "Características de la imagen: Ancho=" << imagen.cols << " Alto=" << imagen.rows << " Canales=" << imagen.channels() << endl;
    
    cout << grisManual.cols << "|" << grisManual.rows << endl;
    
    //En OpenCV las imágenes RGB tienen intercambiado el canal Rojo con el Azul por nomenclatura y aspectos históricos del desarrollo de la herramienta
    
    // La fórmula ideal indica lo siguiente para convertir de color a escala de grises:
    // gris = 0.3*R + 0.59*G + 0.11*B
    cvtColor(imagen,gris,COLOR_BGR2GRAY);

    // Cómo obtener un pixel de una imagen gris:
    // se debe indicar la fila y la columna, y usar el método genérico .at<tipo_dato>
    int valor = gris.at<uchar>(100, 200); // tomo el pixel de la fila 100 y columna 200
    cout << "Pixel(fila = 100, columna = 200) = " << valor << endl;

    // Cómo obtener un pixel de una imagen a color:
    Vec3b pixel = imagen.at<Vec3b>(100, 200);
    cout << "Pixel(fila = 100, columan = 200) = [Azul=" << ((int)pixel[0]) <<", Verde=" << ((int)pixel[1]) <<", Rojo=" << ((int)pixel[2]) << "]" << endl;
    
    // Conversión Manual de una imagen a color en gris:
    int promedio = 0;
    for(int i=0;i<imagen.rows;i++){
        for(int j=0;j<imagen.cols;j++){
            pixel = imagen.at<Vec3b>(i,j);
            //cout << (int)((((int)pixel[0])+((int)pixel[1])+((int)pixel[2]))/3) << endl;
            promedio = (int)((((int)pixel[0])+((int)pixel[1])+((int)pixel[2]))/3);
            
            grisManual.at<uchar>(i,j) = promedio;
        }
    }

    namedWindow("Imagen", WINDOW_AUTOSIZE);
    namedWindow("Gris-OpenCV", WINDOW_AUTOSIZE);
    namedWindow("Gris-Promedio", WINDOW_AUTOSIZE);
    
    imshow("Imagen", imagen);
    imshow("Gris-OpenCV", gris);
    imshow("Gris-Promedio", grisManual);
    
    waitKey(0);
    
    Mat frame;
    VideoCapture video(0);
    if(video.isOpened()){
        namedWindow("Video", WINDOW_AUTOSIZE);
        while(3==3){
            video >> frame;
            imshow("Video",frame);
            
            if(waitKey(23)==27)
                break;
        }
    }
    
    
    destroyAllWindows();
    
    return 0;
}
