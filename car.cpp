#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#define WIDTH 1280
#define HEIGHT 720
using namespace sf;

template <typename T1>
class Environment
{
public:
	RectangleShape *sky;
	RectangleShape *surface;
	CircleShape *sun;
	Environment()
	{
		sky = new RectangleShape;
		sky->setFillColor(Color::Cyan);
		sky->setSize(Vector2f(WIDTH, HEIGHT));

		surface = new RectangleShape;
		surface->setFillColor(Color(0x5E, 0x2C, 0x04));
		surface->setOutlineThickness(0x15);
		surface->setOutlineColor(Color(0x0, 0x0, 0x0));
		surface->setSize(Vector2f(WIDTH, 0x78));

		sun = new CircleShape;
		sun->setFillColor(Color(0xFF, 0xFF, 0x0));
		sun->setOutlineThickness(0x5);
		sun->setOutlineColor(Color(0x0, 0x0, 0x0));
		sun->setRadius(0x23);
	}
};

template <typename T2>
class Car : private Environment<int>
{
public:
	ConvexShape *layout;
	CircleShape *wheel[0x2];
	RectangleShape *window[0x2];
	Color transparent;
	Car()
	{
		transparent = sky->getFillColor();
		layout = new ConvexShape;
		layout->setPointCount(0x6);
		layout->setFillColor(Color(0x0, 0xAA, 0x0));
		layout->setOutlineThickness(0x7);
		layout->setOutlineColor(Color(0x0, 0x0, 0x0));
		for (int i = 0x0; i < 0x2; i++)
		{
			wheel[i] = new CircleShape;
			wheel[i]->setPointCount(0x45);
			wheel[i]->setRadius(0x3C);
			wheel[i]->setFillColor(Color(0x88, 0x88, 0x88));
			wheel[i]->setOutlineThickness(0xF);
			wheel[i]->setOutlineColor(Color(0x0, 0x0, 0x0));

			window[i] = new RectangleShape;
			window[i]->setSize(Vector2f(0x96, 0x55));
			window[i]->setFillColor(transparent);
			window[i]->setOutlineThickness(0x7);
			window[i]->setOutlineColor(Color(0x0, 0x0, 0x0));
		}

	}
	~Car()
	{
		for (int i = 0x0; i < 0x2; i++)
		{
			delete wheel[i];
			delete window[i];
		}
	}
};

int main(int argc, char** argv)
{
	RenderWindow scene(VideoMode(WIDTH, HEIGHT), "Midjorney v2");

	Environment<int> * World = nullptr;
	World = new Environment<int>();
	Car<int> * Niwa = nullptr;
	Niwa = new Car<int>();

	World->surface->setPosition(Vector2f(0x0, HEIGHT - (HEIGHT / 0x6)));
	World->sun->move(Vector2f(0x32, 0x32));

	Niwa->layout->setPoint(0x0, Vector2f(0x8A, 0x20C));
	Niwa->layout->setPoint(0x1, Vector2f(0xBE, 0x18A));
	Niwa->layout->setPoint(0x2, Vector2f(0x285, 0x188));
	Niwa->layout->setPoint(0x3, Vector2f(0x29E, 0xE3));
	Niwa->layout->setPoint(0x4, Vector2f(0x492, 0xEE));
	Niwa->layout->setPoint(0x5, Vector2f(0x4B0, 0x217));

	Niwa->wheel[0x0]->setPosition(0x113, 0x1EA);
	Niwa->wheel[0x1]->setPosition(0x378, 0x1F4);

	Niwa->window[0x0]->setPosition(0x2D0, 0x126);
	Niwa->window[0x1]->setPosition(0x3CF, 0x126);

	while (scene.isOpen())
	{
		Event event;
		while (scene.pollEvent(event))
		{
			if (event.type == Event::Closed)
				scene.close();
		}
		scene.draw(*World->sky);
		scene.draw(*World->sun);
		scene.draw(*World->surface);
		scene.draw(*Niwa->layout);
		scene.draw(*Niwa->wheel[0x0]);
		scene.draw(*Niwa->wheel[0x1]);
		scene.draw(*Niwa->window[0x0]);
		scene.draw(*Niwa->window[0x1]);
		scene.display();
	}
	return 0;
}