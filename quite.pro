QT += core qml quick quickcontrols2
TARGET = quite
TEMPLATE = app
CONFIG += c++17
CONFIG += console
CONFIG += rtti
DEFINES += QT_DEPRECATED_WARNINGS

lessThan(QT_MAJOR_VERSION, 5) : error("requires Qt > 5.12.*")
equals(QT_MAJOR_VERSION, 5) : lessThan(QT_MINOR_VERSION, 12) : error("requires Qt > 5.12.*")

SOURCES += src/main.cpp \
    src/monitors/bindmonitor.cpp \
    src/objects/binder.cpp \
    src/objects/invoke.cpp \
    src/ui/base/node.cpp \
    src/ui/base/componentnode.cpp \
    src/ui/base/element.cpp \
    src/ui/component.cpp \
    src/ui/elements/rectangle.cpp \
    src/ui/elements/button.cpp \
    src/ui/manager.cpp \
    src/ui/elements/window.cpp \
    src/ui/base/invoker.cpp
SOURCES += src/events/renderui.cpp
SOURCES += src/extensions/quiteextension.cpp 
SOURCES +=
SOURCES += src/events/eval.cpp
SOURCES += src/base/emitter.cpp
SOURCES += src/base/monitor.cpp
SOURCES += src/events/await.cpp
SOURCES += src/monitors/timermonitor.cpp
SOURCES += src/extensions/consoleextension.cpp
SOURCES += src/base/engine.cpp
SOURCES += src/application.cpp
SOURCES += src/base/event.cpp
SOURCES += src/base/extension.cpp
SOURCES += src/base/wrapper.cpp
SOURCES += src/extensions/timerextension.cpp
SOURCES += src/events/installextension.cpp
SOURCES += src/events/importmodule.cpp
SOURCES += src/events/throwerror.cpp

HEADERS += src/base/engine.h \
    src/monitors/bindmonitor.h \
    src/objects/binder.h \
    src/objects/invoke.h \
    src/ui/base/node.h \
    src/ui/base/componentnode.h \
    src/ui/base/element.h \
    src/ui/component.h \
    src/ui/elements/rectangle.h \
    src/ui/elements/button.h \
    src/ui/manager.h \
    src/ui/elements/window.h \
    src/ui/base/invoker.h
HEADERS += src/events/renderui.h
HEADERS += src/extensions/quiteextension.h 
HEADERS +=
HEADERS += src/events/eval.h
HEADERS += src/base/emitter.h
HEADERS += src/base/monitor.h
HEADERS += src/events/await.h
HEADERS += src/monitors/timermonitor.h
HEADERS += src/extensions/consoleextension.h
HEADERS += src/application.h
HEADERS += src/base/event.h
HEADERS += src/base/extension.h
HEADERS += src/base/wrapper.h
HEADERS += src/extensions/timerextension.h
HEADERS += src/events/installextension.h
HEADERS += src/events/importmodule.h
HEADERS += src/events/throwerror.h

RESOURCES += res.qrc
