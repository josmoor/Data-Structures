#include <iostream>

class Rectangle {
    private:
        float dis[2]; // X/Y Position from origin (Center of Rectangle)
        float pos[2]; // X - Y
        float height[2]; // Length - Height
        float angle[2]; // Min - Max

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
};