#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef double ld;

// double comparasion
/** basics
 * Description: Comparisons which take double imprecision into account.
 */
#define EPS (1e-10)
int dcmp(ld x){
    return (fabs(x)<EPS) ? 0 : (x<0 ? -1 : 1);
}
bool eq(ld a, ld b) {
    return fabs(a-b) <= fabs(a+b) * EPS;
}
//const ld M_PI = acos(-1.) // M_PI is usually defined
/// basics

// POINTS ///////////////////////////////////////////////////////////// 

/** point
 * Description: Represents both Point and Vector in 2D.
 */
struct Pt{
    ld x, y;
    bool operator <(const Pt &p) const { return x < p.x || (x == p.x && y < p.y); }
    // or return x < p.x-EPS || eq(x, p.x) && y < p.y-EPS);
    Pt operator+(const Pt &p){ return{x+p.x, y+p.y}; }
    Pt operator-(const Pt &p){ return{x-p.x, y-p.y}; }
    Pt operator-(){ return{-x, -y}; }
    Pt operator*(ld d){ return {x*d, y*d}; }
    Pt operator/(ld d){ return {x/d, y/d}; }
    friend ostream &operator<<(ostream &os, const Pt &a){ os<<a.x<<' '<<a.y; return os; }
    friend istream &operator>>(istream &is, Pt &a){ is>>a.x>>a.y; return is; }
};
bool operator==(const Pt &a, const Pt &b){ return eq(a.x,b.x) && eq(a.y,b.y); }  
bool operator!=(const Pt &a, const Pt &b){ return !(a==b); }
namespace std {
    template <> struct hash<Pt> {
        size_t operator()(const Pt &a) const { return (hash<ld>()(a.x) ^ hash<ld>()(a.y)); }
    };
}
/// point

//point_vector
// has + sign for left side and - for right side
// equals |a|*|b|*cos(alf)
ld vec(Pt a, Pt b){ return a.x*b.y-a.y*b.x; }
ld vec(Pt a, Pt b, Pt c){ return vec(b-a, c-a); }
// similar vector -> + / oposite -> - sign
ld dot(Pt a, Pt b){ return a.x*b.x+a.y*b.y; }
ld norm(Pt a){ return hypot(a.x, a.y); }
ld angle(Pt a, Pt b){ return acos(dot(a, b)/norm(a)/norm(b)); }
// angle of vector v from +x axis
ld angle(Pt v){ return atan2(v.y, v.x); }
Pt scale_to(Pt a, ld res){ return a*res/norm(a); }
Pt rotate(Pt a, ld rad){ return {a.x*cos(rad)-a.y*sin(rad), a.x*sin(rad)+a.y*cos(rad)}; }  
ld points_distance(Pt a, Pt b){ return norm(b-a); }
///point_vector

//point_vector_methods
Pt fromPolar(ld len, ld ang){ return {len*cos(ang), len*sin(ang)}; }
ld degtorad(ld deg){ return deg/180*M_PI; }
// perpendicular vector of unit length
Pt normal(Pt a){ ld n=norm(a); return {-a.y/n, a.x/n}; }
///point_vector_methods


// LINES ////////////////////////////////////////////////////////////// 

// line
struct Line {
    Pt a, b;
    bool operator<(Line &l){
        Pt v=b-a, w=l.b-l.a;
        return atan2(v.y, v.x) < atan2(w.y, w.x);
    }
};
/// line

// lines
ld line_point_dist(Line l, Pt p){ return fabs(vec(p-l.a, l.b-l.a)/norm(l.b-l.a)); }
Pt lines_intersection(Line p, Line q){
    Pt v=p.b-p.a;
    Pt w=q.b-q.a;
    ld t=vec(w, p.a-q.a)/vec(v, w);
    return p.a+v*t;
}
Pt line_point_closest_point(Line a, Pt b){
    return lines_intersection(a, {b, b+normal(a.b-a.a)});
}
bool line_line_equal(Line a, Line b){
    return eq(vec(a.a-b.b, b.a-b.b), 0) && eq(angle(a.b-a.a), angle(b.b-b.a));
}
/// lines
//todo test: Pt line_point_closest_point(Line l, Pt a){ Pt v=l.b-l.a; return l.a+v*(dot(v, p-l.a)/norm(v)); }


// SEGMENTS /////////////////////////////////////////////////////////// 

// segment
struct Segment{
    Pt a, b;
    bool operator<(const Segment &q){return a!=q.a ? a<q.a : b<q.b; }
    bool operator==(const Segment &q){return (a==q.a&&b==q.b)||(a==q.b&&b==q.a); }
};
/// segment

// segments
bool segment_intersect(Segment s, Segment t){
    ld c1=vec(s.b-s.a, t.a-s.a), c2=vec(s.b-s.a, t.b-s.a);
    ld c3=vec(t.b-t.a, s.a-t.a), c4=vec(t.b-t.a, s.b-t.a);
    return dcmp(c1)*dcmp(c2)<0 && dcmp(c3)*dcmp(c4)<0;
}
ld segment_point_distance(Segment s, Pt p){
    if(s.a==s.b) return norm(p-s.a);
    Pt v1=s.b-s.a, v2=p-s.a, v3=p-s.b;
    if(dcmp(dot(v1, v2))<0) return norm(v2);
    if(dcmp(dot(v1, v3))>0) return norm(v3);
    return fabs(vec(v1, v2))/norm(v1);
}
// including endpoints, put <0 if endpoints not included
bool is_point_on_segment(Pt p, Segment s){
    return dcmp(vec(s.a-p, s.b-p))==0 && dcmp(dot(s.a-p, s.b-p))<=0;
}
/// segments


// CIRCLES //////////////////////////////////////////////////////////// 

// circle
struct Cir {
    Pt s;
    ld r;
    Pt point(double a)const{ return {s.x+cos(a)*r, s.y+sin(a)*r}; }  
    bool operator<(const Cir &a){ return r<a.r; }  
};
/// circle

// circle_methods
ld circle_line_distance(Cir &a, Line &b){
    return max(line_point_dist(b, a.s)-a.r, 0.);
}
ll circle_line_intersection(Cir a, Line b, Pt &p1, Pt &p2){
    if(circle_line_distance(a, b)>0)return 0;
    Pt dv = line_point_closest_point(b, a.s);
    ld d = norm(dv-a.s);
    ld h = sqrt(a.r*a.r-d*d);
    Pt n = scale_to(b.b-b.a, h);
    p1 = dv+n;
    p2 = dv-n;
    return 1+!(eq(p1.x, p2.x) && eq(p1.y, p2.y)); // returns the number of intersections
}
/* From public domain work. 3/26/2005 Tim Voght */
ll circle_circle_intersection(Cir c1, Cir c2, Pt &p1, Pt &p2){
    Pt dp = c2.s - c1.s;
    ld d = norm(dp);
    if (d > (c1.r + c2.r)) return 0; // do not touch
    if (d < fabs(c2.r - c2.r)) return 0; // one inside the other
    ld a = ((c1.r*c1.r) - (c2.r*c2.r) + (d*d)) / (2.0 * d) ;
    Pt pp = c1.s+dp*(a/d);
    ld h = sqrt(c1.r*c1.r - a*a);
    Pt r = {-dp.y * (h/d), dp.x * (h/d)};
    p1 = pp + r;
    p2 = pp - r;
    if(p1==p2) return 1; // touching
    return 2; // proper intersection
}
/// circle_methods

// relative position -1 in, 0 cross, 1 out (2?)
ll circle_circle_relation(Cir a, Cir b){
    if(b.r<a.r)swap(a, b);
    ld d = points_distance(a.s, b.s);
    return (d<b.r)?d+a.r>b.r:d>a.r+b.r;
}

namespace integer{
    struct Pt{
        ll x, y;
        Pt operator-(Pt a){
            return {x-a.x, y-a.y};
        }
    };
    ll vec(Pt a, Pt b){ return a.x*b.y-b.x*a.y; }
    ll area(vector<Pt> &a){
        ll res = vec(a.back(), a.front());
        for(int i=0; i<a.size()-1; ++i){
            res+=vec(a[i], a[i+1]);
        }
        return res;
    }
    ll lattice_points(vector<Pt> &a){
        ll pts = 0;
        for(int i=0; i<a.size(); ++i){
            int j = (i+1)%a.size();
            Pt diff = a[i]-a[j];
            pts += __gcd(abs(diff.x), abs(diff.y));
        }
        ll in = (abs(area(a))-pts+2)/2;
        return in;
    }
}
