#pragma once

#include <ros/ros.h>
#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>

namespace gazebo {

    class GazeboRosTfPublisher: public WorldPlugin {
        std::unique_ptr<ros::NodeHandle> ros_node_;

    public:
        void Load(physics::WorldPtr world, sdf::ElementPtr _sdf);
    };
}
