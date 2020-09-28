#ifndef DCMAPP_H
#define DCMAPP_H


#include <QMainWindow>
#include  <QObject>
#include <QProcess>
#include <QProcessEnvironment>
#include <qprocess.h>
#include <QDebug>
#include <QDir>
#include  <QLabel>
#include  <QScrollArea>
#include  <QDialog>
#include  <QAction>
#include  <QtPrintSupport/QPrinter>
#include  <QMenuBar>
#include  <QMessageBox>
#include  <QScrollBar>
#include  <QFileDialog>
#include  <QString>
#include  <QDebug>
#include  <QHBoxLayout>
#include  <QLineEdit>
#include  <QCheckBox>
#include  <QScrollArea>
#include   <QComboBox>
#include   <QTableWidget>
#include   <QFile>
#include <QFileOpenEvent>
#include  <QShortcut>
#include <QProgressDialog>
#include  <QMimeDatabase>
#include <QDirIterator>
#include <QVariant>
#include <QClipboard>
#include <QHeaderView>
#include <QDesktopServices>
#include <QStringList>
#include <QTableView>
#include <QTextStream>





class QAction;
class QLabel;
class QMenu;
class QScrollArea;
class QScrollBar;
class QProcess;
class QDir;
class QComboBox;
class QClipboard;



QT_BEGIN_NAMESPACE
namespace Ui { class DCMapp; }
QT_END_NAMESPACE

class DCMapp : public QMainWindow
{
    Q_OBJECT

public:
    DCMapp(QWidget *parent = nullptr);


    void appcall(QString appPath);

    ~DCMapp();

private slots:

    void on_GetArg_clicked();
    void on_executeButton_clicked();


private:




    QProcess myProcess;
    QString   app;
    QString endl;
    QStringList *extractedarguments;
    QStringList *extracteddesc;

    QLabel *Labals;
    QCheckBox *Checkboxs;
    QLineEdit *Textboxs;
    QComboBox *exes;
    QComboBox *textComboBox;
    QComboBox *directoryComboBox;
    QLabel *filesFoundLabel;
    QPushButton *findButton;
    QTableWidget *filesTable;


        QStringList foundFiles;

     QDir currentDir;

    Ui::DCMapp *ui;


    void createActions();

};
#endif // DCMAPP_H
