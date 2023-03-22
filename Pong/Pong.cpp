
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
        o << "pos: (" << c.x << ", " << c.y << "), direction: " << c.direction << endl;
        return o;
    }
};



int main()
{   
    Ball c(0, 0);


    cout << c;
    c.randomDirection();
    cout << c;
    c.Move();
    cout << c;
    c.randomDirection();
    c.Move();
    cout << c;
    c.randomDirection();
    cout << c;

    return 1;
}
