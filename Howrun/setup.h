#ifndef SETUP_H
#define SETUP_H
#include <QString>
#include <QVector>
#include <algorithm>

class Setup
{
private:
    int nNucleos;
    int nPlacas;
    double clockProc;
    double memVideo;
    QString apelido;
    QString estiloJg;


public:
    Setup();
    int getNNucleos() const;
    void setNNucleos(int value);
    int getNPlacas() const;
    void setNPlacas(int value);
    double getClockProc() const;
    bool setClockProc(double value);
    double getMemVideo() const;
    void setMemVideo(double value);
    QString getApelido() const;
    bool setApelido(QString value);
    QString getEstiloJg() const;
    void setEstiloJg(const QString &value);
};

#endif // SETUP_H
