//https://leetcode.com/problems/koko-eating-bananas/
#define ll long long

//* Pra esse problema funcionar vc deve considerar que h>=n
class Solution {
public:
    bool f(int x, vector<int>& piles, int h){
        // basta calcular quantas horas ela precisaria pra comer 
        // tudo e comparar com h, se for menor devolve true
        ll tempo_necessario = 0;
        for (double pilha : piles){
            int tempo_pilha = ceil(pilha/x);
            tempo_necessario += tempo_pilha ;
        }
        return tempo_necessario <= h;
    }


    int minEatingSpeed(vector<int>& piles, int h) {
        // busca binária na resposta FFFTTTTT
        // precisamos de uma f(x) que diz se ela consegue
        // comer todas as bananas em h horas se comer x por vez 
        int lo = 1;
        int hi = 1e9; // pq considerando * esse é o maior valor que da certo com certeza
        while (lo<hi){
            int mid = lo+(hi-lo)/2;
            if (f(mid,piles,h)){
                hi = mid;
            }
            else{
                lo = mid+1;
            }
        }
        return hi;
    }
};
