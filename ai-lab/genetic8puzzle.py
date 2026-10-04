import random

N = 8
POP_SIZE = 50


# Generate random board
def random_board():
    board = list(range(N))
    random.shuffle(board)
    return board


# Fitness function (count conflicts)
def fitness(board):
    conflicts = 0
    
    for i in range(N):
        for j in range(i+1, N):
            if abs(board[i] - board[j]) == abs(i - j):
                conflicts += 1
                
    return -conflicts


# Crossover
def crossover(p1, p2):
    cut = random.randint(0, N-1)
    return p1[:cut] + p2[cut:]


# Mutation
def mutate(board):
    if random.random() < 0.1:
        i, j = random.sample(range(N),2)
        board[i], board[j] = board[j], board[i]
    return board


# Genetic Algorithm
population = [random_board() for _ in range(POP_SIZE)]

for generation in range(1000):

    population = sorted(population, key=fitness, reverse=True)

    if fitness(population[0]) == 0:
        print("Solution found:", population[0])
        break

    new_population = population[:10]

    while len(new_population) < POP_SIZE:
        p1, p2 = random.sample(population[:20],2)
        child = crossover(p1,p2)
        child = mutate(child)
        new_population.append(child)

    population = new_population
    