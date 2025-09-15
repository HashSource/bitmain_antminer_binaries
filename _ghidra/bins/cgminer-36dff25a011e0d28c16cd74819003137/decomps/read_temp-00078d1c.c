
void read_temp(uchar device,uint reg,uchar data,uchar write,uchar chip_addr,int chain)

{
  uint reg_local;
  uchar write_local;
  uchar data_local;
  uchar device_local;
  general_i2c_command_t i2c_cmd;
  
  memset(&i2c_cmd,0,4);
  i2c_cmd.v._0_2_ = CONCAT11((char)reg,data);
  i2c_cmd.v = CONCAT13(i2c_cmd.v._3_1_,CONCAT12(write,i2c_cmd.v._0_2_)) & 0xff01ffff;
  i2c_cmd.v._0_3_ = CONCAT12(i2c_cmd.v._2_1_ | device & 0xfe,i2c_cmd.v._0_2_);
  i2c_cmd.v = CONCAT13(i2c_cmd.v._3_1_,i2c_cmd.v._0_3_) & 0x39ffffff | 0x1000000;
  send_set_config_command(chain,'\0',chip_addr,'\x1c',i2c_cmd.v);
  return;
}

