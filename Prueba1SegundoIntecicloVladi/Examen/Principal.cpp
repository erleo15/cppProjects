
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
#include <vector>
#include <string>


using namespace cv;
using namespace std;


int main(int argc, char *argv[]){
    cout << "Prueba - Hernan Jacinto Leon Loja" << endl;
    
/*
    for (int i =0; i < imagen.rows ; i++){
        for(int j=0; j<imagen.cols;j++){
            nPixelesTotales++;
        }
    }
    int tot=0;
    for (int i=0;i<imagen.rows;i++){
        for (int j=0;j<imagen.cols;j++){
            pixel = resta.at<Vec3b>(i,j);
            if(pixel[0]==0 && pixel[1]==0 && pixel[2]==0){
                pixelCopia = imagen.at<Vec3b>(i,j);
                destino.at<Vec3b>(i,j) = pixelCopia;
                nPixelesIzquierda++;
            }else{
                tot ++;
                break; 
            }
        } 
        for (int j=imagen.cols-1;j>0;j--){
            pixelR = resta.at<Vec3b>(i,j);
            if(pixelR[0]==0 && pixelR[1]==0 && pixelR[2]==0){
                pixelCopia = imagen.at<Vec3b>(i,j);
                destino.at<Vec3b>(i,j) = pixelCopia;
                nPixelesDerecha++;
            }else{
                tot++;
                break;
            } 
        }
        
    }
    
    
    nPixelesCirculo = abs(nPixelesIzquierda - nPixelesDerecha);
    nPixelesFuera = nPixelesTotales - nPixelesCirculo;
    cout << "Numero Pixeles: " << nPixelesTotales<<endl;
    cout << "Numero Pixeles Izquierda: " << nPixelesIzquierda <<endl;
    cout << "Numero Pixeles Derecha: " << nPixelesDerecha <<endl;
    cout << "Filas: " << imagen.rows << endl;
    cout << "Columnas: " << imagen.cols << endl;
    cout << "Numero Pixeles Circulo: " << nPixelesCirculo <<endl;
    cout << "Numero de Pixeles de Circunferencia: " << tot << endl; 
    cout << "Numero Pixeles Fuera del circulo: " << nPixelesFuera <<endl;   
*/



    cout << "PROMEDIO" << endl; 
    
    // Conversión Manual de una imagen a color en gris:
    string path = "/home/erleo15/Descargas/IMAGENES-2/computación/";
    string nombre = "";
    std::vector<std::string> datos;
   // Mat imagenT = imread("./imagen-test.png"); //imagen con el circulo
    string rutas_imagenes[20] = {"img_0.png","img_1.png","img_2.png","img_3.png","img_4.png","img_5.png","img_6.png","img_7.png","img_8.png","img_9.png","img_10.png","img_11.png",
"img_12.png",
"img_13.png",
"img_14.png",
"img_15.png",
"img_16.png",
"img_17.png",
"img_18.png",
"img_19.png"
};

 /*

    for (int i =0; i < 19;i++){
       // cout << path+rutas_imagenes[i] << endl;
        Mat imagen = imread(path+rutas_imagenes[i], IMREAD_GRAYSCALE);
        Mat imagensize ;
        resize(imagen,imagensize,Size(200,200));
        Mat resta ;
        int suma =0;
        for (int j = 0 ;j < 19; j++){
            Mat imagen2 = imread(path+rutas_imagenes[j], IMREAD_GRAYSCALE); 
            Mat imagen2size;
            resize(imagen2,imagen2size,Size(200,200));
            resta = imagensize - imagen2size;
            
            for(int k=0;k<resta.cols;k++){
                for(int l=0;l<resta.rows;l++){
                    Vec3b pixel = resta.at<Vec3b>(k,l);
                    suma += (int)pixel[0];
                    //cout << (int)pixel[0] << endl;
                }
            }
            
            cout << rutas_imagenes[i]+" ; "+rutas_imagenes[j] + " suma: "<< suma << endl;
            datos.push_back(rutas_imagenes[i]+";"+rutas_imagenes[j]);
            suma =0;
                    
        } 
        
       
    }*/


    Mat imagen = imread(path+rutas_imagenes[0]); 
        Mat imagensize ;
        resize(imagen,imagensize,Size(200,200));
        Mat gris(imagensize.size(),CV_8UC1);
        cvtColor(imagensize,gris,COLOR_BGR2GRAY); 
        Mat resta ;
        int suma =0;
        
            Mat imagen2 = imread(path+rutas_imagenes[0]); 
            Mat imagen2size;
            resize(imagen2,imagen2size,Size(200,200));
            resta = gris - gris; 
            for(int k=0;k<resta.cols;k++){
                for(int l=0;l<resta.rows;l++){
                    Vec3b pixel = resta.at<Vec3b>(k,l);
                    int valor = pixel[0];
                    suma += valor;
                }
            }
            
            cout << rutas_imagenes[0]+" ; "+rutas_imagenes[0] + " suma: "<< suma << endl;
            datos.push_back(rutas_imagenes[0]+";"+rutas_imagenes[0]);
            suma =0;
    
    /*namedWindow("Original", WINDOW_AUTOSIZE);
     namedWindow("Original2", WINDOW_AUTOSIZE);
    namedWindow("Resta", WINDOW_AUTOSIZE); 
    
    //imshow("Original", gris);
    imshow("Original2", imagen2size);
    imshow("Resta", resta); */
    waitKey(0);
    destroyAllWindows();
   
    
    return 0;
}
