# 중등부 문제 (2021)
|소스 코드|문제 제목|시도 횟수|언어|결과|날짜|설명|
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|[honey.cpp](./honey.cpp)|[꿀 따기](http://boj.kr/21758)|9|C++|성공|6/13/2021|최댓값을 미리 구한다면? FINISH. GG, O(3N)|

## 과정
|소스 코드|문제 제목|시도 횟수|언어|성공 여부|날짜|설명|
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|[honey_t1_ni.cpp](./Footprints/dog_honey_jam_t1_ni.cpp)|[꿀 따기](http://boj.kr/21758)|1|C++|부분 성공 (11점)|5/30/2021|삼중 포문 안에 while문을 `honey_t2_d.cpp`처럼 값을 미리 구해서 할 수 있음. O(N^3*2N)|
|[honey_t2_d.cpp](./Footprints/honey_t2_d.cpp)|[꿀 따기](http://boj.kr/21758)|2|C++|아직 안함|5/30/2021|만들다가 말았음. 밤새서 그런지 머리가 안돌아감.|
|[honey_t3.cpp](./Footprints/dog_honey_jam_t3.cpp)|[꿀 따기](http://boj.kr/21758)|3|C++|실패|6/6/2021|`dog_honey_jam_t1_ni.cpp` 코드 개선 버전. 왜 실패?|
|[honey_t4_v1_d.cpp](./Footprints/honey_t4_v1_d.cpp)|[꿀 따기](http://boj.kr/21758)|4|C++|때려침|6/6/2021|멘붕|
|[honey_t4_v2.cpp](./Footprints/honey_t4_v2.cpp)|[꿀 따기](http://boj.kr/21758)|5|C++|시간 초과|6/6/2021|다음 시간에 개선 ㄱㄱ|
|[honey_t5_v1.cpp](./Footprints/honey_t5_v1.cpp)|[꿀 따기](http://boj.kr/21758)|6|C++|부분 성공 (24점)|6/13/2021|Idea #3 / O(N^3)|
|[honey_t5_v2.cpp](./Footprints/honey_t5_v2.cpp)|[꿀 따기](http://boj.kr/21758)|7|C++|부분 성공 (55점)|6/13/2021|`fly()` 함수 개선 버전. 기존 while문을 `dog_honey_jam_t3.cpp`에 있는 미리 구하는 코드로 변경, O(N^2)|
|[honey_t5_v3.cpp](./Footprints/honey_t5_v3.cpp)|[꿀 따기](http://boj.kr/21758)|8|C++|부분 성공 (55점)|6/13/2021|상황 3 규칙 개선, O(N^2)|