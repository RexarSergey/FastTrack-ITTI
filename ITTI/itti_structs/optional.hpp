#pragma once

#include <signal.h>

#include <exception>
#include <type_traits>
#include <utility>

namespace vran {
namespace common {
namespace common {

template <typename T>
class optional {
public:
  optional() noexcept(std::is_nothrow_constructible<T>::value)
      : payload_{}
      , engaged_{false} {
  }

  template <typename... Args, typename = std::enable_if_t<std::is_constructible<T, Args &&...>::value>>
  optional(Args &&...args) noexcept(std::is_nothrow_constructible<T, Args &&...>::value)
      : payload_(std::forward<Args>(args)...)
      , engaged_{true} {
  }

  optional(optional const &other) noexcept(std::is_nothrow_assignable<T, T>::value)
      : engaged_{other.hasValue()} {
    if (engaged_) {
      payload_ = *other;
    }
  }

  template <typename U, typename = std::enable_if_t<std::is_convertible<U, T>::value>>
  optional(optional<U> const &other) noexcept(std::is_nothrow_assignable<T, U>::value)
      : engaged_{other.hasValue()} {
    if (engaged_) {
      payload_ = *other;
    }
  }

  optional(optional &&other) noexcept
      : engaged_{other.hasValue()} {
    if (engaged_) {
      payload_ = std::move(*other);
      other    = {};
    }
  }

  template <typename U, typename = std::enable_if_t<std::is_convertible<U, T>::value>>
  optional(optional<U> &&other) noexcept
      : engaged_{other.hasValue()} {
    if (engaged_) {
      payload_ = std::move(*other);
      other    = {};
    }
  }

  template <typename U>
  std::enable_if_t<std::is_convertible<U, T>::value, optional &>
  operator=(U const &value) noexcept(std::is_nothrow_assignable<T, U>::value) {
    payload_ = value;
    engaged_ = true;
    return *this;
  }

  template <typename U>
  std::enable_if_t<std::is_convertible<U, T>::value, optional &> operator=(U &&value) noexcept {
    payload_ = std::move(value);
    engaged_ = true;
    return *this;
  }

  optional &operator=(optional const &other) noexcept(std::is_nothrow_assignable<T, T>::value) {
    if (&other != this) {
      engaged_ = other.hasValue();
      if (engaged_) {
        payload_ = *other;
      }
    }
    return *this;
  }

  template <typename U>
  std::enable_if_t<std::is_convertible<U, T>::value, optional &>
  operator=(optional<U> const &other) noexcept(std::is_nothrow_assignable<T, U>::value) {
    engaged_ = other.hasValue();
    if (engaged_) {
      payload_ = *other;
    }
    return *this;
  }

  optional &operator=(optional &&other) noexcept {
    if (&other != this) {
      engaged_ = other.hasValue();
      if (engaged_) {
        payload_ = std::move(*other);
        other    = {};
      }
    }
    return *this;
  }

  template <typename U>
  std::enable_if_t<std::is_convertible<U, T>::value, optional &> operator=(optional<U> &&other) noexcept {
    engaged_ = other.hasValue();
    if (engaged_) {
      payload_ = std::move(*other);
      other    = {};
    }
    return *this;
  }

  ~optional() noexcept(std::is_nothrow_destructible<T>::value) = default;

  bool hasValue() const noexcept {
    return engaged_;
  }

  T const &value() const {
    if (!engaged_) {
      raise (SIGABRT);
    }
    return payload_;
  }

  T &value() {
    if (!engaged_) {
      raise (SIGABRT);
    }
    return payload_;
  }

  void reset() {
    engaged_ = false;
  }

  const T &operator*() const noexcept {
    return payload_;
  }

  T &operator*() noexcept {
    return payload_;
  }

  const T *operator->() const noexcept {
    return &payload_;
  }

  T *operator->() noexcept {
    return &payload_;
  }

  template <typename U>
  bool operator==(const optional<U> &rhs) const {
    if (engaged_ != rhs.hasValue()) {
      return false;
    }

    return !engaged_ || payload_ == *rhs;
  }

private:
  T    payload_;
  bool engaged_;
};

} // namespace common
} // namespace common
} // namespace vran
