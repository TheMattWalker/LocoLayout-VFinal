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
#ifndef DETECTIONSECTION_H
#define DETECTIONSECTION_H

#include <QObject>
#include <QPointF>
#include <QColor>

class DetectionSection : public QObject
{
Q_OBJECT
public:
    DetectionSection();
    ~DetectionSection();

    QString getds();
    QList<QPointF> getdspieces();
    QString getconnA();
    QString getconnB();
    QString getconnC();
    QColor getdscolor();

    void setconnA(QString detectionSection);
    void setconnB(QString detectionSection);
    void setconnC(QString detectionSection);
    void setds(QString);
    void setdspieces(QList<QPointF>);
    void cleardspieces();
    void appenddspieces(QPointF);
    void setdspiece(QPointF, int);
    void setdspiece(QPointF, QPointF);
    void setdscolor(QColor);

protected:


private:

QString ds;
QList<QPointF> dspieces;
QString connA;
QString connB;
QString connC;
QColor color;


};

#endif // DETECTIONSECTION_H
