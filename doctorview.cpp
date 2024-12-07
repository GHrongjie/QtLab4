#include "doctorview.h"
#include "ui_doctorview.h"

#include <QDebug>

DoctorView::DoctorView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DoctorView)
{
    qDebug()<<"create doctorView";
    ui->setupUi(this);
}

DoctorView::~DoctorView()
{
    qDebug()<<"delete doctorView";
    delete ui;
}
