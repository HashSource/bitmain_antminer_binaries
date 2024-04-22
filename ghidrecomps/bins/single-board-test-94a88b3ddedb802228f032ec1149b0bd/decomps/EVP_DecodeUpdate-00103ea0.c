
int EVP_DecodeUpdate(EVP_ENCODE_CTX *ctx,uchar *out,int *outl,uchar *in,int inl)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint n;
  byte bVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint local_3c;
  uchar *local_34;
  int local_30;
  
  iVar2 = DAT_001040c0;
  n = ctx->num;
  iVar6 = ctx->line_num;
  iVar8 = ctx->expect_nl;
  if (inl == 0) {
    uVar7 = 0;
    local_30 = 0;
  }
  else if ((n == 0) && (*(char *)(DAT_001040c0 + (*in & 0x7f) + 0x44) == -0xe)) {
    uVar7 = 0;
    local_30 = 0;
  }
  else if (inl < 1) {
    local_30 = 0;
    uVar7 = 1;
  }
  else if (iVar6 < 0x50) {
    iVar5 = 0;
    local_3c = 0xffffffff;
    uVar7 = 0;
    local_30 = 0;
    local_34 = out;
    do {
      while( true ) {
        bVar1 = *in;
        iVar5 = iVar5 + 1;
        bVar4 = *(byte *)(iVar2 + (bVar1 & 0x7f) + 0x44);
        if ((bVar4 | 0x13) == 0xf3) {
          if (bVar4 == 0xff) goto LAB_00103fa6;
        }
        else {
          if (0x4f < (int)n) {
            OpenSSLDie(DAT_001040c4,0x106,DAT_001040c8);
          }
          iVar6 = iVar6 + 1;
          ctx->enc_data[n] = bVar1;
          n = n + 1;
        }
        if ((bVar1 == 0x3d) && (uVar7 = uVar7 + 1, local_3c == 0xffffffff)) {
          local_3c = n;
        }
        if (bVar4 == 0xf1) break;
        if ((bVar4 != 0xf0) || (iVar6 = iVar8, iVar8 == 0)) goto joined_r0x00103f8a;
        iVar8 = 0;
LAB_00103fc8:
        iVar6 = 0;
        in = in + 1;
        iVar3 = iVar8;
        if (inl <= iVar5) {
LAB_00103f9c:
          iVar8 = iVar3;
          uVar7 = 1;
          goto LAB_00103fac;
        }
      }
      iVar6 = iVar8;
      if (iVar8 != 0) goto LAB_00103fc8;
joined_r0x00103f8a:
      if ((inl != iVar5) || (((n & 3) != 0 && (uVar7 == 0)))) {
        if (bVar4 == 0xf2) goto LAB_00104014;
LAB_00103f90:
        if (0x3f < (int)n) {
          if (bVar4 == 0xf2) goto LAB_00104026;
          iVar8 = 1;
          goto LAB_00103efc;
        }
        iVar8 = 0;
        iVar3 = 0;
        if (iVar5 < inl) goto LAB_00103f4c;
        goto LAB_00103f9c;
      }
      uVar7 = (uint)(ctx->enc_data[n - 1] == '=');
      if (ctx->enc_data[n - 2] == '=') {
        uVar7 = uVar7 + 1;
      }
LAB_00104014:
      if ((n & 3) != 0) {
        bVar4 = 0xf2;
        goto LAB_00103f90;
      }
LAB_00104026:
      if ((int)n < 1) {
        iVar8 = 0;
        iVar3 = 0;
        if (0 < ctx->length) {
          uVar7 = 0;
          goto LAB_00103fac;
        }
        uVar7 = 1;
      }
      else {
        iVar8 = 0;
LAB_00103efc:
        iVar3 = EVP_DecodeBlock(local_34,ctx->enc_data,n);
        if (iVar3 < 0) {
LAB_00104094:
          uVar7 = 0;
          n = uVar7;
          goto LAB_00103fac;
        }
        if (iVar3 < (int)uVar7) {
          n = 0;
          break;
        }
        local_30 = local_30 + (iVar3 - uVar7);
        if (iVar3 < ctx->length) {
          if (uVar7 != 0) goto LAB_00104094;
          n = 0;
        }
        else {
          n = 0;
        }
      }
      ctx->length = iVar3;
      if (-1 < (int)local_3c) {
        uVar7 = 0;
        goto LAB_00103fac;
      }
      local_34 = local_34 + iVar3;
      iVar3 = iVar8;
      if (inl <= iVar5) goto LAB_00103f9c;
LAB_00103f4c:
      in = in + 1;
    } while (iVar6 != 0x50);
LAB_00103fa6:
    uVar7 = 0xffffffff;
  }
  else {
    local_30 = 0;
    uVar7 = 0xffffffff;
  }
LAB_00103fac:
  *outl = local_30;
  ctx->num = n;
  ctx->line_num = iVar6;
  ctx->expect_nl = iVar8;
  return uVar7;
}

