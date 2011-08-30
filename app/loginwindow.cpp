#include "loginwindow.h"

namespace Mooztik{
namespace Gui {

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setWindowTitle("Login window");

    setMinimumWidth(602);
    m_errors = 0;
    m_errors_limit = 5;


    QFont fontEdit(font());
    fontEdit.setPointSize(font().pointSize()*1.2);

    QRegExp whiteSpace("\\S+");
    QRegExpValidator *whiteSpaceValidator = new QRegExpValidator(whiteSpace, this);
    m_username = new QxtLineEdit(this);
    m_username->setValidator(whiteSpaceValidator);
    m_username->setFixedHeight(30);
    m_username->setFont(fontEdit);
    m_username->setAlignment(Qt::AlignCenter);
    m_username->setSampleText(tr("Nom d'utilisateur"));
    m_username->setAttribute(Qt::WA_MacShowFocusRect, false);

    m_password = new QxtLineEdit(this);
    m_password->setValidator(whiteSpaceValidator);
    m_password->setFixedHeight(30);
    m_password->setFont(fontEdit);
    m_password->setAlignment(Qt::AlignCenter);
    m_password->setSampleText(tr("Mot de passe"));
    m_password->setEchoMode(QLineEdit::Password);
    m_password->setAttribute(Qt::WA_MacShowFocusRect, false);
    m_password->clearFocus();

    QAction *actionConnect = new QAction(tr("Connexion"), this);
    QAction *actionCreateAccount = new QAction(tr("Créer un compte"), this);

    QObject::connect(actionConnect, SIGNAL(triggered()), this, SLOT(connectClicked()));
    QObject::connect(actionCreateAccount, SIGNAL(triggered()), this, SLOT(createAccountClicked()));

    m_connect = new QSint::ActionLabel(actionConnect, this);
    m_createAccount = new QSint::ActionLabel(actionCreateAccount, this);

    const char* ActionLabelStyle =
            "QSint--ActionLabel[class='action'] {"
            "background: white;"
            "border: 1px solid transparent;"
            "color: rgb(162, 173, 182);"
            "text-align: left;"
            " font-family: \"calibri\";"
            "font: 18px;"
            "}"

            "QSint--ActionLabel[class='action']:!enabled {"
            "color: rgb(162, 173, 182);"
            "}"

            "QSint--ActionLabel[class='action']:hover {"
            "color: rgb(100, 100, 100);"
            "text-decoration: none;"
            "}"

            "QSint--ActionLabel[class='action']:on {"
            "color: rgb(95, 113, 127);"
            "}"
            ;

    m_createAccount->setStyleSheet(ActionLabelStyle);
    m_connect->setStyleSheet(ActionLabelStyle);

    /*QLabel *usernameLabel = new QLabel(tr("Utilisateur"), this);
    usernameLabel->setStyleSheet("color:white;");
    QLabel *passwordLabel = new QLabel(tr("Mot de passe"), this);
    passwordLabel->setStyleSheet("color:white;");*/

    QGridLayout *layoutEdit = new QGridLayout;
    layoutEdit->setSpacing(10);
    //layoutEdit->addWidget(usernameLabel, 0, 0);
    layoutEdit->addWidget(m_username, 0, 2);
    //layoutEdit->addWidget(passwordLabel, 1, 0);
    layoutEdit->addWidget(m_password, 1, 2);

    QHBoxLayout *layoutButtons = new QHBoxLayout;
    layoutButtons->setMargin(0);
    layoutButtons->setSpacing(1);
    layoutButtons->addWidget(m_connect);
    layoutButtons->addSpacing(55);
    layoutButtons->addWidget(m_createAccount);

    QVBoxLayout *layoutWidget = new QVBoxLayout;
    layoutWidget->setSpacing(15);
    layoutWidget->setMargin(0);
    layoutWidget->addLayout(layoutEdit);
    layoutWidget->addLayout(layoutButtons);

    m_box_widget = new QWidget(this);
    m_box_widget->setMaximumWidth(310);
    m_box_widget->setMaximumHeight(170);
    m_box_widget->setLayout(layoutWidget);

    QLabel *welcome = new QLabel(this);
    welcome->setStyleSheet("color: rgb(69, 69, 69);font-family: \"lucida\"");
    welcome->setAlignment(Qt::AlignHCenter);
    welcome->setText(tr("<span style=\"font-size:30px\"; font-family: \"lucida\">Mooztic </span>"));

    QFont smallerBoldFont;
    smallerBoldFont.setPointSize(smallerBoldFont.pointSize()*1.5);
    smallerBoldFont.setBold(true);
    welcome->setFont(smallerBoldFont);

    m_announcement = new QLabel(this);
    m_announcement->setStyleSheet("color: rgb(161, 161, 161); font-family: \"lucida\"");
    m_announcement->setAlignment(Qt::AlignHCenter);
    m_announcement->setText(tr("Veuillez vous connectez ou créer un nouveau compte"));
    smallerBoldFont.setPointSize(smallerBoldFont.pointSize()*0.6);
    smallerBoldFont.setBold(true);
    m_announcement->setFont(smallerBoldFont);

    m_error = new QLabel(this);
    QFontMetrics fm(smallerBoldFont);
    m_error->setFixedHeight(fm.height()*2 +4);
    m_error->setAlignment(Qt::AlignHCenter);
    m_error->setStyleSheet("color:red; background: white; font-family: \"lucida\"");
    m_error->setOpenExternalLinks(true);
    m_error->setFont(smallerBoldFont);
    m_error->setText(QString());

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setSpacing(10);
    layout->addWidget(welcome, 0, Qt::AlignTop);
    layout->addWidget(m_announcement, 0, Qt::AlignCenter);
    layout->addStretch(10);
    layout->addWidget(m_box_widget, 0, Qt::AlignCenter);
    layout->addStretch(10);
    layout->addWidget(m_error, Qt::AlignCenter);

    m_widget = new QWidget(this);
    m_widget->setFixedHeight(250);
    m_widget->setFixedWidth(500);
    m_widget->setLayout(layout);

    QVBoxLayout *centralLayoutV = new QVBoxLayout;
    centralLayoutV->addWidget(m_widget, 0, Qt::AlignCenter);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(centralLayoutV);

    this->setCentralWidget(centralWidget);

    clearFocus();
}


QString LoginWindow::password() const
{
    return m_password->text();
}
void LoginWindow::setPassword(const QString &set)
{
    m_password->setText(set);
}

void LoginWindow::setUsername(const QString &set)
{
    m_username->setText(set);
}

QString LoginWindow::username() const
{
    return m_username->text();
}

void LoginWindow::createAccountClicked()
{
    emit createAccount();
}

void LoginWindow::connectClicked()
{
    if(m_username->text().isEmpty())
    {
        error(EMPTY_USERNAME);
        return;
    }
    if(m_password->text().isEmpty())
    {
        error(EMPTY_PASSWORD);
        return;
    }
    emit connect();
}

void LoginWindow::paintEvent(QPaintEvent *event)
{
    QMainWindow::paintEvent(event);

    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing, true);

    p.fillRect(event->rect(), QColor(30, 30, 30));

    QPen pen;
    pen.setWidth(2);
    pen.setColor(QColor(37, 37, 37));
    p.setPen(pen);
    p.translate(event->rect().width()/2-m_widget->rect().width()/2, event->rect().height()/2-m_widget->rect().height()/2);

    qreal leftTopRadius = 10;
    qreal leftBottomRadius = 10;
    qreal rightTopRadius = 10;
    qreal rightBottomRadius = 10;

    QRect roundedRect(0, 0, m_widget->rect().width(), m_widget->rect().height());

    QPainterPath path(QPoint(roundedRect.left(), roundedRect.top() + leftTopRadius));
    path.quadTo(roundedRect.left(), roundedRect.top(), roundedRect.left() + leftTopRadius, roundedRect.top());
    path.lineTo(roundedRect.right() - rightTopRadius, roundedRect.top());
    path.quadTo(roundedRect.right(), roundedRect.top(), roundedRect.right(), roundedRect.top() + rightTopRadius);
    path.lineTo(roundedRect.right(), roundedRect.bottom() - rightBottomRadius);
    path.quadTo(roundedRect.right(), roundedRect.bottom(), roundedRect.right() - rightBottomRadius, roundedRect.bottom());
    path.lineTo(roundedRect.left() + leftBottomRadius, roundedRect.bottom());
    path.quadTo(roundedRect.left(), roundedRect.bottom(), roundedRect.left(), roundedRect.bottom() - leftBottomRadius);
    path.closeSubpath();

    QLinearGradient gradient(QPointF(0, 0), QPointF(0, roundedRect.height()));
    gradient.setColorAt(0, QColor(255, 255, 255));
    gradient.setColorAt(0.5, QColor(245, 245, 245));
    gradient.setColorAt(1, QColor(255, 255, 255));

    p.fillPath(path, QBrush(gradient));
    p.drawRoundedRect(m_widget->rect(), 10, 10);

}

void LoginWindow::error(Error code)
{

    QEventLoop loop;
    QTimer timer;
    QObject::connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));

    switch((int)code)
    {
    case (int)NONE:
        m_error->setText(QString());
        break;
    case (int)EMPTY_USERNAME:
        m_error->setText(tr("Erreur: Entrez un nom d'utilisateur"));
        break;
    case (int)EMPTY_PASSWORD:
        m_error->setText(tr("Erreur: Entrez un mot de passe"));
        break;
    case (int)INVALID_USERNAME_PASSWORD:
        m_error->setText(tr("Erreur: Utilisateur/Mot de passe invalide"));
        break;
    case (int)UNKNOWN_USER:
        m_error->setText(tr("Erreur: utilisateur inconnu"));
        m_errors ++;
        break;
    case (int)DB_CONNECTION_FAILED:
        m_error->setText(tr("Erreur: impossible de vous connecter à votre base de données"));
        break;
    }

    if(m_errors >= m_errors_limit)
        timer.start(1000);
    else
        timer.start(3000);
    loop.exec();

    if(m_errors >= m_errors_limit)
    {
        m_username->setEnabled(false);
        m_password->setEnabled(false);
        m_error->setText(tr("Vous avez atteint vos ")
                         +QString::number(m_errors_limit)+tr(" tentatives autorisées.<br /> Veuillez patienter 45 secondes avant de pouvoir retenter votre chance."));
        timer.start(45000);
        loop.exec();
        m_username->setEnabled(true);
        m_password->setEnabled(true);
    }

    m_error->setText(QString());
}

void LoginWindow::keyReleaseEvent(QKeyEvent *event)
{
    event->ignore();
    if(event->key() == Qt::Key_Return ||  event->key() == Qt::Key_Enter && !m_username->text().isEmpty())
    {
        emit connectClicked();
    }
}

void LoginWindow::setErrorsLimit(int set)
{
    m_errors_limit = set;
}

int LoginWindow::errorsLimit() const
{
    return m_errors_limit;
}

} //Namespace Gui
} //Namespace Mooztik
