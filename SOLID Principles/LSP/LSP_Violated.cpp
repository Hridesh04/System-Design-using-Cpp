#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Account {
public:
    virtual ~Account() = default;
    virtual void deposit(double amount) = 0;
};

class WithdrawableAccount : public Account {
public:
    virtual void withdraw(double amount) = 0;
};

class SavingAccount : public WithdrawableAccount {
private:
    double balance = 0;

public:
    void deposit(double amount) override {
        balance += amount;
        cout << "Deposited: " << amount
             << " in Savings Account. New Balance: " << balance << endl;
    }

    void withdraw(double amount) override {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn: " << amount
                 << " from Savings Account. New Balance: " << balance << endl;
        } else {
            cout << "Insufficient funds in Savings Account!" << endl;
        }
    }
};

class CurrentAccount : public WithdrawableAccount {
private:
    double balance = 0;

public:
    void deposit(double amount) override {
        balance += amount;
        cout << "Deposited: " << amount
             << " in Current Account. New Balance: " << balance << endl;
    }

    void withdraw(double amount) override {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn: " << amount
                 << " from Current Account. New Balance: " << balance << endl;
        } else {
            cout << "Insufficient funds in Current Account!" << endl;
        }
    }
};

class FixedTermAccount : public Account {
private:
    double balance = 0;

public:
    void deposit(double amount) override {
        balance += amount;
        cout << "Deposited: " << amount
             << " in Fixed Term Account. New Balance: " << balance << endl;
    }
};

class BankClient {
private:
    vector<shared_ptr<Account>> allAccounts;
    vector<shared_ptr<WithdrawableAccount>> withdrawableAccounts;

public:
    BankClient(const vector<shared_ptr<Account>>& allAccs,
               const vector<shared_ptr<WithdrawableAccount>>& withdrawableAccs)
        : allAccounts(allAccs), withdrawableAccounts(withdrawableAccs) {}

    void processTransactions() {
        for (auto& acc : allAccounts) {
            acc->deposit(1000);
        }

        for (auto& acc : withdrawableAccounts) {
            acc->withdraw(500);
        }
    }
};

int main() {
    auto savings = make_shared<SavingAccount>();
    auto current = make_shared<CurrentAccount>();
    auto fixed = make_shared<FixedTermAccount>();

    vector<shared_ptr<Account>> allAccounts = {savings, current, fixed};
    vector<shared_ptr<WithdrawableAccount>> withdrawableAccounts = {savings, current};

    BankClient client(allAccounts, withdrawableAccounts);
    client.processTransactions();

    return 0;
}