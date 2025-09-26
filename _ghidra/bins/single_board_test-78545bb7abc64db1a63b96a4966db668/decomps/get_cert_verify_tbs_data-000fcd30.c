
bool get_cert_verify_tbs_data(int param_1,void *param_2,undefined4 *param_3,long *param_4)

{
  long lVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  undefined4 uVar7;
  int local_1c [2];
  
  if ((-1 < *(int *)((*(int **)(param_1 + 4))[0x19] + 0x30) << 0x1c) &&
     (iVar4 = **(int **)(param_1 + 4), iVar4 != 0x10000 && 0x303 < iVar4)) {
    memset(param_2,0x20,0x40);
    if (*(int *)(param_1 + 0x40) - 0x27U < 2) {
      pcVar6 = "TLS 1.3, server CertificateVerify";
    }
    else {
      pcVar6 = "TLS 1.3, client CertificateVerify";
    }
    uVar2 = *(undefined4 *)(pcVar6 + 4);
    uVar3 = *(undefined4 *)(pcVar6 + 8);
    uVar5 = *(undefined4 *)(pcVar6 + 0xc);
    *(undefined4 *)((int)param_2 + 0x40) = *(undefined4 *)pcVar6;
    *(undefined4 *)((int)param_2 + 0x44) = uVar2;
    *(undefined4 *)((int)param_2 + 0x48) = uVar3;
    *(undefined4 *)((int)param_2 + 0x4c) = uVar5;
    uVar2 = *(undefined4 *)(pcVar6 + 0x14);
    uVar3 = *(undefined4 *)(pcVar6 + 0x18);
    uVar5 = *(undefined4 *)(pcVar6 + 0x1c);
    uVar7 = *(undefined4 *)(pcVar6 + 0x20);
    *(undefined4 *)((int)param_2 + 0x50) = *(undefined4 *)(pcVar6 + 0x10);
    *(undefined4 *)((int)param_2 + 0x54) = uVar2;
    *(undefined4 *)((int)param_2 + 0x58) = uVar3;
    *(undefined4 *)((int)param_2 + 0x5c) = uVar5;
    *(short *)((int)param_2 + 0x60) = (short)uVar7;
    if (*(int *)(param_1 + 0x40) == 0x1d || *(int *)(param_1 + 0x40) == 0x27) {
      memcpy((void *)((int)param_2 + 0x62),(void *)(param_1 + 0x408),*(size_t *)(param_1 + 0x448));
      local_1c[0] = *(int *)(param_1 + 0x448);
    }
    else {
      iVar4 = ssl_handshake_hash(param_1,(int)param_2 + 0x62,0x40,local_1c);
      if (iVar4 == 0) {
        return false;
      }
    }
    *param_3 = param_2;
    *param_4 = local_1c[0] + 0x62;
    return true;
  }
  lVar1 = BIO_ctrl(*(BIO **)(*(int *)(param_1 + 0x7c) + 0xd4),3,0,param_3);
  if (0 < lVar1) {
    *param_4 = lVar1;
  }
  else {
    ossl_statem_fatal(param_1,0x50,0x24c,0x44,"ssl/statem/statem_lib.c",0xdd);
  }
  return 0 < lVar1;
}

