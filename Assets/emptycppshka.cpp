#include <cv.h>
#include <highgui.h>
#include <stdlib.h>
#include <stdio.h>

IplImage* frame =0;

int main(int argc, char* argv[])
{
        // имя файла задаётся первым параметром
        char* filename = argc == 2 ? argv[1] : "test.avi";

        printf("[i] file: %s\n", filename);

        // окно для отображения картинки
        cvNamedWindow("original",CV_WINDOW_AUTOSIZE);

        // получаем информацию о видео-файле
        CvCapture* capture = cvCreateFileCapture( filename );

        while(1){
                // получаем следующий кадр
                frame = cvQueryFrame( capture ); 
                if( !frame ) {
                        break;
                }

                // здесь можно вставить
                // процедуру обработки

                // показываем кадр
                cvShowImage( "original", frame );

                char c = cvWaitKey(33);
                if (c == 27) { // если нажата ESC - выходим
                        break;
                }
        }

        // освобождаем ресурсы
        cvReleaseCapture( &capture );
        // удаляем окно
        cvDestroyWindow("original");
        return 0;
}