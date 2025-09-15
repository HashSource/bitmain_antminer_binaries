
int bring_up_chain(int chain,_Bool poweron)

{
  FILE *__stream;
  int iVar1;
  _Bool poweron_local;
  int chain_local;
  FILE *pFile;
  
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: \n\nbring up chain %d\n","driver-btm-soc.c",0x185a,
              "bring_up_chain",chain);
    }
    fclose(__stream);
  }
  if (poweron) {
    power_on_chain(chain);
  }
  else {
    hash_board_reset(chain);
  }
  iVar1 = check_asic_num(chain);
  if (iVar1 < 0) {
    iVar1 = -1;
  }
  else {
    set_addr_one_chain((uint8_t)chain);
    iVar1 = set_freq_by_chain(init_freq,chain);
    if (iVar1 < 0) {
      iVar1 = -1;
    }
    else {
      open_core_BM1393_pre_open(chain,'\r','\x01');
      calibration_sensor_offset(0x98,chain);
      iVar1 = 0;
    }
  }
  return iVar1;
}

