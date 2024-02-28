// Copyright (c) 2019-2020 The OdynStock Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ODYNSTOCKPUSHBUTTON_H
#define ODYNSTOCKPUSHBUTTON_H

#include <QIcon>
#include <QPushButton>
#include <QPainter>
#include <QString>
#include <QWidget>

class OdynStockPushButton : public QPushButton
{
    Q_OBJECT

public:
    OdynStockPushButton(QString label);
    void paintEvent(QPaintEvent*);
    void setBadge(int nValue);

private:
    QIcon getBadgeIcon(int nValue);
};

#endif // ODYNSTOCKPUSHBUTTON_H
