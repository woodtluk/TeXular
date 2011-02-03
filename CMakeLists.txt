 # set project's name

  PROJECT(TeXular)
  cmake_minimum_required(VERSION 2.8)

  SET(CMAKE_BUILD_TYPE Release)

  # enable warnings
  #ADD_DEFINITIONS( -c -g -Wall -frtti -fexceptions -mthreads -enable-stdcall-fixup -Wl,-enable-auto-import -Wl,-enable-runtime-pseudo-reloc)
  #SET(CMAKE_CXX_FLAGS "-Wall")
  ADD_DEFINITIONS( -Wall )


  # enable warnings
  IF(CMAKE_COMPILER_IS_GNUCXX )
    ADD_DEFINITIONS( -g -Wall )
  ENDIF(CMAKE_COMPILER_IS_GNUCXX )

   if(CMAKE_CONFIGURATION_TYPES)
     set(CMAKE_CONFIGURATION_TYPES Debug Release DebugMX31 ReleaseMX31)
     set(CMAKE_CONFIGURATION_TYPES "${CMAKE_CONFIGURATION_TYPES}" CACHE STRING
       "Reset the configurations to what we need"
       FORCE)
   endif()


  # this command finds Qt4 libraries and sets all required variables
  # note that it's Qt4, not QT4 or qt4
  FIND_PACKAGE( Qt4 REQUIRED )

  # add some useful macros and variables
  # (QT_USE_FILE is a variable defined by FIND_PACKAGE( Qt4 ) that contains a path to CMake script)
  INCLUDE( ${QT_USE_FILE} )


  # by default only QtCore and QtGui modules are enabled
  # other modules must be enabled like this:
  # SET( #QT_USE_QTXML                 TRUE
       # QT_USE_QTASSISTANT           TRUE
        # QT_USE_QAXCONTAINER         TRUE
        # QT_USE_QAXSERVER            TRUE
        # QT_USE_QTDESIGNER           TRUE
        # QT_USE_QTMOTIF              TRUE
        #QT_USE_QTMAIN               TRUE
        # QT_USE_QTNETWORK          TRUE
        # QT_USE_QTNSPLUGIN         TRUE
        # QT_USE_QTOPENGL         TRUE
        # QT_USE_QTSQL          TRUE
        # QT_USE_QTXML          TRUE
        # QT_USE_QTSVG          TRUE
        #QT_USE_QTTEST         TRUE
        #QT_USE_QTUITOOLS          TRUE
       #  QT_USE_QTDBUS         TRUE
        # QT_USE_QTSCRIPT         TRUE
        # QT_USE_QTASSISTANTCLIENT          TRUE
        # QT_USE_QTHELP         TRUE
        # QT_USE_QTWEBKIT         TRUE
        # QT_USE_QTXMLPATTERNS          TRUE
        # QT_USE_PHONON         TRUE
  #)

  # This sets the windows build that will need the special winmain@16 call. Qt provides
  #  this for us in the qtmain.lib file. Using this cmake code will ensure we have it
  #  linked into our build. Not needed on Unix/OS X/Linux which is why we have the
  #  IF(WIN32) conditional.
  IF (WIN32)
      SET (QT_USE_QTMAIN TRUE)
  ENDIF (WIN32)

  # with SET() command you can change variables or define new ones
  # here we define TEXULAR_SRCS variable that contains a list of all .cpp files
  # note that we don't need \ at the end of line
  SET( TEXULAR_SRCS
        ./src/main.cpp
       	./src/MainWindow.cpp
        ./src/TableModel.cpp
        ./src/CsvParser.cpp
  )

  # another list, this time it includes all header files that should be treated with moc
  SET( TEXULAR_MOC_HDRS
        ./src/MainWindow.h
        ./src/TableModel.h
        ./src/CsvParser.h
  )

  # some .ui files
  SET( TEXULAR_UIS
       ./ui/MainWindow.ui
  )

  # and finally an resource file
  SET( TEXULAR_RCS

  )


  # and finally this will run moc:
  QT4_WRAP_CPP( TEXULAR_MOC_SRCS ${TEXULAR_MOC_HDRS} )

  # this will run uic on .ui files:
  QT4_WRAP_UI( TEXULAR_UI_HDRS ${TEXULAR_UIS} )

  # this command will generate rules that will run rcc on all files from TEXULAR_RCS
  # in result TEXULAR_RC_SRCS variable will contain paths to files produced by rcc
  QT4_ADD_RESOURCES( TEXULAR_RC_SRCS ${TEXULAR_RCS} )


  # we need this to be able to include headers produced by uic in our code
  # (CMAKE_BINARY_DIR holds a path to the build directory, while INCLUDE_DIRECTORIES() works just like INCLUDEPATH from qmake)
  INCLUDE_DIRECTORIES( ${CMAKE_BINARY_DIR} )

  # here we instruct CMake to build TEXULARexecutable from all of the source files
  ADD_EXECUTABLE( TeXular WIN32 ${TEXULAR_SRCS} ${TEXULAR_MOC_SRCS} ${TEXULAR_RC_SRCS} ${TEXULAR_UI_HDRS} )

  # last thing we have to do is to tell CMake what libraries our executable needs,
  # luckily FIND_PACKAGE prepared QT_LIBRARIES variable for us:
  TARGET_LINK_LIBRARIES( TeXular ${QT_LIBRARIES} )

  #INSTALL_TARGETS( /bin TeXular)



