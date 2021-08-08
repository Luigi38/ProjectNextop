# ProjectNextop
넥스탑 👍

- [용어사전](../main/Documents/WordDictionary.md)
- [정보보호영재교육원 2021](../../tree/main/SWU)
- [가장 어려웠던 문제 모음, 어떻게 풀었을까?](../main/Documents/HowSolved.md)
- [백엔드 모든 개념 총정리](../main/Documents/Backend.md)

## 바로가기
- [프로그래머스 - 코딩테스트 연습](https://programmers.co.kr/learn/challenges)

## 백준 문제
### 완전 탐색 (Brute-Force)
|소스 코드|문제 제목|시도 횟수|언어|성공 여부|날짜|설명|
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|[decomposition.cpp](../main/Baekjoon/21/Brute-Force/decomposition.cpp)|[분해합](http://boj.kr/2231)|1|C++|성공|3/6/2021|

### 완전 탐색 (N-Queen)
|소스 코드|문제 제목|시도 횟수|언어|성공 여부|날짜|설명|
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|[nqueen_05_30_pls_final.cpp](../main/Baekjoon/21/Brute-Force/N-Queen/nqueen_05_30_pls_final.cpp)|[N-Queen](http://boj.kr/9663), [N-Queen 문제 풀이](http://sooyoung32.github.io/dev/2016/03/14/n-queen-algorithm.html)|8|C++|성공|05/30|와 드디어 끝남. 이렇게 단순하게 풀어버리니깐 그동안 만들었던 나만의 알고리즘과 함수들이 갑자기 허무해짐. 아무튼 GG|
|[nqueen_05_23_3.cpp](../main/Baekjoon/21/Brute-Force/N-Queen/nqueen_05_23_3.cpp)|[N-Queen](http://boj.kr/9663), [N-Queen 문제 풀이](http://sooyoung32.github.io/dev/2016/03/14/n-queen-algorithm.html)|7|C++|시간 초과|5/23/2021|답이 없음. 아 정말. 아 진짜. 5시간 반 동안 갇힌 이유가 사라짐 그냥 다음에 선생님께 물어보는걸로|
|[nqueen_05_23_2.cpp](../main/Baekjoon/21/Brute-Force/N-Queen/nqueen_05_23_2.cpp)|[N-Queen](http://boj.kr/9663), [N-Queen 문제 풀이](http://sooyoung32.github.io/dev/2016/03/14/n-queen-algorithm.html)|6|C++|시간 초과|5/23/2021|record() 함수 갈아 엎은 후 소스 코드. 1로 롤백 예정|
|[nqueen_05_23_1.cpp](../main/Baekjoon/21/Brute-Force/N-Queen/nqueen_05_23_1.cpp)|[N-Queen](http://boj.kr/9663), [N-Queen 문제 풀이](http://sooyoung32.github.io/dev/2016/03/14/n-queen-algorithm.html)|5|C++|시간 초과|5/23/2021|record() 함수 갈아 엎기 전 소스 코드
|[nqueen_05_16.cpp](../main/Baekjoon/21/Brute-Force/N-Queen/nqueen_05_16.cpp)|[N-Queen](http://boj.kr/9663), [N-Queen 문제 풀이](http://sooyoung32.github.io/dev/2016/03/14/n-queen-algorithm.html)|4|C++|시간 초과|5/16/2021|어떻게 백트래킹으로 해도 시간 초과지? 이건 답이 없음. 최악의 시간 복잡도는 O(2^N×N^2*2)|
|[nqueen_05_09.cpp](../main/Baekjoon/21/Brute-Force/N-Queen/nqueen_05_09.cpp)|[N-Queen](http://boj.kr/9663), [N-Queen 문제 풀이](http://sooyoung32.github.io/dev/2016/03/14/n-queen-algorithm.html)|3|C++|메모리 초과|5/9/2021|다시 한번 갈아 엎으려다가 수정해서 겨우 힘들게 만들었는데 2^196번 탐색을 해야하는 경우에서 좌절했음. 다음 시간에 백트랙킹으로 마무리하면 됨. 거의 다 끝남. BOHEMIAN RHAPSODY|
|[nqueen_05_02.cpp](../main/Baekjoon/21/Brute-Force/N-Queen/nqueen_05_02.cpp)|[N-Queen](http://boj.kr/9663)|2|C++|아직 안함|5/2/2021|한 번 갈아엎고 다시 하다가 때려침. 진심 답이 없는 것 같음. 다음 번에는 선생님께 물어볼거임.|
|[nQueen_03_28.cpp](../main/Baekjoon/21/Brute-Force/N-Queen/nQueen_03_28.cpp)|[N-Queen](http://boj.kr/9663)|1|C++|아직 안함|3/28/2021|하다가 때려쳤음. 다음 시간에 코드를 다시 짤거임.|

### 동적 계획법 (DP)
|소스 코드|문제 제목|시도 횟수|언어|성공 여부|날짜|설명|
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|[essence_triangle_02.cpp](../main/Baekjoon/21/DP/essence_triangle_02.cpp)|[정수 삼각형](http://boj.kr/1932)|2|C++|성공|7/11/2021|막상 해보니깐 쉬운데 풀 때는 진짜 어려운 것 같음. dp는 v의 배열 구조에 따라서 유동적으로 변할 수 있구나.. 라고 생각을 하게 됨.|
|[essence_triangle.cpp](../main/Baekjoon/21/DP/essence_triangle.cpp)|[정수 삼각형](http://boj.kr/1932)|1|C++|아직 안함|7/11/2021|머리 터질 것 같아서 때려침.|
|[rise_stair.cpp](../main/Baekjoon/21/DP/rise_stair.cpp)|[계단 오르기](http://boj.kr/2579)|1|C++|성공|7/4/2021|
|[make_to_one.cpp](../main/Baekjoon/21/DP/make_to_one.cpp)|[1로 만들기](http://boj.kr/1463)|1|C++|성공|6/27/2021|
|[fibonacci_improved.cpp](../main/Baekjoon/21/DP/fibonacci_improved.cpp)|[피보나치 함수](http://boj.kr/1003)|1|C++|성공|6/27/2021|O(N)|
|[fibonacci.cpp](../main/Baekjoon/21/DP/fibonacci.cpp)|[피보나치 함수](http://boj.kr/1003)|1|C++|성공|6/27/2021|원래 정석적인 방법은 O(N)인데 나는 O(N - 5)로 해결함. 이게 맞나?|

### 자료구조
|소스 코드|문제 제목|시도 횟수|언어|성공 여부|날짜|설명|
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|[min_heap.cpp](../main/Baekjoon/21/Data%20Structure/min_heap.cpp)|[최소 힙](http://boj.kr/1927)|1|C++|성공|7/18/2021|
|[max_heap.cpp](../main/Baekjoon/21/Data%20Structure/max_heap.cpp)|[최대 힙](http://boj.kr/11279)|1|C++|성공|7/18/2021|

### 그래프 (BFS & DFS)
|소스 코드|문제 제목|시도 횟수|언어|성공 여부|날짜|설명|
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|[virus.cpp](../main/Baekjoon/21/Graph/virus.cpp)|[바이러스](http://boj.kr/2606)|1|C++|성공|7/4/2021|
|[paste_complex.cpp](../main/Baekjoon/21/Graph/paste_complex.cpp)|[단지번호붙이기](http://boj.kr/2667)|1|C++|성공|6/20/2021|문제 자체는 쉬웠는데 좀 애먹었음. GG|
|[dfs_and_bfs.cpp](../main/Baekjoon/21/Graph/dfs_and_bfs.cpp)|[DFS와 BFS](http://boj.kr/1260)|1|C++|성공|6/20/2021|쉽ね。|
|[lotto_03_20.cpp](../main/Baekjoon/21/Graph/lotto_03_20.cpp)|[로또](http://boj.kr/6603)|2|C++|성공|3/20/2021|lotto_03_13은 하다가 답이 없어서 때려침. DFS로 대체함|
|[lotto_03_13.cpp](../main/Baekjoon/21/Graph/lotto_03_13.cpp)|[로또](http://boj.kr/6603)|1|C++|아직 안함|3/13/2021|하다가 때려칠 수도?|
|[tree_03_06.cpp](../main/Baekjoon/21/Graph/tree_03_06.cpp)|[트리의 부모 찾기](http://boj.kr/11725)|1|C++|성공|3/6/2021|
|[tree_02_27_failed.cpp](../main/Baekjoon/21/Graph/tree_02_27_failed.cpp)|[트리의 부모 찾기](http://boj.kr/11725)|1|C++|실패|2/27/2021|
|[tomato3.cpp](../main/Baekjoon/21/Graph/tomato3.cpp)|[토마토](http://boj.kr/7569)|1|C++|성공|2/20/2021|3차원 버전|
|[tomato.cpp](../main/Baekjoon/21/Graph/tomato.cpp)|[토마토](http://boj.kr/7576)|1|C++|성공|2/14/2021|2차원 버전|
|[search_miro_by_bfs.cpp](../main/Baekjoon/21/Graph/search_miro_by_bfs.cpp)|[미로 탐색](http://boj.kr/2178)|2|C++|성공|2/6/2021|
|[BDFS_Deprecated.cpp](../main/Baekjoon/21/Graph/BDFS_Deprecated.cpp)|[미로 탐색](http://boj.kr/2178)|1|C++|실패|2/6/2021|하다가 때려쳤음|

### 누적 합
|소스 코드|문제 제목|시도 횟수|언어|성공 여부|날짜|설명|
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|[total_number_of_2d_array_improved.cpp](../main/Baekjoon/21/Prefix%20Sum/total_number_of_2d_array_improved.cpp)|[2차원 배열의 합](http://boj.kr/2167)|1|C++|성공|8/8/2021|집합을 사용한 풀이, 시간 복잡도 재료: O(N * M), 답: O(K)|
|[total_number_of_2d_array.cpp](../main/Baekjoon/21/Prefix%20Sum/total_number_of_2d_array.cpp)|[2차원 배열의 합](http://boj.kr/2167)|1|C++|성공|8/8/2021|시도한지 1번만에 성공. 하지만 개선 케이스가 있다고 함. 시간 복잡도는 O(K * N)|

### Baekjoon / 21
|소스 코드|문제 제목|시도 횟수|언어|성공 여부|날짜|설명|
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|[DietOfSungWon.cpp](../main/Baekjoon/21/DietOfSungWon.cpp)|[다이어트](http://boj.kr/1484)|1|C++|성공|5/1/2021|한국정보올림피아드에서 나온 다이어트 문제 풀다가 개빡쳐서 이거 풀고 옴. 시간 복잡도는 O(n). SUNGWON|
|[prefix_01_31.cpp](../main/Baekjoon/21/prefix_01_31.cpp)|[후위 표기식](http://boj.kr/1918)|2|C++|성공|1/31/2021|
|[prefix_01_24.cpp](../main/Baekjoon/21/prefix_01_24.cpp)|[후위 표기식](http://boj.kr/1918)|1|C++|출력 초과|1/24/2021|

### Baekjoon / 20
|소스 코드|문제 제목|시도 횟수|언어|성공 여부|날짜|
|:---:|:---:|:---:|:---:|:---:|:---:|
|[reverseString2.cpp](../main/Baekjoon/20/reverseString2.cpp)|[문자열 뒤집기2](http://boj.kr/17413)|1|C++|성공|12/14/2020|
|[AC.cpp](../main/Baekjoon/20/AC.cpp)|[AC](http://boj.kr/5430)|1|C++|성공|12/13/2020|
|[stringExplosion3.cpp](../main/Baekjoon/20/stringExplosion3_12_06.cpp)|[문자열 폭발](http://boj.kr/9935)|4|C++|성공|12/6/2020|
|[keylogger.cpp](../main/Baekjoon/20/keylogger.cpp)|[키로거](http://boj.kr/5397)|1|C++|성공|12/6/2020|
|[editor.cpp](../main/Baekjoon/20/editor.cpp)|[에디터](http://boj.kr/1406)|1|C++|성공|11/28/2020|
|[StringExplosion.cpp](../main/Baekjoon/20/StringExplosion_11_28.cpp)|[문자열 폭발](http://boj.kr/9935)|3|C++|시간 초과|11/28/2020|
|[stringExplosion2.cpp](../main/Baekjoon/20/stringExplosion2_11_28.cpp)|[문자열 폭발](http://boj.kr/9935)|2|C++|시간 초과|11/28/2020|
|[StringExplosion.cpp](../main/Baekjoon/20/StringExplosion_11_21.cpp)|[문자열 폭발](http://boj.kr/9935)|C++|1|시간 초과|11/21/2020|

## 프로그래머스
### Programmers / 21
|소스 코드|문제 주제|시퀀스|문제 제목|시도 횟수|언어|성공 여부|날짜|설명|
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|[contact_list.cpp](../main/Programmers/21/Hash/contact_list.cpp)|[해시](https://programmers.co.kr/learn/courses/30/parts/12077)|2|[전화번호 목록](https://programmers.co.kr/learn/courses/30/lessons/42577)|1|C++|성공|7/25/2021|
|[unfinished_player.cpp](../main/Programmers/21/Hash/unfinished_player.cpp)|[해시](https://programmers.co.kr/learn/courses/30/parts/12077)|1|[완주하지 못한 선수](https://programmers.co.kr/learn/courses/30/lessons/42576)|1|C++|성공|7/25/2021|

## 한국정보올림피아드
### Koi / 21
|소스 코드|문제 수준|문제 제목|시도 횟수|언어|성공 여부|날짜|설명|
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|[honey_06_13_04.cpp](../main/Koi/21/honey_06_13_04.cpp)|중등부|[꿀 따기](http://boj.kr/21758)|9|C++|성공|6/13/2021|최댓값을 미리 구한다면? FINISH. GG, O(3N)|
|[honey_06_13_03.cpp](../main/Koi/21/honey_06_13_03.cpp)|중등부|[꿀 따기](http://boj.kr/21758)|8|C++|부분 성공 (55점)|6/13/2021|상황 3 규칙 개선, O(N^2)|
|[honey_06_13_02.cpp](../main/Koi/21/honey_06_13_02.cpp)|중등부|[꿀 따기](http://boj.kr/21758)|7|C++|부분 성공 (55점)|6/13/2021|`fly()` 함수 개선 버전. 기존 while문을 `DogHoneyJam_06_06.cpp`에 있는 미리 구하는 코드로 변경, O(N^2)|
|[honey_06_13_01.cpp](../main/Koi/21/honey_06_13_01.cpp)|중등부|[꿀 따기](http://boj.kr/21758)|6|C++|부분 성공 (24점)|6/13/2021|Idea [#3](../../issues/3), O(N^3)|
|[honey_06_06_02.cpp](../main/Koi/21/honey_06_06_02.cpp)|중등부|[꿀 따기](http://boj.kr/21758)|5|C++|시간 초과|6/6/2021|다음 시간에 개선 ㄱㄱ|
|[honey_06_06_01.cpp](../main/Koi/21/honey_06_06_01.cpp)|중등부|[꿀 따기](http://boj.kr/21758)|4|C++|때려침|6/6/2021|멘붕|
|[DogHoneyJam_06_06.cpp](../main/Koi/21/DogHoneyJam_06_06.cpp)|중등부|[꿀 따기](http://boj.kr/21758)|3|C++|실패|6/6/2021|DogHoneyJam 개선 버전. 왜 실패?|
|[honey.cpp](../main/Koi/21/honey.cpp)|중등부|[꿀 따기](http://boj.kr/21758)|2|C++|아직 안함|5/30/2021|만들다가 말았음. 밤새서 그런지 머리가 안돌아감.|
|[DogHoneyJam.cpp](../main/Koi/21/DogHoneyJam.cpp)|중등부|[꿀 따기](http://boj.kr/21758)|1|C++|부분 성공 (11점)|5/30/2021|삼중 포문 안에 while문을 `honey.cpp`처럼 값을 미리 구해서 할 수 있음. O(N^3*2N)|
|[e_eraser.cpp](../main/Koi/21/e_eraser.cpp)|초등부|[지우개](http://boj.kr/21756)|1|C++|성공|5/23/2021|EASY|

### Koi / 20
|소스 코드|문제 수준|문제 제목|시도 횟수|언어|성공 여부|날짜|설명|
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|[diet_05_02.cpp](../main/Koi/20/diet_05_02.cpp)|중등부|[다이어트](https://koi.or.kr/assets/koi/2020/1/problems/m2-problems.pdf), [다이어트 (백준)](http://boj.kr/19942)|3|C++|성공|5/2/2021|DFS랑 `higher_than_minimum()` 함수랑 `diet()` 함수 셋 다 문제였음. 아무튼 성공!|
|[diet_05_01.cpp](../main/Koi/20/diet_05_01.cpp)|중등부|[다이어트](https://koi.or.kr/assets/koi/2020/1/problems/m2-problems.pdf), [다이어트 (백준)](http://boj.kr/19942)|2|C++|실패|5/1/2021|전에 나왔던 오류는 고쳤는데 아직도 `diet()` 함수 코드 때문에 뭔가 계속 틀림. 예제는 맞음.|
|[hamburger.cpp](../main/Koi/20/hamburger.cpp)|중등부|[햄버거 분배](https://koi.or.kr/assets/koi/2020/1/problems/m2-problems.pdf)|1|C++|성공|4/18/2021|시간 복잡도 O(n)|
|[diet.cpp](../main/Koi/20/diet.cpp)|중등부|[다이어트](https://koi.or.kr/assets/koi/2020/1/problems/m2-problems.pdf)|1|C++|실패|4/18/2021|`diet()` 함수만 고치면 성공적으로 될거임.|

## OpenCV로 배우는 컴퓨터 비전과 머신러닝
### OpenCV / 21
|소스 코드|페이지 수|언어|날짜|설명|
|:---:|:---:|:---:|:---:|:---:|
|[Project REINFORCED](https://github.com/Nextop-OpenCV/ProjectReinforced)|.|C#|2/7/2021|레인포스 프로젝트로 옮김.|
|[colorOp.cpp](../main/OpenCV/21/colorOp.cpp)|334~345p|C++|1/31/2021|
|[inRange.cpp](../main/OpenCV/21/inRange.cpp)|346~356p|C++|1/31/2021|
|[hough.cpp](../main/OpenCV/21/hough.cpp)|320~331p|C++|1/24/2021|
|[LetsRemoveEdge.cpp](../main/OpenCV/21/LetsRemoveEdge.cpp)|304~319p|C++|1/17/2021|
|[affine.cpp](../main/OpenCV/21/affine.cpp)|276~302p|C++|1/10/2021|

### OpenCV / 20
|소스 코드|페이지 수|언어|날짜|설명|
|:---:|:---:|:---:|:---:|:---:|
|[opencv_example.cpp](../main/OpenCV/20/opencv_example.cpp)|.|C++|12/6/2020|OpenCV 예제|
|[lets_remove_noise.cpp](../main/OpenCV/20/lets_remove_noise.cpp)|265~274p|C++|12/6/2020|
|[image_arithmetic.cpp](../main/OpenCV/20/image_arithmetic.cpp)|230~238p|C++|11/29/2020|
|[logical.cpp](../main/OpenCV/20/logical.cpp)|239~242p|C++|11/29/2020|
|[filterer.cpp](../main/OpenCV/20/filterer.cpp)|244~265p|C++|11/29/2020|
|[contrast.cpp](../main/OpenCV/20/contrast.cpp)|207~213p|C++|11/22/2020|
|[histogram.cpp](../main/OpenCV/20/histogram.cpp)|213~227p|C++|11/22/2020|
|[brightness.cpp](../main/OpenCV/20/brightness.cpp)|196~207p|C++|11/15/2020|
|drawingEx.cpp|144~147p|C++|11/8/2020|
|MaskFiltering.cpp|180~183p|C++|11/8/2020|
|[LetsPlayVideo.cpp](../main/OpenCV/20/LetsPlayVideo.cpp)|135~138p|C++|11/1/2020|
|[LetsSaveVideo.cpp](../main/OpenCV/20/LetsSaveVideo.cpp)|138~143p|C++|11/1/2020|
|[MatOpEx4Mt.cpp](../main/OpenCV/20/MatOpEx4Mt.cpp)|95~112p|C++|10/25/2020|
|[ScalarOp.cpp](../main/OpenCV/20/ScalarOp.cpp)|116~118p|C++|10/25/2020|
|[InputArrayOp.cpp](../main/OpenCV/20/InputArrayOp.cpp)|119~120p|C++|10/25/2020|
|[video.cpp](../main/OpenCV/20/video.cpp)|124~135p|C++|10/25/2020|
|[HelloOpenCV.cpp](../main/OpenCV/20/HelloOpenCV.cpp)|49~52p|C++|10/18/2020|
|[MatOpEx.cpp](../main/OpenCV/20/MatOpEx.cpp)|90~95p|C++|10/18/2020|

## 자료구조
|소스 코드|페이지 수|언어|날짜|설명|
|:---:|:---:|:---:|:---:|:---:|
|[search_maze.cpp](../main/Data-Structure/search_maze.cpp)|135~141p|C++|11/14/2020|
|[brackets.cpp](../main/Data-Structure/brackets.cpp)|119~123p|C++|10/31/2020|
|[infix_to_postfix.cpp](../main/Data-Structure/infix_to_postfix.cpp)|124~134p|C++|10/31/2020|
|[just_testing.cpp](../main/Data-Structure/just_testing.cpp)|99p|C++|10/24/2020|12번|
|[just_testing.py](../main/Data-Structure/just_testing.py)|99p|Python|10/24/2020|12번|
|[loc_is_deleted.cpp](../main/Data-Structure/loc_is_deleted.cpp)|99p|C++|10/24/2020|10번|
|[loc_is_deleted.py](../main/Data-Structure/loc_is_deleted.py)|99p|Python|10/24/2020|10번|
|[loc_is_fun.cpp](../main/Data-Structure/loc_is_fun.cpp)|98p|C++|10/17/2020|8번|
|[loc_is_fun.py](../main/Data-Structure/loc_is_fun.py)|98p|Python|10/17/2020|8번|
|[problem4.cpp](../main/Data-Structure/problem4.cpp)|98p|C++|10/17/2020|4번|
|[problem4.py](../main/Data-Structure/problem4.py)|98p|Python|10/17/2020|4번|
|[hanoi_tower.cpp](../main/Data-Structure/hanoi_tower.cpp)|61p|C++|10/11/2020|
|[hanoi_tower.py](../main/Data-Structure/hanoi_tower.py)|61p|Python|10/11/2020|

## 심심해서 그냥 만들어본 소소한 미니 프로젝트
|소스 코드|책 이름|페이지 수|언어|날짜|설명|
|:---:|:---:|:---:|:---:|:---:|:---:|
|[Git4Nextop](https://github.com/MineEric64/Git4Nextop)|.|.|C#|4/24/2021|넥스탑 학원에서 쓰일 깃 프로그램|
|[Project REINFORCED](https://github.com/Nextop-OpenCV/ProjectReinforced)|.|.|C#|2/7/2021|
|[Drug2.cpp](../main/Side-Projects/Drug2.cpp)|OpenCV|158~159p|C++|11/8/2020|
|[Drug.cpp](../main/Side-Projects/Drug.cpp)|OpenCV|.|C++|11/1/2020|대마초를 먹은 느낌이랄까?|

## 서울여대 정보보호영재교육원 (SWU 2021)
|파일 이름|날짜|설명|
|:---:|:---:|:---:|
|[코로나 멈춰!](https://github.com/Luigi38/ProjectNextop/blob/main/SWU/2021%ED%95%99%EB%85%84%EB%8F%84%20%EC%A0%95%EB%B3%B4%EB%B3%B4%ED%98%B8%20%EC%98%81%EC%9E%AC%EA%B5%90%EC%9C%A1%EC%9B%90%20%5B2%EC%A1%B0%20_%EC%BD%94%EB%A1%9C%EB%82%98%20%EB%A9%88%EC%B6%B0!%5D%20%EB%B0%9C%ED%91%9C%EC%9E%90%EB%A3%8C.pdf)|4/10/2021|코로나 멈춰! 앱 개발 계획 프로젝트|

## 소소한 기밀 문서
|index|데이터|설명|
|:---:|:---:|:---:|
|0|ggLNW5K1pvZcCI4h6fXUjNuRUGaaDBOrUgjoXsaCFjrF36v76OhuWM2HkQYsc51h|라고 합니다|
|.|[Advanced Encryption Standard](https://www.devglan.com/online-tools/aes-encryption-decryption)|암호화 및 복호화|
|1|Competitive Programming Helper (cph)|Visual Studio Code 확장 플러그인 (테스트)|

## 꿀팁
```c++
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
```

=> 입출력을 전보다 빠르게 가속시킬 수 있다.

- `endl` 보다 `'\n'`을 사용하기
