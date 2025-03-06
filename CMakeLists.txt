cmake_minimum_required(VERSION 3.16)

project(Q_employer VERSION 0.1 LANGUAGES CXX)

# Active l’automatisation de MOC, UIC et RCC
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Trouver Qt (Widgets + Sql). On recherche d’abord Qt6, puis Qt5 si Qt6 n’est pas disponible.
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql)

# Liste des sources (fichiers .cpp, .h, .ui, .qrc)
set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    connection.cpp
    connection.h
    image_first.qrc
)

# Pour Qt6, on utilise qt_add_executable.
# Pour Qt5 ou si ANDROID, on ajuste la commande selon la version.
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Q_employer
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        employer.h employer.cpp
    )
else()
    if(ANDROID)
        add_library(Q_employer SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(Q_employer
            ${PROJECT_SOURCES}
        )
    endif()
endif()

# Lier notre exécutable à Widgets et Sql
target_link_libraries(Q_employer PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Sql
)

# Options pour le bundle sur macOS/iOS (optionnel, si vous compilez sur d’autres plateformes vous pouvez ignorer)
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Q_employer)
endif()

set_target_properties(Q_employer PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Q_employer
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Finalisation spécifique à Qt6
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Q_employer)
endif()
