// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include "widget.h"
#include "helper.h"
#include <QDebug>
#include <QPainter>
#include <QTimer>
#include <chrono>
#include <qdebug.h>
#include <iostream>

Widget::Widget(Helper *helper, QWidget *parent)
    : QWidget(parent), helper(helper)
{
    elapsed = 0;
    setFixedSize(600, 600);
}

void Widget::animate()
{
    elapsed = (elapsed + qobject_cast<QTimer*>(sender())->interval()) % 5000;
    update();
}

void Widget::paintEvent(QPaintEvent *event)
{
    
    auto start = std::chrono::high_resolution_clock::now();

    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    helper->paint(&painter, event, elapsed);
    painter.end();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> ms_double = end - start;
    qDebug() << ms_double.count() << "ms\n";
}