#include <iostream>
#include <math.h>
#DEFINE PI 3.1415926536

class Rectangle {
    Rectangle(float[2] centerPoint, float[8] points) {
        dis[0] = centerPoint[0];
        dis[1] = centerPoint[1];

        for(int i = 0; i < 8; i++)
            pos[i] = point[i];
    }

    private:
        float dis[2]; // X/Y Position from origin (Center of Rectangle)
        float pos[8]; // {xy,xy,xy,xy}
        float angle[2]; // Min - Max

    public:
        void calcAngle(float radius) {
            int[] xIndex = {0,0};

            for(int i = 2; i < 8; i += 2) {
                if(pos[i] > pos[xIndex[1]])
                    xIndex[1] = i;
                if(pos[i] < pos[xIndex[0]])
                    xIndex[0] = i;
            }

            angle[0] = atan(pos[xIndex[0] + 1] / pos[xIndex[0]]) * 180 / PI;
            angle[1] = atan(pos[xIndex[1] + 1] / pos[xIndex[1]]) * 180 / PI;
        }

        float[] getCenter() { return new float[2] {dis[0], dis[1]}; }
        float[] getPoint(int point) { return new float[2] {pos[point * 2], pos[(point * 2) + 1]}; }
        float[] getMinAngleObscure() { return new float[2] {angle[0], angle[1]}; }
};