#include "idatabase.h"

#include <QDebug>
#include <QUuid>

void IDatabase::initDatabase()
{
    database = QSqlDatabase::addDatabase("QSQLITE");//设置数据库驱动
    QString aFile = "E:/SQLITEprojects/identifier.sqlite";
    database.setDatabaseName(aFile);//设置数据库名称

    if(!database.open()){
        qDebug()<<"Failed to open database";
    }else{
        qDebug()<<"Open database successfu;" << database.connectionName();
    }
}

bool IDatabase::initPatientModel()
{
    patientTabModel = new QSqlTableModel(this,database);

    patientTabModel->setTable("patient");

    patientTabModel->setEditStrategy(QSqlTableModel::OnManualSubmit);//数据保存方式
    patientTabModel->setSort(patientTabModel->fieldIndex("name"),Qt::AscendingOrder);//排序

    if(!(patientTabModel->select())){
        return false;
    }

    thePatientSelection = new QItemSelectionModel(patientTabModel);
    return true;

}

int IDatabase::addNewPatient()
{
    patientTabModel->insertRow(patientTabModel->rowCount(),QModelIndex());
    QModelIndex curIndex = patientTabModel->index(patientTabModel->rowCount()-1,1);

    int curRecNo = curIndex.row();
    QSqlRecord curRec = patientTabModel->record(curRecNo);
    curRec.setValue("CREATEDTIMESTAMP",QDateTime::currentDateTime().toString("yyyy-MM-dd"));
    curRec.setValue("ID",QUuid::createUuid().toString(QUuid::WithoutBraces));

    patientTabModel->setRecord(curRecNo,curRec);

    return curIndex.row();
}

bool IDatabase::searchPatient(QString filter)
{
    patientTabModel->setFilter(filter);
    return patientTabModel->select();
}

bool IDatabase::deleteCurrentPatient()
{
    QModelIndex curIndex = thePatientSelection->currentIndex();
    patientTabModel->removeRow(curIndex.row());
    patientTabModel->submitAll();
    patientTabModel->select();
}

bool IDatabase::submitPatientEdit()
{
    return patientTabModel->submitAll();
}

void IDatabase::reverPatientEdit()
{
    patientTabModel->revertAll();
}

QString IDatabase::userLogin(QString userName, QString password)
{
    QSqlQuery query;
    query.prepare("select username,password from user where username = :USER");
    query.bindValue(":USER",userName);
    query.exec();

    if(query.first() && query.value("username").isValid()){
        QString passwd = query.value("password").toString();

        if(passwd==password){
            return "loginOK";
        }else{
            qDebug()<<"wrong password";
            return "wrong password";
        }

    }else{
        qDebug()<<"No such user";
         return "loginFailed";
    }
}

IDatabase::IDatabase(QObject *parent)
    : QObject{parent}
{
    initDatabase();
}
