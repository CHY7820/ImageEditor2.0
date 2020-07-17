#include "updatesink.h"
#include "../../View/mainwindow.h"

UpdateSink::UpdateSink(View *ptr)
{
    _Update = ptr;
}

 void UpdateSink::OnPropertyChanged(const std::string& str){
    if(str=="ImageModel"){
        _Update->update();
    }

}
