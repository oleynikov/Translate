#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <QKeyEvent>

class EventHandler : public QObject
{

    Q_OBJECT

    public:
        EventHandler(QObject* parent) : QObject(parent)
        {

        }

        bool isChaotic;

    protected:
        bool eventFilter(QObject* object, QEvent* event)
        {

            if (event->type() == QEvent::KeyPress)
            {

                QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);

                switch(keyEvent->key())
                {

                    case 16777220:
                        emit(enterPressed());
                        break;

                    case 16777216:
                        emit(escPressed());
                        break;

                    default:
                        return false;
                        break;

                }

            }

            else if (event->type() == QEvent::Resize)
            {

                emit entered();


            }

            // standard event processing
            return false;

        }

    signals:
        void enterPressed();
        void escPressed();
        void entered();

};

#endif // EVENTHANDLER_H
