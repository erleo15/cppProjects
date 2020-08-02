
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
    
    Mat imagen = imread("./san-petesburgo.png");
    Mat imagenT = imread("./imagentriangulo.png");

    Mat resta = abs(imagen-imagenT);
    Mat destino = Mat(Size(imagen.cols, imagen.rows), CV_8UC3, Scalar(255,255,255));
    
    Vec3b pixel;
    Vec3b pixelCopia;
    Vec3b pixelR;
    
    for (int i=0;i<imagen.rows;i++){
        for (int j=0;j<imagen.cols;j++){
            pixel = resta.at<Vec3b>(i,j);

            if(pixel[0]==0 && pixel[1]==0 && pixel[2]==0){
                pixelCopia = imagen.at<Vec3b>(i,j);
                destino.at<Vec3b>(i,j) = pixelCopia;
            }else{
                break;
            }
        }

        for (int j=imagen.cols-1;j>0;j--){
            pixelR = resta.at<Vec3b>(i,j);
            if(pixelR[0]==0 && pixelR[1]==0 && pixelR[2]==0){
                pixelCopia = imagen.at<Vec3b>(i,j);
                destino.at<Vec3b>(i,j) = pixelCopia;
            }else
                break;
        }
        
    }
    
    namedWindow("Original", WINDOW_AUTOSIZE);
    namedWindow("Triangulo", WINDOW_AUTOSIZE);
    namedWindow("Resta", WINDOW_AUTOSIZE);
    namedWindow("Destino", WINDOW_AUTOSIZE);

    imshow("Original", imagen);
    imshow("Triangulo", imagenT);
    imshow("Resta", resta);
    imshow("Destino", destino);
    

    waitKey(0);
    destroyAllWindows();
   
    
    return 0;
}
