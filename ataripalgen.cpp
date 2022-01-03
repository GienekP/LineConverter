/*--------------------------------------------------------------------*/
/* LineConverter 0.4 - (c) GienekP                                    */
/*--------------------------------------------------------------------*/
#include "ataripalgen.h"
/*--------------------------------------------------------------------*/
ATARIpalGen::ATARIpalGen()
{
    const quint32 AtariPal[256]={
    0x000000,0x0e0d0e,0x1d1d1d,0x2e2d2e,0x3e3e3e,0x4f4f4f,0x5f5f5f,0x6f6f6f,
    0x7a7a79,0x8b8a8b,0x9b9b9b,0xacacac,0xbcbcbc,0xcdcdcd,0xdcdcdc,0xececec,
    0x350000,0x400500,0x4f1400,0x5f2500,0x6e3400,0x7f4503,0x8e5513,0x9f6623,
    0xa9712d,0xba8240,0xca9250,0xdba361,0xeab270,0xfac382,0xfed291,0xffe3a1,
    0x3f0000,0x4b0000,0x590900,0x691903,0x782912,0x883a23,0x984a34,0xa95b45,
    0xb3654f,0xc47661,0xd48772,0xe59883,0xf4a792,0xfdb8a3,0xffc7b3,0xffd7c2,
    0x3d0000,0x490000,0x57050b,0x68151b,0x77252a,0x88363c,0x98464c,0xa8575d,
    0xb26167,0xc37279,0xd38389,0xe4949a,0xf3a3a9,0xfdb4ba,0xffc4ca,0xffd4d9,
    0x380027,0x420032,0x510140,0x610e50,0x701e5f,0x812f70,0x903f81,0xa05190,
    0xab5b9a,0xbc6cac,0xcc7cbc,0xdc8dcd,0xec9ddc,0xfaaeed,0xfebdfa,0xffcdfe,
    0x2c0046,0x370050,0x46015f,0x550e6e,0x651e7d,0x752f8e,0x853f9f,0x9550ae,
    0xa05bb8,0xb16cca,0xc17cda,0xd28deb,0xe19df8,0xf2aefe,0xfcbdff,0xfecdff,
    0x19005e,0x240067,0x340376,0x441385,0x532294,0x6433a5,0x7443b5,0x8555c4,
    0x8f5fce,0xa070e0,0xb081f0,0xc192fc,0xd0a1fe,0xe1b2ff,0xf0c2ff,0xfcd2ff,
    0x00005c,0x000966,0x091875,0x1a2984,0x293893,0x3a49a4,0x4a59b4,0x5c6ac3,
    0x6674cd,0x7785df,0x8796ef,0x98a7fc,0xa8b6fe,0xb9c7ff,0xc8d6ff,0xd8e7ff,
    0x000b45,0x00164f,0x00255d,0x09366d,0x18457c,0x29568d,0x39669d,0x4b77ac,
    0x5681b6,0x6792c8,0x77a2d9,0x88b3e9,0x98c3f7,0xa9d3fe,0xb8e3ff,0xc8f3ff,
    0x001625,0x002230,0x00313f,0x01424f,0x0c515e,0x1e626f,0x2e7280,0x40828f,
    0x4a8d99,0x5c9dab,0x6caebc,0x7ebecc,0x8dcedb,0x9edeed,0xadeefa,0xbdfcfe,
    0x002400,0x002f00,0x003e0a,0x004f1a,0x085e29,0x186f3b,0x287f4b,0x3a8f5c,
    0x449a65,0x55ab78,0x65bb88,0x77cc99,0x86dba8,0x97ecba,0xa6fac9,0xb7fed9,
    0x002a00,0x003700,0x004600,0x015600,0x0f6500,0x207603,0x318513,0x429624,
    0x4ca12d,0x5db140,0x6dc151,0x7fd262,0x8ee271,0x9ff282,0xaffd92,0xbfffa1,
    0x002400,0x003100,0x054000,0x165000,0x265f00,0x367000,0x478000,0x589008,
    0x629b12,0x73ac24,0x84bc35,0x95cd46,0xa4dc55,0xb5ed67,0xc5fb77,0xd5ff86,
    0x021800,0x0f2500,0x1f3400,0x2f4500,0x3f5400,0x4f6500,0x607500,0x708601,
    0x7b900a,0x8ca11c,0x9cb12c,0xadc23e,0xbdd14d,0xcde25e,0xddf16e,0xedfd7e,
    0x1e0900,0x2a1600,0x392500,0x493600,0x584500,0x695600,0x796600,0x8a7708,
    0x948112,0xa59224,0xb5a335,0xc6b346,0xd6c355,0xe6d466,0xf6e376,0xfef386,
    0x340000,0x400500,0x4f1500,0x5f2500,0x6e3500,0x7f4603,0x8f5613,0x9f6723,
    0xaa712e,0xba8240,0xcb9251,0xdca362,0xebb371,0xfac382,0xfed392,0xffe3a1};
    setSaturation(0.5);
    setThreshold(0.1);
    for (int i=0; i<256; i++) {bsrgb[i]=AtariPal[i];};
}
/*--------------------------------------------------------------------*/
void ATARIpalGen::setSaturation(qreal sat)
{
    saturation=sat;
    rebuild();
}
/*--------------------------------------------------------------------*/
void ATARIpalGen::setThreshold(qreal th)
{
    threshold=th;
    rebuild();
}
/*--------------------------------------------------------------------*/
quint32 ATARIpalGen::getBase(quint8 c)
{
    return bsrgb[c];
}
/*--------------------------------------------------------------------*/
quint32 ATARIpalGen::getGray(quint8 c)
{
    quint32 v=((c & 0x0F)<<4) | (c & 0x0F);
    return ((v<<16) | (v<<8) | v);
}
/*--------------------------------------------------------------------*/
quint32 ATARIpalGen::getGreen(quint8 c)
{
    const quint32 cR=74;
    const quint32 cG=255;
    const quint32 cB=0;
    quint32 r,g,b;
    quint32 v=(c & 0x0F);
    switch (v)
    {
        case 14:
            {r=96; g=cG; b=58;} break;
        case 15:
            {r=118; g=cG; b=116;} break;
        default:
            {r=cR*v/13; g=cG*v/13; b=cB*v/13;} break;
    };
    return ((r<<16) | (g<<8) | b);
}
/*--------------------------------------------------------------------*/
int ATARIpalGen::square(int x)
{
    return (x*x);
}
/*--------------------------------------------------------------------*/
qreal ATARIpalGen::square(qreal x)
{
    return (x*x);
}
/*--------------------------------------------------------------------*/
quint32 ATARIpalGen::distance(quint32 c1, quint32 c2)
{
    quint32 d;
    int ra,ga,ba;
    int rb,gb,bb;
    ra=((c1>>16)&0xFF);
    ga=((c1>>8)&0xFF);
    ba=(c1&0xFF);
    rb=((c2>>16)&0xFF);
    gb=((c2>>8)&0xFF);
    bb=(c2&0xFF);
    d=square(ra-rb)+square(ga-gb)+square(ba-bb);
    return d;
}
/*--------------------------------------------------------------------*/
quint32 ATARIpalGen::average(quint32 a,quint32 b,quint32 c,quint32 d)
{
    quint32 ra,ga,ba;
    quint32 rb,gb,bb;
    quint32 rc,gc,bc;
    quint32 rd,gd,bd;
    quint32 rr,gr,br;
    quint32 ret;
    ra=((a>>16)&0xFF);
    ga=((a>>8)&0xFF);
    ba=(a&0xFF);
    rb=((b>>16)&0xFF);
    gb=((b>>8)&0xFF);
    bb=(b&0xFF);
    rc=((c>>16)&0xFF);
    gc=((c>>8)&0xFF);
    bc=(c&0xFF);
    rd=((d>>16)&0xFF);
    gd=((d>>8)&0xFF);
    bd=(d&0xFF);
    rr=ra+rb+rc+rd;
    gr=ga+gb+gc+gd;
    br=ba+bb+bc+bd;
    rr>>=2;
    gr>>=2;
    br>>=2;
    ret=(rr<<16)+(gr<<8)+br;
    return ret;
}
/*--------------------------------------------------------------------*/
void ATARIpalGen::rebuild()
{
    int i;
    for (i=0; i<256; i++)
    {
        atrgb[i]=calc(i);
    };
}
/*--------------------------------------------------------------------*/
quint32 ATARIpalGen::getRGB(quint8 c)
{
    return atrgb[c];
}
/*--------------------------------------------------------------------*/
quint32 ATARIpalGen::calc(quint8 c)
{
    const qreal tangle[16]={0.0,135.0,112.5,90.0,67.5,45.0,22.5,337.5,315.0,292.5,270.0,225.0,202.5,180.0,157.5,135.0};
    qreal angle[16];
    quint32 ret,h,i;
    angle[0]=0;
    for (i=1; i<16; i++)
    {
        qreal a=tangle[i];
        a=a*M_PI/180.0;
        angle[i]=a;
    };
    // ATARI GITA PAL SYSTEM
    h=((c>>4) & 0x0F);
    if (h==0)
    {
        ret=getGray(c);
    }
    else // YUV ATARI model
    {
        qreal y,u,v,r,g,b;
        quint32 rr,gg,bb;
        y=qreal(c&0x0F)/15.0;
        u=0.5*saturation*qCos(angle[h]);
        v=0.5*saturation*qSin(angle[h]);
        r=1.0*y+1.13983*v;
        g=1.0*y-0.39465*u-0.58060*v;
        b=1.0*y+2.03211*u;
        if (r<0.0) {r=0.0;};
        if (g<0.0) {g=0.0;};
        if (b<0.0) {b=0.0;};
        if (r>1.0) {r=1.0;};
        if (g>1.0) {g=1.0;};
        if (b>1.0) {b=1.0;};
        rr=r*255.0;
        gg=g*255.0;
        bb=b*255.0;
        ret=((rr<<16) | (gg<<8) | bb);
    };
    return ret;
}
/*--------------------------------------------------------------------*/
quint8 ATARIpalGen::nearest(quint32 c)
{
    const qreal tangle[16]={0.0,135.0,112.5,90.0,67.5,45.0,22.5,337.5,315.0,292.5,270.0,225.0,202.5,180.0,157.5,135.0};
    quint32 r,g,b,v,p=0,i;
    qreal rr,gg,bb;
    r=((c>>16)&0xFF);
    g=((c>>8)&0xFF);
    b=(c&0xFF);
    rr=r;
    gg=g;
    bb=b;
    rr=(r/255.0);
    gg=(g/255.0);
    bb=(b/255.0);
    qreal Y=0.299*rr+0.587*gg+0.114*bb;
    qreal U=0.492*(bb-Y);
    qreal V=0.877*(rr-Y);
    qreal sat=square(U)+square(V);
    qreal angle=qAtan2(V,U)*180.0/M_PI;
    if (angle<0) {angle=(360+angle);};
    if (sat>(square(threshold*saturation))) // Fundamental Equation
    {
        qreal dist=360*360;
        for (i=1; i<16; i++)
        {
            qreal d=square(tangle[i]-angle);
            if (d<dist)
            {
                dist=d;
                p=i;
            };
        };
    };
    p<<=4;
    v=Y*255;
    v>>=4;
    return (p|v);
}
/*--------------------------------------------------------------------*/
