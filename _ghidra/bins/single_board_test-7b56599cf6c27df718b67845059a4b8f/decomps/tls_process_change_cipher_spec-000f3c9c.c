
undefined4 tls_process_change_cipher_spec(int *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_2 + 4);
  if ((*(uint *)(*(int *)(param_1[1] + 100) + 0x30) & 8) == 0) {
    if (iVar2 != 0) {
      ossl_statem_fatal(param_1,0x32,0x16b,0x67,"ssl/statem/statem_lib.c",0x2d4);
      return 0;
    }
  }
  else if (*param_1 == 0x100) {
    if (iVar2 != 2) goto LAB_000f3d0a;
  }
  else if (iVar2 != 0) {
LAB_000f3d0a:
    ossl_statem_fatal(param_1,0x32,0x16b,0x67,"ssl/statem/statem_lib.c",0x2cd);
    return 0;
  }
  if (*(int *)(param_1[0x1f] + 0x210) == 0) {
    ossl_statem_fatal(param_1,10,0x16b,0x85,"ssl/statem/statem_lib.c",0x2dc);
    uVar1 = 0;
  }
  else {
    *(undefined4 *)(param_1[0x1f] + 0xdc) = 1;
    iVar2 = ssl3_do_change_cipher_spec(param_1);
    if (iVar2 == 0) {
      ossl_statem_fatal(param_1,0x50,0x16b,0x44,"ssl/statem/statem_lib.c",0x2e3);
      return 0;
    }
    if ((*(int *)(*(int *)(param_1[1] + 100) + 0x30) << 0x1c < 0) &&
       (dtls1_reset_seq_numbers(param_1,1), *param_1 == 0x100)) {
      uVar1 = 3;
      *(short *)(param_1[0x20] + 0x10c) = *(short *)(param_1[0x20] + 0x10c) + 1;
    }
    else {
      uVar1 = 3;
    }
  }
  return uVar1;
}

