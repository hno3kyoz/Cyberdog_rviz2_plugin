#ifndef MISSION_PANEL_H
#define MISSION_PANEL_H


#include <rclcpp/rclcpp.hpp>
#include <rclcpp_action/rclcpp_action.hpp>

#include <ament_index_cpp/get_package_share_directory.hpp>
#include <ament_index_cpp/get_package_prefix.hpp>
#include <rviz_common/panel.hpp>
#include <rviz_common/config.hpp>
// #include <string>

#include <QPainter>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QTimer>
#include <QPixmap>

#include "motion_msgs/action/change_mode.hpp"
#include "motion_msgs/action/change_gait.hpp"

#include "switch.h"
#include "teleop_button.h"

class QLineEdit;
namespace cyberdog_rviz2_control_plugin
{

class MissionPanel: public rviz_common::Panel
{
Q_OBJECT
public:
  MissionPanel( QWidget* parent = 0 );

  virtual void load( const rviz_common::Config& config );
  virtual void save( rviz_common::Config config ) const;
  
protected Q_SLOTS:
  void trigger_service(bool msg, std::string service_name);
  void trigger_action(bool state);

protected:
  bool event(QEvent *event);

private:
  std::shared_ptr<DummyNode> dummy_node_;

  rclcpp_action::Client<motion_msgs::action::ChangeMode>::SharedPtr mode_client_;
  rclcpp_action::Client<motion_msgs::action::ChangeGait>::SharedPtr gait_client_;
  QString icon_on_path_;
  QString icon_off_path_;
  TeleopButton* teleop_button_;
  SwitchButton* switch_button_;
  QPushButton* mode_button_;
  QLabel* label_;
  
};

} //namespace cyberdog_rviz2_control_plugin

#endif // MISSION_PANEL_H