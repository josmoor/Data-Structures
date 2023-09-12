#include <math.h>
#include <rectObj.h>
#include <stdlib.h>
#include <time.h>
#DEFINE PI 3.1415926536

class Circle {
    Circle(float center[2], float radius) {
        pos[0] = center[0];
        pos[1] = center[1];
        this->radius = radius;
    }

    private:
        float pos[2];
        float radius;
        float dis;  

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
        float getDistance() { return dis; }

        int getAngle() {
            int ret = rand() % 179 + 1;

            while(ret == 90)
                ret = rand() % 179 + 1;

            return ret;
        }

        float[] setPoints(int p1Angle, int p2Angle) {
            float[8] ret;

            for(int i = 0; i < 8; i++) {
                ret[i] = pos[i % 2] + (radius * ((i % 2 == 0 ? cos((i < 2 || i > 5 ? p1Angle : p2Angle)) : sin(i < 2 || i > 5 ? p1Angle : p2Angle)) * (i < 4 ? 1 : 180 / PI) * (pos[i % 2] > 0 ? 1 : -1));
            }

            // ret[0] = pos[0] + radius * (cos(p1Angle) * 180 / PI);
            // ret[1] = pos[1] + radius * (sin(p1Angle) * 180 / PI);
            // ret[2] = pos[0] + radius * (cos(p2Angle) * 180 / PI);
            // ret[3] = pos[1] + radius * (sin(p2Angle) * 180 / PI);
            // ret[4] = pos[0] + radius * (cos(p2Angle + 180) * 180 / PI);
            // ret[5] = pos[1] + radius * (sin(p2Angle + 180) * 180 / PI);
            // ret[6] = pos[0] + radius * (cos(p1Angle + 180) * 180 / PI);
            // ret[7] = pos[1] + radius * (sin(p1Angle + 180) * 180 / PI);

            return ret;
        }

        Rectangle getRect() {
            srand(time(NULL));

            return new Rectangle(pos,setPoints(getAngle(), getAngle())); //{float[2]}, {float[8]}
        }
};