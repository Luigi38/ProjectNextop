using namespace std;

long long solution(int price, int money, int count)
{
    long long gauss = (long long)price * count * (count + 1) / 2;
    return money < gauss ? gauss - money : 0LL;
}