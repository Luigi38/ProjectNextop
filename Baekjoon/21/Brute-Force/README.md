# 완전 탐색 (Brute-Force)
|소스 코드|문제 제목|시도 횟수|언어|성공 여부|날짜|설명|
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|[decomposition.cpp](../Brute-Force/decomposition.cpp)|[분해합](http://boj.kr/2231)|1|C++|성공|3/6/2021|
|[lotto_d.cpp](../Brute-Force/Footprints/lotto.cpp)|[로또](http://boj.kr/6603)|1|C++|아직 안함|3/13/2021|하다가 때려칠 수도?|
|[lotto.cpp](../Brute-Force/lotto.cpp)|[로또](http://boj.kr/6603)|2|C++|성공|3/20/2021|`lotto_d.cpp` 코드는 하다가 답이 없어서 때려침. DFS로 대체함|

# N-Queen
|소스 코드|문제 제목|시도 횟수|언어|성공 여부|날짜|설명|
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|[nQueen_t1_d.cpp](../Brute-Force/Footprints/N-Queen/nqueen_t1_d.cpp)|[N-Queen](http://boj.kr/9663)|1|C++|아직 안함|3/28/2021|하다가 때려쳤음. 다음 시간에 코드를 다시 짤거임.|
|[nqueen_t2_d.cpp](../Brute-Force/Footprints/N-Queen/nqueen_t2_d.cpp)|[N-Queen](http://boj.kr/9663)|2|C++|아직 안함|5/2/2021|한 번 갈아엎고 다시 하다가 때려침. 진심 답이 없는 것 같음. 다음 번에는 선생님께 물어볼거임.|
|[nqueen_t3.cpp](../Brute-Force/Footprints/N-Queen/nqueen_t3.cpp)|[N-Queen](http://boj.kr/9663)|3|C++|메모리 초과|5/9/2021|다시 한번 갈아 엎으려다가 수정해서 겨우 힘들게 만들었는데 2^196번 탐색을 해야하는 경우에서 좌절했음. 다음 시간에 백트랙킹으로 마무리하면 됨. 거의 다 끝남. BOHEMIAN RHAPSODY|
|[nqueen_t4.cpp](../Brute-Force/Footprints/N-Queen/nqueen_t4.cpp)|[N-Queen](http://boj.kr/9663)|4|C++|시간 초과|5/16/2021|어떻게 백트래킹으로 해도 시간 초과지? 이건 답이 없음. 최악의 시간 복잡도는 O(2^N×N^2*2)|
|[nqueen_t5_v1.cpp](../Brute-Force/Footprints/N-Queen/nqueen_t5_v1.cpp)|[N-Queen](http://boj.kr/9663)|5|C++|시간 초과|5/23/2021|record() 함수 갈아 엎기 전 소스 코드
|[nqueen_t5_v2.cpp](../Brute-Force/Footprints/N-Queen/nqueen_t5_v2.cpp)|[N-Queen](http://boj.kr/9663)|6|C++|시간 초과|5/23/2021|record() 함수 갈아 엎은 후 소스 코드. 1로 롤백 예정|
|[nqueen_t5_v3.cpp](../Brute-Force/Footprints/N-Queen/nqueen_t5_v3.cpp)|[N-Queen](http://boj.kr/9663)|7|C++|시간 초과|5/23/2021|답이 없음. 아 정말. 아 진짜. 5시간 반 동안 갇힌 이유가 사라짐 그냥 다음에 선생님께 물어보는걸로|
|[nqueen_pls_final.cpp](../Brute-Force/nqueen.cpp)|[N-Queen](http://boj.kr/9663), [N-Queen 문제 풀이](http://sooyoung32.github.io/dev/2016/03/14/n-queen-algorithm.html)|8|C++|성공|5/30/2021|와 드디어 끝남. 이렇게 단순하게 풀어버리니깐 그동안 만들었던 나만의 알고리즘과 함수들이 갑자기 허무해짐. 아무튼 GG|