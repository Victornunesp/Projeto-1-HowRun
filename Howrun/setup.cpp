#include "setup.h"

int Setup::getNNucleos() const
{
    return nNucleos;
}

void Setup::setNNucleos(int value)
{
    nNucleos = value;
}

int Setup::getNPlacas() const
{
    return nPlacas;
}

void Setup::setNPlacas(int value)
{
    nPlacas = value;
}

double Setup::getClockProc() const
{
    return clockProc;
}

bool Setup::setClockProc(double value)
{
    if(value <= 0) return true;
    clockProc = value;
    return false;
}

double Setup::getMemVideo() const
{
    return memVideo;
}

void Setup::setMemVideo(double value)
{
    memVideo = value;
}

QString Setup::getApelido() const
{
    return apelido;
}

bool Setup::setApelido(QString value)
{
    if(value.size() < 3){
        return true;
    }
    apelido = value;
    return false;
}

QString Setup::getEstiloJg() const
{
    return estiloJg;
}

void Setup::setEstiloJg(const QString &value)
{
    estiloJg = value;
}

Setup::Setup()
{
    memVideo = 0;
    clockProc = 0;
    nNucleos = 0;
    nPlacas = 0;
}
