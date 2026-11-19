/*
 * 文件: Algorithms/WeilerAthertonAlgorithm.hpp
 * 说明: 多边形裁剪算法。
 *       为保持原有类名/文件名不变，内部按 Sutherland-Hodgman 算法实现。
 *       裁剪窗口是矩形（凸区域），该算法可正确处理任意简单多边形，
 *       包括"多边形完全包住裁剪窗口"和"部分相交"的情况。
 */

#pragma once
#include "Point2D.hpp"
#include "IPolygonAlgorithm.hpp"
#include "ClipWindow.hpp"
#include <vector>

namespace MyGraphics {
    namespace Algorithms {
        class WeilerAthertonAlgorithm : public IPolygonAlgorithm {
        public:
            /**
             * 对多边形进行裁剪
             * @param vertices: 待裁剪的多边形顶点
             * @param window: 矩形裁剪窗口
             * @return: 裁剪后的多边形顶点
             */
            std::vector<Point2D> ClipPolygon(
                const std::vector<Point2D>& vertices,
                const ClipWindow& window) override;

        private:
            enum Boundary { BOUND_LEFT, BOUND_RIGHT, BOUND_TOP, BOUND_BOTTOM };

            static bool IsInside(const Point2D& p, Boundary b, const ClipWindow& w);
            static Point2D Intersect(const Point2D& s, const Point2D& e,
                Boundary b, const ClipWindow& w);
            static std::vector<Point2D> ClipAgainstEdge(
                const std::vector<Point2D>& poly, Boundary b, const ClipWindow& w);
        };
    }
}
