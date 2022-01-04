/*--------------------------------------------------------------------*/
/* LineConverter v0.5 - (c) GienekP                                   */
/*--------------------------------------------------------------------*/
#ifndef ATARIPALGEN_H
#define ATARIPALGEN_H
/*--------------------------------------------------------------------*/
#include <QColor>
#include <QtMath>
/*--------------------------------------------------------------------*/
class ATARIpalGen
{
private:
    qreal saturation=0.5;
    qreal threshold=0.1;
    quint32 bsrgb[256];
    quint32 atrgb[256];
    int square(int x);
    qreal square(qreal x);
    void rebuild();
    quint32 calc(quint8 c);
public:
    ATARIpalGen();
    void setSaturation(qreal sat);
    void setThreshold(qreal th);
    quint32 getBase(quint8 c);
    quint32 getRGB(quint8 c);
    quint32 getGray(quint8 c);
    quint32 getGreen(quint8 c);
    quint8 nearest(quint32 c);
    quint32 average(quint32 a,quint32 b,quint32 c,quint32 d);
};
/*--------------------------------------------------------------------*/
#endif // ATARIPALGEN_H
/*--------------------------------------------------------------------*/
