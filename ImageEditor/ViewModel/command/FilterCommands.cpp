#include "../../ViewModel/command/FilterCommands.h"
#include "../ImageViewModel.h"

ImageCommandGray::ImageCommandGray(ImageViewModel* ptr)
{
    _ImageVM= ptr;
}

void ImageCommandGray::SetParameter(std::shared_ptr<Parameters> param)
{

}

void ImageCommandGray::Exec()
{
    _ImageVM->_ImageModel->Gray();
    //_ImageVM->Fire_OnCommandComplete("GrayCommand", true);
}

void ImageCommandBlur::SetParameter(std::shared_ptr<Parameters> param)
{
    ksize = static_pointer_cast<blurParameters>(param)->ksize;
    anchor = static_pointer_cast<blurParameters>(param)->anchor;
}

ImageCommandBlur::ImageCommandBlur(ImageViewModel* ptr)
{
    _ImageVM= ptr;
}

void ImageCommandBlur::Exec()
{
    _ImageVM->_ImageModel->Blur(ksize,anchor);
    //_ImageVM->Fire_OnCommandComplete("BlurCommand", true);
}

ImageCommandSharp::ImageCommandSharp(ImageViewModel* ptr)
{
    _ImageVM= ptr;
}
void ImageCommandSharp::SetParameter(std::shared_ptr<Parameters> param){

}

void ImageCommandSharp::Exec()
{
    _ImageVM->_ImageModel->Sharp();
    //_ImageVM->Fire_OnCommandComplete("SharpCommand", true);
}


