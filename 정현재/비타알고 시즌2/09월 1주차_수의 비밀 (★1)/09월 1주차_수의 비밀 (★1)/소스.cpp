#include <iostream>
using namespace std;
bool binaryReducer(unsigned long long int arg) {		// ������ȹ�� Ǯ��
	if (arg % 2 == 0 && arg > 2) return binaryReducer(arg / 2);
	else if (arg / 2 == 1 || arg / 2 == 0) return 1;
	else	return 0;
}
int main() {
	unsigned long long int input;		// 10^18 ������ ��ȭ�� �� �ִ� �ڷ���
	cin >> input;
	if (binaryReducer(input)) cout << "Yes";
	else cout << "No";
}