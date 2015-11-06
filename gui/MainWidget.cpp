//
// MainWidget.cpp for  in /home/nicolaschr/TP/qt
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat Apr  4 20:51:15 2015 Nicolas Charvoz
// Last update Thu Nov  5 19:33:01 2015 Nicolas Charvoz
//

#include "UiContact.hh"
#include "Home.hh"
#include "Conversation.hh"
#include "MainWidget.hh"

class QTabBar;

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
  QVBoxLayout *mainLayout = new QVBoxLayout;
  QTabBar *tb;

  UiContact *contact = new UiContact(this);
  QScrollArea *contactScrollArea = new QScrollArea();
  contactScrollArea->setWidget(contact);

  _tabWidget = new QTabWidget;
  tb = _tabWidget->tabBar();

  setFixedSize(1920, 1200);
  setWindowTitle(tr("Babel"));

  _tabWidget->addTab(new Home(), tr("Home"));
  _tabWidget->addTab(new UiContact(this), tr("Contact"));

  std::ostringstream oss;

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
}

void MainWidget::addTab(const std::string &name)
{
  _tabWidget->addTab(new Conversation(name), tr(name.c_str()));
}
