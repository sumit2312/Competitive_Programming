int strStr(string haystack, string needle) {
        int nsize = needle.size();
    	int hsize = haystack.size();
    	if (nsize == 0) return 0;
    	int *table = new int[nsize];
    	memset(table, 0, sizeof(int)*nsize);
    	//building match table
    	for (int i = 1, j = 0; i < nsize - 1;){
    		if (needle[i] != needle[j]){
    			if (j>0){
    				j = table[j - 1];
    			}
    			else{
    				i++;
    			}
    		}
    		else{
    			table[i] = j + 1;
    			i++;
    			j++;
    		}
    	}
    	//matching
    	for (int i = 0, match_pos = 0; i < hsize;){
    		if (haystack[i] == needle[match_pos]){
    			if (match_pos == nsize - 1){
    				return i - (nsize - 1);
    			}
    			else{
    				i++;
    				match_pos++;
    			}
    		}
    		else{
    			if (match_pos == 0){
    				i++;
    			}
    			else{
    				match_pos = table[match_pos - 1];
    			}
    		}
    	}
    	delete[]table;
    	return -1;
    }
    
/*    
I'll talk about the basic idea behind KMP algorithm.

First, some notations:

Denote the pattern string as ps and the match table as table, ps and
table use 0 based index.
Denote substring of ps from index i to index
j (i and j included) as substr(ps,i,j).
Denote string1 is the same as
string2 as string1==string2
The definition of my match table:

table[i] when i>0 means the max length of prefix of ps(0,i) which is the same as the suffix of ps(0,i).

Or table[i]=max{k| substr(substr(ps,0,i),0,k-1) == substr(substr(ps,0,i),i-k+1,i), k<=i}.

Also, we define table[i]=0.

So, for string "aba", table={0,0,1}.

table[1]=0 is because no prefix equals suffix of "ab".

table[2]=1 is because prefix "a" equals suffix "a" of "aba".

for string "abcabce", table={0,0,0,1,2,3,0}.

table[4]=2 is because prefix "ab" equals suffix "ab" of "abcab"

table[5]=3 is because prefix "abc" equals suffix "abc" of "abcabc"

for string "aabaabaaa", table={0,1,0,1,2,3,4,5,2}.

How would this match table be helpful to string matching?

Suppose we have a target string "abcabcdxxxxx" and a pattern "abcabce".
In the first round of matching, we start at first character and have

abcabcdxxxxx
abcabce
We discover that 'd' and 'e' are different and string before that is the same, which is "abcabc".
if we move "abcabce" forward one character, we would be comparing

abcabcdxxxxx
 abcabce
let's focus on the parts which are same in the previous round:

abcabc
 abcabc
we are actually comparing the suffix of length 5 of "abcabc", which is "bcabc" and the prefix of length 5 of "abcabc", which is "abcab".

However, table[5]==3 tells us the max length of suffix and prefix of "abcabc" which are same is 3, so suffix and prefix
of length 5 can't be the same. Thus, we can skip this round of comparing.
Next, we move "abcabce" forward by another one character, we would be comparing

abcabc
  abcabc
Now, we are comparing suffix and prefix of length 4, since table[5]==3, we can skip this round.
Next, we move "abcabce" forward by another one character, we would be comparing

abcabc
   abcabc
Now, we are comparing suffix and prefix of length 3, since table[5]==3, this is valid.
Another property we can use to simply the matching process is that we already know the prefix and suffix of length 3 are the same, so we can start by comparing from the 4th charater in pattern, which is 'a', with the target string.

To sum up, when the ps(pattern string) at index i(i>0) failed to match ts(target string) at index j, which means substr(ps,0,i-1) matches, we start by comparing ps[table[i-1]] with ts[j].
*/
