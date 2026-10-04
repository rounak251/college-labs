def minimax(depth, node_index, is_maximizing, values, alpha, beta, max_depth):
    # Base case: leaf node
    if depth == max_depth:
        return values[node_index]

    if is_maximizing:
        best = float('-inf')

        for i in range(2):  # binary tree (2 children)
            val = minimax(depth + 1,
                          node_index * 2 + i,
                          False,
                          values,
                          alpha,
                          beta,
                          max_depth)
            
            best = max(best, val)
            alpha = max(alpha, best)

            # Alpha-Beta Pruning
            if beta <= alpha:
                break

        return best

    else:
        best = float('inf')

        for i in range(2):
            val = minimax(depth + 1,
                          node_index * 2 + i,
                          True,
                          values,
                          alpha,
                          beta,
                          max_depth)
            
            best = min(best, val)
            beta = min(beta, best)

            # Alpha-Beta Pruning
            if beta <= alpha:
                break

        return best