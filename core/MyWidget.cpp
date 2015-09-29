//
// MyWidget.cpp for  in /home/nicolaschr/TP/qt
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat Apr  4 20:51:15 2015 Nicolas Charvoz
// Last update Tue Sep 29 17:14:50 2015 Nicolas Charvoz
//

#include "Contact.hh"
#include "Home.hh"
#include "MyWidget.hh"


MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
  setFixedSize(1920, 1200);

  _tabWidget = new QTabWidget;
  _tabWidget->addTab(new Home(), tr("Home"));
  _tabWidget->addTab(new Contact(), tr("Contact"));

  QVBoxLayout *mainLayout = new QVBoxLayout;
  mainLayout->addWidget(_tabWidget);
  setLayout(mainLayout);
  setWindowTitle(tr("Babel"));
}
