#ifndef SETTINGS_H
#define SETTINGS_H

#include <QPainter>
#include <QLinearGradient>
#include "singleton.h"

class Settings: public Singleton<Settings>
{
    friend class Singleton<Settings>;
private:
    Settings();
public:
    QLinearGradient headerGradient();
private:
    QLinearGradient _headerGradient;
};

#endif // SETTINGS_H
