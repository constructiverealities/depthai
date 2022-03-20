#include "depthai/pipeline/node/ToF.hpp"

namespace dai {
namespace node {

ToF::ToF(const std::shared_ptr<PipelineImpl>& par, int64_t nodeId) : ToF(par, nodeId, std::make_unique<ToF::Properties>()) {}
ToF::ToF(const std::shared_ptr<PipelineImpl>& par, int64_t nodeId, std::unique_ptr<Properties> props)
    : NodeCRTP<Node, ToF, ToFProperties>(par, nodeId, std::move(props)) {
    setInputRefs({&inputImage});
    setOutputRefs({&out, &amp_out, &err_out, &pc_out, &rgb_pc_out});
}

}
}
