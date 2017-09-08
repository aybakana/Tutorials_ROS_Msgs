#include "ros/ros.h"
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Accel.h>
#include <geometry_msgs/Transform.h>
#include <geometry_msgs/Inertia.h>

void pointCallback(const geometry_msgs::Point::ConstPtr& point)
{
	ROS_INFO("I heard: [%s]", point->x);
	ROS_INFO("I heard: [%s]", point->y);
	ROS_INFO("I heard: [%s]", point->z);
}

void poseCallback(const geometry_msgs::Pose::ConstPtr& pose)
{
	ROS_INFO("I heard: [%s]", pose->position.x);
	ROS_INFO("I heard: [%s]", pose->position.y);
	ROS_INFO("I heard: [%s]", pose->position.z);
	ROS_INFO("I heard: [%s]", pose->orientation.x);
	ROS_INFO("I heard: [%s]", pose->orientation.y);
	ROS_INFO("I heard: [%s]", pose->orientation.z);
	ROS_INFO("I heard: [%s]", pose->orientation.w);
}

void twistCallback(const geometry_msgs::Twist::ConstPtr& twist)
{
	ROS_INFO("I heard: [%s]", twist->linear.x);
	ROS_INFO("I heard: [%s]", twist->linear.y);
	ROS_INFO("I heard: [%s]", twist->linear.z);
	ROS_INFO("I heard: [%s]", twist->angular.x);
	ROS_INFO("I heard: [%s]", twist->angular.y);
	ROS_INFO("I heard: [%s]", twist->angular.z);
}

void accelCallback(const geometry_msgs::Accel::ConstPtr& accel)
{
	ROS_INFO("I heard: [%s]", accel->linear.x);
	ROS_INFO("I heard: [%s]", accel->linear.y);
	ROS_INFO("I heard: [%s]", accel->linear.z);
	ROS_INFO("I heard: [%s]", accel->angular.x);
	ROS_INFO("I heard: [%s]", accel->angular.y);
	ROS_INFO("I heard: [%s]", accel->angular.z);
}

void transformCallback(const geometry_msgs::Transform::ConstPtr& transform)
{
	ROS_INFO("I heard: [%s]", transform->translation.x);
	ROS_INFO("I heard: [%s]", transform->translation.y);
	ROS_INFO("I heard: [%s]", transform->translation.z);
	ROS_INFO("I heard: [%s]", transform->rotation.x);
	ROS_INFO("I heard: [%s]", transform->rotation.y);
	ROS_INFO("I heard: [%s]", transform->rotation.z);
	ROS_INFO("I heard: [%s]", transform->rotation.w);
}

void inertiaCallback(const geometry_msgs::Inertia::ConstPtr& inertia)
{
	ROS_INFO("I heard: [%s]", inertia->m);
	ROS_INFO("I heard: [%s]", inertia->com.x);
	ROS_INFO("I heard: [%s]", inertia->com.y);
	ROS_INFO("I heard: [%s]", inertia->com.z);
	ROS_INFO("I heard: [%s]", inertia->ixx);
	ROS_INFO("I heard: [%s]", inertia->ixy);
	ROS_INFO("I heard: [%s]", inertia->ixz);
	ROS_INFO("I heard: [%s]", inertia->iyy);
	ROS_INFO("I heard: [%s]", inertia->iyz);
	ROS_INFO("I heard: [%s]", inertia->izz);
}

void gridcellCallback(const geometry_msgs::GridCellsidCells::ConstPtr& grid_cell)
{
	// an array of cells in a 2D grid
	ROS_INFO("I heard: [%s]", grid_cell->header);
	ROS_INFO("I heard: [%s]", grid_cell->cell_width);
	ROS_INFO("I heard: [%s]", grid_cell->cell_height);
	// geometry_msgs/Point[] cells
	ROS_INFO("I heard: [%s]", grid_cell->cells[0].x);
	ROS_INFO("I heard: [%s]", grid_cell->cells[0].y);
	ROS_INFO("I heard: [%s]", grid_cell->cells[0].z);

}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "geometry_msgs_listener");
  ros::NodeHandle n;
  ros::Subscriber subpoint = n.subscribe("point_", 1000, pointCallback);
  ros::Subscriber subpose = n.subscribe("pose_", 1000, poseCallback);
  ros::Subscriber subtwist = n.subscribe("twist_", 1000, twistCallback);
  ros::Subscriber subaccel = n.subscribe("accel_", 1000, accelCallback);
  ros::Subscriber subtransform = n.subscribe("transform_", 1000, transformCallback);
  ros::Subscriber subinertia = n.subscribe("inertia_", 1000, inertiaCallback);
  ros::Subscriber subgridcell = n.subscribe("gridcell_", 1000, gridcellCallback);
  ros::spin();

  return 0;
}
