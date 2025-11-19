#ifndef LIB_HPP
#define LIB_HPP

#include <iostream>

class figure
{
public:
    virtual ~figure() = default;
    virtual float perimeter() = 0;
    virtual void print_characteristics() = 0;
};

class polygone : public figure
{
public:
    polygone() = default;
    ~polygone() override;

    void print_characteristics() override;

protected:
    int nb_sides;
};

class rectangle : public polygone
{
public:
    rectangle();
    rectangle(float len, float wid);
    ~rectangle() override;

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
    ~square() override;

    void set_size(float len);
    void show_size(void);

private:
};

#endif // LIB_HPP