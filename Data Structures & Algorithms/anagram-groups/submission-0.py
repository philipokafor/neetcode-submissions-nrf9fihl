class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anas = dict()
        for word in strs:
            lets = ''.join(sorted(word))
            if lets in anas:
                anas[lets].append(word)
            else:
                anas[lets] = [word]
        print(anas.values())
        return list(anas.values())
        