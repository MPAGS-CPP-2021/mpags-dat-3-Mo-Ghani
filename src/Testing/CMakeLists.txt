# sub-scripts for testing of MPAGSCipher library

# testHello executable settings
add_executable(testHello testHello.cpp)
add_test(NAME test-hello COMMAND testHello)

# testCatch executable settings
add_executable(testCatch testCatch.cpp)
target_include_directories(testCatch PRIVATE $(CMAKE_CURRENT_LIST_DIR))
add_test(NAME test-catch COMMAND testCatch)

# testTransformChar test settings
add_executable(testTransformChar testTransformChar.cpp)
target_include_directories(testTransformChar PRIVATE $(CMAKE_CURRENT_LIST_DIR))
target_link_libraries(testTransformChar MPAGSCipher)
add_test(NAME test-transformchar COMMAND testTransformChar)

# testTransformChar test settings
add_executable(testProcessCommandLine testProcessCommandLine.cpp)
target_include_directories(testProcessCommandLine PRIVATE $(CMAKE_CURRENT_LIST_DIR))
target_link_libraries(testProcessCommandLine MPAGSCipher)
add_test(NAME test-processcommandline COMMAND testProcessCommandLine)

# testCaesarCipher test settings
add_executable(testCaesarCipher testCaesarCipher.cpp)
target_include_directories(testCaesarCipher PRIVATE $(CMAKE_CURRENT_LIST_DIR))
target_link_libraries(testCaesarCipher MPAGSCipher)
add_test(NAME test-caesarcipher COMMAND testCaesarCipher)
