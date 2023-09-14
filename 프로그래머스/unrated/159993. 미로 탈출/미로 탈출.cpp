#include <string>
#include <vector>
#include <queue>

using namespace std;

const int dy[] = { 1,0,-1,0 };
const int dx[] = { 0,1,0,-1 };

bool BFS(char dest , int& answer, pair<int, int>& start_coord, const vector<string>& maps, vector<vector<int>>& visited)
{
    queue<pair<int, int>> road; 
    road.push(start_coord);
    visited[start_coord.first][start_coord.second] = 1;

    while (!road.empty())
    {
        auto current_coord = road.front();
        road.pop();

        if (maps[current_coord.first][current_coord.second] == dest)
        {
            answer += visited[current_coord.first][current_coord.second];
            start_coord = current_coord;
            return true;
        }

        for (int dir = 0; dir < 4; dir++)
        {
            int ny = current_coord.first + dy[dir];
            int nx = current_coord.second + dx[dir];

            if (ny < 0 || ny > maps.size() - 1) continue;
            if (nx < 0 || nx > maps[ny].size() - 1) continue;
            if (maps[ny][nx] == 'X')continue;
            if (visited[ny][nx]) continue;

            visited[ny][nx] = visited[current_coord.first][current_coord.second] + 1;
            road.push(make_pair(ny, nx));
        }
    }

    return false;
}


int solution(vector<string> maps) {

    vector<vector<int>> visited;
    visited.resize(maps.size(), vector<int>());
    pair<int, int> s_coord; //y,x
    for (int i = 0; i < maps.size(); i++)
    {
        auto s_idx = maps[i].find('S');
        if (s_idx != string::npos)
            s_coord = make_pair(i, s_idx);

        visited[i].resize(maps[i].size(), 0);
    }

    int answer = 0;

    if (BFS('L', answer, s_coord, maps, visited))
    {
        for (auto& v : visited)
            fill(v.begin(), v.end(), 0);

        if (BFS('E', answer, s_coord, maps, visited))
        {
            return answer - 2;
        }
    }

    return -1;
}