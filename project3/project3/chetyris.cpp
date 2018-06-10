#include "Game.h"

const int WELL_WIDTH  = 10;
const int WELL_HEIGHT = 18;


//inheritance & polymorphism  queue for falling pieces, recursion for FoamBomb
//circular linked list for piece orientation
int main()
{
    Game g(WELL_WIDTH, WELL_HEIGHT);
    g.play();
}

#include "Piece.h"
#include <random>

PieceType chooseRandomPieceType()
{
    static std::random_device aRandomDevice;
    static std::default_random_engine generator(aRandomDevice());
    std::uniform_int_distribution<> distro(0, NUM_PIECE_TYPES-1);
    return static_cast<PieceType>(distro(generator));
}
