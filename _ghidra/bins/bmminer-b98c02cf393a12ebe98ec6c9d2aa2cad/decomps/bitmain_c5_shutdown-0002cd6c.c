
void bitmain_c5_shutdown(void)

{
  uint uVar1;
  undefined4 extraout_r2;
  undefined4 in_r3;
  undefined8 uVar2;
  
  thr_info_cancel(check_system_work_id);
  thr_info_cancel(read_nonce_reg_id);
  thr_info_cancel(read_temp_id);
  thr_info_cancel(pic_heart_beat);
  uVar1 = get_BC_write_command();
  set_BC_write_command(uVar1 & 0xffbfffff);
  uVar2 = get_dhash_acc_control();
  set_dhash_acc_control((uint)uVar2 & 0xffffffbf,(int)((ulonglong)uVar2 >> 0x20),extraout_r2,in_r3);
  return;
}

