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
#include "detectionsection.h"

// Detection Sections

DetectionSection::DetectionSection()
{
    ds = "NULL";
    connA = "NULL";
    connB = "NULL";
    connC = "NULL";
}
QString DetectionSection::getds()
{
    return ds;
}
QList<QPointF> DetectionSection::getdspieces()
{
    return dspieces;
}
QString DetectionSection::getconnA()
{
    return connA;
}
QString DetectionSection::getconnB()
{
    return connB;
}
QString DetectionSection::getconnC()
{
    return connC;
}

void DetectionSection::setconnA(QString detectionSection)
{
    connA = detectionSection;
}

void DetectionSection::setconnB(QString detectionSection)
{
    connB = detectionSection;
}

void DetectionSection::setconnC(QString detectionSection)
{
    connC = detectionSection;
}

void DetectionSection::setds(QString detectionSection)
{
    ds = detectionSection;
}
void DetectionSection::setdspieces(QList<QPointF> dsCoords)
{
    dspieces = dsCoords;
}
void DetectionSection::setdspiece(QPointF coord, int index)
{
    dspieces[index].setX(coord.x());
    dspieces[index].setY(coord.y());
}
void DetectionSection::setdspiece(QPointF coord, QPointF pos)
{
    for(int i=0; i<=dspieces.size()-1; i++)
    {
        if(dspieces.at(i)==pos)
        {
            dspieces[i].setX(coord.x());
            dspieces[i].setY(coord.y());
        }
    }
}
void DetectionSection::cleardspieces()
{
    dspieces.clear();
}
void DetectionSection::appenddspieces(QPointF coord)
{
    dspieces.append(coord);
}

void DetectionSection::setdscolor(QColor rgb)
{
    color = rgb;
}

QColor DetectionSection::getdscolor()
{
    return color;
}

DetectionSection::~DetectionSection()
{
    delete this;
}

