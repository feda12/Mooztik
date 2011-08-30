#ifndef ACTION_H
#define ACTION_H

#include <QAction>

namespace Qopo{
namespace Gui{

class Action : public QAction
{
    Q_OBJECT
public:
    explicit Action(QObject *parent = 0);
    Action(const QString &text, QObject *parent = 0);
    Action(const QIcon &icon, const QString &text = QString(), QObject *parent = 0);

    void setText(const QString &text);
    QString text() const;

    void setSecondStateText(const QString &text);
    QString secondStateText() const;

    void enableSecondState(bool e);
    bool secondStateEnabled() const;

    void setCheckedIcon(const QIcon &icon);
    QIcon checkedIcon() const;

public slots:
    void changeState();

private:
    void setup();

    QIcon m_checkedIcon;
    QString m_secondText;
    bool m_secondStateEnabled;
    bool m_state;
signals:
    void textChanged(const QString &text);
};

} //NAMESPACE Gui
}//NAMESPACE Mooztik
#endif // ACTION_H
