
int asn1_d2i_ex_primitive
              (ASN1_VALUE **param_1,uchar **param_2,undefined4 param_3,ASN1_ITEM *param_4,
              uint param_5,undefined4 param_6,char param_7,undefined *param_8)

{
  int iVar1;
  uchar *puVar2;
  int iVar3;
  uchar *puVar4;
  uchar *puVar5;
  char local_60 [8];
  char local_58 [7];
  char local_51;
  uint local_50;
  uchar *local_4c;
  uchar *local_48;
  int iStack_44;
  int iStack_40;
  int local_3c;
  uchar *local_38;
  BUF_MEM local_34;
  
  local_58[0] = '\0';
  if (param_1 == (ASN1_VALUE **)0x0) {
    ERR_put_error(0xd,0x6c,0x7d,DAT_000baf34,0x2d1);
    return 0;
  }
  if (param_4->itype == '\x05') {
    local_50 = param_5;
    if (param_5 == 0xfffffffc) {
      param_5 = 0xffffffff;
      goto LAB_000bad70;
    }
LAB_000bad5c:
    param_6 = 0;
    param_5 = local_50;
  }
  else {
    local_50 = param_4->utype;
    if (local_50 == 0xfffffffc) {
      if (-1 < (int)param_5) {
        ERR_put_error(0xd,0x6c,0x7f,DAT_000baf34,0x2df);
        return 0;
      }
LAB_000bad70:
      if (param_7 != '\0') {
        ERR_put_error(0xd,0x6c,0x7e,DAT_000baf34,0x2e4);
        return 0;
      }
      local_48 = *param_2;
      iVar1 = asn1_check_tlen_constprop_1(0,&local_50,&local_38,0,0,&local_48,param_3,0,param_8);
      if (iVar1 == 0) {
        ERR_put_error(0xd,0x6c,0x3a,DAT_000baf34,0x2eb);
        return 0;
      }
      if ((char)local_38 != '\0') {
        local_50 = 0xfffffffd;
      }
    }
    if (param_5 == 0xffffffff) goto LAB_000bad5c;
  }
  local_48 = *param_2;
  iVar1 = asn1_check_tlen(&local_4c,0,0,&local_51,local_60,&local_48,param_3,param_5,param_6,param_7
                          ,param_8);
  if (iVar1 == 0) {
    ERR_put_error(0xd,0x6c,0x3a,DAT_000baf34,0x2fa);
    return 0;
  }
  if (iVar1 == -1) {
    return -1;
  }
  puVar4 = (uchar *)(uint)(local_50 == 0xfffffffd);
  if (local_50 - 0x10 < 2) {
    puVar4 = (uchar *)0x1;
  }
  if (puVar4 == (uchar *)0x0) {
    if (local_60[0] == '\0') {
      puVar4 = local_48;
      local_48 = local_48 + (int)local_4c;
    }
    else {
      if (((((local_50 & 0xfffffffb) == 1) || (local_50 == 6)) || (local_50 == 2)) ||
         (local_50 == 10)) {
        ERR_put_error(0xd,0x6c,0xda,DAT_000baf34,799);
        return 0;
      }
      local_34.length = (size_t)puVar4;
      local_34.data = (char *)puVar4;
      local_34.max = (size_t)puVar4;
      iVar1 = asn1_collect_constprop_0(&local_34,&local_48,local_4c,local_51,0);
      local_4c = (uchar *)local_34.length;
      if (iVar1 == 0) {
        local_58[0] = '\x01';
        iVar1 = 0;
        goto LAB_000bacd8;
      }
      iVar1 = BUF_MEM_grow_clean(&local_34,(size_t)(local_34.length + 1));
      if (iVar1 == 0) {
        ERR_put_error(0xd,0x6c,0x41,DAT_000baf34,0x332);
        return 0;
      }
      local_34.data[(int)local_4c] = '\0';
      local_58[0] = '\x01';
      puVar4 = (uchar *)local_34.data;
    }
LAB_000bacb8:
    iVar1 = asn1_ex_c2i(param_1,puVar4,(int)local_4c,local_50,local_58,param_4);
    if (iVar1 != 0) {
      iVar1 = 1;
      *param_2 = local_48;
    }
  }
  else {
    if ((uchar *)(uint)(local_50 == 0xfffffffd) == (uchar *)0x0) {
      if (local_60[0] == '\0') {
        ERR_put_error(0xd,0x6c,0x9c,DAT_000baf34,0x30c);
        return 0;
      }
    }
    else if (param_8 != (undefined *)0x0) {
      *param_8 = 0;
    }
    puVar4 = *param_2;
    if (local_51 == '\0') {
      puVar2 = local_48 + (int)local_4c;
      local_4c = local_4c + ((int)local_48 - (int)puVar4);
      local_34.data = (char *)0x0;
      local_48 = puVar2;
      goto LAB_000bacb8;
    }
    if (0 < (int)local_4c) {
      iVar1 = 1;
      puVar2 = local_4c;
      puVar5 = local_48;
      do {
        if (((puVar2 == (uchar *)0x1) || (*puVar5 != '\0')) || (puVar5[1] != '\0')) {
          local_38 = puVar5;
          iVar3 = ASN1_get_object(&local_38,&local_3c,&iStack_44,&iStack_40,(long)puVar2);
          if (iVar3 << 0x18 < 0) {
            ERR_put_error(0xd,0x68,0x66,DAT_000baf34,0x4a2);
            ERR_put_error(0xd,0xbe,0x3a,DAT_000baf34,0x3fb);
            goto LAB_000bae0c;
          }
          if (iVar3 << 0x1f < 0) {
            iVar1 = iVar1 + 1;
            puVar2 = puVar2 + ((int)puVar5 - (int)local_38);
            puVar5 = local_38;
          }
          else {
            puVar2 = puVar2 + ((int)puVar5 - (int)(local_38 + local_3c));
            puVar5 = local_38 + local_3c;
          }
        }
        else {
          iVar1 = iVar1 + -1;
          puVar5 = puVar5 + 2;
          puVar2 = puVar2 + -2;
          if (iVar1 == 0) {
            local_4c = puVar5 + -(int)puVar4;
            local_48 = puVar5;
            goto LAB_000bacb8;
          }
        }
      } while (0 < (int)puVar2);
    }
    ERR_put_error(0xd,0xbe,0x89,DAT_000baf34,0x405);
LAB_000bae0c:
    iVar1 = 0;
  }
  if (local_58[0] == '\0') {
    return iVar1;
  }
LAB_000bacd8:
  if ((uchar *)local_34.data != (uchar *)0x0) {
    CRYPTO_free(local_34.data);
    return iVar1;
  }
  return iVar1;
}

