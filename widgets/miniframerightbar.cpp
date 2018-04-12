/*
 * Copyright (C) 2017 ~ 2018 Deepin Technology Co., Ltd.
 *
 * Author:     rekols <rekols@foxmail.com>
 *
 * Maintainer: rekols <rekols@foxmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "miniframerightbar.h"
#include "avatar.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QPainter>

MiniFrameRightBar::MiniFrameRightBar(QWidget *parent)
    : QWidget(parent),
      m_modeToggleBtn(new DImageButton),
      m_avatar(new Avatar)
{
    m_modeToggleBtn->setNormalPic(":/icons/skin/icons/fullscreen_normal.png");
    m_modeToggleBtn->setHoverPic(":/icons/skin/icons/fullscreen_hover.png");
    m_modeToggleBtn->setPressPic(":/icons/skin/icons/fullscreen_press.png");

    QVBoxLayout *layout = new QVBoxLayout(this);
    QHBoxLayout *bottomLayout = new QHBoxLayout;
    QPushButton *computerBtn = new QPushButton(tr("Computer"));
    QPushButton *documentBtn = new QPushButton(tr("Document"));
    QPushButton *videoBtn = new QPushButton(tr("Video"));
    QPushButton *musicBtn = new QPushButton(tr("Music"));
    QPushButton *pictureBtn = new QPushButton(tr("Picture"));
    QPushButton *downloadBtn = new QPushButton(tr("Downloads"));
    QPushButton *manualBtn = new QPushButton(tr("Manual"));
    QPushButton *settingsBtn = new QPushButton(tr("Settings"));
    QPushButton *shutdownBtn = new QPushButton(tr("Shutdown"));

    bottomLayout->addWidget(settingsBtn);
    bottomLayout->addWidget(shutdownBtn);

    layout->addWidget(m_modeToggleBtn, 0, Qt::AlignTop | Qt::AlignRight);
    layout->addWidget(m_avatar);
    layout->addSpacing(30);
    layout->addWidget(computerBtn);
    layout->addWidget(documentBtn);
    layout->addWidget(videoBtn);
    layout->addWidget(musicBtn);
    layout->addWidget(pictureBtn);
    layout->addWidget(downloadBtn);
    layout->addWidget(manualBtn);
    layout->addStretch();
    layout->addLayout(bottomLayout);
    layout->setContentsMargins(20, 12, 12, 15);

    setFixedWidth(240);

    connect(m_modeToggleBtn, &DImageButton::clicked, this, &MiniFrameRightBar::modeToggleBtnClicked);
}

MiniFrameRightBar::~MiniFrameRightBar()
{
}

void MiniFrameRightBar::paintEvent(QPaintEvent *e)
{
    QWidget::paintEvent(e);

    QPainter painter(this);
    painter.setPen(QColor(255, 255, 255, 0.2 * 255));
    painter.drawLine(QPoint(0, 0),
                     QPoint(0, rect().height()));
}