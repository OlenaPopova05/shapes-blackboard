#pragma once
#include <string>
#include <vector>

class Figure {
private:
    int id;
public:
    Figure(int id = 1) : id(id) {};

    virtual ~Figure() = default;

    virtual void draw(std::vector<std::vector<char>>& board) const = 0;

    virtual std::string getParameters() const = 0;;

    int getID();

    void setID(int id);
};


class Circle : public Figure {
private:
    int x, y;
    int radius;
public:
    Circle(int id, int x, int y, int radius);

    void draw(std::vector<std::vector<char>>& board) const override;

    std::string getParameters() const override;
};

class Triangle : public Figure {
private:
    int x, y;
    int height;
public:
    Triangle(int id, int x, int y, int height);

    void draw(std::vector<std::vector<char>>& board) const override;

    std::string getParameters() const override;
};

class Rectangle : public Figure {
private:
    int x, y;
    int width, height;
public:
    Rectangle(int id, int x, int y, int width, int height);

    void draw(std::vector<std::vector<char>>& board) const override;

    std::string getParameters() const override;
};

class Line : public Figure {
private:
    int x1, y1;
    int x2, y2;
public:
    Line(int id, int x1, int y1, int x2, int y2);

    void draw(std::vector<std::vector<char>>& board) const override;

    std::string getParameters() const override;
};
