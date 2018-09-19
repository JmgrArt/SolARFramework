#ifndef ITRIANGULATOR_H
#define ITRIANGULATOR_H

#include "xpcf/api/IComponentIntrospect.h"
#include "core/Messages.h"
#include "datastructure/GeometryDefinitions.h"
#include "datastructure/MathDefinitions.h"
#include "datastructure/Image.h"
#include "datastructure/Keypoint.h"
#include "datastructure/CloudPoint.h"
#include "datastructure/DescriptorMatch.h"


namespace SolAR {
using namespace datastructure;
namespace api {
namespace solver {
namespace map {

/**
 * @class ITriangulator
 * @brief Triangulates a set of 2D-2d points correspondances with known respective camera poses.
 */
class  ITriangulator : public virtual org::bcom::xpcf::IComponentIntrospect {
public:
    /// @brief ITriangulator default constructor
    ITriangulator() = default;

    /// @brief ITriangulator default destructor
    virtual ~ITriangulator() = default;

    /// @brief this method is used to set intrinsic parameters and distorsion of the camera
    /// @param[in] Camera calibration matrix parameters.
    /// @param[in] Camera distorsion parameters.
    virtual void setCameraParameters(const CamCalibration & intrinsicParams, const CamDistortion & distorsionParams) = 0;

    /// @brief triangulate pairs of points 2d captured from two views with differents poses (with respect to the camera instrinsic parameters).
    /// @param[in] pointsView1, set of 2D points seen in view_1.
    /// @param[in] pointsView2, set of 2D points seen in view_2.
    /// @param[in] matches, the matches between the keypoints of the view1 and the keypoints of the view 2.
    /// @param[in] working_views, a pair representing the id of the two views
    /// @param[in] poseView1, camera pose in the world coordinates system of the view_1 expressed as a Transform3D.
    /// @param[in] poseView2, camera pose in the world coordinates system of the view_2 expressed as a Transform3D..
    /// @param[out] pcloud, set of triangulated 3d_points.
    /// @return the mean re-projection error (mean distance in pixels between the original 2D points and the projection of the reconstructed 3D points)
    virtual double triangulate(const std::vector<SRef<Point2Df>>& pointsView1,
                               const std::vector<SRef<Point2Df>>& pointView2,
                               const std::vector<DescriptorMatch>&matches,
                               const std::pair<int,int>&working_views,
                               const Transform3Df& poseView1,
                               const Transform3Df& poseView2,
                               std::vector<SRef<CloudPoint>>& pcloud)=0;

    /// @brief triangulate pairs of points 2d captured from two views with differents poses (with respect to the camera instrinsic parameters).
    /// @param[in] keypointsView1, set of keypoints seen in view_1.
    /// @param[in] keypointsView2, set of keypoints seen in view_2.
    /// @param[in] matches, the matches between the keypoints of the view1 and the keypoints of the view 2.
    /// @param[in] working_views, a pair representing the id of the two views
    /// @param[in] poseView1, camera pose in the world coordinates system of the view_1 expressed as a Transform3D.
    /// @param[in] poseView2, camera pose in the world coordinates system of the view_2 expressed as a Transform3D..
    /// @param[out] pcloud, set of triangulated 3d_points.
    /// @return the mean re-projection error (mean distance in pixels between the original 2D points and the projection of the reconstructed 3D points)
    virtual double triangulate(const std::vector<SRef<Keypoint>>& keypointsView1,
                               const std::vector<SRef<Keypoint>>& keypointsView2,
                               const std::vector<DescriptorMatch>&matches,
                               const std::pair<int,int>&working_views,
                               const Transform3Df& poseView1,
                               const Transform3Df& poseView2,
                               std::vector<SRef<CloudPoint>>& pcloud)=0;
};

}
}
}
}  // end of namespace Solar

XPCF_DEFINE_INTERFACE_TRAITS(SolAR::api::solver::map::ITriangulator,
                             "3a01b0e9-9a76-43f5-97b3-85bb6979b953",
                             "SolAR::api::solver::map::ITriangulator interface");

#endif // ITRIANGULATOR_H
