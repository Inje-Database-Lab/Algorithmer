#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// two pointer ���
int binarySearch(vector<int>& seq, int data) {
	int l = 0, r = seq.size() - 1;		// l = left edge(seq[0]) to right pointer , r = right edge(seq[seq.size()-1]) to left pointer
	while (l <= r) {			// left pointer�� right pointer�� ����ġ�� ������  (l > r�� �Ǵ� ����, ****rl****�� ���)
		int mid = (l + r) / 2;		// ���� ���� �迭�� �߰����� mid�� ����
		if (seq[mid] == data) return mid;	// mid�� ���ϴ� ���� ������ return
		else if (seq[mid] < data) l = mid + 1;	// mid�� ���ϴ� ������ �۴ٸ�, mid �Ʒ��� �ʿ���� -> left pointer�� mid+1�� �����
		else r = mid - 1;		// mid�� ���ϴ� ������ ũ�ٸ�, mid ���δ� �ʿ���� -> right pointer�� mid-1�� �����
	}
	return -1;	// while �������� ���� �� ������, �� ���� ���°���
}

void showArr(vector<int> arr) {		// �迭�� �������� �����ִ� �Լ�
	int cnt = arr.size();		// vector�� ������ : size() ����Լ�
	cout << "[";
	for (int i = 0; i < cnt; i++) {
		if (i != cnt - 1) cout << arr[i] << ", ";		// �� �������� ,�� ����
		else cout << arr[i] << "]\n";					// ������ , ����
	}
}

int main() {
	int cnt, tmp;
	vector<int> vArr;
	cout << "\n\n\t�� ���� ���� �Է¹������?\n\t>> ";
	cin >> cnt;
	cout << "\n\t����� �����Ͽ� " << cnt << "���� �迭 ���� �Է�\n\t>> ";
	for (int i = 0; i < cnt; i++) {
		cin >> tmp;
		vArr.push_back(tmp);		// vector ���ø� -> push_back�� �ڿ� �������� �߰��ϴ� �Լ�
	}
	cout << "\n\t�Է��� �迭 X = ";
	showArr(vArr);
	sort(vArr.begin(), vArr.end());	// algorithm ��� -> �����ϱ� (default = Ascending order ; ��������)
	cout << "\n\t���ĵ� �迭 X = ";
	showArr(vArr);

	cout << "\n\t�迭 �� ������ ã�� ���� ���ڴ�? >> ";
	rewind(stdin);	// stdin �� ���� �ʱ�ȭ 
	cin >> tmp;
	tmp = binarySearch(vArr, tmp);  // binarysearch ����
	if (tmp > -1) cout << "\n\t" << tmp + 1 << "��° �����Դϴ�.\n\n\t";
	else cout << "���Ҹ� ã�� ���߽��ϴ�.\n\n\t";	// -1 ����� ���ٴ� ��
	system("pause");
}