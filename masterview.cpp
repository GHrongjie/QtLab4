#include "masterview.h"
#include "ui_masterview.h"

#include <QDebug>

MasterView::MasterView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MasterView)
{
    ui->setupUi(this);

    goLoginView();
}

MasterView::~MasterView()
{
    delete ui;
}

void MasterView::goLoginView()
{
    qDebug()<<"goLoginView";
    loginView = new LoginView();

    pushWidgetToStackView(loginView);
}

void MasterView::goWelcomeView()
{
    qDebug()<<"goWelcomeView";
    welcomeView = new WelcomeView();

    pushWidgetToStackView(welcomeView);
}

void MasterView::goDoctorView()
{
    qDebug()<<"goDoctorView";
    doctorView = new DoctorView();

    pushWidgetToStackView(doctorView);
}

void MasterView::goPatientView()
{
    qDebug()<<"goPatientView";
    patientView = new PatientView();

    pushWidgetToStackView(patientView);
}

void MasterView::goDepartmentView()
{
    qDebug()<<"goDepartmentView";
    departmentView = new DepartmentView();

    pushWidgetToStackView(departmentView);
}

void MasterView::goPatientEditView()
{
    qDebug()<<"goPatientEditView";
    patientEditView = new PatientEditView();

    pushWidgetToStackView(patientEditView);
}

void MasterView::goPreviousView()
{

}

void MasterView::pushWidgetToStackView(QWidget *widget)
{
    ui->stackedWidget->addWidget(widget);
    int count = ui->stackedWidget->count();
    ui->stackedWidget->setCurrentIndex(count-1);//总是显示最新加入的view
    ui->labelTitle->setText(loginView->windowTitle());
}
