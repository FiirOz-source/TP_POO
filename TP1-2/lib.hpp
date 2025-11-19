#ifndef LIB_HPP
#define LIB_HPP

#include <iostream>
#include <string>

class figure
{
public:
    virtual ~figure() = default;
    figure();
    virtual float perimeter() = 0;
    virtual void print_characteristics() = 0;
    static int get_nbr_figure() { return nbr_figure; };

private:
    static int nbr_figure;
};

class polygone : public figure
{
public:
    polygone() = default;
    ~polygone();

    void print_characteristics() override;

protected:
    int nb_sides;
};

class rectangle : public polygone
{
public:
    rectangle();
    rectangle(float len, float wid);
    ~rectangle();

    float perimeter() override;

    void set_length(float len);
    void show_length(void);

    void set_width(float wid);
    void show_width(void);

protected:
    float length;
    float width;
};

class square : public rectangle
{
public:
    square();
    square(float size);
    ~square();

    void set_size(float len);
    void show_size(void);

private:
    void set_length(float len);
    void show_length(void);

    void set_width(float wid);
    void show_width(void);
};

class equilateral_triangle : public polygone
{
public:
    equilateral_triangle();
    equilateral_triangle(float sz);
    ~equilateral_triangle();

    float perimeter() override;

    void set_size(float sz);
    void show_size(void);

protected:
    float size;
};

class colorable
{
protected:
    std::string color;

public:
    colorable() = default;
    colorable(std::string col);
    std::string get_color();
    void set_color(std::string col);
};

class circle : public figure, public colorable
{
public:
    circle() = default;
    circle(float rad);
    circle(float rad, std::string col);
    ~circle();

    float perimeter() override;

    void print_characteristics() override;

    void set_radius(float rad);
    void show_radius(void);

protected:
    float radius;
};

#endif // LIB_HPP