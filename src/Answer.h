#ifndef ANSWER_H
#define ANSWER_H

#include <QLineEdit>
#include "EventHandler.h"

class Answer : public QLineEdit
{

    public:
        Answer(QWidget* parent) : QLineEdit(parent)
        {

            resize(200,30);
            move(0,50);

            setStyleSheet("padding-left:8px;background-color:#7E628F;color:#F5E4FF;border:2px solid #F5E4FF;border-top:none;");

            EventHandler* eventHandler = new EventHandler(this);
            installEventFilter(eventHandler);
            setFocus();

        }


};

#endif // ANSWER_H
