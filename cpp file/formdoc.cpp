#include "formdoc.h"
#include "ui_formdoc.h"

#include <QVBoxLayout>
#include <QToolBar>


FormDoc::FormDoc(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FormDoc)
{
    ui->setupUi(this);

    QToolBar *loc_tool_bar = new QToolBar("文档", this);
    loc_tool_bar->addAction(ui->actOpen);
    loc_tool_bar->addAction(ui->actFont);
    loc_tool_bar->addSeparator();
    loc_tool_bar->addAction(ui->actCut);
    loc_tool_bar->addAction(ui->actCopy);
    loc_tool_bar->addAction(ui->actPaste);
    loc_tool_bar->addAction(ui->actUndo);
    loc_tool_bar->addAction(ui->actRedo);
    loc_tool_bar->addSeparator();
    loc_tool_bar->addAction(ui->actClose);

    loc_tool_bar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    //
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(loc_tool_bar);
    layout->addWidget(ui->plainTextEdit);
    layout->setContentsMargins(2,2,2,2);
    layout->setSpacing(2);
    setLayout(layout);
}

FormDoc::~FormDoc()
{
    delete ui;
}
