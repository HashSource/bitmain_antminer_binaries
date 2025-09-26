
undefined4
asn1_check_tlen(int *param_1,int *param_2,undefined1 *param_3,undefined1 *param_4,byte *param_5,
               int *param_6,int param_7,int param_8,int param_9,char param_10,char *param_11)

{
  uint uVar1;
  uchar *puVar2;
  undefined4 uVar3;
  int local_38;
  int local_34;
  int local_30;
  uchar *local_2c [2];
  
  puVar2 = (uchar *)*param_6;
  local_2c[0] = puVar2;
  if (param_11 == (char *)0x0) {
    uVar1 = ASN1_get_object(local_2c,&local_30,&local_38,&local_34,param_7);
    if ((int)(uVar1 << 0x18) < 0) {
      ERR_put_error(0xd,0x68,0x66,"crypto/asn1/tasn_dec.c",0x471);
      return 0;
    }
  }
  else {
    if (*param_11 == '\0') {
      uVar1 = ASN1_get_object(local_2c,&local_30,&local_38,&local_34,param_7);
      *(int *)(param_11 + 0x10) = local_34;
      *param_11 = '\x01';
      *(uint *)(param_11 + 4) = uVar1;
      *(int *)(param_11 + 0x14) = (int)local_2c[0] - (int)puVar2;
      *(int *)(param_11 + 8) = local_30;
      *(int *)(param_11 + 0xc) = local_38;
      if (((uVar1 & 0x81) == 0) && (param_7 < ((int)local_2c[0] - (int)puVar2) + local_30)) {
        ERR_put_error(0xd,0x68,0x9b,"crypto/asn1/tasn_dec.c",0x469);
        *param_11 = '\0';
        return 0;
      }
    }
    else {
      local_38 = *(int *)(param_11 + 0xc);
      local_30 = *(int *)(param_11 + 8);
      uVar1 = *(uint *)(param_11 + 4);
      local_2c[0] = puVar2 + *(int *)(param_11 + 0x14);
      local_34 = *(int *)(param_11 + 0x10);
    }
    if ((int)(uVar1 << 0x18) < 0) {
      ERR_put_error(0xd,0x68,0x66,"crypto/asn1/tasn_dec.c",0x471);
      *param_11 = '\0';
      return 0;
    }
  }
  if (-1 < param_8) {
    if ((param_8 != local_38) || (local_34 != param_9)) {
      if (param_10 == '\0') {
        if (param_11 != (char *)0x0) {
          *param_11 = '\0';
        }
        uVar3 = 0;
        ERR_put_error(0xd,0x68,0xa8,"crypto/asn1/tasn_dec.c",0x47d);
      }
      else {
        uVar3 = 0xffffffff;
      }
      return uVar3;
    }
    if (param_11 != (char *)0x0) {
      *param_11 = '\0';
    }
  }
  if ((uVar1 & 1) != 0) {
    local_30 = param_7 - ((int)local_2c[0] - (int)puVar2);
  }
  if (param_4 != (undefined1 *)0x0) {
    *param_4 = (char)(uVar1 & 1);
  }
  if (param_5 != (byte *)0x0) {
    *param_5 = (byte)uVar1 & 0x20;
  }
  if (param_1 != (int *)0x0) {
    *param_1 = local_30;
  }
  if (param_3 != (undefined1 *)0x0) {
    *param_3 = (char)local_34;
  }
  if (param_2 != (int *)0x0) {
    *param_2 = local_38;
  }
  *param_6 = (int)local_2c[0];
  return 1;
}

