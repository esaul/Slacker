#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStandardPaths>
#include <QWebPage>
#include <QtCore>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString path(QStandardPaths::writableLocation(QStandardPaths::CacheLocation));
    qDebug() << "Cache path" << path;

    ui->webView->page()->settings()->enablePersistentStorage(path);
    ui->webView->settings()->setThirdPartyCookiePolicy(
                QWebSettings::ThirdPartyCookiePolicy::AlwaysAllowThirdPartyCookies);

    QIcon smallIcon(QPixmap(QString::fromUtf8("://images/png/icon32.png")));
    QIcon bigIcon(QPixmap(QString::fromUtf8("://images/png/Slack.png")));

    trayIcon = new QSystemTrayIcon(smallIcon, this);
    trayIcon->show();
    setWindowIcon(bigIcon);
    setWindowTitle(QString::fromUtf8("Slack"));

    connect(ui->webView->page(), SIGNAL(featurePermissionRequested(QWebFrame*,QWebPage::Feature)),
            this, SLOT(featureRequest(QWebFrame*,QWebPage::Feature)));
    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason )),
            this, SLOT(trayActivated(QSystemTrayIcon::ActivationReason)));

    button = new QWinTaskbarButton(this);
    button->setWindow(this->windowHandle());
    button->setOverlayIcon(QIcon("://images/png/Slack.png"));

    progress = button->progress();
    progress->setVisible(true);
    progress->setValue(100);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete trayIcon;
    delete progress;
    delete button;
}

void MainWindow::featureRequest(QWebFrame *frame, QWebPage::Feature feature)
{
    qDebug() << feature << QWebPage::Feature::Notifications;
    if (feature == QWebPage::Feature::Notifications)
    {
        ui->webView->page()->setFeaturePermission(frame, feature,
                                                  QWebPage::PermissionPolicy::PermissionGrantedByUser);
    }
}

void MainWindow::trayActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason)
    {
        case QSystemTrayIcon::Trigger:
        {
            if(isHidden())
                show();
            else
                hide();
            break;
        }
        default: break;
    }
}

void MainWindow::hide(){
    QMainWindow::hide();
    progress->setValue(0);
}

void MainWindow::show(){
    QMainWindow::show();
    progress->setValue(100);
}