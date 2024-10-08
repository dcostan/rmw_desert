#include <stdlib.h>
#include <string.h>

#include "rmw/rmw.h"
#include "rmw/allocators.h"

#include "rclcpp/typesupport_helpers.hpp"

#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_c/field_types.h"

#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/identifier.h"

#include "std_msgs/msg/string.hpp"

#include "classes.h"
#include "debug.h"


rmw_ret_t rmw_borrow_loaned_message(const rmw_publisher_t * publisher, const rosidl_message_type_support_t * type_support, void ** ros_message)
{
  DEBUG("rmw_borrow_loaned_message" "\n");
  return RMW_RET_OK;
}

rmw_ret_t rmw_client_request_publisher_get_actual_qos(const rmw_client_t * client, rmw_qos_profile_t * qos)
{
  DEBUG("rmw_client_request_publisher_get_actual_qos" "\n");
  return RMW_RET_OK;
}

rmw_ret_t rmw_client_response_subscription_get_actual_qos(const rmw_client_t * client, rmw_qos_profile_t * qos)
{
  DEBUG("rmw_client_response_subscription_get_actual_qos" "\n");
  return RMW_RET_OK;
}

rmw_ret_t rmw_client_set_on_new_response_callback(rmw_client_t * client, rmw_event_callback_t callback, const void * user_data)
{
  DEBUG("rmw_client_set_on_new_response_callback" "\n");
  return RMW_RET_OK;
}

rmw_ret_t rmw_compare_gids_equal(const rmw_gid_t * gid1,  const rmw_gid_t * gid2,  bool * result)
{
  DEBUG("rmw_compare_gids_equal" "\n");
  return RMW_RET_OK;
}

rmw_ret_t rmw_count_clients(const rmw_node_t * node, const char * service_name, size_t * count)
{
  DEBUG("rmw_count_clients" "\n");
  return RMW_RET_OK;
}

rmw_ret_t rmw_count_publishers(const rmw_node_t * node, const char * topic_name, size_t * count)
{
  DEBUG("rmw_count_publishers" "\n");
  return RMW_RET_OK;
}

rmw_ret_t rmw_count_services(const rmw_node_t * node, const char * service_name, size_t * count)
{
  DEBUG("rmw_count_services" "\n");
  return RMW_RET_OK;
}

rmw_ret_t rmw_count_subscribers(const rmw_node_t * node, const char * topic_name, size_t * count)
{
  DEBUG("rmw_count_subscribers" "\n");
  return RMW_RET_OK;
}

rmw_client_t * rmw_create_client(const rmw_node_t * node, const rosidl_service_type_support_t * type_supports, const char * service_name, const rmw_qos_profile_t * qos_policies)
{
  DEBUG("rmw_create_client" "\n");

  rmw_client_t * ret = rmw_client_allocate();
  ret->implementation_identifier = rmw_get_implementation_identifier();
  ret->service_name = service_name;
  
  DesertClient * cli = new DesertClient(service_name, type_supports);
  ret->data = (void *)cli;
  
  return ret;
}

rmw_guard_condition_t * rmw_create_guard_condition(rmw_context_t * context)
{
  DEBUG("rmw_create_guard_condition" "\n");
  rmw_guard_condition_t * ret = rmw_guard_condition_allocate();
  ret->data = NULL;
  ret->implementation_identifier = rmw_get_implementation_identifier();
  return ret;
}

rmw_node_t * rmw_create_node(rmw_context_t * context, const char * name, const char * namespace_)
{
  DEBUG("rmw_create_node" "\n");
  rmw_node_t *node = rmw_node_allocate();
  node->implementation_identifier = rmw_get_implementation_identifier();
  node->data = (void*)new DesertNode(name);
  node->context = context;

  const size_t namelen = strlen(name) + 1;
  node->name = (const char*)malloc(namelen);
  memcpy((char*)node->name, name, namelen);

  const size_t nslen = strlen(namespace_) + 1;
  node->namespace_ = (const char*)malloc(nslen);
  memcpy((char*)node->namespace_, namespace_, nslen);

  return node;
}

rmw_publisher_t * rmw_create_publisher(const rmw_node_t * node, const rosidl_message_type_support_t * type_supports, const char * topic_name, const rmw_qos_profile_t * qos_profile, const rmw_publisher_options_t * publisher_options)
{
  DEBUG("rmw_create_publisher" "\n");

  rmw_publisher_t * ret = rmw_publisher_allocate();
  ret->implementation_identifier = rmw_get_implementation_identifier();
  ret->topic_name = topic_name;
  
  DesertPublisher * pub = new DesertPublisher(topic_name, type_supports);
  ret->data = (void *)pub;
  
  return ret;
}

rmw_service_t * rmw_create_service(const rmw_node_t * node, const rosidl_service_type_support_t * type_supports, const char * service_name, const rmw_qos_profile_t * qos_profile)
{
  DEBUG("rmw_create_service" "\n");

  rmw_service_t * ret = rmw_service_allocate();
  ret->implementation_identifier = rmw_get_implementation_identifier();
  ret->service_name = service_name;
  
  DesertService * ser = new DesertService(service_name, type_supports);
  ret->data = (void *)ser;
  
  return ret;
}

rmw_subscription_t * rmw_create_subscription(const rmw_node_t * node, const rosidl_message_type_support_t * type_supports, const char * topic_name, const rmw_qos_profile_t * qos_policies, const rmw_subscription_options_t * subscription_options)
{
  DEBUG("rmw_create_subscription" "\n");

  rmw_subscription_t * ret = rmw_subscription_allocate();
  ret->implementation_identifier = rmw_get_implementation_identifier();
  ret->topic_name = topic_name;
  
  DesertSubscriber* sub = new DesertSubscriber(topic_name, type_supports);
  ret->data = (void*)sub;
  
  return ret;
}

rmw_wait_set_t * rmw_create_wait_set(rmw_context_t * context,  size_t max_conditions)
{
  DEBUG("rmw_create_wait_set" "\n");

  rmw_wait_set_t * ret = rmw_wait_set_allocate();
  ret->implementation_identifier = rmw_get_implementation_identifier();
  
  ret->guard_conditions = NULL;
  
  DesertWaitset* ws = new DesertWaitset();
  ret->data = (void*)ws;
  
  return ret;
}

rmw_ret_t rmw_deserialize(const rmw_serialized_message_t * serialized_message, const rosidl_message_type_support_t * type_support, void * ros_message)
{
  DEBUG("rmw_deserialize" "\n");
  return RMW_RET_OK;
}

rmw_ret_t rmw_destroy_client(rmw_node_t * node,  rmw_client_t * client)
{
  DEBUG("rmw_destroy_client" "\n");
  
  DesertClient * cli = static_cast<DesertClient *>(client->data);
  
  delete cli;
  delete client;
  
  return RMW_RET_OK;
}

rmw_ret_t rmw_destroy_guard_condition(rmw_guard_condition_t * guard_condition)
{
  DEBUG("rmw_destroy_guard_condition" "\n");
  return RMW_RET_OK;
}

rmw_ret_t rmw_destroy_node(rmw_node_t * node)
{
  DEBUG("rmw_destroy_node" "\n");
  
  DesertNode * nod = static_cast<DesertNode *>(node->data);
  
  delete nod;
  delete node;
  
  return RMW_RET_OK;
}

rmw_ret_t rmw_destroy_publisher(rmw_node_t * node,  rmw_publisher_t * publisher)
{
  DEBUG("rmw_destroy_publisher" "\n");
  
  DesertPublisher * pub = static_cast<DesertPublisher *>(publisher->data);
  
  delete pub;
  delete publisher;
  
  return RMW_RET_OK;
}

rmw_ret_t rmw_destroy_service(rmw_node_t * node,  rmw_service_t * service)
{
  DEBUG("rmw_destroy_service" "\n");
  
  DesertService * ser = static_cast<DesertService *>(service->data);
  
  delete ser;
  delete service;
  
  return RMW_RET_OK;
}

rmw_ret_t rmw_destroy_subscription(rmw_node_t * node,  rmw_subscription_t * subscription)
{
  DEBUG("rmw_destroy_subscription" "\n");
  
  DesertSubscriber * sub = static_cast<DesertSubscriber *>(subscription->data);
  
  delete sub;
  delete subscription;
  
  return RMW_RET_OK;
}

rmw_ret_t rmw_destroy_wait_set(rmw_wait_set_t * wait_set)
{
  DEBUG("rmw_destroy_wait_set" "\n");
  
  DesertWaitset * ws = static_cast<DesertWaitset *>(wait_set->data);
  
  delete ws;
  delete wait_set;
  
  return RMW_RET_OK;
}

rmw_ret_t rmw_event_set_callback(rmw_event_t * event, rmw_event_callback_t callback, const void * user_data)
{
  DEBUG("rmw_event_set_callback" "\n");
  return RMW_RET_OK;
}

rmw_ret_t rmw_fini_publisher_allocation(rmw_publisher_allocation_t * allocation)
{
  DEBUG("rmw_fini_publisher_allocation" "\n");
  return RMW_RET_OK;
}

rmw_ret_t rmw_fini_subscription_allocation(rmw_subscription_allocation_t * allocation)
{
  DEBUG("rmw_fini_subscription_allocation" "\n");
  return RMW_RET_OK;
}

rmw_ret_t rmw_get_gid_for_client(const rmw_client_t * client,  rmw_gid_t * gid)
{
  DEBUG("rmw_get_gid_for_client" "\n");
  return RMW_RET_OK;
}

rmw_ret_t rmw_get_gid_for_publisher(const rmw_publisher_t * publisher,  rmw_gid_t * gid)
{
  DEBUG("rmw_get_gid_for_publisher" "\n");
  return RMW_RET_OK;
}

const char * rmw_get_implementation_identifier(void)
{
  static const char * fake_impl_id = "rmw_desert";
  return fake_impl_id;
}

rmw_ret_t rmw_get_node_names(const rmw_node_t * node, rcutils_string_array_t * node_names, rcutils_string_array_t * node_namespaces)
{
  DEBUG("rmw_get_node_names" "\n");
  return RMW_RET_OK;
}

rmw_ret_t rmw_get_node_names_with_enclaves(const rmw_node_t * node, rcutils_string_array_t * node_names, rcutils_string_array_t * node_namespaces, rcutils_string_array_t * enclaves)
{
  DEBUG("rmw_get_node_names_with_enclaves" "\n");
  return RMW_RET_OK;
}

const char * rmw_get_serialization_format(void)
{
  DEBUG("rmw_get_serialization_format" "\n");
  return "";
}

rmw_ret_t rmw_get_serialized_message_size(const rosidl_message_type_support_t * type_support, const rosidl_runtime_c__Sequence__bound * message_bounds, size_t * size)
{
  DEBUG("rmw_get_serialized_message_size" "\n");
  return RMW_RET_OK;
}

rmw_ret_t rmw_init_publisher_allocation(const rosidl_message_type_support_t * type_support, const rosidl_runtime_c__Sequence__bound * message_bounds, rmw_publisher_allocation_t * allocation)
{
  DEBUG("rmw_init_publisher_allocation" "\n");
  return RMW_RET_OK;
}

rmw_ret_t rmw_init_subscription_allocation(const rosidl_message_type_support_t * type_support, const rosidl_runtime_c__Sequence__bound * message_bounds, rmw_subscription_allocation_t * allocation)
{
  DEBUG("rmw_init_subscription_allocation" "\n");
  return RMW_RET_OK;
}

rmw_ret_t rmw_node_assert_liveliness(const rmw_node_t * node)
{
  DEBUG("rmw_node_assert_liveliness" "\n");
  return RMW_RET_OK;
}

const rmw_guard_condition_t * rmw_node_get_graph_guard_condition(const rmw_node_t * node)
{
  DEBUG("rmw_node_get_graph_guard_condition" "\n");
  
  rmw_guard_condition_t * ret = rmw_guard_condition_allocate();
  ret->data = NULL;
  ret->implementation_identifier = rmw_get_implementation_identifier();
  
  return ret;
}

rmw_ret_t rmw_publish(const rmw_publisher_t * publisher, const void * ros_message, rmw_publisher_allocation_t * allocation)
{
  DEBUG("rmw_publish" "\n");
  
  DesertPublisher * pub = static_cast<DesertPublisher *>(publisher->data);
  pub->push(ros_message);
  
  return RMW_RET_OK;
}

rmw_ret_t rmw_publish_loaned_message(const rmw_publisher_t * publisher, void * ros_message, rmw_publisher_allocation_t * allocation)
{
  DEBUG("rmw_publish_loaned_message" "\n");
  return RMW_RET_OK;
}

rmw_ret_t rmw_publish_serialized_message(const rmw_publisher_t * publisher, const rmw_serialized_message_t * serialized_message, rmw_publisher_allocation_t * allocation)
{
  DEBUG("rmw_publish_serialized_message" "\n");
  return RMW_RET_OK;
}

rmw_ret_t rmw_publisher_assert_liveliness(const rmw_publisher_t * publisher)
{
  DEBUG("rmw_publisher_assert_liveliness" "\n");
  return RMW_RET_OK;
}

rmw_ret_t rmw_publisher_count_matched_subscriptions(const rmw_publisher_t * publisher, size_t * subscription_count)
{
  DEBUG("rmw_publisher_count_matched_subscriptions" "\n");
  return RMW_RET_OK;
}

rmw_ret_t rmw_publisher_get_actual_qos(const rmw_publisher_t * publisher, rmw_qos_profile_t * qos)
{
  DEBUG("rmw_publisher_get_actual_qos" "\n");
  return RMW_RET_OK;
}

rmw_ret_t rmw_publisher_wait_for_all_acked(const rmw_publisher_t * publisher, rmw_time_t wait_timeout)
{
  DEBUG("rmw_publisher_wait_for_all_acked" "\n");
  return RMW_RET_OK;
}

rmw_ret_t rmw_return_loaned_message_from_publisher(const rmw_publisher_t * publisher, void * loaned_message)
{
  DEBUG("rmw_return_loaned_message_from_publisher" "\n");
  return RMW_RET_OK;
}

rmw_ret_t rmw_return_loaned_message_from_subscription(const rmw_subscription_t * subscription, void * loaned_message)
{
  DEBUG("rmw_return_loaned_message_from_subscription" "\n");
  return RMW_RET_OK;
}

rmw_ret_t rmw_send_request(const rmw_client_t * client, const void * ros_request, int64_t * sequence_id)
{
  DEBUG("rmw_send_request" "\n");
  
  *sequence_id = rand() % 1000;
  
  DesertClient * cli = static_cast<DesertClient *>(client->data);
  cli->send_request(ros_request, sequence_id);
  
  return RMW_RET_OK;
}

rmw_ret_t rmw_send_response(const rmw_service_t * service, rmw_request_id_t * request_header, void * ros_response)
{
  DEBUG("rmw_send_response" "\n");
  
  DesertService * ser = static_cast<DesertService *>(service->data);
  ser->send_response(ros_response, request_header);
  
  return RMW_RET_OK;
}

rmw_ret_t rmw_serialize(const void * ros_message, const rosidl_message_type_support_t * type_support, rmw_serialized_message_t * serialized_message)
{
  DEBUG("rmw_serialize" "\n");
  return RMW_RET_OK;
}

rmw_ret_t rmw_service_request_subscription_get_actual_qos(const rmw_service_t * service, rmw_qos_profile_t * qos)
{
  DEBUG("rmw_service_request_subscription_get_actual_qos" "\n");
  return RMW_RET_OK;
}

rmw_ret_t rmw_service_response_publisher_get_actual_qos(const rmw_service_t * service, rmw_qos_profile_t * qos)
{
  DEBUG("rmw_service_response_publisher_get_actual_qos" "\n");
  return RMW_RET_OK;
}

rmw_ret_t rmw_service_server_is_available(const rmw_node_t * node, const rmw_client_t * client, bool * is_available)
{
  DEBUG("rmw_service_server_is_available" "\n");
  //*is_available = true;
  return RMW_RET_OK;
}

rmw_ret_t rmw_service_set_on_new_request_callback(rmw_service_t * service, rmw_event_callback_t callback, const void * user_data)
{
  DEBUG("rmw_service_set_on_new_request_callback" "\n");
  return RMW_RET_OK;
}

rmw_ret_t rmw_set_log_severity(rmw_log_severity_t severity)
{
  DEBUG("rmw_set_log_severity" "\n");
  return RMW_RET_OK;
}

rmw_ret_t rmw_subscription_count_matched_publishers(const rmw_subscription_t * subscription, size_t * publisher_count)
{
  DEBUG("rmw_subscription_count_matched_publishers" "\n");
  return RMW_RET_OK;
}

rmw_ret_t rmw_subscription_get_actual_qos(const rmw_subscription_t * subscription, rmw_qos_profile_t * qos)
{
  DEBUG("rmw_subscription_get_actual_qos" "\n");
  return RMW_RET_OK;
}

rmw_ret_t rmw_subscription_get_content_filter(const rmw_subscription_t * subscription, rcutils_allocator_t * allocator, rmw_subscription_content_filter_options_t * options)
{
  DEBUG("rmw_subscription_get_content_filter" "\n");
  return RMW_RET_OK;
}

rmw_ret_t rmw_subscription_set_content_filter(rmw_subscription_t * subscription, const rmw_subscription_content_filter_options_t * options)
{
  DEBUG("rmw_subscription_set_content_filter" "\n");
  return RMW_RET_OK;
}

rmw_ret_t rmw_subscription_set_on_new_message_callback(rmw_subscription_t * subscription, rmw_event_callback_t callback, const void * user_data)
{
  DEBUG("rmw_subscription_set_on_new_message_callback" "\n");
  return RMW_RET_OK;
}

rmw_ret_t rmw_take(const rmw_subscription_t * subscription, void * ros_message, bool * taken, rmw_subscription_allocation_t * allocation)
{
  DEBUG("rmw_take" "\n");
  return RMW_RET_OK;
}

rmw_ret_t rmw_take_loaned_message(const rmw_subscription_t * subscription, void ** loaned_message, bool * taken, rmw_subscription_allocation_t * allocation)
{
  DEBUG("rmw_take_loaned_message" "\n");
  return RMW_RET_OK;
}

rmw_ret_t rmw_take_loaned_message_with_info(const rmw_subscription_t * subscription, void ** loaned_message, bool * taken, rmw_message_info_t * message_info, rmw_subscription_allocation_t * allocation)
{
  DEBUG("rmw_take_loaned_message_with_info" "\n");
  return RMW_RET_OK;
}

rmw_ret_t rmw_take_request(const rmw_service_t * service, rmw_service_info_t * request_header, void * ros_request, bool * taken)
{
  DEBUG("rmw_take_request" "\n");
  
  DesertService * ser = static_cast<DesertService *>(service->data);
  if (ser->has_data())
  {
    ser->read_request(ros_request, request_header);
    *taken = true;
  }
  
  usleep(1000);
  return RMW_RET_OK;
}

rmw_ret_t rmw_take_response(const rmw_client_t * client, rmw_service_info_t * request_header, void * ros_response, bool * taken)
{
  DEBUG("rmw_take_response" "\n");
  
  DesertClient * cli = static_cast<DesertClient *>(client->data);
  if (cli->has_data())
  {
    cli->read_response(ros_response, request_header);
    *taken = true;
  }
  
  usleep(1000);
  return RMW_RET_OK;
}

rmw_ret_t rmw_take_sequence(const rmw_subscription_t * subscription, size_t count, rmw_message_sequence_t * message_sequence, rmw_message_info_sequence_t * message_info_sequence, size_t * taken, rmw_subscription_allocation_t * allocation)
{
  DEBUG("rmw_take_sequence" "\n");
  return RMW_RET_OK;
}

rmw_ret_t rmw_take_serialized_message(const rmw_subscription_t * subscription, rmw_serialized_message_t * serialized_message, bool * taken, rmw_subscription_allocation_t * allocation)
{
  DEBUG("rmw_take_serialized_message" "\n");
  return RMW_RET_OK;
}

rmw_ret_t rmw_take_serialized_message_with_info(const rmw_subscription_t * subscription, rmw_serialized_message_t * serialized_message, bool * taken, rmw_message_info_t * message_info, rmw_subscription_allocation_t * allocation)
{
  DEBUG("rmw_take_serialized_message_with_info" "\n");
  return RMW_RET_OK;
}

rmw_ret_t rmw_take_with_info(const rmw_subscription_t * subscription, void * ros_message, bool * taken, rmw_message_info_t * message_info, rmw_subscription_allocation_t * allocation)
{
  DEBUG("rmw_take_with_info" "\n");
  
  DesertSubscriber * sub = static_cast<DesertSubscriber *>(subscription->data);
  if (sub->has_data())
  {
    sub->read_data(ros_message);
    *taken = true;
  }
  
  usleep(1000);
  return RMW_RET_OK;
}

rmw_ret_t rmw_trigger_guard_condition(const rmw_guard_condition_t * guard_condition)
{
  DEBUG("rmw_trigger_guard_condition" "\n");
  return RMW_RET_OK;
}

rmw_ret_t rmw_wait(rmw_subscriptions_t * subscriptions, rmw_guard_conditions_t * guard_conditions, rmw_services_t * services, rmw_clients_t * clients, rmw_events_t * events, rmw_wait_set_t * wait_set, const rmw_time_t * wait_timeout)
{
  DEBUG("rmw_wait" "\n");
  usleep(1000);
  return RMW_RET_OK;
}

