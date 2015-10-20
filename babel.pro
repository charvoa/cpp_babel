TEMPLATE = subdirs
RESOURCES += resources.qrc
CONFIG += ordered
SUBDIRS = gui
SUBDIRS += app
app.depends = gui

unix {
clean.target = clean
clean.commands = rm -f */*.o
clean.commands += rm -f */*/*.o
clean.commands += rm -f *~
clean.commands += rm -f */*~
clean.commands += rm -f */*/*~
clean.commands += rm -f */moc_*
clean.commands += rm -f */*/moc_*

}

win32 {
clean.target = clean
clean.commands = del */*.o
clean.commands += del */*/*.o
clean.commands += del *~
clean.commands += del */*~
clean.commands += del */*/*~
clean.commands += del */moc_*
clean.commands += del */*/moc_*
}

QMAKE_EXTRA_TARGETS += clean

unix {
fclean.target = fclean
fclean.commands = rm -f */*.o
fclean.commands += rm -f */*.a
fclean.commands += rm -f */*/*.o
fclean.commands += rm -f */*~
fclean.commands += rm -f */*/*~
fclean.commands += rm -f */moc_*
fclean.commands += rm -f */*/moc_*
fclean.commands += rm -f *.o
fclean.commands += rm -f moc_*
fclean.commands += rm -f babelUI
fclean.commands += rm -f */Makefile
fclean.commands += rm -f Makefile
}

win32 {
fclean.target = fclean
fclean.commands = del *\*.o
fclean.commands += del *\*.a
fclean.commands += del *\*\*.o
fclean.commands += del *\*~
fclean.commands += del *\*\*~
fclean.commands += del *\moc_*
fclean.commands += del *\*\moc_*
fclean.commands += del *.o
fclean.commands += del moc_*
fclean.commands += del babelUI
fclean.commands += del *\Makefile
fclean.commands += del Makefile

}

QMAKE_EXTRA_TARGETS += fclean

re.target = re
unix {
re.commands = make clean
}
win32 {
re.commands = nmake clean
}
re.commands += all

QMAKE_EXTRA_TARGETS += re

