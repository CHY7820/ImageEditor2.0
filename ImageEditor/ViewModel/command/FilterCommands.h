#ifndef FILTERCOMMANDS_H
#define FILTERCOMMANDS_H
#include "../../Common/notification.h"

class ImageViewModel;

class ImageCommandGray :public ICommandBase
{
private:
    ImageViewModel* _ImageVM;
public:
    ImageCommandGray(ImageViewModel* ptr);
    virtual void SetParameter(std::shared_ptr<Parameters> param);
    virtual void Exec() ;
};

class ImageCommandBlur :public ICommandBase
{
private:
    ImageViewModel* _ImageVM;
    int ksize,anchor;

public:
    ImageCommandBlur(ImageViewModel* ptr);
    virtual void SetParameter(std::shared_ptr<Parameters> param);
    virtual void Exec() ;
};

class ImageCommandSharp :public ICommandBase
{
private:
    ImageViewModel* _ImageVM;
public:
    ImageCommandSharp(ImageViewModel* ptr);
    virtual void SetParameter(std::shared_ptr<Parameters> param);
    virtual void Exec() ;
};


#endif // FILTERCOMMANDS_H
