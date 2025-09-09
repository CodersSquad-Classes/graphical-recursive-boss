// Evidence 1.3.1 - Graphical Recursive Algorithms
// Luis Andrés Casillas 
// A01645008
// 08/09/2025

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

struct P { long long x, y; };
static vector<pair<P,P>> segs;   
static long long gx = 0, gy = 0; 

static inline void DrawRelative(long long dx, long long dy) {
    P a{gx, gy};
    gx += dx; gy += dy;
    P b{gx, gy};
    segs.push_back({a, b});
}

void Hilbert(int depth, long long dx, long long dy) {
    if (depth == 0) {

    } else {
        Hilbert(depth - 1, dy, dx);
        DrawRelative(dx, dy);
        Hilbert(depth - 1, dx, dy);
        DrawRelative(dy, dx);
        Hilbert(depth - 1, dx, dy);
        DrawRelative(-dx, -dy);
        Hilbert(depth - 1, -dy, -dx);
    }
}

static inline long long clampll(long long v, long long lo, long long hi) {
    return max(lo, min(hi, v));
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (argc < 3) {
        cerr << "Usage: " << argv[0] << " hilbert <depth>\n";
        cerr << "  depth in [1..10]\n";
        return 1;
    }

    string algo = argv[1];
    if (algo != "hilbert") {
        cerr << "Only 'hilbert' is implemented for this lab.\n";
        return 1;
    }

    int depth = stoi(argv[2]);
    if (depth < 1 || depth > 10) {
        cerr << "Depth must be between 1 and 10 (inclusive).\n";
        return 1;
    }


    const long long G = (1LL << depth) - 1LL;  
    const double scale = (G == 0) ? 0.0 : (1023.0 / static_cast<double>(G));

    gx = 0; gy = 0;
    segs.clear();
    segs.reserve((1ULL << (2*depth)) - 1ULL); 

    Hilbert(depth, 0, 1);



    ofstream out("lines.txt");
    if (!out) {
        cerr << "Failed to open lines.txt for writing.\n";
        return 1;
    }

    auto toCanvas = [&](long long v)->int {

        long long r = llround(v * scale);
        return (int)clampll(r, 0, 1023);
    };

    for (const auto& s : segs) {
        int x1 = toCanvas(s.first.x);
        int y1 = toCanvas(s.first.y);
        int x2 = toCanvas(s.second.x);
        int y2 = toCanvas(s.second.y);
        out << '(' << x1 << ',' << y1 << ")(" << x2 << ',' << y2 << ")\n";
    }
    out.close();

    cout << "Algorithm: Hilbert, depth=" << depth << "\n";
    cout << "Grid size: " << (G+1) << "x" << (G+1) << " points\n";
    cout << "Segments:  " << segs.size() << " (expected " << ((1ULL << (2*depth)) - 1ULL) << ")\n";
    cout << "Output:    lines.txt (1024x1024 canvas)\n";
    return 0;
}
