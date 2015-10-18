TEMPLATE = subdirs
RESOURCES += resources.qrc
CONFIG += ordered
SUBDIRS = gui
SUBDIRS += app
app.depends = gui
clean.target = clean
clean.commands = rm -f */*.o
clean.commands += rm -f */*/*.o
clean.commands += rm -f *~
clean.commands += rm -f */*~
clean.commands += rm -f */*/*~
clean.commands += rm -f */moc_*
clean.commands += rm -f */*/moc_*

QMAKE_EXTRA_TARGETS += clean

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

QMAKE_EXTRA_TARGETS += fclean

re.target = re
re.commands = make clean
re.commands += all

QMAKE_EXTRA_TARGETS += re

