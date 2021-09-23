/*
Created by S.Tsuji, since 2021.9.22
Yasunori Ohtoによる
グラフスペクトルによる多項式時間最大クリーク抽出
(Polynomial-time Extraction of
the Maximum Clique Using Eigenvalue Relation)
内のアルゴリズム(順次追加予定)
論文url
日本語版
https://www.researchgate.net/publication/348225014_gurafusupekutoruniyoruduoxiangshishijianzuidakurikuchouchu
英語版(English version)
https://www.researchgate.net/publication/347522479_Polynomial-time_Extraction_of_the_Maximum_Clique_Using_Eigenvalue_Relation
*/

#include "../include/weight_graph.hpp"

// Algorithm 1
bool is_complete_graph(const WeightGraph& T) {
    auto es = T.e.size(), vs = T.v.size();
    if (es == (vs * vs - vs) / 2) {
        for (auto i = 0; i < vs - 1; ++i) {
            for (auto j = i + 1; j < vs; ++j) {
                if (T.w.at({T.v[i], T.v[j]}) != 1) {
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}
