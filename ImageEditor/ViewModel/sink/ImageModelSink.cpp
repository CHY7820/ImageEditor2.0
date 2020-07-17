#include "ImageModelSink.h"
#include "../ImageViewModel.h"

ImageModelSink::ImageModelSink(ImageViewModel *ptr)
{
    _ImageVM = ptr;
}

void ImageModelSink::OnPropertyChanged(const std::string &str){
    _ImageVM->update();
    _ImageVM->Fire_OnPropertyChanged(str);
}
