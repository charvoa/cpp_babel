//
// MainWidget.cpp for  in /home/nicolaschr/TP/qt
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat Apr  4 20:51:15 2015 Nicolas Charvoz
// Last update Mon Oct 12 07:52:10 2015 Nicolas Charvoz
//

#include "Contact.hh"
#include "Home.hh"
#include "Conversation.hh"
#include "MainWidget.hh"

class QTabBar;

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
  QVBoxLayout *mainLayout = new QVBoxLayout;
  QTabBar *tb;
  int conv = 4;

  _tabWidget = new QTabWidget;
  tb = _tabWidget->tabBar();

  setFixedSize(1920, 1200);
  setWindowTitle(tr("Babel"));

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
  _tabWidget->setTabsClosable(true);
  connect(_tabWidget, SIGNAL(tabCloseRequested(int)), this, SLOT(closeTab(int)));

  tb->tabButton(0, QTabBar::RightSide)->hide();
  tb->tabButton(1, QTabBar::RightSide)->hide();

  _tabWidget->setFocusPolicy(Qt::NoFocus);

  mainLayout->addWidget(_tabWidget);
  setLayout(mainLayout);
}

void MainWidget::closeTab(int index)
{
  _tabWidget->removeTab(index);

  delete _tabWidget->widget(index);
}
