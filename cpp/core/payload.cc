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

#include "core/payload.h"

namespace location {
namespace nearby {
namespace connections {

// Payload is default-constructible, and moveable, but not copyable container
// that holds at most one instance of one of:
// ByteArray, InputStream, or InputFile.
Payload::Payload(Payload&& other) noexcept {
  file_name_ = other.file_name_;
  parent_folder_ = other.parent_folder_;
  content_ = std::move(other.content_);
  id_ = other.id_;
  offset_ = other.offset_;
  type_ = other.type_;
}
Payload::~Payload() = default;
Payload& Payload::operator=(Payload&& other) noexcept {
  file_name_ = other.file_name_;
  parent_folder_ = other.parent_folder_;
  content_ = std::move(other.content_);
  id_ = other.id_;
  offset_ = other.offset_;
  type_ = other.type_;
  return *this;
}

// Default (invalid) payload.
Payload::Payload() : content_(absl::monostate()) {}

// Constructors for outgoing payloads.
Payload::Payload(ByteArray&& bytes) : content_(std::move(bytes)) {}

Payload::Payload(const ByteArray& bytes) : content_(bytes) {}

Payload::Payload(const char* parent_folder, const char* file_name,
                 InputFile&& file)
    : content_(std::move(file)),
      parent_folder_(parent_folder),
      file_name_(file_name) {}

// TODO(jfcarroll): Convert std::function to function pointer
Payload::Payload(std::function<InputStream&()> stream)
    : content_(std::move(stream)) {}

// Constructors for incoming payloads.
Payload::Payload(Id id, ByteArray&& bytes)
    : content_(std::move(bytes)), id_(id) {}

Payload::Payload(Id id, const ByteArray& bytes) : content_(bytes), id_(id) {}

Payload::Payload(Id id, InputFile&& file)
    : content_(std::move(file)), id_(id), parent_folder_("") {
  auto fileName = std::to_string(id);
  file_name_ = fileName.c_str();

  NEARBY_LOGS(INFO) << "Payload(Id,InputFile): parent folder ="
                    << parent_folder_ << " file name = " << file_name_ << "\n";
}

// TODO(jfcarroll): Convert std::function to function pointer
Payload::Payload(Id id, std::function<InputStream&()> stream)
    : content_(std::move(stream)), id_(id) {}

// Returns ByteArray payload, if it has been defined, or empty ByteArray.
const ByteArray& Payload::AsBytes() const& {
  static const ByteArray empty;  // NOLINT: function-level static is OK.
  auto* result = absl::get_if<ByteArray>(&content_);
  return result ? *result : empty;
}
ByteArray&& Payload::AsBytes() && {
  auto* result = absl::get_if<ByteArray>(&content_);
  return result ? std::move(*result) : std::move(ByteArray());
}
// Returns InputStream* payload, if it has been defined, or nullptr.
InputStream* Payload::AsStream() {
  auto* result = absl::get_if<std::function<InputStream&()>>(&content_);
  return result ? &(*result)() : nullptr;
}
// Returns InputFile* payload, if it has been defined, or nullptr.
const InputFile* Payload::AsFile() const {
  return absl::get_if<InputFile>(&content_);
}

// Returns Payload unique ID.
Payload::Id Payload::GetId() const { return id_; }

// Returns Payload type.
Payload::Type Payload::GetType() const { return type_; }

// Sets the payload offset in bytes
void Payload::SetOffset(size_t offset) {
  CHECK(type_ == Type::kFile || type_ == Type::kStream);
  const InputFile* file = AsFile();
  if (file != nullptr) {
    NEARBY_LOGS(INFO) << "Payload::SetOffset: offset: " << offset
                      << " file total size : " << file->GetTotalSize() << "\n";
    CHECK(file->GetTotalSize() > 0 && offset < (size_t)file->GetTotalSize());
  }
  offset_ = offset;
}

size_t Payload::GetOffset() { return offset_; }

// Generate Payload Id; to be passed to outgoing file constructor.
Payload::Id Payload::GenerateId() { return Prng().NextInt64(); }

Payload::Type Payload::FindType() const {
  return static_cast<Type>(content_.index());
}

const std::string Payload::GetParentFolder() const {
  return std::string(parent_folder_);
}

const std::string Payload::GetFileName() const {
  return std::string(file_name_);
}

}  // namespace connections
}  // namespace nearby
}  // namespace location
