
# Complexity Analysis
## Q1. Shortest Path using 0-1 BFS

**Time Complexity Calculation:**

1. Initializing the adjacency list takes O(V).
2. Each vertex has 2 states (Even and Odd).
3. Each state is processed using the deque.
4. Every edge is relaxed at most once per state.

Therefore:
Time Complexity = O(V + E)

**Space Complexity Calculation:**

1. Adjacency list requires O(V + E).
2. Distance array requires O(2V).
3. Deque requires O(V + E).

Therefore:

Space Complexity = O(V + E)

---
## Q2. Multi-Source BFS

**Time Complexity Calculation:**

1. Creating the adjacency matrix takes O(V²).
2. Initializing distance and owner arrays takes O(V).
3. BFS processes each vertex once.
4. For every vertex, all V possible neighbours are checked.

Therefore:
Time Complexity = O(V²)

**Space Complexity Calculation:**

1. Adjacency matrix requires O(V²).
2. Queue requires O(V).
3. Distance and owner arrays require O(V).

Therefore:

Space Complexity = O(V²)

---
## Q3. Bidirectional BFS – Word Transformation

**Time Complexity Calculation:**

1. There are N words in the dictionary.
2. Each visited word is compared with all N dictionary words.
3. Comparing two words takes O(L) time.
4. Therefore, the worst-case time is O(N × N × L).
Therefore:
Time Complexity = O(N² × L)

**Space Complexity Calculation:**

1. Dictionary storage requires O(N × L).
2. Distance arrays require O(N).
3. BFS queues require O(N).

Therefore:

Space Complexity = O(N × L)

---