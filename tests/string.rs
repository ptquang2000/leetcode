#[cfg(test)]
mod string {
    use leetcode::convert_base::convert_base;
    use leetcode::int_to_string::int_to_string;
    use leetcode::is_palindrome::is_palindrome;
    use leetcode::look_and_say::look_and_say;
    use leetcode::rabin_karp::rabin_karp;
    use leetcode::reverse_words::reverse_words;
    use leetcode::roman_to_integer::roman_to_integer;
    use leetcode::snake_string::snake_string;
    use leetcode::spreadsheet_decode_column_id::spreadsheet_decode_column_id;
    use leetcode::string_decoding::string_decoding;
    use leetcode::string_encoding::string_encoding;
    use leetcode::string_to_int::string_to_int;

    #[test]
    fn test_int_to_string() {
        assert_eq!(int_to_string(123), "123");
        assert_eq!(int_to_string(-123), "-123");
        assert_eq!(int_to_string(314), "314");
        assert_eq!(int_to_string(-314), "-314");

        assert_eq!(int_to_string(0), "0");
        assert_eq!(int_to_string(3), "3");

        // single-digit negatives
        assert_eq!(int_to_string(-3), "-3");

        // larger numbers
        assert_eq!(int_to_string(1000), "1000");
        assert_eq!(int_to_string(-1000), "-1000");

        // numbers with zeros inside
        assert_eq!(int_to_string(1010), "1010");
        assert_eq!(int_to_string(-1010), "-1010");

        // max/min 32-bit int edge cases (if applicable)
        assert_eq!(int_to_string(i32::MAX), i32::MAX.to_string());
        assert_eq!(int_to_string(i32::MIN), i32::MIN.to_string());

        // repeated digits
        assert_eq!(int_to_string(11111), "11111");
        assert_eq!(int_to_string(-11111), "-11111");
    }

    #[test]
    fn test_string_to_int() {
        assert_eq!(string_to_int("123"), 123);
        assert_eq!(string_to_int("-123"), -123);
        assert_eq!(string_to_int("314"), 314);
        assert_eq!(string_to_int("-314"), -314);
        assert_eq!(string_to_int("0"), 0);
        assert_eq!(string_to_int("3"), 3);

        // Leading zeros
        assert_eq!(string_to_int("00123"), 123);
        assert_eq!(string_to_int("-00123"), -123);

        // Plus sign (if supported)
        assert_eq!(string_to_int("+123"), 123);

        // Larger numbers
        assert_eq!(string_to_int("1000"), 1000);
        assert_eq!(string_to_int("-1000"), -1000);

        // Single digit edge cases
        assert_eq!(string_to_int("9"), 9);
        assert_eq!(string_to_int("-9"), -9);
    }

    #[test]
    fn test_convert_base() {
        // given cases
        assert_eq!(convert_base("615", 7, 13), "1A7");
        assert_eq!(convert_base("1A7", 13, 7), "615");
        assert_eq!(convert_base("102", 3, 4), "23");
        assert_eq!(convert_base("23", 4, 3), "102");

        // zero cases
        assert_eq!(convert_base("0", 10, 2), "0");
        assert_eq!(convert_base("0", 2, 10), "0");

        // single-digit conversions
        assert_eq!(convert_base("5", 10, 2), "101");
        assert_eq!(convert_base("A", 16, 10), "10");
        assert_eq!(convert_base("Z", 36, 10), "35");

        // identity conversions (same base)
        assert_eq!(convert_base("1234", 10, 10), "1234");
        assert_eq!(convert_base("1A7", 16, 16), "1A7");

        // binary ↔ decimal
        assert_eq!(convert_base("1010", 2, 10), "10");
        assert_eq!(convert_base("10", 10, 2), "1010");

        // hex ↔ decimal
        assert_eq!(convert_base("FF", 16, 10), "255");
        assert_eq!(convert_base("255", 10, 16), "FF");

        // max base (36)
        assert_eq!(convert_base("Z", 36, 10), "35");
        assert_eq!(convert_base("35", 10, 36), "Z");

        // leading zeros
        assert_eq!(convert_base("0012", 10, 2), "1100");
        assert_eq!(convert_base("000", 10, 7), "0");
    }

    #[test]
    fn test_is_palindrome() {
        // classic true cases
        assert!(is_palindrome("A man, a plan, a canal Panama."));
        assert!(is_palindrome("Able was I, ere I saw Elba!"));

        // simple cases
        assert!(is_palindrome("a"));
        assert!(is_palindrome("aa"));
        assert!(is_palindrome("madam"));
        assert!(is_palindrome("RaceCar"));

        // punctuation / spacing robustness
        assert!(is_palindrome("Was it a car or a cat I saw?"));
        assert!(is_palindrome("No 'x' in Nixon"));
        assert!(is_palindrome("Never odd or even"));

        // numbers mixed in
        assert!(is_palindrome("12321"));
        assert!(is_palindrome("1,2,3,2,1"));

        // edge cases
        assert!(is_palindrome("")); // empty string often treated as palindrome
        assert!(is_palindrome(" ")); // whitespace-only input

        // negative cases
        assert!(!is_palindrome("Ray a Ray"));
        assert!(!is_palindrome("hello"));
        assert!(!is_palindrome("abc"));
        assert!(!is_palindrome("palindrome"));
        assert!(!is_palindrome("Rust is great"));
    }

    #[test]
    fn test_spreadsheet_decode_column_id() {
        // basic single-letter cases
        assert_eq!(spreadsheet_decode_column_id("A"), 1);
        assert_eq!(spreadsheet_decode_column_id("C"), 3);
        assert_eq!(spreadsheet_decode_column_id("D"), 4);
        assert_eq!(spreadsheet_decode_column_id("Z"), 26);

        // two-letter cases
        assert_eq!(spreadsheet_decode_column_id("AA"), 27);
        assert_eq!(spreadsheet_decode_column_id("AB"), 28);
        assert_eq!(spreadsheet_decode_column_id("AZ"), 52);
        assert_eq!(spreadsheet_decode_column_id("BA"), 53);
        assert_eq!(spreadsheet_decode_column_id("BC"), 55);
        assert_eq!(spreadsheet_decode_column_id("ZZ"), 702);

        // three-letter case
        assert_eq!(spreadsheet_decode_column_id("AAA"), 703);

        // larger stress case (Excel max column)
        assert_eq!(spreadsheet_decode_column_id("FXSHRXW"), 2147483647);
    }

    #[test]
    fn test_reverse_words() {
        // basic cases
        let mut s = String::from("Alice likes Bob");
        reverse_words(&mut s);
        assert_eq!(s, "Bob likes Alice");

        let mut s = String::from("ram is costly");
        reverse_words(&mut s);
        assert_eq!(s, "costly is ram");

        // single word
        let mut s = String::from("hello");
        reverse_words(&mut s);
        assert_eq!(s, "hello");

        // empty string
        let mut s = String::from("");
        reverse_words(&mut s);
        assert_eq!(s, "");

        // leading/trailing spaces (if your function trims or preserves behavior, adjust expectation accordingly)
        let mut s = String::from("  Alice likes Bob  ");
        reverse_words(&mut s);
        assert_eq!(s, "  Bob likes Alice  ");

        // multiple spaces between words
        let mut s = String::from("Alice   likes    Bob");
        reverse_words(&mut s);
        assert_eq!(s, "Bob    likes   Alice");

        // punctuation handling
        let mut s = String::from("Alice, likes Bob!");
        reverse_words(&mut s);
        assert_eq!(s, "!Bob likes ,Alice");
    }

    #[test]
    fn test_look_and_say() {
        // basic sequence checks
        assert_eq!(look_and_say(1), "1");
        assert_eq!(look_and_say(2), "11");
        assert_eq!(look_and_say(3), "21");
        assert_eq!(look_and_say(4), "1211");
        assert_eq!(look_and_say(5), "111221");
        assert_eq!(look_and_say(6), "312211");
        assert_eq!(look_and_say(7), "13112221");
        assert_eq!(look_and_say(8), "1113213211");

        // higher term sanity check
        assert_eq!(look_and_say(9), "31131211131221");

        // consistency checks
        assert_eq!(look_and_say(6), look_and_say(6));
        assert_ne!(look_and_say(7), look_and_say(8));

        // optional edge case (adjust if your implementation differs)
        assert_eq!(look_and_say(0), "");
    }

    #[test]
    fn test_roman_to_integer() {
        // Your existing cases
        assert_eq!(roman_to_integer("XXXXXIIIIIIIII"), 59);
        assert_eq!(roman_to_integer("LVIIII"), 59);
        assert_eq!(roman_to_integer("LIX"), 59);

        // Basic symbols
        assert_eq!(roman_to_integer("I"), 1);
        assert_eq!(roman_to_integer("V"), 5);
        assert_eq!(roman_to_integer("X"), 10);
        assert_eq!(roman_to_integer("L"), 50);
        assert_eq!(roman_to_integer("C"), 100);
        assert_eq!(roman_to_integer("D"), 500);
        assert_eq!(roman_to_integer("M"), 1000);

        // Subtractive notation (standard)
        assert_eq!(roman_to_integer("IV"), 4);
        assert_eq!(roman_to_integer("IX"), 9);
        assert_eq!(roman_to_integer("XL"), 40);
        assert_eq!(roman_to_integer("XC"), 90);
        assert_eq!(roman_to_integer("CD"), 400);
        assert_eq!(roman_to_integer("CM"), 900);

        // Mixed valid numbers
        assert_eq!(roman_to_integer("XIV"), 14);
        assert_eq!(roman_to_integer("XXIX"), 29);
        assert_eq!(roman_to_integer("XLII"), 42);
        assert_eq!(roman_to_integer("XCIX"), 99);
        assert_eq!(roman_to_integer("CXLIV"), 144);
        assert_eq!(roman_to_integer("MCMXCIV"), 1994);

        // Repetition-heavy forms
        assert_eq!(roman_to_integer("III"), 3);
        assert_eq!(roman_to_integer("XXX"), 30);
        assert_eq!(roman_to_integer("CCC"), 300);
        assert_eq!(roman_to_integer("MMM"), 3000);

        // Non-standard / edge interpretations (depending on your implementation rules)
        assert_eq!(roman_to_integer("IIII"), 4);
        assert_eq!(roman_to_integer("VIIII"), 9);
        assert_eq!(roman_to_integer("XXXX"), 40);
        assert_eq!(roman_to_integer("LXXXX"), 90);
    }

    #[test]
    fn test_string_encoding() {
        // original cases
        assert_eq!(string_encoding("aaaabcccaa"), "4a1b3c2a");
        assert_eq!(string_encoding("eeeffffee"), "3e4f2e");

        // edge cases
        assert_eq!(string_encoding(""), ""); // empty string
        assert_eq!(string_encoding("a"), "1a"); // single character
        assert_eq!(string_encoding("abc"), "1a1b1c"); // no repeats

        // mixed patterns
        assert_eq!(string_encoding("aabbaa"), "2a2b2a"); // alternating groups
        assert_eq!(string_encoding("aaaaa"), "5a"); // single long run
        assert_eq!(string_encoding("abbbbbcc"), "1a5b2c"); // uneven groups

        // numeric / non-alpha (if supported by your implementation)
        assert_eq!(string_encoding("1112233"), "312223"); // run-length of digits
    }

    #[test]
    fn test_string_decoding() {
        assert_eq!(string_decoding("4a1b3c2a"), "aaaabcccaa");
        assert_eq!(string_decoding("3e4f2e"), "eeeffffee");

        // single group
        assert_eq!(string_decoding("1a"), "a");

        // multiple single-char groups
        assert_eq!(string_decoding("1a1b1c"), "abc");

        // repeated same character in separate groups
        assert_eq!(string_decoding("2a3a"), "aaaaa");

        // larger counts
        assert_eq!(string_decoding("10a"), "aaaaaaaaaa");

        // mixed single and multi-digit groups
        assert_eq!(string_decoding("2a10b1c"), "aabbbbbbbbbbc");
        // corrected version:
        assert_eq!(string_decoding("2a10b1c"), "aabbbbbbbbbbc");

        // empty input
        assert_eq!(string_decoding(""), "");

        // long sequence
        assert_eq!(string_decoding("5x5y5z"), "xxxxxyyyyyzzzzz");
    }

    #[test]
    fn test_snake_string() {
        // Empty string
        assert_eq!(snake_string(""), "");

        // Single character
        assert_eq!(snake_string("A"), "A");

        // Two characters
        assert_eq!(snake_string("AB"), "AB");

        // Classic example
        assert_eq!(snake_string("Hello World!"), "HoWel ol!lrd");

        // Even length
        assert_eq!(snake_string("Rust"), "Ruts");

        // Odd length
        assert_eq!(snake_string("Snake"), "Snkae");

        // Spaces preserved (spaces are characters too)
        assert_eq!(snake_string("a b c"), "ac  b");

        // Numbers and symbols
        assert_eq!(snake_string("12345!"), "15243!");

        // Repeated characters
        assert_eq!(snake_string("aaaaaa"), "aaaaaa");

        // Unicode characters (treated as chars)
        assert_eq!(snake_string("héllo"), "hoéll");

        // Longer sentence
        assert_eq!(snake_string("The quick brown fox"), "Tqkofh u c r w oeibnx");
    }

    #[test]
    fn test_rabin_karp() {
        // Basic matches
        let t = "GACGCCA";
        let s = "CGC";
        assert_eq!(rabin_karp(t, s), t.find(s).map(|i| i as i32).unwrap_or(-1));

        let t = "GACGCCA";
        let s = "CCA";
        assert_eq!(rabin_karp(t, s), t.find(s).map(|i| i as i32).unwrap_or(-1));

        // No match
        let t = "GACGCCA";
        let s = "BBA";
        assert_eq!(rabin_karp(t, s), t.find(s).map(|i| i as i32).unwrap_or(-1));

        // Match in middle
        let t = "hello how are you?";
        let s = "how are";
        assert_eq!(rabin_karp(t, s), t.find(s).map(|i| i as i32).unwrap_or(-1));

        // Match with leading whitespace
        let t = " hello world is the first code of every programmer";
        let s = "first";
        assert_eq!(rabin_karp(t, s), t.find(s).map(|i| i as i32).unwrap_or(-1));

        // Match at beginning
        let t = "abcdef";
        let s = "abc";
        assert_eq!(rabin_karp(t, s), t.find(s).map(|i| i as i32).unwrap_or(-1));

        // Match at end
        let t = "abcdef";
        let s = "def";
        assert_eq!(rabin_karp(t, s), t.find(s).map(|i| i as i32).unwrap_or(-1));

        // Whole string match
        let t = "abcdef";
        let s = "abcdef";
        assert_eq!(rabin_karp(t, s), t.find(s).map(|i| i as i32).unwrap_or(-1));

        // Pattern longer than text
        let t = "abc";
        let s = "abcdef";
        assert_eq!(rabin_karp(t, s), t.find(s).map(|i| i as i32).unwrap_or(-1));

        // Empty pattern
        let t = "abcdef";
        let s = "";
        assert_eq!(rabin_karp(t, s), t.find(s).map(|i| i as i32).unwrap_or(-1));

        // Empty text
        let t = "";
        let s = "abc";
        assert_eq!(rabin_karp(t, s), t.find(s).map(|i| i as i32).unwrap_or(-1));

        // Both empty
        let t = "";
        let s = "";
        assert_eq!(rabin_karp(t, s), t.find(s).map(|i| i as i32).unwrap_or(-1));

        // Repeated characters
        let t = "aaaaaa";
        let s = "aaa";
        assert_eq!(rabin_karp(t, s), t.find(s).map(|i| i as i32).unwrap_or(-1));

        // Multiple possible matches
        let t = "abababab";
        let s = "abab";
        assert_eq!(rabin_karp(t, s), t.find(s).map(|i| i as i32).unwrap_or(-1));

        // Single character present
        let t = "abcdef";
        let s = "d";
        assert_eq!(rabin_karp(t, s), t.find(s).map(|i| i as i32).unwrap_or(-1));

        // Single character absent
        let t = "abcdef";
        let s = "x";
        assert_eq!(rabin_karp(t, s), t.find(s).map(|i| i as i32).unwrap_or(-1));

        // Special characters
        let t = "a$c^d[e]f(g)";
        let s = "[e]";
        assert_eq!(rabin_karp(t, s), t.find(s).map(|i| i as i32).unwrap_or(-1));

        // Case sensitivity
        let t = "HelloWorld";
        let s = "world";
        assert_eq!(rabin_karp(t, s), t.find(s).map(|i| i as i32).unwrap_or(-1));

        // Long repetitive input
        let t = "a".repeat(10_000) + "b";
        let s = "aaab";
        assert_eq!(rabin_karp(&t, s), t.find(s).map(|i| i as i32).unwrap_or(-1));
    }
}
