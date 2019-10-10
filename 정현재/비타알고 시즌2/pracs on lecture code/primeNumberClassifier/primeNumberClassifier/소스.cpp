#include <iostream>

#define MAX_NUM 1000000

using namespace std;

void basicSolve(int num) {
	bool prime = 1;
	for (int i = 2; i*i < num; ++i) {		// 2���� �������Ѱ��� 1����
		if (num%i == 0) {		// �Է¹��� ���� ������ �� ������������ 
			prime = 0;			// �Ҽ��� �ƴ�
			break;
		}
	}
	if (prime)
		cout << "�Ҽ�";
	else
		cout << "�ռ���";
}

void eratosthenes_sieve(int start, int end) {	// �����佺�׳׽��� ü (���� ���� �Ҽ��� �Ѳ����� �˻��� �� ����)
	bool sieve[MAX_NUM] = { 1, 1 };	// 0�� 1�� �Ҽ��� �ƴ� ������ �Ǻ�
	for (int i = 2; i*i <= MAX_NUM; ++i) {
		if (sieve[i]) continue;	// �̹� 1 (if�ȿ����� true)�̸� �Ѿ��.
		for (int j = i * i; j < MAX_NUM; j += i)	// j�� i^2�� �����ϴ� ���� : �̹� ���� �ܰ迡�� i*(i-1)���� �������ֱ� ����!
			sieve[j] = 1;	// ���� i�� ����� ��� �����.
	}

	int count = 0;
	for (int i = start; i < end; ++i) {
		if (!sieve[i]) {
			cout << i << "\t";
			if (++count % 10 == 0) cout << "\n\t";
		}
	}
}

int main() {
	int tmp1, tmp2;
	cout << "\n\t�Ҽ����� �˰� ���� ���� �Է�! >> ";
	cin >> tmp1;
	cout << "\t" << tmp1 << "�� >> ";
	basicSolve(tmp1);
	rewind(stdin);
	cout << "\n\n\t���� ���� ���� �Ҽ� ��� ��� : ������ �ּ� �ִ밪 �Է� >> ";
	cin >> tmp1 >> tmp2;
	cout << "\t" << tmp1 << " �̻� " << tmp2 << " �̸��� �Ҽ�\n\t>> ";
	eratosthenes_sieve(tmp1, tmp2);
	system("pause");
}