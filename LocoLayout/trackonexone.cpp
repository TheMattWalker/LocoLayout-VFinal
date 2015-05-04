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
#include "trackonexone.h"
#include <QtWidgets>

// This is the class that is used when creating a one by one track piece

TrackOneXOne::TrackOneXOne(int toolSelected, int x, int y)
{

    this->pos.setX(x);
    this->pos.setY(y);

    this->trackType = toolSelected;
    setZValue((x + y) % 2);

    setFlags(ItemIsSelectable | ItemIsFocusable);
    setAcceptHoverEvents(true);
}

QRectF TrackOneXOne::boundingRect() const
{
    return QRectF(0, 0, 50, 50);
}

QPainterPath TrackOneXOne::shape() const
{
    QPainterPath path;

    path.addRect(0, 0, 50, 50);
    return path;
}

void TrackOneXOne::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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
        case 1:
            painter->drawPixmap(0,0,50,50,QPixmap(":/1.png"));
            break;
        case 2:
            painter->drawPixmap(0,0,50,50,QPixmap(":/2.png"));
            break;
        case 3:
            painter->drawPixmap(0,0,50,50,QPixmap(":/3.png"));
            break;
        case 4:
            painter->drawPixmap(0,0,50,50,QPixmap(":/4.png"));
            break;
        case 5:
            painter->drawPixmap(0,0,50,50,QPixmap(":/5.png"));
            break;
        case 6:
            painter->drawPixmap(0,0,50,50,QPixmap(":/6.png"));
            break;
        case 7:
            painter->drawPixmap(0,0,50,50,QPixmap(":/7.png"));
            break;
        case 8:
            painter->drawPixmap(0,0,50,50,QPixmap(":/8.png"));
            break;
        case 9:
            painter->drawPixmap(0,0,50,50,QPixmap(":/9.png"));
            break;
        case 10:
            painter->drawPixmap(0,0,50,50,QPixmap(":/10.png"));
            break;
        case 11:
            painter->drawPixmap(0,0,50,50,QPixmap(":/11.png"));
            break;
        case 12:
            painter->drawPixmap(0,0,50,50,QPixmap(":/12.png"));
            break;
        case 13:
            painter->drawPixmap(0,0,50,50,QPixmap(":/13.png"));
            break;
        case 14:
            painter->drawPixmap(0,0,50,50,QPixmap(":/14.png"));
            break;
        case 15:
            painter->drawPixmap(0,0,50,50,QPixmap(":/15.png"));
            break;
        case 16:
            painter->drawPixmap(0,0,50,50,QPixmap(":/16.png"));
            break;
        case 17:
            painter->drawPixmap(0,0,50,50,QPixmap(":/17.png"));
            break;
        case 18:
            painter->drawPixmap(0,0,50,50,QPixmap(":/18.png"));
            break;
        case 19:
            painter->drawPixmap(0,0,50,50,QPixmap(":/19.png"));
            break;
        case 20:
            painter->drawPixmap(0,0,50,50,QPixmap(":/20.png"));
            break;
        case 21:
            painter->drawPixmap(0,0,50,50,QPixmap(":/21.png"));
            break;
        case 22:
            painter->drawPixmap(0,0,50,50,QPixmap(":/22.png"));
            break;
        case 23:
            painter->drawPixmap(0,0,50,50,QPixmap(":/23.png"));
            break;
        case 24:
            painter->drawPixmap(0,0,50,50,QPixmap(":/24.png"));
            break;
        case 25:
            painter->drawPixmap(0,0,50,50,QPixmap(":/25.png"));
            break;
        case 26:
            painter->drawPixmap(0,0,50,50,QPixmap(":/26.png"));
            break;

            //27-42 in non 1x1 piece classes

        case 43:
            painter->drawPixmap(0,0,50,50,QPixmap(":/43.png"));
            break;
        case 44:
            painter->drawPixmap(0,0,50,50,QPixmap(":/44.png"));
            break;
        case 45:
            painter->drawPixmap(0,0,50,50,QPixmap(":/45.png"));
            break;
        case 46:
            painter->drawPixmap(0,0,50,50,QPixmap(":/46.png"));
            break;
        case 47:
            painter->drawPixmap(0,0,50,50,QPixmap(":/47.png"));
            break;
        case 48:
            painter->drawPixmap(0,0,50,50,QPixmap(":/48.png"));
            break;
        case 49:
            painter->drawPixmap(0,0,50,50,QPixmap(":/49.png"));
            break;
        case 50:
            painter->drawPixmap(0,0,50,50,QPixmap(":/50.png"));
            break;
        case 51:
            painter->drawPixmap(0,0,50,50,QPixmap(":/51.png"));
            break;
        case 52:
            painter->drawPixmap(0,0,50,50,QPixmap(":/52.png"));
            break;
        case 53:
            painter->drawPixmap(0,0,50,50,QPixmap(":/53.png"));
            break;
        case 54:
            painter->drawPixmap(0,0,50,50,QPixmap(":/54.png"));
            break;
        case 55:
            painter->drawPixmap(0,0,50,50,QPixmap(":/55.png"));
            break;
        case 56:
            painter->drawPixmap(0,0,50,50,QPixmap(":/56.png"));
            break;
        case 57:
            painter->drawPixmap(0,0,50,50,QPixmap(":/57.png"));
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

void TrackOneXOne::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
        QGraphicsItem::mousePressEvent(event);
        update();
}

void TrackOneXOne::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->modifiers() & Qt::ShiftModifier) {
        stuff << event->pos();
        update();
        return;
    }
        QGraphicsItem::mouseMoveEvent(event);
        // update();
}

void TrackOneXOne::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
        QGraphicsItem::mouseReleaseEvent(event);
        update();
}

void TrackOneXOne::setPossiblePos(QPointF possiblePosition)
{
    pos = possiblePosition;
}

int TrackOneXOne::getTrackType()
{
    return trackType;
}

QPointF TrackOneXOne::getPos()
{
    return pos;
}
