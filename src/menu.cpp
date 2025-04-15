#include "menu.h"

using namespace std;

GameMode Menu::menu() {
	const int screenWidth = 800;
	const int screenHeight = 600;

	InitWindow(screenWidth, screenHeight, "Snake AI");

	SetTargetFPS(60);

	vector<string> options = {
		"Play Snake (Manual)",
		"Run Snake AI",
		"Exit"
	};

	int selected = -1;

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(BLACK);

		DrawText("Snake AI", screenWidth / 2 - MeasureText("Snake AI", 40) / 2, 50, 40, GREEN);

		for (size_t i = 0; i < options.size(); i++) {
			Rectangle button = {
				static_cast<float>(screenWidth / 2 - 150),
				static_cast<float>(150 + i * 80),
				300,
				50,
			};

			Vector2 mouse = GetMousePosition();
			bool hovered = CheckCollisionPointRec(mouse, button);

			Color btnColor = hovered ? DARKGREEN : GRAY;
			DrawRectangleRec(button, btnColor);
			DrawText(
				options[i].c_str(),
				button.x + 20,
				button.y + 15,
				20,
				WHITE
			);

			if (hovered && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
				selected = static_cast<int>(i);
				break;
			}
		}
		EndDrawing();

		if (selected != -1) break;

	}

	CloseWindow();

	switch (selected) {
		case 0: return GameMode::HUMAN;
		case 1: return GameMode::AI;
		default: return GameMode::EXIT;
	}
	
}
