#[derive(Debug)]
pub struct Problem {
    pub name: &'static str,
    parameters: &'static [(&'static str, &'static str)],
    values: &'static [(&'static str, &'static str)],
}

pub const PROBLEMS: &[&[Problem]] = &[ARRAY, ARRAY_2D];

pub const ARRAY: &[Problem] = &[
    Problem {
        name: "dutch_flag_partition",
        parameters: &[("pivot_idx", "usize"), ("a", "&mut Vec<i32>")],
        values: &[],
    },
    Problem {
        name: "plus_one",
        parameters: &[("a", "Vec<i32>")],
        values: &[("Vec<i32>", "vec![]")],
    },
    Problem {
        name: "multiply",
        parameters: &[("num1", "Vec<i32>"), ("num2", "Vec<i32>")],
        values: &[("Vec<i32>", "vec![]")],
    },
    Problem {
        name: "next_permutation",
        parameters: &[("perm", "Vec<i32>")],
        values: &[("Vec<i32>", "vec![]")],
    },
    Problem {
        name: "apply_permutation",
        parameters: &[("mut perm", "Vec<i32>"), ("a", "&mut [char]")],
        values: &[],
    },
    Problem {
        name: "generate_primes",
        parameters: &[("n", "i32")],
        values: &[("Vec<i32>", "vec![]")],
    },
    Problem {
        name: "buy_and_sell_stock_once",
        parameters: &[("prices", "Vec<i32>")],
        values: &[("i32", "-1")],
    },
    Problem {
        name: "buy_and_sell_stock_twice",
        parameters: &[("prices", "Vec<i32>")],
        values: &[("i32", "-1")],
    },
    Problem {
        name: "delete_duplicates",
        parameters: &[("a", "&mut Vec<i32>")],
        values: &[("i32", "-1")],
    },
    Problem {
        name: "can_reach_end",
        parameters: &[("a", "Vec<i32>")],
        values: &[("bool", "false")],
    },
];

pub const ARRAY_2D: &[Problem] = &[
    Problem {
        name: "generate_pascal_triangle",
        parameters: &[("n", "i32")],
        values: &[("Vec<Vec<i32>>", "vec![vec![]]")],
    },
    Problem {
        name: "rotate_matrix",
        parameters: &[("square_matrix", "&mut Vec<Vec<i32>>")],
        values: &[],
    },
    Problem {
        name: "is_valid_sudoku",
        parameters: &[("partial_assignment", "&Vec<Vec<i32>>")],
        values: &[("bool", "false")],
    },
    Problem {
        name: "matrix_in_spiral_order",
        parameters: &[("square_matrix", "&Vec<Vec<i32>>")],
        values: &[("Vec<i32>", "vec![]")],
    },
];

impl Problem {
    pub fn generate(&self) -> String {
        format!(
            r#"
pub fn {0}({1}) {2} {{
    {3}
}}
"#,
            self.name,
            self.parameters
                .into_iter()
                .map(|(name, value)| format!("{}: {}", name, value))
                .collect::<Vec<_>>()
                .join(", "),
            match self.values.len() {
                0 => String::from(""),
                1 => format!("-> {}", &self.values[0].0),
                _ => panic!("Unsupported multiple return values"),
            },
            match self.values.len() {
                0 => String::from(""),
                1 => String::from(self.values[0].1),
                _ => panic!("Unsupported multiple return values"),
            }
        )
    }

    pub fn export(&self, module: &String) -> String {
        format!(
            r#"
pub {0}{1};
"#,
            if module.is_empty() {
                String::from("mod ")
            } else {
                format!("use {0}::", &module)
            },
            self.name
        )
    }
}
