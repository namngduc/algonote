from typing import List
from collections import defaultdict

class Solution:
    def findAllRecipes(self, recipes: List[str], ingredients: List[List[str]], supplies: List[str]) -> List[str]:
        sup = set(supplies)
        graph = defaultdict(list)
        indgre = dict()
        for ele in recipes:
            indgre[ele] = 0
        for i in range(len(recipes)):
            for j in range(len(ingredients[i])):
                if ingredients[i][j] not in sup:
                    graph[ingredients[i][j]].append(recipes[i])
                    indgre[recipes[i]] = indgre.get(recipes[i], 0) + 1
        # print(graph, indgre)
        visited = set()
        pos = []
        def dfs(start, graph):
            if start in visited:
                return
            visited.add(start)
            for node in graph[start]:
                indgre[node] -= 1
                if indgre[node] == 0:
                    dfs(node, graph)
            pos.append(start)
        for k, v in indgre.items():
            if v==0:
                dfs(k, graph)
        return pos


so = Solution()
recipes = ["xevvq","izcad","p","we","bxgnm","vpio","i","hjvu","igi","anp","tokfq","z","kwdmb","g","qb","q","b","hthy"]
ingredients = [["wbjr"],["otr","fzr","g"],["fzr","wi","otr","xgp","wbjr","igi","b"],["fzr","xgp","wi","otr","tokfq","izcad","igi","xevvq","i","anp"],["wi","xgp","wbjr"],["wbjr","bxgnm","i","b","hjvu","izcad","igi","z","g"],["xgp","otr","wbjr"],["wbjr","otr"],["wbjr","otr","fzr","wi","xgp","hjvu","tokfq","z","kwdmb"],["xgp","wi","wbjr","bxgnm","izcad","p","xevvq"],["bxgnm"],["wi","fzr","otr","wbjr"],["wbjr","wi","fzr","xgp","otr","g","b","p"],["otr","fzr","xgp","wbjr"],["xgp","wbjr","q","vpio","tokfq","we"],["wbjr","wi","xgp","we"],["wbjr"],["wi"]]
supplies = ["wi","otr","wbjr","fzr","xgp"]
result = so.findAllRecipes(recipes, ingredients, supplies)
print(result)
assert result == ["xevvq","izcad","bxgnm","i","hjvu","tokfq","z","g","b","hthy"]