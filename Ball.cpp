#include "Ball.h"

#include <vector>
#include <iostream>


using namespace std;

Ball::Ball(float t_X, float t_Y)
{
    shape.setPosition(t_X, t_Y);
    shape.setRadius(this->ballRadius);
    shape.setFillColor(Color::Blue);
    shape.setOrigin(this->ballRadius, this->ballRadius);
}

void Ball::draw(RenderTarget& target, RenderStates state) const
{
    target.draw(this->shape, state);
}

//Metoda rysujaca poczatkowe ustawienie bil
vector<Ball> Ball::generateBalls() {
    vector<Ball> balls;
    float radius = 10.f;
    float x = 650.f - 3 * radius;
    float y = 270.f - 3 * radius;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j <= i; j++) {
            Ball ball(x + 2 * i * radius, y + 2 * j * radius);
            balls.push_back(ball);
            cout << x + 2 * i * radius << "  " << y + 2 * j * radius << "  " << i << "  " << j << endl;
        }
        y -= radius;
    }
    return balls;
}

//Metoda ruchu bili 
void Ball::update()
{
    velocity *= 0.998f;
    shape.move(this->velocity);

    if (this->left() < 200.f)
    {
        velocity.x = ballVelocity;
    }
    else if (this->right() > 770.f)
    {
        velocity.x = -ballVelocity;
    }

    if (this->top() < 100.f)
    {
        velocity.y = ballVelocity;
    }
    else if (this->bottom() > 385.f)
    {
        velocity.y = -ballVelocity;
    }
    /*if (ballVelocity < 0.1f) {
        ballVelocity = 0;
        velocity = Vector2f{ 0.f, 0.f };
    }*/
}

float Ball::left()
{
    return this->shape.getPosition().x - shape.getRadius();
}

float Ball::right()
{
    return this->shape.getPosition().x + shape.getRadius();
}

float Ball::top()
{
    return this->shape.getPosition().y - shape.getRadius();
}

float Ball::bottom()
{
    return this->shape.getPosition().y + shape.getRadius();
}
