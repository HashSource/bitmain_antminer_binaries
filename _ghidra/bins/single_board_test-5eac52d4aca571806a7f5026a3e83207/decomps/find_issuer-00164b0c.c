
X509 * find_issuer(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  X509 *b;
  X509 *a;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 local_2c;
  
  iVar4 = 0;
  local_2c = (X509 *)0x0;
  iVar1 = OPENSSL_sk_num(param_2);
  if (0 < iVar1) {
    do {
      b = (X509 *)OPENSSL_sk_value(param_2,iVar4);
      iVar1 = (**(code **)(param_1 + 0x24))(param_1,param_3,b);
      if (iVar1 != 0) {
        if ((-1 < *(int *)(param_3 + 0x80) << 0x1a) ||
           (iVar1 = OPENSSL_sk_num(*(undefined4 *)(param_1 + 0x50)), iVar1 != 1)) {
          uVar3 = *(undefined4 *)(param_1 + 0x50);
          iVar1 = OPENSSL_sk_num(uVar3);
          if (0 < iVar1) {
            iVar5 = 0;
            do {
              a = (X509 *)OPENSSL_sk_value(uVar3,iVar5);
              iVar5 = iVar5 + 1;
              iVar2 = X509_cmp(a,b);
              if (iVar2 == 0) goto LAB_00164b84;
            } while (iVar1 != iVar5);
          }
        }
        iVar1 = x509_check_cert_time(param_1,b,0xffffffff);
        local_2c = b;
        if (iVar1 != 0) {
          return b;
        }
      }
LAB_00164b84:
      iVar4 = iVar4 + 1;
      iVar1 = OPENSSL_sk_num(param_2);
    } while (iVar4 < iVar1);
  }
  return local_2c;
}

