/*
 * Copyright (C) OpenTX
 *
 * Based on code named
 *   th9x - http://code.google.com/p/th9x
 *   er9x - http://code.google.com/p/er9x
 *   gruvin9x - http://code.google.com/p/gruvin9x
 *
 * License GPLv2: http://www.gnu.org/licenses/gpl-2.0.html
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include "simulateduiwidget.h"
#include "ui_simulateduiwidgetX12.h"

SimulatedUIWidgetX12::SimulatedUIWidgetX12(SimulatorInterface *simulator, QWidget * parent):
  SimulatedUIWidget(simulator, parent),
  ui(new Ui::SimulatedUIWidgetX12)
{
  RadioUiAction * act;
  QPolygon polygon;

  ui->setupUi(this);

  // add actions in order of appearance on the help menu

  int x = 74, y = 190, oR = 63, iR = 40;

  polygon << polyArc(x, y, oR, 225, 315) << polyArc(x, y, iR, 225, 315);
  act = new RadioUiAction(0, QList<int>() << Qt::Key_PageUp, tr(SIMU_STR_HLP_KEY_PGUP), tr(SIMU_STR_HLP_ACT_PGUP));
  addRadioWidget(ui->leftbuttons->addArea(polygon, "Horus/left_btn1.png", act));

  polygon.clear();
  polygon << polyArc(x, y, oR, 135, 225) << polyArc(x, y, iR, 135, 225);
  act = new RadioUiAction(1, QList<int>() << Qt::Key_PageDown, tr(SIMU_STR_HLP_KEY_PGDN), tr(SIMU_STR_HLP_ACT_PGDN));
  addRadioWidget(ui->leftbuttons->addArea(polygon, "Horus/left_btn2.png", act));

  polygon.clear();
  polygon << polyArc(x, y, oR, -45, 45) << polyArc(x, y, iR, -45, 45);
  act = new RadioUiAction(3, QList<int>() << Qt::Key_Up, tr(SIMU_STR_HLP_KEY_UP), tr(SIMU_STR_HLP_ACT_MDL));
  addRadioWidget(ui->rightbuttons->addArea(polygon, "Horus/right_btnU.png", act));

  polygon.clear();
  polygon << polyArc(x, y, oR, 225, 315) << polyArc(x, y, iR, 225, 315);
  act = new RadioUiAction(6, QList<int>() << Qt::Key_Left, tr(SIMU_STR_HLP_KEY_LFT), tr(SIMU_STR_HLP_ACT_SYS));
  addRadioWidget(ui->rightbuttons->addArea(polygon, "Horus/right_btnL.png", act));

  polygon.clear();
  polygon << polyArc(x, y, oR, 45, 135) << polyArc(x, y, iR, 45, 135);
  act = new RadioUiAction(5, QList<int>() << Qt::Key_Right, tr(SIMU_STR_HLP_KEY_RGT), tr(SIMU_STR_HLP_ACT_TELE));
  addRadioWidget(ui->rightbuttons->addArea(polygon, "Horus/right_btnR.png", act));

  polygon.clear();
  polygon << polyArc(x, y, oR, 135, 225) << polyArc(x, y, iR, 135, 225);
  act = new RadioUiAction(4, QList<int>() << Qt::Key_Down << Qt::Key_Delete << Qt::Key_Escape << Qt::Key_Backspace,
                         tr(SIMU_STR_HLP_KEY_DN "<br>" SIMU_STR_HLP_KEYS_EXIT), tr(SIMU_STR_HLP_ACT_RTN));
  addRadioWidget(ui->rightbuttons->addArea(polygon, "Horus/right_btnD.png", act));

  m_scrollUpAction = new RadioUiAction(-1, QList<int>() << Qt::Key_Minus, tr(SIMU_STR_HLP_KEY_MIN "|" SIMU_STR_HLP_MOUSE_UP), tr(SIMU_STR_HLP_ACT_ROT_LFT));
  m_scrollDnAction = new RadioUiAction(-1, QList<int>() << Qt::Key_Plus << Qt::Key_Equal, tr(SIMU_STR_HLP_KEY_PLS "|" SIMU_STR_HLP_MOUSE_DN), tr(SIMU_STR_HLP_ACT_ROT_RGT));
  connectScrollActions();

  m_mouseMidClickAction = new RadioUiAction(2, QList<int>() << Qt::Key_Enter << Qt::Key_Return, tr(SIMU_STR_HLP_KEYS_ACTIVATE), tr(SIMU_STR_HLP_ACT_ROT_DN));
  addRadioWidget(ui->rightbuttons->addArea(polyArc(x, y, iR), "Horus/right_ent.png", m_mouseMidClickAction));

  addRadioWidget(ui->leftbuttons->addArea(QRect(9, 259, 30, 30), "Horus/left_scrnsht.png", m_screenshotAction));

  m_backlightColors << QColor(47, 123, 227);

  setLcd(ui->lcd);
}

SimulatedUIWidgetX12::~SimulatedUIWidgetX12()
{
  delete ui;
}
