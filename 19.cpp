#include <bits/stdc++.h>
using namespace std;
// ý tưởng
// dùng vector lưu ví trí đầu và cuối của 1 dãy liền kề
// tìm độ dài dài nhất trong mảng liền kề
// tìm vị trí đầu và cuối của dãy dài nhất và lưu vào 1 vector mới
//  xét tổng của các dãy đã lưu trong vector mới và in ra dãy dài nhất với vị trí đã lưu
void day_lien_ke(int *a, vector<int> &index, int n);
int max(vector<int> &index);
void output_index(vector<int> &index, vector<int> &max_index, int max_dis);
int sum_max(int *a, int left, int right);
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> index;
    day_lien_ke(a, index, n);//gọi hàm tìm các dãy liền kề
    int max_dis = max(index);//gọi hàm tìm khoảng cách mảng dài nhất
    vector<int> max_index;
    output_index(index, max_index, max_dis);//gọi hàm để lấy ra các vị trí đầu và cuối của dãy dài nhất
    int max = 0, left, right;// dùng biến left và right để lưu vị trí đầu và cuối của dãy dài nhất
    for (int i = 0; i < max_index.size(); i += 2)
    {
        int temp = sum_max(a, i, i + 1);
        if (temp > max)
        {
            max = temp;
            left = max_index[i];
            right = max_index[i + 1];
        }
    }
    cout << max_dis + 1 << endl;
    for (int i = left; i <= right; i++)
        cout << a[i] << " ";
    delete[] a;
    return 0;
}
void day_lien_ke(int *a, vector<int> &index, int n)
{
    int count = 0, left, right;
    for (int i = 0; i < n; i++)
    {
        left = i;
        for (int j = i; j < n; j++)
        {
            if (a[j] < a[j + 1])
                count++;
            else
            {
                right = j;
                break;
            }
        }
        index.push_back(left);
        index.push_back(right);
        i = right;
    }
}
int max(vector<int> &index)
{
    int max_index = 0;
    for (int i = 0; i < index.size(); i += 2)
        if (index[i + 1] - index[i] >= max_index)
            max_index = index[i + 1] - index[i];
    return max_index;
}
void output_index(vector<int> &index, vector<int> &max_index, int max_dis)
{
    for (int i = 0; i < index.size(); i += 2)
        if (index[i + 1] - index[i] == max_dis)
        {
            max_index.push_back(index[i]);
            max_index.push_back(index[i + 1]);
        }
}
int sum_max(int *a, int left, int right)
{
    int sum = 0;
    for (int i = left; i <= right; i++)
    {
        sum += a[i];
    }
    return sum;
}