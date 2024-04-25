#ifndef FORMDOC_H
#define FORMDOC_H

#include <QDialog>

namespace Ui {
class FormDoc;
}

class FormDoc : public QDialog
{
    Q_OBJECT

public:
    explicit FormDoc(QWidget *parent = nullptr);
    ~FormDoc();

private:
    Ui::FormDoc *ui;
};

#endif // FORMDOC_H
