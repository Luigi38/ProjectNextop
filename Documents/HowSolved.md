# 가장 어려웠던 문제 모음, 어떻게 풀었는가?
## [N-Queen](http://boj.kr/9663)
### 3월 28일, 첫 시도
- [1번째 시도](../Baekjoon/21/Brute-Force/Footprints/N-Queen/nqueen_t1_d.cpp)

dfs랑 bfs를 섞은 구조로 짰었습니다.
하지만 정답이 하나도 근사하게 나오지 않아서 코드를 버리고 다시 시도했습니다.

### 5월 2일, 멘붕의 날
- [2번째 시도](../Baekjoon/21/Brute-Force/Footprints/N-Queen/nqueen_t2_d.cpp)

dfs랑 bfs (그래프) 구조를 거의 버리고 코드를 짜기 시작했습니다.
사실 그래프 구조를 살짝 살려두긴 했습니다. 남은 흔적이 `main()` 함수에 있는 좌표들을 저장하고 `bohemian_rhapsody()` 함수에 모든 대입 공격을 하는 방식으로 짰습니다.

`attack()` 함수로 만약 `p1` 좌표에서 `p2` 좌표로 Queen이 이동할 수 있는지의 여부를 따지려 만들려고 했었는데,
멘탈이 붕괴가 되었습니다.

### 5월 9일, 경우의 수
- [3번째 시도](../Baekjoon/21/Brute-Force/Footprints/N-Queen/nqueen_t3.cpp)

다행히 완전 탐색 구조 (dfs)로 코드를 짰습니다.
3월 20일에 [로또](../Baekjoon/21/Brute-Force/lotto.cpp)를 풀어서 완전 탐색 구조는 어느정도 알고 있었기 때문에 로또 코드를 짤 때 보다 쉽게 짰던 기억이 납니다.

하지만, N-Queen에서는 **백트래킹**을 적용하지 않아서 시간 복잡도가 O(2^N), (N = 14). 즉 2^196번을 돌아야 탐색이 끝나야 했던 겁니다.

따라서 이 때 무엇을 해야 최적화, 즉 `미리 규칙을 정할 수 있다면?` 라는 생각을 해보게 되었습니다.

### 5월 16일, 백트래킹이 등장하다
- [4번째 시도](../Baekjoon/21/Brute-Force/Footprints/N-Queen/nqueen_t4.cpp)

백트래킹을 짜게 되었지만,
진정한 백트래킹이 아니였습니다. 아직 `record()` 함수에 while 문이 들어가 있어서 다시 시간 초과가 나오게 되었습니다.

### 5월 23일, 혁신
**혁신**이라는 정의를 소개하기 위해서는, 일단 떡밥을 뿌리고 와야 사전준비가 완료됩니다.

- 5시간동안 탈옥 시도
- `record()` 함수 DELETED **?**
- 무언가의 변화.
- 전체적인 Colourful 시도

넵. 이제 시작하겠습니다.

- [5번째 시도](../Baekjoon/21/Brute-Force/N-Queen/Footprints/nqueen_t5_v1.cpp)

저에게는 이 코드가 저의 최선이였습니다.
가장 아름답고 완벽했던, 코드였죠.

하지만 " **내일의 코드는 오늘의 최선이다.** " 라는 말이 있죠.
드디어 **무언가의 변화**가 시작됩니다.

- [6번째 시도](../main/Baekjoon/21/Brute-Force/N-Queen/Footprints/nqueen_t5_v2.cpp)

드디어 `record()` 함수 부분을 O(N)에서 O(1)로 바꼈습니다. 즉 상수 시간으로 개선된거죠.

하지만 이래도 시간 초과였습니다. `왜일까?` 라고 생각을 하게 된 계기가 되었습니다.

떡밥을 다시 뿌려봅니다. **1차원으로 생각하지 말고, 2차원으로 봐야한다고...**

- [7번째 시도](../main/Baekjoon/21/Brute-Force/N-Queen/Footprints/nqueen_t5_v3.cpp)

`record()` 함수가 좀 더 정석적인 코드로 변경이 되었습니다.
여기서 더 말할 게 없습니다. 왜냐하면 5시간 반의 4/5는 생각을 하고, 나머지는 코드를 짰기 때문이죠.

하지만 생각은 더 이상 개선이 되지 않았습니다. **5월 30일이 되기 전 까지는...**

### 5월 30일, Fin
- [N-Queen의 정석](../Baekjoon/21/Brute-Force/nqueen.cpp)

5월 23일의 5번째 시도에 뿌렸던 떡밥이 이제서야 풀렸습니다.

`dfs()` 함수를 호출 할 때 칸 별로 호출하는게 아닌 줄 별로 호출을 하였습니다.
따라서 `dfs()` 구조도 완벽히 변경하였습니다.

코드를 완벽히 리뉴얼 하여서 엄청 간편해졌습니다.
그래서 뭔가 허탈감이 있긴 했습니다. 하지만 N-Queen을 풀었으니 다행입니다!

**GG**

## [꿀 따기](http://boj.kr/21758)
소설을 쓰는 중... (0 / 9)

## [다이어트](http://boj.kr/19942)
소설을 쓰는 중... (0 / 3)
