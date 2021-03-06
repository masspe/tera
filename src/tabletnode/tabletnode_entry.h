// Copyright (c) 2015, Baidu.com, Inc. All Rights Reserved
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// Author: An Qin (qinan@baidu.com)

#ifndef TERA_TABLETNODE_TABLETNODE_ENTRY_H_
#define TERA_TABLETNODE_TABLETNODE_ENTRY_H_

#include <sofa/pbrpc/pbrpc.h>

#include "common/base/scoped_ptr.h"
#include "common/metric/metric_http_server.h"
#include "tera/tera_entry.h"

namespace tera {

namespace master {
class MasterClient;
}

namespace tabletnode {

class TabletNodeImpl;
class RemoteTabletNode;

class TabletNodeEntry : public TeraEntry {
 public:
  TabletNodeEntry();
  ~TabletNodeEntry();

  bool StartServer();
  bool Run();
  void ShutdownServer();

  void SetProcessorAffinity();

 private:
  scoped_ptr<TabletNodeImpl> tabletnode_impl_;
  RemoteTabletNode* remote_tabletnode_;
  scoped_ptr<sofa::pbrpc::RpcServer> rpc_server_;
  scoped_ptr<tera::MetricHttpServer> metric_http_server_;
};

}  // namespace tabletnode
}  // namespace tera

#endif  // TERA_TABLETNODE_TABLETNODE_ENTRY_H_
