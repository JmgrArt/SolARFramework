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

#ifndef SOLAR_IIMAGEVIEWER_H
#define SOLAR_IIMAGEVIEWER_H

#include "datastructure/Image.h"
#include "xpcf/api/IComponentIntrospect.h"
#include "core/Messages.h"

namespace SolAR {
using namespace datastructure;
namespace api {
namespace display {
/**
 * @class IImageViewer
 * @brief Viewer interface to display an image in a window.
 *
 * This class provides a viewer to display an image in a window.
 */

class IImageViewer : public virtual org::bcom::xpcf::IComponentIntrospect {
public:
    virtual ~IImageViewer() = default;


    /// \brief this method displays an image contained in a Image object in a window
    /// @param[in] img The image to display in the window
    /// @return FrameworkReturnCode::_SUCCESS if the window is created, else FrameworkReturnCode::_ERROR_
    virtual FrameworkReturnCode display(SRef<Image> img) = 0;

};
}
}
}

XPCF_DEFINE_INTERFACE_TRAITS(SolAR::api::display::IImageViewer,
                             "B05F3DBB-F93D-465C-AEE1-FB58E1480C42",
                             "IImageViewer",
                             "SolAR::IImageViewer interface")

#endif
