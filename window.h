// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause
#pragma once

#include "helper.h"

#include <QWidget>

class Window : public QWidget
{
    Q_OBJECT

public:
    Window();

private:
    Helper helper;
};
