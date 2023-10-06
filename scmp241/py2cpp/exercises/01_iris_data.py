from typing import Dict, List

if __name__ == '__main__':
    f = open('data/iris_shuffled.dat', 'r')

    n = 4 # Number of numeric columns

    counts: Dict[str, int] = {}
    sums: Dict[str, List[float]] = {}

    for row in f:
        row = row.split()
        species = row[0]
        if not species in counts:
            counts[species] = 0
            sums[species] = [0] * n
        counts[species] += 1
        for col in range(n):
            datum = float(row[col + 1])
            sums[species][col] += datum
    
    for species, data in sums.items():
        print(species, end=' ')
        for datum in data:
            print(f'{datum / counts[species]:.3f}', end=' ')
        print()