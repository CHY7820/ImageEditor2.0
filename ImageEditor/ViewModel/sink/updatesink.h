#ifndef UPDATESINK_H
#define UPDATESINK_H


#include "../../Common/notification.h"
#include "../../View/view.h"

class View;
class UpdateSink: public IPropertyNotification
{
public:
    UpdateSink(View *ptr);
    virtual void OnPropertyChanged(const std::string& str);

private:
   View * _Update;
};

#endif // UPDATESINK_H
