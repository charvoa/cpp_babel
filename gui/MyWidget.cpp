//
// MyWidget.cpp for  in /home/nicolaschr/TP/qt
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat Apr  4 20:51:15 2015 Nicolas Charvoz
// Last update Fri Oct  9 13:50:34 2015 Nicolas Charvoz
//

#include "Contact.hh"
#include "Home.hh"
#include "Conversation.hh"
#include "MyWidget.hh"

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
  QVBoxLayout *mainLayout = new QVBoxLayout;
  int conv = 4;

  setFixedSize(1920, 1200);
  setWindowTitle(tr("Babel"));

  _tabWidget = new QTabWidget;

  _tabWidget->addTab(new Home(), tr("Home"));
  _tabWidget->addTab(new Contact(), tr("Contact"));

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
  //  _tabWidget->setTabsClosable(true);
  connect(_tabWidget, SIGNAL(tabCloseRequested(int)), this, SLOT(closeTab(int)));

  _tabWidget->setFocusPolicy(Qt::NoFocus);

  //  _tabWidget->setTabPosition(QTabWidget::West);
  mainLayout->addWidget(_tabWidget);
  setLayout(mainLayout);
}

void MyWidget::closeTab(int index)
{
  _tabWidget->removeTab(index);

  delete _tabWidget->widget(index);
}
