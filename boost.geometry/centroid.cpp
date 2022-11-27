/***************************************************************** 
* 
* filename: 
* description：计算形心.
* author: 
* see：https://www.boost.org/doc/libs/1_79_0/libs/geometry/doc/html/geometry/reference/algorithms/centroid/centroid_2.html
*********************************************************************/
#include <iostream>
#include <list>

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/geometries/polygon.hpp>


int main()
{
    typedef boost::geometry::model::d2::point_xy<double> point_type;
    typedef boost::geometry::model::polygon<point_type> polygon_type;

    polygon_type poly;
    boost::geometry::read_wkt(
        "POLYGON((2 1.3,2.4 1.7,2.8 1.8,3.4 1.2,3.7 1.6,3.4 2,4.1 3,5.3 2.6,5.4 1.2,4.9 0.8,2.9 0.7,2 1.3)"
            "(4.0 2.0, 4.2 1.4, 4.8 1.9, 4.4 2.2, 4.0 2.0))", poly);

    point_type p;
    boost::geometry::centroid(poly, p);

    std::cout << "centroid: " << boost::geometry::dsv(p) << std::endl;

    return 0;
}

//参考
//http://www.paulbourke.net/geometry/polygonmesh/centroid.pdf
//https://www.cnblogs.com/jbelial/archive/2011/08/08/2131165.html