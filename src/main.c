#include "config/autoconf.h"

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

int main()
{
        // Array

#ifdef CONFIG_APPLY_PERMUTATION
        test_array_string_applyPermutation();
#endif
#ifdef CONFIG_BUY_AND_SELL_STOCK_ONCE
        test_array_string_buyAndSellStockOnce();
#endif
#ifdef CONFIG_BUY_AND_SELL_STOCK_TWICE
        test_array_string_buyAndSellStockTwice();
#endif
#ifdef CONFIG_CAN_REACH_END
        test_array_string_canReachEnd();
#endif
#ifdef CONFIG_DELETE_DUPLICATES
        test_array_string_deleteDuplicates();
#endif
#ifdef CONFIG_DUTCH_FLAG_PARTITION
        test_array_string_dutchFlagPartition();
#endif
#ifdef CONFIG_GENERATE_PRIMES
        test_array_string_generatePrimes();
#endif
#ifdef CONFIG_MULTIPLY
        test_array_string_multiply();
#endif
#ifdef CONFIG_NEXT_PERMUTATION
        test_array_string_nextPermutation();
#endif
#ifdef CONFIG_PLUS_ONE
        test_array_string_plusOne();
#endif
#ifdef CONFIG_IS_VALID_SUDOKU
        test_array_string_isValidSudoku();
#endif
#ifdef CONFIG_MATRIX_IN_SPIRAL_ORDER
        test_array_string_matrixInSpiralOrder();
#endif
#ifdef CONFIG_ROTATE_MATRIX
        test_array_string_rotateMatrix();
#endif
#ifdef CONFIG_GENERATE_PASCAL_TRIANGLE
        test_array_string_generatePascalTriangle();
#endif

        // String

#ifdef CONFIG_CONVERT_BASE
        test_array_string_convertBase();
#endif
#ifdef CONFIG_INT_TO_STRING
        test_array_string_intToString();
#endif
#ifdef CONFIG_IS_PALINDROME
        test_array_string_isPalindrome();
#endif
#ifdef CONFIG_LOOK_AND_SAY
        test_array_string_lookAndSay();
#endif
#ifdef CONFIG_RABIN_KARP
        test_array_string_rabinKarp();
#endif
#ifdef CONFIG_REPLACE_AND_REMOVE
        test_array_string_replaceAndRemove();
#endif
#ifdef CONFIG_REVERSE_WORDS
        test_array_string_reverseWords();
#endif
#ifdef CONFIG_ROMAN_TO_INTEGER
        test_array_string_romanToInteger();
#endif
#ifdef CONFIG_SNAKE_STRING
        test_array_string_snakeString();
#endif
#ifdef CONFIG_SPREADSHEET_DECODE_COLUMN_ID
        test_array_string_spreadsheetDecodeColumnID();
#endif
#ifdef CONFIG_STRING_DECODING
        test_array_string_stringDecoding();
#endif
#ifdef CONFIG_STRING_ENCODING
        test_array_string_stringEncoding();
#endif
#ifdef CONFIG_STRING_TO_INT
        test_array_string_stringToInt();
#endif

        // Array String

#ifdef CONFIG_MERGE
        test_array_string_merge();
#endif
#ifdef CONFIG_REMOVE_ELEMENT
        test_array_string_removeElement();
#endif

        // Binary tree

#ifdef CONFIG_CREATE_LIST_OF_LEAVES
        test_binary_tree_create_list_of_leaves();
#endif
#ifdef CONFIG_FIND_KTH_NODE_BINARY_TREE
        test_binary_tree_find_kth_node_binary_tree();
#endif
#ifdef CONFIG_FROM_PREORDER_INORDER
        test_binary_tree_from_preorder_inorder();
#endif
#ifdef CONFIG_HAS_PATH_SUM
        test_binary_tree_has_path_sum();
#endif
#ifdef CONFIG_INORDER_TRAVERSAL
        test_binary_tree_inorder_traversal();
#endif
#ifdef CONFIG_IS_BALANCED_BINARY_TREE
        test_binary_tree_is_balanced_binary_tree();
#endif
#ifdef CONFIG_IS_SYMMETRIC
        test_binary_tree_is_symmetric();
#endif
#ifdef CONFIG_LOWEST_COMMON_ANCESTOR
        test_binary_tree_lowest_common_ancestor();
#endif
#ifdef CONFIG_PREORDER_TRAVERSAL
        test_binary_tree_preorder_traversal();
#endif
#ifdef CONFIG_RECONSTRUCT_PREORDER
        test_binary_tree_reconstruct_preorder();
#endif
#ifdef CONFIG_SUM_ROOT_TO_LEAVE
        test_binary_tree_sum_root_to_leave();
#endif

        // Linked list

#ifdef CONFIG_ADD_TWO_NUMBERS
        test_linked_list_addTwoNumbers();
#endif
#ifdef CONFIG_CYCLICALLY_RIGHT_SHIFT_LIST
        test_linked_list_cyclicallyRightShiftList();
#endif
#ifdef CONFIG_DELETION_FROM_LIST
        test_linked_list_deletionFromList();
#endif
#ifdef CONFIG_EVEN_ODD_MERGE
        test_linked_list_evenOddMerge();
#endif
#ifdef CONFIG_HAS_CYCLE
        test_linked_list_hasCycle();
#endif
#ifdef CONFIG_IS_LINKED_LIST_A_PALINDROME
        test_linked_list_isLinkedListAPalindrome();
#endif
#ifdef CONFIG_LIST_PIVOTING
        test_linked_list_listPivoting();
#endif
#ifdef CONFIG_MERGE_TWO_SORTED_LISTS
        test_linked_list_mergeTwoSortedLists();
#endif
#ifdef CONFIG_OVERLAPPING_LISTS
        test_linked_list_overlappingLists();
#endif
#ifdef CONFIG_OVERLAPPING_NO_CYCLE_LISTS
        test_linked_list_overlappingNoCycleLists();
#endif
#ifdef CONFIG_REMOVE_DUPLICATES
        test_linked_list_removeDuplicates();
#endif
#ifdef CONFIG_REMOVE_KTH_LAST
        test_linked_list_removeKthLast();
#endif
#ifdef CONFIG_REVERSE_SUBLIST
        test_linked_list_reverseSublist();
#endif

        // Recursion

#ifdef CONFIG_COMBINATIONS
        test_recursion_combinations();
#endif
#ifdef CONFIG_GENERATE_BALANCED_PARENTHESES
        test_recursion_generate_balanced_parentheses();
#endif
#ifdef CONFIG_GENERATE_POWER_SET
        test_recursion_generate_power_set();
#endif
#ifdef CONFIG_N_QUEENS
        test_recursion_n_queens();
#endif
#ifdef CONFIG_PERMUTATIONS
        test_recursion_permutations();
#endif
#ifdef CONFIG_SOLVE_SUDOKU
        test_recursion_solve_sudoku();
#endif

        // Stack

#ifdef CONFIG_EVALUATE
        test_stack_evaluate();
#endif
#ifdef CONFIG_EXAMINE_BUILDING_WITH_SUNSET
        test_stack_examine_building_with_sunset();
#endif
#ifdef CONFIG_IS_WELL_FORMED
        test_stack_is_well_formed();
#endif
#ifdef CONFIG_SHORTEST_EQUIVALENT_PATH
        test_stack_shortest_equivalent_path();
#endif

        // Heap
#ifdef CONFIG_MERGE_SORTED_ARRAYS
        test_heap_merge_sorted_arrays();
#endif
#ifdef CONFIG_SORT_K_INCREASING_DECREASING_ARRAY
        test_heap_sort_k_increasing_decreasing_array();
#endif
#ifdef CONFIG_FIND_CLOSEST_K_STARS
        test_heap_find_closest_k_stars();
#endif
#ifdef CONFIG_SORT_APPROXIMATELY_SORTED_ARRAY
        test_heap_sort_approximately_sorted_array();
#endif
#ifdef CONFIG_ONLINE_MEDIAN
        test_heap_online_median();
#endif
#ifdef CONFIG_K_LARGEST_IN_BINARY_HEAP
        test_heap_k_largest_in_binary_heap();
#endif

        // DSA

#ifdef CONFIG_BINARY_SEARCH
        test_dsa_binary_search();
#endif
#ifdef CONFIG_BST_DFS
        test_dsa_bst_dfs();
#endif
#ifdef CONFIG_BT_BFS
        test_dsa_bt_bfs();
#endif
#ifdef CONFIG_BT_IN_ORDER
        test_dsa_bt_in_order();
#endif
#ifdef CONFIG_BT_POST_ORDER
        test_dsa_bt_post_order();
#endif
#ifdef CONFIG_BT_PRE_ORDER
        test_dsa_bt_pre_order();
#endif
#ifdef CONFIG_BUBBLE_SORT
        test_dsa_bubble_sort();
#endif
#ifdef CONFIG_COMPARE
        test_dsa_compare();
#endif
#ifdef CONFIG_DOUBLY_LINKED_LIST
        test_dsa_doubly_linked_list();
#endif
#ifdef CONFIG_LINEAR_SEARCH
        test_dsa_linear_search();
#endif
#ifdef CONFIG_MAZE_SOLVER
        test_dsa_solve();
#endif
#ifdef CONFIG_DSA_QUEUE
        test_dsa_queue();
#endif
#ifdef CONFIG_MIN_HEAP
        test_dsa_min_heap();
#endif
#ifdef CONFIG_QUICK_SORT
        test_dsa_quick_sort();
#endif
#ifdef CONFIG_DSA_STACK
        test_dsa_stack();
#endif
#ifdef CONFIG_TWO_CRYSTAL_BALLS
        test_dsa_two_crystal_balls();
#endif
#ifdef CONFIG_GRAPH_LIST_DFS
        test_dsa_graph_list_dfs();
#endif
#ifdef CONFIG_GRAPH_MATRIX_BFS
        test_dsa_graph_matrix_bfs();
#endif
#ifdef CONFIG_DIJKSTRA_LIST
        test_dsa_dijkstra_list();
#endif

        // Graph

#ifdef CONFIG_FILLED_SURROUNDED_REGION
        test_graph_filled_surrounded_region();
#endif
#ifdef CONFIG_FLIP_COLOR
        test_graph_flip_color();
#endif
#ifdef CONFIG_SEARCH_MAZE
        test_graph_search_maze();
#endif
}
