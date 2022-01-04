/*--------------------------------------------------------------------*/
/* LineConverter v0.5 - (c) GienekP                                   */
/*--------------------------------------------------------------------*/
#ifndef ATARIPIC_H
#define ATARIPIC_H
/*--------------------------------------------------------------------*/
#include <QTextStream>
#include <QDataStream>
/*--------------------------------------------------------------------*/
#include "ataripalgen.h"
/*--------------------------------------------------------------------*/
#define ALCWIDTH 320
#define ALCHEIGHT 240
#define GTIAWIDTH 80
#define RCSIZE (120*14)
/*--------------------------------------------------------------------*/
class ATARIpic
{
private:
    ATARIpalGen apal;
    quint32 input[ALCWIDTH*ALCHEIGHT];
    quint32 pal[ALCWIDTH*ALCHEIGHT];
    quint32 g09[ALCWIDTH*ALCHEIGHT];
    quint32 output[ALCWIDTH*ALCHEIGHT];
    quint32 grey[ALCWIDTH*ALCHEIGHT];
    quint32 green[ALCWIDTH*ALCHEIGHT];
    quint32 chroma[ALCWIDTH*ALCHEIGHT];
    quint32 bg09[GTIAWIDTH*ALCHEIGHT];
    quint8 bpal[GTIAWIDTH*ALCHEIGHT];
    quint8 lc[GTIAWIDTH*ALCHEIGHT];
    quint8 rp[RCSIZE];
    char hex[4];
    quint32 rcount;
    void lineConvert(const quint8 *in, quint8 *out);
    void reset();
    char *rh();
    quint8 averageChroma(const quint8 *dta, quint32 s);
public:
    const quint16 width=ALCWIDTH;
    const quint16 height=ALCHEIGHT;
    const quint16 gtia=GTIAWIDTH;
    ATARIpic();
    void Demo();
    void copy(quint32 *pic);
    void letsGo();
    quint32 getPixel(quint16 x, quint16 y, quint8 t=0);
    void newSaturation(qreal saturation);
    void newThreshold(qreal threshold);
    void saveASM(QTextStream &out);
    void saveXEX(QDataStream &out);
};
/*--------------------------------------------------------------------*/
#endif // ATARIPIC_H
/*--------------------------------------------------------------------*/
