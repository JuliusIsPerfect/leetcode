# 获取所有cpp文件
file(GLOB SOURCES "*.cpp")

# 为每个源文件生成一个可执行文件
foreach(source ${SOURCES})
    # 获取源文件的名称
    get_filename_component(name ${source} NAME_WE)
    # 添加一个新的可执行文件
    add_executable(${name} ${source})
endforeach()