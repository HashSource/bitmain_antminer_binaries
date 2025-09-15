
uint asn1_template_print_ctx
               (BIO *param_1,undefined4 *param_2,int param_3,uint *param_4,uint *param_5)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  _STACK *p_Var8;
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
        pcVar7 = "SEQUENCE";
        if ((uVar1 & 2) != 0) {
          pcVar7 = "SET";
        }
        iVar6 = BIO_printf(param_1,"%*s%s OF %s {\n",param_3,&DAT_0013a6fc,pcVar7,uVar4);
      }
      else {
        iVar6 = BIO_printf(param_1,"%*s%s:\n",param_3,&DAT_0013a6fc,uVar4);
      }
      if (iVar6 < 1) {
        return 0;
      }
    }
  }
  iVar6 = 0;
  p_Var8 = (_STACK *)*param_2;
  while( true ) {
    iVar2 = sk_num(p_Var8);
    if (iVar2 <= iVar6) {
      if ((iVar6 == 0) &&
         (iVar6 = BIO_printf(param_1,"%*s<EMPTY>\n",param_3 + 2,&DAT_0013a6fc), iVar6 < 1)) {
        return 0;
      }
      if (-1 < (int)(*param_5 << 0x1e)) {
        return 1;
      }
      iVar6 = BIO_printf(param_1,"%*s}\n",param_3,&DAT_0013a6fc);
      return (uint)(0 < iVar6);
    }
    if ((0 < iVar6) && (iVar2 = BIO_puts(param_1,"\n"), iVar2 < 1)) break;
    local_2c[0] = sk_value(p_Var8,iVar6);
    iVar6 = iVar6 + 1;
    iVar2 = asn1_item_print_ctx(param_1,local_2c,param_3 + 2,param_4[4],0,0,1,param_5);
    if (iVar2 == 0) {
      return 0;
    }
  }
  return 0;
}

