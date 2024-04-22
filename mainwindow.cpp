#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVideoWidget>
#include <QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->settingsApplication();

    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
}

//----------------------------------------------------------------------------------

MainWindow::~MainWindow()
{
    delete ui;
}

//----------------------------------------------------------------------------------

void MainWindow::settingsApplication()
{
    this->setWindowTitle("TV REMOTE CONTROL");
    this->setWindowIcon(QIcon(":/icons/icons/remote.png"));

    this->setFixedSize(500, 900);

    ui->info_frame->setMaximumHeight(100);
    ui->video_frame->setMinimumHeight(450);

    ui->power_button->setIcon(QIcon(":/icons/icons/power.png"));
    ui->power_button->setIconSize(ui->power_button->size());
    ui->power_button->setStyleSheet("QPushButton { background-color: #FF6666; }");

    ui->soundOff_button->setIcon(QIcon(":/icons/icons/soundOff.png"));
    ui->soundOff_button->setIconSize(ui->soundOff_button->size());

    ui->forward_button->setIcon(QIcon(":/icons/icons/forward.png"));
    ui->forward_button->setIconSize(ui->forward_button->size());

    ui->back_button->setIcon(QIcon(":/icons/icons/back.png"));
    ui->back_button->setIconSize(ui->back_button->size());

    ui->plus_button->setIcon(QIcon(":/icons/icons/plus.png"));
    ui->plus_button->setIconSize(ui->plus_button->size());

    ui->minus_button->setIcon(QIcon(":/icons/icons/minus.png"));
    ui->minus_button->setIconSize(ui->minus_button->size());

    m_pButtonSound = std::make_unique<QMediaPlayer>();
    m_pButtonSound->setMedia(QUrl("qrc:/sounds/sounds/button.mp3"));
    m_pButtonSound->setVolume(10);

    m_pScreen = std::make_unique<QMediaPlayer>(this);
    QVideoWidget *videoWidget = new QVideoWidget(ui->video_frame);
    ui->video_frame->layout()->addWidget(videoWidget);

    m_pScreen->setVideoOutput(videoWidget);
    ui->video_frame->setStyleSheet("background-color: black");
}

//-------------------------------------------------------------------------------------------

void MainWindow::printInfo()
{
    int channel = m_tvControl.getChannel();

    if(channel != -1)
    {
        ui->channelInfo_label->setText(QString::number(channel));
    }
    else
    {
        ui->channelInfo_label->setText("-");
    }

    int sound = m_tvControl.getSound();

    if(sound != -1)
    {
        ui->soundInfo_label->setText(QString::number(sound));
    }
    else
    {
        ui->soundInfo_label->setText("-");
    }
}

//-------------------------------------------------------------------------------------------

void MainWindow::setupVideo()
{
    int value;
    do{
        value = rand()%5;
    }
    while(value == m_currentVideo);

    m_currentVideo = value;

    QString videoPath;
    switch (value) {
    case 0:
        videoPath = "qrc:/videos/videos/video_0.mp4";
        break;
    case 1:
        videoPath = "qrc:/videos/videos/video_1.mp4";
        break;
    case 2:
        videoPath = "qrc:/videos/videos/video_2.mp4";
        break;
    case 3:
        videoPath = "qrc:/videos/videos/video_3.mp4";
        break;
    default:
        videoPath = "qrc:/videos/videos/video_4.mp4";
        break;
    }
    m_pScreen->setMedia(QUrl(videoPath));
    m_pScreen->setVolume(m_tvControl.getSound());

    m_pScreen->play();
    ui->video_frame->setStyleSheet("");
}

//-------------------------------------------------------------------------------------------

void MainWindow::turnOffTv()
{
    m_pScreen->stop();
    ui->video_frame->setStyleSheet("background-color: black");
}

//-------------------------------------------------------------------------------------------

void MainWindow::setChannel(int channel)
{
    if(channel != -1)
    {
        this->setupVideo();
    }
    else
    {
        this->turnOffTv();
    }
}

void MainWindow::setVolume(int volume)
{
    if(volume != -1)
    {
        m_pScreen->setVolume(volume);
    }
}

//-------------------------------------------------------------------------------------------

void MainWindow::on_power_button_clicked()
{
    m_pButtonSound->play();

    m_tvControl.pushPower();

    this->printInfo();

    this->setChannel(m_tvControl.getChannel());
}

//-------------------------------------------------------------------------------------------

void MainWindow::on_soundOff_button_clicked()
{
    m_pButtonSound->play();

    m_tvControl.pushSoundOff();

    this->printInfo();

    this->setVolume(m_tvControl.getSound());
}

//-------------------------------------------------------------------------------------------

void MainWindow::on_forward_button_clicked()
{
    m_pButtonSound->play();

    m_tvControl.pushForward();

    this->printInfo();

    this->setChannel(m_tvControl.getChannel());
}

//-------------------------------------------------------------------------------------------

void MainWindow::on_back_button_clicked()
{
    m_pButtonSound->play();

    m_tvControl.pushBack();

    this->printInfo();

    this->setChannel(m_tvControl.getChannel());
}

//-------------------------------------------------------------------------------------------

void MainWindow::on_plus_button_clicked()
{
    m_pButtonSound->play();

    m_tvControl.pushPlus();

    this->printInfo();

    this->setVolume(m_tvControl.getSound());
}

//-------------------------------------------------------------------------------------------

void MainWindow::on_minus_button_clicked()
{
    m_pButtonSound->play();

    m_tvControl.pushMinus();

    this->printInfo();

    this->setVolume(m_tvControl.getSound());
}

//-------------------------------------------------------------------------------------------

void MainWindow::on_button_1_clicked()
{
    m_pButtonSound->play();

    m_tvControl.setChannel(1);

    this->printInfo();

    this->setChannel(m_tvControl.getChannel());
}

//-------------------------------------------------------------------------------------------

void MainWindow::on_button_2_clicked()
{
    m_pButtonSound->play();

    m_tvControl.setChannel(2);

    this->printInfo();

    this->setChannel(m_tvControl.getChannel());
}

//-------------------------------------------------------------------------------------------

void MainWindow::on_button_3_clicked()
{
    m_pButtonSound->play();

    m_tvControl.setChannel(3);

    this->printInfo();

    this->setChannel(m_tvControl.getChannel());
}

//-------------------------------------------------------------------------------------------

void MainWindow::on_button_4_clicked()
{
    m_pButtonSound->play();

    m_tvControl.setChannel(4);

    this->printInfo();

    this->setChannel(m_tvControl.getChannel());
}

//-------------------------------------------------------------------------------------------

void MainWindow::on_button_5_clicked()
{
    m_pButtonSound->play();

    m_tvControl.setChannel(5);

    this->printInfo();

    this->setChannel(m_tvControl.getChannel());
}

//-------------------------------------------------------------------------------------------

void MainWindow::on_button_6_clicked()
{
    m_pButtonSound->play();

    m_tvControl.setChannel(6);

    this->printInfo();

    this->setChannel(m_tvControl.getChannel());
}

//-------------------------------------------------------------------------------------------

void MainWindow::on_button_7_clicked()
{
    m_pButtonSound->play();

    m_tvControl.setChannel(7);

    this->printInfo();

    this->setChannel(m_tvControl.getChannel());
}

//-------------------------------------------------------------------------------------------

void MainWindow::on_button_8_clicked()
{
    m_pButtonSound->play();

    m_tvControl.setChannel(8);

    this->printInfo();

    this->setChannel(m_tvControl.getChannel());
}

//-------------------------------------------------------------------------------------------

void MainWindow::on_button_9_clicked()
{
    m_pButtonSound->play();

    m_tvControl.setChannel(9);

    this->printInfo();

    this->setChannel(m_tvControl.getChannel());
}

//-------------------------------------------------------------------------------------------

void MainWindow::on_button_0_clicked()
{
    m_pButtonSound->play();

    m_tvControl.setChannel(0);

    this->printInfo();

    this->setChannel(m_tvControl.getChannel());
}

//-------------------------------------------------------------------------------------------
