//
// Home.cpp for  in /home/nicolaschr/rendu/test/babel/core
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Sep 29 16:55:30 2015 Nicolas Charvoz
// Last update Wed Oct  7 17:18:26 2015 Nicolas Charvoz
//

#include "Home.hh"

Home::Home(QWidget *parent) : QWidget(parent)
{
  QVBoxLayout *mainLayout = new QVBoxLayout;

  QLabel *homeMessage = new QLabel(tr("Welcome in the babel"), this);
}
