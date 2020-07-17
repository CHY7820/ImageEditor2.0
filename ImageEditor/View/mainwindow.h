#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QFileDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QStack>
#include <QMessageBox>

#include "Common/notification.h"
#include "Model/imagemodel.h"
#include "mainwindowsink.h"
#include "view.h"
using namespace cv;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class View;

class mainwindowsink;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    View *GetCurrentView() const;

    std::shared_ptr<ICommandNotification> getMainSink(void);

    void EnableOp();
    void DisableOp();

private slots:
    void on_actionOpen_triggered();
    void on_actionClose_triggered();
    void on_actionSave_triggered();
    void on_actionSave_As_triggered();

    //void on_actionCut_triggered();
    void on_actionRotate_90_triggered();
    void on_actionRotate_270_triggered();
    void on_actionRotate_180_triggered();
    //void on_actionZoom_in_triggered();
    //void on_actionZoom_out_triggered();

    void on_actionGray_triggered();
    void on_actionBlur_triggered();
    void on_actionSharp_triggered();

private:
    Ui::MainWindow *ui;
    std::shared_ptr<mainwindowsink> _MainWindowSink;
};
#endif // MAINWINDOW_H
