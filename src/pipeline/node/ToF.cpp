#include "depthai/pipeline/node/ToF.hpp"

namespace dai {
namespace node {

ToF::ToF(const std::shared_ptr<PipelineImpl>& par, int64_t nodeId) : ToF(par, nodeId, std::make_unique<ToF::Properties>()) {}
ToF::ToF(const std::shared_ptr<PipelineImpl>& par, int64_t nodeId, std::unique_ptr<Properties> props)
    : NodeCRTP<Node, ToF, ToFProperties>(par, nodeId, std::move(props)) {
    setInputRefs({&inputImage});
    setOutputRefs({&out, &amp_out, &err_out, &pc_out, &rgb_pc_out});
}

  void ToF::setFilterConfig(const std::string& hex) {
      std::vector<uint8_t> bytes;
      for (unsigned int i = 0; i < hex.length(); i += 2) {
	std::string byteString = hex.substr(i, 2);
	uint8_t byte = (uint8_t) strtol(byteString.c_str(), nullptr, 16);
	bytes.push_back(byte);
      }
      setFilterConfig(bytes);
  }

  void ToF::setFilterConfig(const std::vector<uint8_t>& filter_config) {
    properties.filter_config = filter_config;
  }

  void ToF::setCalibration(const std::vector<uint8_t>& calibration) {
    properties.tof_calibration = calibration;
  }
}
}
