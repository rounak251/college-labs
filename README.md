# College Lab Work

My lab programs from B.Tech coursework, grouped by subject: AI search algorithms, automata and compiler design, computer networks, and the design and analysis of algorithms.

## 🤖 [AI Lab](ai-lab)
| Program | Topic |
|---|---|
| `a_star.py` | A* search |
| `alpha_beta_pruning.py` | Minimax with alpha-beta pruning |
| `hillclimbing.py` | Hill-climbing local search |
| `genetic8puzzle.py` | Genetic algorithm for the 8-puzzle |
| `puzzle.py`, `c.cpp` | 8-puzzle state-space search (Python, C++) |
| `lab2exp1.py`, `lab2exp2.py` | Python basics: calculator, leap year |

## 🔤 [Automata / Compiler Design Lab](automata-lab)
| Program | Topic |
|---|---|
| `dfa1.cpp`, `dfa2.cpp` | DFA simulation |
| `ex1.c` | FIRST and FOLLOW sets of a grammar |
| `ex2.c` | Eliminating left recursion |
| `recurrsiveparser.cpp` | Recursive-descent parser |
| `projectauto.cpp` | Regular expression → NFA (Thompson construction) |
| `t.l`, `tt.l` | Lex programs: Pascal token recogniser, symbol table |

## 🌐 [Computer Networks Lab](computer-networks-lab)
| Program | Topic |
|---|---|
| `LAB2/` | Routing graphs: Dijkstra, Prim, Kruskal |
| `lab3/task1.cpp` | Hamming distance (error detection) |
| `lab4/` | Bit stuffing and byte stuffing (framing) |
| `LAB5/` | Flow control: Stop-and-Wait, Go-Back-N, Selective Repeat |
| `lab8/bell.cpp` | Distance-vector routing (Bellman-Ford) |
| `NETWORK.CPP` | Shortest paths on an 8-node network |
| `udp-socket/` | UDP client and server in Python |

## 📈 [Design & Analysis of Algorithms Lab](daa-lab)
| Program | Topic |
|---|---|
| `lab1/` | Min/max: linear scan vs divide and conquer |
| `lab2/` | Binary search (iterative and recursive) |
| `lab5/job.cpp`, `exam/jobsq.cpp` | Job sequencing with deadlines (greedy) |
| `lab6/` | Minimum spanning trees: Prim, Kruskal |
| `lab9.cpp` | Dijkstra with a priority queue |
| `exam/huffman.cpp` | Huffman coding |
| `exam/matrixmul.cpp`, `exam/strassenmulti.cpp` | Matrix multiplication: naive vs Strassen |

## Build & run
```bash
g++ -std=c++17 file.cpp -o prog && ./prog          # C++
gcc file.c -o prog && ./prog                       # C
python3 file.py                                    # Python
lex file.l && gcc lex.yy.c -o lexer -ll && ./lexer # Lex
```
