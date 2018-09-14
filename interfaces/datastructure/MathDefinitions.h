/**
 * @copyright Copyright (c) 2017 B-com http://www.b-com.com/
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef SOLAR_MATHSDEFINITIONS_H
#define SOLAR_MATHSDEFINITIONS_H

#define EIGEN_DEFAULT_TO_ROW_MAJOR
#include <Eigen/Eigen>


#define SOLAR_PI           3.14159265358979323846
#define SOLAR_RAD2DEG      57.29577951308233
#define SOLAR_DEG2RAD      0.0174532925199433

namespace SolAR {
namespace datastructure {

namespace Maths = Eigen;

template <class T, int Rows, int Cols>
using Matrix = Maths::Matrix<T,Rows,Cols>;

typedef Maths::Matrix<float,3,4> ProjectionMatrix ;
typedef Maths::Matrix<float,3,3> RotationMatrixf;
typedef Maths::Matrix<float,3,3>    CamCalibration;
typedef Maths::Matrix<float, 5, 1>  CamDistortion;
//Pose matrix definition               Vector defintion
//
//  R1x1    R1x2    R1x3    Tx         | X |
//  R2x1    R2x2    R2x3    Ty     *   | Y |
//  R3x1    R3x2    R3x3    Tz         | Z |
//  0       0       0       1          | 1 |
//
// This defintion avoids to apply a tranpose...

typedef Maths::Matrix<float,4,4> PoseMatrix ;


template <class T, int Rows>
using Vector = Maths::Matrix<T,Rows,1>;

typedef Vector<float,4> Vector4f ;
typedef Vector<float,3> Vector3f ;
typedef Vector<double,3>Vector3d ;


template <class T, int Cols>
using RowVector = Maths::Matrix<T,1,Cols>;


template <class T, int Dim>
using Transform = Maths::Transform<T,Dim,Maths::Projective>;
typedef Transform<float,3> Transform3Df;
typedef Transform<float,2> Transform2Df;


template <class T, int Dim>
using Translation = Maths::Translation<T, Dim>;
typedef Translation<float,3> Translation3Df;
typedef Translation<float,2> Translation2Df;


template <class T>
using Quaternion = Maths::Quaternion<T>;
typedef Quaternion<float> Quaternionf;

}
}

#endif // SOLAR_MATHSDEFINITIONS_H
