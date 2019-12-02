#ifndef CPP_GRPC_COMMON_COMPAT_H_
#define CPP_GRPC_COMMON_COMPAT_H_

#ifdef OLD_GRPC_VERSION

#include "grpc++/impl/codegen/client_context.h"

namespace grpc {
namespace internal {

// Map "grpc::internal" to "grpc".
using namespace grpc;

// Factories are copied from:
// https://github.com/grpc/grpc/blob/master/include/grpcpp/impl/codegen/sync_stream_impl.h
template <class R>
class ClientReaderFactory {
 public:
  template <class W>
  static ClientReader<R>* Create(::grpc::ChannelInterface* channel,
                                 const ::grpc::internal::RpcMethod& method,
                                 ::grpc::ClientContext* context,
                                 const W& request) {
    return new ClientReader<R>(channel, method, context, request);
  }
};

template <class W>
class ClientWriterFactory {
 public:
  template <class R>
  static ClientWriter<W>* Create(::grpc::ChannelInterface* channel,
                                 const ::grpc::internal::RpcMethod& method,
                                 ::grpc::ClientContext* context, R* response) {
    return new ClientWriter<W>(channel, method, context, response);
  }
};

template <class W, class R>
class ClientReaderWriterFactory {
 public:
  static ClientReaderWriter<W, R>* Create(
      ::grpc::ChannelInterface* channel,
      const ::grpc::internal::RpcMethod& method,
      ::grpc::ClientContext* context) {
    return new ClientReaderWriter<W, R>(channel, method, context);
  }
};

}  // namespace internal
}  // namespace grpc

#endif  // OLD_GRPC_VERSION

#endif  // CPP_GRPC_COMMON_COMPAT_H_