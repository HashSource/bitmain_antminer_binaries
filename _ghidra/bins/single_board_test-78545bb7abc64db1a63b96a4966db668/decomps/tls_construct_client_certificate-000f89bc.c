
int tls_construct_client_certificate(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if ((-1 < *(int *)((*(int **)(param_1 + 4))[0x19] + 0x30) << 0x1c) &&
     (iVar2 = **(int **)(param_1 + 4), iVar2 != 0x10000 && 0x303 < iVar2)) {
    if (*(int *)(param_1 + 0x5fc) == 0) {
      iVar2 = WPACKET_put_bytes__(param_2,1,0,0,1);
      if (iVar2 == 0) {
        uVar1 = 0xde3;
        goto LAB_000f8a84;
      }
    }
    else {
      iVar2 = WPACKET_sub_memcpy__
                        (param_2,*(int *)(param_1 + 0x5fc),*(undefined4 *)(param_1 + 0x600),1);
      if (iVar2 == 0) {
        uVar1 = 0xde8;
LAB_000f8a84:
        ossl_statem_fatal(param_1,0x50,0x1e4,0x44,"ssl/statem/statem_clnt.c",uVar1);
        return 0;
      }
    }
  }
  if (*(int *)(*(int *)(param_1 + 0x7c) + 0x218) == 2) {
    uVar1 = 0;
  }
  else {
    uVar1 = **(undefined4 **)(param_1 + 0x404);
  }
  iVar2 = ssl3_output_cert_chain(param_1,param_2,uVar1);
  if (iVar2 != 0) {
    iVar2 = (*(int **)(param_1 + 4))[0x19];
    if ((((*(int *)(iVar2 + 0x30) << 0x1c < 0) ||
         (iVar3 = **(int **)(param_1 + 4), iVar3 == 0x10000 || iVar3 < 0x304)) ||
        ((*(int *)(*(int *)(param_1 + 0x7c) + 0x180) != 0 &&
         (*(int *)(*(int *)(param_1 + 0x7c) + 0x204) != 0)))) ||
       (iVar2 = (**(code **)(iVar2 + 0x10))(param_1,0x92), iVar2 != 0)) {
      iVar2 = 1;
    }
    else {
      ossl_statem_fatal(param_1,0xffffffff,0x1e4,0x6d,"ssl/statem/statem_clnt.c",0xdfc);
      iVar2 = 0;
    }
  }
  return iVar2;
}

