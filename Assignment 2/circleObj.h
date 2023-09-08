#include <math.h>
#include <rectObj.h>

class Circle {
    Circle(float center[2], float radius) {
        pos[0] = center[0];
        pos[1] = center[1];
        this->radius = radius;
        dis = sqrt((center[0]^2 + center[1]^2));
    }

    private:
        float pos[2];
        float radius;
        float dis;  

    public:
        bool isInCircle(float pos[2], float radius) {
            //TODO: Check if given circle data is within this circle data

            return false;
        }

        void setPosition(float newPos[2]) {
            pos[0] = newPos[0];
            pos[1] = newPos[1];
        }

        void setRadius(float radi) {
            radius = radi;
        }

        float getRadius() { return radius; }
        float getX() { return pos[0]; }
        float getY() { return pos[1]; }
        float getDistance() { return dis; }

        Rectangle getRect() {
            //TODO: Get random point on circle.
            //Q2angle = (90 - angle) + 90
            //Q3angle = 180 + angle
            //Q4angle = 360 - angle
            //TODO: get points on circle
            //TODO: get random length (max of circle point)

            //TODO: store in rect

            return new Rectangle(); //{Center}, {Position}, Length, Width, Radius (circle of all rects)
        }
};