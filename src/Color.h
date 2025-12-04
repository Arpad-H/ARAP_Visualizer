//
// Created by Arpad on 12/4/2025.
//

#ifndef ARAP_VISUALIZER_COLOR_H
#define ARAP_VISUALIZER_COLOR_H


class Color
{
    public:
    float R;
    float G;
    float B;

    Color();
    Color( float r, float g, float b);
    Color operator*(const Color& c) const;
    Color operator*(const float Factor) const;
    Color operator+(const Color& c) const;
    Color& operator+=(const Color& c);

};


#endif //ARAP_VISUALIZER_COLOR_H