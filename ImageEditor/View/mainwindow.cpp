#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _MainWindowSink = std::make_shared<mainwindowsink>(this);
    DisableOp();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::EnableOp()
{
    ui->menuBasic->setEnabled(true);
    ui->menuFilter->setEnabled(true);
    ui->actionClose->setEnabled(true);
    ui->actionSave->setEnabled(true);
    ui->actionSave_As->setEnabled(true);
}
void MainWindow::DisableOp()
{
    ui->menuBasic->setEnabled(false);
    ui->menuFilter->setEnabled(false);
    ui->actionClose->setEnabled(false);
    ui->actionSave->setEnabled(false);
    ui->actionSave_As->setEnabled(false);
}

View* MainWindow::GetCurrentView() const
{
    return ui->view;
}

std::shared_ptr<ICommandNotification> MainWindow::getMainSink(void){
    return std::static_pointer_cast<ICommandNotification>(_MainWindowSink);
}

void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("open Image"),".",tr("Image File(*.png *.jpg *JPG *jpeg *.bmp)"));
    if(filename.isEmpty())
        return;
    GetCurrentView()->Open(filename);
    EnableOp();
    qDebug()<<"open image";
}

//TO DO tab: check tab number
void MainWindow::on_actionClose_triggered()
{
    GetCurrentView()->Close();
    DisableOp();
}

void MainWindow::on_actionSave_triggered()
{
    if (QMessageBox::question(this, tr("Question"), tr("Save File?")))
        GetCurrentView()->Save();
}

void MainWindow::on_actionSave_As_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("open Image"),".",tr("Image File(*.png *.jpg *JPG *jpeg *.bmp)"));
    if(filename.isEmpty())
        return;
    GetCurrentView()->Save(filename);
}

void MainWindow::on_actionGray_triggered()
{
    GetCurrentView()->Gray();
}

void MainWindow::on_actionBlur_triggered()
{
    GetCurrentView()->Blur();
}

void MainWindow::on_actionSharp_triggered()
{
    GetCurrentView()->Sharp();
}

void MainWindow::on_actionRotate_90_triggered()
{
    GetCurrentView()->Rotate(90);
}

void MainWindow::on_actionRotate_270_triggered()
{
    GetCurrentView()->Rotate(-90);
}

void MainWindow::on_actionRotate_180_triggered()
{
    GetCurrentView()->Rotate(180);
}


