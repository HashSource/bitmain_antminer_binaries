
undefined4
BIO_hex_string(BIO *param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  byte *pbVar1;
  int extraout_r1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (0 < param_5) {
    if (param_5 != 1) {
      iVar3 = 0;
      iVar4 = iVar3;
      iVar5 = param_4;
      while( true ) {
        pbVar1 = (byte *)(param_4 + iVar3);
        iVar3 = iVar3 + 1;
        BIO_printf(param_1,DAT_00102ff0,(uint)*pbVar1);
        __aeabi_idivmod(iVar4 + 1,param_3);
        if (extraout_r1 == 0) {
          BIO_printf(param_1,DAT_00102ffc);
        }
        if (iVar3 == param_5 + -1) break;
        iVar2 = iVar3;
        if (iVar3 != 0) {
          iVar2 = 1;
        }
        if (extraout_r1 != 0) {
          iVar2 = 0;
        }
        iVar4 = extraout_r1;
        if (iVar2 != 0) {
          BIO_printf(param_1,DAT_00102ff4,param_2,DAT_00102ff8,iVar5);
        }
      }
      if (extraout_r1 == 0) {
        BIO_printf(param_1,DAT_00102ff4,param_2,DAT_00102ff8,iVar5);
      }
    }
    BIO_printf(param_1,DAT_00103000,(uint)*(byte *)(param_4 + param_5 + -1));
  }
  return 1;
}

