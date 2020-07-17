#include "view.h"
#include "../Common/Parameter.h"
#include <QObject>

View::View(QWidget *parent):QGraphicsView(parent)
{
    setScene(new QGraphicsScene(this));
    _UpdateSink = std::make_shared<UpdateSink>(this);
}

std::shared_ptr<IPropertyNotification> View::getUpdateSink(void){
    return std::static_pointer_cast<IPropertyNotification>(_UpdateSink);
}

void View::SetImage(std::shared_ptr<QImage> img)
{
        this->image = img;
}

void View::update()
{
    scene()->clear();
    scene()->addPixmap(QPixmap::fromImage(*image));
}

void View::BindingCommandOpen(const std::shared_ptr<ICommandBase>& ptr){
    _Open = ptr;
}

void View::BindingCommandClose(const std::shared_ptr<ICommandBase> &ptr)
{

    _Close = ptr;
}

void View::BindingCommandSave(const std::shared_ptr<ICommandBase> &ptr)
{
    _Save = ptr;
}

void View::BindingCommandSaveAs(const std::shared_ptr<ICommandBase> &ptr)
{
    _SaveAs = ptr;
}

void View::BindingCommandGray(const std::shared_ptr<ICommandBase>& ptr)
{
    _Gray=ptr;
}
void View::BindingCommandBlur(const std::shared_ptr<ICommandBase> &ptr)
{
    _Blur=ptr;
}

void View::BindingCommandSharp(const std::shared_ptr<ICommandBase> &ptr)
{
    _Sharp=ptr;
}

void View::BindingCommandRotate(const std::shared_ptr<ICommandBase> &ptr)
{
    _Rotate = ptr;
}

void View::Open(const QString &fileName)
{
    currentFileName = fileName;
    std::shared_ptr<pathParameters> Param = std::make_shared<pathParameters>(currentFileName);
    _Open->SetParameter(std::static_pointer_cast<Parameters>(Param));
    _Open->Exec();
}

void View::Close()
{
     scene()->clear();
     currentFileName = "";
    _Close->Exec();
}

void View::Save()
{
    Save(currentFileName);
}

void View::Save(const QString &fileName)
{
    std::shared_ptr<pathParameters> Param = std::make_shared<pathParameters>(fileName);
    _Save->SetParameter(std::static_pointer_cast<Parameters>(Param));
    _Save->Exec();
}

void View::Gray()
{
    _Gray->Exec();
}

void View::Blur()
{
    std::shared_ptr<blurParameters> Param = std::make_shared<blurParameters>();
    _Blur->SetParameter(std::static_pointer_cast<Parameters>(Param));
    _Blur->Exec();
}

void View::Sharp()
{
    _Sharp->Exec();
}

void View::Rotate(int angle)
{
    std::shared_ptr<intParameters> Param = std::make_shared<intParameters>(angle);
    _Rotate->SetParameter(std::static_pointer_cast<Parameters>(Param));
    _Rotate->Exec();
}
