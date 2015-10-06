//
// MyWidget.cpp for  in /home/nicolaschr/TP/qt
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat Apr  4 20:51:15 2015 Nicolas Charvoz
// Last update Tue Oct  6 11:42:37 2015 Nicolas Charvoz
//

#include "Contact.hh"
#include "Home.hh"
#include "Conversation.hh"
#include "MyWidget.hh"

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
  int conv = 4;

  setFixedSize(1920, 1200);

  _tabWidget = new QTabWidget;
  _tabWidget->addTab(new Home(), tr("Home"));
  _tabWidget->addTab(new Contact(), tr("Contact"));

  _tabWidget->setTabPosition(QTabWidget::West);
  std::ostringstream oss;
  while (conv >= 0)
    {
      oss.str("");
      oss.clear();
      oss << "Number" << conv;
      std::string var = oss.str();
      _tabWidget->addTab(new Conversation(var), tr(var.c_str()));
      conv--;
    }

  QVBoxLayout *mainLayout = new QVBoxLayout;
  mainLayout->addWidget(_tabWidget);
  setLayout(mainLayout);
  setWindowTitle(tr("Babel"));
}
