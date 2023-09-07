#include <math.h>
#include <rectObj.h>

class Circle {
    private:
        float pos[2];
        float radius;

    public:
        bool isInCircle(float pos[2], bool top) {
            if(top) { // If other circle is above
                for(int i = 0; i < 180; i++) {
                    float tempPos[2];
                    tempPos[0] = this->pos[0] + (radius * sin(i));
                    tempPos[1] = this->pos[1] + (radius * cos(i));

                    if(tempPos[0] == pos[0] && tempPos[1] == pos[1])
                        return true;
                }
            } else {
                for(int i = 180; i < 360; i++) {
                    float tempPos[2];
                    tempPos[0] = this->pos[0] + (radius * sin(i));
                    tempPos[1] = this->pos[1] +  (radius * cos(i));

                    if(tempPos[0] == pos[0] && tempPos[1] == pos[1])
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

        Rectangle getRect() {
            Rectangle rect;

            //TODO: Get random point on circle.
            //Q2angle = (90 - angle) + 90
            //Q3angle = 180 + angle
            //Q4angle = 360 - angle
            //TODO: get points on circle
            //TODO: get random length (max of circle point)
            //TODO: get obscure angle of origin

            //TODO: store in rect

            return rect;
        }
};