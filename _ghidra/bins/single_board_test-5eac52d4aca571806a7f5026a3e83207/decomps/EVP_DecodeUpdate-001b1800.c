
int EVP_DecodeUpdate(EVP_ENCODE_CTX *ctx,uchar *out,int *outl,uchar *in,int inl)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  int iVar6;
  uchar *puVar7;
  int iVar8;
  undefined1 *puVar9;
  
  puVar7 = ctx->enc_data;
  uVar4 = ctx->num;
  if (((int)uVar4 < 1) || (puVar7[uVar4 - 1] != '=')) {
    iVar6 = 0;
  }
  else if (uVar4 == 1) {
    iVar6 = 1;
  }
  else if (puVar7[uVar4 - 2] == '=') {
    iVar6 = 2;
  }
  else {
    iVar6 = 1;
  }
  iVar8 = inl;
  if (inl != 0) {
    if (ctx->expect_nl << 0x1e < 0) {
      puVar9 = srpdata_ascii2bin;
    }
    else {
      puVar9 = data_ascii2bin;
    }
    if (inl < 1) {
      iVar8 = 0;
LAB_001b191a:
      if ((0 < (int)uVar4) && (uVar2 = uVar4 & 3, uVar2 == 0)) {
LAB_001b18cc:
        iVar3 = evp_decodeblock_int(ctx,out,puVar7,uVar4);
        if (iVar3 < iVar6 || iVar3 < 0) {
LAB_001b1954:
          uVar4 = 0;
          inl = 0xffffffff;
          goto LAB_001b1898;
        }
        iVar8 = iVar8 + (iVar3 - iVar6);
        inl = 0;
        uVar4 = 0;
        if (uVar2 != 0) goto LAB_001b1898;
        uVar4 = 0;
      }
      inl = (int)(iVar6 == 0);
      if (uVar4 != 0) {
        inl = 1;
      }
    }
    else {
      uVar2 = (uint)*in;
      if (((int)(uVar2 << 0x18) < 0) || (bVar1 = puVar9[uVar2], bVar1 == 0xff)) {
        iVar8 = 0;
        inl = 0xffffffff;
      }
      else {
        iVar8 = 0;
        pbVar5 = in + 1;
        while( true ) {
          if (uVar2 == 0x3d) {
            iVar6 = iVar6 + 1;
            if (iVar6 == 3) goto LAB_001b1894;
          }
          else if ((iVar6 != 0) && ((bVar1 | 0x13) != 0xf3)) goto LAB_001b1894;
          if (bVar1 == 0xf2) break;
          if ((bVar1 | 0x13) != 0xf3) {
            if (0x3f < (int)uVar4) goto LAB_001b1894;
            puVar7[uVar4] = (uchar)uVar2;
            uVar4 = uVar4 + 1;
          }
          if (uVar4 == 0x40) {
            iVar3 = evp_decodeblock_int(ctx,out,puVar7,0x40);
            if (iVar3 < iVar6 || iVar3 < 0) goto LAB_001b1954;
            iVar8 = iVar8 + (iVar3 - iVar6);
            out = out + (iVar3 - iVar6);
            uVar4 = 0;
          }
          if (pbVar5 == in + inl) goto LAB_001b191a;
          uVar2 = (uint)*pbVar5;
          if (((int)(uVar2 << 0x18) < 0) ||
             (bVar1 = puVar9[uVar2], pbVar5 = pbVar5 + 1, bVar1 == 0xff)) goto LAB_001b1894;
        }
        if ((int)uVar4 < 1) {
          inl = 0;
          goto LAB_001b1898;
        }
        if ((uVar4 & 3) == 0) {
          uVar2 = 1;
          goto LAB_001b18cc;
        }
LAB_001b1894:
        inl = 0xffffffff;
      }
    }
  }
LAB_001b1898:
  *outl = iVar8;
  ctx->num = uVar4;
  return inl;
}

