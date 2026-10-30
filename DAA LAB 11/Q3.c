/*3. [Bidirectional BFS for Shortest Transformation Sequence in a Word Graph] You are given: 
◦ A dictionary D containing N unique words, where every word has the exact same length L.
◦ Astarting word A and a target word B, both of length L.
 A valid mutation step consists of changing exactly one character of a word such that the resulting word exists in dictionary D.
  A transformation sequence from A to B is an ordered sequence of words: W0,W1,W2,...,Wk such that: 
  1. W0 =A and Wk =B.
   2. Every intermediate word Wi ∈ D for all 1 ≤ i ≤ k. (Note: whether A must initially be in D is typically specified by the input constraints, but B must always be in D.) 
   3. For every adjacent pair (Wi−1,Wi), the two words differ by exactly one character (i.e., their Hamming distance is 1).
  Objective: Compute the minimum number of mutations k required to transform A into B.
     If A cannot be transformed into B through valid intermediate words in D, return −1 (or report that no valid path exists).
      Keep in mind to consider the following constraints for this problem during implementation:
       ◦ N ≤105 (number of dictionary words) ◦ L≤10 (length of each word) ◦
        All words consist solely of lowercase English letters (’a’ to ’z’). By choosing the proper input representation, 
write a program in C to validate your algorithm and derive the complexity analysis of your algorithm.*/
#include<stdio.h>
#include <string.h>
#define MAX 100
#define LEN 20

char words[MAX][LEN];
int distA[MAX], distB[MAX];
int qA[MAX], qB[MAX];

int n;

// Find a word in dictionary
int findWord(char s[]) {
    for(int i = 0; i < n; i++) {
        if(strcmp(words[i], s) == 0)
            return i;
    }
    return -1;
}

// Check if two words differ by one character
int valid(char a[], char b[]) {
    int count = 0;

    for(int i = 0; a[i] != '\0'; i++) {
        if(a[i] != b[i])
            count++;
    }

    return count == 1;
}

// Expand one BFS level
int expand(int q[], int *size, int dist[],
           int otherDist[]) {

    int newQ[MAX];
    int newSize = 0;

    for(int i = 0; i < *size; i++) {

        int u = q[i];

        for(int v = 0; v < n; v++) {

            if(dist[v] == -1 &&
               valid(words[u], words[v])) {

                dist[v] = dist[u] + 1;

                if(otherDist[v] != -1)
                    return dist[v] + otherDist[v];

                newQ[newSize++] = v;
            }
        }
    }

    for(int i = 0; i < newSize; i++)
        q[i] = newQ[i];

    *size = newSize;

    return -1;
}

int main() {

    char A[LEN], B[LEN];

    printf("Enter number of dictionary words: ");
    scanf("%d", &n);

    printf("Enter dictionary words:\n");

    for(int i = 0; i < n; i++) {
        printf("Word %d: ", i + 1);
        scanf("%19s", words[i]);
    }

    printf("Enter starting word: ");
    scanf("%19s", A);

    printf("Enter target word: ");
    scanf("%19s", B);

    if(strlen(A) != strlen(B)) {
        printf("Minimum mutations: -1\n");
        return 0;
    }

    for(int i = 0; i < n; i++) {
        if(strlen(words[i]) != strlen(A)) {
            printf("All words must have equal length.\n");
            return 0;
        }
    }

    if(strcmp(A, B) == 0) {
        printf("Minimum mutations: 0\n");
        return 0;
    }

    int start = findWord(A);
    int target = findWord(B);

    // Target must exist in dictionary
    if(target == -1) {
        printf("Minimum mutations: -1\n");
        return 0;
    }

    // Add starting word if not present
    if(start == -1) {
        start = n;
        strcpy(words[n], A);
        n++;
    }

    for(int i = 0; i < n; i++) {
        distA[i] = -1;
        distB[i] = -1;
    }

    // Start BFS from both ends
    int sizeA = 1, sizeB = 1;

    qA[0] = start;
    qB[0] = target;

    distA[start] = 0;
    distB[target] = 0;

    int ans = -1;

    // Bidirectional BFS
    while(sizeA > 0 && sizeB > 0) {

        if(sizeA <= sizeB) {
            ans = expand(qA, &sizeA, distA, distB);
        }
        else {
            ans = expand(qB, &sizeB, distB, distA);
        }

        if(ans != -1)
            break;
    }

    printf("Minimum mutations: %d\n", ans);

    return 0;
}
