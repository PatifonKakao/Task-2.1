# задаем набор исходников
set(SOURCES_LIB
sin.h
sin.cpp
)

# Включение экспорта всех символов для создания динамической библиотеки
set ( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON )

# создаем динамическую библиотеку
add_library(sin_shared_lib SHARED ${SOURCES_LIB})

# добавлем путь к исходникам для возожности подключения библиотеки
target_include_directories(sin_shared_lib PUBLIC ${SRC_ROOT_DIR})

# группируем исходники по типу по категориям
source_group(TREE ${CMAKE_CURRENT_LIST_DIR} FILES ${SOURCES_LIB})

# В solution эта библиотека лежит в simple_project
set_property(TARGET sin_shared_lib PROPERTY FOLDER "sin_shared_lib")

# включаем в сборку проекnа подпроект с тестами
add_subdirectory(tests)