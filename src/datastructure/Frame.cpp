#include "datastructure/Frame.h"
namespace SolAR {
namespace datastructure {

    Frame::Frame()
    {
        m_countOfFramesSinceLastKframe = 0 ;
    }


    Frame::~Frame()
    {
    }


    void Frame::InitKeyPointsAndDescriptors(std::vector<SRef<Keypoint>> keypoints, SRef<DescriptorBuffer> descriptors)
    {
        m_keypoints = keypoints ;
        m_descriptor = descriptors ;
    }

    void Frame::setReferenceKeyFrame(SRef<Keyframe> kframe)
    {
        m_refrenceKeyFrame = kframe ;
    }

    SRef<Keyframe> Frame::getReferenceKeyFrame()
    {
        return m_refrenceKeyFrame ;
    }


    SRef<DescriptorBuffer> Frame::getDescriptors()
    {
        return m_descriptor ;
    }

    std::vector<SRef<Keypoint>> Frame::getKeyPoints()
    {
        return m_keypoints ;
    }

    void   Frame::setNumberOfFramesSinceLastKeyFrame(unsigned int nbFrames)
    {
       m_countOfFramesSinceLastKframe = nbFrames ;  ;
    }

    unsigned int Frame::getNumberOfFramesSinceLastKeyFrame() const
    {
        return m_countOfFramesSinceLastKframe ;
    }

    void  Frame::setMatchesWithReferenceKeyFrame(std::vector<DescriptorMatch> & matches)
    {
        m_matchesWithReferenceKeyFrame = matches ;
    }

    std::vector<DescriptorMatch> &   Frame::getMatchesWithReferenceKeyFrame()
    {
        return m_matchesWithReferenceKeyFrame ; //
    }

    void Frame::addCommonMapPointsWithReferenceKeyFrame(std::vector<SRef<CloudPoint>> & points)
    {
        m_trackedPoints.insert(m_trackedPoints.end(), points.begin(), points.end());
    }

    std::vector<SRef<CloudPoint>> &  Frame::getCommonMapPointsWithReferenceKeyFrame()
    {
        return m_trackedPoints ;
    }


    /*unsigned int  Frame::getNumberOfMatchesWithReferenceKeyFrame()
    {
        return static_cast<unsigned int>(m_matchesWithReferenceKeyFrame.size()) ;
    }*/
}
}
