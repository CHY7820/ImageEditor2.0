#ifndef IMAGEVIEWMODEL_H
#define IMAGEVIEWMODEL_H

#include<QImage>
#include "../Model/imagemodel.h"
#include "../Common/notification.h"
#include "../Common/image.h"
#include "sink/ImageModelSink.h"
#include "command/FilterCommands.h"
#include "command/BasicCommands.h"


using namespace std; 

class ImageViewModel:public Proxy_PropertyNotification<ImageViewModel>,
        public Proxy_CommandNotification<ImageViewModel>
{
public:
    ImageViewModel();
    ~ImageViewModel(){}

    void SetImageModel(const std::shared_ptr<ImageModel> &ImageM);

    shared_ptr<QImage> getImage();

    shared_ptr<ICommandBase> getOpenCommand();
    shared_ptr<ICommandBase> getCloseCommand();
    shared_ptr<ICommandBase> getSaveCommand();
    shared_ptr<ICommandBase> getSaveAsCommand();
    shared_ptr<ICommandBase> getGrayCommand();
    shared_ptr<ICommandBase> getBlurCommand();
    shared_ptr<ICommandBase> getSharpCommand();

  //  shared_ptr<ICommandBase> getZoominCommand();
  //  shared_ptr<ICommandBase> getZoomoutCommand();
    shared_ptr<ICommandBase> getRotateCommand();
    shared_ptr<ImageModel> _ImageModel;
    void update();
private:
    shared_ptr<ImageModelSink> _ImageMS;

    std::shared_ptr<QImage> image;

    shared_ptr<ImageCommandGray> _Gray;
    shared_ptr<ImageCommandSharp> _Sharp;
    shared_ptr<ImageCommandBlur> _Blur;
    shared_ptr<ImageCommandOpen> _Open;
    shared_ptr<ImageCommandClose> _Close;
    shared_ptr<ImageCommandSave> _Save;
   // shared_ptr<ImageCommandZoomin> _Zoomin;
  //  shared_ptr<ImageCommandZoomout> _Zoomout;
    shared_ptr<ImageCommandRotate> _Rotate;

};
#endif // IMAGEVIEWMODEL_H
