
/* WARNING: Unknown calling convention */

void dsPIC33EP16GS202_test(uchar which_chain,uchar which_i2c)

{
  uint which_chain_00;
  
  which_chain_00 = (uint)which_chain;
  printf("\n--- %s\n",DAT_000245e0);
  power_on();
  usleep(2000000);
  power_set_voltage('\x14');
  usleep(500000);
  reset_dsPIC33EP16GS202_pic(which_chain_00,which_i2c);
  usleep(500000);
  jump_from_loader_to_app_dsPIC33EP16GS202(which_chain_00,which_i2c);
  usleep(500000);
  enable_dsPIC33EP16GS202_dc_dc(which_chain_00,which_i2c,'\x01');
  usleep(500000);
  do {
    heart_beat_dsPIC33EP16GS202(which_chain_00,which_i2c);
    enable_dsPIC33EP16GS202_clamping_voltage(which_chain_00,which_i2c,'\x01');
    sleep(0x32);
    heart_beat_dsPIC33EP16GS202(which_chain_00,which_i2c);
    enable_dsPIC33EP16GS202_clamping_voltage(which_chain_00,which_i2c,'\0');
    sleep(0x32);
  } while( true );
}

