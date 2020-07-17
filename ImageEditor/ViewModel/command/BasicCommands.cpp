#include "../../ViewModel/command/BasicCommands.h"
#include "../ImageViewModel.h"
#include <QString>
ImageCommandOpen::ImageCommandOpen(ImageViewModel* ptr)
 {
     _ImageVM= ptr;
 }
void ImageCommandOpen::SetParameter(std::shared_ptr<Parameters> param)
{
    this->path = static_pointer_cast<pathParameters>(param)->getPath();
}

void ImageCommandOpen::Exec()
{
    _ImageVM->_ImageModel->Open(path);
    //_ImageVM->Fire_OnCommandComplete("Open",true);
}

//-----------------------------
ImageCommandClose::ImageCommandClose(ImageViewModel* ptr)
{
    _ImageVM= ptr;
}

void ImageCommandClose::SetParameter(std::shared_ptr<Parameters> param){}


void ImageCommandClose::Exec()
{
    _ImageVM->_ImageModel->Close();
}


//--------------------------------------
ImageCommandSave::ImageCommandSave(ImageViewModel* ptr)
{
    _ImageVM = ptr;
}

void ImageCommandSave::SetParameter(std::shared_ptr<Parameters> param)
{
    this->path = static_pointer_cast<pathParameters>(param)->getPath();
}

void ImageCommandSave::Exec()
{
    _ImageVM->_ImageModel->Save(path);
}

//--------------------------------------
ImageCommandRotate::ImageCommandRotate(ImageViewModel* ptr)
{
    _ImageVM = ptr;
}

void ImageCommandRotate::SetParameter(std::shared_ptr<Parameters> param)
{
    this->angle = static_pointer_cast<intParameters>(param)->getValue();
}

void ImageCommandRotate::Exec()
{
    _ImageVM->_ImageModel->Rotate(angle);
}
