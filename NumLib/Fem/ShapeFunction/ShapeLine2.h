/**
 * \copyright
 * Copyright (c) 2012-2014, OpenGeoSys Community (http://www.opengeosys.org)
 *            Distributed under a Modified BSD License.
 *              See accompanying file LICENSE.txt or
 *              http://www.opengeosys.org/project/license
 *
 */

#ifndef SHAPELINE2_H_
#define SHAPELINE2_H_

#include "MeshLib/Elements/Line.h"

namespace NumLib
{

/**
 *  Shape function for a line element of two nodes in natural coordinates
 *
 * \verbatim
 *  2 (-1,0)     1 (1,0)
 *     *--------*
 * \endverbatim
 */
class ShapeLine2
{
public:
    /**
     * Evaluate the shape function at the given point
     *
     * @param [in]  r    point coordinates
     * @param [out] N   a vector of calculated shape function.
     */
    template <class T_X, class T_N>
    static void computeShapeFunction(const T_X &r, T_N &N);

    /**
     * Evaluate derivatives of the shape function at the given point
     *
     * @param [in]  r    point coordinates
     * @param [out] dN  a matrix of the derivatives
     */
    template <class T_X, class T_N>
    static void computeGradShapeFunction(const T_X &r, T_N &dN);

    using MeshElement = MeshLib::Line;
    static constexpr std::size_t DIM = MeshElement::dimension;
    static constexpr std::size_t NPOINTS = MeshElement::n_all_nodes;
};

}

#include "ShapeLine2-impl.h"

#endif //SHAPELINE2_H_
