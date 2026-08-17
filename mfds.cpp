#include <iostream>
#include <vector>
using namespace std;
int det(vector<vector<int>> A)
{
    int n1=A.size();
    int n2=A[0].size();
    if(n1!=n2)
    {
        cout<<"Can't be found";
        return 0;
    }
    if(n1==1) return A[0][0];
    if(n1==2) return A[0][0]*A[1][1]-A[0][1]*A[1][0];
    int ans=0;
    for(int i=0;i<n1;i++)
    {
        vector<vector<int>> matrix;
        for(int j=1;j<n1;j++)
        {
            vector<int> row;
            for(int k=0;k<n1;k++)
            {
                if(k!=i){
                    row.push_back(A[j][k]);
                }
            }
            matrix.push_back(row);
        }
        if(i%2==0) ans=ans+A[0][i]*det(matrix);  
        else ans=ans-A[0][i]*det(matrix);
    }
    return ans;
}
vector<vector<int>> add(vector<vector<int>> A,vector<vector<int>> B)
{
    int n=A.size();
    int m=A[0].size();
    vector<vector<int>> ans;
    for(int i=0;i<n;i++)
    {
        vector<int> row;
        for(int j=0;j<m;j++)
        {
            row.push_back(A[i][j]+B[i][j]);
        }
        ans.push_back(row);
    }
    return ans;
}
vector<vector<int>> multiply(vector<vector<int>> A,vector<vector<int>> B)
{
    int n=A.size();
    int m=B[0].size();
    int p=B.size();
    vector<vector<int>> ans;
    for(int i=0;i<n;i++)
    {
        vector<int> row;
        for(int j=0;j<m;j++)
        {
            int total=0;
            for(int k=0;k<p;k++)
            {
                total=total+A[i][k]*B[k][j];
            }
            row.push_back(total);
        }
        ans.push_back(row);
    }
    return ans;
}
int main()
{
    vector<vector<int>> A={{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> B={{1,2},{3,4}};
    vector<vector<int>> C={{5,6},{7,8}};
    vector<vector<int>> D={{1,2},{3,4}};
    vector<vector<int>> E={{5,6},{7,8}};
    cout<<det(A)<<endl;
    vector<vector<int>> ans=add(B,C);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[0].size();j++) cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    ans=multiply(D,E);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[0].size();j++) cout<<ans[i][j]<<" ";
        cout<<endl;
    }
}