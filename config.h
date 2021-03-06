#ifndef CONFIG_H
#define CONFIG_H

#include <QWidget>
#include <QValidator>
#include <QDir>

namespace Ui {
class Config;
}

class Config : public QWidget
{
    Q_OBJECT

public:
    explicit Config(QWidget *parent = 0);
    ~Config();
    //scanner
    int get_length_SN();
    int get_delay_loop();
    int get_delay_dmtx();
    int get_scanTimout();

    //com
    QString get_COM();
    int get_Baud();
    int get_DataB();
    int get_Parity();
    int get_StopB();
    int get_FlowC();

    //gpio
    int get_delay_gpio();

    //ROI
    QRect get_ROI();

public slots:
    void closeWindow();
    void setConfig(); //寫入檔案
    void saveROI(QRect ROI);

private:
    Ui::Config *ui;
    QDir dir;
    QFile file;
    QValidator *validInt;
    void setUI();
    void getSerialInfo();
    void getConfig(); //讀取檔案
    QRect ROI;  //ROI 統一由這裡記錄著
};

#endif // CONFIG_H
