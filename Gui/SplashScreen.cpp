//  Natron
//
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
/*
*Created by Alexandre GAUTHIER-FOICHAT on 6/1/2012.
*contact: immarespond at gmail dot com
*
*/

#include "SplashScreen.h"

#include <QPainter>
#include <QStyleOption>

SplashScreen::SplashScreen(const QString& filePath)
: QWidget(0,Qt::ToolTip | Qt::FramelessWindowHint | Qt::X11BypassWindowManagerHint)
, _pixmap()
{
    setAttribute( Qt::WA_TransparentForMouseEvents );
    
    _pixmap.load(filePath);
    _pixmap = _pixmap.scaled(768, 432);
    
    resize(_pixmap.width(), _pixmap.height());
    show();
}

void SplashScreen::updateText(const QString& text) {
    _text = text;
    repaint();
    QCoreApplication::processEvents();
}

void SplashScreen::paintEvent(QPaintEvent*)
{
    
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    
    p.drawPixmap(0,0,_pixmap);
    p.setPen(Qt::white);
    p.drawText(QPointF(120,100), _text);
}