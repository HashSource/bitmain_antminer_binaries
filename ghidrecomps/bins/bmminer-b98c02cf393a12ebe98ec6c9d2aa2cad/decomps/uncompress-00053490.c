
int uncompress(undefined4 param_1,undefined4 *param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 local_48;
  int local_44;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_28;
  undefined4 local_24;
  
  local_38 = *param_2;
  local_28 = 0;
  local_24 = 0;
  local_48 = param_3;
  local_44 = param_4;
  local_3c = param_1;
  iVar1 = inflateInit_(&local_48,DAT_000534f8,0x38);
  if (iVar1 == 0) {
    iVar1 = inflate(&local_48,4);
    if (iVar1 == 1) {
      *param_2 = local_34;
      iVar1 = inflateEnd(&local_48);
    }
    else {
      inflateEnd(&local_48);
      if (iVar1 == 2) {
        iVar1 = -3;
      }
      else if ((iVar1 == -5) && (local_44 == 0)) {
        iVar1 = -3;
      }
    }
  }
  return iVar1;
}

