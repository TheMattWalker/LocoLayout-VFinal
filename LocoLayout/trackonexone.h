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
#ifndef TRACKONEXONE_H
#define TRACKONEXONE_H

#include <QColor>
#include <QGraphicsObject>

class TrackOneXOne : public QGraphicsObject
{
Q_OBJECT
public:
    TrackOneXOne(int toolSelected, int x, int y);

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    QPainterPath shape() const Q_DECL_OVERRIDE;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void setPossiblePos(QPointF possiblePosition);
    QPointF getPos();
    int getTrackType();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;

    //void keyPressEvent(QKeyEvent *event);

private:

    QPointF pos;

    int trackType;

    QVector<QPointF> stuff;

signals:
    void itemDeleted(QPointF);

};

#endif // TRACKONEXONE_H
