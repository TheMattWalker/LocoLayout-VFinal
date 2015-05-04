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
#include "tracktwoxfour.h"
#include <QtWidgets>

// This is the class that is used when creating a two by three track piece

TrackTwoXFour::TrackTwoXFour(int toolSelected, int x, int y)
{

    this->pos.setX(x);
    this->pos.setY(y);

    this->trackType = toolSelected;
    setZValue((x + y) % 2);

    setFlags(ItemIsSelectable | ItemIsFocusable);


    setAcceptHoverEvents(true);
}

QRectF TrackTwoXFour::boundingRect() const
{
    switch(trackType)
    {
        case 27:
            return QRectF(0, -150, 100, 200);
            break;
        case 28:
            return QRectF(0, 0, 100, 200);
            break;
        case 29:
            return QRectF(-50, -150, 100, 200);
            break;
        case 30:
            return QRectF(-50, 0, 100, 200);
            break;
    default:
            return QRectF(0, 0, 100, 200);
            break;
    }

}

QPainterPath TrackTwoXFour::shape() const
{
    QPainterPath path;

    switch(trackType)
    {
        case 27:
            path.addRect(0, -150, 100, 200);
            break;
        case 28:
            path.addRect(0, 0, 100, 200);
            break;
        case 29:
            path.addRect(-50, -150, 100, 200);
            break;
        case 30:
            path.addRect(-50, 0, 100, 200);
            break;
    default:
            path.addRect(0, 0, 100, 200);
            break;
    }
    return path;
}

void TrackTwoXFour::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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
        case 27:
            painter->drawPixmap(0,-150,100,200,QPixmap(":/27.png"));
            break;
        case 28:
            painter->drawPixmap(0,0,100,200,QPixmap(":/28.png"));
            break;
        case 29:
            painter->drawPixmap(-50,-150,100,200,QPixmap(":/29.png"));
            break;
        case 30:
            painter->drawPixmap(-50,0,100,200,QPixmap(":/30.png"));
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

void TrackTwoXFour::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
        QGraphicsItem::mousePressEvent(event);
        update();
}

void TrackTwoXFour::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->modifiers() & Qt::ShiftModifier) {
        stuff << event->pos();
        update();
        return;
    }
        QGraphicsItem::mouseMoveEvent(event);
        //update();
}

void TrackTwoXFour::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
        QGraphicsItem::mouseReleaseEvent(event);
        update();
}
void TrackTwoXFour::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Delete)
    {
            delete this;
    }
}

void TrackTwoXFour::setPossiblePos(QPointF possiblePosition)
{
    pos = possiblePosition;
}

QPointF TrackTwoXFour::getPos()
{
    return pos;
}

