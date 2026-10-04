from collections import deque

# Goal State
GOAL_STATE = (
    (1, 2, 3),
    (4, 5, 6),
    (7, 8, 0)
)

# Possible moves: up, down, left, right
MOVES = [(-1, 0), (1, 0), (0, -1), (0, 1)]


def find_blank(state):
    """Find position of blank (0)"""
    for i in range(3):
        for j in range(3):
            if state[i][j] == 0:
                return i, j


def generate_states(state):
    """Generate all valid next states"""
    x, y = find_blank(state)
    next_states = []

    for dx, dy in MOVES:
        nx, ny = x + dx, y + dy
        if 0 <= nx < 3 and 0 <= ny < 3:
            new_state = [list(row) for row in state]
            new_state[x][y], new_state[nx][ny] = new_state[nx][ny], new_state[x][y]
            next_states.append(tuple(tuple(row) for row in new_state))

    return next_states


def bfs(initial_state):
    """Breadth-First Search"""
    queue = deque([(initial_state, [initial_state])])
    visited = set()

    while queue:
        state, path = queue.popleft()

        if state == GOAL_STATE:
            return path

        visited.add(state)

        for next_state in generate_states(state):
            if next_state not in visited:
                queue.append((next_state, path + [next_state]))

    return None


# def dfs(initial_state):
#     """Depth-First Search"""
#     stack = [(initial_state, [initial_state])]
#     visited = set()

#     while stack:
#         state, path = stack.pop()

#         if state == GOAL_STATE:
#             return path

#         visited.add(state)

#         for next_state in generate_states(state):
#             if next_state not in visited:
#                 stack.append((next_state, path + [next_state]))

#     return None


# Initial State
initial_state = (
    (1, 2, 3),
    (4, 0, 5),
    (6, 7, 8)
)

# BFS Solution
bfs_path = bfs(initial_state)
print("BFS Solution:")
for step in bfs_path:
    print(step)

print("\nDFS Solution:")
# dfs_path = dfs(initial_state)
# for step in dfs_path:
#     print(step)
