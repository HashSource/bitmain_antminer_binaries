
undefined4 tls_process_end_of_early_data(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_2 + 4) != 0) {
    ossl_statem_fatal(param_1,0x32,0x219,0x9f,"ssl/statem/statem_srvr.c",0x10b6);
    return 0;
  }
  if (*(int *)(param_1 + 0x68) - 10U < 2) {
    iVar1 = RECORD_LAYER_processed_read_pending(param_1 + 0x650);
    if (iVar1 != 0) {
      ossl_statem_fatal(param_1,10,0x219,0xb6,"ssl/statem/statem_srvr.c",0x10c8);
      return 0;
    }
    *(undefined4 *)(param_1 + 0x68) = 0xc;
    iVar1 = (**(code **)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x10))(param_1,0xa1);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = 3;
    }
    return uVar2;
  }
  ossl_statem_fatal(param_1,0x50,0x219,0x44,"ssl/statem/statem_srvr.c",0x10bd);
  return 0;
}

