#pragma once

#include "../generated/location.hh"

struct LocationManager {
    yy::location current;

    yy::location last_id;
    yy::location last_assign_id;
    yy::location last_break_continue;

    void initialize(yy::location::filename_type* f);

    void step();
    void move_down(int lines_cnt);
    void move_forward(int token_length);
    void matched_assign();
    void matched_id();
    void matched_break_continue();
};