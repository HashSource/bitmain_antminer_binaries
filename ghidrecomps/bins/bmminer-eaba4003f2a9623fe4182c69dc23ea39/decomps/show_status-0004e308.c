
void show_status(int if_quit)

{
  uint uVar1;
  char *pcVar2;
  int if_quit_local;
  char tmp42 [2048];
  uint buf [2];
  char *buf_hex;
  int i;
  uint *l_job_start_address;
  
  l_job_start_address = (uint *)0x0;
  buf[0] = 0;
  buf[1] = 0;
  get_work_nonce2(buf);
  uVar1 = get_dhash_acc_control();
  set_dhash_acc_control(uVar1 & 0xffffffbf);
  while (uVar1 = get_dhash_acc_control(), (uVar1 & 0x40) != 0) {
    cgsleep_ms(1);
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"%s: run bit is 1 after set it to 0","show_status");
      _applog(7,tmp42,false);
    }
  }
  pcVar2 = bin2hex((uchar *)dev->current_job_start_address,c_coinbase_padding);
  free(pcVar2);
  for (i = 0; (uint)i < c_merkles_num; i = i + 1) {
    pcVar2 = bin2hex((uchar *)((int)dev->current_job_start_address + i * 0x20 + c_coinbase_padding),
                     0x20);
    free(pcVar2);
  }
  if (dev->current_job_start_address == job_start_address_1) {
    l_job_start_address = job_start_address_2;
  }
  else if (dev->current_job_start_address == job_start_address_2) {
    l_job_start_address = job_start_address_1;
  }
  pcVar2 = bin2hex((uchar *)l_job_start_address,l_coinbase_padding);
  free(pcVar2);
  for (i = 0; (uint)i < l_merkles_num; i = i + 1) {
    pcVar2 = bin2hex((uchar *)((int)l_job_start_address + i * 0x20 + l_coinbase_padding),0x20);
    free(pcVar2);
  }
  if (if_quit != 0) {
    builtin_strncpy(tmp42,"HW is more than 5!!",0x14);
    _applog(3,tmp42,true);
    _quit(1);
  }
  return;
}

