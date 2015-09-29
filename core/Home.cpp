//
// Home.cpp for  in /home/nicolaschr/rendu/test/babel/core
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Sep 29 16:55:30 2015 Nicolas Charvoz
// Last update Tue Sep 29 17:18:37 2015 Nicolas Charvoz
//

#include "Home.hh"

Home::Home(QWidget *parent) : QWidget(parent)
{
  QLabel *fileNameLabel = new QLabel(tr("Home"));

  QVBoxLayout *mainLayout = new QVBoxLayout;
  mainLayout->addWidget(fileNameLabel);
  mainLayout->addStretch(1);
  setLayout(mainLayout);
}
