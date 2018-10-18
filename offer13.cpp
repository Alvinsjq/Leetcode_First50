#include <string.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int movingCount(int threshold, int rows, int cols){
        if(rows<1 || cols <1)
            return 0;
        int num = 0;
        bool* visited = new bool[rows * cols];
        memset(visited,0,rows * cols);
        haspath(threshold,rows,cols,0,0,visited);

        //������һ������б��Ϊtrue�ĸ���������Ϊ���ջ������ܹ�����ĸ�����
        for(int row = 0; row < rows; row++)
            for(int col=0; col < cols; col++)
                if(visited[row  * cols + col])
                    num ++;

        return num;
    }

    void haspath(int threshold, int rows, int cols, int row, int col, bool* visited){
        //��ʼ��ǣ��������ñ߽�
        if(row>=0 && row<rows && col>=0 && col<cols && !visited[row * cols + col]){
            //���㲻�ܽ���ĸ���
            int bitsum = getBitSum(row) + getBitSum(col);
            if(bitsum <= threshold){
                //ֻ�����ܽ���ĸ����в��ܹ����еݹ飬�ڵݹ��н��б��
                visited[row * cols + col] = true;
                haspath(threshold,rows,cols,row-1,col,visited);
                haspath(threshold,rows,cols,row+1,col,visited);
                haspath(threshold,rows,cols,row,col-1,visited);
                haspath(threshold,rows,cols,row,col+1,visited);
            }
        }
    }

private:
    int getBitSum(int x){
        int sum = 0;
        while(x){
            sum += x%10;
            x /= 10;
        }
        return sum;
    }
};

int main(){

    Solution s;

    return 0;
}
