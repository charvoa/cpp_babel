//
// MainWidget.cpp for  in /home/nicolaschr/TP/qt
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat Apr  4 20:51:15 2015 Nicolas Charvoz
// Last update Sun Nov  8 18:26:15 2015 Nicolas Charvoz
//

#include "UiContact.hh"
#include "Home.hh"
#include "Conversation.hh"
#include "MainWidget.hh"

class QTabBar;

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
  setFixedSize(1920, 1200);
  setWindowTitle(tr("Babel"));

  QVBoxLayout *mainLayout = new QVBoxLayout;
  QTabBar *tb;

  UiContact *contact = new UiContact(this);
  QScrollArea *contactScrollArea = new QScrollArea();
  contactScrollArea->setWidget(contact);

  _tabWidget = new QTabWidget;
  tb = _tabWidget->tabBar();

  _tabWidget->addTab(new Home(), tr("Home"));
  _tabWidget->addTab(contactScrollArea, tr("Contact"));

  std::ostringstream oss;

  _tabWidget->setTabsClosable(true);
  connect(_tabWidget, SIGNAL(tabCloseRequested(int)), this, SLOT(closeTab(int)));

  tb->tabButton(0, QTabBar::RightSide)->hide();
  tb->tabButton(1, QTabBar::RightSide)->hide();

  _tabWidget->setFocusPolicy(Qt::NoFocus);

  connect(&g_PTUser, SIGNAL(receivedCall(const std::string&)), this, SLOT(receivedCall(const std::string&)));
  mainLayout->addWidget(_tabWidget);
  setLayout(mainLayout);
}

void MainWidget::receivedCall(const std::string &name)
{
  QMessageBox msgBox;

  std::stringstream ss;

  ss << name << " is calling you !" << std::endl;
  msgBox.setText(ss.str().c_str());
  msgBox.addButton(QMessageBox::Yes);
  msgBox.addButton(QMessageBox::No);
  msgBox.exec();
  std::cout << "Receiving call by " << name;
}

void MainWidget::closeTab(int index)
{
  //remove At Index PTUSER
  _tabWidget->removeTab(index);
}

void MainWidget::addTab(const std::string &name)
{
  _tabWidget->addTab(new Conversation(name), tr(name.c_str()));
}
