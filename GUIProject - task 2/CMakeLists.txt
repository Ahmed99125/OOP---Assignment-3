cmake_minimum_required(VERSION 3.23)

project(GUIProject VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(GUIProject
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        BoardGame_Classes.hpp
        collectfourboard.h collectfourboard.cpp
        collectfourplayer.h collectfourplayer.cpp
        fivexfive_gamemanager.h fivexfive_gamemanager.cpp
        fivexfiveboard.h fivexfiveboard.cpp
        fivexfiveplayer.h fivexfiveplayer.cpp
        GameManager.cpp
        Player.cpp
        pyramid_x_o_board.h pyramid_x_o_board.cpp
        pyramid_x_o_player.h pyramid_x_o_player.cpp
        RandomPlayer.cpp
        connectfourgame.h connectfourgame.cpp connectfourgame.ui
        fivexfivegame.h fivexfivegame.cpp fivexfivegame.ui
        pyramidgame.h pyramidgame.cpp pyramidgame.ui
        normalgame.h normalgame.cpp normalgame.ui
        X_O_Board.cpp
        AI_Player.h
        AI_Player.cpp
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET GUIProject APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(GUIProject SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(GUIProject
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(GUIProject PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.GUIProject)
endif()
set_target_properties(GUIProject PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS GUIProject
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(GUIProject)
endif()
