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
#include "tracktwoxtwo.h"
#include <QtWidgets>

// This is the class that is used when creating a two by two track piece

TrackTwoXTwo::TrackTwoXTwo(int toolSelected, int x, int y)
{

    this->pos.setX(x);
    this->pos.setY(y);

    this->trackType = toolSelected;
    setZValue((x + y) % 2);

    setFlags(ItemIsSelectable | ItemIsFocusable);

    setAcceptHoverEvents(true);
}

QRectF TrackTwoXTwo::boundingRect() const
{
    switch(trackType)
    {
        case 35:
            return QRectF(-50, -50, 100, 100);
            break;
        case 36:
            return QRectF(0, -50, 100, 100);
            break;
        case 37:
            return QRectF(-50, -50, 100, 100);
            break;
        case 38:
            return QRectF(0, -50, 100, 100);
            break;
        case 39:
            return QRectF(-50, 0, 100, 100);
            break;
        case 40:
            return QRectF(0, 0, 100, 100);
            break;
        case 41:
            return QRectF(-50, 0, 100, 100);
            break;
        case 42:
            return QRectF(0, 0, 100, 100);
            break;
    default:
            return QRectF(0, 0, 100, 100);
            break;
    }
}

QPainterPath TrackTwoXTwo::shape() const
{
    QPainterPath path;

    switch(trackType)
    {
        case 35:
            path.addRect(-50, -50, 100, 100);
            break;
        case 36:
            path.addRect(0, -50, 100, 100);
            break;
        case 37:
            path.addRect(-50, -50, 100, 100);
            break;
        case 38:
            path.addRect(0, -50, 100, 100);
            break;
        case 39:
            path.addRect(-50, 0, 100, 100);
            break;
        case 40:
            path.addRect(0, 0, 100, 100);
            break;
        case 41:
            path.addRect(-50, 0, 100, 100);
            break;
        case 42:
            path.addRect(0, 0, 100, 100);
            break;
    default:
            path.addRect(0, 0, 100, 100);
            break;
    }
    return path;
}

void TrackTwoXTwo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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
        case 35:
            painter->drawPixmap(-50,-50,100,100,QPixmap(":/35.png"));
            break;
        case 36:
            painter->drawPixmap(0,-50,100,100,QPixmap(":/36.png"));
            break;
        case 37:
            painter->drawPixmap(-50,-50,100,100,QPixmap(":/37.png"));
            break;
        case 38:
            painter->drawPixmap(0,-50,100,100,QPixmap(":/38.png"));
            break;
        case 39:
            painter->drawPixmap(-50,0,100,100,QPixmap(":/39.png"));
            break;
        case 40:
            painter->drawPixmap(0,0,100,100,QPixmap(":/40.png"));
            break;
        case 41:
            painter->drawPixmap(-50,0,100,100,QPixmap(":/41.png"));
            break;
        case 42:
            painter->drawPixmap(0,0,100,100,QPixmap(":/42.png"));
            break;
        case 58:
            painter->drawPixmap(0,0,100,100,QPixmap(":/58.png"));
            break;
        case 59:
            painter->drawPixmap(0,0,100,100,QPixmap(":/59.png"));
            break;
        case 60:
            painter->drawPixmap(0,0,100,100,QPixmap(":/60.png"));
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

void TrackTwoXTwo::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
        QGraphicsItem::mousePressEvent(event);
        update();
}

void TrackTwoXTwo::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->modifiers() & Qt::ShiftModifier) {
        stuff << event->pos();
        update();
        return;
    }
        QGraphicsItem::mouseMoveEvent(event);
        //update();
}

void TrackTwoXTwo::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
        QGraphicsItem::mouseReleaseEvent(event);
        update();
}
void TrackTwoXTwo::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Delete)
    {
            delete this;
    }
}

void TrackTwoXTwo::setPossiblePos(QPointF possiblePosition)
{
    pos = possiblePosition;
}

QPointF TrackTwoXTwo::getPos()
{
    return pos;
}

