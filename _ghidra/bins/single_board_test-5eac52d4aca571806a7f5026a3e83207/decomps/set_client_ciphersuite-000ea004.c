
undefined4 set_client_ciphersuite(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  
  iVar1 = ssl_get_cipher_by_char(param_1,param_2,0);
  if (iVar1 == 0) {
    ossl_statem_fatal(param_1,0x2f,0x21c,0xf8,"ssl/statem/statem_clnt.c",0x537);
    return 0;
  }
  iVar2 = ssl_cipher_disabled(param_1,iVar1,0x10003,1);
  if (iVar2 == 0) {
    uVar3 = ssl_get_ciphers_by_id(param_1);
    iVar2 = OPENSSL_sk_find(uVar3,iVar1);
    if (iVar2 < 0) {
      uVar3 = 0x549;
    }
    else {
      piVar5 = *(int **)(param_1 + 4);
      uVar6 = *(uint *)(piVar5[0x19] + 0x30) & 8;
      if ((((uVar6 != 0) || (*piVar5 == 0x10000 || *piVar5 < 0x304)) ||
          (iVar2 = *(int *)(*(int *)(param_1 + 0x7c) + 0x210), iVar2 == 0)) ||
         (*(int *)(iVar2 + 0xc) == *(int *)(iVar1 + 0xc))) {
        iVar2 = *(int *)(param_1 + 0x474);
        if (*(int *)(iVar2 + 0x1b8) != 0) {
          *(undefined4 *)(iVar2 + 0x1bc) = *(undefined4 *)(*(int *)(iVar2 + 0x1b8) + 0xc);
        }
        if ((*(int *)(param_1 + 0x8c) != 0) && (*(int *)(iVar2 + 0x1bc) != *(int *)(iVar1 + 0xc))) {
          if ((uVar6 != 0) || (*piVar5 == 0x10000 || *piVar5 < 0x304)) {
            ossl_statem_fatal(param_1,0x2f,0x21c,0xc5,"ssl/statem/statem_clnt.c",0x56f);
            return 0;
          }
          iVar2 = ssl_md(*(undefined4 *)(iVar1 + 0x34));
          iVar4 = ssl_md(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x474) + 0x1b8) + 0x34));
          if (iVar2 != iVar4) {
            ossl_statem_fatal(param_1,0x2f,0x21c,0xda,"ssl/statem/statem_clnt.c",0x566);
            return 0;
          }
        }
        *(int *)(*(int *)(param_1 + 0x7c) + 0x210) = iVar1;
        return 1;
      }
      uVar3 = 0x551;
    }
    ossl_statem_fatal(param_1,0x2f,0x21c,0x105,"ssl/statem/statem_clnt.c",uVar3);
    return 0;
  }
  ossl_statem_fatal(param_1,0x2f,0x21c,0x105,"ssl/statem/statem_clnt.c",0x540);
  return 0;
}

