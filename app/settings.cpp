#include "settings.h"

Settings::Settings()
{
    _headerGradient.setColorAt(0, QColor(50, 50, 50));
    _headerGradient.setColorAt(1, QColor(30, 30, 30));
}

QLinearGradient Settings::headerGradient()
{
    return _headerGradient;
}
