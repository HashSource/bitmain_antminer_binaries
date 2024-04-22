
undefined4
ssl_parse_clienthello_renegotiate_ext(int param_1,byte *param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  
  if (param_3 < 1) {
    iVar2 = 0x9a;
  }
  else {
    if (*param_2 + 1 == param_3) {
      iVar2 = *(int *)(param_1 + 0x58);
      if ((uint)*(byte *)(iVar2 + 0x3d4) == (uint)*param_2) {
        iVar1 = memcmp(param_2 + 1,(void *)(iVar2 + 0x394),(uint)*(byte *)(iVar2 + 0x3d4));
        if (iVar1 == 0) {
          *(undefined4 *)(iVar2 + 0x418) = 1;
          return 1;
        }
        iVar2 = 0xb4;
      }
      else {
        iVar2 = 0xac;
      }
      ERR_put_error(0x14,300,0x151,DAT_00083a18,iVar2);
      *param_4 = 0x28;
      return 0;
    }
    iVar2 = 0xa4;
  }
  ERR_put_error(0x14,300,0x150,DAT_00083a18,iVar2);
  *param_4 = 0x2f;
  return 0;
}

