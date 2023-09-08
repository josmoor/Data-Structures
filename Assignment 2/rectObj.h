#include <iostream>

class Rectangle {
    Rectangle(float centerPoint[2], float startPoint[2], float length, float width, float radius) {
        dis = centerPoint;
        pos = startPoint;
        height[0] = length;
        height[1] = width;

        calcAngle(radius);
    }

    private:
        float dis[2]; // X/Y Position from origin (Center of Rectangle)
        float pos[2]; // X - Y
        float height[2]; // Length - Height
        float angle[2]; // Min - Max

        void calcAngle(float radius) {
            // TODO: Calculate the min/max angle
        }

    public:
        void setDistance(float x, float y) {
            dis[0] = x;
            dis[1] = y;
        }

        void setPosition(float x, float y) {
            pos[0] = x;
            pos[1] = y;
        }

        void setHeight(float l, float h) {
            height[0] = l;
            height[1] = h;
        }
        void setAngle(float min, float max) {
            angle[0] = min;
            angle[1] = max;
        }

        float getCenterX() { return dis[0]; }
        float getCenterY() { return dis[1]; }
        float getPointX() { return pos[0]; }
        float getPointY() { return pos[1]; }
        float getLength() { return height[0]; }
        float getWidth() { return height[1]; }
        float getMinAngleObscure() { return angle[0]; }
        float getMaxAngleObscure() { return angle[1]; }
};