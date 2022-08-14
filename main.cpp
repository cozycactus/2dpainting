// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include "window.h"

#include <QApplication>
#include <QSurfaceFormat>
#include <QLoggingCategory>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QLoggingCategory::defaultCategory()->setEnabled(QtDebugMsg, true);


    QSurfaceFormat fmt;
    fmt.setSamples(4);
    QSurfaceFormat::setDefaultFormat(fmt);

    Window window;
    window.show();
    return app.exec();
}
