#include "departmentview.h"
#include "ui_departmentview.h"

#include <QDebug>

DepartmentView::DepartmentView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DepartmentView)
{
    qDebug()<<"create departmentView";
    ui->setupUi(this);
}

DepartmentView::~DepartmentView()
{
    qDebug()<<"delete departmentView";
    delete ui;
}
