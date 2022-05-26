#pragma once

#include "depthai/pipeline/Node.hpp"

// shared
#include <depthai-shared/properties/ToFProperties.hpp>
#include "depthai/pipeline/datatype/ToFConfig.hpp"

namespace dai {
namespace node {

/**
 * @brief ToF node
 */
class ToF : public NodeCRTP<Node, ToF, ToFProperties> {
   public:
    constexpr static const char* NAME = "ToF";

  ToFConfig initialConfig;
  Input inputConfig{*this, "inputConfig", Input::Type::SReceiver, false, 4, {{DatatypeEnum::ToFConfig, false}}};
    /**
     * Constructs ToF node.
     */
    ToF(const std::shared_ptr<PipelineImpl>& par, int64_t nodeId);
    ToF(const std::shared_ptr<PipelineImpl>& par, int64_t nodeId, std::unique_ptr<Properties> props);

    Input inputImage{*this, "inputImage", Input::Type::SReceiver, true, 8, {{DatatypeEnum::ImgFrame, true}}};
    Input rgbImage{*this, "rgbImage", Input::Type::SReceiver, true, 8, {{DatatypeEnum::ImgFrame, true}}};  

    /**
     * Outputs ImgFrame message that carries modified image.
     */
    Output out{*this, "out", Output::Type::MSender, {{DatatypeEnum::ImgFrame, true}}};
    Output amp_out{*this, "amplitude", Output::Type::MSender, {{DatatypeEnum::ImgFrame, true}}};
    Output err_out{*this, "error", Output::Type::MSender, {{DatatypeEnum::ImgFrame, true}}};
  Output pc_out{*this, "pointcloud", Output::Type::MSender, {{DatatypeEnum::Buffer, true}}};
  Output rgb_pc_out{*this, "rgb_pointcloud", Output::Type::MSender, {{DatatypeEnum::Buffer, true}}};      
};

}  // namespace node
}  // namespace dai
