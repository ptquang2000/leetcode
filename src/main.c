#include "config/autoconf.h"
#include "utils/logger.h"

#ifdef CONFIG_DSA
#include "dsa/dsa.h"
#endif
#ifdef CONFIG_ARRAY_STRING
#include "array_string/array_string.h"
#endif
#ifdef CONFIG_BINARY_TREE
#include "binary_tree/binary_tree.h"
#endif
#ifdef CONFIG_LINKED_LIST
#include "linked_list/linked_list.h"
#endif
#ifdef CONFIG_RECURSION
#include "recursion/recursion.h"
#endif
#ifdef CONFIG_STACK
#include "stack/stack.h"
#endif
#ifdef CONFIG_HEAP
#include "heap/heap.h"
#endif
#ifdef CONFIG_GRAPH
#include "graph/graph.h"
#endif
#ifdef CONFIG_MAP
#include "map/map.h"
#endif
#ifdef CONFIG_BITWISE
#include "bitwise/bitwise.h"
#endif

#define TEST(func)                                                                                                     \
        test_##func();                                                                                                 \
        printf(".");

int main()
{
        // Array

#ifdef CONFIG_APPLY_PERMUTATION
        TEST(array_string_applyPermutation);
#endif
#ifdef CONFIG_BUY_AND_SELL_STOCK_ONCE
        TEST(array_string_buyAndSellStockOnce);
#endif
#ifdef CONFIG_BUY_AND_SELL_STOCK_TWICE
        TEST(array_string_buyAndSellStockTwice);
#endif
#ifdef CONFIG_CAN_REACH_END
        TEST(array_string_canReachEnd);
#endif
#ifdef CONFIG_DELETE_DUPLICATES
        TEST(array_string_deleteDuplicates);
#endif
#ifdef CONFIG_DUTCH_FLAG_PARTITION
        TEST(array_string_dutchFlagPartition);
#endif
#ifdef CONFIG_GENERATE_PRIMES
        TEST(array_string_generatePrimes);
#endif
#ifdef CONFIG_MULTIPLY
        TEST(array_string_multiply);
#endif
#ifdef CONFIG_NEXT_PERMUTATION
        TEST(array_string_nextPermutation);
#endif
#ifdef CONFIG_PLUS_ONE
        TEST(array_string_plusOne);
#endif
#ifdef CONFIG_IS_VALID_SUDOKU
        TEST(array_string_isValidSudoku);
#endif
#ifdef CONFIG_MATRIX_IN_SPIRAL_ORDER
        TEST(array_string_matrixInSpiralOrder);
#endif
#ifdef CONFIG_ROTATE_MATRIX
        TEST(array_string_rotateMatrix);
#endif
#ifdef CONFIG_GENERATE_PASCAL_TRIANGLE
        TEST(array_string_generatePascalTriangle);
#endif

        // String

#ifdef CONFIG_CONVERT_BASE
        TEST(array_string_convertBase);
#endif
#ifdef CONFIG_INT_TO_STRING
        TEST(array_string_intToString);
#endif
#ifdef CONFIG_IS_PALINDROME
        TEST(array_string_isPalindrome);
#endif
#ifdef CONFIG_LOOK_AND_SAY
        TEST(array_string_lookAndSay);
#endif
#ifdef CONFIG_RABIN_KARP
        TEST(array_string_rabinKarp);
#endif
#ifdef CONFIG_REPLACE_AND_REMOVE
        TEST(array_string_replaceAndRemove);
#endif
#ifdef CONFIG_REVERSE_WORDS
        TEST(array_string_reverseWords);
#endif
#ifdef CONFIG_ROMAN_TO_INTEGER
        TEST(array_string_romanToInteger);
#endif
#ifdef CONFIG_SNAKE_STRING
        TEST(array_string_snakeString);
#endif
#ifdef CONFIG_SPREADSHEET_DECODE_COLUMN_ID
        TEST(array_string_spreadsheetDecodeColumnID);
#endif
#ifdef CONFIG_STRING_DECODING
        TEST(array_string_stringDecoding);
#endif
#ifdef CONFIG_STRING_ENCODING
        TEST(array_string_stringEncoding);
#endif
#ifdef CONFIG_STRING_TO_INT
        TEST(array_string_stringToInt);
#endif

        // Array String

#ifdef CONFIG_MERGE
        TEST(array_string_merge);
#endif
#ifdef CONFIG_REMOVE_ELEMENT
        TEST(array_string_removeElement);
#endif

        // Binary tree

#ifdef CONFIG_CREATE_LIST_OF_LEAVES
        TEST(binary_tree_create_list_of_leaves);
#endif
#ifdef CONFIG_FIND_KTH_NODE_BINARY_TREE
        TEST(binary_tree_find_kth_node_binary_tree);
#endif
#ifdef CONFIG_FROM_PREORDER_INORDER
        TEST(binary_tree_from_preorder_inorder);
#endif
#ifdef CONFIG_HAS_PATH_SUM
        TEST(binary_tree_has_path_sum);
#endif
#ifdef CONFIG_INORDER_TRAVERSAL
        TEST(binary_tree_inorder_traversal);
#endif
#ifdef CONFIG_IS_BALANCED_BINARY_TREE
        TEST(binary_tree_is_balanced_binary_tree);
#endif
#ifdef CONFIG_IS_SYMMETRIC
        TEST(binary_tree_is_symmetric);
#endif
#ifdef CONFIG_LOWEST_COMMON_ANCESTOR
        TEST(binary_tree_lowest_common_ancestor);
#endif
#ifdef CONFIG_PREORDER_TRAVERSAL
        TEST(binary_tree_preorder_traversal);
#endif
#ifdef CONFIG_RECONSTRUCT_PREORDER
        TEST(binary_tree_reconstruct_preorder);
#endif
#ifdef CONFIG_SUM_ROOT_TO_LEAVE
        TEST(binary_tree_sum_root_to_leave);
#endif

        // Linked list

#ifdef CONFIG_ADD_TWO_NUMBERS
        TEST(linked_list_addTwoNumbers);
#endif
#ifdef CONFIG_CYCLICALLY_RIGHT_SHIFT_LIST
        TEST(linked_list_cyclicallyRightShiftList);
#endif
#ifdef CONFIG_DELETION_FROM_LIST
        TEST(linked_list_deletionFromList);
#endif
#ifdef CONFIG_EVEN_ODD_MERGE
        TEST(linked_list_evenOddMerge);
#endif
#ifdef CONFIG_HAS_CYCLE
        TEST(linked_list_hasCycle);
#endif
#ifdef CONFIG_IS_LINKED_LIST_A_PALINDROME
        TEST(linked_list_isLinkedListAPalindrome);
#endif
#ifdef CONFIG_LIST_PIVOTING
        TEST(linked_list_listPivoting);
#endif
#ifdef CONFIG_MERGE_TWO_SORTED_LISTS
        TEST(linked_list_mergeTwoSortedLists);
#endif
#ifdef CONFIG_OVERLAPPING_LISTS
        TEST(linked_list_overlappingLists);
#endif
#ifdef CONFIG_OVERLAPPING_NO_CYCLE_LISTS
        TEST(linked_list_overlappingNoCycleLists);
#endif
#ifdef CONFIG_REMOVE_DUPLICATES
        TEST(linked_list_removeDuplicates);
#endif
#ifdef CONFIG_REMOVE_KTH_LAST
        TEST(linked_list_removeKthLast);
#endif
#ifdef CONFIG_REVERSE_SUBLIST
        TEST(linked_list_reverseSublist);
#endif

        // Recursion

#ifdef CONFIG_COMBINATIONS
        TEST(recursion_combinations);
#endif
#ifdef CONFIG_GENERATE_BALANCED_PARENTHESES
        TEST(recursion_generate_balanced_parentheses);
#endif
#ifdef CONFIG_GENERATE_POWER_SET
        TEST(recursion_generate_power_set);
#endif
#ifdef CONFIG_N_QUEENS
        TEST(recursion_n_queens);
#endif
#ifdef CONFIG_PERMUTATIONS
        TEST(recursion_permutations);
#endif
#ifdef CONFIG_SOLVE_SUDOKU
        TEST(recursion_solve_sudoku);
#endif

        // Stack

#ifdef CONFIG_EVALUATE
        TEST(stack_evaluate);
#endif
#ifdef CONFIG_EXAMINE_BUILDING_WITH_SUNSET
        TEST(stack_examine_building_with_sunset);
#endif
#ifdef CONFIG_IS_WELL_FORMED
        TEST(stack_is_well_formed);
#endif
#ifdef CONFIG_SHORTEST_EQUIVALENT_PATH
        TEST(stack_shortest_equivalent_path);
#endif

        // Heap
#ifdef CONFIG_MERGE_SORTED_ARRAYS
        TEST(heap_merge_sorted_arrays);
#endif
#ifdef CONFIG_SORT_K_INCREASING_DECREASING_ARRAY
        TEST(heap_sort_k_increasing_decreasing_array);
#endif
#ifdef CONFIG_FIND_CLOSEST_K_STARS
        TEST(heap_find_closest_k_stars);
#endif
#ifdef CONFIG_SORT_APPROXIMATELY_SORTED_ARRAY
        TEST(heap_sort_approximately_sorted_array);
#endif
#ifdef CONFIG_ONLINE_MEDIAN
        TEST(heap_online_median);
#endif
#ifdef CONFIG_K_LARGEST_IN_BINARY_HEAP
        TEST(heap_k_largest_in_binary_heap);
#endif

        // DSA

#ifdef CONFIG_BINARY_SEARCH
        TEST(dsa_binary_search);
#endif
#ifdef CONFIG_BST_DFS
        TEST(dsa_bst_dfs);
#endif
#ifdef CONFIG_BT_BFS
        TEST(dsa_bt_bfs);
#endif
#ifdef CONFIG_BT_IN_ORDER
        TEST(dsa_bt_in_order);
#endif
#ifdef CONFIG_BT_POST_ORDER
        TEST(dsa_bt_post_order);
#endif
#ifdef CONFIG_BT_PRE_ORDER
        TEST(dsa_bt_pre_order);
#endif
#ifdef CONFIG_BUBBLE_SORT
        TEST(dsa_bubble_sort);
#endif
#ifdef CONFIG_COMPARE
        TEST(dsa_compare);
#endif
#ifdef CONFIG_DOUBLY_LINKED_LIST
        TEST(dsa_doubly_linked_list);
#endif
#ifdef CONFIG_LINEAR_SEARCH
        TEST(dsa_linear_search);
#endif
#ifdef CONFIG_MAZE_SOLVER
        TEST(dsa_solve);
#endif
#ifdef CONFIG_DSA_QUEUE
        TEST(dsa_queue);
#endif
#ifdef CONFIG_MIN_HEAP
        TEST(dsa_min_heap);
#endif
#ifdef CONFIG_QUICK_SORT
        TEST(dsa_quick_sort);
#endif
#ifdef CONFIG_DSA_STACK
        TEST(dsa_stack);
#endif
#ifdef CONFIG_TWO_CRYSTAL_BALLS
        TEST(dsa_two_crystal_balls);
#endif
#ifdef CONFIG_GRAPH_LIST_DFS
        TEST(dsa_graph_list_dfs);
#endif
#ifdef CONFIG_GRAPH_MATRIX_BFS
        TEST(dsa_graph_matrix_bfs);
#endif
#ifdef CONFIG_DIJKSTRA_LIST
        TEST(dsa_dijkstra_list);
#endif

        // Graph

#ifdef CONFIG_FILLED_SURROUNDED_REGION
        TEST(graph_filled_surrounded_region);
#endif
#ifdef CONFIG_FLIP_COLOR
        TEST(graph_flip_color);
#endif
#ifdef CONFIG_SEARCH_MAZE
        TEST(graph_search_maze);
#endif

        // Maps

#ifdef CONFIG_CAN_PERFORM_PALINDROME
        TEST(map_can_perform_palindrome);
#endif
#ifdef CONFIG_FIND_ALL_SUBSTRINGS
        TEST(map_find_all_substrings);
#endif
#ifdef CONFIG_FIND_NEAREST_REPETITION
        TEST(map_find_nearest_repetition);
#endif
#ifdef CONFIG_FIND_SMALLEST_SEQUENTIALLY_COVERING_SET
        TEST(map_find_smallest_sequentially_covering_set);
#endif
#ifdef CONFIG_FIND_SMALLEST_SUBARRAY_COVERING_SET
        TEST(map_find_smallest_subarray_covering_set);
#endif
#ifdef CONFIG_IS_LETTER_CONSTRUCTIBLE_FROM_MAGAZINE
        TEST(map_is_letter_constructible_from_magazine);
#endif
#ifdef CONFIG_LONGEST_CONTAINED_RANGE
        TEST(map_longest_contained_range);
#endif
#ifdef CONFIG_LONGEST_SUBARRAY_WITH_DISTINCT_ENTRIES
        TEST(map_longest_subarray_with_distinct_entries);
#endif
#ifdef CONFIG_test_map_COLLATZ_CONJECTURE
        TEST(map_test_collatz_conjecture);
#endif

        // Bit manipulation

#ifdef CONFIG_ADD_BINARY
        TEST(bitwise_add_binary);
#endif
#ifdef CONFIG_HAMMING_WEIGHT
        TEST(bitwise_hamming_weight);
#endif
#ifdef CONFIG_RANGE_BITWISE_AND
        TEST(bitwise_range_bitwise_and);
#endif
#ifdef CONFIG_REVERSE_BITS
        TEST(bitwise_reverse_bits);
#endif
#ifdef CONFIG_SINGLE_NUMBER
        TEST(bitwise_single_number);
#endif
#ifdef CONFIG_single_number_2
        TEST(bitwise_single_number_2);
#endif

        printf("\n");
}
