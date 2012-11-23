#ifndef TRANSLATEIT_H
#define TRANSLATEIT_H

#include <QApplication>
#include <QWidget>
#include "Question.h"
#include "Answer.h"
#include "BtnOk.h"
#include "BtnAnswer.h"
#include "EventHandler.h"

#include <QFile>
#include <QTextStream>
#include <QHash>
#include <QTime>
#include <QTimer>
#include <QDir>

#include <iostream>

class TranslateIt : public QWidget
{

    Q_OBJECT

    public:
        TranslateIt(QPoint screenSize)
            : QWidget(NULL,Qt::WindowStaysOnTopHint|Qt::CustomizeWindowHint) , screenSize(screenSize)
        {

            setWindowTitle("Translate");

            if (DictionaryRead())
            {


                //  Applying fonts
                setFixedSize(280,80);
                QFont urlFont("Verdana",14);
                this->setFont(urlFont);

                question = new Question(this);
                answer = new Answer(this);
                btnOk = new BtnOk(this);
                btnAnswer = new BtnAnswer(this);

                eventHandler = new EventHandler(this);
                installEventFilter(eventHandler);

                QObject::connect(btnOk,SIGNAL(clicked()),this,SLOT(answerDone()));
                QObject::connect(btnAnswer,SIGNAL(clicked()),this,SLOT(answerRequested()));
                QObject::connect(eventHandler,SIGNAL(enterPressed()),this,SLOT(answerDone()));
                QObject::connect(eventHandler,SIGNAL(escPressed()),this,SLOT(answerRequested()));
                QObject::connect(eventHandler,SIGNAL(entered()),this,SLOT(entered()));

                QuestionAsk();

            }

        }

    public slots:
        void answerDone()
        {

            if ( answer->text() == answerCurrent )
            {

                answer->setFocus();
                answer->clear();
                QuestionAsk();

            }

            else
            {

                answer->clear();

            }

        }
        void answerRequested()
        {

            answer->setFocus();
            answer->setText(answerCurrent);

        }
        void entered()
        {

            PlaceToCorner();
            activateWindow();
            answer->setFocus();

        }

    private:
        Question* question;
        Answer* answer;
        BtnOk* btnOk;
        BtnAnswer* btnAnswer;
        EventHandler* eventHandler;

        QPoint screenSize;
        QHash<QString,QString> dictionary;
        QString answerCurrent;

        int desktopGap;

        bool DictionaryRead(void)
        {

            QFile dictionaryFile("dictionary");

            //  File opened
            if ( dictionaryFile.open(QIODevice::ReadOnly|QIODevice::Text) )
            {

                QTextStream stream(&dictionaryFile);
                stream.setCodec("UTF-8");

                while ( ! stream.atEnd() )
                {

                    QString dictionaryLine = stream.readLine();
                    QString wordEnglish = dictionaryLine.section('|',0,0);
                    QString wordRussian = dictionaryLine.section('|',1,1);
                    dictionary.insert(wordEnglish,wordRussian);

                }

                return true;

            }

            //  Error while reading the file
            else
            {

                return false;

            }

        }
        void QuestionAsk(void)
        {

            QHash<QString,QString>::iterator iterator = dictionary.begin();
            int dictionarySize = dictionary.size();
            int questionCurrent = GetRandomInt(dictionarySize);
            iterator += questionCurrent;
            question->setText(iterator.key());
            answerCurrent = iterator.value();

        }
        int GetRandomInt (int max)
        {

            QTime time = QTime::currentTime();
            qsrand((uint)time.msec());
            return qrand() % max;

        }
        void PlaceToCorner(void)
        {

            QSize windowSize = frameGeometry().size();
            move(screenSize.x()-this->frameGeometry().width(),0);
            answer->setFocus();

        }
};

#endif // TRANSLATEIT_H
