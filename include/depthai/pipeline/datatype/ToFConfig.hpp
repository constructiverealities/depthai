#pragma once

#include <unordered_map>
#include <vector>

#include "depthai-shared/datatype/RawToFConfig.hpp"
#include "depthai/pipeline/datatype/Buffer.hpp"

namespace dai {
class ToFConfig : public Buffer {
    std::shared_ptr<RawBuffer> serialize() const override;
    RawToFConfig& cfg;

   public:
    /**
     * Construct ToFConfig message.
     */
    ToFConfig();
    explicit ToFConfig(std::shared_ptr<RawToFConfig> ptr);
    virtual ~ToFConfig() = default;
  const dai::RawToFConfig& get() const;
  dai::RawToFConfig& get();  
};

}  // namespace dai
