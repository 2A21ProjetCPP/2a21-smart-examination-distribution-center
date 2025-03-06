#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
#include <QScreen>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // S’assurer qu’on démarre sur la page du logo
    ui->Principle_stackedWidget->setCurrentIndex(0);

    // 1) Créer un effet d’opacité sur la page du logo
    auto *opacityEffect = new QGraphicsOpacityEffect(ui->pageLogo);
    ui->pageLogo->setGraphicsEffect(opacityEffect);

    // 2) Créer deux animations : fade in, puis fade out
    auto *fadeIn = new QPropertyAnimation(opacityEffect, "opacity", this);
    fadeIn->setDuration(2000);   // 2 secondes
    fadeIn->setStartValue(0.0);  // opacité = 0 (invisible)
    fadeIn->setEndValue(1.0);    // opacité = 1 (opaque)

    auto *fadeOut = new QPropertyAnimation(opacityEffect, "opacity", this);
    fadeOut->setDuration(2000);
    fadeOut->setStartValue(1.0);
    fadeOut->setEndValue(0.0);

    // 3) Chaîner les animations : fadeIn -> pause -> fadeOut
    auto *sequence = new QSequentialAnimationGroup(this);
    sequence->addAnimation(fadeIn);
    // On ajoute une pause de 1 seconde (optionnel)
    sequence->addPause(1000);
    sequence->addAnimation(fadeOut);

    // 4) Quand tout est fini, on passe à la page suivante (login)
    connect(sequence, &QSequentialAnimationGroup::finished, this, [this]() {
        ui->Principle_stackedWidget->setCurrentIndex(1);
    });


    // 5) Lancer l’animation
    sequence->start();

            // --- NOUVEAU : connections pour la sidebar ---
            // On s'assure qu'on est sur la pageCRM au moment où on veut tester la sidebar
            // (Sinon, vous pouvez cliquer sur un bouton qui amène à la pageCRM)
            // ui->Principle_stackedWidget->setCurrentIndex(2);

    connect(ui->pushButton_openSidebar, &QPushButton::clicked, this, &MainWindow::openSidebar);
    connect(ui->pushButton_closeSidebar, &QPushButton::clicked, this, &MainWindow::closeSidebar);

    // ui->Principle_stackedWidget->setCurrentIndex(2);

    connect(ui->pushButton_login, &QPushButton::clicked, this, [this]() {
        // Basculer sur la page d'index 2 (par exemple)
        ui->Principle_stackedWidget->setCurrentIndex(2);
    });

    connect(ui->pushButton_forget, &QPushButton::clicked, this, [this]() {
        // Basculer sur la page d'index 2 (par exemple)
        ui->stackedWidget_2->setCurrentIndex(1);
    });

    connect(ui->pushButton_14, &QPushButton::clicked, this, [this]() {
        // Basculer sur la page d'index 2 (par exemple)
        ui->stackedWidget_2->setCurrentIndex(0);
    });

    connect(ui->pushButton_8, &QPushButton::clicked, this, [this]() {
        // Basculer sur la page d'index 2 (par exemple)
        ui->Principle_stackedWidget->setCurrentIndex(1);
    });

    connect(ui->pushButton_18, &QPushButton::clicked, this, [this]() {
        // Basculer sur la page d'index 2 (par exemple)
        ui->stackedWidget->setCurrentIndex(0);
    });

    connect(ui->pushButton, &QPushButton::clicked, this, [this]() {
        // Basculer sur la page d'index 2 (par exemple)
        ui->stackedWidget->setCurrentIndex(1);
    });

    connect(ui->pushButton_19, &QPushButton::clicked, this, [this]() {
        // Basculer sur la page d'index 2 (par exemple)
        ui->stackedWidget->setCurrentIndex(0);
    });

    connect(ui->pushButton_20, &QPushButton::clicked, this, [this]() {
        // Basculer sur la page d'index 2 (par exemple)
        ui->stackedWidget->setCurrentIndex(2);
    });

    connect(ui->pushButton_21, &QPushButton::clicked, this, [this]() {
        // Basculer sur la page d'index 2 (par exemple)
        ui->stackedWidget->setCurrentIndex(0);
    });

    connect(ui->pushButton_2, &QPushButton::clicked, this, [this]() {
        // Basculer sur la page d'index 2 (par exemple)
        ui->stackedWidget->setCurrentIndex(3);
    });

    connect(ui->pushButton_28, &QPushButton::clicked, this, [this]() {
        // Basculer sur la page d'index 2 (par exemple)
        ui->stackedWidget->setCurrentIndex(5);
    });

    connect(ui->pushButton_33, &QPushButton::clicked, this, [this]() {
        // Basculer sur la page d'index 2 (par exemple)
        ui->stackedWidget->setCurrentIndex(4);
    });

    connect(ui->pushButton_38, &QPushButton::clicked, this, [this]() {
        // Basculer sur la page d'index 2 (par exemple)
        ui->stackedWidget->setCurrentIndex(6);
    });

    connect(ui->pushButton_41, &QPushButton::clicked, this, [this]() {
        // Basculer sur la page d'index 2 (par exemple)
        ui->stackedWidget->setCurrentIndex(4);
    });

    connect(ui->pushButton_40, &QPushButton::clicked, this, [this]() {
        // Basculer sur la page d'index 2 (par exemple)
        ui->stackedWidget->setCurrentIndex(4);
    });

    connect(ui->pushButton_27, &QPushButton::clicked, this, [this]() {
        // Basculer sur la page d'index 2 (par exemple)
        ui->stackedWidget->setCurrentIndex(7);
    });

    connect(ui->pushButton_48, &QPushButton::clicked, this, [this]() {
        // Basculer sur la page d'index 2 (par exemple)
        ui->stackedWidget->setCurrentIndex(9);
    });

    connect(ui->pushButton_59, &QPushButton::clicked, this, [this]() {
        // Basculer sur la page d'index 2 (par exemple)
        ui->stackedWidget->setCurrentIndex(8);
    });

    connect(ui->pushButton_56, &QPushButton::clicked, this, [this]() {
        // Basculer sur la page d'index 2 (par exemple)
        ui->stackedWidget->setCurrentIndex(10);
    });

    connect(ui->pushButton_76, &QPushButton::clicked, this, [this]() {
        // Basculer sur la page d'index 2 (par exemple)
        ui->stackedWidget->setCurrentIndex(8);
    });

    connect(ui->pushButton_47, &QPushButton::clicked, this, [this]() {
        // Basculer sur la page d'index 2 (par exemple)
        ui->stackedWidget->setCurrentIndex(11);
    });

    connect(ui->pushButton_70, &QPushButton::clicked, this, [this]() {
        // Basculer sur la page d'index 2 (par exemple)
        ui->stackedWidget->setCurrentIndex(13);
    });

    connect(ui->pushButton_66, &QPushButton::clicked, this, [this]() {
        // Basculer sur la page d'index 2 (par exemple)
        ui->stackedWidget->setCurrentIndex(12);
    });

    connect(ui->pushButton_63, &QPushButton::clicked, this, [this]() {
        // Basculer sur la page d'index 2 (par exemple)
        ui->stackedWidget->setCurrentIndex(14);
    });

    connect(ui->pushButton_78, &QPushButton::clicked, this, [this]() {
        // Basculer sur la page d'index 2 (par exemple)
        ui->stackedWidget->setCurrentIndex(12);
    });

    connect(ui->pushButton_69, &QPushButton::clicked, this, [this]() {
        // Basculer sur la page d'index 2 (par exemple)
        ui->stackedWidget->setCurrentIndex(15);
    });

    connect(ui->pushButton_81, &QPushButton::clicked, this, [this]() {
        // Basculer sur la page d'index 2 (par exemple)
        ui->stackedWidget->setCurrentIndex(12);
    });

    connect(ui->pushButton_10, &QPushButton::clicked, this, [this]() {
        // Basculer sur la page d'index 2 (par exemple)
        ui->stackedWidget->setCurrentIndex(0);
    });

    connect(ui->pushButton_15, &QPushButton::clicked, this, [this]() {
        // Basculer sur la page d'index 2 (par exemple)
        ui->stackedWidget->setCurrentIndex(8);
    });

    connect(ui->pushButton_16, &QPushButton::clicked, this, [this]() {
        // Basculer sur la page d'index 2 (par exemple)
        ui->stackedWidget->setCurrentIndex(4);
    });

    connect(ui->pushButton_17, &QPushButton::clicked, this, [this]() {
        // Basculer sur la page d'index 2 (par exemple)
        ui->stackedWidget->setCurrentIndex(12);
    });



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::openSidebar()
{
    // On crée l’animation
    QPropertyAnimation *animation = new QPropertyAnimation(ui->frame_sidebar, "geometry", this);
    animation->setDuration(300);

    // Position de départ: x=1543
    QRect startRect = ui->frame_sidebar->geometry();
    startRect.moveLeft(-300);
    animation->setStartValue(startRect);

    // Position d’arrivée: x=1343
    QRect endRect = startRect;
    endRect.moveLeft(0);
    animation->setEndValue(endRect);

    // Easing (optionnel)
    animation->setEasingCurve(QEasingCurve::OutCubic);

    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void MainWindow::closeSidebar()
{
    QPropertyAnimation *animation = new QPropertyAnimation(ui->frame_sidebar, "geometry", this);
    animation->setDuration(300);

    // Position de départ: x=1343
    QRect startRect = ui->frame_sidebar->geometry();
    startRect.moveLeft(0);
    animation->setStartValue(startRect);

    // Position d’arrivée: x=1543
    QRect endRect = startRect;
    endRect.moveLeft(-300);
    animation->setEndValue(endRect);

    animation->setEasingCurve(QEasingCurve::InCubic);

    animation->start(QAbstractAnimation::DeleteWhenStopped);
}
