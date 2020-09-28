#include "dcmapp.h"
#include "ui_dcmapp.h"
#include "ui_dcmapp.h"


DCMapp::DCMapp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DCMapp)

{

ui->setupUi(this);
QStringList filter;
QString Path;

#ifdef Q_OS_LINUX
Path = "\usr\bin";
#endif

#ifdef Q_OS_WINDOWS
filter << "*.exe";
Path = "C:\\ProgramData\\chocolatey\\bin";
#endif

QDirIterator it(Path, filter, QDir::AllEntries);
while (it.hasNext()){
     //qDebug() << it.next();
     ui->exes->addItem(QString(it.next()).section("/",-1,-1),it.next());

}
}


void DCMapp::appcall(QString appPath)
{
    QStringList arguments ;
   DCMapp::extractedarguments = new QStringList;
   //   DCMapp::extracteddesc  = new QStringList;

    arguments <<"-h";
    QProcess myProcess;
   if(!QFile::exists(appPath)){
       qDebug() << "print an error";
   };
    myProcess.start(appPath, arguments);

    myProcess.waitForFinished(); // sets current thread to sleep and waits for the Process end
    QString output(myProcess.readAllStandardOutput());
    //qDebug() << output;
    int i = 0;
    while(i < output.size()){
    if((output[i] == "-") && (output[i+1] == "-")){
        QString arg = "";
        while(output[i] != " "){
            arg.append(output[i]);
          i++;

        }
        if(output[i] == " "){
             DCMapp::extractedarguments->append(arg);
        }
    }
    i++;
}

    int j = 0;
   // QWidget * wdg = ui->centralwidget;
//generate GUI
    //Hi Pedro here are some ideas i still think about them
    //array with information
    //"--file" => "required args", "type"
    QVBoxLayout *vlay = new QVBoxLayout;
    //make them global
     DCMapp::Labals = new QLabel[DCMapp::extractedarguments->size()];
     DCMapp::Checkboxs = new QCheckBox[DCMapp::extractedarguments->size()];
     DCMapp::Textboxs = new QLineEdit[DCMapp::extractedarguments->size()];


while(j < DCMapp::extractedarguments->size() ){
    QHBoxLayout *varrg  = new QHBoxLayout();
    vlay->addLayout(varrg);
    DCMapp::Labals[j].setText(DCMapp::extractedarguments->at(j));

    varrg->addWidget(&DCMapp::Labals[j]);
    varrg->addWidget(&DCMapp::Textboxs[j]);
    varrg->addWidget(&DCMapp::Checkboxs [j]);
    j++;
}
QWidget * ArgWdg = new QWidget;
ArgWdg->setLayout(vlay);
ui->argumentArea->setWidget(ArgWdg);
ui->executeButton->setEnabled(true);
ui->GetArg->setEnabled(false);
}


DCMapp::~DCMapp()

{
   // if(myProcess.isOpen()) myProcess.close();
    delete ui;
}

void DCMapp::on_GetArg_clicked()
{
    DCMapp::appcall(ui->exes->itemData(ui->exes->currentIndex()).toString());

}

void DCMapp::on_executeButton_clicked()
{

    //qDebug() << DCMapp::extractedarguments->at(0);

        QStringList checkedarguments;
        QProcess ProcessWithArg;
int j =0;
    while(j < DCMapp::extractedarguments->size() ){
        if(DCMapp::Checkboxs[j].isChecked()){

            checkedarguments.append(Labals[j].text());
            if(Textboxs[j].text() != ""){
                checkedarguments.append(QString(" ") + Textboxs[j].text());
            }
        }
            j++;
        }


    ProcessWithArg.start(ui->exes->itemData(ui->exes->currentIndex()).toString(), checkedarguments);
    ProcessWithArg.waitForFinished(); // sets current thread to sleep and waits for theProcess end
    QString outputwitharg(ProcessWithArg.readAllStandardOutput());
    ui->outputConsole->setPlainText(outputwitharg);
}
