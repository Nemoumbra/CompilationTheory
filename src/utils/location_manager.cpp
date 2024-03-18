#include "location_manager.hh"

void LocationManager::initialize(yy::location::filename_type* f) {
    current.initialize(f);
    last_id.initialize(f);
    last_assign_id.initialize(f);
}

void LocationManager::step() {
    current.step();
}
void LocationManager::move_down(int lines_cnt) {
    current.lines(lines_cnt);
}
void LocationManager::move_forward(int token_length) {
    current.columns(token_length);
}



// The following functions are deprecated

void LocationManager::matched_assign() {
    last_assign_id = last_id;
}
void LocationManager::matched_id() {
    last_id = current;
}
void LocationManager::matched_break_continue() {
    last_break_continue = current;
}
void LocationManager::matched_assert() {
    last_assert = current;
}