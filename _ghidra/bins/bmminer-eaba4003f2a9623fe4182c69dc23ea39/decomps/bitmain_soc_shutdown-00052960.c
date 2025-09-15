
void bitmain_soc_shutdown(thr_info *thr)

{
  uint uVar1;
  thr_info *thr_local;
  uint ret;
  
  thr_info_cancel(check_system_work_id);
  thr_info_cancel(read_nonce_reg_id);
  thr_info_cancel(read_temp_id);
  thr_info_cancel(pic_heart_beat);
  uVar1 = get_BC_write_command();
  set_BC_write_command(uVar1 & 0xffbfffff);
  uVar1 = get_dhash_acc_control();
  set_dhash_acc_control(uVar1 & 0xffffffbf);
  return;
}

