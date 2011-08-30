#ifndef SEARCHLINEWIDGET_H
#define SEARCHLINEWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QxtLineEdit>
#include <QHBoxLayout>
#include "3rdparty/QSint/actionlabel.h"

namespace Qopo{
namespace Gui{

class SearchLineWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SearchLineWidget(QWidget *parent = 0);

signals:
    void search(const QString&);
    void search();
    void advancedSearch();

private:
    QxtLineEdit *_lineEdit;

protected:
    void paintEvent(QPaintEvent *e);
};

} //Namespace Gui
} //Namespace Qopo

#endif // SEARCHLINEWIDGET_H
