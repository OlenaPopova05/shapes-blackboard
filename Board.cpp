#include "iostream"
#include "Board.h"

Board::Board() : figureID(0), grid(BOARD_HEIGHT, std::vector<char>(BOARD_WIDTH, '~')) {}

void Board::addFigure(std::unique_ptr<Figure> figure) {
    figures.push_back(std::make_pair(figureID++, std::move(figure)));
}

void Board::removeLastFigure() {
    if (!figures.empty()) {
        figures.pop_back();
    }
}

void Board::clearBoard() {
    figures.clear();
    for (auto& row : grid) {
        for (char& c : row) {
            c = ' ';
        }
    }
}

void Board::drawBoard() const {
    for (const auto& row : grid) {
        for (char c : row) {
            std::cout << c;
        }
        std::cout << "\n";
    }
}

void Board::listFigures() const {
    for (const auto& figure : figures) {
        std::string type;
        if (dynamic_cast<Circle*>(figure.second.get())) {
            type = "Circle";
        } else if (dynamic_cast<Triangle*>(figure.second.get())) {
            type = "Triangle";
        } else if (dynamic_cast<Rectangle*>(figure.second.get())) {
            type = "Rectangle";
        } else if (dynamic_cast<Line*>(figure.second.get())) {
            type = "Line";
        } else {
            type = "Unknown";
        }
        std::cout << figure.first << type << figure.second->getParameters() << std::endl;
    }
}

std::vector<std::vector<char>>& Board::getGrid() {
    return grid;
}