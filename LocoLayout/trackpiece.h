/****************************************************************************
**
** LocoLayout
**
** Copyright (C) 2015 UAHell
**
** Contact: mnw0002@uah.edu
**
** Authors: Mike Walsh, Becca Sander, Matt Walker
**
** This file is part of the LocoLayout train program.
**
** These files and all other files included in this program package
** can NOT be modified without the author's explicit authorization.
**
** This program is for demonstrations only.
**
**
****************************************************************************/
#ifndef TRACKPIECE_H
#define TRACKPIECE_H

#include <QObject>
#include <QPointF>

class TrackPiece : public QObject
{
Q_OBJECT
public:
    TrackPiece(int toolSelected, QPointF position);
    ~TrackPiece();

    QPointF getPos();
    QPointF getSwPos2();
    QPointF getSwPos3();
    QPointF getSwPos4();
    QPointF getSwPos5();
    QPointF getSwPos6();
    QPointF getSwPos7();
    QPointF getSwPos8();
    int getTrackType();
    QString getDS();
    QString getconnA();
    QString getconnB();
    QString getconnC();
    QString getSwitchID();


    void setPos(QPointF);
    void setSwPos2(QPointF);
    void setSwPos3(QPointF);
    void setSwPos4(QPointF);
    void setSwPos5(QPointF);
    void setSwPos6(QPointF);
    void setSwPos7(QPointF);
    void setSwPos8(QPointF);
    void setTrackType(int);
    void setDS(QString);
    void setconnA(QString);
    void setconnB(QString);
    void setconnC(QString);
    void setSwitchID(QString);

protected:


private:

    QPointF pos;
    int trackType;
    QString ds;
    QString connA;
    QString connB;
    QString connC;
    bool startPiece;
    bool endPiece;
    QString switchID;
    QPointF swPos2;
    QPointF swPos3;
    QPointF swPos4;
    QPointF swPos5;
    QPointF swPos6;
    QPointF swPos7;
    QPointF swPos8;
    QPointF connPos; //used for connection point trackpieces


};

#endif // TRACKPIECE_H
