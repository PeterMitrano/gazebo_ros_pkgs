#include <sdf/sdf.hh>
#include <tf/transform_listener.h>
#include <tf/transform_broadcaster.h>
#include <turtlesim/Pose.h>

#include <gazebo_plugins/gazebo_ros_tf_publisher.h>

using namespace gazebo;

void GazeboRosTfPublisher::Load(physics::WorldPtr world, sdf::ElementPtr _sdf) {
    if (!ros::isInitialized()) {
        auto argc = 0;
        char **argv = nullptr;
        ros::init(argc, argv, "collision_map_plugin", ros::init_options::NoSigintHandler);
    }

    ros_node_ = std::make_unique<ros::NodeHandle>("collision_map_plugin");

    tf::TransformBroadcaster br;
    tf::Transform transform;
    transform.setOrigin(tf::Vector3(0.0, 0.0, 0.0));
    tf::Quaternion q;
    q.setRPY(0, 0, 0);
    transform.setRotation(q);
    br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "world", "gazebo_world"));
}

GZ_REGISTER_WORLD_PLUGIN(GazeboRosTfPublisher)
