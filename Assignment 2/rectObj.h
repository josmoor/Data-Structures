#include <iostream>
#include <math.h>
#define PI 3.1415926536

class Rectangle {
    private:
        float dis[2]; // X/Y Position from origin (Center of Rectangle)
        float pos[8]; // {xy,xy,xy,xy}
        float angle[2]; // Min - Max

        int getAngle() {
            int ret = rand() % 179 + 1;

            while(ret == 90)
                ret = rand() % 179 + 1;

            return ret;
        }

        void setPoints(float radius) {
            srand(time(NULL));
            float points[8];
            int p1Angle = getAngle();
            int p2Angle = getAngle();

            for(int i = 0; i < 8; i++) {
                points[i] = pos[i % 2] + (radius * ((i % 2 == 0 ? cos((i < 2 || i > 5 ? (i > 5 ? p1Angle + 180 : p1Angle) : (i > 3 ? p2Angle + 180 : p2Angle))) : sin(i < 2 || i > 5 ? (i > 5 ? p1Angle + 180 : p1Angle) : (i > 3 ? p2Angle + 180 : p2Angle))) * (i < 4 ? 1 : 180 / PI) * (pos[i % 2] > 0 ? 1 : -1)));
            }

            // ret[0] = pos[0] + radius * (cos(p1Angle) * 180 / PI);
            // ret[1] = pos[1] + radius * (sin(p1Angle) * 180 / PI);
            // ret[2] = pos[0] + radius * (cos(p2Angle) * 180 / PI);
            // ret[3] = pos[1] + radius * (sin(p2Angle) * 180 / PI);
            // ret[4] = pos[0] + radius * (cos(p2Angle + 180) * 180 / PI);
            // ret[5] = pos[1] + radius * (sin(p2Angle + 180) * 180 / PI);
            // ret[6] = pos[0] + radius * (cos(p1Angle + 180) * 180 / PI);
            // ret[7] = pos[1] + radius * (sin(p1Angle + 180) * 180 / PI);
        }

    public:
        Rectangle(float centerPointX, float centerPointY, float radius) {
            dis[0] = centerPointX;
            dis[1] = centerPointY;

            setPoints(radius);
            calcAngle(radius);
        }

        void calcAngle(float radius) {
            int xIndex[] = {0,0};

            for(int i = 2; i < 8; i += 2) {
                if(pos[i] > pos[xIndex[1]])
                    xIndex[1] = i;
                if(pos[i] < pos[xIndex[0]])
                    xIndex[0] = i;
            }

            angle[0] = atan(pos[xIndex[0] + 1] / pos[xIndex[0]]) * 180 / PI;
            angle[1] = atan(pos[xIndex[1] + 1] / pos[xIndex[1]]) * 180 / PI;
        }

        float getCenterX() { return dis[0]; }
        float getCenterY() { return dis[1]; }
        float getPointX(int point) { return pos[point * 2]; }
        float getPointY(int point) { return pos[point * 2] + 1; }
        float getMinAngle() { return angle[0]; }
        float getMaxAngle() { return angle[1]; }
};