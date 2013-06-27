/* Copyright 2012 MaidSafe.net limited

This MaidSafe Software is licensed under the MaidSafe.net Commercial License, version 1.0 or later,
and The General Public License (GPL), version 3. By contributing code to this project You agree to
the terms laid out in the MaidSafe Contributor Agreement, version 1.0, found in the root directory
of this project at LICENSE, COPYING and CONTRIBUTOR respectively and also available at:

http://www.novinet.com/license

Unless required by applicable law or agreed to in writing, software distributed under the License is
distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
implied. See the License for the specific language governing permissions and limitations under the
License.
*/

#include "maidsafe/routing/routing_api.h"
#include "maidsafe/routing/routing_impl.h"


namespace maidsafe {

namespace routing {

namespace { typedef boost::asio::ip::udp::endpoint Endpoint; }

template<>
Routing::Routing(const NodeId& node_id) : pimpl_() {
  InitialisePimpl(true, node_id, asymm::GenerateKeyPair());
}

void Routing::InitialisePimpl(bool client_mode,
                              const NodeId& node_id,
                              const asymm::Keys& keys) {
  pimpl_.reset(new Impl(client_mode, node_id, keys));
}

void Routing::Join(Functors functors, std::vector<Endpoint> peer_endpoints) {
  pimpl_->Join(functors, peer_endpoints);
}

int Routing::ZeroStateJoin(Functors functors,
                           const Endpoint& local_endpoint,
                           const Endpoint& peer_endpoint,
                           const NodeInfo& peer_info) {
  return pimpl_->ZeroStateJoin(functors, local_endpoint, peer_endpoint, peer_info);
}

void Routing::SendDirect(const NodeId& destination_id,
                   const std::string& message,
                   const bool& cacheable,
                   ResponseFunctor response_functor) {
  return pimpl_->SendDirect(destination_id, message, cacheable, response_functor);
}

void Routing::SendGroup(const NodeId& destination_id,
                        const std::string& message,
                        const bool& cacheable,
                        ResponseFunctor response_functor) {
  return pimpl_->SendGroup(destination_id, message, cacheable, response_functor);
}

bool Routing::ClosestToId(const NodeId& target_id) {
  return pimpl_->ClosestToId(target_id);
}

GroupRangeStatus Routing::IsNodeIdInGroupRange(const NodeId& group_id) const {
  return pimpl_->IsNodeIdInGroupRange(group_id);
}

GroupRangeStatus Routing::IsNodeIdInGroupRange(const NodeId& group_id,
                                               const NodeId& /*node_id*/) const {
  return pimpl_->IsNodeIdInGroupRange(group_id);  // FIXME
}

NodeId Routing::RandomConnectedNode() {
  return pimpl_->RandomConnectedNode();
}

bool Routing::EstimateInGroup(const NodeId& sender_id, const NodeId& info_id) const {
  return pimpl_->EstimateInGroup(sender_id, info_id);
}

std::future<std::vector<NodeId>> Routing::GetGroup(const NodeId& group_id) {
  return pimpl_->GetGroup(group_id);
}

NodeId Routing::kNodeId() const {
  return pimpl_->kNodeId();
}

int Routing::network_status() {
  return pimpl_->network_status();
}

std::vector<NodeInfo> Routing::ClosestNodes() {
  return pimpl_->ClosestNodes();
}

bool Routing::IsConnectedVault(const NodeId& node_id) {
  return pimpl_->IsConnectedVault(node_id);
}

bool Routing::IsConnectedClient(const NodeId& node_id) {
  return pimpl_->IsConnectedClient(node_id);
}

}  // namespace routing

}  // namespace maidsafe
