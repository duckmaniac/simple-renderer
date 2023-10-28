#include "FLY/Application.h"
#include "CubeScene3D.h"

constexpr Size WINDOW_SIZE = {720, 720};
constexpr int FPS_LIMIT = 60;

int WINAPI WinMain(HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow) {
	try {
		Application app("Renderer", WINDOW_SIZE, FPS_LIMIT);

		// Load resources.
		auto icon = app.load_resource<sf::Image>("ID_IMAGE_ICON");

		// Setup window's icon.
		app.set_icon(icon);

		// Setup scene.
		auto sc_main = std::make_shared<CubeScene3D>(CubeScene3D("cube_scene"));
		app.add_scene(sc_main);
		app.load_scene("cube_scene");

		// Start the application.
		app.start();
	}
	catch (const std::exception& e) {
		MessageBox(NULL, e.what(), "Error!", MB_ICONERROR | MB_OK);
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}