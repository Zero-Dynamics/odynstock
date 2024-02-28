// Copyright (c) 2011-2014 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ODYNSTOCK_QT_ODYNSTOCKADDRESSVALIDATOR_H
#define ODYNSTOCK_QT_ODYNSTOCKADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class OdynStockAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit OdynStockAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** OdynStock address widget validator, checks for a valid odynstock address.
 */
class OdynStockAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit OdynStockAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // ODYNSTOCK_QT_ODYNSTOCKADDRESSVALIDATOR_H
