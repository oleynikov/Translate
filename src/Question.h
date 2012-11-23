#ifndef QUESTION_H
#define QUESTION_H

#include <QLabel>

class Question : public QLabel
{

    public:
        Question(QWidget* parent) : QLabel(parent)
        {

            move(0,0);
            resize(280,50);

            setStyleSheet("background-color:#7E628F;color:#F5E4FF;border:2px solid #F5E4FF;");
            setFrameStyle(1);
            setFrameShape(QFrame::StyledPanel);

            //  Applying fonts
            QFont urlFont("Verdana",24);
            this->setFont(urlFont);

        }

};

#endif // QUESTION_H
