
int tls_process_key_update(int param_1,undefined4 *param_2)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = RECORD_LAYER_processed_read_pending(param_1 + 0x650);
  if (iVar2 != 0) {
    ossl_statem_fatal(param_1,10,0x206,0xb6,"ssl/statem/statem_lib.c",0x279);
    return 0;
  }
  if (param_2[1] != 0) {
    iVar2 = param_2[1] + -1;
    bVar1 = *(byte *)*param_2;
    *param_2 = (byte *)*param_2 + 1;
    param_2[1] = iVar2;
    if (iVar2 == 0) {
      if (bVar1 < 2) {
        if (bVar1 == 1) {
          *(undefined4 *)(param_1 + 0x5f0) = 0;
        }
        iVar2 = tls13_update_key(param_1,0);
        if (iVar2 != 0) {
          iVar2 = 1;
        }
        return iVar2;
      }
      ossl_statem_fatal(param_1,0x2f,0x206,0x7a,"ssl/statem/statem_lib.c",0x28b);
      return 0;
    }
  }
  ossl_statem_fatal(param_1,0x32,0x206,0x7a,"ssl/statem/statem_lib.c",0x280);
  return 0;
}

