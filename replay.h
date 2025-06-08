#ifndef REPLAY_H
#define REPLAY_H

void save_move(char piece, int x, int y, char name[]);
char** load_replay(char name[]);
void play_replay();

#endif