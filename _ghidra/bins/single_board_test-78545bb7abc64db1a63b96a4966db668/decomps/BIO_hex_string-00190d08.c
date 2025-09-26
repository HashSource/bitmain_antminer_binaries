
undefined4
BIO_hex_string(BIO *param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  int extraout_r1;
  int iVar1;
  int iVar2;
  byte *pbVar3;
  
  if (0 < param_5) {
    if (param_5 != 1) {
      pbVar3 = (byte *)(param_4 + -1);
      iVar1 = 0;
      iVar2 = 0;
      do {
        while( true ) {
          pbVar3 = pbVar3 + 1;
          iVar2 = iVar2 + 1;
          BIO_printf(param_1,"%02X:",(uint)*pbVar3);
          __aeabi_idivmod(iVar1 + 1,param_3);
          iVar1 = extraout_r1;
          if (extraout_r1 != 0) break;
          BIO_printf(param_1,"\n");
          if (param_5 + -1 == iVar2) {
            if (param_5 != 1) {
              BIO_printf(param_1,"%*s",param_2,"");
            }
            goto LAB_00190d5c;
          }
          BIO_printf(param_1,"%*s",param_2,"");
        }
      } while (param_5 + -1 != iVar2);
    }
LAB_00190d5c:
    BIO_printf(param_1,"%02X",(uint)*(byte *)(param_4 + param_5 + -1));
  }
  return 1;
}

