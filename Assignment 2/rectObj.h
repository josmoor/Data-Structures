#include <iostream>
#include <math.h>

class Rectangle {
    Rectangle(float[2] centerPoint, float[8] points, float[2] dimensions, float radius) {
        dis[0] = centerPoint[0];
        dis[1] = centerPoint[1];
        height[0] = dimensions[0];
        height[1] = dimensions[1];

        for(int i = 0; i < 8; i++)
            pos[i] = point[i];

        calcAngle(radius);
    }

    private:
        float dis[2]; // X/Y Position from origin (Center of Rectangle)
        float pos[8]; // {xy,xy,xy,xy}
        float height[2]; // Length - Height
        float angle[2]; // Min - Max

        void calcAngle(float radius) {
            int[] xIndex = {0,0};

            for(int i = 2; i < 8; i += 2) {
                if(pos[i] > pos[xIndex[1]])
                    xIndex[1] = i;
                if(pos[i] < pos[xIndex[0]])
                    xIndex[0] = i;
            }

            // angle[0] = ARCtan(pos[xIndex[0] + 1] / pos[xIndex[0]]) - Min Angle
            // angle[1] = ARCtan(pos[xIndex[1] + 1] / pos[xIndex[1]]) - Max angle
        }

    public:
        float[] getCenter() { return new float[2] {dis[0], dis[1]}; }
        float[] getPoint(int point) { return new float[2] {pos[point * 2], pos[(point * 2) + 1]}; }
        float[] getDimensions() { return new float[2] {height[0], height[1]}; }
        float[] getMinAngleObscure() { return new float[2] {angle[0], angle[1]}; }
};