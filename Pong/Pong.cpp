
#include <iostream>
using namespace std;


enum Dir {STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6 };

class Ball{
private:
    int x, y;
    int originalX, originalY;
    Dir direction;
public:

    Ball( int posX, int posY ){
        originalX = posX;
        originalY = posY;
        x = posX;
        y = posY;
        direction = STOP;
    }

    void Reset() {
        x = originalX;
        y = originalY;
        direction = STOP;
    }

    void changeDirection(Dir d) {
        direction = d;
    }

    inline int getX() {
        return x;
    }

    inline int getY() {
        return y;
    }
    
    inline Dir getDirection() {
        return direction;
    }

    void randomDirection() {
        direction = (Dir)((rand() % 6) + 1 );

    }
    void Move() {
        switch (direction) {
        case STOP:
            break;
        case LEFT:
            x--;
            break;
        case UPLEFT:
            x--;
            y--;
            break;
        case DOWNLEFT:
            x--;
            y++;
            break;
        case RIGHT:
            x++;
            break;
        case UPRIGHT:
            x++;
            y--;
            break;
        case DOWNRIGHT:
            x++;
            y++;
            break;
        default:
            break;
        }
    }
    friend ostream& operator << (ostream& o, Ball c) {
        o << "Ball pos: (" << c.x << ", " << c.y << "), direction: " << c.direction << endl;
        return o;
    }
};

class Paddle {
private:
    int x, y;
    int originalX, originalY;
public:
    Paddle() {
        x = y = 0;
    }
    Paddle(int posX, int posY) : Paddle() {
        originalX = posX;
        originalY = posY;
        x = posX;
        y = posY;
    }

    inline void Reset() {
        x = originalX;
        y = originalY;
    }

    inline int getX() {
        return x;
    }

    inline int getY() {
        return y;
    }

    inline void moveUp() {
        y--;
    }

    inline void moveDown() {
        y++;
    }

    friend ostream& operator << (ostream& o, Paddle p) {
        o << "Paddle pos: (" << p.x << ", " << p.y << ")" << endl;
        return o;
    }
};


int main()
{   
    Paddle p1(0, 0);
    Paddle p2(10, 0);
    cout << p1;
    cout << p2;
    p1.moveDown();
    p2.moveUp();
    cout << p1;
    cout << p2;


    return 1;
}
