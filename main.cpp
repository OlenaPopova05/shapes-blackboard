#include "Board.h"
#include "Figure.h"

int main() {
    Board board;

    std::unique_ptr<Figure> triangle = std::make_unique<Triangle>(10, 10, 5);
    std::unique_ptr<Figure> circle = std::make_unique<Circle>(7, 30, 5);
    std::unique_ptr<Figure> rectangle = std::make_unique<Rectangle>(2, 5, 5, 5);
    std::unique_ptr<Figure> line = std::make_unique<Line>(2, 1, 10, 10);

    triangle->draw(board.getGrid());
    circle->draw(board.getGrid());
    rectangle->draw(board.getGrid());
    line->draw(board.getGrid());

    board.drawBoard();
    return 0;
}
