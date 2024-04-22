
undefined4 ssl3_send_certificate_request(SSL *param_1)

{
  undefined4 uVar1;
  int iVar2;
  _STACK *p_Var3;
  int iVar4;
  X509_NAME *a;
  int iVar5;
  size_t __n;
  ssl3_enc_method *psVar6;
  int iVar7;
  BUF_MEM *str;
  char *pcVar8;
  uint uVar9;
  _STACK *p_Var10;
  uchar *puVar11;
  int local_34;
  uchar *local_30;
  void *local_2c [2];
  
  if (param_1->state == 0x2160) {
    str = param_1->init_buf;
    iVar7 = *(int *)(param_1->method->ssl3_enc + 0x3c);
    pcVar8 = str->data;
    local_30 = (uchar *)(pcVar8 + iVar7 + 1);
    iVar2 = ssl3_get_req_cert_type(param_1,local_30);
    pcVar8[iVar7] = (char)iVar2;
    local_34 = iVar2 + 1;
    local_30 = local_30 + iVar2;
    if (*(int *)(param_1->method->ssl3_enc + 0x38) << 0x1e < 0) {
      __n = tls12_get_psigalgs(param_1,local_2c);
      *local_30 = (uchar)(__n >> 8);
      local_30[1] = (uchar)__n;
      local_30 = local_30 + 2;
      memcpy(local_30,local_2c[0],__n);
      local_34 = local_34 + __n + 2;
      local_30 = local_30 + __n;
    }
    local_30 = local_30 + 2;
    iVar2 = local_34 + 2;
    p_Var3 = &SSL_get_client_CA_list(param_1)->stack;
    p_Var10 = p_Var3;
    if (p_Var3 != (_STACK *)0x0) {
      uVar9 = 0;
      for (iVar7 = 0; iVar4 = sk_num(p_Var3), iVar7 < iVar4; iVar7 = iVar7 + 1) {
        a = (X509_NAME *)sk_value(p_Var3,iVar7);
        iVar4 = i2d_X509_NAME(a,(uchar **)0x0);
        iVar5 = BUF_MEM_grow_clean(str,*(int *)(param_1->method->ssl3_enc + 0x3c) + 2 + iVar2 +
                                       iVar4);
        if (iVar5 == 0) {
          iVar2 = 0x819;
          goto LAB_00086ae4;
        }
        pcVar8 = param_1->init_buf->data;
        iVar5 = *(int *)(param_1->method->ssl3_enc + 0x3c) + iVar2;
        puVar11 = (uchar *)(pcVar8 + iVar5);
        if (param_1->references << 2 < 0) {
          local_30 = puVar11;
          i2d_X509_NAME(a,&local_30);
          pcVar8[iVar5] = (char)((uint)(iVar4 + -2) >> 8);
          puVar11[1] = (uchar)(iVar4 + -2);
        }
        else {
          pcVar8[iVar5] = (char)((uint)iVar4 >> 8);
          puVar11[1] = (uchar)iVar4;
          iVar4 = iVar4 + 2;
          local_30 = puVar11 + 2;
          i2d_X509_NAME(a,&local_30);
        }
        uVar9 = uVar9 + iVar4;
        iVar2 = iVar2 + iVar4;
      }
      p_Var3 = (_STACK *)(uVar9 & 0xff);
      p_Var10 = (_STACK *)((uVar9 << 0x10) >> 0x18);
    }
    pcVar8 = param_1->init_buf->data;
    local_34 = local_34 + *(int *)(param_1->method->ssl3_enc + 0x3c);
    pcVar8[local_34] = (char)p_Var10;
    pcVar8[local_34 + 1] = (char)p_Var3;
    local_30 = (uchar *)(pcVar8 + local_34 + 2);
    (**(code **)(param_1->method->ssl3_enc + 0x40))(param_1,0xd,iVar2);
    psVar6 = param_1->method->ssl3_enc;
    if ((*(uint *)(psVar6 + 0x38) & 8) == 0) {
      iVar2 = BUF_MEM_grow_clean(str,param_1->init_num + 4);
      if (iVar2 == 0) {
        iVar2 = 0x836;
LAB_00086ae4:
        ERR_put_error(0x14,0x96,7,DAT_00086b34,iVar2);
        param_1->state = 5;
        return 0xffffffff;
      }
      iVar2 = param_1->init_num;
      pcVar8 = param_1->init_buf->data;
      pcVar8[iVar2] = '\x0e';
      pcVar8[iVar2 + 1] = '\0';
      local_30 = (uchar *)(pcVar8 + iVar2 + 4);
      pcVar8[iVar2 + 2] = '\0';
      pcVar8[iVar2 + 3] = '\0';
      psVar6 = param_1->method->ssl3_enc;
      param_1->init_num = param_1->init_num + 4;
    }
    param_1->state = 0x2161;
  }
  else {
    psVar6 = param_1->method->ssl3_enc;
  }
  uVar1 = (**(code **)(psVar6 + 0x44))(param_1);
  return uVar1;
}

