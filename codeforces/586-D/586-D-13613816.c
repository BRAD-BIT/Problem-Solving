using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace C_sharp
{
    struct train { public int start, end, row; public train(int s, int e, int r) { start = s; end = e; row = r; } };
    class Program
    {
        static public train[] t;
        static public int[,,] mem;
        static public char[,] grid;
        static public int n, k, x;

        static public bool can_move(int r,int c,int dep,bool type)
        {
            dep*=2;
            for(int i=0;i<k;i++)
            {
                if(r!=t[i].row)continue;
                if((c>t[i].end-dep||c<t[i].start-dep)&&(c>t[i].end-(dep+2)||c<t[i].start-(dep+2)||type))continue;
                return false;
            }
            return true;
        }
        static public int DFS(int r,int c,int dep)
        {
            if(2*dep>=x){return 1;}
            if(mem[r,c,dep]!=-1)return mem[r,c,dep];
            int ans1=0,ans2=0,ans3=0;
            if(r+1<3&&c+1<n)if(can_move(r,c+1,dep,true)&&can_move(r+1,c+1,dep,false))ans1=DFS(r+1,c+1,dep+1);
            if(r-1>=0&&c+1<n)if(can_move(r,c+1,dep,true)&&can_move(r-1,c+1,dep,false))ans2=DFS(r-1,c+1,dep+1);
            if(c+1<n)if(can_move(r,c+1,dep,false))ans3=DFS(r,c+1,dep+1);
            return mem[r,c,dep]=ans1|ans2|ans3;
        }
        static void Main(string[] args)
        {
                int T = Convert.ToInt32(Console.ReadLine());
                mem = new int[5, 210, 210];
                grid = new char[4,200];
                t = new train[200];
                    while (true)
                    {
                        for (int i = 0; i < 4; i++)
                            for (int j = 0; j < 200; j++)
                                for (int u = 0; u < 200; u++)
                                    mem[i, j, u] = -1;
                        if (T-- == 0) break;
                        string[] l = Console.ReadLine().Split(' ');
                        n = int.Parse(l[0]);
                        k = int.Parse(l[1]);
                        string[] ss = new string[3];
                        ss[0] = Console.ReadLine(); ss[1] = Console.ReadLine(); ss[2] = Console.ReadLine();
                        for (int i = 0; i < 3; i++) for (int j = 0; j < n; j++)
                            { grid[i, j] = ss[i][j]; grid[0, n] = grid[1, n] = grid[2, n] = '*'; }
                        int p = 0; x = 0; int S = 0;
                        for (int i = 0; i < 3; i++) for (int j = 0; j < n; j++)
                            {
                                {
                                    if (grid[i, j] == 's') { S = i; continue; }
                                    if (grid[i, j] == '.') continue;
                                    int s = j; int e=0; char c = grid[i, j];
                                    for (int z = j; z <= n; z++, j++) if (grid[i, z + 1] != c) { e = z; break; }
                                    t[p++] = new train(s, e, i);
                                    x = Math.Max(x, e + 1);
                                }
                            }
                        Console.WriteLine((DFS(S,0,0)==1)?"YES":"NO");
                    }
        }
    }
}