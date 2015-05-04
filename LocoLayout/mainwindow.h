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
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStyle>
#include <QtSql>
#include <QAction>
#include <QLabel>
#include <QProgressBar>
#include <QSplitter>
#include <QPushButton>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QDialog>
#include <QToolButton>
#include <QFileDialog>
#include <QLineEdit>
#include <QRadioButton>
#include <QTableWidget>
#include <QDockWidget>
#include <random>
#include "gridscene.h"
#include "view.h"
#include "trackpiece.h"
#include "detectionsection.h"
#include "trackonexone.h"
#include "tracktwoxtwo.h"
#include "tracktwoxfour.h"
#include"trackfourxtwo.h"

class QGraphicsScene;
class QSplitter;

namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
Ui::MainWindow *ui;

    void setupMatrix();
    void populateScene(QString string);
    QColor getColor(QColor mix);

    View *view;
    GridScene *gridscene;
    QSplitter *h1Splitter;
    QSplitter *h2Splitter;

    QLabel* statusLabel;

    QTableWidget* tptable;
    QTableWidget* ctable;

    QDockWidget* dsDock;
    QDockWidget* tpDock;
    QDockWidget* sqlDock;

    QVector<TrackPiece*> trackpieces;
    QVector<DetectionSection*> dsections;

    QPointF lastPos;
    QPointF currentPos;

    QPointF nullPoint;
    QPointF possPointA;
    QPointF possPointB;
    QPointF possPointC;
    QPointF possPointD;

    QVector<TrackPiece*> connPoints;

    QString newDSName;

    QString layoutName;

    QMenu* fileMenu;
    QMenu* editMenu;
    QMenu* toolsMenu;
    QMenu* helpMenu;
    QAction* exitAction;
    QAction* aboutAction;
    QAction* printAction;
    QAction* saveLayoutAction;
    QAction* saveAsLayoutAction;
    QAction* loadLayoutAction;
    QAction* antiaAction;

    QAction* tpToolAction;
    QAction* dsToolAction;
    QAction* sqlToolAction;

    QVBoxLayout* dsMainLayout;
    QWidget* dsMainWidget;
    QVBoxLayout* tpMainLayout;
    QWidget* tpMainWidget;
    QHBoxLayout* sqlMainLayout;
    QWidget* sqlMainWidget;

    QLineEdit* sqlHostEdit;
    QLineEdit* sqlPortEdit;
    QLineEdit* sqlDBNameEdit;
    QLineEdit* sqlUserNameEdit;
    QLineEdit* sqlPasswordEdit;

    QSqlDatabase remotedb;

    QTabWidget* tpTabWidget;

    QWidget* dsLabelWidget;
    QWidget* dsTableWidget;

    QVBoxLayout* tpTabLayout;

    QHBoxLayout* trackLibTabLayout;
    QGridLayout* trackButtonLayout;
    QWidget* trackButtonBox;

    QWidget* newDSBox;
    QWidget* saveDSBox;
    QVBoxLayout* newDSBoxLayout;
    QVBoxLayout* saveDSBoxLayout;

    QLabel* errorDSLabel;
    QPushButton* newDSPushButton;
    QLineEdit* newDSLineEdit;
    QPushButton* saveDSPushButton;

    QWidget* straightToolGroupBox;
    QGridLayout* straightTrackLayout;
    QWidget* bumperToolGroupBox;
    QGridLayout *bumperTrackLayout;
    QWidget* curvedToolGroupBox;
    QGridLayout* curvedTrackLayout;
    QWidget* switchToolGroupBox;
    QGridLayout* switchTrackLayout;
    QWidget* crossToolGroupBox;
    QGridLayout* crossTrackLayout;
    QWidget* diagonalToolGroupBox;
    QGridLayout* diagonalTrackLayout;
    QWidget* cosmeticToolGroupBox;
    QGridLayout* cosmeticTrackLayout;

    QPushButton* zoomInButton;
    QPushButton* zoomOutButton;
    QPushButton* rotateRightButton;
    QPushButton* rotateLeftButton;
    QPushButton* zeroViewButton;

    QPushButton* straightToolButton;
    QPushButton* bumperToolButton;
    QPushButton* curvedToolButton;
    QPushButton* switchToolButton;
    QPushButton* crossToolButton;
    QPushButton* diagonalToolButton;
    QPushButton* cosmeticToolButton;
    QPushButton* lastItemPosButton;

    QLabel* DSidLabel;
    QLineEdit* DSidEdit;
    QLabel* switchIDLabel;
    QLineEdit* switchIDEdit;
    /*QLabel* connADSidLabel;
    QLineEdit* connADSidEdit;
    QLabel* connBDSidLabel;
    QLineEdit* connBDSidEdit;
    QLabel* connCDSidLabel;
    QLineEdit* connCDSidEdit;
    QPushButton* DSButton;*/

    QByteArray data;

    bool dsExists;

    int toolSelected;

    QString layoutFileName;

    int pieceCounter;
    int firstPieceType;
    int prevConn;
    bool badPosFlag;
    int isEndConn;
    int connPointExists;
    int curConnPointType;

    QPointF crossPosition;
    int crossType;
    bool addCross;
    bool dsAddedCross;
    QPointF dsCrossPos;

    QString switchID;

    bool switchConnA;
    bool switchConnB;
    bool switchConnC;

    //bool DSsaved;

    //STRAIGHT TOOLBAR
    QPushButton* Straight1ToolButton;
    QPushButton* Straight2ToolButton;

    //BUMPER TOOLBAR
    QPushButton* Bumper3ToolButton;
    QPushButton* Bumper4ToolButton;
    QPushButton* Bumper5ToolButton;
    QPushButton* Bumper6ToolButton;
    QPushButton* Bumper7ToolButton;
    QPushButton* Bumper8ToolButton;
    QPushButton* Bumper9ToolButton;
    QPushButton* Bumper10ToolButton;

    //CROSS TOOLBAR
    QPushButton* Cross11ToolButton;
    QPushButton* Cross12ToolButton;
    QPushButton* Cross13ToolButton;
    QPushButton* Cross14ToolButton;
    QPushButton* Cross15ToolButton;
    QPushButton* Cross16ToolButton;

    //CURVED TOOLBAR
    QPushButton* Curve17ToolButton;
    QPushButton* Curve18ToolButton;
    QPushButton* Curve19ToolButton;
    QPushButton* Curve20ToolButton;
    QPushButton* Curve21ToolButton;
    QPushButton* Curve22ToolButton;
    QPushButton* Curve23ToolButton;
    QPushButton* Curve24ToolButton;

    //DIAGONAL TOOLBAR
    QPushButton* Diagonal25ToolButton;
    QPushButton* Diagonal26ToolButton;

    //SWITCH TOOLBAR
    QPushButton*  Switch27ToolButton;
    QPushButton*  Switch28ToolButton;
    QPushButton*  Switch29ToolButton;
    QPushButton*  Switch30ToolButton;
    QPushButton*  Switch31ToolButton;
    QPushButton*  Switch32ToolButton;
    QPushButton*  Switch33ToolButton;
    QPushButton*  Switch34ToolButton;
    QPushButton*  Switch35ToolButton;
    QPushButton*  Switch36ToolButton;
    QPushButton*  Switch37ToolButton;
    QPushButton*  Switch38ToolButton;
    QPushButton*  Switch39ToolButton;
    QPushButton*  Switch40ToolButton;
    QPushButton*  Switch41ToolButton;
    QPushButton*  Switch42ToolButton;

    //COSMETIC TOOLBAR
    QPushButton*  Cosmetic43ToolButton;
    QPushButton*  Cosmetic44ToolButton;
    QPushButton*  Cosmetic45ToolButton;
    QPushButton*  Cosmetic46ToolButton;
    QPushButton*  Cosmetic47ToolButton;
    QPushButton*  Cosmetic48ToolButton;
    QPushButton*  Cosmetic49ToolButton;
    QPushButton*  Cosmetic50ToolButton;
    QPushButton*  Cosmetic51ToolButton;
    QPushButton*  Cosmetic52ToolButton;
    QPushButton*  Cosmetic53ToolButton;
    QPushButton*  Cosmetic54ToolButton;
    QPushButton*  Cosmetic55ToolButton;
    QPushButton*  Cosmetic56ToolButton;
    QPushButton*  Cosmetic57ToolButton;
    QPushButton*  Cosmetic58ToolButton;
    QPushButton*  Cosmetic59ToolButton;
    QPushButton*  Cosmetic60ToolButton;



protected:

    int getToolSelected();
    void setToolSelected(int toolNumber);

signals:
    void loadItem(int itemType, QPointF pos);
    void newDSNameSignal(QString);

public slots:
    void aboutDialog();
    void saveLayout();
    void saveAsLayout();
    void loadLayout();
    void loadLayoutCheck();
    void editDS();
    void newDSWindow();
    void createNewDS();
    void saveDS();
    void setDSName(QString);
    void addItemToDS(QPointF);
    void endDSDialog();
    void startDSDialog();
    void showDSections(bool);
    void deleteDSections();
    void loadItemOnGrid(int, QPointF);
    void toggleDSDock(bool);
    void toggleTPDock(bool);
    void toggleSQLDock(bool);

    void uploadLayout();

    void getPossPoints(QPointF, int);
    int  isDSConnection(QPointF, int);
    void setDSConnPoints(QPointF, int, int);
    void setPossPieces(int);

    void hitACross(QPointF, QPointF, int);

    void setSwitchID(QString);

    void newMainDS();
    void saveMainDS();

    void straightToolActionSlot();
    void bumperToolActionSlot();
    void curvedToolActionSlot();
    void switchToolActionSlot();
    void crossToolActionSlot();
    void diagonalToolActionSlot();
    void cosmeticToolActionSlot();

    void lastItemPosActionSlot();
    void setCrossCursor();
    void setArrowCursor();
    void addItem(int tracktype, QPointF pos);
    void movedItem(QPointF,QPointF);
    void selectItem(QPointF pos);
    void deleteItems(QList<QPointF>);
    void setCopyTool();
    void pasteItems(QList<QPointF>,QPointF);
    void clearToolSelected();

    //STRAIGHT TOOLBAR
    void Straight1Slot();
    void Straight2Slot();

    //BUMPER TOOLBAR
    void Bumper3Slot();
    void Bumper4Slot();
    void Bumper5Slot();
    void Bumper6Slot();
    void Bumper7Slot();
    void Bumper8Slot();
    void Bumper9Slot();
    void Bumper10Slot();

    //CROSS TOOLBAR
    void Cross11Slot();
    void Cross12Slot();
    void Cross13Slot();
    void Cross14Slot();
    void Cross15Slot();
    void Cross16Slot();

    //CURVED TOOLBAR
    void Curve17Slot();
    void Curve18Slot();
    void Curve19Slot();
    void Curve20Slot();
    void Curve21Slot();
    void Curve22Slot();
    void Curve23Slot();
    void Curve24Slot();

    //DIAGONAL TOOLBAR
    void Diagonal25Slot();
    void Diagonal26Slot();

    //SWITCH TOOLBAR
    void Switch27Slot();
    void Switch28Slot();
    void Switch29Slot();
    void Switch30Slot();
    void Switch31Slot();
    void Switch32Slot();
    void Switch33Slot();
    void Switch34Slot();
    void Switch35Slot();
    void Switch36Slot();
    void Switch37Slot();
    void Switch38Slot();
    void Switch39Slot();
    void Switch40Slot();
    void Switch41Slot();
    void Switch42Slot();

    //COSMETIC TOOLBAR
    void Corner43Slot();
    void Corner44Slot();
    void Corner45Slot();
    void Corner46Slot();
    void Corner47Slot();
    void Corner48Slot();
    void Corner49Slot();
    void Corner50Slot();
    void Corner51Slot();
    void Corner52Slot();
    void Corner53Slot();
    void Corner54Slot();
    void Corner55Slot();
    void Corner56Slot();
    void Corner57Slot();
    void Corner58Slot();
    void Corner59Slot();
    void Corner60Slot();




};

#endif // MAINWINDOW_H
