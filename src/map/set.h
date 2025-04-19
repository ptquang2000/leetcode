#ifndef SET_H
#define SET_H

struct set {
        size_t size;
        int **data;
        size_t *len;
        size_t nr;
};

void set_clear(struct set *set);
size_t set_size(struct set *set);
bool set_in(struct set *set, int k);
int set_pop(struct set *set);
void set_remove(struct set *set, int k);
void set_add(struct set *set, int k);

#endif
