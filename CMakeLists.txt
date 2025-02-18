cmake_minimum_required(VERSION 3.30)
project(basic2d_engine)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(SDL2_ttf CONFIG REQUIRED)

add_executable(basic2d_engine src/main.cpp
        src/core/Engine.cpp
        src/core/Engine.h
        src/core/Logger.cpp
        src/core/Logger.h
        src/ecs/Entity.cpp
        src/ecs/Entity.h
        src/ecs/EntityManager.cpp
        src/ecs/EntityManager.h
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

target_link_libraries(basic2d_engine
        PRIVATE
        $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
        $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
)
target_link_libraries(basic2d_engine PRIVATE $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>)
target_link_libraries(basic2d_engine PRIVATE $<IF:$<TARGET_EXISTS:SDL2_ttf::SDL2_ttf>,SDL2_ttf::SDL2_ttf,SDL2_ttf::SDL2_ttf-static>)