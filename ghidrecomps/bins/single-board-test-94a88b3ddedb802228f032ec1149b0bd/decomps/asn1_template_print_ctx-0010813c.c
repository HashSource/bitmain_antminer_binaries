
uint asn1_template_print_ctx(BIO *param_1,_STACK **param_2,int param_3,uint *param_4,uint *param_5)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  _STACK *p_Var7;
  void *local_2c [2];
  
  uVar1 = *param_4;
  uVar5 = *param_5;
  if ((uVar5 & 0x80) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined4 *)(param_4[4] + 0x18);
  }
  if ((int)(uVar5 << 0x19) < 0) {
    uVar4 = uVar1 & 6;
    if (uVar4 == 0) {
LAB_0010820e:
      uVar1 = asn1_item_print_ctx(param_1,param_2,param_3,param_4[4],uVar4,uVar3,0,param_5);
      return uVar1;
    }
  }
  else {
    uVar4 = param_4[3];
    if ((uVar1 & 6) == 0) goto LAB_0010820e;
    if (uVar4 != 0) {
      if ((int)(uVar5 << 0x1d) < 0) {
        uVar3 = DAT_00108270;
        if ((uVar1 & 2) != 0) {
          uVar3 = DAT_0010826c;
        }
        iVar6 = BIO_printf(param_1,DAT_00108274,param_3,DAT_00108278,uVar3,uVar4);
      }
      else {
        iVar6 = BIO_printf(param_1,DAT_0010827c,param_3,DAT_00108278,uVar4);
      }
      if (iVar6 < 1) {
        return 0;
      }
    }
  }
  iVar6 = 0;
  p_Var7 = *param_2;
  while( true ) {
    iVar2 = sk_num(p_Var7);
    if (iVar2 <= iVar6) {
      if ((iVar6 == 0) &&
         (iVar6 = BIO_printf(param_1,DAT_00108284,param_3 + 2,DAT_00108278), iVar6 < 1)) {
        return 0;
      }
      if (-1 < (int)(*param_5 << 0x1e)) {
        return 1;
      }
      iVar6 = BIO_printf(param_1,DAT_00108280,param_3,DAT_00108278);
      return (uint)(0 < iVar6);
    }
    if ((0 < iVar6) && (iVar2 = BIO_puts(param_1,DAT_00108268), iVar2 < 1)) break;
    local_2c[0] = sk_value(p_Var7,iVar6);
    iVar6 = iVar6 + 1;
    iVar2 = asn1_item_print_ctx(param_1,local_2c,param_3 + 2,param_4[4],0,0,1,param_5);
    if (iVar2 == 0) {
      return 0;
    }
  }
  return 0;
}

