/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#ifndef MODULES_CANBUS_VEHICLE_LEXUS_PROTOCOL_STEERING_CMD_12C_H_
#define MODULES_CANBUS_VEHICLE_LEXUS_PROTOCOL_STEERING_CMD_12C_H_

#include "modules/canbus/proto/chassis_detail.pb.h"
#include "modules/drivers/canbus/can_comm/protocol_data.h"

namespace apollo {
namespace canbus {
namespace lexus {

class Steeringcmd12c : public ::apollo::drivers::canbus::ProtocolData<
                           ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Steeringcmd12c();
  void Parse(const std::uint8_t* bytes, int32_t length,
             ChassisDetail* chassis) const override;

 private:
  // config detail: {'name': 'IGNORE_OVERRIDES', 'offset': 0.0,
  // 'precision': 1.0, 'len': 1, 'is_signed_var': False, 'physical_range':
  // '[0|1]', 'bit': 1, 'type': 'bool', 'order': 'motorola', 'physical_unit':
  // ''}
  bool ignore_overrides(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'name': 'ENABLE', 'offset': 0.0, 'precision': 1.0, 'len':
  // 1, 'is_signed_var': False, 'physical_range': '[0|1]', 'bit': 0, 'type':
  // 'bool', 'order': 'motorola', 'physical_unit': ''}
  bool enable(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'name': 'CLEAR_OVERRIDE', 'offset': 0.0, 'precision': 1.0,
  // 'len': 1, 'is_signed_var': False, 'physical_range': '[0|1]', 'bit': 2,
  // 'type': 'bool', 'order': 'motorola', 'physical_unit': ''}
  bool clear_override(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'name': 'CLEAR_FAULTS', 'offset': 0.0, 'precision': 1.0,
  // 'len': 1, 'is_signed_var': False, 'physical_range': '[0|1]', 'bit': 3,
  // 'type': 'bool', 'order': 'motorola', 'physical_unit': ''}
  bool clear_faults(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'name': 'POSITION', 'offset': 0.0, 'precision': 0.001,
  // 'len': 16, 'is_signed_var': True, 'physical_range': '[-32.768|32.767]',
  // 'bit': 15, 'type': 'double', 'order': 'motorola', 'physical_unit': 'rad'}
  double position(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'name': 'ROTATION_RATE', 'offset': 0.0, 'precision': 0.001,
  // 'len': 16, 'is_signed_var': False, 'physical_range': '[0|65.535]', 'bit':
  // 31, 'type': 'double', 'order': 'motorola', 'physical_unit': 'rad/s'}
  double rotation_rate(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace lexus
}  // namespace canbus
}  // namespace apollo

#endif  // MODULES_CANBUS_VEHICL_LEXUS_PROTOCOL_STEERING_CMD_12C_H_
