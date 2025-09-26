
int EVP_DecodeUpdate(EVP_ENCODE_CTX *ctx,uchar *out,int *outl,uchar *in,int inl)

{
  byte bVar1;
  int iVar2;
  uint n;
  byte bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint local_3c;
  uchar *local_34;
  int local_30;
  
  n = ctx->num;
  iVar5 = ctx->line_num;
  iVar7 = ctx->expect_nl;
  if (inl == 0) {
    uVar6 = 0;
    local_30 = 0;
  }
  else if ((n == 0) && (data_ascii2bin[*in & 0x7f] == -0xe)) {
    uVar6 = 0;
    local_30 = 0;
  }
  else if (inl < 1) {
    local_30 = 0;
    uVar6 = 1;
  }
  else if (iVar5 < 0x50) {
    iVar4 = 0;
    local_3c = 0xffffffff;
    uVar6 = 0;
    local_30 = 0;
    local_34 = out;
    do {
      while( true ) {
        bVar1 = *in;
        iVar4 = iVar4 + 1;
        bVar3 = data_ascii2bin[bVar1 & 0x7f];
        if ((bVar3 | 0x13) == 0xf3) {
          if (bVar3 == 0xff) goto LAB_0019da52;
        }
        else {
          if (0x4f < (int)n) {
            OpenSSLDie("encode.c",0x106,"n < (int)sizeof(ctx->enc_data)");
          }
          iVar5 = iVar5 + 1;
          ctx->enc_data[n] = bVar1;
          n = n + 1;
        }
        if ((bVar1 == 0x3d) && (uVar6 = uVar6 + 1, local_3c == 0xffffffff)) {
          local_3c = n;
        }
        if (bVar3 == 0xf1) break;
        if ((bVar3 != 0xf0) || (iVar5 = iVar7, iVar7 == 0)) goto joined_r0x0019da36;
        iVar7 = 0;
LAB_0019da74:
        iVar5 = 0;
        in = in + 1;
        iVar2 = iVar7;
        if (inl <= iVar4) {
LAB_0019da48:
          iVar7 = iVar2;
          uVar6 = 1;
          goto LAB_0019da58;
        }
      }
      iVar5 = iVar7;
      if (iVar7 != 0) goto LAB_0019da74;
joined_r0x0019da36:
      if ((inl != iVar4) || (((n & 3) != 0 && (uVar6 == 0)))) {
        if (bVar3 == 0xf2) goto LAB_0019dac0;
LAB_0019da3c:
        if (0x3f < (int)n) {
          if (bVar3 == 0xf2) goto LAB_0019dad2;
          iVar7 = 1;
          goto LAB_0019d9a8;
        }
        iVar7 = 0;
        iVar2 = 0;
        if (iVar4 < inl) goto LAB_0019d9f8;
        goto LAB_0019da48;
      }
      uVar6 = (uint)(ctx->enc_data[n - 1] == '=');
      if (ctx->enc_data[n - 2] == '=') {
        uVar6 = uVar6 + 1;
      }
LAB_0019dac0:
      if ((n & 3) != 0) {
        bVar3 = 0xf2;
        goto LAB_0019da3c;
      }
LAB_0019dad2:
      if ((int)n < 1) {
        iVar7 = 0;
        iVar2 = 0;
        if (0 < ctx->length) {
          uVar6 = 0;
          goto LAB_0019da58;
        }
        uVar6 = 1;
      }
      else {
        iVar7 = 0;
LAB_0019d9a8:
        iVar2 = EVP_DecodeBlock(local_34,ctx->enc_data,n);
        if (iVar2 < 0) {
LAB_0019db40:
          uVar6 = 0;
          n = uVar6;
          goto LAB_0019da58;
        }
        if (iVar2 < (int)uVar6) {
          n = 0;
          break;
        }
        local_30 = local_30 + (iVar2 - uVar6);
        if (iVar2 < ctx->length) {
          if (uVar6 != 0) goto LAB_0019db40;
          n = 0;
        }
        else {
          n = 0;
        }
      }
      ctx->length = iVar2;
      if (-1 < (int)local_3c) {
        uVar6 = 0;
        goto LAB_0019da58;
      }
      local_34 = local_34 + iVar2;
      iVar2 = iVar7;
      if (inl <= iVar4) goto LAB_0019da48;
LAB_0019d9f8:
      in = in + 1;
    } while (iVar5 != 0x50);
LAB_0019da52:
    uVar6 = 0xffffffff;
  }
  else {
    local_30 = 0;
    uVar6 = 0xffffffff;
  }
LAB_0019da58:
  *outl = local_30;
  ctx->num = n;
  ctx->line_num = iVar5;
  ctx->expect_nl = iVar7;
  return uVar6;
}

