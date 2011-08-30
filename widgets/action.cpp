#include "action.h"

namespace Qopo{
namespace Gui{

Action::Action(QObject *parent) :
    QAction(parent)
{
    setup();
}

Action::Action(const QString &text, QObject *parent): QAction(text, parent)
{
    setup();
}

Action::Action(const QIcon &icon, const QString &text, QObject *parent): QAction(icon, text, parent)
{
    setup();
}

void Action::setup()
{
    m_state = false;
    m_secondStateEnabled = false;
    QObject::connect(this, SIGNAL(triggered()), this, SLOT(changeState()));
}

void Action::setText(const QString &text)
{
    emit textChanged(text);
    QAction::setText(text);
}

QString Action::text() const
{
    if(m_secondStateEnabled && m_state)
    {
        return m_secondText;
    }
    return QAction::text();
}

void Action::setCheckedIcon(const QIcon &icon)
{
    m_checkedIcon = icon;
}

QIcon Action::checkedIcon() const
{
    return m_checkedIcon;
}

void Action::setSecondStateText(const QString &text)
{
    m_secondText = text;
}

QString Action::secondStateText() const
{
    return m_secondText;
}

void Action::enableSecondState(bool e)
{
    m_secondStateEnabled = e;
}

bool Action::secondStateEnabled() const
{
    return m_secondStateEnabled;
}

void Action::changeState()
{
    if(m_secondStateEnabled)
        m_state = !m_state;
}

} // NAMESPACE Gui
} //NAMESPACE Mooztik
