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
#include "trackfourxtwo.h"
#include <QtWidgets>

// This is the class that is used when creating a three by two track piece

TrackFourXTwo::TrackFourXTwo(int toolSelected, int x, int y)
{

    this->pos.setX(x);
    this->pos.setY(y);

    this->trackType = toolSelected;
    setZValue((x + y) % 2);

    setFlags(ItemIsSelectable | ItemIsFocusable);

    setAcceptHoverEvents(true);
}

QRectF TrackFourXTwo::boundingRect() const
{
    switch(trackType)
    {
        case 31:
            return QRectF(0, 0, 200, 100);
            break;
        case 32:
            return QRectF(-150, 0, 200, 100);
            break;
        case 33:
            return QRectF(0, -50, 200, 100);
            break;
        case 34:
            return QRectF(-150, -50, 200, 100);
            break;
    default:
            return QRectF(0, 0, 200, 100);
            break;
    }

}

QPainterPath TrackFourXTwo::shape() const
{
    QPainterPath path;
    switch(trackType)
    {
        case 31:
            path.addRect(0, 0, 200, 100);
            break;
        case 32:
            path.addRect(-150, 0, 200, 100);
            break;
        case 33:
            path.addRect(0, -50, 200, 100);
            break;
        case 34:
            path.addRect(-150, -50, 200, 100);
            break;
    default:
            break;
    }

    return path;
}

void TrackFourXTwo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);
    Q_UNUSED(option);

    if(option->state & QStyle::State_Selected)
    {
        painter->setBrush(QColor(195,221,246));
        painter->drawPath(this->shape());
    }

    QString string;
    string = "(";
    string.append(QString::number(pos.x()));
    string.append(", ");
    string.append(QString::number(pos.x()));
    string.append(" )");

    switch(trackType)
    {
        case 31:
            painter->drawPixmap(0,0,200,100,QPixmap(":/31.png"));
            break;
        case 32:
            painter->drawPixmap(-150,0,200,100,QPixmap(":/32.png"));
            break;
        case 33:
            painter->drawPixmap(0,-50,200,100,QPixmap(":/33.png"));
            break;
        case 34:
            painter->drawPixmap(-150,-50,200,100,QPixmap(":/34.png"));
            break;
    default:
            break;
    }


    //painter->drawText(0,0,string);

    //painter->setBrush(Qt::red);
    //painter->drawPath(this->shape());

    // Draw red ink
    if (stuff.size() > 1) {
        QPen p = painter->pen();
        painter->setPen(QPen(Qt::red, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
        painter->setBrush(Qt::NoBrush);
        QPainterPath path;
        path.moveTo(stuff.first());
        for (int i = 1; i < stuff.size(); ++i)
            path.lineTo(stuff.at(i));
        painter->drawPath(path);
        painter->setPen(p);
    }
}

void TrackFourXTwo::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
        QGraphicsItem::mousePressEvent(event);
        update();
}

void TrackFourXTwo::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->modifiers() & Qt::ShiftModifier) {
        stuff << event->pos();
        update();
        return;
    }
        QGraphicsItem::mouseMoveEvent(event);
        //update();
}

void TrackFourXTwo::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
        QGraphicsItem::mouseReleaseEvent(event);
        update();
}
void TrackFourXTwo::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Delete)
    {
            delete this;
    }
}

void TrackFourXTwo::setPossiblePos(QPointF possiblePosition)
{
    pos = possiblePosition;
}

QPointF TrackFourXTwo::getPos()
{
    return pos;
}

