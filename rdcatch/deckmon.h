// deckmon.h
//
// Monitor a Rivendell Netcatcher Deck
//
//   (C) Copyright 2002-2019 Fred Gleason <fredg@paravelsystems.com>
//
//   This program is free software; you can redistribute it and/or modify
//   it under the terms of the GNU General Public License version 2 as
//   published by the Free Software Foundation.
//
//   This program is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU General Public License for more details.
//
//   You should have received a copy of the GNU General Public
//   License along with this program; if not, write to the Free Software
//   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
//

#ifndef DECKMON_H
#define DECKMON_H

#include <qlabel.h>
#include <qpushbutton.h>

#include <rddeck.h>
#include <rdframe.h>
#include <rdplaymeter.h>
#include <rdrecording.h>

class DeckMon : public RDFrame
{
  Q_OBJECT
 public:
  DeckMon(QString station,unsigned channel,QWidget *parent=0);
  ~DeckMon();
  QSize sizeHint() const;
  QSizePolicy sizePolicy() const;
  void enableMonitorButton(bool state);

 public slots:
  void setMonitor(bool state);
  void setStatus(RDDeck::Status status,int id,const QString &cutname);
  void setEvent(int number);
  void setLeftMeter(int level);
  void setRightMeter(int level);
  
 signals:
  void monitorClicked();
  void abortClicked();

 protected:
  void resizeEvent(QResizeEvent *e);

 private slots:
  void monitorButtonData();
  void abortButtonData();
  void eventResetData();

 private:
  void SetCutInfo(int id,const QString &cutname);
  QLabel *mon_station_label;
  QLabel *mon_cut_label;
  QLabel *mon_event_label;
  QLabel *mon_status_label;
  QPushButton *mon_abort_button;
  QPushButton *mon_monitor_button;
  QPalette *mon_monitor_palette;
  RDPlayMeter *mon_left_meter;
  RDPlayMeter *mon_right_meter;
  QString mon_station;
  unsigned mon_channel;
  QTimer *mon_event_timer;
  QPalette mon_red_palette;
  QPalette mon_dark_palette;
};


#endif

