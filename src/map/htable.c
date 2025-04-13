#include "htable.h"

static size_t __hash_str(const char *s)
{
        size_t hash = 5381;
        for (const char *i = &s[0]; i[0] != 0; i++)
                hash = ((hash << 5) + hash) * i[0];
        return hash;
}

static struct htable __htable_new(size_t nr)
{
        struct htable *ht = &(struct htable){};

        ht->nr = nr;

        ht->len = malloc(ht->nr * sizeof *ht->len);
        memset(ht->len, 0, ht->nr * sizeof *ht->len);

        ht->data = malloc(ht->nr * sizeof *ht->data);
        memset(ht->data, 0, ht->nr * sizeof *ht->data);

        return ht[0];
}

static void __htable_rehash(struct htable *ht)
{
        size_t nr = ht->nr ? ht->nr * 1.5 : 5;
        struct htable other = __htable_new(nr);

        for (struct htable_node **r = &ht->data[0]; r < &ht->data[ht->nr]; r++) {
                size_t len = ht->len[r - &ht->data[0]];
                for (struct htable_node *c = &r[0][0]; c < &r[0][len]; c++)
                        htable_set(&other, c[0].key, c[0].value);
                free(r[0]);
        }

        free(ht->len);
        free(ht->data);
        memcpy(ht, &other, sizeof *ht);
}

static struct htable_node *__htable_node(struct htable_node *nodes, size_t len, const char *k)
{
        for (struct htable_node *n = &nodes[0]; n < &nodes[len]; n++) {
                if (strcmp(k, n->key))
                        continue;
                return n;
        }
        return 0;
}

struct htable_node *htable_set(struct htable *ht, const char *k, int v)
{
        if (ht->size >= ht->nr * 0.7)
                __htable_rehash(ht);

        size_t hash = __hash_str(k);
        size_t idx = hash % ht->nr;

        struct htable_node *added = __htable_node(&ht->data[idx][0], ht->len[idx], k);
        if (added) {
                added->value = v;
                return added;
        }

        ht->len[idx]++;
        ht->data[idx] = realloc(ht->data[idx], ht->len[idx] * sizeof *ht->data[idx]);
        ht->data[idx][ht->len[idx] - 1] = (struct htable_node){.key = k, .value = v};

        ht->size++;
        return &ht->data[idx][ht->len[idx] - 1];
}

void htable_delete(struct htable *ht, const char *k)
{
        if (!ht->size)
                return;

        size_t hash = __hash_str(k);
        size_t idx = hash % ht->nr;
        if (!ht->len[idx])
                return;

        struct htable_node *added = __htable_node(&ht->data[idx][0], ht->len[idx], k);
        if (!added)
                return;

        int cnt = &ht->data[idx][ht->len[idx]] - (added + 1);
        memmove(added, added + 1, cnt * sizeof *added);
        ht->len[idx]--;
        ht->data[idx] = realloc(ht->data[idx], ht->len[idx] * sizeof *ht->data[idx]);

        ht->size--;
}

struct htable_node *htable_get(struct htable *ht, const char *k)
{
        if (!ht->size)
                return 0;

        size_t hash = __hash_str(k);
        size_t idx = hash % ht->nr;
        if (!ht->len[idx])
                return 0;

        struct htable_node *added = __htable_node(&ht->data[idx][0], ht->len[idx], k);
        return added;
}

size_t htable_size(struct htable *ht)
{
        return ht->size;
}
