#include "imagemodel.h"
#include <QDebug>
ImageModel::ImageModel()
{
    _Image = std::make_shared<Image>();
    is_Gray = false;
}

std::shared_ptr<Image> ImageModel::getImage(){
    return _Image;
}

void ImageModel::Open(const QString& str)
{
    this->_Image->filename = str;
    this->_Image->currentImage = cv::imread(str.toLatin1().data(),IMREAD_COLOR);

    Fire_OnPropertyChanged("ImageModel");
}

void ImageModel::Close()
{
    this->_Image->filename = "";
    //this->is_Gray = false;
    this->_Image->currentImage.~Mat();
    //Fire_OnPropertyChanged("ImageModel");
}

void ImageModel::Save(const QString & path)
{
    imwrite(path.toLatin1().data(),this->_Image->currentImage);
}
void ImageModel::Rotate(int angle)
{
    switch(angle)
    {
    case 90:
        rotate(_Image->currentImage,_Image->currentImage,ROTATE_90_CLOCKWISE);
        break;
    case -90:
        rotate(_Image->currentImage,_Image->currentImage,ROTATE_90_COUNTERCLOCKWISE);
        break;
    case 180:
        rotate(_Image->currentImage,_Image->currentImage,ROTATE_180);
        break;
    default: break;
    }

    Fire_OnPropertyChanged("ImageModel");
}

void ImageModel::Gray(){
    if(_Image!=NULL)
    {
        cvtColor(this->_Image->currentImage,this->_Image->currentImage,COLOR_BGR2GRAY);
        cvtColor(this->_Image->currentImage,this->_Image->currentImage,COLOR_GRAY2BGR);
        qDebug()<<"after gray:"<<this->_Image->currentImage.channels();
        Fire_OnPropertyChanged("ImageModel");
    }
    else
    {
        Fire_OnCommandComplete("Gray",false);
    }

}

void ImageModel::Blur(int ksize,int anchor){
    if(_Image!=NULL)
    {
        blur(this->_Image->currentImage, this->_Image->currentImage, Size(ksize,anchor));
        qDebug()<<"after blur:"<<this->_Image->currentImage.channels();
        Fire_OnPropertyChanged("ImageModel");
    }
    else
    {
        Fire_OnCommandComplete("Blur",false);
    }

}

void ImageModel::Sharp(){
    if(_Image!=NULL)
    {
        Mat sharpkernel = (Mat_<float>(3, 3) <<
                    0, -1, 0,
                    -1,10, -1,
                    0, -1, 0);
        filter2D(this->_Image->currentImage,this->_Image->currentImage, CV_8UC1, sharpkernel);

        qDebug()<<"after sharp:"<<this->_Image->currentImage.channels();


        Fire_OnPropertyChanged("ImageModel");
    }
    else
    {
        Fire_OnCommandComplete("Sharp",false);
    }


}







