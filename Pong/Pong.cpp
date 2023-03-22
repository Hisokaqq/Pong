
#include <iostream>

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
};



int main()
{
    return 1;
}
