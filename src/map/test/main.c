#include "map/htable.h"
#include "utils/asserts.h"

int main()
{
        struct htable *ht = &(struct htable){};

        htable_set(ht, "foo", 55);
        ASSERT_EQUAL((int_obj){htable_size(ht)}, (int_obj){1});
        htable_set(ht, "fool", 75);
        ASSERT_EQUAL((int_obj){htable_size(ht)}, (int_obj){2});
        htable_set(ht, "foolish", 105);
        ASSERT_EQUAL((int_obj){htable_size(ht)}, (int_obj){3});
        htable_set(ht, "bar", 69);
        ASSERT_EQUAL((int_obj){htable_size(ht)}, (int_obj){4});

        ASSERT_EQUAL((int_obj){htable_get(ht, "bar")->value}, (int_obj){69});
        ASSERT_TRUE(htable_get(ht, "blaz") == 0);

        htable_delete(ht, "barblabr");
        ASSERT_EQUAL((int_obj){htable_size(ht)}, (int_obj){4});

        htable_delete(ht, "bar");
        ASSERT_EQUAL((int_obj){htable_size(ht)}, (int_obj){3});
        ASSERT_TRUE(htable_get(ht, "bar") == 0);

        htable_set(ht, "alice", 25);
        htable_set(ht, "bob", 30);
        htable_set(ht, "carol", 28);
        htable_set(ht, "dave", 35);
        htable_set(ht, "eve", 22);

        ASSERT_EQUAL((int_obj){htable_get(ht, "alice")->value}, (int_obj){25});
        ASSERT_EQUAL((int_obj){htable_get(ht, "bob")->value}, (int_obj){30});

        htable_set(ht, "alice", 26);
        ASSERT_EQUAL((int_obj){htable_get(ht, "alice")->value}, (int_obj){26});

        htable_delete(ht, "carol");
        ASSERT_TRUE(htable_get(ht, "carol") == 0);

        htable_delete(ht, "zoe");
        ASSERT_TRUE(htable_get(ht, "zoe") == 0);
}
