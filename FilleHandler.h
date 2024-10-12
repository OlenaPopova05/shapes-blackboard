#pragma once
#include <string>
#include "Board.h"

class FileHandler {
public:
    static void save(const Board& board, const std::string& file_path);

    static void load(Board& board, const std::string& file_path);
};

