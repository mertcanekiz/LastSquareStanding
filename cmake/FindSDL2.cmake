SET( SDL2_SEARCH_PATHS
  ${SDL2_ROOT_DIR}# SDL2!
  ./lib/SDL2
  $ENV{PROGRAMFILES}/SDL2# WINDOWS
  "$ENV{PROGRAMFILES(X86)}/SDL2"# WINDOWS
  ~/Library/Frameworks# MAC
  /Library/Frameworks# MAC
  /usr/local# LINUX/MAC/UNIX
  /usr# LINUX/MAC/UNIX
  /opt# LINUX/MAC/UNIX
  /sw# Fink
  /opt/local# DarwinPorts
  /opt/csw# Blastwave
)

FIND_PATH( SDL2_INCLUDE_DIRS
  NAMES
  SDL.h SDL2/SDL.h SDL_image.h SDL2/SDL_image.h
  PATHS
  ${SDL2_SEARCH_PATHS}
  PATH_SUFFIXES
  include
  DOC
  "The directory where SDL.h resides"
)

FIND_LIBRARY( SDL2_LIBRARIES
  NAMES
  SDL2 SDL2main SDL2_image
  PATHS
  ${SDL2_SEARCH_PATHS}
  PATH_SUFFIXES
  lib
  lib64
  lib/x86
  lib/x64
  DOC
  "The SDL2 library"
)


IF ( SDL2_INCLUDE_DIRS AND SDL2_LIBRARIES )
  SET( SDL2_FOUND TRUE )
  MESSAGE(STATUS "Looking for SDL2 - found")
ELSE ( SDL2_INCLUDE_DIRS AND SDL2_LIBRARIES )
  SET( SDL2_FOUND FALSE )
  MESSAGE(STATUS "Looking for SDL2 - not found")
ENDIF ( SDL2_INCLUDE_DIRS AND SDL2_LIBRARIES )