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

#ifndef SOLAR_IDESCRIPTORMATCHER_H
#define SOLAR_IDESCRIPTORMATCHER_H

#ifndef _BCOM_SHARED
#define _BCOM_SHARED
#endif // _BCOM_SHARED

#include <vector>
//#include "IDescriptor.h"
#include "datastructure/DescriptorBuffer.h"
#include "datastructure/DescriptorMatch.h"

// Definition of IDescriptorMatcher Class //
// part of SolAR namespace //

#include "xpcf/api/IComponentIntrospect.h"

namespace SolAR {
using namespace datastructure;
namespace api {
namespace features {

	namespace DescriptorMatcher {

    ///
    /// \brief The DescriptorMatcher return codes
    ///
		enum  RetCode {
          DESCRIPTORS_MATCHER_OK=0,     /**< the default OK code*/
           DESCRIPTORS_DONT_MATCH,      /**< try to match descriptors of different types*/
           DESCRIPTOR_TYPE_UNDEFINED,   /**< one of the descriptor sets is is unknown*/
           DESCRIPTOR_EMPTY             /**< One set is empty*/
		};

    }    // end of namespace DescriptorMatcher

/**
 * @class IDescriptorMatcher
 * @brief matches two sets of descriptors together
 *
 * This class provides a filtering method to prune a set of contours.
 */
    class  IDescriptorMatcher : public virtual org::bcom::xpcf::IComponentIntrospect {
    public:
        /// @brief IDescriptorMatcher default constructor
        IDescriptorMatcher() = default;

        /// @brief IDescriptorMatcher default destructor
        virtual ~IDescriptorMatcher() {};


        /// @brief Match two sets of descriptors together
        /// @param[in] descriptors1 The first set of descriptors organized in a dedicated buffer structure.
        /// @param[in] descriptors2 The second set of descriptors organized in a dedicated buffer structure.
        /// @param[out] matches A vector of matches representing pairs of indices relatively to the first and second set of descriptors.
        /// @return DesciptorMatcher::DESCRIPTORS_MATCHER_OK if matching succeeds, DesciptorMatcher::DESCRIPTORS_DONT_MATCH if the types of descriptors are different, DesciptorMatcher::DESCRIPTOR_TYPE_UNDEFINED if one of the descriptors set is unknown, or DesciptorMatcher::DESCRIPTOR_EMPTY if one of the set is empty.
        virtual DescriptorMatcher::RetCode match(
               SRef<DescriptorBuffer> descriptors1,
               SRef<DescriptorBuffer> descriptors2,
               std::vector<DescriptorMatch>& matches
            )=0;

        /// @brief Match two sets of descriptors together. The second set is organized in a vector of descriptors buffer and can be used if the descriptors have been extracted on subsets of an image.
        /// @param[in] descriptors1 The first set of descriptors organized in a dedicated buffer structure.
        /// @param[in] descriptors2 The second set of descriptors organized in a vectir of dedicated buffer structure.
        /// @param[out] matches A vector of matches representing pairs of indices relatively to the first and second set of descriptors.
        /// @return DesciptorMatcher::DESCRIPTORS_MATCHER_OK if matching succeeds, DesciptorMatcher::DESCRIPTORS_DONT_MATCH if the types of descriptors are different, DesciptorMatcher::DESCRIPTOR_TYPE_UNDEFINED if one of the descriptors set is unknown, or DesciptorMatcher::DESCRIPTOR_EMPTY if one of the set is empty.
        virtual DescriptorMatcher::RetCode match(
               SRef<DescriptorBuffer> descriptors1,
               std::vector<SRef<DescriptorBuffer>>& descriptors2,
               std::vector<DescriptorMatch>& matches
            )=0;            


    };
}
}
}  // end of namespace SolAR

XPCF_DEFINE_INTERFACE_TRAITS(SolAR::api::features::IDescriptorMatcher,
                             "dda38a40-c50a-4e7d-8433-0f04c7c98518",
                             "IDescriptorMatcher",
                             "SolAR::api::features::IDescriptorMatcher");

#endif // SOLAR_IDESCRIPTORMATCHER_H
