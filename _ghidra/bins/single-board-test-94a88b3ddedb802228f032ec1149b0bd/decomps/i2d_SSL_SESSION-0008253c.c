
int i2d_SSL_SESSION(SSL_SESSION *in,uchar **pp)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint length;
  int length_00;
  uchar *puVar8;
  int local_198;
  int local_194;
  int local_190;
  X509 *local_18c;
  int local_188;
  int local_180;
  int local_17c;
  uchar local_178 [8];
  uchar local_170;
  uchar local_16f;
  uchar local_16e;
  byte *local_16c;
  uchar auStack_168 [8];
  uchar auStack_160 [8];
  uchar auStack_158 [8];
  uchar auStack_150 [8];
  uchar auStack_148 [8];
  uchar auStack_140 [8];
  ASN1_INTEGER local_138;
  ASN1_INTEGER local_128;
  ASN1_OCTET_STRING local_118;
  ASN1_OCTET_STRING local_108;
  ASN1_OCTET_STRING local_f8;
  ASN1_OCTET_STRING local_e8;
  ASN1_OCTET_STRING local_d8;
  ASN1_OCTET_STRING local_c8;
  ASN1_INTEGER local_b8;
  ASN1_INTEGER local_a8;
  ASN1_INTEGER local_98;
  ASN1_OCTET_STRING local_88;
  ASN1_INTEGER local_78;
  ASN1_OCTET_STRING local_68;
  ASN1_OCTET_STRING local_58;
  ASN1_OCTET_STRING local_48;
  ASN1_OCTET_STRING local_38;
  
  if (in == (SSL_SESSION *)0x0) {
    iVar6 = 0;
  }
  else if ((*(int *)(in->krb5_client_princ + 0x24) == 0) &&
          (*(int *)(in->krb5_client_princ + 0x28) == 0)) {
    iVar6 = 0;
  }
  else {
    local_138.data = auStack_168;
    local_138.length = 8;
    local_138.type = 2;
    ASN1_INTEGER_set(&local_138,1);
    local_128.data = auStack_160;
    local_128.length = 8;
    local_128.type = 2;
    ASN1_INTEGER_set(&local_128,in->ssl_version);
    local_118.data = &local_170;
    local_118.type = 4;
    if (*(int *)(in->krb5_client_princ + 0x24) == 0) {
      uVar7 = *(undefined4 *)(in->krb5_client_princ + 0x28);
    }
    else {
      uVar7 = *(undefined4 *)(*(int *)(in->krb5_client_princ + 0x24) + 8);
    }
    local_16f = (uchar)((uint)uVar7 >> 8);
    if (in->ssl_version == 2) {
      local_170 = (uchar)((uint)uVar7 >> 0x10);
      local_118.length = 3;
      local_16e = (uchar)uVar7;
    }
    else {
      local_118.length = 2;
      local_170 = local_16f;
      local_16f = (uchar)uVar7;
    }
    if (*(int *)(in->krb5_client_princ + 0x20) != 0) {
      local_108.data = local_178;
      local_178[0] = (uchar)*(int *)(in->krb5_client_princ + 0x20);
      local_108.length = 1;
      local_108.type = 4;
    }
    local_f8.length = in->master_key_length;
    local_f8.data = in->master_key;
    local_e8.data = in->session_id;
    local_d8.data = in->sid_ctx;
    local_c8.data = in->key_arg;
    local_e8.length = in->session_id_length;
    local_f8.type = 4;
    local_e8.type = 4;
    local_d8.length = in->sid_ctx_length;
    local_d8.type = 4;
    local_c8.type = 4;
    local_c8.length = in->key_arg_length;
    if (*(long *)(in->krb5_client_princ + 0x1c) != 0) {
      local_b8.data = auStack_158;
      local_b8.length = 8;
      local_b8.type = 2;
      ASN1_INTEGER_set(&local_b8,*(long *)(in->krb5_client_princ + 0x1c));
    }
    if (*(long *)(in->krb5_client_princ + 0x18) == 0) {
      iVar6 = *(int *)(in->krb5_client_princ + 0x10);
    }
    else {
      local_a8.data = auStack_150;
      local_a8.length = 8;
      local_a8.type = 2;
      ASN1_INTEGER_set(&local_a8,*(long *)(in->krb5_client_princ + 0x18));
      iVar6 = *(int *)(in->krb5_client_princ + 0x10);
    }
    if (iVar6 != 0) {
      local_98.data = auStack_148;
      local_98.length = 8;
      local_98.type = 2;
      ASN1_INTEGER_set(&local_98,iVar6);
    }
    puVar8 = *(uchar **)(in->krb5_client_princ + 0x40);
    if (puVar8 != (uchar *)0x0) {
      local_88.length = strlen((char *)puVar8);
      local_88.type = 4;
      local_88.data = puVar8;
    }
    if (*(uchar **)(in->krb5_client_princ + 0x54) != (uchar *)0x0) {
      local_68.length = *(int *)(in->krb5_client_princ + 0x58);
      local_68.type = 4;
      local_68.data = *(uchar **)(in->krb5_client_princ + 0x54);
    }
    if (0 < *(long *)(in->krb5_client_princ + 0x5c)) {
      local_78.data = auStack_140;
      local_78.length = 8;
      local_78.type = 2;
      ASN1_INTEGER_set(&local_78,*(long *)(in->krb5_client_princ + 0x5c));
    }
    puVar8 = (uchar *)in->krb5_client_princ_len;
    if (puVar8 != (uchar *)0x0) {
      local_58.length = strlen((char *)puVar8);
      local_58.type = 4;
      local_58.data = puVar8;
    }
    puVar8 = *(uchar **)in->krb5_client_princ;
    if (puVar8 != (uchar *)0x0) {
      local_48.length = strlen((char *)puVar8);
      local_48.type = 4;
      local_48.data = puVar8;
    }
    puVar8 = *(uchar **)(in->krb5_client_princ + 0x60);
    if (puVar8 != (uchar *)0x0) {
      local_38.length = strlen((char *)puVar8);
      local_38.type = 4;
      local_38.data = puVar8;
    }
    iVar2 = i2d_ASN1_INTEGER(&local_138,(uchar **)0x0);
    iVar3 = i2d_ASN1_INTEGER(&local_128,(uchar **)0x0);
    iVar4 = i2d_ASN1_OCTET_STRING(&local_118,(uchar **)0x0);
    iVar5 = i2d_ASN1_OCTET_STRING(&local_e8,(uchar **)0x0);
    iVar6 = i2d_ASN1_OCTET_STRING(&local_f8,(uchar **)0x0);
    iVar6 = iVar6 + iVar5 + iVar4 + iVar2 + iVar3;
    if (in->key_arg_length != 0) {
      iVar2 = i2d_ASN1_OCTET_STRING(&local_c8,(uchar **)0x0);
      iVar6 = iVar6 + iVar2;
    }
    if (*(int *)(in->krb5_client_princ + 0x1c) == 0) {
      local_188 = 0;
    }
    else {
      local_188 = i2d_ASN1_INTEGER(&local_b8,(uchar **)0x0);
      iVar2 = ASN1_object_size(1,local_188,1);
      iVar6 = iVar6 + iVar2;
    }
    if (*(int *)(in->krb5_client_princ + 0x18) == 0) {
      local_18c = *(X509 **)(in->krb5_client_princ + 0xc);
      iVar2 = 0;
    }
    else {
      iVar2 = i2d_ASN1_INTEGER(&local_a8,(uchar **)0x0);
      iVar3 = ASN1_object_size(1,iVar2,2);
      iVar6 = iVar6 + iVar3;
      local_18c = *(X509 **)(in->krb5_client_princ + 0xc);
    }
    if (local_18c != (X509 *)0x0) {
      local_18c = (X509 *)i2d_X509(local_18c,(uchar **)0x0);
      iVar3 = ASN1_object_size(1,(int)local_18c,3);
      iVar6 = iVar6 + iVar3;
    }
    iVar3 = i2d_ASN1_OCTET_STRING(&local_d8,(uchar **)0x0);
    iVar4 = ASN1_object_size(1,iVar3,4);
    iVar4 = iVar4 + iVar6;
    if (*(int *)(in->krb5_client_princ + 0x10) == 0) {
      local_180 = 0;
    }
    else {
      local_180 = i2d_ASN1_INTEGER(&local_98,(uchar **)0x0);
      iVar6 = ASN1_object_size(1,local_180,5);
      iVar4 = iVar4 + iVar6;
    }
    if (*(int *)(in->krb5_client_princ + 0x5c) < 1) {
      local_190 = 0;
    }
    else {
      local_190 = i2d_ASN1_INTEGER(&local_78,(uchar **)0x0);
      iVar6 = ASN1_object_size(1,local_190,9);
      iVar4 = iVar4 + iVar6;
    }
    if (*(int *)(in->krb5_client_princ + 0x54) == 0) {
      local_198 = 0;
    }
    else {
      local_198 = i2d_ASN1_OCTET_STRING(&local_68,(uchar **)0x0);
      iVar6 = ASN1_object_size(1,local_198,10);
      iVar4 = iVar4 + iVar6;
    }
    iVar5 = *(int *)(in->krb5_client_princ + 0x40);
    if (iVar5 != 0) {
      iVar5 = i2d_ASN1_OCTET_STRING(&local_88,(uchar **)0x0);
      iVar6 = ASN1_object_size(1,iVar5,6);
      iVar4 = iVar4 + iVar6;
    }
    if (*(int *)(in->krb5_client_princ + 0x20) == 0) {
      local_17c = 0;
    }
    else {
      local_17c = i2d_ASN1_OCTET_STRING(&local_108,(uchar **)0x0);
      iVar6 = ASN1_object_size(1,local_17c,0xb);
      iVar4 = iVar4 + iVar6;
    }
    length = in->krb5_client_princ_len;
    if (length != 0) {
      length = i2d_ASN1_OCTET_STRING(&local_58,(uchar **)0x0);
      iVar6 = ASN1_object_size(1,length,7);
      iVar4 = iVar4 + iVar6;
    }
    length_00 = *(int *)in->krb5_client_princ;
    if (length_00 != 0) {
      length_00 = i2d_ASN1_OCTET_STRING(&local_48,(uchar **)0x0);
      iVar6 = ASN1_object_size(1,length_00,8);
      iVar4 = iVar4 + iVar6;
    }
    if (*(int *)(in->krb5_client_princ + 0x60) == 0) {
      local_194 = 0;
    }
    else {
      local_194 = i2d_ASN1_OCTET_STRING(&local_38,(uchar **)0x0);
      iVar6 = ASN1_object_size(1,local_194,0xc);
      iVar4 = iVar4 + iVar6;
    }
    iVar6 = ASN1_object_size(1,iVar4,0x10);
    if (pp != (uchar **)0x0) {
      local_16c = *pp;
      ASN1_put_object(&local_16c,1,iVar4,0x10,0);
      i2d_ASN1_INTEGER(&local_138,&local_16c);
      i2d_ASN1_INTEGER(&local_128,&local_16c);
      i2d_ASN1_OCTET_STRING(&local_118,&local_16c);
      i2d_ASN1_OCTET_STRING(&local_e8,&local_16c);
      i2d_ASN1_OCTET_STRING(&local_f8,&local_16c);
      pbVar1 = local_16c;
      if (in->key_arg_length != 0) {
        i2d_ASN1_OCTET_STRING(&local_c8,&local_16c);
        *pbVar1 = *pbVar1 & 0x20 | 0x80;
      }
      if (*(int *)(in->krb5_client_princ + 0x1c) != 0) {
        ASN1_put_object(&local_16c,1,local_188,1,0x80);
        i2d_ASN1_INTEGER(&local_b8,&local_16c);
      }
      if (*(int *)(in->krb5_client_princ + 0x18) != 0) {
        ASN1_put_object(&local_16c,1,iVar2,2,0x80);
        i2d_ASN1_INTEGER(&local_a8,&local_16c);
      }
      if (*(int *)(in->krb5_client_princ + 0xc) != 0) {
        ASN1_put_object(&local_16c,1,(int)local_18c,3,0x80);
        i2d_X509(*(X509 **)(in->krb5_client_princ + 0xc),&local_16c);
      }
      ASN1_put_object(&local_16c,1,iVar3,4,0x80);
      i2d_ASN1_OCTET_STRING(&local_d8,&local_16c);
      if (*(int *)(in->krb5_client_princ + 0x10) != 0) {
        ASN1_put_object(&local_16c,1,local_180,5,0x80);
        i2d_ASN1_INTEGER(&local_98,&local_16c);
      }
      if (*(int *)(in->krb5_client_princ + 0x40) != 0) {
        ASN1_put_object(&local_16c,1,iVar5,6,0x80);
        i2d_ASN1_OCTET_STRING(&local_88,&local_16c);
      }
      if (in->krb5_client_princ_len != 0) {
        ASN1_put_object(&local_16c,1,length,7,0x80);
        i2d_ASN1_OCTET_STRING(&local_58,&local_16c);
      }
      if (*(int *)in->krb5_client_princ != 0) {
        ASN1_put_object(&local_16c,1,length_00,8,0x80);
        i2d_ASN1_OCTET_STRING(&local_48,&local_16c);
      }
      if (0 < *(int *)(in->krb5_client_princ + 0x5c)) {
        ASN1_put_object(&local_16c,1,local_190,9,0x80);
        i2d_ASN1_INTEGER(&local_78,&local_16c);
      }
      if (*(int *)(in->krb5_client_princ + 0x54) != 0) {
        ASN1_put_object(&local_16c,1,local_198,10,0x80);
        i2d_ASN1_OCTET_STRING(&local_68,&local_16c);
      }
      if (*(int *)(in->krb5_client_princ + 0x20) != 0) {
        ASN1_put_object(&local_16c,1,local_17c,0xb,0x80);
        i2d_ASN1_OCTET_STRING(&local_108,&local_16c);
      }
      if (*(int *)(in->krb5_client_princ + 0x60) != 0) {
        ASN1_put_object(&local_16c,1,local_194,0xc,0x80);
        i2d_ASN1_OCTET_STRING(&local_38,&local_16c);
      }
      *pp = local_16c;
    }
  }
  return iVar6;
}

