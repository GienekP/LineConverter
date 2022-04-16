/*--------------------------------------------------------------------*/
/* LineConverter v0.5 - (c) GienekP                                   */
/*--------------------------------------------------------------------*/
#include "ataripic.h"
#include "basexex.h"
/*--------------------------------------------------------------------*/
ATARIpic::ATARIpic()
{
    Demo();
}
/*--------------------------------------------------------------------*/
void ATARIpic::Demo()
{
    quint32 x,y;
    for (y=0; y<height; y++)
    {
        for (x=0; x<width; x++)
        {
             quint32 p=width*y+x;
             quint16 a=(16*y/height);
             quint16 b=(16*x/width);
             quint8 c=((a<<4)|b);
             input[p]=apal.getRGB(c);
             g09[p]=input[p];
             pal[p]=input[p];
             output[p]=apal.getBase(c);
             grey[p]=apal.getGray(c);
             green[p]=apal.getGreen(c);
             chroma[p]=apal.getRGB((a<<4)|0x0A);
        };
    };
}
/*--------------------------------------------------------------------*/
quint32 ATARIpic::getPixel(quint16 x, quint16 y, quint8 t)
{
    quint32 ret=5;
    quint32 adr=width*y+x;
    switch (t)
    {
        case 1: {ret=g09[adr];} break;
        case 2: {ret=pal[adr];} break;
        case 3: {ret=output[adr];} break;
        case 4: {ret=grey[adr];} break;
        case 5: {ret=green[adr];} break;
        case 6: {ret=chroma[adr];} break;
        default: {ret=input[adr];} break;
    };
    return ret;
};
/*--------------------------------------------------------------------*/
void ATARIpic::newSaturation(qreal saturation)
{
    qreal s=qreal(saturation)/100;
    apal.setSaturation(s);
}
/*--------------------------------------------------------------------*/
void ATARIpic::newThreshold(qreal threshold)
{
    qreal t=qreal(threshold)/100;
    apal.setThreshold(t);
}
/*--------------------------------------------------------------------*/
void ATARIpic::copy(quint32 *pic)
{
    for (int i=0; i<(ALCWIDTH*ALCHEIGHT); i++)
    {
        input[i]=pic[i];
    };
    letsGo();
}
/*--------------------------------------------------------------------*/
void ATARIpic::letsGo()
{
    unsigned int i,j;
    for (j=0; j<ALCHEIGHT; j++)
    {
        for (i=0; i<GTIAWIDTH; i++)
        {
            unsigned int ia,oa;
            ia=j*ALCWIDTH+(i<<2);
            oa=j*GTIAWIDTH+i;
            quint32 c=apal.average(input[ia],input[ia+1],input[ia+2],input[ia+3]);
            bg09[oa]=c;
            bpal[oa]=apal.nearest(c);
        };
    };
    lineConvert(bpal,lc);
    for (j=0; j<ALCHEIGHT; j++)
    {
        for (i=0; i<ALCWIDTH; i++)
        {
            quint8 c;
            unsigned int inadr,outadr;
            inadr=(j*GTIAWIDTH+(i>>2));
            outadr=(j*ALCWIDTH+i);
            g09[outadr]=bg09[inadr];
            pal[outadr]=apal.getRGB(bpal[inadr]);
            grey[outadr]=apal.getGray(bpal[inadr]);
            green[outadr]=apal.getGreen(bpal[inadr]);
            c=lc[inadr];
            output[outadr]=apal.getBase(c);
            chroma[outadr]=apal.getBase((c&0xF0)|0x08);
        };
    };
}
/*--------------------------------------------------------------------*/
void ATARIpic::reset()
{
    rcount=0;
}
/*--------------------------------------------------------------------*/
char * ATARIpic::rh()
{
    const char h[]="0123456789ABCDEF";
    quint8 d=rp[rcount];
    if (rcount<(RCSIZE-1)) {rcount++;};
    hex[0]='$';
    hex[1]=h[(d>>4)&0x0F];
    hex[2]=h[d&0x0F];
    hex[3]=0;
    return hex;
}
/*--------------------------------------------------------------------*/
quint8 ATARIpic::averageChroma(const quint8 *dta, quint32 s)
{
    quint8 ch[16],max=0,p=0;
    quint32 i;
    for (i=0; i<16; i++) {ch[i]=0;};
    for (i=0; i<s; i++)
    {
        ch[((dta[i]>>4)&0x0F)]++;
    };
    for (i=0; i<16; i++)
    {
        if (ch[i]>max) {max=ch[i];p=i;};
    };
    return (p<<4);
}
/*--------------------------------------------------------------------*/
void ATARIpic::lineConvert(const quint8 *in, quint8 *out)
{
    const quint32 ct[14]={4,16,20,12,12,12,4,11,16,16,12,12,10,3};
    quint32 i,j,k,h=0;
    for (i=0; i<(ALCHEIGHT/2); i++)
    {
        for (j=0; j<14; j++)
        {
            quint32 cyc=ct[j];
            quint8 a=averageChroma(&in[h],cyc);
            for (k=0; k<cyc; k++)
            {
                out[h]=((in[h]&0x0F)|a);
                h++;
            };
            rp[i*14+j]=a;
        };
    };
}
/*--------------------------------------------------------------------*/
void ATARIpic::saveXEX(QDataStream &out)
{
    quint32 i,pos;
    quint8 xex[sizeof(basexex)];
    for (i=0; i<(sizeof(basexex)); i++) {xex[i]=basexex[i];};
    pos=0x0000001C;
    i=0;
    while (i<(GTIAWIDTH*ALCHEIGHT))
    {
        quint8 d=xex[pos];
        if (d==0xFF)
        {
            quint8 y1=(lc[i]&0x0F);
            i++;
            quint8 y2=(lc[i]&0x0F);
            i++;
            quint8 y=(y1<<4)|y2;
            xex[pos]=y;
        };
        pos++;
    };
    pos=0x00002900;
    i=0;
    while ((i<RCSIZE) && (pos<(sizeof(basexex))))
    {
        quint8 d=xex[pos];
        if (d==0xF0)
        {
            quint8 y=(rp[i]&0xF0);
            i++;
            xex[pos]=y;
        };
        pos++;
    };
    for (i=0; i<(sizeof(basexex)); i++) {out << xex[i];};
}
/*--------------------------------------------------------------------*/
void ATARIpic::saveASM(QTextStream &out)
{
    const char h[]="0123456789ABCDEF";
    int i,j;
    out << ";" << endl;
    out << "; LineConverter Gr9" << endl;
    out << "; (c) GienekP" << endl;
    out << ";" << endl;
    out << endl;
    out << "DMACTLS = $022F" << endl;
    out << "DLPTRS  = $0230" << endl;
    out << "GTICTLS = $026F" << endl;
    out << "COLPM0S = $02C0" << endl;
    out << "COLPM1S = $02C1" << endl;
    out << "COLPM2S = $02C2" << endl;
    out << "COLPM3S = $02C3" << endl;
    out << "COLPF0S = $02C4" << endl;
    out << "COLPF1S = $02C5" << endl;
    out << "COLPF2S = $02C6" << endl;
    out << "COLPF3S = $02C7" << endl;
    out << "COLBAKS = $02C8" << endl;
    out << "HPOSP0  = $D000" << endl;
    out << "HPOSP1  = $D001" << endl;
    out << "SIZEP0  = $D008" << endl;
    out << "SIZEP1  = $D009" << endl;
    out << "GRAFP0  = $D00D" << endl;
    out << "GRAFP1  = $D00E" << endl;
    out << "COLBAK  = $D01A" << endl;
    out << "TRIG0   = $D010" << endl;
    out << "TRIG1   = $D011" << endl;
    out << "CONSOL  = $D01F" << endl;
    out << "SKCTL   = $D20F" << endl;
    out << "WSYNC   = $D40A" << endl;
    out << "VCOUNT  = $D40B" << endl;
    out << endl;
    out << ".define poke mva #%%2 %%1" << endl;
    out << endl;
    out << "    org $2000" << endl;
    out << "    run MAIN" << endl;
    out << endl;
    out << "    :16 .byte 0" << endl;
    out << "PICTURE" << endl;
    for (i=0; i<ALCHEIGHT; i++)
    {
        if (i==204) {out << "    :16 .byte 0" << endl;};
        out << "    dta ";
        for (j=0; j<(GTIAWIDTH/2); j++)
        {
            char d[4]="$00";
            quint8 d1=lc[i*GTIAWIDTH+j*2]&0x0F;
            quint8 d2=lc[i*GTIAWIDTH+j*2+1]&0x0F;
            d[1]=h[d1];
            d[2]=h[d2];
            out << d;
            if (j<((GTIAWIDTH/2)-1)) {out << ", ";};
        };
        out << endl;
    };
    out << ".ALIGN $0400" << endl;
    out << "ANT ANTIC_PROGRAM PICTURE,ANT" << endl;
    out << endl;
    out << ".MACRO ANTIC_PROGRAM" << endl;
    out << "    :+204 dta $4F,a(:1+$0000+#*40)" << endl;
    out << "    :+35 dta $4F,a(:1+$1FF0+#*40)" << endl;
    out << "    dta $41,a(:2)" << endl;
    out << "    dta $41,a(:2)" << endl;
    out << ".ENDM" << endl;
    out << endl;
    out << "MAIN"<< endl;
    out << "    poke(DMACTLS,0)" << endl;
    out << "    poke(GTICTLS,$40)" << endl;
    out << "    mva <ANT DLPTRS" << endl;
    out << "    mva >ANT DLPTRS+1" << endl;
    out << "    poke(COLPM0S,$00)" << endl;
    out << "    poke(COLPM1S,$00)" << endl;
    out << "    poke(COLPM2S,$00)" << endl;
    out << "    poke(COLPM3S,$00)" << endl;
    out << "    poke(COLPF0S,$00)" << endl;
    out << "    poke(COLPF1S,$00)" << endl;
    out << "    poke(COLPF2S,$00)" << endl;
    out << "    poke(COLPF3S,$00)" << endl;
    out << "    poke(COLBAKS,$00)" << endl;
    out << "    poke(GRAFP0,$FF)" << endl;
    out << "    poke(GRAFP1,$FF)" << endl;
    out << "    poke(SIZEP0,$03)" << endl;
    out << "    poke(SIZEP1,$03)" << endl;
    out << "    poke(HPOSP0,$10)" << endl;
    out << "    poke(HPOSP1,$D0)" << endl;
    out << "    poke(DMACTLS,$22)" << endl;
    out << "LOOP" << endl;
    out << "    lda VCOUNT" << endl;
    out << "    cmp #$02" << endl;
    out << "    bne LOOP" << endl;
    out << "    lda #$00" << endl;
    out << "    sta COLBAK" << endl;
    out << "    sta WSYNC" << endl;
    out << "    sta WSYNC" << endl;
    out << "    sta WSYNC" << endl;
    out << "    sta WSYNC" << endl;
    out << "    nop" << endl;
    out << "    nop" << endl;
    out << "    nop" << endl;
    out << "    nop" << endl;
    out << "    nop" << endl;
    out << "    nop" << endl;
    out << "    nop" << endl;
    out << "    nop" << endl;
    reset();
    out << "    lda #" << rh() << endl;
    out << "    ldx #" << rh() << endl;
    out << "    ldy #" << rh() << endl;
    out << "    sta COLBAK" << endl;
    out << "    stx COLBAK" << endl;
    out << "    sty COLBAK" << endl;
    out << "    lda #" << rh() << endl;
    out << "    sta COLBAK" << endl;
    out << "    lda #" << rh() << endl;
    out << "    sta COLBAK" << endl;
    out << "    lda #" << rh() << endl;
    out << "    sta COLBAK" << endl;
    out << "    lda #" << rh() << endl;
    out << "    sta COLBAK" << endl;
    out << "    lda #$00;" << endl;
    out << "    sta COLBAK" << endl;
    out << "    nop" << endl;
    out << "    nop" << endl;
    out << "    nop" << endl;
    out << "    nop" << endl;
    out << "    nop" << endl;
    out << "    nop" << endl;
    out << "    nop" << endl;
    out << "    nop" << endl;
    out << "    lda #" << rh() << endl;
    out << "    ldx #" << rh() << endl;
    out << "    ldy #" << rh() << endl;
    out << "    sta COLBAK" << endl;
    out << "    stx COLBAK" << endl;
    out << "    sty COLBAK" << endl;
    out << "    lda #" << rh() << endl;
    out << "    sta COLBAK" << endl;
    out << "    lda #" << rh() << endl;
    out << "    sta COLBAK" << endl;
    out << "    lda #" << rh() << endl;
    out << "    sta COLBAK" << endl;
    out << "    lda #" << rh() << endl;
    out << "    sta COLBAK" << endl;
    out << "    lda #$00" << endl;
    out << "    sta COLBAK" << endl;
    for (i=0; i<119; i++)
    {
        out << "    nop" << endl;
        out << "    nop" << endl;
        out << "    nop" << endl;
        out << "    nop" << endl;
        out << "    nop" << endl;
        out << "    nop" << endl;
        out << "    lda #" << rh() << endl;
        out << "    ldx #" << rh() << endl;
        out << "    ldy #" << rh() << endl;
        out << "    sta COLBAK" << endl;
        out << "    stx COLBAK" << endl;
        out << "    sty COLBAK" << endl;
        out << "    lda #" << rh() << endl;
        out << "    sta COLBAK" << endl;
        out << "    lda #" << rh() << endl;
        out << "    sta COLBAK" << endl;
        out << "    lda #" << rh() << endl;
        out << "    sta COLBAK" << endl;
        out << "    lda #" << rh() << endl;
        out << "    sta COLBAK" << endl;
        out << "    lda #$00;" << endl;
        out << "    sta COLBAK" << endl;
        out << "    nop" << endl;
        out << "    nop" << endl;
        out << "    nop" << endl;
        out << "    nop" << endl;
        out << "    nop" << endl;
        out << "    nop" << endl;
        out << "    nop" << endl;
        out << "    nop" << endl;
        out << "    lda #" << rh() << endl;
        out << "    ldx #" << rh() << endl;
        out << "    ldy #" << rh() << endl;
        out << "    sta COLBAK" << endl;
        out << "    stx COLBAK" << endl;
        out << "    sty COLBAK" << endl;
        out << "    lda #" << rh() << endl;
        out << "    sta COLBAK" << endl;
        out << "    lda #" << rh() << endl;
        out << "    sta COLBAK" << endl;
        out << "    lda #" << rh() << endl;
        out << "    sta COLBAK" << endl;
        out << "    lda #" << rh() << endl;
        out << "    sta COLBAK" << endl;
        out << "    lda #$00" << endl;
        out << "    sta COLBAK" << endl;
    };
    out << "    lda TRIG0" << endl;
    out << "    beq STOP" << endl;
    out << "    lda TRIG1" << endl;
    out << "    beq STOP" << endl;
    out << "    lda CONSOL" << endl;
    out << "    and #1" << endl;
    out << "    beq STOP" << endl;
    out << "    lda SKCTL" << endl;
    out << "    and #$04" << endl;
    out << "    beq STOP" << endl;
    out << "    jmp LOOP" << endl;
    out << "STOP" << endl;
    out << "    rts" << endl;
    out << endl;
}
/*--------------------------------------------------------------------*/
