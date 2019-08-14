#include "header.h"

void checkMove(t_player *player, char* mass, int width) {
    check_y(player, mass, width);
    check_x(player, mass, width);
}
