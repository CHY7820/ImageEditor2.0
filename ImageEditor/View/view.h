#ifndef VIEW_H
#define VIEW_H
#include "Common/notification.h"
#include <QGraphicsView>
#include "../ViewModel/sink/updatesink.h"

class UpdateSink;
class View : public QGraphicsView
{
    Q_OBJECT
public:
    explicit View(QWidget *parent = nullptr);

    void Open(const QString &fileName);
    void Close();
    void Save();
    void Save(const QString &fileName);
    void Gray();
    void Blur();
    void Sharp();
    void Rotate(int angle);

    //bind functions
    void BindingCommandOpen(const std::shared_ptr<ICommandBase>& ptr);
    void BindingCommandClose(const std::shared_ptr<ICommandBase>& ptr);
    void BindingCommandSave(const std::shared_ptr<ICommandBase>& ptr);
    void BindingCommandSaveAs(const std::shared_ptr<ICommandBase>& ptr);
    void BindingCommandGray(const std::shared_ptr<ICommandBase>& ptr);
    void BindingCommandBlur(const std::shared_ptr<ICommandBase>& ptr);
    void BindingCommandSharp(const std::shared_ptr<ICommandBase>& ptr);
    void BindingCommandRotate(const std::shared_ptr<ICommandBase>& ptr);

    std::shared_ptr<IPropertyNotification> getUpdateSink(void);

    void update();
    void SetImage(std::shared_ptr<QImage> img);

private:

    std::shared_ptr<ICommandBase> _Open;
    std::shared_ptr<ICommandBase> _Close;
    std::shared_ptr<ICommandBase> _Save;
    std::shared_ptr<ICommandBase> _SaveAs;
    std::shared_ptr<ICommandBase> _Rotate;
    std::shared_ptr<ICommandBase> _Gray;
    std::shared_ptr<ICommandBase> _Blur;
    std::shared_ptr<ICommandBase> _Sharp;

    std::shared_ptr<UpdateSink> _UpdateSink;

    QString currentFileName;
    std::shared_ptr<QImage> image;
    //void Set_Image(std::shared_ptr<QImage> img);
};

#endif // VIEW_H
