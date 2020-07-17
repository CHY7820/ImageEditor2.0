#ifndef IMAGEMODEL_H
#define IMAGEMODEL_H
#include "../Common/image.h"
#include "../Common/notification.h"
#include <memory>

class ImageModel: public Proxy_PropertyNotification<ImageModel>, public Proxy_CommandNotification<ImageModel>
{
public:
    ImageModel();
    bool is_Gray;
    ~ImageModel(){}
    std::shared_ptr<Image> getImage();

    void Open(const QString& str);
    void Close();
    void Save(const QString& path);

    void Rotate(int);
    void Gray();
    void Blur(int,int);
    void Sharp();
private:
    std::shared_ptr<Image> _Image;
};
#endif // IMAGEMODEL_H
