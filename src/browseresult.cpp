#include "browseresult.hpp"

namespace open62541 {

class BrowseResult::impl {
  StatusCode m_status_code;
  ByteString m_continuation_point;
  std::vector<ReferenceDescription> m_references;

 public:
  impl() {}
  impl(StatusCode status_code,
       const ByteString &continuation_point,
       const std::vector<ReferenceDescription> &references)
      : m_status_code{status_code},
        m_continuation_point{continuation_point},
        m_references{references} {}
  StatusCode status_code() { return m_status_code; }
  ByteString continuation_point() { return m_continuation_point; }
  std::vector<ReferenceDescription> references() { return m_references; }
};

BrowseResult::BrowseResult() : d_ptr{std::make_unique<impl>()} {}

BrowseResult::BrowseResult(StatusCode status_code,
                           const ByteString &continuation_point,
                           const std::vector<ReferenceDescription> &references)
    : d_ptr{std::make_unique<impl>(
          status_code, continuation_point, references)} {}

StatusCode BrowseResult::status_code() const { return d_ptr->status_code(); }

ByteString BrowseResult::continuation_point() const {
  return d_ptr->continuation_point();
}

std::vector<ReferenceDescription> BrowseResult::references() const {
  return d_ptr->references();
}

BrowseResult::BrowseResult(BrowseResult const &op)
    : d_ptr(new impl(*op.d_ptr)) {}

BrowseResult &BrowseResult::operator=(BrowseResult const &op) {
  if (this != &op) {
    d_ptr.reset(new impl(*op.d_ptr));
  }
  return *this;
}

BrowseResult::~BrowseResult() = default;

}  // namespace open62541