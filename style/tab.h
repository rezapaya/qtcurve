#ifndef __QTC_TAB_H__
#define __QTC_TAB_H__

/*
  QtCurve (C) Craig Drummond, 2003 - 2010 craig.p.drummond@gmail.com

  ----

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public
  License version 2 as published by the Free Software Foundation.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; see the file COPYING.  If not, write to
  the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
  Boston, MA 02110-1301, USA.
 */

extern gboolean qtcTabCurrentHoveredIndex(GtkWidget *widget);
extern void qtcTabSetup(GtkWidget *widget);
extern void qtcTabUpdateRect(GtkWidget *widget, int tabIndex, int x, int y, int width, int height);
extern gboolean qtcTabIsLabel(GtkNotebook *notebook, GtkWidget *widget);
extern GdkRectangle qtcTabGetTabbarRect(GtkNotebook *notebook);
extern gboolean qtcTabHasVisibleArrows(GtkNotebook *notebook);

#endif