/*******************************************************************************
 *  Copyright 2012 maidsafe.net limited                                        *
 *                                                                             *
 *  The following source code is property of maidsafe.net limited and is not   *
 *  meant for external use.  The use of this code is governed by the licence   *
 *  file licence.txt found in the root of this directory and also on           *
 *  www.maidsafe.net.                                                          *
 *                                                                             *
 *  You are not free to copy, amend or otherwise use this source code without  *
 *  the explicit written permission of the board of directors of maidsafe.net. *
 ******************************************************************************/
#include "maidsafe/routing/node_info.h"

namespace maidsafe {

namespace routing {

NodeInfo::NodeInfo()
    : node_id(),
      public_key(),
      rank(),
      bucket(99999),
      endpoint(),
      dimension_1(),
      dimension_2(),
      dimension_3(),
      dimension_4() {}

}  // namespace routing

}  // namespace maidsafe