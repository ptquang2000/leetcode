TYPE = "type"
DEF = "def"
ARGS = "agrs"
RETURN = "return"
IMPORT = "import"
PROPERTIES = "properties"
NAME = "name"
VALUE = "value"
METHODS = "methods"
FUNCTION = "function"

LENGTH_PROPERTY = {
    NAME: "length",
    VALUE: '0',
}

LIST_INTERFACE = [{ 
    DEF: "prepend",
    ARGS: "item",
    RETURN: "None",
}, {
    DEF: "insertAt",
    ARGS: "item, idx",
    RETURN: "None",
}, {
    DEF: "append",
    ARGS: "item",
    RETURN: "None",
}, {
    DEF: "remove",
    ARGS: "item",
    RETURN: "None",
}, {
    DEF: "get",
    ARGS: "idx",
    RETURN: "None",
}, {
    DEF: "removeAt",
    ARGS: "idx",
    RETURN: "None",
}]

modules = {
    # The Last Algorithm Course You'll Need

    "core_linear_search_list": {
        TYPE: "function",
        DEF: "linear_search",
        ARGS: "haystack: list[int], needle: int",
        RETURN: "bool",
    },

    "core_binary_search_list": {
        TYPE: "function",
        DEF: "binary_search",
        ARGS: "haystack: list[int], needle: int",
        RETURN: "bool",
    },

    "core_two_crystal_balls": {
        TYPE: "function",
        DEF: "two_crystal_balls",
        ARGS: "breaks: list[bool]",
        RETURN: "int",
    },

    "core_bubble_sort": {
        TYPE: "function",
        DEF: "bubble_sort",
        ARGS: "arr: list[int]",
        RETURN: "None",
    },

    "core_queue": {
        TYPE: "class",
        DEF: "Queue",
        PROPERTIES: [
            LENGTH_PROPERTY,
        ],
        METHODS: [{ 
            DEF: "enqueue",
            ARGS: "item",
            RETURN: "None",
        }, {
            DEF: "deque",
            ARGS: "",
            RETURN: "None",
            }, {
            DEF: "peek",
            RETURN: "None",
            ARGS: "",
        }]
    },

    "core_stack": {
        TYPE: "class",
        DEF: "Stack",
        PROPERTIES: [
            LENGTH_PROPERTY,
        ],
        METHODS: [{ 
            DEF: "push",
            ARGS: "item",
            RETURN: "None",
        }, {
            DEF: "pop",
            ARGS: "",
            RETURN: "None",
            }, {
            DEF: "peek",
            RETURN: "None",
            ARGS: "",
        }]
    },

    "core_maze_solver": {
        TYPE: "function",
        DEF: "solve",
        ARGS: "maze, wall, start, end",
        RETURN: "list[dict[str, int]]",

    },

    "core_quick_sort": {
        TYPE: "function",
        DEF: "quick_sort",
        ARGS: "arr: list[int]",
        RETURN: "None",
    },

    "core_doubly_linked_list": {
        TYPE: "class",
        DEF: "DoublyLinkedList",
        PROPERTIES: [
            LENGTH_PROPERTY,
        ],
        METHODS: LIST_INTERFACE,
    },

    "core_bt_pre_order": {
        TYPE: "function",
        IMPORT: ["from common import BinaryNode"],
        DEF: "pre_order_search",
        ARGS: "head: BinaryNode",
        RETURN: "list[int]"
    },

    "core_bt_in_order": {
        TYPE: "function",
        IMPORT: ["from common import BinaryNode"],
        DEF: "in_order_search",
        ARGS: "head: BinaryNode",
        RETURN: "list[int]"
    },

    "core_bt_post_order": {
        TYPE: "function",
        IMPORT: ["from common import BinaryNode"],
        DEF: "post_order_search",
        ARGS: "head: BinaryNode",
        RETURN: "list[int]"
    },

    "core_bt_bfs": {
        TYPE: "function",
        IMPORT: ["from common import BinaryNode"],
        DEF: "bt_bfs",
        ARGS: "head: BinaryNode, needle: int",
        RETURN: "bool"
    },

    "core_compare_binary_trees": {
        TYPE: "function",
        IMPORT: ["from common import BinaryNode"],
        DEF: "compare",
        ARGS: "a: BinaryNode, b: BinaryNode",
        RETURN: "bool"
    },

    # Element of Programming Interviews

    "array_dutch_flag_partition": {
        TYPE: "function",
        DEF: "dutch_flag_partition",
        ARGS: "pivot_idx: int, A: list[int]",
        RETURN: "None",
    },

    "array_plus_one": {
        TYPE: "function",
        DEF: "plus_one",
        ARGS: "A: list[int]",
        RETURN: "list[int]",
    },

    "array_multiply": {
        TYPE: "function",
        DEF: "multiply",
        ARGS: "num1: list[int], num2: list[int]",
        RETURN: "list[int]",
    },

    "array_can_reach_end": {
        TYPE: "function",
        DEF: "can_reach_end",
        ARGS: "A: list[int]",
        RETURN: "bool",
    },

    "array_delete_duplicates": {
        TYPE: "function",
        DEF: "delete_duplicates",
        ARGS: "A: list[int]",
        RETURN: "int",
    },

    "array_buy_and_sell_stock_once": {
        TYPE: "function",
        DEF: "buy_and_sell_stock_once",
        ARGS: "prices: list[int]",
        RETURN: "int",
    },

    "array_buy_and_sell_stock_twice": {
        TYPE: "function",
        DEF: "buy_and_sell_stock_twice",
        ARGS: "prices: list[int]",
        RETURN: "int",
    },

    "array_generate_primes": {
        TYPE: "function",
        DEF: "generate_primes",
        ARGS: "n: int",
        RETURN: "list[int]",
    },

    "array_apply_permutation": {
        TYPE: "function",
        DEF: "apply_permutation",
        ARGS: "perm: list[int], A: list[str]",
        RETURN: "None",
    },

    "array_next_permutation": {
        TYPE: "function",
        DEF: "next_permutation",
        ARGS: "perm: list[int]",
        RETURN: "list[int]",
    },

    "multi_dim_array_is_valid_sudoku": {
        TYPE: "function",
        DEF: "is_valid_sudoku",
        ARGS: "partial_assignment: list[list[int]]",
        RETURN: "bool",
    },

    "multi_dim_array_matrix_in_spiral_order": {
        TYPE: "function",
        DEF: "matrix_in_spiral_order",
        ARGS: "square_matrix: list[list[int]]",
        RETURN: "list[int]",
    },

    "multi_dim_array_rotate_matrix": {
        TYPE: "function",
        DEF: "rotate_matrix",
        ARGS: "square_matrix: list[list[int]]",
        RETURN: "None",
    },

    "multi_dim_array_generate_pascal_triangle": {
        TYPE: "function",
        DEF: "generate_pascal_triangle",
        ARGS: "n: int",
        RETURN: "list[list[int]]",
    },

    "string_int_to_string": {
        TYPE: "function",
        DEF: "int_to_string",
        ARGS: "x: int",
        RETURN: "str",
    },

    "string_string_to_int": {
        TYPE: "function",
        DEF: "string_to_int",
        ARGS: "s: str",
        RETURN: "int",
    },

    "string_convert_base": {
        TYPE: "function",
        DEF: "convert_base",
        ARGS: "num_as_string: str, b1: int, b2: int",
        RETURN: "str",
    },

    "string_ss_decode_col_id": {
        TYPE: "function",
        DEF: "ss_decode_col_id",
        ARGS: "col: str",
        RETURN: "int",
    },

    "string_replace_and_remove": {
        TYPE: "function",
        DEF: "replace_and_remove",
        ARGS: "size: int, s: list[str]",
        RETURN: "int",
    },

    "string_is_palindrome": {
        TYPE: "function",
        DEF: "is_palindrome",
        ARGS: "s: str",
        RETURN: "bool",
    },

    "string_reverse_words": {
        TYPE: "function",
        DEF: "reverse_words",
        ARGS: "s: list[str]",
        RETURN: "None",
    },

    "string_look_and_say": {
        TYPE: "function",
        DEF: "look_and_say",
        ARGS: "n: int",
        RETURN: "str",
    },

    "string_roman_to_integer": {
        TYPE: "function",
        DEF: "roman_to_integer",
        ARGS: "s: str",
        RETURN: "int",
    },

    "string_snake_string": {
        TYPE: "function",
        DEF: "snake_string",
        ARGS: "s: str",
        RETURN: "str",
    },

    "string_string_decoding": {
        TYPE: "function",
        DEF: "string_decoding",
        ARGS: "s: str",
        RETURN: "str",
    },

    "string_string_encoding": {
        TYPE: "function",
        DEF: "string_encoding",
        ARGS: "s: str",
        RETURN: "str",
    },

    "string_rabin_karp": {
        TYPE: "function",
        DEF: "rabin_karp",
        ARGS: "t: str, s: str",
        RETURN: "int",
    },

    "linked_lists_merge_two_sorted_lists": {
        TYPE: "function",
        IMPORT: ["from common import ListNode"],
        DEF: "merge_two_sorted_lists",
        ARGS: "L1: ListNode, L2: ListNode",
        RETURN: "ListNode",
    },

    "linked_lists_reverse_sublist": {
        TYPE: "function",
        IMPORT: ["from common import ListNode"],
        DEF: "reverse_sublist",
        ARGS: "L: ListNode, start: int, finish: int",
        RETURN: "ListNode",
    },

    "linked_lists_has_cycle": {
        TYPE: "function",
        IMPORT: ["from common import ListNode"],
        DEF: "has_cycle",
        ARGS: "head: ListNode",
        RETURN: "ListNode",
    },

    "linked_lists_overlapping_no_cycle_lists": {
        TYPE: "function",
        IMPORT: ["from common import ListNode"],
        DEF: "overlapping_no_cycle_lists",
        ARGS: "L1: ListNode, L2: ListNode",
        RETURN: "ListNode",
    },

    "linked_lists_overlapping_lists": {
        TYPE: "function",
        IMPORT: ["from common import ListNode"],
        DEF: "overlapping_lists",
        ARGS: "L1: ListNode, L2: ListNode",
        RETURN: "ListNode",
    },

    "linked_lists_deletion_from_list": {
        TYPE: "function",
        IMPORT: ["from common import ListNode"],
        DEF: "deletion_from_list",
        ARGS: "node_to_delete: ListNode",
        RETURN: "None",
    },

    "linked_lists_remove_kth_last": {
        TYPE: "function",
        IMPORT: ["from common import ListNode"],
        DEF: "remove_kth_last",
        ARGS: "L: ListNode, k: int",
        RETURN: "ListNode",
    },

    "linked_lists_remove_duplicates": {
        TYPE: "function",
        IMPORT: ["from common import ListNode"],
        DEF: "remove_duplicates",
        ARGS: "L: ListNode",
        RETURN: "ListNode",
    },

    "linked_lists_cyclically_right_shift_list": {
        TYPE: "function",
        IMPORT: ["from common import ListNode"],
        DEF: "cyclically_right_shift_list",
        ARGS: "L: ListNode, k: int",
        RETURN: "ListNode",
    },

    "linked_lists_even_odd_merge": {
        TYPE: "function",
        IMPORT: ["from common import ListNode"],
        DEF: "even_odd_merge",
        ARGS: "L: ListNode",
        RETURN: "ListNode",
    },

    "linked_lists_is_linked_list_a_palindrome": {
        TYPE: "function",
        IMPORT: ["from common import ListNode"],
        DEF: "is_linked_list_a_palindrome",
        ARGS: "L: ListNode",
        RETURN: "bool",
    },

    "linked_lists_list_pivoting": {
        TYPE: "function",
        IMPORT: ["from common import ListNode"],
        DEF: "list_pivoting",
        ARGS: "L: ListNode, x: int",
        RETURN: "ListNode",
    },

    "linked_lists_add_two_numbers": {
        TYPE: "function",
        IMPORT: ["from common import ListNode"],
        DEF: "add_two_numbers",
        ARGS: "L1: ListNode, L2: ListNode",
        RETURN: "ListNode",
    },

    "stack_evaluate_rpn_expression": {
        TYPE: "function",
        DEF: "evaluate",
        ARGS: "RPN_expression: list[str]",
        RETURN: "int",
    },

    "stack_is_well_formed": {
        TYPE: "function",
        DEF: "is_well_formed",
        ARGS: "s: str",
        RETURN: "bool",
    },

    "stack_shortest_equivalent_path": {
        TYPE: "function",
        DEF: "shortest_equivalent_path",
        ARGS: "path: str",
        RETURN: "str",
    },

    "stack_examine_buildings_with_sunset": {
        TYPE: "function",
        DEF: "examine_buildings_with_sunset",
        ARGS: "sequence: list[int]",
        RETURN: "list[int]",
    },

    "recursion_n_queens": {
        TYPE: "function",
        DEF: "n_queens",
        ARGS: "n: int",
        RETURN: "list[list[int]]",
    },

    "recursion_permutations": {
        TYPE: "function",
        DEF: "permutations",
        ARGS: "A: list[int]",
        RETURN: "list[int]",
    },

    "recursion_generate_power_set": {
        TYPE: "function",
        DEF: "generate_power_set",
        ARGS: "input_set: list[int]",
        RETURN: "list[list[int]]",
    },

    "recursion_combinations": {
        TYPE: "function",
        DEF: "combinations",
        ARGS: "n: int, k: int",
        RETURN: "list[list[int]]",
    },

    "recursion_generate_balanced_parentheses": {
        TYPE: "function",
        DEF: "generate_balanced_parentheses",
        ARGS: "num_pairs: int",
        RETURN: "list[str]",
    },

    "recursion_solve_sudoku": {
        TYPE: "function",
        DEF: "solve_sudoku",
        ARGS: "partial_assignment: list[list[int]]",
        RETURN: "bool",
    },

    "binary_trees_is_balanced_binary_tree": {
        TYPE: "function",
        IMPORT: ["from common import BinaryNode"],
        DEF: "is_balanced_binary_tree",
        ARGS: "tree: BinaryNode | None",
        RETURN: "bool",
    },

    "binary_trees_is_symmetric": {
        TYPE: "function",
        IMPORT: ["from common import BinaryNode"],
        DEF: "is_symmetric",
        ARGS: "tree: BinaryNode | None",
        RETURN: "bool",
    },

    "binary_trees_lca": {
        TYPE: "function",
        IMPORT: ["from common import BinaryNode"],
        DEF: "lca",
        ARGS: "tree: BinaryNode, node0: BinaryNode, node1: BinaryNode",
        RETURN: "BinaryNode",
    },

    "binary_trees_sum_root_to_leaf": {
        TYPE: "function",
        IMPORT: ["from common import BinaryNode"],
        DEF: "sum_root_to_leaf",
        ARGS: "tree: BinaryNode | None",
        RETURN: "int",
    },

    "binary_trees_has_path_sum": {
        TYPE: "function",
        IMPORT: ["from common import BinaryNode"],
        DEF: "has_path_sum",
        ARGS: "tree: BinaryNode | None, remaining_weight: int",
        RETURN: "bool",
    },

    "binary_trees_inorder_traversal": {
        TYPE: "function",
        IMPORT: ["from common import BinaryNode"],
        DEF: "inorder_traversal",
        ARGS: "tree: BinaryNode | None",
        RETURN: "list[int]",
    },

    "binary_trees_preorder_traversal": {
        TYPE: "function",
        IMPORT: ["from common import BinaryNode"],
        DEF: "preorder_traversal",
        ARGS: "tree: BinaryNode",
        RETURN: "list[int]",
    },

    "binary_trees_find_kth_node_binary_tree": {
        TYPE: "function",
        IMPORT: ["from common import BinaryNode"],
        DEF: "find_kth_node_binary_tree",
        ARGS: "tree: BinaryNode, k: int",
        RETURN: "BinaryNode | None",
    },

    "binary_trees_binary_tree_from_preorder_inorder": {
        TYPE: "function",
        IMPORT: ["from common import BinaryNode"],
        DEF: "binary_tree_from_preorder_inorder",
        ARGS: "preorder: list[int], inorder: list[int]",
        RETURN: "BinaryNode | None",
    },

    "binary_trees_reconstruct_preorder": {
        TYPE: "function",
        IMPORT: ["from common import BinaryNode"],
        DEF: "reconstruct_preorder",
        ARGS: "preorder: list[int]",
        RETURN: "BinaryNode | None",
    },

    "binary_trees_create_list_of_leaves": {
        TYPE: "function",
        IMPORT: ["from common import BinaryNode"],
        DEF: "create_list_of_leaves",
        ARGS: "tree: BinaryNode | None",
        RETURN: "list[BinaryNode]",
    },
}

