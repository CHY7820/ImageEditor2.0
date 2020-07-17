#ifndef IMAGE_H
#define IMAGE_H

#include <QStack>
#include <QMessageBox>
#include <QFileDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QStack>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

class Image
{
public:
    QString filename;
    int initwidth;
    int initheight;
    Mat originImage;
    Mat currentImage;
    Image(){};
    
};

#endif // IMAGE_H
