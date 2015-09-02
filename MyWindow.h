/* 
 * File:   MyWindow.h
 * Author: russell
 *
 * Created on 3 September 2015, 12:13 AM
 */

#ifndef _MYWINDOW_H
#define	_MYWINDOW_H

#include "ui_MyWindow.h"

class MyWindow : public QMainWindow {
    Q_OBJECT
public:
    MyWindow();
    virtual ~MyWindow();
private:
    Ui::MyWindow widget;
};

#endif	/* _MYWINDOW_H */
