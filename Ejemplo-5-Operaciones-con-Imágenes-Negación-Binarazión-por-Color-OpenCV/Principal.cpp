
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
    resize(imagen, imagen, Size(),0.5, 0.5);
    Mat gris;
    
    cvtColor(imagen, gris, COLOR_BGR2GRAY);
    
    Mat negativoColor = 255 - imagen;
    Mat negativoGris = 255 - gris;
    
    vector<Mat> canales;
    split(imagen, canales);
    
    canales[0] = 255 - canales[0];
    canales[1] = 255 - canales[1];
    canales[2] = 255 - canales[2];
    Mat nuevaColor;
    
    merge(canales, nuevaColor);
    
    namedWindow("Color", WINDOW_AUTOSIZE);
    namedWindow("Gris", WINDOW_AUTOSIZE);
    namedWindow("Negativo Color", WINDOW_AUTOSIZE);
    namedWindow("Negativo Gris", WINDOW_AUTOSIZE);
    namedWindow("Imagen - Canales", WINDOW_AUTOSIZE);
    namedWindow("Rojo", WINDOW_AUTOSIZE);
    namedWindow("Verde", WINDOW_AUTOSIZE);
    namedWindow("Azul", WINDOW_AUTOSIZE);
    
    //createTrackbar("Threshold","Imagen", &umbral, 255, functionTrack, NULL);
    
    canales[0] = 255 - canales[0];
    canales[1] = 255 - canales[1];
    canales[2] = 255 - canales[2];
    
    imshow("Color", imagen);
    imshow("Gris", gris);
    imshow("Negativo Color", negativoColor);
    imshow("Negativo Gris", negativoGris);
    imshow("Imagen - Canales", nuevaColor);
    imshow("Rojo", canales[2]);
    imshow("Verde", canales[1]);
    imshow("Azul", canales[0]);

    waitKey(0);
    destroyAllWindows();
    
    VideoCapture video("/home/vlarobbyk/Descargas/Car.mkv");
    
    if(video.isOpened()){
        Mat frame;
        Mat frameGris;
        Mat resta;
        Mat siguiente;
        
        namedWindow("Video",WINDOW_AUTOSIZE);
        namedWindow("Resta",WINDOW_AUTOSIZE);
        
        while(3==3){
            video >> frame;
            
            if(!frame.empty()){
                resize(frame, frame, Size(640,480));
                
                cvtColor(frame, frameGris, COLOR_BGR2GRAY);
                
                if(siguiente.empty()){
                    siguiente = frameGris.clone(); // Forma correcta de copiar una imagen 
                                                // siguiente = frameGris; NOOO
                }
                
                resta = abs(siguiente - frameGris);
                siguiente = frameGris.clone();
                //cout << sum(resta) << endl;
                /*
                if(suma(resta)[0]>3){
                    imwrite("foto.png",frame);
                    // Enviar mensaje al chatbot
                }
                */
                
                circle(frame, Point(frame.cols/2,frame.rows/2),37,Scalar(1,1,200),2);
                putText(frame, "Circulo",Point(frame.cols/2,(frame.rows/2)-30),FONT_HERSHEY_SIMPLEX,0.7, Scalar(10,200,177),2);
                imshow("Video", frame);
                imshow("Resta", resta);
                
                if(waitKey(370)==27)
                    break;
            }else
                break;
        }
    }
    
    destroyAllWindows();
    
    return 0;
}
