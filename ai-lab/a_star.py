# a* algorithm implementation in python
def a_star_algorithm(start, goal, h):
    open_set = set()
    open_set.add(start)
    came_from = {}
    g_score = {start: 0}
    f_score = {start: h[start]}

    while open_set:
        current = min(open_set, key=lambda x: f_score.get(x, float('inf')))

        if current == goal:
            return reconstruct_path(came_from, current)

        open_set.remove(current)

        for neighbor in get_neighbors(current):
            tentative_g_score = g_score[current] + get_cost(current, neighbor)

            if tentative_g_score < g_score.get(neighbor, float('inf')):
                came_from[neighbor] = current
                g_score[neighbor] = tentative_g_score
                f_score[neighbor] = g_score[neighbor] + h[neighbor]

                if neighbor not in open_set:
                    open_set.add(neighbor)

    return None # No path found 
