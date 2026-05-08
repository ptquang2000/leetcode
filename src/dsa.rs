#[derive(Debug)]
pub struct Problem {
    pub name: &'static str,
    parameters: &'static [(&'static str, &'static str)],
    values: &'static [(&'static str, &'static str)],
}

pub const PROBLEMS: &[&[Problem]] = &[];

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
