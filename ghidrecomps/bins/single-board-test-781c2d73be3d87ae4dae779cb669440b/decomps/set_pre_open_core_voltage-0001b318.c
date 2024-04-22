
/* WARNING: Unknown calling convention */

int set_pre_open_core_voltage(uchar which_chain,uchar which_iic)

{
  undefined4 uVar1;
  byte N;
  
  uVar1 = DAT_0001b3f8;
  N = power_calculate_voltage(Conf.pre_open_core_voltage);
  power_set_voltage(N);
  printf("\n--- %s: Conf.pre_open_core_voltage = %d, N = %d\n",uVar1,Conf.pre_open_core_voltage,
         (uint)N);
  write(power_control_fd,&DAT_0002cbd8,1);
  usleep(500000);
  printf("%s line %d: Enter hash board power on flow:\n",uVar1,0x1fb);
  write_axi_fpga(0xd,0xffff);
  usleep(300000);
  printf("%s line %d: Reset hash board done\n",uVar1,0x1ff);
  enable_dsPIC33EP16GS202_dc_dc((uint)which_chain,which_iic,'\x01');
  usleep(500000);
  printf("%s line %d: dc dc enable done\n",uVar1,0x203);
  write_axi_fpga(0xd,0);
  usleep(300000);
  printf("%s line %d: release hash board reset done.\n",uVar1,0x207);
  return 0;
}

