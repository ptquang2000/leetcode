#include "set.h"

static size_t __hash_int(int k)
{
        return k * 2654435761u;
}

static struct set __set_new(size_t nr)
{
        struct set *set = &(struct set){};

        set->nr = nr;

        set->len = malloc(set->nr * sizeof *set->len);
        memset(set->len, 0, set->nr * sizeof *set->len);

        set->data = malloc(set->nr * sizeof *set->data);
        memset(set->data, 0, set->nr * sizeof *set->data);

        return set[0];
}

static void __set_rehash(struct set *set)
{
        size_t nr = set->nr ? set->nr * 1.5 : 5;
        struct set other = __set_new(nr);

        for (int **r = &set->data[0]; r < &set->data[set->nr]; r++) {
                size_t len = set->len[r - &set->data[0]];
                for (int *c = &r[0][0]; c < &r[0][len]; c++)
                        set_add(&other, c[0]);
                free(r[0]);
        }

        free(set->len);
        free(set->data);
        memcpy(set, &other, sizeof *set);
}

static int *__set_iter(int *nodes, size_t len, int k)
{
        for (int *n = &nodes[0]; n < &nodes[len]; n++) {
                if (k == n[0])
                        return n;
        }
        return 0;
}

void set_add(struct set *set, int k)
{
        if (set->size >= set->nr * 0.7)
                __set_rehash(set);

        size_t hash = __hash_int(k);
        size_t idx = hash % set->nr;

        int *added = __set_iter(&set->data[idx][0], set->len[idx], k);
        if (added)
                return;

        set->len[idx]++;
        set->data[idx] = realloc(set->data[idx], set->len[idx] * sizeof *set->data[idx]);
        set->data[idx][set->len[idx] - 1] = k;

        set->size++;
}

void set_remove(struct set *set, int k)
{
        if (!set->size)
                return;

        size_t hash = __hash_int(k);
        size_t idx = hash % set->nr;
        if (!set->len[idx])
                return;

        int *added = __set_iter(&set->data[idx][0], set->len[idx], k);
        if (!added)
                return;

        int cnt = &set->data[idx][set->len[idx]] - (added + 1);
        memmove(added, added + 1, cnt * sizeof *added);
        set->len[idx]--;
        set->data[idx] = realloc(set->data[idx], set->len[idx] * sizeof *set->data[idx]);

        set->size--;
}

int set_pop(struct set *set)
{
        for (int **r = &set->data[0]; r < &set->data[set->nr]; r++) {
                size_t len = set->len[r - &set->data[0]];
                for (int *c = &r[0][0]; c < &r[0][len]; c++) {
                        int k = c[0];
                        set_remove(set, k);
                        return k;
                }
        }
        return 0;
}

bool set_in(struct set *set, int k)
{
        if (!set->size)
                return false;

        size_t idx = __hash_int(k) % set->nr;
        if (!set->len[idx])
                return false;

        if (!__set_iter(&set->data[idx][0], set->len[idx], k))
                return false;

        return true;
}

size_t set_size(struct set *set)
{
        return set->size;
}

void set_clear(struct set *set)
{
        for (int **r = &set->data[0]; r < &set->data[set->nr]; r++)
                free(r[0]);
        free(set->len);
        free(set->data);
        set[0] = (struct set){};
}
