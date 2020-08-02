
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
#include <opencv2/xfeatures2d/nonfree.hpp>
#include <opencv2/objdetect/objdetect.hpp>

using namespace cv;
using namespace std;

CascadeClassifier face_classifier;
CascadeClassifier eye_classifier;
Mat frame;


void detectar(Mat grisE){
    vector<Rect> rostros;
    face_classifier.detectMultiScale(grisE, rostros);
    
    cout << "Rostros Detectados: " << rostros.size() << endl;
    
    for(int i=0;i<rostros.size();i++){
        Point centro(rostros[i].x+rostros[i].width/2,rostros[i].y+rostros[i].height/2);
        ellipse(frame,centro,Size(rostros[i].width/2,rostros[i].height/2),0,0,360,Scalar(233,10,10),4);
        
        vector<Rect> ojos;
        // Permite crear una sub-imagen a partir del rectángulo que se pasa como parámetro
        Mat rostro = grisE(rostros[i]);
        eye_classifier.detectMultiScale(rostro, ojos);
        
        for(int j=0;j<ojos.size();j++){
            Point centroOjo(rostros[i].x+ojos[j].x+ojos[j].width/2,rostros[i].y+ojos[j].y+ojos[j].height/2);
            ellipse(frame,centroOjo,Size(ojos[j].width/2,ojos[j].height/2),0,0,360,Scalar(10,233,233),5);
        }
    }
    imshow("Captura", frame);
}


int main(int argc, char *argv[]){
    
    if(!face_classifier.load("/home/vlarobbyk/aplicaciones/Librerias/opencv-4.0.0/opencv4-installation/share/opencv4/haarcascades/haarcascade_frontalface_default.xml")){
        cout << "No puede cargar fichero Haar Faces" << endl;
        return -1;
    }
    
    if(!eye_classifier.load("/home/vlarobbyk/aplicaciones/Librerias/opencv-4.0.0/opencv4-installation/share/opencv4/haarcascades/haarcascade_eye.xml")){
        cout << "No puede cargar fichero Haar Eyes" << endl;
        return -1;
    }
    
    Mat imagen = imread("imagen.jpg");
    Mat imgGris;
    
    cvtColor(imagen, imgGris, COLOR_BGR2GRAY);
    equalizeHist(imgGris, imgGris);
    
    vector<Rect> rostros;
    face_classifier.detectMultiScale(imgGris,rostros);
    
    for(int i=0;i<rostros.size();i++){
        Point centro(rostros[i].x+rostros[i].width/2,rostros[i].y+rostros[i].height/2);
        ellipse(imagen,centro,Size(rostros[i].width/2,rostros[i].height/2),0,0,360,Scalar(233,10,10),4);
    }
    
    imshow("Imagen", imagen);
    
    VideoCapture video("/dev/video0");
    
    if(video.isOpened()){
        
        Mat gris;
        Mat grisEcualizada;
        
        namedWindow("Captura", WINDOW_AUTOSIZE);
        namedWindow("Gris", WINDOW_AUTOSIZE);
        namedWindow("Gris Ecualizada", WINDOW_AUTOSIZE);
        
        while(3==3){
            video >> frame;
            flip(frame, frame, 1);
            cvtColor(frame, gris, COLOR_BGR2GRAY);
            equalizeHist(gris, grisEcualizada);
            
            detectar(grisEcualizada);
            
            imshow("Gris", gris);
            imshow("Gris Ecualizada", grisEcualizada);
            
            if(waitKey(23)==27)
                break;
        }

    }    
    destroyAllWindows();
    
    return 0;
}
