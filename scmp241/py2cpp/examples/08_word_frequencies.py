from typing import Dict, List, Tuple

def read_text(filename: str) -> str:
    """Read entire content of a file."""
    with open(filename, 'r') as f:
        return f.read()

def process_text(text: str) -> str:
    """Remove punctuation and change to lowercase."""
    punctuation = '!"&\'()[]-,.:;?'
    for c in punctuation:
        text = text.replace(c, ' ')
    text = text.lower()
    return text

def count_appearances(text: str) -> Dict[str, int]:
    """Count the number of times each word appears in input."""
    word_counts = {}
    word_list = text.split()
    for word in word_list:
        try:
            word_counts[word] += 1
        except KeyError:
            word_counts[word] = 1
    return word_counts

def sorted_word_list(word_counts: Dict[str, int]) -> List[Tuple[str, int]]:
    """Create a sorted list from a dictionary based on an item's value."""
    word_counts_sorted = sorted(word_counts.items(), key=lambda a: a[1], reverse=True)
    return word_counts_sorted

if __name__ == '__main__':
    text = read_text('data/shakespeare.txt')
    text = process_text(text)
    word_counts = count_appearances(text)
    word_counts_sorted = sorted_word_list(word_counts)

    for word, count in word_counts_sorted[:20]:
        print(word, count)