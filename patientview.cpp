#include "patientview.h"
#include "ui_patientview.h"
#include "idatabase.h"

#include <QDebug>

PatientView::PatientView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PatientView)
{
    qDebug()<<"create patientView";
    ui->setupUi(this);

    IDatabase &iDatabase = IDatabase::getInstance();
    if(iDatabase.initPatientModel()){
        ui->tableView->setModel(iDatabase.patientTabModel);
        ui->tableView->setSelectionModel(iDatabase.thePatientSelection);
    }
}

PatientView::~PatientView()
{
    qDebug()<<"create patientView";
    delete ui;
}

void PatientView::on_btAdd_clicked()
{
    int currow = IDatabase::getInstance().addNewPatient();
    emit goPatientEditView(currow);
}


void PatientView::on_btSearch_clicked()
{
    QString filter = QString("name like '%%1%'").arg(ui->txtSearch->text());
    IDatabase::getInstance().searchPatient(filter);
}


void PatientView::on_btDelete_clicked()
{
    IDatabase::getInstance().deleteCurrentPatient();
}


void PatientView::on_btEdit_clicked()
{
    QModelIndex curIndex = IDatabase::getInstance().thePatientSelection->currentIndex();

    emit goPatientEditView(curIndex.row());
}

