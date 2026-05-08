pub mod dsa;
use dsa::PROBLEMS;
use std::io::Write;

const ROOT_DIR: &'static str = ".";
const DAY_PREFIX: &'static str = "day";

fn main() {
    let dir = std::path::PathBuf::from(ROOT_DIR);
    let next_day = format!(
        "{}{}",
        DAY_PREFIX,
        std::fs::read_dir(ROOT_DIR)
            .expect("Failed to read root dir")
            .filter_map(Result::ok)
            .filter_map(|e| e.path().file_name()?.to_str().map(str::to_owned))
            .filter_map(|s| s.strip_prefix(DAY_PREFIX)?.parse::<i32>().ok())
            .max()
            .unwrap_or(0)
            + 1
    );
    let day_dir = dir.join(&next_day);
    std::fs::create_dir(&day_dir).expect("Failed to create dir {next_day}");

    let filename = dir.join("src").join("lib.rs");
    std::fs::remove_file(&filename).ok();
    let mut lib_file = std::fs::File::create(&filename).expect("Failed to create lib.rs");
    write!(
        lib_file,
        r#"
#[path = "../{0}/mod.rs"]
pub mod {0};
"#,
        &next_day
    )
    .expect("Failed to export {next_day}");

    let mod_file = day_dir.join("mod.rs");
    let mut mod_file = std::fs::File::create(&mod_file).expect("Failed to create mod {mod_file}");

    for problem in PROBLEMS.iter().flat_map(|v| v.iter()) {
        let mut filename = day_dir.join(problem.name);
        filename.set_extension("rs");
        let mut problem_file =
            std::fs::File::create(filename).expect("Failed to create file {filename}");
        write!(problem_file, "{0}", problem.generate())
            .expect("Failed to write file {problem_file}");
        write!(lib_file, "{0}", problem.export(&next_day))
            .expect("Failed to export {problem.name}");
        write!(mod_file, "{0}", problem.export(&String::from("")))
            .expect("Failed to pub {problem.name}");
    }
}
