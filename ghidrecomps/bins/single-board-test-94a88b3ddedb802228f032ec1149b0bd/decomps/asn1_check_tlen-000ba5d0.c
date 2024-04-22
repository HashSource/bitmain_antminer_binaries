
undefined4
asn1_check_tlen(uchar **param_1,int *param_2,undefined *param_3,undefined *param_4,byte *param_5,
               uchar **param_6,int param_7,int param_8,int param_9,char param_10,char *param_11)

{
  uint uVar1;
  undefined4 uVar2;
  uchar *puVar3;
  int local_38;
  int local_34;
  uchar *local_30;
  uchar *local_2c [2];
  
  puVar3 = *param_6;
  local_2c[0] = puVar3;
  if (param_11 == (char *)0x0) {
    uVar1 = ASN1_get_object(local_2c,(long *)&local_30,&local_38,&local_34,param_7);
  }
  else if (*param_11 == '\0') {
    uVar1 = ASN1_get_object(local_2c,(long *)&local_30,&local_38,&local_34,param_7);
    *(uint *)(param_11 + 4) = uVar1;
    *(int *)(param_11 + 0x14) = (int)local_2c[0] - (int)puVar3;
    *(uchar **)(param_11 + 8) = local_30;
    *(int *)(param_11 + 0x10) = local_34;
    *param_11 = '\x01';
    *(int *)(param_11 + 0xc) = local_38;
    if (((uVar1 & 0x81) == 0) && (param_7 < (int)(local_30 + ((int)local_2c[0] - (int)puVar3)))) {
      ERR_put_error(0xd,0x68,0x9b,DAT_000ba730,0x49a);
      *param_11 = '\0';
      return 0;
    }
  }
  else {
    local_30 = *(uchar **)(param_11 + 8);
    local_34 = *(int *)(param_11 + 0x10);
    local_2c[0] = puVar3 + *(int *)(param_11 + 0x14);
    local_38 = *(int *)(param_11 + 0xc);
    uVar1 = *(uint *)(param_11 + 4);
  }
  if ((uVar1 & 0x80) == 0) {
    if (-1 < param_8) {
      if ((param_8 != local_38) || (param_9 != local_34)) {
        if (param_10 != '\0') {
          return 0xffffffff;
        }
        if (param_11 != (char *)0x0) {
          *param_11 = '\0';
        }
        ERR_put_error(0xd,0x68,0xa8,DAT_000ba730,0x4ae);
        goto LAB_000ba638;
      }
      if (param_11 != (char *)0x0) {
        *param_11 = '\0';
      }
    }
    if ((uVar1 & 1) != 0) {
      local_30 = puVar3 + (param_7 - (int)local_2c[0]);
    }
    if (param_4 != (undefined *)0x0) {
      *param_4 = (char)(uVar1 & 1);
    }
    if (param_5 != (byte *)0x0) {
      *param_5 = (byte)uVar1 & 0x20;
    }
    if (param_1 != (uchar **)0x0) {
      *param_1 = local_30;
    }
    if (param_3 != (undefined *)0x0) {
      *param_3 = (char)local_34;
    }
    if (param_2 != (int *)0x0) {
      *param_2 = local_38;
    }
    uVar2 = 1;
    *param_6 = local_2c[0];
  }
  else {
    ERR_put_error(0xd,0x68,0x66,DAT_000ba730,0x4a2);
    if (param_11 != (char *)0x0) {
      *param_11 = '\0';
      return 0;
    }
LAB_000ba638:
    uVar2 = 0;
  }
  return uVar2;
}

