/****************************************************************************
** Meta object code from reading C++ file 'main_window.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "main_window.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      26,   11,   11,   11, 0x08,
      38,   11,   11,   11, 0x08,
      51,   11,   11,   11, 0x08,
      63,   11,   11,   11, 0x08,
      74,   11,   11,   11, 0x08,
      85,   11,   11,   11, 0x08,
     102,   11,   11,   11, 0x08,
     116,   11,   11,   11, 0x08,
     128,   11,   11,   11, 0x08,
     143,   11,   11,   11, 0x08,
     158,   11,   11,   11, 0x08,
     175,   11,   11,   11, 0x08,
     189,   11,   11,   11, 0x08,
     203,   11,   11,   11, 0x08,
     213,   11,   11,   11, 0x08,
     221,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0AndOrSearch()\0alphaSort()\0"
    "reviewSort()\0addToCart()\0viewCart()\0"
    "checkout()\0removeFromCart()\0showReviews()\0"
    "addReview()\0submitReview()\0saveDatabase()\0"
    "exportDatabase()\0quitProgram()\0"
    "showProgram()\0addUser()\0login()\0"
    "closeInfo()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->AndOrSearch(); break;
        case 1: _t->alphaSort(); break;
        case 2: _t->reviewSort(); break;
        case 3: _t->addToCart(); break;
        case 4: _t->viewCart(); break;
        case 5: _t->checkout(); break;
        case 6: _t->removeFromCart(); break;
        case 7: _t->showReviews(); break;
        case 8: _t->addReview(); break;
        case 9: _t->submitReview(); break;
        case 10: _t->saveDatabase(); break;
        case 11: _t->exportDatabase(); break;
        case 12: _t->quitProgram(); break;
        case 13: _t->showProgram(); break;
        case 14: _t->addUser(); break;
        case 15: _t->login(); break;
        case 16: _t->closeInfo(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE