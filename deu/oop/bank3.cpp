#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

// 프로그램 사용자의 선택 메뉴
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

// 신용등급
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };

// 계좌의 종류
enum { NORMAL = 1, CREDIT = 2 };

// Account 클래스
class Account
{
private:
	int accID;      // 계좌번호
	int balance;    // 잔    액
	char* cusName;  // 고객이름

public:
	// 계좌번호, 초기 잔액, 고객 이름으로 계좌 생성
	Account(int ID, int money, char* name);

	// 다른 Account 객체를 복사해 새 객체 생성
	Account(const Account& ref);

	// 계좌번호 반환
	int GetAccID() const;

	// 전달받은 금액만큼 잔액 증가
	virtual void Deposit(int money);

	// 잔액이 충분하면 출금, 부족하면 0 반환
	int Withdraw(int money);

	// 계좌번호, 고객 이름, 잔액 화면 출력
	void ShowAccInfo() const;

	// 동적으로 할당한 고객 이름 메모리 해제
	~Account();
};

// NormalAccount 클래스
class NormalAccount : public Account
{
private:
	int interRate;  // 이자율

public:
	// 계좌번호, 초기 잔액, 고객 이름, 이자율로 계좌 생성
	NormalAccount(int ID, int money, char* name, int rate);

	// 원금과 이자를 함께 입금
	virtual void Deposit(int money);
};

// HighCreditAccount 클래스
class HighCreditAccount : public NormalAccount
{
private:
	int specialRate;  // 특별 이자율

public:
	// 계좌번호, 초기 잔액, 고객 이름, 이자율, 특별 이자율로 계좌 생성
	HighCreditAccount(int ID, int money, char* name, int rate, int special);

	// 원금, 기본 이자, 특별 이자를 함께 입금
	virtual void Deposit(int money);
};

// AccountHandler 클래스
class AccountHandler
{
private:
	Account* accArr[100];  // Account 저장을 위한 배열
	int accNum;            // 저장된 Account 수

public:
	// 저장된 계좌 수를 0으로 초기화
	AccountHandler();

	// 사용 가능한 메뉴 목록 출력
	void ShowMenu(void) const;

	// 계좌 종류를 선택받아 계좌 생성
	void MakeAccount(void);

	// 계좌번호를 찾아 해당 계좌에 입금
	void DepositMoney(void);

	// 계좌번호를 찾아 해당 계좌에서 출금
	void WithdrawMoney(void);

	// 저장된 모든 계좌의 정보를 순서대로 출력
	void ShowAllAccInfo(void) const;

	// 저장된 모든 계좌 객체 메모리 해제
	~AccountHandler();

protected:
	// 보통예금계좌 생성
	void MakeNormalAccount(void);

	// 신용신뢰계좌 생성
	void MakeCreditAccount(void);
};

// 계좌번호, 초기 잔액, 고객 이름으로 계좌 생성
Account::Account(int ID, int money, char* name)
	// 계좌번호와 초기 잔액 초기화
	: accID(ID), balance(money)
{
	// 고객 이름 길이만큼 메모리 동적 할당
	cusName = new char[strlen(name) + 1];
	// 전달받은 고객 이름 문자열 복사
	strcpy_s(cusName, (strlen(name) + 1), name);
}

// 다른 Account 객체를 복사해 새 객체 생성
Account::Account(const Account& ref)
	// 원본 객체의 계좌번호와 잔액 복사
	: accID(ref.accID), balance(ref.balance)
{
	// 원본 이름 길이만큼 메모리 동적 할당
	cusName = new char[strlen(ref.cusName) + 1];
	// 원본의 고객 이름 문자열 복사
	strcpy_s(cusName, (strlen(ref.cusName) + 1), ref.cusName);
}

// 계좌번호 반환
int Account::GetAccID() const
{
	return accID;
}

// 전달받은 금액만큼 잔액 증가
void Account::Deposit(int money)
{
	// 현재 잔액에 입금액 더하기
	balance += money;
}

// 잔액이 충분하면 출금, 부족하면 0 반환
int Account::Withdraw(int money)
{
	// 출금하려는 금액이 잔액보다 크면 출금 실패
	if (balance < money)
		return 0;

	// 잔액에서 출금액 차감
	balance -= money;
	// 실제 출금한 금액 반환
	return money;
}

// 계좌번호, 고객 이름, 잔액 화면 출력
void Account::ShowAccInfo() const
{
	// 계좌번호 출력
	cout << "계좌ID: " << accID << endl;
	// 고객 이름 출력
	cout << "이  름: " << cusName << endl;
	// 현재 잔액 출력
	cout << "잔  액: " << balance << endl;
}

// 동적으로 할당한 고객 이름 메모리 해제
Account::~Account()
{
	// 동적으로 할당한 이름 메모리 해제
	delete[] cusName;
}

// 계좌번호, 초기 잔액, 고객 이름, 이자율로 계좌 생성
NormalAccount::NormalAccount(int ID, int money, char* name, int rate)
	// 부모 클래스와 이자율 초기화
	: Account(ID, money, name), interRate(rate)
{
}

// 원금과 이자를 함께 입금
void NormalAccount::Deposit(int money)
{
	// 원금 입금
	Account::Deposit(money);
	// 기본 이자 추가
	Account::Deposit(money * (interRate / 100.0));
}

// 계좌번호, 초기 잔액, 고객 이름, 이자율, 특별 이자율로 계좌 생성
HighCreditAccount::HighCreditAccount(int ID, int money, char* name, int rate, int special)
	// 부모 클래스와 특별 이자율 초기화
	: NormalAccount(ID, money, name, rate), specialRate(special)
{
}

// 원금, 기본 이자, 특별 이자를 함께 입금
void HighCreditAccount::Deposit(int money)
{
	// 원금과 기본 이자 입금
	NormalAccount::Deposit(money);
	// 특별 이자 추가
	Account::Deposit(money * (specialRate / 100.0));
}

// 저장된 계좌 수를 0으로 초기화
AccountHandler::AccountHandler() : accNum(0)
{
}

// 사용 가능한 메뉴 목록 출력
void AccountHandler::ShowMenu(void) const
{
	// 메뉴 제목 출력
	cout << "-----Menu------" << endl;
	// 계좌개설 메뉴 출력
	cout << "1. 계좌개설" << endl;
	// 입금 메뉴 출력
	cout << "2. 입    금" << endl;
	// 출금 메뉴 출력
	cout << "3. 출    금" << endl;
	// 전체 계좌정보 출력 메뉴 출력
	cout << "4. 계좌정보 전체 출력" << endl;
	// 프로그램 종료 메뉴 출력
	cout << "5. 프로그램 종료" << endl;
}

// 계좌 종류를 선택받아 계좌 생성
void AccountHandler::MakeAccount(void)
{
	// 계좌 종류 선택값 저장
	int sel;

	// 계좌 종류 선택 안내 문구 출력
	cout << "[계좌종류선택]" << endl;
	// 보통예금계좌 메뉴 출력
	cout << "1.보통예금계좌 ";
	// 신용신뢰계좌 메뉴 출력
	cout << "2.신용신뢰계좌 " << endl;
	// 메뉴 번호 입력 안내
	cout << "선택: ";
	// 사용자가 선택한 계좌 종류 입력
	cin >> sel;

	// 보통예금계좌 선택 시 해당 함수 호출
	if (sel == NORMAL)
		MakeNormalAccount();
	// 신용신뢰계좌 선택 시 해당 함수 호출
	else
		MakeCreditAccount();
}

// 보통예금계좌 생성
void AccountHandler::MakeNormalAccount(void)
{
	// 새 계좌의 번호 저장
	int id;
	// 새 계좌의 이름 저장
	char name[NAME_LEN];
	// 새 계좌의 초기 잔액 저장
	int balance;
	// 이자율 저장
	int interRate;

	// 보통예금계좌 개설 안내 문구 출력
	cout << "[보통예금계좌 개설]" << endl;
	// 계좌번호 입력 요청 후 저장
	cout << "계좌ID: ";
	cin >> id;
	// 이름 입력 요청 후 저장
	cout << "이  름: ";
	cin >> name;
	// 초기 입금액 입력 요청 후 저장
	cout << "입금액: ";
	cin >> balance;
	// 이자율 입력 요청 후 저장
	cout << "이자율: ";
	cin >> interRate;
	// 줄바꿈 출력
	cout << endl;

	// 새 NormalAccount 객체를 생성해 배열에 저장
	accArr[accNum++] = new NormalAccount(id, balance, name, interRate);
}

// 신용신뢰계좌 생성
void AccountHandler::MakeCreditAccount(void)
{
	// 새 계좌의 번호 저장
	int id;
	// 새 계좌의 이름 저장
	char name[NAME_LEN];
	// 새 계좌의 초기 잔액 저장
	int balance;
	// 기본 이자율 저장
	int interRate;
	// 신용등급 저장
	int creditLevel;

	// 신용신뢰계좌 개설 안내 문구 출력
	cout << "[신용신뢰계좌 개설]" << endl;
	// 계좌번호 입력 요청 후 저장
	cout << "계좌ID: ";
	cin >> id;
	// 이름 입력 요청 후 저장
	cout << "이  름: ";
	cin >> name;
	// 초기 입금액 입력 요청 후 저장
	cout << "입금액: ";
	cin >> balance;
	// 이자율 입력 요청 후 저장
	cout << "이자율: ";
	cin >> interRate;
	// 신용등급 입력 요청 후 저장
	cout << "신용등급(1toA, 2toB, 3toC): ";
	cin >> creditLevel;
	// 줄바꿈 출력
	cout << endl;

	// 입력한 신용등급에 따라 계좌 생성
	switch (creditLevel)
	{
		// A등급 계좌 생성
	case 1:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_A);
		break;

		// B등급 계좌 생성
	case 2:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_B);
		break;

		// C등급 계좌 생성
	case 3:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_C);
	}
}

// 계좌번호를 찾아 해당 계좌에 입금
void AccountHandler::DepositMoney(void)
{
	// 입금액 저장
	int money;
	// 계좌번호 저장
	int id;

	// 입금 안내 문구 출력
	cout << "[입    금]" << endl;
	// 계좌번호 입력 요청 후 저장
	cout << "계좌ID: ";
	cin >> id;
	// 입금액 입력 요청 후 저장
	cout << "입금액: ";
	cin >> money;

	// 저장된 모든 계좌를 순차적으로 확인
	for (int i = 0; i < accNum; i++)
	{
		// 입력한 계좌번호와 현재 계좌번호가 같은지 확인
		if (accArr[i]->GetAccID() == id)
		{
			// 해당 계좌에 입금 처리
			accArr[i]->Deposit(money);
			// 입금 완료 메시지 출력
			cout << "입금완료" << endl << endl;
			// 작업 종료
			return;
		}
	}

	// 계좌번호가 일치하지 않으면 오류 메시지 출력
	cout << "유효하지 않은 ID 입니다." << endl << endl;
}

// 계좌번호를 찾아 해당 계좌에서 출금
void AccountHandler::WithdrawMoney(void)
{
	// 출금액 저장
	int money;
	// 계좌번호 저장
	int id;

	// 출금 안내 문구 출력
	cout << "[출    금]" << endl;
	// 계좌번호 입력 요청 후 저장
	cout << "계좌ID: ";
	cin >> id;
	// 출금액 입력 요청 후 저장
	cout << "출금액: ";
	cin >> money;

	// 저장된 모든 계좌를 순차적으로 확인
	for (int i = 0; i < accNum; i++)
	{
		// 입력한 계좌번호와 현재 계좌번호가 같은지 확인
		if (accArr[i]->GetAccID() == id)
		{
			// 출금 실패 여부 확인
			if (accArr[i]->Withdraw(money) == 0)
			{
				// 잔액 부족 메시지 출력
				cout << "잔액부족" << endl << endl;
				// 작업 종료
				return;
			}

			// 출금 완료 메시지 출력
			cout << "출금완료" << endl << endl;
			// 작업 종료
			return;
		}
	}

	// 계좌번호가 일치하지 않으면 오류 메시지 출력
	cout << "유효하지 않은 ID 입니다." << endl << endl;
}

// 저장된 모든 계좌의 정보를 순서대로 출력
void AccountHandler::ShowAllAccInfo(void) const
{
	// 저장된 모든 계좌를 순차적으로 확인
	for (int i = 0; i < accNum; i++)
	{
		// 각 계좌의 정보 출력
		accArr[i]->ShowAccInfo();
		// 계좌 정보 사이 줄바꿈 출력
		cout << endl;
	}
}

// 저장된 모든 계좌 객체 메모리 해제
AccountHandler::~AccountHandler()
{
	// 저장된 모든 계좌 객체 메모리 해제
	for (int i = 0; i < accNum; i++)
		delete accArr[i];
}

// 사용자의 메뉴 선택을 받아 각 기능 실행
int main(void)
{
	// 계좌 관리 기능을 담당하는 객체 생성
	AccountHandler manager;
	// 사용자의 메뉴 선택 값을 저장할 변수
	int choice;

	// 프로그램이 종료될 때까지 반복 실행
	while (1)
	{
		// 사용자에게 메뉴 목록 출력
		manager.ShowMenu();
		// 메뉴 번호 입력 안내
		cout << "선택: ";
		// 사용자가 선택한 메뉴 번호 입력
		cin >> choice;
		// 줄바꿈 출력
		cout << endl;

		// 입력한 choice에 따라 기능 수행
		switch (choice)
		{
			// 계좌개설 기능
		case MAKE:
			manager.MakeAccount();
			break;

			// 입금 기능
		case DEPOSIT:
			manager.DepositMoney();
			break;

			// 출금 기능
		case WITHDRAW:
			manager.WithdrawMoney();
			break;

			// 전체 계좌조회 기능
		case INQUIRE:
			manager.ShowAllAccInfo();
			break;

			// 프로그램 종료
		case EXIT:
			return 0;

			// 정의되지 않은 번호 입력 시 오류 메시지 출력
		default:
			cout << "Illegal selection.." << endl;
		}
	}

	// 프로그램 정상 종료
	return 0;
}
