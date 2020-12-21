class Solution:
    def beforeAndAfterPuzzles(self, phrases: List[str]) -> List[str]:
        # creating the set dictionary
        dict = defaultdict(set)
        # enumerate gives each element in the form of ([index, value])
        for index, phrase in enumerate(phrases):
            # split() is a stringstream
            words = phrase.split()
            # Add firstword as a key with its index and full sentence
            dict[words[0]].add((index, phrase));

        output = []

        for index, phrase in enumerate(phrases):
            words = phrase.split()
            # Find the index and pphrase of last word
            for jndex, pphrase in dict[words[-1]]:
                if index != jndex: # to avoid sentence such as "word is word"
                    output.append(" ".join(words[:-1] + pphrase.split()))

        return sorted(set(output))
