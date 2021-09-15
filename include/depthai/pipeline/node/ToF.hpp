#pragma once

#include "depthai/pipeline/Node.hpp"

namespace dai {
namespace node {

/**
 * @brief ToF node
 */
class ToF : public Node {
   public:

   private:

   public:
  std::string getName() const override { return "ToF"; }
  std::shared_ptr<Node> clone() override;
  nlohmann::json getProperties() override;
    /**
     * Constructs ToF node.
     */
    ToF(const std::shared_ptr<PipelineImpl>& par, int64_t nodeId);

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
