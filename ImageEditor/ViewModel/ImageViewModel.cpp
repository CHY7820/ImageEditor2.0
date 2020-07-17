#include "ImageViewModel.h"
#include "sink/ImageModelSink.h"
#include <iostream>
#include "../Common/utils.h"

using namespace std;

ImageViewModel::ImageViewModel()
{
    _ImageMS = std::make_shared<ImageModelSink>(this);
    image = make_shared<QImage>();
    _Open = std::make_shared<ImageCommandOpen>(this);
    _Close = std::make_shared<ImageCommandClose>(this);
    _Save = std::make_shared<ImageCommandSave>(this);
    _Rotate = std::make_shared<ImageCommandRotate>(this);
    _Gray = std::make_shared<ImageCommandGray>(this);
    _Blur = std::make_shared<ImageCommandBlur>(this);
    _Sharp = std::make_shared<ImageCommandSharp>(this);
}

void ImageViewModel::update()
{
    *image = Mat2QImage(_ImageModel->getImage()->currentImage);
}


void ImageViewModel::SetImageModel(const std::shared_ptr<ImageModel> &_ImageM){
    _ImageModel = _ImageM;
    _ImageModel->AddPropertyNotification(std::static_pointer_cast<IPropertyNotification>(_ImageMS));
}

std::shared_ptr<QImage> ImageViewModel::getImage(){
    return image;
}

std::shared_ptr<ICommandBase> ImageViewModel::getGrayCommand(){
    return std::static_pointer_cast<ICommandBase>(_Gray);
}

std::shared_ptr<ICommandBase> ImageViewModel::getBlurCommand(){
    return std::static_pointer_cast<ICommandBase>(_Blur);
}

std::shared_ptr<ICommandBase> ImageViewModel::getSharpCommand(){
    return std::static_pointer_cast<ICommandBase>(_Sharp);
}

std::shared_ptr<ICommandBase> ImageViewModel::getOpenCommand()
{
    return std::static_pointer_cast<ICommandBase>(_Open);  //上行转换 父类ICommandBase控制
}

std::shared_ptr<ICommandBase> ImageViewModel::getCloseCommand()
{
    return std::static_pointer_cast<ICommandBase>(_Close);
}

std::shared_ptr<ICommandBase> ImageViewModel::getSaveCommand()
{
    return std::static_pointer_cast<ICommandBase>(_Save);
}

std::shared_ptr<ICommandBase> ImageViewModel::getRotateCommand()
{
    return std::static_pointer_cast<ICommandBase>(_Rotate);
}



