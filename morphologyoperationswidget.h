#ifndef MORPHOLOGYOPERATIONSWIDGET_H
#define MORPHOLOGYOPERATIONSWIDGET_H

#include <QWidget>

namespace Ui {
class MorphologyOperationsWidget;
}

class MorphologyOperationsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MorphologyOperationsWidget(QWidget *parent = 0);
    ~MorphologyOperationsWidget();

private:
    Ui::MorphologyOperationsWidget *ui;
};

#endif // MORPHOLOGYOPERATIONSWIDGET_H
