/****************************************************************************
** Meta object code from reading C++ file 'MainWidget.h'
**
** Created: Tue Jun 7 01:30:57 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "StdAfx.h"
#include "..\..\MainWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      35,   11,   11,   11, 0x0a,
      58,   11,   11,   11, 0x0a,
      81,   11,   11,   11, 0x0a,
     104,   11,   11,   11, 0x0a,
     129,   11,   11,   11, 0x0a,
     160,  154,   11,   11, 0x0a,
     194,   11,   11,   11, 0x0a,
     219,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWidget[] = {
    "MainWidget\0\0onInsertProductClick()\0"
    "onUpdateProductClick()\0onInsertFactoryClick()\0"
    "onUpdateFactoryClick()\0onInsertPurchaseCClick()\0"
    "onUpdatePurchaseCClick()\0index\0"
    "onPurchaseCViewClick(QModelIndex)\0"
    "onInsertPurchaseSClick()\0"
    "onUpdatePurchaseSClick()\0"
};

const QMetaObject MainWidget::staticMetaObject = {
    { &QTabWidget::staticMetaObject, qt_meta_stringdata_MainWidget,
      qt_meta_data_MainWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWidget))
        return static_cast<void*>(const_cast< MainWidget*>(this));
    return QTabWidget::qt_metacast(_clname);
}

int MainWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: onInsertProductClick(); break;
        case 1: onUpdateProductClick(); break;
        case 2: onInsertFactoryClick(); break;
        case 3: onUpdateFactoryClick(); break;
        case 4: onInsertPurchaseCClick(); break;
        case 5: onUpdatePurchaseCClick(); break;
        case 6: onPurchaseCViewClick((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 7: onInsertPurchaseSClick(); break;
        case 8: onUpdatePurchaseSClick(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
