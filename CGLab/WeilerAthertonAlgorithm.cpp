/*
 * 文件: Algorithms/WeilerAthertonAlgorithm.cpp
 * 说明: 使用 Sutherland-Hodgman 算法对多边形逐边裁剪。
 *       裁剪窗口为矩形，依次对左、右、上、下四条边界裁剪即可得到交集。
 */

#include "pch.h"
#include "WeilerAthertonAlgorithm.hpp"
#include <cmath>

using namespace MyGraphics;
using namespace MyGraphics::Algorithms;

bool WeilerAthertonAlgorithm::IsInside(
    const Point2D& p, Boundary b, const ClipWindow& w) {
    switch (b) {
    case BOUND_LEFT:   return p.x >= w.GetXmin();
    case BOUND_RIGHT:  return p.x <= w.GetXmax();
    case BOUND_TOP:    return p.y >= w.GetYmin();  // 屏幕坐标中 y 越小越靠上
    case BOUND_BOTTOM: return p.y <= w.GetYmax();
    }
    return true;
}

Point2D WeilerAthertonAlgorithm::Intersect(
    const Point2D& s, const Point2D& e, Boundary b, const ClipWindow& w) {
    double x = s.x;
    double y = s.y;

    if (b == BOUND_LEFT || b == BOUND_RIGHT) {
        double X = (b == BOUND_LEFT) ? w.GetXmin() : w.GetXmax();
        if (e.x != s.x) {
            double t = (X - s.x) / static_cast<double>(e.x - s.x);
            y = s.y + t * (e.y - s.y);
        }
        x = X;
    }
    else {
        double Y = (b == BOUND_TOP) ? w.GetYmin() : w.GetYmax();
        if (e.y != s.y) {
            double t = (Y - s.y) / static_cast<double>(e.y - s.y);
            x = s.x + t * (e.x - s.x);
        }
        y = Y;
    }

    return Point2D(static_cast<int>(std::lround(x)),
        static_cast<int>(std::lround(y)));
}

std::vector<Point2D> WeilerAthertonAlgorithm::ClipAgainstEdge(
    const std::vector<Point2D>& poly, Boundary b, const ClipWindow& w) {
    std::vector<Point2D> output;
    if (poly.empty()) return output;

    for (size_t i = 0; i < poly.size(); ++i) {
        const Point2D& current = poly[i];
        const Point2D& previous = poly[(i + poly.size() - 1) % poly.size()];

        bool currentInside = IsInside(current, b, w);
        bool previousInside = IsInside(previous, b, w);

        if (currentInside) {
            if (!previousInside) {
                output.push_back(Intersect(previous, current, b, w));
            }
            output.push_back(current);
        }
        else if (previousInside) {
            output.push_back(Intersect(previous, current, b, w));
        }
    }

    return output;
}

std::vector<Point2D> WeilerAthertonAlgorithm::ClipPolygon(
    const std::vector<Point2D>& vertices, const ClipWindow& window) {
    if (vertices.size() < 3) return std::vector<Point2D>();

    std::vector<Point2D> result = vertices;
    result = ClipAgainstEdge(result, BOUND_LEFT, window);
    result = ClipAgainstEdge(result, BOUND_RIGHT, window);
    result = ClipAgainstEdge(result, BOUND_TOP, window);
    result = ClipAgainstEdge(result, BOUND_BOTTOM, window);

    // 去掉连续重复点，避免绘制出零长度边
    std::vector<Point2D> cleaned;
    for (const auto& p : result) {
        if (cleaned.empty() || cleaned.back() != p) {
            cleaned.push_back(p);
        }
    }
    if (cleaned.size() > 1 && cleaned.front() == cleaned.back()) {
        cleaned.pop_back();
    }
    return cleaned;
}
