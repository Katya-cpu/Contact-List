cmake_minimum_required(VERSION 3.16)

project(kurss VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

qt_add_executable(appkurss
    main.cpp
    contactmodel.cpp
    contactmodel.h
)

qt_add_qml_module(appkurss
    URI kurss
    VERSION 1.0
    QML_FILES
        Main.qml
        ContactDelegate.ui.qml
        ContactDialog.qml
        ContactForm.ui.qml
        ContactList.qml
        ContactView.ui.qml
        SectionDelegate.ui.qml
    RESOURCES
        resources.qrc
        default-avatar.png
    SOURCES
        contactmodel.h contactmodel.cpp
        SOURCES contactfiltermodel.h contactfiltermodel.cpp
)

set_target_properties(appkurss PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appkurss
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appkurss
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
