// Copyright 2020 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "third_party/nearby/cpp/platform/api/platform.h"

#include <string>

#include "third_party/nearby/cpp/platform/api/mutex.h"
#include "third_party/nearby/cpp/platform/base/payload_id.h"
#import "third_party/nearby/cpp/platform/impl/ios/Source/Internal/GNCCore.h"
#include "third_party/nearby/cpp/platform/impl/ios/Source/Platform/atomic_boolean.h"
#include "third_party/nearby/cpp/platform/impl/ios/Source/Platform/atomic_uint32.h"
#include "third_party/nearby/cpp/platform/impl/ios/Source/Platform/condition_variable.h"
#include "third_party/nearby/cpp/platform/impl/ios/Source/Platform/count_down_latch.h"
#include "third_party/nearby/cpp/platform/impl/ios/Source/Platform/input_file.h"
#import "third_party/nearby/cpp/platform/impl/ios/Source/Platform/log_message.h"
#import "third_party/nearby/cpp/platform/impl/ios/Source/Platform/multi_thread_executor.h"
#include "third_party/nearby/cpp/platform/impl/ios/Source/Platform/mutex.h"
#import "third_party/nearby/cpp/platform/impl/ios/Source/Platform/scheduled_executor.h"
#import "third_party/nearby/cpp/platform/impl/ios/Source/Platform/single_thread_executor.h"
#import "third_party/nearby/cpp/platform/impl/ios/Source/Platform/utils.h"
#include "third_party/nearby/cpp/platform/impl/ios/Source/Platform/wifi_lan.h"
#include "third_party/nearby/cpp/platform/impl/shared/file.h"

namespace location {
namespace nearby {
namespace api {

std::unique_ptr<std::string> ImplementationPlatform::GetDownloadPath(
    std::unique_ptr<std::string> path) {
  // TODO(jfcarroll): Fixme, we need to modulate the path the the system download path
  return path;
}

// Atomics:
std::unique_ptr<AtomicBoolean> ImplementationPlatform::CreateAtomicBoolean(bool initial_value) {
  return std::make_unique<ios::AtomicBoolean>(initial_value);
}

std::unique_ptr<AtomicUint32> ImplementationPlatform::CreateAtomicUint32(
    std::uint32_t initial_value) {
  return std::make_unique<ios::AtomicUint32>(initial_value);
}

std::unique_ptr<CountDownLatch> ImplementationPlatform::CreateCountDownLatch(std::int32_t count) {
  return std::make_unique<ios::CountDownLatch>(count);
}

std::unique_ptr<Mutex> ImplementationPlatform::CreateMutex(Mutex::Mode mode) {
  // iOS does not support unchecked Mutex in debug mode, therefore
  // ios::Mutex is used for both kRegular and kRegularNoCheck.
  if (mode == Mutex::Mode::kRecursive) {
    return absl::make_unique<ios::RecursiveMutex>();
  } else {
    return absl::make_unique<ios::Mutex>();
  }
}

std::unique_ptr<ConditionVariable> ImplementationPlatform::CreateConditionVariable(Mutex* mutex) {
  return std::make_unique<ios::ConditionVariable>(static_cast<ios::Mutex*>(mutex));
}

std::unique_ptr<InputFile> ImplementationPlatform::CreateInputFile(const char* file_path) {
// Extract the NSURL object with payload_id from |GNCCore| which stores the maps. If the retrieved
// NSURL object is not nil, we create InputFile by ios::InputFile. The difference is
// that ios::InputFile implements to read bytes from local real file for sending.
// TODO(jfcarroll): Need someone familiar with iOS to fix this
#if 0
  GNCCore* core = GNCGetCore();
  NSURL* url = [core extractURLWithPayloadID:payload_id];
  if (url != nil) {
    return absl::make_unique<ios::InputFile>(url);
  } else {
    return absl::make_unique<shared::InputFile>(GetDownloadPath(payload_id), total_size);
  }
#endif
  return nullptr;
}

std::unique_ptr<OutputFile> ImplementationPlatform::CreateOutputFile(const char* file_path) {
  return absl::make_unique<shared::OutputFile>(file_path);
}

std::unique_ptr<LogMessage> ImplementationPlatform::CreateLogMessage(
    const char* file, int line, LogMessage::Severity severity) {
  return absl::make_unique<ios::LogMessage>(file, line, severity);
}

// Java-like Executors
std::unique_ptr<SubmittableExecutor> ImplementationPlatform::CreateSingleThreadExecutor() {
  return std::make_unique<ios::SingleThreadExecutor>();
}

std::unique_ptr<SubmittableExecutor> ImplementationPlatform::CreateMultiThreadExecutor(
    int max_concurrency) {
  return std::make_unique<ios::MultiThreadExecutor>(max_concurrency);
}

std::unique_ptr<ScheduledExecutor> ImplementationPlatform::CreateScheduledExecutor() {
  return std::make_unique<ios::ScheduledExecutor>();
}

// Mediums
std::unique_ptr<BluetoothAdapter> ImplementationPlatform::CreateBluetoothAdapter() {
  return nullptr;
}

std::unique_ptr<BluetoothClassicMedium> ImplementationPlatform::CreateBluetoothClassicMedium(
    api::BluetoothAdapter& adapter) {
  return nullptr;
}

std::unique_ptr<BleMedium> ImplementationPlatform::CreateBleMedium(api::BluetoothAdapter& adapter) {
  return nullptr;
}

std::unique_ptr<ble_v2::BleMedium> ImplementationPlatform::CreateBleV2Medium(
    api::BluetoothAdapter& adapter) {
  return nullptr;
}

std::unique_ptr<ServerSyncMedium> ImplementationPlatform::CreateServerSyncMedium() {
  return nullptr;
}

std::unique_ptr<WifiMedium> ImplementationPlatform::CreateWifiMedium() { return nullptr; }

std::unique_ptr<WifiLanMedium> ImplementationPlatform::CreateWifiLanMedium() {
  return std::make_unique<ios::WifiLanMedium>();
}

std::unique_ptr<WebRtcMedium> ImplementationPlatform::CreateWebRtcMedium() { return nullptr; }

}  // namespace api
}  // namespace nearby
}  // namespace location
