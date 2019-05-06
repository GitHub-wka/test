#include <iostream>
#include <fstream>
using namespace std;
int Medians(int a[], int b[], int n) {
	int s1 = 0, e1 = n - 1, s2 = 0, e2 = n - 1; //s1,e1分别是数组a[n]的下界和上界，s2和e2分别是数组b[n]的下界和上界
	while (s1 < e1 && s2 < e2) { //循环直到两个数组均只剩一个元素
		int mid1 = (s1 + e1) / 2;
		int mid2 = (s2 + e2) / 2;
		if (a[mid1] == b[mid2])
			return a[mid1];
		else if (a[mid1] > b[mid2]) {
			
			if ((s2 + e2) % 2 == 0)
				s2 = mid2;
			else
				s2 = mid2 + 1; //保证两个子序列长度相等
			e1 = mid1;
		}
		else {
			if ((s1 + e1) % 2 == 0)
				s1 = mid1;
			else
				s1 = mid1 + 1; //保证两个子序列长度相等
			e2 = mid2;
		}
	}
	if (a[s1] < b[s2]) //较小者即为所求
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
	ifstream in("d:\\算法设计与分析实验\\分治法\\中位数\\input.txt");
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
	ofstream out("d:\\算法设计与分析实验\\分治法\\中位数\\output.txt");
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
		cout << "输入n：" << endl;
		cin >> n;
		if (n < 0 || n > 200)
			cout << "输入的n越界！" << endl;
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
	cout << "中位数：" << Medians(a, b, n) << endl;
	delete[]a;
	delete[]b;
	system("pause");
	return 0;
}
*/
