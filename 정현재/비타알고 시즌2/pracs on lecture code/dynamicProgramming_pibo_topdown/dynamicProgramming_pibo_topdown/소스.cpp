#include <iostream>
using namespace std;

int d[101010];
int fiboTopDown(int n) {		// ����Լ�
	if (n <= 1) return 1;			// n(�Ǻ���ġ ����) �� 1 ���Ϸ� ������ ��� 1�� ���
	int &res = d[n];					// res�� ���� �Ǻ���ġ ������ ���� ����
	if (res) return res;				// 
	return res = fiboTopDown(n - 1) + fiboTopDown(n - 2);
}

int fiboBottomUp(int n) {
	int dd[101010] = { 1,1 };
	for (int i = 2; i <= n; ++i)
		dd[i] = dd[i - 1] + dd[i - 2];
	return dd[n];
}

int main() {
	cout << "\n\t�� ��° �Ǻ���ġ ���� �����帱���?\n\t(¦�� : topdown���, Ȧ��:bottomup���)\n\t";
	int aa;
	cin >> aa;
	cout << "\t" << aa << "��° �Ǻ���ġ �� = ";
	if (aa % 2 == 0) cout << fiboTopDown(aa) << "\n\tTopDown��� �̿�";
	else cout << fiboBottomUp(aa) << "\n\tBottomUp��� �̿�\n\n\t";
	system("pause");
}