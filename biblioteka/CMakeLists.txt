cmake_minimum_required(VERSION 3.4)
project(Biblioteka)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/blok.cpp
    src/klucz.cpp
	  src/funkcje.cpp)

add_library(Biblioteka ${SOURCE_FILES})

#dolacz katalog z plikami naglowkowymi include z projektu biblioteka do sciezek
target_include_directories(Biblioteka PUBLIC include)

#Sekcja testów
#find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
 #       ${Boost_INCLUDE_DIRS}
)

#set(SOURCE_TEST_HUMAN_FILES
 #       test/master.cpp
  #      test/HumanTest.cpp)

#add_executable (TestHuman ${SOURCE_TEST_HUMAN_FILES})

#target_link_libraries (TestHuman
 #       Biblioteka
  #      ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
   #     )

#set(SOURCE_TEST_MONSTER_FILES
 #       test/master.cpp
  #      test/MonsterTest.cpp)

#add_executable (TestMonster ${SOURCE_TEST_MONSTER_FILES})

#target_link_libraries (TestMonster
#        Biblioteka
 #       ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
  #      )

enable_testing()
#add_test(TestBiblioteki1 TestHuman
 #       --report_level=detailed
  #      --log_level=all
   #     --color_output=yes
     #   )
#add_test(NAME TestBiblioteki2 COMMAND TestMonster
 #       --report_level=detailed
  #      --log_level=all
   #     --color_output=yes
    #    )

#add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
 #       ${CMAKE_CTEST_COMMAND} -C $<CONFIG> --verbose
  #      WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
