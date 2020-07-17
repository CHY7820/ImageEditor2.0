#ifndef BASICCOMMAND_H
#define BASICCOMMAND_H
#include "../../Common/notification.h"

class ImageViewModel;

class ImageCommandOpen :public ICommandBase
{
private:
    ImageViewModel* _ImageVM;
    QString path;
public:
    ImageCommandOpen(ImageViewModel* ptr);
    virtual void SetParameter(std::shared_ptr<Parameters> param);
    virtual void Exec() ;
};

class ImageCommandClose :public ICommandBase
{
private:
    ImageViewModel* _ImageVM;
public:
    ImageCommandClose(ImageViewModel* ptr);
    virtual void SetParameter(std::shared_ptr<Parameters> param);
    virtual void Exec() override;
};

class ImageCommandSave:public ICommandBase
{
private:
    ImageViewModel* _ImageVM;
    QString path;
public:
    ImageCommandSave(ImageViewModel* ptr);
    virtual void SetParameter(std::shared_ptr<Parameters> param) override;
    virtual void Exec() override;
};

class ImageCommandRotate:public ICommandBase
{
private:
    ImageViewModel* _ImageVM;
    int angle;
public:
    ImageCommandRotate(ImageViewModel* ptr);
    virtual void SetParameter(std::shared_ptr<Parameters> param) override;
    virtual void Exec() override;
};

#endif // BASICCOMMAND_H
