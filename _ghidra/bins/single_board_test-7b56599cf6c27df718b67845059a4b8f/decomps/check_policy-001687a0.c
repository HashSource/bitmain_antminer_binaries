
undefined4 check_policy(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (*(int *)(param_1 + 0x78) == 0) {
    if ((*(int *)(param_1 + 0x84) == 0) ||
       (iVar1 = OPENSSL_sk_push(*(undefined4 *)(param_1 + 0x50)), iVar1 != 0)) {
      iVar1 = X509_policy_check((X509_POLICY_TREE **)(param_1 + 0x54),(int *)(param_1 + 0x58),
                                *(stack_st_X509 **)(param_1 + 0x50),
                                *(stack_st_ASN1_OBJECT **)(*(int *)(param_1 + 0x10) + 0x20),
                                *(uint *)(*(int *)(param_1 + 0x10) + 0xc));
      if (*(int *)(param_1 + 0x84) != 0) {
        OPENSSL_sk_pop(*(undefined4 *)(param_1 + 0x50));
      }
      if (iVar1 != 0) {
        if (iVar1 == -1) {
          for (iVar1 = 1; iVar2 = OPENSSL_sk_num(*(undefined4 *)(param_1 + 0x50)), iVar1 < iVar2;
              iVar1 = iVar1 + 1) {
            iVar2 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x50),iVar1);
            if (*(int *)(iVar2 + 0x80) << 0x14 < 0) {
              *(int *)(param_1 + 100) = iVar2;
              *(int *)(param_1 + 0x5c) = iVar1;
              *(undefined4 *)(param_1 + 0x60) = 0x2a;
              iVar2 = (**(code **)(param_1 + 0x1c))(0,param_1);
              if (iVar2 == 0) {
                return 0;
              }
            }
          }
        }
        else {
          if (iVar1 == -2) {
            *(undefined4 *)(param_1 + 0x60) = 0x2b;
            *(undefined4 *)(param_1 + 100) = 0;
                    /* WARNING: Could not recover jumptable at 0x0016889e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            uVar3 = (**(code **)(param_1 + 0x1c))(0,param_1);
            return uVar3;
          }
          if (iVar1 != 1) {
            ERR_put_error(0xb,0x91,0x44,"crypto/x509/x509_vfy.c",0x688);
            return 0;
          }
          if (*(int *)(*(int *)(param_1 + 0x10) + 0xc) << 0x14 < 0) {
            *(undefined4 *)(param_1 + 100) = 0;
            iVar1 = (**(code **)(param_1 + 0x1c))(2,param_1);
            if (iVar1 == 0) {
              return 0;
            }
            return 1;
          }
        }
        goto LAB_001687a8;
      }
      iVar1 = 0x66e;
    }
    else {
      iVar1 = 0x664;
    }
    uVar3 = 0;
    ERR_put_error(0xb,0x91,0x41,"crypto/x509/x509_vfy.c",iVar1);
    *(undefined4 *)(param_1 + 0x60) = 0x11;
  }
  else {
LAB_001687a8:
    uVar3 = 1;
  }
  return uVar3;
}

