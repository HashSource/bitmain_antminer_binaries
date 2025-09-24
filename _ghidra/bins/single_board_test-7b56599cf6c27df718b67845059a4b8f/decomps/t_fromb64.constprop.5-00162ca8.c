
size_t t_fromb64_constprop_5(uchar *param_1,byte *param_2)

{
  byte bVar1;
  size_t sVar2;
  EVP_ENCODE_CTX *ctx;
  int iVar3;
  uint inl;
  bool bVar4;
  size_t local_28;
  int local_24 [2];
  
  bVar1 = *param_2;
  local_28 = 0;
  local_24[0] = 0;
  bVar4 = 0x1f < bVar1;
  if (bVar1 != 0x20) {
    bVar4 = bVar1 != 9;
  }
  if (!bVar4 || (bVar1 == 0x20 || bVar1 == 10)) {
    do {
      param_2 = param_2 + 1;
      bVar1 = *param_2;
      bVar4 = 0x1f < bVar1;
      if (bVar1 != 0x20) {
        bVar4 = bVar1 != 9;
      }
    } while (!bVar4 || (bVar1 == 0x20 || bVar1 == 10));
  }
  sVar2 = strlen((char *)param_2);
  inl = -sVar2 & 3;
  if ((((int)sVar2 < 0) || (0x9c4 < (sVar2 + inl >> 2) * 3)) ||
     (ctx = (EVP_ENCODE_CTX *)EVP_ENCODE_CTX_new(), ctx == (EVP_ENCODE_CTX *)0x0)) {
    return 0xffffffff;
  }
  if (inl != 3) {
    EVP_DecodeInit(ctx);
    evp_encode_ctx_set_flags(ctx,2);
    if (inl == 0) {
      iVar3 = EVP_DecodeUpdate(ctx,param_1,local_24,param_2,sVar2);
      if (-1 < iVar3) {
        local_28 = local_24[0] + local_28;
        EVP_DecodeFinal(ctx,param_1 + local_28,local_24);
        local_28 = local_24[0] + local_28;
        goto LAB_00162d64;
      }
    }
    else {
      iVar3 = EVP_DecodeUpdate(ctx,param_1,(int *)&local_28,"00",inl);
      if (-1 < iVar3) {
        iVar3 = EVP_DecodeUpdate(ctx,param_1,local_24,param_2,sVar2);
        if (-1 < iVar3) {
          local_28 = local_28 + local_24[0];
          EVP_DecodeFinal(ctx,param_1 + local_28,local_24);
          local_28 = local_24[0] + local_28;
          if ((int)inl < (int)local_28) {
            sVar2 = local_28 - inl;
            memmove(param_1,param_1 + inl,sVar2);
            local_28 = sVar2;
            goto LAB_00162d64;
          }
        }
      }
    }
  }
  local_28 = 0xffffffff;
LAB_00162d64:
  EVP_ENCODE_CTX_free(ctx);
  return local_28;
}

