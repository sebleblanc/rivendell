// rdcatch_conf.h
//
// Abstract RDCatch Configuration
//
//   (C) Copyright 2002-2003 Fred Gleason <fredg@paravelsystems.com>
//
//      $Id: rdcatch_conf.h,v 1.3 2010/07/29 19:32:33 cvs Exp $
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

#ifndef RDCATCH_CONF_H
#define RDCATCH_CONF_H

#include <qsqldatabase.h>


class RDCatchConf
{
 public:
  RDCatchConf(const QString &station);
  QString station() const;
  QString errorRml() const;
  void setErrorRml(const QString &str) const;

 private:
  void SetRow(const QString &param,const QString &value) const;
  QString air_station;
};


#endif  // RDCATCH_CONF_H
