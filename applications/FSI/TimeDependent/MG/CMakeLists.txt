CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(FSI_TIME_DEPENDENT_ML)

SET(MAIN_FILE "fsiTimeDepMG")
SET(EXEC_FILE "fsitimedepMG")

femusMacroBuildApplication(${MAIN_FILE} ${EXEC_FILE})

FILE(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/save/)

