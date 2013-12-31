#ifndef INPUT_H
#define INPUT_H

void input_init();
void input_update();

bool key_hit(int key);
bool key_down(int key);
void flush_keys();

bool mouse_hit(int key);
bool mouse_down(int key);
void flush_mouse();
int get_mouse_x();
int get_mouse_y();
#endif
