#include <iostream>

using namespace std;

class FruitSeller
{
private:
    int price, cnt, balance;

public:
    FruitSeller(int pc, int count, int money)
    {
        price = pc;
        cnt = count;
        balance = money;
    }

    int SaleApples(int money)
    {
        int num = money / price;
        cnt -= num;
        balance += money;
        return num;
    }

    void ShowSalesResult()
    {
        cout << "남은 사과: " << cnt << '\n';
        cout << "판매 수익: " << balance << '\n';
    }
};

class FruitBuyer
{
private:
    int balance, cnt;

public:
    FruitBuyer(int money, int count)
    {
        balance = money;
        cnt = count;
    }

    void BuyApples(FruitSeller &seller, int money)
    {
        cnt += seller.SaleApples(money);
        balance -= money;
    }

    void ShowBuyResult()
    {
        cout << "현재 잔액: " << balance << '\n';
        cout << "사과 개수: " << cnt << '\n';
    }
};

int main()
{
    cout << "=======================6_2=================\n";

    FruitSeller seller(1000, 20, 0);
    FruitBuyer buyer(5000, 0);

    buyer.BuyApples(seller, 2000);

    cout << "과일 판매자의 현황\n";
    seller.ShowSalesResult();

    cout << '\n';

    cout << "과일 구매자의 현황\n";
    buyer.ShowBuyResult();

    return 0;
}