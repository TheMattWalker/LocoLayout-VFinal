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
#ifndef VIEW_H
#define VIEW_H

#include <QFrame>
#include <QGraphicsView>
#include <QPushButton>

class QLabel;
class QSlider;
class QToolButton;

class View;

class GraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    GraphicsView(View *v) : QGraphicsView(), view(v) { }

protected:
//#ifndef QT_NO_WHEELEVENT
    void wheelEvent(QWheelEvent *);// Q_DECL_OVERRIDE;
//#endif

private:
    View *view;
};

class View : public QFrame
{
    Q_OBJECT
public:
    explicit View(const QString &name, QWidget *parent = 0);

    QGraphicsView *view() const;

    void setLayoutName(QString string);

public slots:
    void zoomIn(int level = 1);
    void zoomOut(int level = 1);

private slots:
    void resetView();
    void setResetButtonEnabled();
    void setupMatrix();
    void togglePointerMode();
    void toggleOpenGL();
    //void toggleAntialiasing();
    void toggleAntialiasing(bool ok);
    void print();
    void rotateLeft();
    void rotateRight();

    QTransform getQTransform();

private:
    GraphicsView *graphicsView;
    QLabel *label;
    QLabel *label2;

    QLabel* layoutName;

    QPushButton *selectModeButton;
    QPushButton *dragModeButton;
    QToolButton *openGlButton;
    QToolButton *antialiasButton;
    QToolButton *printButton;
    QPushButton *resetButton;
    QSlider *zoomSlider;
    QSlider *rotateSlider;
};

#endif // VIEW_H
