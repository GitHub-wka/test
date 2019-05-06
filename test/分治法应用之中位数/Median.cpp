#include <iostream>
#include <fstream>
using namespace std;
int Medians(int a[], int b[], int n) {
	int s1 = 0, e1 = n - 1, s2 = 0, e2 = n - 1; //s1,e1�ֱ�������a[n]���½���Ͻ磬s2��e2�ֱ�������b[n]���½���Ͻ�
	while (s1 < e1 && s2 < e2) { //ѭ��ֱ�����������ֻʣһ��Ԫ��
		int mid1 = (s1 + e1) / 2;
		int mid2 = (s2 + e2) / 2;
		if (a[mid1] == b[mid2])
			return a[mid1];
		else if (a[mid1] > b[mid2]) {
			
			if ((s2 + e2) % 2 == 0)
				s2 = mid2;
			else
				s2 = mid2 + 1; //��֤���������г������
			e1 = mid1;
		}
		else {
			if ((s1 + e1) % 2 == 0)
				s1 = mid1;
			else
				s1 = mid1 + 1; //��֤���������г������
			e2 = mid2;
		}
	}
	if (a[s1] < b[s2]) //��С�߼�Ϊ����
		return a[s1];
	else
		return b[s2];
}
int atoi(char s[]) {
	int n = 0;
	for (int i = 0; s[i] > '0'&&s[i] < '9'; i++)
		n = 10 * n + (s[i] - '0');
	return n;
}
int main() {
	ifstream in("d:\\�㷨��������ʵ��\\���η�\\��λ��\\input.txt");
	if (!in) {
		cout << "Cannot open File!\n";
		return 1;
	}
	int n;
	in >> n;
	int *a = new int[n];
	int *b = new int[n];
	for (int i = 0; i < n; i++)
		in >> a[i];
	for (int i = 0; i < n; i++)
		in >> b[i];
	int result = Medians(a, b, n);
	ofstream out("d:\\�㷨��������ʵ��\\���η�\\��λ��\\output.txt");
	if (!out) {
		cout << "Cannot open File!" << endl;
		return 1;
	}
	out << result << endl;
	delete[]a;
	delete[]b;
	in.close();
	out.close();
	system("pause");
	return 0;
}
/*
int main() {
	int n;
	while(true){
		cout << "����n��" << endl;
		cin >> n;
		if (n < 0 || n > 200)
			cout << "�����nԽ�磡" << endl;
		else
			break;
	}
	int *a = new int[n];
	int *b = new int[n];
	cout << "a[]:" << endl;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << "b[]:" << endl;
	for (int i = 0; i < n; i++)
		cin >> b[i];
	cout << "��λ����" << Medians(a, b, n) << endl;
	delete[]a;
	delete[]b;
	system("pause");
	return 0;
}
*/
