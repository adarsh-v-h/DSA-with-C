#ifndef C_UTILS_H
#define C_UTILS_H

void getInt(int *data);
void *safeAllo(int size);
void *parent_node(void *head, void *target);
void *parent_pos(void *head, int pos);
#endif