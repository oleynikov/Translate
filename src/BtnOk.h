#ifndef BTNOK_H
#define BTNOK_H

#include <QPushButton>
#include <QIcon>
#include <QPixmap>
#include "EventHandler.h"

#include <QDir>
class BtnOk : public QPushButton
{

    public:

        BtnOk(QWidget* parent) : QPushButton(parent)
        {

            resize(40,30);
            move(200,50);

            setStyleSheet("background-color:#F5E4FF;");

            QPixmap pic(":/icons/check.ico");
            QIcon icon(pic);
            setIcon(icon);

        }

};

#endif // BTNOK_H
