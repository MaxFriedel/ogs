if (Qt5XmlPatterns_FOUND)
    if (Shapelib_FOUND)
        add_executable(ConvertSHPToGLI ConvertSHPToGLI.cpp)
        set_target_properties(ConvertSHPToGLI PROPERTIES FOLDER Utilities)
        target_link_libraries(ConvertSHPToGLI GeoLib Qt5::Xml ${Shapelib_LIBRARIES})
    endif()

    add_executable(FEFLOW2OGS FEFLOW2OGS.cpp)
    set_target_properties(FEFLOW2OGS PROPERTIES FOLDER Utilities)
    target_link_libraries(FEFLOW2OGS ApplicationsFileIO)
endif ()

add_executable(convertGEO convertGEO.cpp)
set_target_properties(convertGEO PROPERTIES FOLDER Utilities)
target_link_libraries(convertGEO GeoLib ApplicationsFileIO)

add_executable(generateMatPropsFromMatID generateMatPropsFromMatID.cpp )
target_link_libraries(generateMatPropsFromMatID MeshLib)
set_target_properties(generateMatPropsFromMatID
    PROPERTIES FOLDER Utilities)

add_executable(GMSH2OGS GMSH2OGS.cpp)
set_target_properties(GMSH2OGS PROPERTIES FOLDER Utilities)
target_link_libraries(GMSH2OGS ApplicationsFileIO)

add_executable(OGS2VTK OGS2VTK.cpp)
set_target_properties(OGS2VTK PROPERTIES FOLDER Utilities)
target_link_libraries(OGS2VTK MeshLib)

add_executable(VTK2OGS VTK2OGS.cpp)
set_target_properties(VTK2OGS PROPERTIES FOLDER Utilities)
target_link_libraries(VTK2OGS MeshLib)

add_executable(VTK2TIN VTK2TIN.cpp)
set_target_properties(VTK2TIN PROPERTIES FOLDER Utilities)
target_link_libraries(VTK2TIN MeshLib)

add_executable(TIN2VTK TIN2VTK.cpp)
set_target_properties(TIN2VTK PROPERTIES FOLDER Utilities)
target_link_libraries(TIN2VTK MeshLib)

add_executable(TecPlotTools TecPlotTools.cpp)
set_target_properties(TecPlotTools PROPERTIES FOLDER Utilities)
target_link_libraries(TecPlotTools GeoLib MeshLib)

add_executable(GocadSGridReader GocadSGridReaderMain.cpp)
set_target_properties(GocadSGridReader PROPERTIES FOLDER Utilities)
target_link_libraries(GocadSGridReader
    GeoLib
    MeshLib
    ApplicationsFileIO
    ${Boost_LIBRARIES}
)

####################
### Installation ###
####################
install(TARGETS generateMatPropsFromMatID GMSH2OGS OGS2VTK VTK2OGS VTK2TIN GocadSGridReader
    RUNTIME DESTINATION bin COMPONENT ogs_converter)

if(Qt5XmlPatterns_FOUND)
    if(Shapelib_FOUND)
        install(TARGETS ConvertSHPToGLI
            RUNTIME DESTINATION bin COMPONENT ogs_converter)
    endif()
    install(TARGETS  FEFLOW2OGS convertGEO
        RUNTIME DESTINATION bin COMPONENT ogs_converter)
endif()

cpack_add_component(ogs_converter
    DISPLAY_NAME "File converter"
    DESCRIPTION "File converter."
    GROUP Utilities
)
