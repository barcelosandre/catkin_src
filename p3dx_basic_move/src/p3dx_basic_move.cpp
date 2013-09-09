//######################## P3DX BASIC MOVE.cpp ##########################################
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <geometry_msgs/Twist.h>
double max_speed = 0.100; // m/second
double max_turn = 60.0*M_PI/180.0; // rad/second

geometry_msgs::Twist cmdvel;
ros::Publisher pub_;

void moveRobot(float speed, float turn){
	cmdvel.linear.x = speed * max_speed;
	cmdvel.angular.z = turn * max_turn;
	pub_.publish(cmdvel);
}
void stopRobot()
{
	moveRobot(0, 0);
}

int main(int argc, char** argv)
{
	ros::init(argc,argv, "p3dx_basic_move");

	ros::NodeHandle n_;

	pub_ = n_.advertise<geometry_msgs::Twist>("/cmd_vel",0);

	printf("Inicindo...\n");

	//while (n_.ok()){
	while (ros::ok() && n_.ok()){
		printf("Comando... \n");
		
		moveRobot(0, 1);
		sleep(3.2);
		moveRobot(0, 0);
		sleep(3);

		moveRobot(3, 0);
		sleep(5);
		moveRobot(0, 0);
		sleep(3);
	}

	printf("Saindo... \n");
	moveRobot(0, 0);
	ros::spin();

	return(0);
}
//###################################################################################
