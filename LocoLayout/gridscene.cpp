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
#include "gridscene.h"

// Reimplementation of QGraphicsScene. Displayed by the QGraphicsView. This is what handles all the graphics on the grid.

// Efficiently draws a grid in the background.
// For more information: http://www.qtcentre.org/threads/5609-Drawing-grids-efficiently-in-QGraphicsScene?p=28905#post28905

void GridScene::drawBackground(QPainter *painter, const QRectF &rect)
{
    qreal left = int(rect.left()) - (int(rect.left()) % mCellSize.width());
    qreal top = int(rect.top()) - (int(rect.top()) % mCellSize.height());

    QVarLengthArray<QLineF, 100> lines;

    for (qreal x = left; x < rect.right(); x += mCellSize.width())
        lines.append(QLineF(x, rect.top(), x, rect.bottom()));
    for (qreal y = top; y < rect.bottom(); y += mCellSize.height())
        lines.append(QLineF(rect.left(), y, rect.right(), y));

    painter->setBrush(QColor(64,224,208));
    painter->drawRect(QRectF(0,0, 50, 50));

    //painter->drawTiledPixmap(rect,QPixmap("../LocoLayout/images/SnowyGrassTexture.jpg"));
    painter->drawPixmap(200,-300,1400,1400,QPixmap(":/logotransparent.png"));

    painter->drawLines(lines.data(), lines.size());

    if(showDSColors)
    {
        if(!dsections.isEmpty())
        {
            for(int i=0; i<=dsections.size()-1; i++)
            {
                painter->setBrush(QBrush(dsections.at(i)->getdscolor()));
                if(!dsections.at(i)->getdspieces().isEmpty())
                {
                    for(int j=0; j<=dsections.at(i)->getdspieces().size()-1; j++)
                    {
                        painter->drawRect(dsections.at(i)->getdspieces().at(j).x(),dsections.at(i)->getdspieces().at(j).y(),50,50);
                    }
                }
            }
        }
    }

    //painter->drawPixmap(0,0,480,480,QPixmap("../LocoLayout/images/SnowyGrassTexture.jpg"));
}

void GridScene::drawForeground(QPainter *painter, const QRectF &rect)
{
    painter->setBrush(QColor(250,255,120));
    for(int i=0; i<=connPoints.size()-1; i++)
        painter->drawRect(QRectF(connPoints.at(i).x(),connPoints.at(i).y(), 50, 50));

    painter->setBrush(QColor(120,255,120));
    if(possPointA!=nullPoint)
        if(!itemAt(possPointA,QTransform()))
            painter->drawRect(QRectF(possPointA.x(),possPointA.y(), 50, 50));
    if(possPointB!=nullPoint)
        if(!itemAt(possPointB,QTransform()))
            painter->drawRect(QRectF(possPointB.x(),possPointB.y(), 50, 50));
    if(possPointC!=nullPoint)
        if(!itemAt(possPointC,QTransform()))
            painter->drawRect(QRectF(possPointC.x(),possPointC.y(), 50, 50));
    if(possPointD!=nullPoint)
        if(!itemAt(possPointD,QTransform()))
            painter->drawRect(QRectF(possPointD.x(),possPointD.y(), 50, 50));

    update();

}

// When the mouse is clicked anywhere on the graphics scene
void GridScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{

    QGraphicsScene::mouseDoubleClickEvent(event);
}

void GridScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    mDragged = qgraphicsitem_cast<QGraphicsItem*>(itemAt(event->scenePos(), QTransform()));


    if(toolSelected == 0)
    {
        if (mDragged)
        {
            if(selectedItems().size()>1) //If selected multiple items
            {

            }
            else //if selected one item
            {
               emit itemSelected(mDragged->pos());
            }
        }
    }
    else if(toolSelected == 42069)    //Tool tool for first piece in ds
    {

        if (mDragged)
        {
            if(selectedItems().size()>1) //If selected multiple items
            {
                for(int i=0; i<=selectedItems().size()-1; i++)
                {
                    selectedItems().at(i)->setFlag(QGraphicsItem::ItemIsMovable,true);
                    selectedOrigPos.append(selectedItems().at(i)->pos());
                }
            }
            else //if selected one item
            {
                mDragged->setFlag(QGraphicsItem::ItemIsMovable,true);
                origPos = mDragged->pos();
                mDragOffset = event->scenePos() - mDragged->pos();
            }
        }
    }
    else if(toolSelected==999)
    {
        if(mDragged)    //If item where clicked, disable item
        {
            mDragged->setFlag(QGraphicsItem::ItemIsSelectable,false);
            mDragged->setFlag(QGraphicsItem::ItemIsFocusable,false);
        }
    }

    else //Tool used
    {
        if(mDragged)    //If item where clicked, disable item
        {
        mDragged->setFlag(QGraphicsItem::ItemIsSelectable,false);
        mDragged->setFlag(QGraphicsItem::ItemIsFocusable,false);
        }
    }

        QGraphicsScene::mousePressEvent(event);
}

// When the mouse is moved anywhere on the graphics scene
void GridScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    //qDebug()<<mDragged;
    if(toolSelected == 42069)
    {
        if (mDragged)
        {
            // Ensure that the item's offset from the mouse cursor stays the same.
            mDragged->setPos(event->scenePos() - mDragOffset);
        }
    }
            QGraphicsScene::mouseMoveEvent(event);


}

// When the mouse click is released anywhere on the graphics scene
void GridScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

   // If a tool is being used, add an item to the scene where clicked
    if(toolSelected==0)
    {


    }
    else if(toolSelected==999)//Copy tool being used
    {
            int x = floor(event->scenePos().x() / 50) * 50;
            int y = floor(event->scenePos().y() / 50) * 50;
            pos.setX(x);
            pos.setY(y);

            emit pasteInformation(copiedItemsList,pos);

            copiedItemsList.clear();

            if (mDragged)
            {
                mDragged->setFlag(QGraphicsItem::ItemIsSelectable,true);
                mDragged->setFlag(QGraphicsItem::ItemIsFocusable,true);
                mDragged = 0;
            }


    }

    else if(toolSelected==42069) // tool for first item in ds, handle dropping event
    {
        if (mDragged)
        {
            if(selectedItems().size()>1)
            {
                for(int i=0; i<=selectedItems().size()-1; i++)
                {
                    selectedItems().at(i)->setFlag(QGraphicsItem::ItemIsMovable,false);
                    int x = floor(selectedItems().at(i)->pos().x() / 50) * 50;
                    int y = floor(selectedItems().at(i)->pos().y() / 50) * 50;
                    pos.setX(x);
                    pos.setY(y);

                    gItems = items(pos, Qt::IntersectsItemShape, Qt::DescendingOrder, QTransform());
                    mDragged = selectedItems().at(i);


                    if(gItems.isEmpty())                    //If list is empty
                    {
                       mDragged->setPos(pos);
                       emit itemMoved(selectedOrigPos.at(i), pos);

                    }
                    else
                    {
                        if(mDragged != gItems.first())
                            mDragged->setPos(selectedOrigPos.at(i));
                        else if(mDragged != gItems.last())
                            mDragged->setPos(selectedOrigPos.at(i));
                        else
                        {
                             mDragged->setPos(pos);
                             emit itemMoved(selectedOrigPos.at(i), pos);

                        }
                    }

                    gItems.clear();
                }

                mDragged = 0;
                gItems.clear();
                selectedOrigPos.clear();
            }

            else
            {
                mDragged->setFlag(QGraphicsItem::ItemIsMovable,false);
                int x = floor(event->scenePos().x() / 50) * 50;
                int y = floor(event->scenePos().y() / 50) * 50;
                pos.setX(x);
                pos.setY(y);

               // List of items at the dragged item destination
                gItems = items(pos, Qt::IntersectsItemShape, Qt::DescendingOrder, QTransform());

                if(gItems.isEmpty())                    //If list is empty
                {
                   mDragged->setPos(pos);
                   emit itemMoved(origPos, pos);
                   emit dsAddPiece(pos);
                }
                else
                {
                    if(mDragged != gItems.first())
                        mDragged->setPos(origPos);
                    else if(mDragged != gItems.last())
                        mDragged->setPos(origPos);
                    else
                    {
                         mDragged->setPos(pos);
                         emit itemMoved(origPos, pos);
                         emit dsAddPiece(pos);

                    }
                }

                mDragged = 0;
                gItems.clear();
            }
        }
    }
    else
    {
        int x = floor(event->scenePos().x() / 50) * 50;
        int y = floor(event->scenePos().y() / 50) * 50;
        pos.setX(x);
        pos.setY(y);

        emit itemAdded(toolSelected, pos);

        if (mDragged)
        {
            mDragged->setFlag(QGraphicsItem::ItemIsSelectable,true);
            mDragged->setFlag(QGraphicsItem::ItemIsFocusable,true);
            mDragged = 0;
        }
    }

    QGraphicsScene::mouseReleaseEvent(event);
}

QPointF GridScene::getItemPos()
{
    return pos;
}

int GridScene::getToolSelected()
{
    return toolSelected;
}

void GridScene::setToolSelected(int toolNumber)
{
    toolSelected = toolNumber;
}

void GridScene::setPossPointA(QPointF pos)
{
    possPointA = pos;
}
void GridScene::setPossPointB(QPointF pos)
{
    possPointB = pos;
}
void GridScene::setPossPointC(QPointF pos)
{
    possPointC = pos;
}
void GridScene::setPossPointD(QPointF pos)
{
    possPointD = pos;
}

void GridScene::clearDeletedItemsList()
{
    deletedItemsList.clear();
}

// When a key is pressed while the graphics scene is focused
void GridScene::keyPressEvent(QKeyEvent *event)
{
    //If delete key is pressed, delete the selected track pieces
    if(event->key()==Qt::Key_Delete)
    {
        if(!selectedItems().isEmpty())
        {
           for(int i = 0; i<= selectedItems().size()-1; i++)
           {
                deletedItemsList.append(selectedItems().at(i)->pos());
           }
        }

       emit deletedItems(deletedItemsList);

     /*  for(int i = 0; i<= deletedItemsList.size()-1; i++)
       {
            delete this->itemAt(deletedItemsList.at(i),QTransform());
       }

       deletedItemsList.clear();*/
    }

    //if copy keys is pressed, copy the selected track pieces
    /*if(event->key() == Qt::Key_C && event->modifiers() & Qt::ControlModifier)
    {
        for(int i = 0; i<= selectedItems().size()-1; i++)
        {
             copiedItemsList.append(selectedItems().at(i)->pos());
        }

        if(!copiedItemsList.isEmpty())
        {
            emit itemscopied();
            qDebug()<<"Items Copied: "<<copiedItemsList;
        }
    }*/

    //if escape key is pressed, clear any copied track pieces, set tool equiped back to none and set cursor back to arrow
    if(event->key()==Qt::Key_Escape)
    {
        //if(toolSelected==999)
        if(!toolSelected==0)
        {
            copiedItemsList.clear();
            emit clearToolSelected();
        }
    }
    if(event->key()==Qt::Key_F1)
    {

        qDebug()<<toolSelected;
    }

}

