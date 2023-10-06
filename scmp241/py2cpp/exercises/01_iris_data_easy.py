from typing import Dict

if __name__ == '__main__':
    f = open('data/iris_shuffled.dat', 'r')

    counts: Dict[str, int] = {}
    sums: Dict[str, float] = {}

    for row in f:
        row = row.split()
        species = row[0]
        if not species in counts:
            counts[species] = 0
            sums[species] = 0
        counts[species] += 1
        sums[species] += float(row[1])
    
    for species, datum in sums.items():
        print(species, datum)