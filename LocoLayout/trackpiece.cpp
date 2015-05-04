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
#include "trackpiece.h"

// This class is used to create abstract track pieces that are placed into an array to keep track of all track pieces on the grid

TrackPiece::TrackPiece(int toolSelected, QPointF position)
{
    pos = position;
    trackType = toolSelected;
    ds = "NULL";
    connA = "NULL";
    connB = "NULL";
    connC = "NULL";
    switchID = "NULL";

}
int TrackPiece::getTrackType()
{
    return trackType;
}

QPointF TrackPiece::getPos()
{
    return pos;
}

QPointF TrackPiece::getSwPos2()
{
    return swPos2;
}

QPointF TrackPiece::getSwPos3()
{
    return swPos3;
}

QPointF TrackPiece::getSwPos4()
{
    return swPos4;
}

QPointF TrackPiece::getSwPos5()
{
    return swPos5;
}

QPointF TrackPiece::getSwPos6()
{
    return swPos6;
}

QPointF TrackPiece::getSwPos7()
{
    return swPos7;
}

QPointF TrackPiece::getSwPos8()
{
    return swPos8;
}

QString TrackPiece::getDS()
{
    return ds;
}

QString TrackPiece::getconnA()
{
    return connA;
}

QString TrackPiece::getconnB()
{
    return connB;
}

QString TrackPiece::getconnC()
{
    return connC;
}

QString TrackPiece::getSwitchID()
{
    return switchID;
}


void TrackPiece::setTrackType(int toolSelected)
{
    trackType = toolSelected;
}

void TrackPiece::setPos(QPointF position)
{
    pos = position;
}

void TrackPiece::setSwPos2(QPointF position)
{
    swPos2 = position;
}

void TrackPiece::setSwPos3(QPointF position)
{
    swPos3 = position;
}

void TrackPiece::setSwPos4(QPointF position)
{
    swPos4 = position;
}
void TrackPiece::setSwPos5(QPointF position)
{
    swPos5 = position;
}

void TrackPiece::setSwPos6(QPointF position)
{
    swPos6 = position;
}

void TrackPiece::setSwPos7(QPointF position)
{
    swPos7 = position;
}

void TrackPiece::setSwPos8(QPointF position)
{
    swPos8 = position;
}

void TrackPiece::setDS(QString detectionSection)
{
    ds = detectionSection;
}

void TrackPiece::setconnA(QString detectionSection)
{
    connA = detectionSection;
}

void TrackPiece::setconnB(QString detectionSection)
{
    connB = detectionSection;
}

void TrackPiece::setconnC(QString detectionSection)
{
    connC = detectionSection;
}

void TrackPiece::setSwitchID(QString switchName)
{
    switchID = switchName;
}

TrackPiece::~TrackPiece()
{
    delete this;
}

