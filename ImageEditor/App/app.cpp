#include <QApplication>
#include "app.h"
using namespace std;
App::App():_MainWindow(new MainWindow)
{
    //initialize model
    _ImageModel = make_shared<ImageModel>();

    //initialize viewmodel and binding
    _ImageViewModel = make_shared<ImageViewModel>();
}

App::~App()
{
}

void App::run(){

    _ImageViewModel->SetImageModel(_ImageModel);

    auto *view = _MainWindow->GetCurrentView();
    //binding commands in mainwindows
    view->BindingCommandOpen(_ImageViewModel->getOpenCommand());
    view->BindingCommandClose(_ImageViewModel->getCloseCommand());
    view->BindingCommandSave(_ImageViewModel->getSaveCommand());
    view->BindingCommandRotate(_ImageViewModel->getRotateCommand());
    view->BindingCommandGray(_ImageViewModel->getGrayCommand());
    view->BindingCommandBlur(_ImageViewModel->getBlurCommand());
    view->BindingCommandSharp(_ImageViewModel->getSharpCommand());

    view->SetImage(_ImageViewModel->getImage());

    //add notification to viewmodel
    _ImageViewModel->AddCommandNotification(_MainWindow->getMainSink());
    _ImageViewModel->AddPropertyNotification(view->getUpdateSink());


    //show mainwindow
    _MainWindow->show();
}
