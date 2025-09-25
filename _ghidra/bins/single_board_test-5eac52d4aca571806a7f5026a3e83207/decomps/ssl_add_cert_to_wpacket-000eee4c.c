
undefined4 ssl_add_cert_to_wpacket(int param_1,undefined4 param_2,X509 *param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uchar *apuStack_24 [2];
  
  iVar1 = i2d_X509(param_3,(uchar **)0x0);
  if (iVar1 < 0) {
    uVar4 = 0x37a;
    uVar3 = 7;
  }
  else {
    iVar2 = WPACKET_sub_allocate_bytes__(param_2,iVar1,apuStack_24,3);
    if ((iVar2 != 0) && (iVar2 = i2d_X509(param_3,apuStack_24), iVar1 == iVar2)) {
      if ((-1 < *(int *)((*(int **)(param_1 + 4))[0x19] + 0x30) << 0x1c) &&
         (iVar1 = **(int **)(param_1 + 4), iVar1 != 0x10000 && 0x303 < iVar1)) {
        iVar1 = tls_construct_extensions(param_1,param_2,0x1000,param_3,param_4);
        if (iVar1 == 0) {
          return 0;
        }
        return 1;
      }
      return 1;
    }
    uVar4 = 0x380;
    uVar3 = 0x44;
  }
  ossl_statem_fatal(param_1,0x50,0x1ed,uVar3,"ssl/statem/statem_lib.c",uVar4);
  return 0;
}

