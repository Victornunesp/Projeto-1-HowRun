#ifndef CADASTRO_H
#define CADASTRO_H
#include "setup.h"
#include <QVector>
class Cadastro
{
private:
    QVector <Setup> cadastros;

public:
    Cadastro();
    void adicionarSetup(Setup a);
    void valordoSetup();
    void size();

};

#endif // CADASTRO_H
