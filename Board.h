#pragma once
#include <vector>
#include "Figure.h"

class Board {
private:
    int figureID;
    std::vector<std::vector<char>> grid;
    std::vector<std::unique_ptr<Figure>> figures;

public:
    Board();

    void addFigure(std::unique_ptr<Figure> shape);

    void removeLastFigure();

    void clearBoard();

    void drawBoard() const;

    void listFigures() const;
};
