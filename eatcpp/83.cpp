#include <bits/stdc++.h>
using namespace std;

class Point
{
    int x, y;

public:
    Point(int pos_x, int pos_y);
    int GetX() const { return x; }
    int GetY() const { return y; }
};

Point::Point(int pos_x, int pos_y)
{
    x = pos_x;
    y = pos_y;
}

struct Line
{
    int a, b, c;
};

class Geometry
{
    Point *point_array[100];
    int num_points;

public:
    Geometry();
    void AddPoint(const Point &point);
    void PrintDistance();
    void PrintNumMeets();
};

Geometry::Geometry()
{
    num_points = 0;
}

void Geometry::AddPoint(const Point &point)
{
    point_array[num_points] = new Point(point);
    num_points++;
}

Line MakeLine(Point *p1, Point *p2)
{
    int x1 = p1->GetX();
    int y1 = p1->GetY();
    int x2 = p2->GetX();
    int y2 = p2->GetY();

    Line line;
    line.a = y2 - y1;
    line.b = x1 - x2;
    line.c = x2 * y1 - x1 * y2;
    return line;
}

void Geometry::PrintDistance()
{
    for (int i = 0; i < num_points; i++)
    {
        for (int j = i + 1; j < num_points; j++)
        {
            int x1 = point_array[i]->GetX();
            int y1 = point_array[i]->GetY();
            int x2 = point_array[j]->GetX();
            int y2 = point_array[j]->GetY();

            double dist = sqrt((x1 - x2) * (x1 - x2) +
                               (y1 - y2) * (y1 - y2));

            cout << i + 1 << "번째 점과 "
                 << j + 1 << "번째 점 사이의 거리 : "
                 << dist << '\n';
        }
    }
}

void Geometry::PrintNumMeets()
{
    vector<Line> lines;

    for (int i = 0; i < num_points; i++)
    {
        for (int j = i + 1; j < num_points; j++)
        {
            lines.push_back(MakeLine(point_array[i], point_array[j]));
        }
    }

    int cnt = 0;
    for (int i = 0; i < (int)lines.size(); i++)
    {
        for (int j = i + 1; j < (int)lines.size(); j++)
        {
            int det = lines[i].a * lines[j].b - lines[j].a * lines[i].b;
            if (det != 0)
                cnt++;
        }
    }

    cout << "교점의 개수 : " << cnt << '\n';
}

void solve()
{
    Geometry geo;

    geo.AddPoint(Point(1, 1));
    geo.AddPoint(Point(2, 2));
    geo.AddPoint(Point(3, 1));
    geo.AddPoint(Point(4, 3));

    geo.PrintDistance();
    geo.PrintNumMeets();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}