#[cfg(test)]
mod array {
    use leetcode::apply_permutation::apply_permutation;
    use leetcode::buy_and_sell_stock_once::buy_and_sell_stock_once;
    use leetcode::buy_and_sell_stock_twice::buy_and_sell_stock_twice;
    use leetcode::can_reach_end::can_reach_end;
    use leetcode::delete_duplicates::delete_duplicates;
    use leetcode::dutch_flag_partition::dutch_flag_partition;
    use leetcode::generate_primes::generate_primes;
    use leetcode::multiply::multiply;
    use leetcode::next_permutation::next_permutation;
    use leetcode::plus_one::plus_one;

    #[test]
    fn test_dutch_flag_partition() {
        // Basic mixed-case partition with pivot value = 2.
        // Verifies:
        // - element counts are preserved
        // - all values < 2 come before values == 2
        let a = &mut vec![0, 1, 2, 0, 2, 1, 1];
        dutch_flag_partition(2, a);
        assert_eq!(a.iter().filter(|&&x| x == 0).count(), 2);
        assert_eq!(a.iter().filter(|&&x| x == 1).count(), 3);
        assert_eq!(a.iter().filter(|&&x| x == 2).count(), 2);
        assert!(a[..5].iter().all(|&x| x < 2));
        assert!(a[5..].iter().all(|&x| x == 2));

        // Same input, but pivot value = 0.
        // Ensures all zeros are grouped at the front.
        let a = &mut vec![0, 1, 2, 0, 2, 1, 1];
        dutch_flag_partition(3, a);
        assert_eq!(a.iter().filter(|&&x| x == 0).count(), 2);
        assert_eq!(a.iter().filter(|&&x| x == 1).count(), 3);
        assert_eq!(a.iter().filter(|&&x| x == 2).count(), 2);
        assert!(a[..2].iter().all(|&x| x == 0));
        assert!(a[2..].iter().all(|&x| x > 0));

        // Single-element array should remain unchanged.
        let a = &mut vec![42];
        dutch_flag_partition(0, a);
        assert_eq!(a, &vec![42]);

        // All elements equal to pivot.
        // Array should remain unchanged.
        let a = &mut vec![5, 5, 5, 5];
        dutch_flag_partition(1, a);
        assert!(a.iter().all(|&x| x == 5));

        // Already partitioned ascending input with pivot value = 2.
        let a = &mut vec![1, 1, 2, 2, 3, 3];
        dutch_flag_partition(2, a); // pivot value = 2
        assert!(a[..2].iter().all(|&x| x < 2));
        assert!(a[2..4].iter().all(|&x| x == 2));
        assert!(a[4..].iter().all(|&x| x > 2));

        // Reverse-ordered input with pivot value = 2.
        // Ensures algorithm correctly rearranges unsorted data.
        let a = &mut vec![3, 3, 2, 2, 1, 1];
        dutch_flag_partition(2, a); // pivot value = 2
        assert!(a[..2].iter().all(|&x| x < 2));
        assert!(a[2..4].iter().all(|&x| x == 2));
        assert!(a[4..].iter().all(|&x| x > 2));

        // Pivot is the minimum value in the array.
        // All pivot values should move to the front.
        let a = &mut vec![3, 1, 4, 1, 5, 9, 2, 6];
        dutch_flag_partition(1, a); // pivot value = 1
        assert_eq!(a.iter().filter(|&&x| x == 1).count(), 2);
        assert!(a[..2].iter().all(|&x| x == 1));
        assert!(a[2..].iter().all(|&x| x > 1));

        // Pivot is the maximum value in the array.
        // Pivot should end up at the end.
        let a = &mut vec![3, 1, 4, 1, 5, 9, 2, 6];
        dutch_flag_partition(5, a); // pivot value = 9
        assert_eq!(a.iter().filter(|&&x| x == 9).count(), 1);
        assert!(a[..7].iter().all(|&x| x < 9));
        assert_eq!(a[7], 9);

        // Two-element array already in correct order.
        let a = &mut vec![1, 5];
        dutch_flag_partition(1, a); // pivot value = 5
        assert_eq!(a, &vec![1, 5]);

        // Two-element array requiring swap.
        let a = &mut vec![5, 1];
        dutch_flag_partition(0, a); // pivot value = 5
        assert_eq!(a, &vec![1, 5]);

        // Distinct ordered values with middle pivot.
        // Verifies clean three-way partitioning.
        let a = &mut vec![10, 20, 30, 40, 50];
        dutch_flag_partition(2, a); // pivot value = 30
        assert!(a[..2].iter().all(|&x| x < 30));
        assert_eq!(a[2], 30);
        assert!(a[3..].iter().all(|&x| x > 30));

        // Includes negative values and multiple zeros.
        // Verifies handling of signed integers.
        let a = &mut vec![-3, 0, 5, -1, 0, 2, -2, 0];
        dutch_flag_partition(1, a); // pivot value = 0
        assert_eq!(a.iter().filter(|&&x| x < 0).count(), 3);
        assert_eq!(a.iter().filter(|&&x| x == 0).count(), 3);
        assert_eq!(a.iter().filter(|&&x| x > 0).count(), 2);
        assert!(a[..3].iter().all(|&x| x < 0));
        assert!(a[3..6].iter().all(|&x| x == 0));
        assert!(a[6..].iter().all(|&x| x > 0));

        // Larger mixed dataset with repeated pivot values.
        // Validates partition boundaries using computed counts.
        let a = &mut vec![5, 2, 8, 1, 9, 3, 7, 4, 6, 5, 2, 8, 1, 5];
        dutch_flag_partition(0, a); // pivot value = 5
        let lt = a.iter().filter(|&&x| x < 5).count();
        let eq = a.iter().filter(|&&x| x == 5).count();
        assert_eq!(lt, 6);
        assert_eq!(eq, 3);
        assert!(a[..lt].iter().all(|&x| x < 5));
        assert!(a[lt..lt + eq].iter().all(|&x| x == 5));
        assert!(a[lt + eq..].iter().all(|&x| x > 5));

        // Pivot chosen near the end of the array.
        // Ensures indexing logic works for last-position pivots.
        let a = &mut vec![4, 2, 7, 1, 3, 5, 6];
        dutch_flag_partition(a.len() - 1, a); // pivot value = 6
        assert!(a[..5].iter().all(|&x| x < 6));
        assert_eq!(a[5], 6);
        assert!(a[6..].iter().all(|&x| x > 6));
    }

    #[test]
    fn test_plus_one() {
        // Original cases
        assert_eq!(plus_one(vec![1, 2, 9]), [1, 3, 0]);
        assert_eq!(plus_one(vec![9, 9, 9]), [1, 0, 0, 0]);

        // Single digit
        assert_eq!(plus_one(vec![0]), [1]);
        assert_eq!(plus_one(vec![5]), [6]);
        assert_eq!(plus_one(vec![9]), [1, 0]);

        // No carry at all
        assert_eq!(plus_one(vec![1, 2, 3]), [1, 2, 4]);
        assert_eq!(plus_one(vec![1, 0, 0]), [1, 0, 1]);

        // Carry stops partway (doesn't propagate to the front)
        assert_eq!(plus_one(vec![1, 9, 9]), [2, 0, 0]);
        assert_eq!(plus_one(vec![5, 2, 9, 9]), [5, 3, 0, 0]);

        // Two-digit boundary
        assert_eq!(plus_one(vec![1, 9]), [2, 0]);

        // Trailing zeros (no carry case, makes sure you handle the last index correctly)
        assert_eq!(plus_one(vec![1, 0, 0, 0]), [1, 0, 0, 1]);

        // Long input — stress the loop
        assert_eq!(
            plus_one(vec![9, 9, 9, 9, 9, 9, 9, 9, 9, 9]),
            [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
        );

        // Only the leading digit is 9
        assert_eq!(plus_one(vec![9, 0, 0]), [9, 0, 1]);
        assert_eq!(plus_one(vec![9, 8, 7]), [9, 8, 8]);
    }

    #[test]
    fn test_multiply() {
        // Existing case: large positive × negative multi-digit numbers
        assert_eq!(
            multiply(
                vec![1, 9, 3, 7, 0, 7, 7, 2, 1],
                vec![-7, 6, 1, 8, 3, 8, 2, 5, 7, 2, 8, 7]
            ),
            [
                -1, 4, 7, 5, 7, 3, 9, 5, 2, 5, 8, 9, 6, 7, 6, 4, 1, 2, 9, 2, 7
            ]
        );

        // Single-digit multiplication
        assert_eq!(multiply(vec![2], vec![3]), [6]);

        // Standard multi-digit multiplication
        assert_eq!(multiply(vec![1, 2, 3], vec![4, 5, 6]), [5, 6, 0, 8, 8]);

        // Zero multiplied by zero
        assert_eq!(multiply(vec![0], vec![0]), [0]);

        // Zero multiplied by a multi-digit number
        assert_eq!(multiply(vec![0], vec![1, 2, 3, 4, 5]), [0]);

        // Multi-digit number multiplied by zero
        assert_eq!(multiply(vec![9, 9, 9], vec![0]), [0]);

        // Multiplicative identity: 1 × 1
        assert_eq!(multiply(vec![1], vec![1]), [1]);

        // Multiplication by one preserves the number
        assert_eq!(multiply(vec![1], vec![7, 8, 9]), [7, 8, 9]);

        // Multiplication by one on the right-hand side
        assert_eq!(multiply(vec![4, 2], vec![1]), [4, 2]);

        // Single-digit multiplication with carry
        assert_eq!(multiply(vec![9], vec![9]), [8, 1]);

        // Two-digit multiplication with cascading carry
        assert_eq!(multiply(vec![9, 9], vec![9, 9]), [9, 8, 0, 1]);

        // Larger repeated-digit multiplication
        assert_eq!(multiply(vec![9, 9, 9], vec![9, 9, 9]), [9, 9, 8, 0, 0, 1]);

        // Multiplication involving trailing zeros
        assert_eq!(multiply(vec![1, 0], vec![1, 0]), [1, 0, 0]);

        // Larger numbers with trailing zeros
        assert_eq!(multiply(vec![1, 0, 0], vec![1, 0, 0]), [1, 0, 0, 0, 0]);

        // Single-digit × multi-digit number
        assert_eq!(multiply(vec![5], vec![1, 2, 3, 4, 5]), [6, 1, 7, 2, 5]);

        // Multi-digit × single-digit number
        assert_eq!(multiply(vec![1, 2, 3, 4, 5], vec![5]), [6, 1, 7, 2, 5]);

        // Negative × positive single-digit multiplication
        assert_eq!(multiply(vec![-5], vec![3]), [-1, 5]);

        // Positive × negative single-digit multiplication
        assert_eq!(multiply(vec![7], vec![-8]), [-5, 6]);

        // Negative × negative produces positive result
        assert_eq!(multiply(vec![-4], vec![-6]), [2, 4]);

        // Negative multi-digit × positive multi-digit
        assert_eq!(multiply(vec![-1, 2], vec![1, 2]), [-1, 4, 4]);

        // Negative multi-digit × negative multi-digit
        assert_eq!(multiply(vec![-1, 2], vec![-3, 4]), [4, 0, 8]);

        // Negative zero should behave like zero
        assert_eq!(multiply(vec![-0], vec![5, 5]), [0]);

        // Large multi-digit multiplication with mixed carries
        assert_eq!(
            multiply(vec![1, 2, 3, 4, 5], vec![6, 7, 8, 9, 0]),
            [8, 3, 8, 1, 0, 2, 0, 5, 0]
        );

        // Small repeated-digit multiplication
        assert_eq!(multiply(vec![1, 1], vec![1, 1]), [1, 2, 1]);

        // Verify multiplication is commutative
        assert_eq!(
            multiply(vec![3, 1, 4], vec![2, 7, 1, 8]),
            multiply(vec![2, 7, 1, 8], vec![3, 1, 4])
        );

        // Verify expected result for a known multiplication
        assert_eq!(
            multiply(vec![3, 1, 4], vec![2, 7, 1, 8]),
            [8, 5, 3, 4, 5, 2]
        );
    }

    #[test]
    fn test_can_reach_end() {
        // Can jump over zeros and still reach the last index
        assert!(can_reach_end(vec![2, 4, 1, 1, 0, 2, 3]));

        // Large jump value enables reaching the end despite intermediate zeros
        assert!(can_reach_end(vec![3, 3, 7, 0, 2, 0, 1]));

        // Gets stuck at consecutive zeros before reaching the end
        assert!(!can_reach_end(vec![3, 2, 0, 0, 2, 0, 7]));

        // Single-element array is already at the destination
        assert!(can_reach_end(vec![0]));

        // Single-element array with nonzero value is also trivially reachable
        assert!(can_reach_end(vec![5]));

        // One valid jump directly to the end
        assert!(can_reach_end(vec![1, 0]));

        // Jump length greater than needed still succeeds
        assert!(can_reach_end(vec![2, 0]));

        // Cannot move anywhere from the starting position
        assert!(!can_reach_end(vec![0, 1]));

        // Starting position has zero jump length in a multi-element array
        assert!(!can_reach_end(vec![0, 5, 3, 2]));

        // Reaches a dead end before the last index
        assert!(!can_reach_end(vec![1, 0, 1]));

        // Path becomes blocked by zeros before completion
        assert!(!can_reach_end(vec![2, 1, 0, 0, 1]));

        // Step-by-step progression successfully reaches the end
        assert!(can_reach_end(vec![1, 1, 1, 1, 1]));

        // Large first jump can directly reach the last index
        assert!(can_reach_end(vec![4, 0, 0, 0, 0]));

        // First jump is insufficient to bypass all zeros
        assert!(!can_reach_end(vec![3, 0, 0, 0, 0]));

        // Oversized jump value easily reaches the destination
        assert!(can_reach_end(vec![10, 0, 0, 0, 0, 0]));

        // Extremely large jump value handles long arrays
        assert!(can_reach_end(vec![100, 0, 0, 0, 0, 0, 0, 0]));

        // Exact sequence of jumps reaches the end
        assert!(can_reach_end(vec![1, 1, 0]));

        // Multiple valid jump choices still allow success
        assert!(can_reach_end(vec![2, 3, 1, 1, 0]));

        // Classic reachable jump-game example
        assert!(can_reach_end(vec![2, 3, 1, 1, 4]));

        // Zero creates an unavoidable blocking position
        assert!(!can_reach_end(vec![3, 2, 1, 0, 4, 2, 1]));

        // Long array with uniform step size of one
        assert!(can_reach_end(vec![1; 100]));

        // Repeated jump length of two keeps progress possible
        assert!(can_reach_end(vec![2; 50]));

        // Trailing zeros create an unreachable ending segment
        assert!(!can_reach_end(vec![1, 1, 1, 0, 0, 0, 1]));

        // Exact jump range barely reaches the last index
        assert!(can_reach_end(vec![5, 0, 0, 0, 0, 1]));

        // Jump range falls one step short of the destination
        assert!(!can_reach_end(vec![4, 0, 0, 0, 0, 1]));
    }

    #[test]
    fn test_delete_duplicates() {
        // Mixed duplicates throughout the array
        let a = &mut vec![2, 3, 5, 5, 7, 11, 11, 11, 13];
        let len = delete_duplicates(a) as usize;
        assert_eq!(a[..len], [2, 3, 5, 7, 11, 13]);

        // Empty array should remain empty
        let a = &mut vec![];
        let len = delete_duplicates(a) as usize;
        assert_eq!(a[..len], [] as [i32; 0]);

        // Single-element array should be unchanged
        let a = &mut vec![42];
        let len = delete_duplicates(a) as usize;
        assert_eq!(a[..len], [42]);

        // Array with no duplicates should remain unchanged
        let a = &mut vec![1, 2, 3, 4, 5];
        let len = delete_duplicates(a) as usize;
        assert_eq!(a[..len], [1, 2, 3, 4, 5]);

        // All elements are duplicates, leaving only one
        let a = &mut vec![7, 7, 7, 7, 7];
        let len = delete_duplicates(a) as usize;
        assert_eq!(a[..len], [7]);

        // Two identical elements should collapse into one
        let a = &mut vec![1, 1];
        let len = delete_duplicates(a) as usize;
        assert_eq!(a[..len], [1]);

        // Two distinct elements should remain unchanged
        let a = &mut vec![1, 2];
        let len = delete_duplicates(a) as usize;
        assert_eq!(a[..len], [1, 2]);

        // Duplicates only at the beginning
        let a = &mut vec![1, 1, 1, 2, 3, 4];
        let len = delete_duplicates(a) as usize;
        assert_eq!(a[..len], [1, 2, 3, 4]);

        // Duplicates only at the end
        let a = &mut vec![1, 2, 3, 4, 4, 4];
        let len = delete_duplicates(a) as usize;
        assert_eq!(a[..len], [1, 2, 3, 4]);

        // Every element appears exactly twice
        let a = &mut vec![1, 1, 2, 2, 3, 3, 4, 4];
        let len = delete_duplicates(a) as usize;
        assert_eq!(a[..len], [1, 2, 3, 4]);

        // Handles negative numbers and zero correctly
        let a = &mut vec![-5, -5, -3, -1, -1, 0, 0, 2, 2];
        let len = delete_duplicates(a) as usize;
        assert_eq!(a[..len], [-5, -3, -1, 0, 2]);

        // Large run of duplicates in the middle
        let a = &mut vec![1, 2, 2, 2, 2, 2, 2, 2, 3];
        let len = delete_duplicates(a) as usize;
        assert_eq!(a[..len], [1, 2, 3]);

        // Verifies returned length after removing duplicates
        let a = &mut vec![1, 1, 2, 3, 3];
        let len = delete_duplicates(a);
        assert_eq!(len, 3);
    }

    #[test]
    fn test_buy_and_sell_stock_twice() {
        // original
        assert_eq!(
            buy_and_sell_stock_twice(vec![12, 11, 13, 9, 12, 8, 14, 13, 15]),
            10
        );
        assert_eq!(
            buy_and_sell_stock_twice(vec![2, 30, 15, 10, 8, 25, 80]),
            100
        );
        assert_eq!(buy_and_sell_stock_twice(vec![7, 1, 5, 3, 6, 4]), 7);

        // empty / minimal inputs
        assert_eq!(buy_and_sell_stock_twice(vec![]), 0);
        assert_eq!(buy_and_sell_stock_twice(vec![5]), 0);
        assert_eq!(buy_and_sell_stock_twice(vec![5, 10]), 5);
        assert_eq!(buy_and_sell_stock_twice(vec![10, 5]), 0);

        // strictly increasing
        assert_eq!(buy_and_sell_stock_twice(vec![1, 2, 3, 4, 5]), 4);

        // strictly decreasing
        assert_eq!(buy_and_sell_stock_twice(vec![7, 6, 4, 3, 1]), 0);

        // two clear profitable transactions
        assert_eq!(
            buy_and_sell_stock_twice(vec![3, 8, 5, 1, 7, 8]),
            12 // (3->8)=5 and (1->8)=7
        );

        assert_eq!(
            buy_and_sell_stock_twice(vec![1, 5, 2, 10]),
            12 // (1->5)=4 and (2->10)=8
        );

        // best to do only one transaction
        assert_eq!(buy_and_sell_stock_twice(vec![1, 10, 9, 8, 7]), 9);

        // duplicate prices
        assert_eq!(buy_and_sell_stock_twice(vec![5, 5, 5, 5]), 0);

        assert_eq!(buy_and_sell_stock_twice(vec![1, 2, 2, 2, 5]), 4);

        // alternating valleys and peaks
        assert_eq!(buy_and_sell_stock_twice(vec![2, 1, 2, 0, 1]), 2);

        assert_eq!(
            buy_and_sell_stock_twice(vec![6, 1, 3, 2, 4, 7]),
            7 // (1->3)=2 and (2->7)=5
        );

        // classic LC123 example
        assert_eq!(buy_and_sell_stock_twice(vec![3, 3, 5, 0, 0, 3, 1, 4]), 6);

        // large second profit
        assert_eq!(
            buy_and_sell_stock_twice(vec![1, 4, 2, 20]),
            21 // (1->4)=3 and (2->20)=18
        );
    }

    #[test]
    fn test_buy_and_sell_stock_once() {
        // original
        assert_eq!(
            buy_and_sell_stock_once(vec![310, 315, 275, 295, 260, 270, 290, 230, 255, 250]),
            30
        );
        assert_eq!(buy_and_sell_stock_once(vec![10, 12, 9, 6, 8, 12]), 6);
        assert_eq!(buy_and_sell_stock_once(vec![7, 1, 5, 3, 6, 4]), 5);
        assert_eq!(buy_and_sell_stock_once(vec![7, 6, 4, 3, 1]), 0);

        // strictly increasing
        assert_eq!(buy_and_sell_stock_once(vec![1, 2, 3, 4, 5]), 4);

        // single element
        assert_eq!(buy_and_sell_stock_once(vec![5]), 0);

        // empty input
        assert_eq!(buy_and_sell_stock_once(vec![]), 0);

        // all same prices
        assert_eq!(buy_and_sell_stock_once(vec![4, 4, 4, 4]), 0);

        // profit occurs at the end
        assert_eq!(buy_and_sell_stock_once(vec![9, 8, 7, 1, 10]), 9);

        // multiple ups and downs
        assert_eq!(buy_and_sell_stock_once(vec![3, 8, 2, 5, 1, 7]), 6);

        // best buy is in the middle
        assert_eq!(buy_and_sell_stock_once(vec![10, 7, 5, 8, 11, 9]), 6);

        // two equal max profits
        assert_eq!(buy_and_sell_stock_once(vec![1, 5, 2, 6]), 5);

        // large drop then recovery
        assert_eq!(buy_and_sell_stock_once(vec![100, 90, 80, 70, 60, 120]), 60);

        // alternating prices
        assert_eq!(buy_and_sell_stock_once(vec![5, 1, 5, 1, 5]), 4);

        // negative values (if supported)
        assert_eq!(buy_and_sell_stock_once(vec![-3, -1, -5, 0]), 5);

        // max profit from first to last
        assert_eq!(buy_and_sell_stock_once(vec![2, 10]), 8);

        // decreasing then flat
        assert_eq!(buy_and_sell_stock_once(vec![9, 7, 5, 5, 5]), 0);

        // valley before peak
        assert_eq!(buy_and_sell_stock_once(vec![8, 6, 2, 9, 1, 4]), 7);
    }

    #[test]
    fn test_generate_primes() {
        // original
        assert_eq!(generate_primes(18), [2, 3, 5, 7, 11, 13, 17]);

        // empty / small ranges
        assert_eq!(generate_primes(0), vec![]); // no primes
        assert_eq!(generate_primes(1), vec![]); // no primes
        assert_eq!(generate_primes(2), vec![2]); // smallest prime

        // small range
        assert_eq!(generate_primes(3), vec![2, 3]); // primes up to 3

        // typical case
        assert_eq!(
            generate_primes(10),
            vec![2, 3, 5, 7] // primes under 10
        );

        // medium range
        assert_eq!(
            generate_primes(18),
            vec![2, 3, 5, 7, 11, 13, 17] // primes under 18
        );

        // larger range
        assert_eq!(
            generate_primes(20),
            vec![2, 3, 5, 7, 11, 13, 17, 19] // primes under 20
        );

        // bigger range
        assert_eq!(
            generate_primes(30),
            vec![2, 3, 5, 7, 11, 13, 17, 19, 23, 29] // primes under 30
        );

        // extended range
        assert_eq!(
            generate_primes(50),
            vec![2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47] // primes under 50
        );
    }

    #[test]
    fn test_apply_permutation() {
        // reverse permutation
        let a = &mut ['a', 'b', 'c', 'd'];
        apply_permutation(vec![3, 2, 1, 0], a);
        assert_eq!(a[..], ['d', 'c', 'b', 'a']);

        // cyclic / mixed permutation
        let a = &mut ['a', 'b', 'c', 'd'];
        apply_permutation(vec![2, 0, 1, 3], a);
        assert_eq!(a[..], ['b', 'c', 'a', 'd']);

        // identity permutation (no change)
        let a = &mut ['a', 'b', 'c', 'd'];
        apply_permutation(vec![0, 1, 2, 3], a);
        assert_eq!(a[..], ['a', 'b', 'c', 'd']);

        // single swap
        let a = &mut ['a', 'b', 'c', 'd'];
        apply_permutation(vec![1, 0, 2, 3], a);
        assert_eq!(a[..], ['b', 'a', 'c', 'd']);

        // shuffle-like permutation
        let a = &mut ['a', 'b', 'c', 'd'];
        apply_permutation(vec![3, 1, 0, 2], a);
        assert_eq!(a[..], ['c', 'b', 'd', 'a']);

        // already partially sorted
        let a = &mut ['a', 'b', 'c', 'd'];
        apply_permutation(vec![0, 2, 3, 1], a);
        assert_eq!(a[..], ['a', 'd', 'b', 'c']);

        // empty slice
        let a: &mut [char] = &mut [];
        apply_permutation(vec![], a);
        assert_eq!(a, []);

        // single element
        let a = &mut ['x'];
        apply_permutation(vec![0], a);
        assert_eq!(a[..], ['x']);

        // two independent swaps
        let a = &mut ['a', 'b', 'c', 'd', 'e', 'f'];
        apply_permutation(vec![1, 0, 3, 2, 5, 4], a);
        assert_eq!(a[..], ['b', 'a', 'd', 'c', 'f', 'e']);

        // long cycle
        let a = &mut ['a', 'b', 'c', 'd', 'e'];
        apply_permutation(vec![1, 2, 3, 4, 0], a);
        assert_eq!(a[..], ['e', 'a', 'b', 'c', 'd']);

        // permutation with fixed points
        let a = &mut ['a', 'b', 'c', 'd', 'e'];
        apply_permutation(vec![0, 2, 1, 3, 4], a);
        assert_eq!(a[..], ['a', 'c', 'b', 'd', 'e']);

        // odd-sized reversal
        let a = &mut ['a', 'b', 'c', 'd', 'e'];
        apply_permutation(vec![4, 3, 2, 1, 0], a);
        assert_eq!(a[..], ['e', 'd', 'c', 'b', 'a']);

        // repeated application stability check
        let a = &mut ['a', 'b', 'c', 'd'];
        apply_permutation(vec![2, 3, 0, 1], a);
        assert_eq!(a[..], ['c', 'd', 'a', 'b']);

        apply_permutation(vec![2, 3, 0, 1], a);
        assert_eq!(a[..], ['a', 'b', 'c', 'd']);

        // alternating pattern
        let a = &mut ['a', 'b', 'c', 'd', 'e', 'f'];
        apply_permutation(vec![5, 0, 4, 1, 3, 2], a);
        assert_eq!(a[..], ['b', 'd', 'f', 'e', 'c', 'a']);
    }

    #[test]
    fn test_next_permutation() {
        // swap inside middle
        assert_eq!(
            next_permutation(vec![1, 0, 3, 2]),
            vec![1, 2, 0, 3] // correct next lexicographic permutation
        );

        // highest permutation -> no next permutation exists
        assert_eq!(
            next_permutation(vec![3, 2, 1, 0]),
            vec![] // or sometimes expected to be sorted: [0,1,2,3] depending on design
        );

        // general case
        assert_eq!(
            next_permutation(vec![6, 2, 1, 5, 4, 3, 0]),
            vec![6, 2, 3, 0, 1, 4, 5] // next lexicographic permutation
        );
        //
        // already sorted ascending → next permutation exists
        assert_eq!(next_permutation(vec![1, 2, 3]), vec![1, 3, 2]);

        // simple swap at end
        assert_eq!(next_permutation(vec![1, 2, 3, 4]), vec![1, 2, 4, 3]);

        // middle pivot change
        assert_eq!(next_permutation(vec![1, 3, 2, 4]), vec![1, 3, 4, 2]);

        // multiple decreasing suffix
        assert_eq!(next_permutation(vec![1, 5, 4, 3, 2]), vec![2, 1, 3, 4, 5]);

        // full reverse → no next permutation
        assert_eq!(next_permutation(vec![9, 8, 7, 6]), vec![]);

        // duplicates present (important edge case)
        assert_eq!(next_permutation(vec![1, 1, 2]), vec![1, 2, 1]);

        assert_eq!(next_permutation(vec![1, 2, 2]), vec![2, 1, 2]);

        // repeated blocks
        assert_eq!(next_permutation(vec![2, 2, 0, 1]), vec![2, 2, 1, 0]);

        // already highest permutation among duplicates
        assert_eq!(next_permutation(vec![3, 3, 2, 2]), vec![]);

        // single element
        assert_eq!(next_permutation(vec![1]), vec![]);

        // two elements
        assert_eq!(next_permutation(vec![2, 1]), vec![]);

        assert_eq!(next_permutation(vec![1, 2]), vec![2, 1]);

        // larger mixed case
        assert_eq!(next_permutation(vec![1, 4, 3, 2]), vec![2, 1, 3, 4]);

        // long plateau then increase
        assert_eq!(
            next_permutation(vec![1, 2, 3, 6, 5, 4]),
            vec![1, 2, 4, 3, 5, 6]
        );

        // pivot far left
        assert_eq!(
            next_permutation(vec![2, 7, 6, 5, 4, 3, 1]),
            vec![3, 1, 2, 4, 5, 6, 7]
        );
    }
}

#[cfg(test)]
mod array_2d {
    use leetcode::generate_pascal_triangle::generate_pascal_triangle;
    use leetcode::is_valid_sudoku::is_valid_sudoku;
    use leetcode::matrix_in_spiral_order::matrix_in_spiral_order;
    use leetcode::rotate_matrix::rotate_matrix;

    #[test]
    fn test_generate_pascal_triangle() {
        // n = 0 → empty triangle
        assert_eq!(generate_pascal_triangle(0), Vec::<Vec<i32>>::new());

        // n = 1 → single row
        assert_eq!(generate_pascal_triangle(1), vec![vec![1]]);

        // n = 2 → simplest expansion
        assert_eq!(generate_pascal_triangle(2), vec![vec![1], vec![1, 1]]);

        // n = 3 → small triangle
        assert_eq!(
            generate_pascal_triangle(3),
            vec![vec![1], vec![1, 1], vec![1, 2, 1]]
        );

        // n = 5 → original
        assert_eq!(
            generate_pascal_triangle(5),
            vec![
                vec![1],
                vec![1, 1],
                vec![1, 2, 1],
                vec![1, 3, 3, 1],
                vec![1, 4, 6, 4, 1]
            ]
        );

        // n = 6 → deeper structure check
        assert_eq!(
            generate_pascal_triangle(6),
            vec![
                vec![1],
                vec![1, 1],
                vec![1, 2, 1],
                vec![1, 3, 3, 1],
                vec![1, 4, 6, 4, 1],
                vec![1, 5, 10, 10, 5, 1]
            ]
        );

        // verify symmetry property indirectly
        let tri = generate_pascal_triangle(7);
        for row in tri.iter() {
            assert_eq!(row[0], 1);
            assert_eq!(row[row.len() - 1], 1);
        }

        // check row lengths grow correctly
        let tri = generate_pascal_triangle(8);
        for (i, row) in tri.iter().enumerate() {
            assert_eq!(row.len(), i + 1);
        }

        // large-ish sanity check (structure only)
        let tri = generate_pascal_triangle(10);
        assert_eq!(tri.len(), 10);
        assert_eq!(tri[9][0], 1);
        assert_eq!(tri[9][9], 1);
    }

    #[test]
    fn test_is_valid_sudoku() {
        assert!(!is_valid_sudoku(&vec![
            vec![5, 3, 0, 0, 7, 0, 0, 0, 0],
            vec![6, 0, 0, 1, 9, 5, 0, 0, 0],
            vec![0, 9, 8, 0, 0, 0, 0, 6, 0],
            vec![8, 0, 0, 0, 6, 0, 0, 0, 3],
            vec![4, 0, 0, 8, 0, 3, 0, 0, 1],
            vec![7, 0, 0, 0, 2, 0, 0, 0, 6],
            vec![0, 6, 0, 0, 0, 0, 2, 8, 0],
            vec![0, 0, 0, 4, 1, 9, 0, 0, 5],
            vec![0, 0, 0, 0, 8, 0, 0, 7, 9],
        ]));
        assert!(is_valid_sudoku(&vec![
            vec![5, 3, 4, 6, 7, 8, 9, 1, 2],
            vec![6, 7, 2, 1, 9, 5, 3, 4, 8],
            vec![1, 9, 8, 3, 4, 2, 5, 6, 7],
            vec![8, 5, 9, 7, 6, 1, 4, 2, 3],
            vec![4, 2, 6, 8, 5, 3, 7, 9, 1],
            vec![7, 1, 3, 9, 2, 4, 8, 5, 6],
            vec![9, 6, 1, 5, 3, 7, 2, 8, 4],
            vec![2, 8, 7, 4, 1, 9, 6, 3, 5],
            vec![3, 4, 5, 2, 8, 6, 1, 7, 9],
        ]));

        // invalid: duplicate in a row
        assert!(!is_valid_sudoku(&vec![
            vec![5, 3, 4, 6, 7, 8, 9, 1, 5], // duplicate 5 in row
            vec![6, 7, 2, 1, 9, 5, 3, 4, 8],
            vec![1, 9, 8, 3, 4, 2, 5, 6, 7],
            vec![8, 5, 9, 7, 6, 1, 4, 2, 3],
            vec![4, 2, 6, 8, 5, 3, 7, 9, 1],
            vec![7, 1, 3, 9, 2, 4, 8, 5, 6],
            vec![9, 6, 1, 5, 3, 7, 2, 8, 4],
            vec![2, 8, 7, 4, 1, 9, 6, 3, 5],
            vec![3, 4, 5, 2, 8, 6, 1, 7, 9],
        ]));

        // invalid: duplicate in a column
        assert!(!is_valid_sudoku(&vec![
            vec![5, 3, 4, 6, 7, 8, 9, 1, 2],
            vec![6, 3, 2, 1, 9, 5, 3, 4, 8], // duplicate 3 in column
            vec![1, 9, 8, 3, 4, 2, 5, 6, 7],
            vec![8, 5, 9, 7, 6, 1, 4, 2, 3],
            vec![4, 2, 6, 8, 5, 3, 7, 9, 1],
            vec![7, 1, 3, 9, 2, 4, 8, 5, 6],
            vec![9, 6, 1, 5, 3, 7, 2, 8, 4],
            vec![2, 8, 7, 4, 1, 9, 6, 3, 5],
            vec![3, 4, 5, 2, 8, 6, 1, 7, 9],
        ]));

        // invalid: duplicate in a 3x3 sub-box
        assert!(!is_valid_sudoku(&vec![
            vec![5, 3, 4, 6, 7, 8, 9, 1, 2],
            vec![6, 7, 2, 1, 9, 5, 3, 4, 8],
            vec![1, 9, 8, 3, 4, 2, 5, 6, 7],
            vec![8, 5, 9, 7, 6, 1, 4, 2, 3],
            vec![4, 2, 6, 8, 5, 3, 7, 9, 1],
            vec![7, 1, 3, 9, 2, 4, 8, 5, 6],
            vec![9, 6, 1, 5, 3, 7, 2, 8, 4],
            vec![2, 8, 7, 4, 1, 9, 6, 3, 5],
            vec![3, 4, 5, 2, 8, 6, 1, 7, 3], // duplicate 3 in bottom-right box
        ]));

        // valid: empty grid (all zeros)
        assert!(!is_valid_sudoku(&vec![
            vec![0, 0, 0, 0, 0, 0, 0, 0, 0],
            vec![0, 0, 0, 0, 0, 0, 0, 0, 0],
            vec![0, 0, 0, 0, 0, 0, 0, 0, 0],
            vec![0, 0, 0, 0, 0, 0, 0, 0, 0],
            vec![0, 0, 0, 0, 0, 0, 0, 0, 0],
            vec![0, 0, 0, 0, 0, 0, 0, 0, 0],
            vec![0, 0, 0, 0, 0, 0, 0, 0, 0],
            vec![0, 0, 0, 0, 0, 0, 0, 0, 0],
            vec![0, 0, 0, 0, 0, 0, 0, 0, 0],
        ]));

        // edge: single filled cell
        assert!(!is_valid_sudoku(&vec![
            vec![5, 0, 0, 0, 0, 0, 0, 0, 0],
            vec![0; 9],
            vec![0; 9],
            vec![0; 9],
            vec![0; 9],
            vec![0; 9],
            vec![0; 9],
            vec![0; 9],
            vec![0; 9],
        ]));

        // edge: invalid number (if your function enforces 1–9)
        assert!(!is_valid_sudoku(&vec![
            vec![10, 0, 0, 0, 0, 0, 0, 0, 0], // invalid value
            vec![0; 9],
            vec![0; 9],
            vec![0; 9],
            vec![0; 9],
            vec![0; 9],
            vec![0; 9],
            vec![0; 9],
            vec![0; 9],
        ]));
    }

    #[test]
    fn test_rotate_matrix() {
        // 1x1 matrix (edge case - smallest possible input)
        let m = &mut vec![vec![42]];
        rotate_matrix(m);
        assert_eq!(m, &mut vec![vec![42],],);

        // 2x2 matrix (basic rotation)
        let m = &mut vec![vec![1, 2], vec![3, 4]];
        rotate_matrix(m);
        assert_eq!(m, &mut vec![vec![3, 1], vec![4, 2],],);

        // 3x3 matrix (odd dimension)
        let m = &mut vec![vec![1, 2, 3], vec![4, 5, 6], vec![7, 8, 9]];
        rotate_matrix(m);
        assert_eq!(m, &mut vec![vec![7, 4, 1], vec![8, 5, 2], vec![9, 6, 3],],);

        // 4x4 matrix (your original-style case)
        let m = &mut vec![
            vec![1, 2, 3, 4],
            vec![5, 6, 7, 8],
            vec![9, 10, 11, 12],
            vec![13, 14, 15, 16],
        ];
        rotate_matrix(m);
        assert_eq!(
            m,
            &mut vec![
                vec![13, 9, 5, 1],
                vec![14, 10, 6, 2],
                vec![15, 11, 7, 3],
                vec![16, 12, 8, 4],
            ],
        );

        // matrix with negative numbers
        let m = &mut vec![vec![-1, -2, -3], vec![-4, -5, -6], vec![-7, -8, -9]];
        rotate_matrix(m);
        assert_eq!(
            m,
            &mut vec![vec![-7, -4, -1], vec![-8, -5, -2], vec![-9, -6, -3],],
        );

        // 5x5 matrix (larger stress test)
        let m = &mut vec![
            vec![1, 2, 3, 4, 5],
            vec![6, 7, 8, 9, 10],
            vec![11, 12, 13, 14, 15],
            vec![16, 17, 18, 19, 20],
            vec![21, 22, 23, 24, 25],
        ];
        rotate_matrix(m);
        assert_eq!(
            m,
            &mut vec![
                vec![21, 16, 11, 6, 1],
                vec![22, 17, 12, 7, 2],
                vec![23, 18, 13, 8, 3],
                vec![24, 19, 14, 9, 4],
                vec![25, 20, 15, 10, 5],
            ],
        );
    }

    #[test]
    fn test_matrix_in_spiral_order() {
        // 1x1 matrix
        assert_eq!(matrix_in_spiral_order(&vec![vec![42]]), vec![42]);

        // 2x2 matrix
        assert_eq!(
            matrix_in_spiral_order(&vec![vec![1, 2], vec![3, 4],]),
            vec![1, 2, 4, 3]
        );

        // 3x3 matrix
        assert_eq!(
            matrix_in_spiral_order(&vec![vec![1, 2, 3], vec![4, 5, 6], vec![7, 8, 9],]),
            vec![1, 2, 3, 6, 9, 8, 7, 4, 5]
        );

        // 4x4 matrix
        assert_eq!(
            matrix_in_spiral_order(&vec![
                vec![1, 2, 3, 4],
                vec![5, 6, 7, 8],
                vec![9, 10, 11, 12],
                vec![13, 14, 15, 16],
            ]),
            vec![1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10]
        );

        // 5x5 matrix
        assert_eq!(
            matrix_in_spiral_order(&vec![
                vec![1, 2, 3, 4, 5],
                vec![6, 7, 8, 9, 10],
                vec![11, 12, 13, 14, 15],
                vec![16, 17, 18, 19, 20],
                vec![21, 22, 23, 24, 25],
            ]),
            vec![
                1, 2, 3, 4, 5, 10, 15, 20, 25, 24, 23, 22, 21, 16, 11, 6, 7, 8, 9, 14, 19, 18, 17,
                12, 13
            ]
        );

        // empty matrix
        assert_eq!(matrix_in_spiral_order(&Vec::<Vec<i32>>::new()), vec![]);

        // matrix with empty row
        assert_eq!(matrix_in_spiral_order(&vec![vec![]]), vec![]);
    }
}
