// https://leetcode.com/problems/daily-temperatures

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // a ideia é varrer o array da direita pra esquerda
        // quando estivermos com um elemento na mão
        // todos os necessários da direita dele vão estar 
        // na stack e aí como queremos um maior, tiramos
        // elementos do topo enquanto o topo for menor que o que
        // temos na mão afinal queremos o proximo maior
        vector<pair<int,int>> pares(temperatures.size());
        for (int i = 0;i<temperatures.size();i++){
            pares[i].first = temperatures[i];
            pares[i].second = i;
        }
        stack<pair<int,int>> s;
        vector<int> indice_maior_direita(temperatures.size());
        s.push({INT_MAX,0});
        for (int i = temperatures.size()-1;i>=0;i--){
            while (pares[i].first>=s.top().first) s.pop();
            if (s.top().first == INT_MAX) indice_maior_direita[i] = 0;
            else indice_maior_direita[i] = s.top().second - i;
            s.push(pares[i]);
        }
        return indice_maior_direita;
    }
};