#ifndef BTNANSWER_H
#define BTNANSWER_H

#include <QPushButton>
#include "EventHandler.h"


class BtnAnswer : public QPushButton
{

    public:

        BtnAnswer(QWidget* parent) : QPushButton(parent)
        {

            resize(40,30);
            move(240,50);

            setStyleSheet("background-color:#F5E4FF;");

            QPixmap pic(":/icons/question.ico");
            QIcon icon(pic);
            setIcon(icon);

        }

};

#endif // BTNANSWER_H
