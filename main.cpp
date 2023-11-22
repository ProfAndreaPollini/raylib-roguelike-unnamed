
#include <iostream>
#if defined(_WIN32)
#define NOGDI  // All GDI defines and routines
#define NOUSER // All USER defines and routines
#endif

#include "spdlog/spdlog.h"

#if defined(_WIN32) // raylib uses these names as function parameters
#undef near
#undef far
#endif

#include "raylib.h"

#include "imgui.h"
#include "rlImGui.h"

#include "Entity.h"
#include "Grid.h"
#include "World.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1600;
    const int screenHeight = 900;

    auto console = spdlog::stdout_color_mt("console");
    console->set_level(spdlog::level::debug);
    console->set_pattern("[multi_sink_example] [%H:%M:%S:%f] [%^%L%$]: %v");

    spdlog::get("console")->info("loggers can be retrieved from a ");

    SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    rlImGuiSetup(true);
    //--------------------------------------------------------------------------------------

    Grid grid{screenWidth, screenHeight, 16, 16};

    auto gridCenter = grid.center();

    World world{&grid};

    auto player = world.CreateEntity();
    // player->SetPosition(world, gridCenter);

    auto playerPosition = IntVector2{gridCenter.x, gridCenter.y};
    // Entity player{16, 16};
    auto cmd = player->SetPosition(playerPosition);
    world.Execute(cmd.get());
    auto enemyPosition = IntVector2{gridCenter.x + 5, gridCenter.y + 5};
    Entity enemy{16, 16, 0.5f, BLUE};
    enemy.SetPosition(enemyPosition);

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        //----------------------------------------------------------------------------------
        auto dt = GetFrameTime();
        player->Update(dt);
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        grid.Draw();
        player->Draw();
        enemy.Draw();

        // start ImGui Conent
        rlImGuiBegin();

        // show ImGui Content
        bool open = true;
        ImGui::ShowDemoWindow(&open);

        // end ImGui Content
        rlImGuiEnd();

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    rlImGuiShutdown();
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}