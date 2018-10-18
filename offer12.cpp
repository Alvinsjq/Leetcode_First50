#include <string.h>
#include <iostream>
using namespace std;

class Solution {
public:
      bool hasPath(char* matrix, int rows, int cols, char* str){
        //������Ϊ�յ�ʱ��
        if(matrix == nullptr || rows < 1 || cols < 1 || str == nullptr)
             return false;
        //��ʼ��һ����Ǿ���
        bool *visited = new bool[rows * cols];
        memset(visited,0,rows*cols);
        //��ʼ����
        int pathLength = 0;
        for(int row=0;row<rows;row++)
            for(int col=0;col<cols;col++)
                //ʹ�õݹ��㷨
                if(haspath(matrix,rows,cols,row,col,str,pathLength,visited))
                    return true;
        delete[] visited;
        return false;
    }

    bool haspath(const char* matrix, int rows, int cols, int row, int col, const char *str, int& pathLength, bool* visited){
        //��pathLength�����µ��ַ�Ϊ��ʱ������true
        if(str[pathLength] == '\0')
            return true;
        bool nexthaspath = false;
        //������Ϊrow��col�ĸ��Ӻ�·���ַ���������ΪpathLength���ַ�һ��ʱ,�ݹ����ڸ���
        if(row>=0 && row<rows && col>=0 && col<cols && matrix[row*cols + col] == str[pathLength] && !visited[row*cols + col]){
            //��λ��һ��str�ַ�
            pathLength ++;
            visited[row*cols + col] = true;
            nexthaspath = haspath(matrix,rows,cols,row,col-1,str,pathLength,visited)
                    ||  haspath(matrix,rows,cols,row-1,col,str,pathLength,visited)
                    ||  haspath(matrix,rows,cols,row,col+1,str,pathLength,visited)
                    ||  haspath(matrix,rows,cols,row+1,col,str,pathLength,visited);
            if(!nexthaspath){
                pathLength--;
                visited[row*cols+col] = false;
            }
        }
        return nexthaspath;
    }
};

int main(){
    Solution s;
    return 0;
}
