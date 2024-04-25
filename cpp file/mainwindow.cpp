#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QPainter>
#include "formdoc.h"
#include "formtable.h"


void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.drawPixmap(0, ui->toolBar->height(),
                       width(), height()-ui->toolBar->height()-ui->statusbar->height(),
                       QPixmap(":/images/images/back2.jpg"));
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setCentralWidget(ui->maintabWidget);        //自动居中（布满）
    ui->maintabWidget->setVisible(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}


//
void MainWindow::on_actWidgetInsite_triggered()
{
    FormDoc * my_form_doc = new FormDoc(this);
    my_form_doc->setAttribute(Qt::WA_DeleteOnClose);

    int cur_tab = ui->maintabWidget->addTab(my_form_doc,
                                            QString::asprintf("Doc %d", ui->maintabWidget->count()));
    ui->maintabWidget->setCurrentIndex(cur_tab);
    ui->maintabWidget->setVisible(true);

}


//点击tab的关闭按钮
void MainWindow::on_maintabWidget_tabCloseRequested(int index)
{
    if(ui->maintabWidget->count() == 1)
        ui->maintabWidget->setVisible(false);

    QWidget * tab = ui->maintabWidget->widget(index);
    tab->close();
}


void MainWindow::on_actWidget_triggered()
{
    FormDoc * form_doc = new FormDoc;   //没有父类(this)，则关闭主窗口不会回收子窗口
    form_doc->setAttribute(Qt::WA_DeleteOnClose);

    form_doc->setWindowTitle("子窗口 独立显示");
    form_doc->setWindowOpacity(0.8);
    form_doc->show();
}


//
void MainWindow::on_actWindowInsite_triggered()
{
    FormTable * form_table = new FormTable(this);
    form_table->setAttribute(Qt::WA_DeleteOnClose);

    int index = ui->maintabWidget->addTab(form_table,
                                          QString::asprintf("Table %d", ui->maintabWidget->count()));
    ui->maintabWidget->setCurrentIndex(index);
    ui->maintabWidget->setVisible(true);
}


void MainWindow::on_actWindow_triggered()
{
    FormTable * form_table = new FormTable(this);   //(生命周期管理)
    /* 这里生命周期：form_table依靠的this父类，当this父类删除时，回收form_table
       上面的form_doc没有this父类，mainwindow删除时，form_doc不会被回收
           此时，对于form_table来说，父类还没有彻底删除（form_doc还在显示）,
           当form_doc也删除时，则form_table的this父类窗口都没了，此时释放form_doc
    */
    form_table->setAttribute(Qt::WA_DeleteOnClose);

    form_table->setWindowTitle("子窗口");
    form_table->setWindowOpacity(0.8);
    form_table->show();     //非模态
}





