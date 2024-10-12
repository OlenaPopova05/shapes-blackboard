#include "iostream"
#include "Board.h"

Board::Board() : figureID(0), grid(BOARD_HEIGHT, std::vector<char>(BOARD_WIDTH, ' ')) {}

void Board::addFigure(std::unique_ptr<Figure> figure) {
    figure->setID(figureID++);
    figures.push_back(std::move(figure));
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
        if (dynamic_cast<Circle*>(figure.get())) {
            type = "Circle";
        } else if (dynamic_cast<Triangle*>(figure.get())) {
            type = "Triangle";
        } else if (dynamic_cast<Rectangle*>(figure.get())) {
            type = "Rectangle";
        } else if (dynamic_cast<Line*>(figure.get())) {
            type = "Line";
        } else {
            type = "Unknown";
        }
        std::cout << figure->getID() << type << figure->getParameters() << std::endl;
    }
}