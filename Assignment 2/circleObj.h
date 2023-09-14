#ifndef CIRCLE_H
#define CIRCLE_H
#endif

#include <math.h>
#include "rectObj.h"
#include <stdlib.h>
#include <time.h>
#define PI 3.1415926536

class Circle {
    private:
        float pos[2];
        float radius;
        float dis;

    public:
        Circle(float center[2], float radius) {
            pos[0] = center[0];
            pos[1] = center[1];
            this->radius = radius;
        }

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
            pos[0] += newPos[0];
            pos[1] += newPos[1];
        }

        void setRadius(float radi) {
            radius = radi;
        }

        float getRadius() { return radius; }
        float getX() { return pos[0]; }
        float getY() { return pos[1]; }
        float getDistance() { return dis; }
};