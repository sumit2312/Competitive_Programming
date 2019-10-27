/*
  Longest Common Subsequence | DP-4 - GeeksforGeeks:
  https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
  The video to explain this code is here: https://www.youtube.com/watch?v=ASoaQq66foQ
*/

/*
  This is what the DP table looks like filled out for the 2 strings
  "AGGTAB" and "GXTXAYB".
     ""  A  G  G  T  A  B
  ""  0  0  0  0  0  0  0
  G   0  0  1  1  1  1  1
  X   0  0  1  1  1  1  1
  T   0  0  1  1  2  2  2
  X   0  0  1  1  2  2  2
  A   0  1  1  1  2  3  3
  Y   0  1  1  1  2  3  3
  B   0  1  1  1  2  3  4
  Just like we did in the video. Each cell is a subproblem call on the
  appropriate substring snippets.
*/

class TopDown {

  public int longestCommonsubsequenceLength(String s1, String s2) {

    /*
      Base Case
      lcs("", anything...) == 0
      lcs(anything..., "") == 0
      lcs("", "") == 0
      A subproblem where either string is empty will have a result
      of 0. There can be nothing in common with an empty string and
      anything else.
    */
    if (s1.length() == 0 || s2.length() == 0) {
      return 0;
    }

    /*
      Just extracting what we certainly will need and being explicit
    */
    String s1WithoutFinalCharacter = s1.substring(0, s1.length() - 1);
    String s2WithoutFinalCharacter = s2.substring(0, s2.length() - 1);

    char s1FinalCharacter = s1.charAt(s1.length() - 1);
    char s2FinalCharacter = s2.charAt(s2.length() - 1);

    if (s1FinalCharacter == s2FinalCharacter) {

      /*
        No competition necessary. A match. The answer to THIS subproblem
        is 1 PLUS the best answer to the subproblem without either of these
        characters.
      */

      return 1 + longestCommonsubsequenceLength(s1WithoutFinalCharacter, s2WithoutFinalCharacter);

    } else {

      /*
        Character mismatch. Compete subproblems, whoever wins becomes the answer to this
        subproblem and is hence returned
      */
      return Math.max(longestCommonsubsequenceLength(s1, s2WithoutFinalCharacter),
                 longestCommonsubsequenceLength(s1WithoutFinalCharacter, s2));

    }

  }

}

class BottomUp {

  public int longestCommonsubsequenceLength(String s1, String s2) {

    /*
      s2 will be on the rows, s1 will be on the columns.
      +1 to leave room at the left for the "".
    */
    int cache[][] = new int[s2.length() + 1][s1.length() + 1];

    /*
      cache[s2.length()][s1.length()] is our original subproblem. Each entry in the
      table is taking a substring operation against whatever string is
      on the rows or columns.
      It goes from index 0 to index s2Row/s1Col (exclusive)
      So if my s1 = "azb" and s1Col = 2...then my substring that I pass
      to the lcs() function will be:
       0  1  2
      "a  z  b"
      "az" (index 2...our upper bound of the snippet...is excluded)
    */
    for (int s2Row = 0; s2Row <= s2.length(); s2Row++) {
      for (int s1Col = 0; s1Col <= s1.length(); s1Col++) {

        if (s2Row == 0 || s1Col == 0) {

          /*
            Base case...empty strings being solved against.
            Remember:
              lcs("", anything...) == 0
              lcs(anything..., "") == 0
              lcs("", "") == 0
          */
          cache[s2Row][s1Col] = 0;

        } else if (s2.charAt(s2Row - 1) == s1.charAt(s1Col - 1)) {

          /*
            Characters match. Remove both and lengthen the best answer at the
            subproblem without either final character. That is the answer
            to this subproblem.
          */
          cache[s2Row][s1Col] = cache[s2Row - 1][s1Col - 1] + 1;
        }
        else {

          /*
            Character mismatch. No +1 happens, we can't lengthen the lcs. But we
            do need to compete subproblems to find the answer to this one.
          */
          cache[s2Row][s1Col] = Math.max(cache[s2Row - 1][s1Col], cache[s2Row][s1Col - 1]);

        }

      }
    }

    return cache[s2.length()][s1.length()];
  }

}
