
undefined4 check_policy(int param_1)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int iVar5;
  
  if (*(int *)(param_1 + 0x7c) == 0) {
    iVar1 = X509_policy_check((X509_POLICY_TREE **)(param_1 + 0x58),(int *)(param_1 + 0x5c),
                              *(stack_st_X509 **)(param_1 + 0x54),
                              *(stack_st_ASN1_OBJECT **)(*(int *)(param_1 + 0x14) + 0x1c),
                              *(uint *)(*(int *)(param_1 + 0x14) + 0xc));
    if (iVar1 == 0) {
      ERR_put_error(0xb,0x91,0x41,DAT_000c0c7c,0x64b);
      return 0;
    }
    if (iVar1 == -1) {
      iVar1 = 1;
      while( true ) {
        iVar2 = sk_num(*(_STACK **)(param_1 + 0x54));
        iVar5 = iVar1 + 1;
        if (iVar2 <= iVar1) break;
        pvVar3 = sk_value(*(_STACK **)(param_1 + 0x54),iVar1);
        iVar1 = iVar5;
        if (*(int *)((int)pvVar3 + 0x28) << 0x14 < 0) {
          *(void **)(param_1 + 0x68) = pvVar3;
          *(undefined4 *)(param_1 + 100) = 0x2a;
          iVar2 = (**(code **)(param_1 + 0x20))(0,param_1);
          if (iVar2 == 0) {
            return 0;
          }
        }
      }
    }
    else {
      if (iVar1 == -2) {
        *(undefined4 *)(param_1 + 0x68) = 0;
        *(undefined4 *)(param_1 + 100) = 0x2b;
        uVar4 = (**(code **)(param_1 + 0x20))(0,param_1);
        return uVar4;
      }
      if (*(int *)(*(int *)(param_1 + 0x14) + 0xc) << 0x14 < 0) {
        *(undefined4 *)(param_1 + 0x68) = 0;
        *(undefined4 *)(param_1 + 100) = 0;
        iVar1 = (**(code **)(param_1 + 0x20))(2,param_1);
        if (iVar1 == 0) {
          return 0;
        }
        return 1;
      }
    }
  }
  return 1;
}

