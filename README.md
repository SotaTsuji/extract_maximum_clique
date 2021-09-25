# extract_maximum_clique

グラフスペクトルによる多項式時間最大クリーク抽出の実装  
Implementation of Polynomial-time Extraction of the Maximum Clique Using Eigenvalue Relation  
進行中 in progress

参考文献 References  
Author - Yasunori Ohto  
日本語版: https://www.researchgate.net/publication/348225014_gurafusupekutoruniyoruduoxiangshishijianzuidakurikuchouchu  
English version: https://www.researchgate.net/publication/347522479_Polynomial-time_Extraction_of_the_Maximum_Clique_Using_Eigenvalue_Relation  

# Requirement

* compiler that implements c++20
* cmake 3.10
* boost 1.74.0
* googletest 1.11.0

# Usage

```bash
mkdir build
cd build
cmake ..
make
make test
```

# Note

現在、get_coefficientは多項式時間で動きません。  
後ほど、多項式時間のアルゴリズムに置き換えます(実装が大変なため後回しにしています)。  
Currently, "get_coefficient" is NOT a polynomial-time algorithm.  
Later, we are going to replace it with a polynomial-time algorithm.  
(The implementation of a polynomial-time algorithm is difficult, so we are putting it off).

# Author

* Sota Tsuji
* Kyoto University
* tuzisou201p@gmail.com

# License

The source code is licensed MIT, see LICENSE.
