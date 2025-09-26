
/* WARNING: Unknown calling convention */

_Bool init_fpga(void)

{
  uint32_t uVar1;
  char time_stamp [48];
  char tmp1 [2048];
  uint32_t fpga_data;
  
  stop_dhash_work_gen();
  usleep(1000000);
  reset_fpga(0);
  usleep(150000);
  disable_bypass_mode();
  enable_sync_header();
  uVar1 = _get_dhash_acc_control();
  _set_dhash_acc_control(uVar1 & 0xffff3f1f | 0x8080);
  if ((Local_Config_Information->Test_Info).Test_Method.Midstate_Number == 4) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Set midstate as %d\n","init_fpga",4);
    snprintf(tmp1,0x800,"Set midstate as %d",4);
    log_to_file(tmp1,time_stamp);
    set_dhash_midstate(4);
  }
  else if ((Local_Config_Information->Test_Info).Test_Method.Midstate_Number == 8) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Set midstate as %d\n","init_fpga",8);
    snprintf(tmp1,0x800,"Set midstate as %d",8);
    log_to_file(tmp1,time_stamp);
    set_dhash_midstate(8);
  }
  else if ((Local_Config_Information->Test_Info).Test_Method.Midstate_Number == 0x10) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Set midstate as %d\n","init_fpga",0x10);
    snprintf(tmp1,0x800,"Set midstate as %d",0x10);
    log_to_file(tmp1,time_stamp);
    set_dhash_midstate(0x10);
  }
  else {
    if ((Local_Config_Information->Test_Info).Test_Method.Midstate_Number != 1) {
      lcd_clear_result();
      lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
      lcd_show(1,"Midstate Num");
      lcd_show(2,"error");
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: Midstate Num error !!!\n","init_fpga");
      builtin_strncpy(tmp1,"Midstate Num error !",0x14);
      tmp1[0x14] = '!';
      tmp1[0x15] = '!';
      tmp1[0x16] = '\0';
      log_to_file(tmp1,time_stamp);
      return false;
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Set midstate as %d\n","init_fpga",1);
    snprintf(tmp1,0x800,"Set midstate as %d",1);
    log_to_file(tmp1,time_stamp);
    set_dhash_midstate(1);
  }
  if ((Local_Config_Information->Test_Info).Test_Method.Hardware_Pattern != false) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Set midstate as %d\n","init_fpga",1);
    snprintf(tmp1,0x800,"Set midstate as %d",1);
    log_to_file(tmp1,time_stamp);
    set_dhash_midstate(1);
  }
  if ((Local_Config_Information->Test_Info).Test_Method.Autogen_Pattern != false) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Set auto_gen pattern\n","init_fpga");
    builtin_strncpy(tmp1,"Set auto_gen pattern",0x14);
    tmp1._20_2_ = (ushort)(byte)tmp1[0x15] << 8;
    log_to_file(tmp1,time_stamp);
    disable_dhash_midstate_autogen();
    set_dhash_midstate((Local_Config_Information->Test_Info).Test_Method.Midstate_Number);
  }
  usleep(50000);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  uVar1 = _get_dhash_acc_control();
  printf("%s: dhash acc ctrl is %08x\n","init_fpga",uVar1);
  uVar1 = _get_dhash_acc_control();
  snprintf(tmp1,0x800,"dhash acc ctrl is %08x",uVar1);
  log_to_file(tmp1,time_stamp);
  return true;
}

