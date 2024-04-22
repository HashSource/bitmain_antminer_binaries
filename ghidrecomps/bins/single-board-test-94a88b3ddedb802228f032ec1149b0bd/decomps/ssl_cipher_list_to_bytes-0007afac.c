
int ssl_cipher_list_to_bytes(int param_1,_STACK *param_2,int param_3,code *param_4)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  code *pcVar8;
  
  iVar5 = *(int *)(param_1 + 0x98);
  iVar7 = *(int *)(param_1 + 400);
  pcVar8 = param_4;
  ssl_set_client_disabled();
  if (param_2 == (_STACK *)0x0) {
    return 0;
  }
  if (param_4 == (code *)0x0) {
    param_4 = *(code **)(*(int *)(param_1 + 8) + 0x4c);
  }
  iVar3 = 0;
  iVar6 = param_3;
  while( true ) {
    iVar1 = sk_num(param_2);
    iVar4 = iVar3 + 1;
    if (iVar1 <= iVar3) break;
    pvVar2 = sk_value(param_2,iVar3);
    iVar3 = iVar4;
    if (((*(uint *)(iVar5 + 0x18) & *(uint *)((int)pvVar2 + 0x1c)) == 0) &&
       ((*(uint *)(iVar5 + 8) & *(uint *)((int)pvVar2 + 0xc)) == 0)) {
      if ((*(uint *)(iVar5 + 0xc) & *(uint *)((int)pvVar2 + 0x10)) == 0) {
        iVar1 = (*param_4)(pvVar2,iVar6,*(uint *)((int)pvVar2 + 0x10),*(uint *)(iVar5 + 0xc),pcVar8)
        ;
        iVar6 = iVar6 + iVar1;
      }
    }
  }
  if (iVar6 != param_3) {
    if (iVar7 == 0) {
      iVar5 = (*param_4)(DAT_0007b054,iVar6);
      iVar7 = *(int *)(param_1 + 0x104);
      iVar6 = iVar6 + iVar5;
    }
    else {
      iVar7 = *(int *)(param_1 + 0x104);
    }
    if (iVar7 << 0x18 < 0) {
      iVar5 = (*param_4)(DAT_0007b058,iVar6);
      return (iVar6 + iVar5) - param_3;
    }
  }
  return iVar6 - param_3;
}

