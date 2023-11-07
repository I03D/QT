#include "widget.h"
#include "ui_widget.h"

#include <QPushButton>

#include <QuiLib/include/QuiLib.h>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &Widget::onPushButtonClicked);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onPushButtonClicked()
{
    QuiLib libWidget(this);
    libWidget.exec();
}
