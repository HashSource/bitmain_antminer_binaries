
int cert_crl(int param_1,X509_CRL *param_2,X509 *param_3)

{
  int iVar1;
  X509_REVOKED *local_14 [2];
  
  if (((*(uint *)(*(int *)(param_1 + 0x14) + 0xc) & 0x10) == 0) && (param_2->flags << 0x16 < 0)) {
    *(undefined4 *)(param_1 + 100) = 0x24;
    iVar1 = (**(code **)(param_1 + 0x20))(0,param_1);
    if (iVar1 == 0) {
      return 0;
    }
  }
  iVar1 = X509_CRL_get0_by_cert(param_2,local_14,param_3);
  if (iVar1 == 0) {
    iVar1 = 1;
  }
  else if (local_14[0]->reason == 8) {
    iVar1 = 2;
  }
  else {
    *(undefined4 *)(param_1 + 100) = 0x17;
    iVar1 = (**(code **)(param_1 + 0x20))(0,param_1);
    if (iVar1 != 0) {
      iVar1 = 1;
    }
  }
  return iVar1;
}

