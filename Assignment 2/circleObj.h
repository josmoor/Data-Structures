#include <math.h>
#include <rectObj.h>
#include <stdlib.h>
#include <time.h>

class Circle {
    Circle(float center[2], float radius) {
        pos[0] = center[0];
        pos[1] = center[1];
        this->radius = radius;
    }

    private:
        float pos[2];
        float radius;

    public:
        bool isInCircle(float pos[2], float radius) {
            if(this->pos[1] > pos[1]) { // This circle on top
                if(this->pos[0] > pos[0]) { // This circle right
                    if(this->pos[0] - this->radius < pos[0] + radius &&
                        this->pos[1] - this->radius < pos[1] + radius)
                            return true;
                } else { // Other circle right
                    if(this->pos[0] + this-> radius < pos[0] - radius &&
                        this->pos[1] - this->radius < pos[1] + radius)
                            return true;
                }
            } else { // Other circle on top
                if(this->pos[0] > pos[0]) { // This circle right
                    if(this->pos[0] - this->radius < pos[0] + radius &&
                        this->pos[1] + this->radius < pos[1] + radius)
                            return true;
                } else { // Other circle right
                    if(this->pos[0] + this-> radius < pos[0] - radius &&
                        this->pos[1] + this->radius < pos[1] + radius)
                            return true;
                }
            }

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

        int getAngle() {
            int ret = rand() % 179 + 1;

            while(ret == 90)
                ret = rand() % 179 + 1;

            return ret;
        }

        Rectangle getRect() {
            srand(time(NULL));
            int p1Angle = getAngle();
            int p2Angle = getAngle();
            bool[2] Q = {true, true};

            if(p1Angle > 90)
                Q[0] = false;
            if(p2Angle > 90)
                Q[1] = false;

            if(Q[0] && Q[1]) {
                if(Q[0]) { // Q1
                   //TODO: Both points in Q1 
                } else { // Q2
                    //TODO: Both points in Q2
                }
            } else {

            }

            //TODO: Get random point on circle.
            //Q2angle = (90 - angle) + 90
            //Q3angle = 180 + angle
            //Q4angle = 360 - angle
            //TODO: get points on circle
            //TODO: get random length (max of circle point)

            //TODO: store in rect

            return new Rectangle(); //{float[2]}, {float[8]}
        }
};