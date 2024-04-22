#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <memory>

#include <tvcontrol.h>

const int64_t AMOUNT_OF_VIDEOS = 5;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_power_button_clicked();
    void on_soundOff_button_clicked();
    void on_forward_button_clicked();
    void on_back_button_clicked();
    void on_plus_button_clicked();
    void on_minus_button_clicked();
    void on_button_1_clicked();
    void on_button_2_clicked();
    void on_button_3_clicked();
    void on_button_4_clicked();
    void on_button_5_clicked();
    void on_button_6_clicked();
    void on_button_7_clicked();
    void on_button_8_clicked();
    void on_button_9_clicked();
    void on_button_0_clicked();

private:
    Ui::MainWindow *ui;

    std::unique_ptr<QMediaPlayer> m_pButtonSound;
    std::unique_ptr<QMediaPlayer> m_pScreen;
    tvControl m_tvControl;
    int64_t m_currentVideo = 0;

    void settingsApplication();
    void printInfo();
    void setupVideo();
    void turnOffTv();
    void setChannel(int channel);
    void setVolume(int volume);
};
#endif // MAINWINDOW_H
