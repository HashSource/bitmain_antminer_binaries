
undefined4 ssl_add_clienthello_use_srtp_ext(int param_1,undefined *param_2,int *param_3,int param_4)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  _STACK *p_Var4;
  int iVar5;
  undefined *puVar6;
  
  if (param_1 == 0) {
    p_Var4 = (_STACK *)0x0;
  }
  else {
    p_Var4 = *(_STACK **)(param_1 + 0x17c);
    if ((p_Var4 == (_STACK *)0x0) && (*(int *)(param_1 + 0xe4) != 0)) {
      p_Var4 = *(_STACK **)(*(int *)(param_1 + 0xe4) + 0x1b4);
      iVar1 = sk_num(p_Var4);
      goto joined_r0x00079656;
    }
  }
  iVar1 = sk_num(p_Var4);
joined_r0x00079656:
  if (param_2 == (undefined *)0x0) {
    iVar5 = (iVar1 + 1) * 2;
  }
  else {
    if (iVar1 == 0) {
      ERR_put_error(0x14,0x133,0x162,DAT_00079710,0xfe);
      return 1;
    }
    iVar5 = (iVar1 + 1) * 2;
    if (param_4 <= iVar5) {
      ERR_put_error(0x14,0x133,0x16b,DAT_00079710,0x104);
      return 1;
    }
    puVar6 = param_2 + 2;
    param_2[1] = (char)(iVar1 << 1);
    *param_2 = (char)((uint)(iVar1 << 1) >> 8);
    if (0 < iVar1) {
      param_2 = param_2 + 4;
      iVar3 = 0;
      do {
        pvVar2 = sk_value(p_Var4,iVar3);
        iVar3 = iVar3 + 1;
        param_2[-2] = (char)((uint)*(undefined4 *)((int)pvVar2 + 4) >> 8);
        param_2[-1] = (char)*(undefined4 *)((int)pvVar2 + 4);
        param_2 = param_2 + 2;
      } while (iVar3 != iVar1);
      puVar6 = puVar6 + iVar3 * 2;
    }
    *puVar6 = 0;
  }
  *param_3 = iVar5 + 1;
  return 0;
}

