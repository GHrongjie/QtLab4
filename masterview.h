#ifndef MASTERVIEW_H
#define MASTERVIEW_H

#include <QMainWindow>
#include "loginview.h"
#include "welcomeview.h"
#include "doctorview.h"
#include "departmentview.h"
#include "patientview.h"
#include "patienteditview.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MasterView;
}
QT_END_NAMESPACE

class MasterView : public QMainWindow
{
    Q_OBJECT

public:
    MasterView(QWidget *parent = nullptr);
    ~MasterView();

public slots:
    void goLoginView();
    void goWelcomeView();
    void goDoctorView();
    void goPatientView();
    void goDepartmentView();
    void goPatientEditView();
    void goPreviousView();

private:
    void pushWidgetToStackView(QWidget *widget);

    Ui::MasterView *ui;

    WelcomeView *welcomeView;
    DoctorView *doctorView;
    PatientView *patientView;
    DepartmentView *departmentView;
    LoginView *loginView;
    PatientEditView *patientEditView;
};
#endif // MASTERVIEW_H
