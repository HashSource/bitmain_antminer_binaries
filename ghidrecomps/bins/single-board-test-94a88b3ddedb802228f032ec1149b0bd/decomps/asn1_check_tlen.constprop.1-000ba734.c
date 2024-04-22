
char * asn1_check_tlen_constprop_1
                 (uchar **param_1,int *param_2,undefined *param_3,undefined *param_4,byte *param_5,
                 uchar **param_6,int param_7,undefined4 param_8,char *param_9)

{
  char *pcVar1;
  uint uVar2;
  uchar *puVar3;
  int local_38;
  int local_34;
  uchar *local_30;
  uchar *local_2c [2];
  
  puVar3 = *param_6;
  local_2c[0] = puVar3;
  if (param_9 == (char *)0x0) {
    uVar2 = ASN1_get_object(local_2c,(long *)&local_30,&local_38,&local_34,param_7);
  }
  else if (*param_9 == '\0') {
    uVar2 = ASN1_get_object(local_2c,(long *)&local_30,&local_38,&local_34,param_7);
    *(uint *)(param_9 + 4) = uVar2;
    *(int *)(param_9 + 0x14) = (int)local_2c[0] - (int)puVar3;
    *(uchar **)(param_9 + 8) = local_30;
    *(int *)(param_9 + 0x10) = local_34;
    *param_9 = '\x01';
    *(int *)(param_9 + 0xc) = local_38;
    if (((uVar2 & 0x81) == 0) && (param_7 < (int)(local_30 + ((int)local_2c[0] - (int)puVar3)))) {
      ERR_put_error(0xd,0x68,0x9b,DAT_000ba850,0x49a);
      *param_9 = '\0';
      return (char *)0x0;
    }
  }
  else {
    uVar2 = *(uint *)(param_9 + 4);
    local_30 = *(uchar **)(param_9 + 8);
    local_34 = *(int *)(param_9 + 0x10);
    local_2c[0] = puVar3 + *(int *)(param_9 + 0x14);
    local_38 = *(int *)(param_9 + 0xc);
  }
  if ((int)(uVar2 << 0x18) < 0) {
    ERR_put_error(0xd,0x68,0x66,DAT_000ba850,0x4a2);
    pcVar1 = param_9;
    if (param_9 != (char *)0x0) {
      pcVar1 = (char *)0x0;
      *param_9 = '\0';
    }
  }
  else {
    if ((uVar2 & 1) != 0) {
      local_30 = puVar3 + (param_7 - (int)local_2c[0]);
    }
    if (param_4 != (undefined *)0x0) {
      *param_4 = (char)(uVar2 & 1);
    }
    if (param_5 != (byte *)0x0) {
      *param_5 = (byte)uVar2 & 0x20;
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
    *param_6 = local_2c[0];
    pcVar1 = (char *)0x1;
  }
  return pcVar1;
}

