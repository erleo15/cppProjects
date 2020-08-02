#include <opencv2/highgui/highgui.hpp> //maneja interfaz grafica del usuario
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/video/video.hpp>
#include <opencv2/videoio/videoio.hpp>

using namespace cv;
using namespace std;

int main(int argc, char *argv[]){
    Mat imagen = imread("./foto.jpg");
    Mat gris;

    cvtColor(imagen,gris,COLOR_BGR2GRAY);

    namedWindow("Imagen",WINDOW_AUTOSIZE);
    imshow("Imagen",imagen);

    namedWindow("Gris",WINDOW_AUTOSIZE);
    imshow("Gris",gris);

    waitKey(0);
    destroyAllWindows();
    return 0;
}





