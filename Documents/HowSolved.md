# 가장 어려웠던 문제 모음, 어떻게 풀었는가?
## [N-Queen](http://boj.kr/9663)
3월 28일, [1번째 시도](../Baekjoon/21/Brute-Force/Footprints/N-Queen/nQueen_03_28.cpp) 때 dfs랑 bfs를 섞은 구조로 짰었습니다.
하지만 정답이 하나도 근사하게 나오지 않아서 코드를 버리고 다시 시도했습니다.

5월 2일, [2번째 시도](../Baekjoon/21/Brute-Force/Footprints/N-Queen/nqueen_05_02.cpp) 때는 dfs랑 bfs (그래프) 구조를 거의 버리고 코드를 짜기 시작했습니다.
사실 그래프 구조를 살짝 살려두긴 했습니다. 남은 흔적이 `main()` 함수에 있는 좌표들을 저장하고 `bohemian_rhapsody()` 함수에 모든 대입 공격을 하는 방식으로 짰습니다.

`attack()` 함수로 만약 `p1` 좌표에서 `p2` 좌표로 Queen이 이동할 수 있는지의 여부를 따지려 만들려고 했었는데,
멘탈이 붕괴가 되었습니다.

5월 9일, [3번째 시도](../Baekjoon/21/Brute-Force/Footprints/N-Queen/nqueen_05_09.cpp) 때에는 다행히 완전 탐색 구조 (dfs)로 코드를 짰습니다.
3월 20일에 [로또](../Baekjoon/21/Brute-Force/lotto.cpp)

하지만, **백트래킹**을 적용하지 않아서 시간 복잡도가 O(2^N), (N = 14). 즉 2^196번을 돌아야 탐색이 끝나야 했던 겁니다.

따라서 이 때 무엇을 해야 


[N번째 시도](../Baekjoon/21/Brute-Force/N-Queen/)

## [꿀 따기](http://boj.kr/21758)
ㅁ

## [다이어트](http://boj.kr/19942)
ㅁ
