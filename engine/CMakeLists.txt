# Create a static or shared library from your engine sources
add_library(basic2d_engine_lib
        src/core/Engine.cpp
        src/core/Logger.cpp
        src/ecs/Entity.cpp
        src/ecs/EntityManager.cpp
        src/ecs/Component.h
        src/ecs/System.h
        src/ecs/components/Transform.h
        src/ecs/components/Sprite.h
        src/ecs/systems/RenderingSystem.cpp
        src/ecs/systems/RenderingSystem.h
        src/ecs/systems/InputSystem.cpp
        src/ecs/systems/InputSystem.h
        src/rendering/Renderer.cpp
        src/rendering/Renderer.h
        src/rendering/TextureManager.cpp
        src/rendering/TextureManager.h
        src/input/InputHandler.cpp
        src/input/InputHandler.h
        src/audio/AudioManager.cpp
        src/audio/AudioManager.h
)

target_link_libraries(basic2d_engine_lib
        PRIVATE
        $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
        $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
        $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>
        $<IF:$<TARGET_EXISTS:SDL2_ttf::SDL2_ttf>,SDL2_ttf::SDL2_ttf,SDL2_ttf::SDL2_ttf-static>
)

add_executable(engine src/main.cpp)
target_link_libraries(engine PRIVATE basic2d_engine_lib)

install(TARGETS engine
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
)
