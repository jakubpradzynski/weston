#ifndef TEXTURINGWIDGET_H
#define TEXTURINGWIDGET_H

#include <QWidget>

namespace Ui {
class TexturingWidget;
}

class TexturingWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TexturingWidget(QWidget *parent = 0);
    ~TexturingWidget();

private:
    Ui::TexturingWidget *ui;
};

#endif // TEXTURINGWIDGET_H
