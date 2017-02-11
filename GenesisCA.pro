#-------------------------------------------------
#
# Project created by QtCreator 2017-01-24T18:56:12
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = GenesisCA
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += \
 src/ca_modeler/AttributeHandler/ \
 src/ca_modeler/ModelPropertiesHandler/

SOURCES += \
  src/main.cpp \
  src/ca_modeler/ca_modeler_gui.cpp \
  src/ca_modeler/ca_modeler_manager.cpp \
  src/ca_model/ca_model.cpp \
    src/ca_model/graph_node.cpp \
    src/ca_model/neighborhood.cpp \
    src/ca_model/partition.cpp \
    src/ca_modeler/AttributeHandler/attribute_handler_widget.cpp \
    src/ca_modeler/ModelPropertiesHandler/model_properties_handler_widget.cpp \
    src/ca_modeler/ModelPropertiesHandler/model_attr_init_value.cpp \
    src/ca_modeler/ModelPropertiesHandler/break_case_instance.cpp

HEADERS  += \
  src/ca_modeler/ca_modeler_gui.h \
  src/ca_modeler/ca_modeler_manager.h \
  src/ca_model/ca_model.h \
    src/ca_model/graph_node.h \
    src/ca_model/model_properties.h \
    src/ca_model/attribute.h \
    src/ca_model/neighborhood.h \
    src/ca_model/partition.h \
    src/ca_modeler/AttributeHandler/attribute_handler_widget.h \
    src/ca_modeler/ModelPropertiesHandler/model_properties_handler_widget.h \
    src/ca_modeler/ModelPropertiesHandler/model_attr_init_value.h \
    src/ca_model/break_case.h \
    src/ca_modeler/ModelPropertiesHandler/break_case_instance.h

FORMS    += \
  src/ca_modeler/ca_modeler_gui.ui \
    src/ca_modeler/AttributeHandler/attribute_handler_widget.ui \
    src/ca_modeler/ModelPropertiesHandler/model_attr_init_value.ui \
    src/ca_modeler/ModelPropertiesHandler/model_properties_handler_widget.ui \
    src/ca_modeler/ModelPropertiesHandler/break_case_instance.ui
