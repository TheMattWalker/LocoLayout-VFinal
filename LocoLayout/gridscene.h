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
#ifndef GRIDSCENE_H
#define GRIDSCENE_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QDialog>
#include "math.h"
#include "view.h"
#include "trackpiece.h"
#include "detectionsection.h"

#include <QDebug>

class GridScene : public QGraphicsScene
{
private:
    // The size of the cells in the grid.
    const QSize mCellSize;

    // The item being dragged.
    //QGraphicsItem *mDragged;
    QGraphicsItem* mDragged;
    QList<QGraphicsItem*> selectedDragged;

    // List of items at the dragged item destination
    QList<QGraphicsItem*> gItems;

    // The distance from the top left of the item to the mouse position.
    QPointF mDragOffset;

    int toolSelected;

    QPointF pos;
    QPointF origPos;
    QList<QPointF> selectedOrigPos;
    QList<QPointF> deletedItemsList;
    QList<QPointF> copiedItemsList;

    QPointF nullPoint;
    QPointF possPointA;
    QPointF possPointB;
    QPointF possPointC;
    QPointF possPointD;


Q_OBJECT
public:
    GridScene() :
        mCellSize(50, 50), toolSelected(0), mDragged(0), showDSColors(0)
    {
        nullPoint.setX(0.1);
        nullPoint.setY(0.1);
    }

    QVector<QPointF> connPoints;
    QVector<DetectionSection*> dsections;
    bool showDSColors;

    void setToolSelected(int toolNumber);
    void setPossPointA(QPointF);
    void setPossPointB(QPointF);
    void setPossPointC(QPointF);
    void setPossPointD(QPointF);
    QPointF getItemPos();
    void clearDeletedItemsList();

protected:
    void drawForeground(QPainter *painter, const QRectF &rect);
    void drawBackground(QPainter *painter, const QRectF &rect);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);

    int getToolSelected();


signals:
    void itemAdded(int, QPointF);
    void itemMoved(QPointF,QPointF);
    void itemSelected(QPointF);
    void deletedItems(QList<QPointF>);
    void itemscopied();
    void pasteInformation(QList<QPointF>,QPointF);
    void clearToolSelected();
    void dsAddPiece(QPointF);
};

#endif // GRIDSCENE_H
