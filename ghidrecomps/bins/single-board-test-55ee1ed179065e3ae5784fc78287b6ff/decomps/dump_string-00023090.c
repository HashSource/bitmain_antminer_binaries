
undefined4 dump_string(char *param_1,code *param_2,undefined4 param_3,uint param_4)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  char *local_3c;
  char acStack_34 [16];
  uint local_24;
  uint local_20;
  uint local_1c;
  undefined4 local_18;
  char *local_14;
  char *local_10;
  char *local_c;
  
  iVar2 = (*param_2)(&DAT_0002ce08,1,param_3);
  local_3c = param_1;
  pcVar1 = param_1;
  if (iVar2 != 0) {
    return 0xffffffff;
  }
LAB_00023114:
  local_c = pcVar1;
  local_10 = local_c;
  if (*local_c != '\0') goto LAB_000230c4;
  goto LAB_00023124;
LAB_000230c4:
  local_10 = (char *)utf8_iterate(local_c,&local_24);
  if (local_10 == (char *)0x0) {
    return 0xffffffff;
  }
  if (((((local_24 != 0x5c) && (local_24 != 0x22)) && (0x1f < (int)local_24)) &&
      (((param_4 & 0x400) == 0 || (local_24 != 0x2f)))) &&
     ((pcVar1 = local_10, (param_4 & 0x40) == 0 || (pcVar1 = local_10, (int)local_24 < 0x80))))
  goto LAB_00023114;
LAB_00023124:
  if ((local_c != local_3c) &&
     (iVar2 = (*param_2)(local_3c,(int)local_c - (int)local_3c,param_3), iVar2 != 0)) {
    return 0xffffffff;
  }
  if (local_10 == local_c) {
    uVar3 = (*param_2)(&DAT_0002ce08,1,param_3);
    return uVar3;
  }
  local_18 = 2;
  if (local_24 == 0xc) {
    local_14 = "\\f";
    goto LAB_00023256;
  }
  if ((int)local_24 < 0xd) {
    if (local_24 == 9) {
      local_14 = "\\t";
      goto LAB_00023256;
    }
    if (local_24 == 10) {
      local_14 = "\\n";
      goto LAB_00023256;
    }
    if (local_24 == 8) {
      local_14 = "\\b";
      goto LAB_00023256;
    }
  }
  else {
    if (local_24 == 0x22) {
      local_14 = "\\\"";
      goto LAB_00023256;
    }
    if ((int)local_24 < 0x23) {
      if (local_24 == 0xd) {
        local_14 = "\\r";
        goto LAB_00023256;
      }
    }
    else {
      if (local_24 == 0x2f) {
        local_14 = "\\/";
        goto LAB_00023256;
      }
      if (local_24 == 0x5c) {
        local_14 = "\\\\";
        goto LAB_00023256;
      }
    }
  }
  if ((int)local_24 < 0x10000) {
    sprintf(acStack_34,"\\u%04x",local_24);
    local_18 = 6;
  }
  else {
    local_24 = local_24 - 0x10000;
    local_1c = (int)(local_24 & 0xffc00) >> 10 | 0xd800;
    local_20 = local_24 & 0x3ff | 0xdc00;
    sprintf(acStack_34,"\\u%04x\\u%04x",local_1c,local_20);
    local_18 = 0xc;
  }
  local_14 = acStack_34;
LAB_00023256:
  iVar2 = (*param_2)(local_14,local_18,param_3);
  if (iVar2 != 0) {
    return 0xffffffff;
  }
  local_c = local_10;
  local_3c = local_10;
  pcVar1 = local_c;
  goto LAB_00023114;
}

