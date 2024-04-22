
int CMAC_Final(CMAC_CTX *ctx,uchar *out,size_t *poutlen)

{
  uchar *puVar1;
  uint inl;
  CMAC_CTX *pCVar2;
  uint uVar3;
  CMAC_CTX *pCVar4;
  CMAC_CTX *pCVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uchar *puVar10;
  uint uVar11;
  bool bVar12;
  bool bVar13;
  
  if (*(int *)(ctx + 0x10c) == -1) {
    return 0;
  }
  inl = EVP_CIPHER_CTX_block_size((EVP_CIPHER_CTX *)ctx);
  *poutlen = inl;
  if (out == (uchar *)0x0) {
    return 1;
  }
  uVar11 = *(uint *)(ctx + 0x10c);
  if (uVar11 == inl) {
    if (0 < (int)uVar11) {
      pCVar5 = (CMAC_CTX *)(out + 4);
      pCVar4 = ctx + 0xec;
      bVar13 = out <= ctx + 0xf0;
      bVar12 = ctx + 0xf0 == (CMAC_CTX *)out;
      if (bVar13 && !bVar12) {
        bVar13 = pCVar4 <= pCVar5;
        bVar12 = pCVar5 == pCVar4;
      }
      pCVar2 = ctx + 0x8c;
      uVar3 = uVar11 >> 2;
      uVar9 = uVar11 & 0xfffffffc;
      if (uVar3 == 0 ||
          ((uVar11 < 4 || (bVar13 && !bVar12 || ((uint)out & 3) != 0)) ||
          out < ctx + 0x90 && pCVar2 < pCVar5)) {
        uVar9 = 0;
      }
      else {
        if (uVar3 < 9) {
          uVar7 = 0;
          puVar10 = out;
        }
        else {
          uVar7 = 0;
          pCVar5 = ctx + 0x10c;
          puVar1 = out + 0x20;
          do {
            puVar10 = puVar1;
            pCVar4 = pCVar5;
            uVar8 = uVar7 + 9;
            uVar7 = uVar7 + 8;
            HintPreloadData(pCVar4 + 0x30);
            *(uint *)(puVar10 + -0x20) = *(uint *)(pCVar4 + -0x80) ^ *(uint *)(pCVar4 + -0x20);
            pCVar2 = pCVar4 + -0x60;
            *(uint *)(puVar10 + -0x1c) = *(uint *)(pCVar4 + -0x7c) ^ *(uint *)(pCVar4 + -0x1c);
            *(uint *)(puVar10 + -0x18) = *(uint *)(pCVar4 + -0x78) ^ *(uint *)(pCVar4 + -0x18);
            *(uint *)(puVar10 + -0x14) = *(uint *)(pCVar4 + -0x74) ^ *(uint *)(pCVar4 + -0x14);
            *(uint *)(puVar10 + -0x10) = *(uint *)(pCVar4 + -0x70) ^ *(uint *)(pCVar4 + -0x10);
            *(uint *)(puVar10 + -0xc) = *(uint *)(pCVar4 + -0x6c) ^ *(uint *)(pCVar4 + -0xc);
            *(uint *)(puVar10 + -8) = *(uint *)(pCVar4 + -0x68) ^ *(uint *)(pCVar4 + -8);
            *(uint *)(puVar10 + -4) = *(uint *)(pCVar4 + -100) ^ *(uint *)(pCVar4 + -4);
            pCVar5 = pCVar4 + 0x20;
            puVar1 = puVar10 + 0x20;
          } while (uVar8 < uVar3 - 7);
        }
        iVar6 = 0;
        do {
          uVar7 = uVar7 + 1;
          *(uint *)(puVar10 + iVar6) = *(uint *)(pCVar2 + iVar6) ^ *(uint *)(pCVar4 + iVar6);
          iVar6 = iVar6 + 4;
        } while (uVar7 < uVar3);
        if (uVar11 == uVar9) goto LAB_00111be0;
      }
      pCVar4 = ctx + uVar9 + 0xeb;
      do {
        out[uVar9] = (byte)pCVar4[1] ^ (byte)pCVar4[-0x5f];
        uVar9 = uVar9 + 1;
        pCVar4 = pCVar4 + 1;
      } while ((int)uVar9 < (int)uVar11);
    }
  }
  else {
    ctx[uVar11 + 0xec] = (CMAC_CTX)0x80;
    if (1 < (int)(inl - uVar11)) {
      memset(ctx + uVar11 + 0xed,0,(inl - uVar11) - 1);
    }
    if (0 < (int)inl) {
      pCVar4 = (CMAC_CTX *)(out + 4);
      pCVar5 = ctx + 0xec;
      bVar13 = out <= ctx + 0xf0;
      bVar12 = ctx + 0xf0 == (CMAC_CTX *)out;
      if (bVar13 && !bVar12) {
        bVar13 = pCVar5 <= pCVar4;
        bVar12 = pCVar4 == pCVar5;
      }
      pCVar2 = ctx + 0xac;
      uVar9 = inl >> 2;
      uVar11 = inl & 0xfffffffc;
      if (uVar9 == 0 ||
          (inl < 4 ||
          ((((uint)out & 3) != 0 || bVar13 && !bVar12) || out < ctx + 0xb0 && pCVar2 < pCVar4))) {
        uVar11 = 0;
      }
      else {
        if (uVar9 < 9) {
          uVar3 = 0;
          puVar10 = out;
        }
        else {
          uVar3 = 0;
          puVar1 = out + 0x20;
          pCVar4 = ctx + 0x10c;
          do {
            pCVar5 = pCVar4;
            puVar10 = puVar1;
            uVar7 = uVar3 + 9;
            uVar3 = uVar3 + 8;
            HintPreloadData(pCVar5 + 0x30);
            *(uint *)(puVar10 + -0x20) = *(uint *)(pCVar5 + -0x60) ^ *(uint *)(pCVar5 + -0x20);
            pCVar2 = pCVar5 + -0x40;
            *(uint *)(puVar10 + -0x1c) = *(uint *)(pCVar5 + -0x5c) ^ *(uint *)(pCVar5 + -0x1c);
            *(uint *)(puVar10 + -0x18) = *(uint *)(pCVar5 + -0x58) ^ *(uint *)(pCVar5 + -0x18);
            *(uint *)(puVar10 + -0x14) = *(uint *)(pCVar5 + -0x54) ^ *(uint *)(pCVar5 + -0x14);
            *(uint *)(puVar10 + -0x10) = *(uint *)(pCVar5 + -0x50) ^ *(uint *)(pCVar5 + -0x10);
            *(uint *)(puVar10 + -0xc) = *(uint *)(pCVar5 + -0xc) ^ *(uint *)(pCVar5 + -0x4c);
            *(uint *)(puVar10 + -8) = *(uint *)(pCVar5 + -8) ^ *(uint *)(pCVar5 + -0x48);
            *(uint *)(puVar10 + -4) = *(uint *)(pCVar5 + -4) ^ *(uint *)(pCVar5 + -0x44);
            puVar1 = puVar10 + 0x20;
            pCVar4 = pCVar5 + 0x20;
          } while (uVar7 < uVar9 - 7);
        }
        iVar6 = 0;
        do {
          uVar3 = uVar3 + 1;
          *(uint *)(puVar10 + iVar6) = *(uint *)(pCVar5 + iVar6) ^ *(uint *)(pCVar2 + iVar6);
          iVar6 = iVar6 + 4;
        } while (uVar3 < uVar9);
        if (inl == uVar11) goto LAB_00111be0;
      }
      pCVar4 = ctx + uVar11 + 0xeb;
      do {
        out[uVar11] = (byte)pCVar4[1] ^ (byte)pCVar4[-0x3f];
        uVar11 = uVar11 + 1;
        pCVar4 = pCVar4 + 1;
      } while ((int)uVar11 < (int)inl);
    }
  }
LAB_00111be0:
  iVar6 = EVP_Cipher((EVP_CIPHER_CTX *)ctx,out,out,inl);
  if (iVar6 != 0) {
    return 1;
  }
  OPENSSL_cleanse(out,inl);
  return 0;
}

