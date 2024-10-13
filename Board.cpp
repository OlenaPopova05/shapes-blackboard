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
            c = '~';
        }
    }
}

void Board::drawBoard() const {
    std::vector<std::vector<char>> board = grid;
    for (const auto& figure : figures) {
        figure.second->draw(board);
    }
    for (const auto& row : board) {
        for (char c : row) {
            std::cout << c;
        }
        std::cout << std::endl;
    }
}

void Board::listFigures() const {
    for (const auto& figure : figures) {
        std::string type;
        if (dynamic_cast<Circle*>(figure.second.get())) {
            type = "circle";
        } else if (dynamic_cast<Triangle*>(figure.second.get())) {
            type = "triangle";
        } else if (dynamic_cast<Rectangle*>(figure.second.get())) {
            type = "rectangle";
        } else if (dynamic_cast<Line*>(figure.second.get())) {
            type = "line";
        } else {
            type = "unknown";
        }
        std::cout << figure.first << " " << type << figure.second->getParameters() << std::endl;
    }
}

std::vector<std::vector<char>>& Board::getGrid() {
    return grid;
}