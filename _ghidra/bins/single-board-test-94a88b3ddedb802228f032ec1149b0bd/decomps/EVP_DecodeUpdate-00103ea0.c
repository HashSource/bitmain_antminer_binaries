
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
          if (bVar3 == 0xff) goto LAB_00103fa6;
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
        if ((bVar3 != 0xf0) || (iVar5 = iVar7, iVar7 == 0)) goto joined_r0x00103f8a;
        iVar7 = 0;
LAB_00103fc8:
        iVar5 = 0;
        in = in + 1;
        iVar2 = iVar7;
        if (inl <= iVar4) {
LAB_00103f9c:
          iVar7 = iVar2;
          uVar6 = 1;
          goto LAB_00103fac;
        }
      }
      iVar5 = iVar7;
      if (iVar7 != 0) goto LAB_00103fc8;
joined_r0x00103f8a:
      if ((inl != iVar4) || (((n & 3) != 0 && (uVar6 == 0)))) {
        if (bVar3 == 0xf2) goto LAB_00104014;
LAB_00103f90:
        if (0x3f < (int)n) {
          if (bVar3 == 0xf2) goto LAB_00104026;
          iVar7 = 1;
          goto LAB_00103efc;
        }
        iVar7 = 0;
        iVar2 = 0;
        if (iVar4 < inl) goto LAB_00103f4c;
        goto LAB_00103f9c;
      }
      uVar6 = (uint)(ctx->enc_data[n - 1] == '=');
      if (ctx->enc_data[n - 2] == '=') {
        uVar6 = uVar6 + 1;
      }
LAB_00104014:
      if ((n & 3) != 0) {
        bVar3 = 0xf2;
        goto LAB_00103f90;
      }
LAB_00104026:
      if ((int)n < 1) {
        iVar7 = 0;
        iVar2 = 0;
        if (0 < ctx->length) {
          uVar6 = 0;
          goto LAB_00103fac;
        }
        uVar6 = 1;
      }
      else {
        iVar7 = 0;
LAB_00103efc:
        iVar2 = EVP_DecodeBlock(local_34,ctx->enc_data,n);
        if (iVar2 < 0) {
LAB_00104094:
          uVar6 = 0;
          n = uVar6;
          goto LAB_00103fac;
        }
        if (iVar2 < (int)uVar6) {
          n = 0;
          break;
        }
        local_30 = local_30 + (iVar2 - uVar6);
        if (iVar2 < ctx->length) {
          if (uVar6 != 0) goto LAB_00104094;
          n = 0;
        }
        else {
          n = 0;
        }
      }
      ctx->length = iVar2;
      if (-1 < (int)local_3c) {
        uVar6 = 0;
        goto LAB_00103fac;
      }
      local_34 = local_34 + iVar2;
      iVar2 = iVar7;
      if (inl <= iVar4) goto LAB_00103f9c;
LAB_00103f4c:
      in = in + 1;
    } while (iVar5 != 0x50);
LAB_00103fa6:
    uVar6 = 0xffffffff;
  }
  else {
    local_30 = 0;
    uVar6 = 0xffffffff;
  }
LAB_00103fac:
  *outl = local_30;
  ctx->num = n;
  ctx->line_num = iVar5;
  ctx->expect_nl = iVar7;
  return uVar6;
}

