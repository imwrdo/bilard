#pragma once
#include <vector>
#include <SFML/Graphics.hpp> 

using namespace std;
using namespace sf;

class Ball : public Drawable
{
public:
	Ball(float t_X, float t_Y);
	Ball() = default;
	~Ball() = default;
	Ball& operator=(const Ball& other)
	{
		if (this != &other)
		{
			shape = other.shape;
			ballRadius = other.ballRadius;
		}
		return *this;
	}
	static vector <Ball> generateBalls();

	void update();

	float left();
	float right();
	float top();
	float bottom();

private:
	CircleShape shape;
	float ballRadius{ 10.0f };
	float ballVelocity{ 3.0f };
	Vector2f velocity{ ballVelocity, ballVelocity };
	void draw(RenderTarget& target, RenderStates state) const override;
};