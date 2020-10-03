// 关于地图的操作
int n,m;
char mp[size][size];
// 地图有很多种，这里以最简单的地图——'#' 表示障碍物，'.' 表示空地——为例。
// 注意！如果使用了万能头文件，在 map[] 上会编译错误，原因是重复名称。map 这个名字在 STL 中已经存在，请换一个名字。

// 地图上的 DFS，平均时间复杂度 O(kmn)，其中第 15 行与 24 行处理的总时间复杂度为 k
const int dx={-1,0,0,1};
const int dy={0,-1,1,0};
// 这是每一步可以走的方向，这里是上下左右。常见的还有上下左右、左上右上左下右下八个方向。
bool visit[size][size];
void dfs (int x,int y) // 根据题目需要可以更改返回类型或增加参数等
{
    visit[x][y]=1;
    // 对该点 (x,y) 进行一些处理，具体看题目要求
    for (int k=0;k<4;k++) // 4 个方向，所以是 4。如果是 8 个方向，应改成 8。
    {
        int xx=x+dx[k];
        int yy=y+dy[k];
        if (xx>=0 && xx<n && yy>=0 && yy<n
            && !visit[xx][yy] /*&& 题目规定的要求*/)
        {
            dfs (xx,yy);
            // 这里其实也可以进行一些操作
        }
    }
}

// 上面都是二维地图，三位地图可以此类推。