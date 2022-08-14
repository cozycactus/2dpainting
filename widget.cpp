// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include "widget.h"
#include "helper.h"

#include <QPainter>
#include <QTimer>

//! [0]
Widget::Widget(Helper *helper, QWidget *parent)
    : QWidget(parent), helper(helper)
{
    elapsed = 0;
    setFixedSize(600, 600);
}
//! [0]

//! [1]
void Widget::animate()
{
    elapsed = (elapsed + qobject_cast<QTimer*>(sender())->interval()) % 5000;
    update();
}
//! [1]

//! [2]
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
    qDebug() << "Native" << ms_double.count() << "ms\n";
}
//! [2]
