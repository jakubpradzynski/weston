#ifndef BLENDMODESWIDGET_H
#define BLENDMODESWIDGET_H

#include <QWidget>

namespace Ui {
class BlendModesWidget;
}

class BlendModesWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BlendModesWidget(QWidget *parent = 0);
    ~BlendModesWidget();

private:
    Ui::BlendModesWidget *ui;
};

#endif // BLENDMODESWIDGET_H
