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

        htable_delete(ht, "foolish");
        htable_delete(ht, "fool");
        htable_delete(ht, "foo");
        ASSERT_EQUAL((int_obj){htable_size(ht)}, (int_obj){0});

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

        htable_delete(ht, "alice");
        htable_delete(ht, "bob");
        htable_delete(ht, "carol");
        htable_delete(ht, "dave");
        htable_delete(ht, "eve");
        ASSERT_EQUAL((int_obj){htable_size(ht)}, (int_obj){0});
        free_array(ht->data, ht->nr);
        free(ht->len);

        ht = &(struct htable){};
        htable_set(ht, "apple", 10);
        ASSERT_EQUAL((int_obj){htable_get(ht, "apple")->value}, (int_obj){10});
        htable_set(ht, "apple", 20);
        ASSERT_EQUAL((int_obj){htable_get(ht, "apple")->value}, (int_obj){20});
        htable_set(ht, "banana", 30);
        htable_set(ht, "cherry", 40);
        ASSERT_EQUAL((int_obj){htable_get(ht, "banana")->value}, (int_obj){30});
        ASSERT_EQUAL((int_obj){htable_get(ht, "cherry")->value}, (int_obj){40});
        htable_delete(ht, "banana");
        ASSERT_TRUE(htable_get(ht, "banana") == 0);
        htable_delete(ht, "nonexistent");
        ASSERT_TRUE(htable_get(ht, "nothing") == 0);
        htable_set(ht, "Aa", 100);
        htable_set(ht, "BB", 200);
        ASSERT_EQUAL((int_obj){htable_get(ht, "Aa")->value}, (int_obj){100});
        ASSERT_EQUAL((int_obj){htable_get(ht, "BB")->value}, (int_obj){200});
        htable_set(ht, "aa", 300);
        htable_set(ht, "bB", 400);
        ASSERT_EQUAL((int_obj){htable_get(ht, "aa")->value}, (int_obj){300});
        ASSERT_EQUAL((int_obj){htable_get(ht, "bB")->value}, (int_obj){400});
        htable_set(ht, "", 55);
        ASSERT_EQUAL((int_obj){htable_get(ht, "")->value}, (int_obj){55});

        htable_delete(ht, "apple");
        htable_delete(ht, "banana");
        htable_delete(ht, "cherry");
        htable_delete(ht, "nonexistent");
        htable_delete(ht, "nothing");
        htable_delete(ht, "Aa");
        htable_delete(ht, "BB");
        htable_delete(ht, "aa");
        htable_delete(ht, "bB");
        htable_delete(ht, "");
        ASSERT_EQUAL((int_obj){htable_size(ht)}, (int_obj){0});
        free_array(ht->data, ht->nr);
        free(ht->len);
}
