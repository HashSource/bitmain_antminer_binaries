
int CMAC_Final(CMAC_CTX *ctx,uchar *out,size_t *poutlen)

{
  uint inl;
  byte *pbVar1;
  CMAC_CTX *pCVar2;
  CMAC_CTX *pCVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;
  bool bVar7;
  
  if (*(int *)(ctx + 0x84) == -1) {
    iVar5 = 0;
  }
  else {
    inl = EVP_CIPHER_CTX_block_size(*(EVP_CIPHER_CTX **)ctx);
    *poutlen = inl;
    if (out != (uchar *)0x0) {
      uVar4 = *(uint *)(ctx + 0x84);
      if (inl == uVar4) {
        if (0 < (int)inl) {
          if (inl < 6 || (((uint)out & 3) != 0 || ctx < out && out < ctx + 0x68)) {
            pCVar3 = ctx + 3;
            pbVar1 = out + -1;
            pCVar2 = ctx + 99;
            do {
              pCVar3 = pCVar3 + 1;
              pCVar2 = pCVar2 + 1;
              pbVar1 = pbVar1 + 1;
              *pbVar1 = (byte)*pCVar3 ^ (byte)*pCVar2;
            } while (pCVar3 != ctx + inl + 3);
          }
          else {
            iVar5 = (inl - 4 >> 2) + 1;
            *(uint *)out = *(uint *)(ctx + 100) ^ *(uint *)(ctx + 4);
            uVar4 = iVar5 * 4;
            if ((((iVar5 != 1) &&
                 (*(uint *)(out + 4) = *(uint *)(ctx + 8) ^ *(uint *)(ctx + 0x68), iVar5 != 2)) &&
                (*(uint *)(out + 8) = *(uint *)(ctx + 0xc) ^ *(uint *)(ctx + 0x6c), iVar5 != 3)) &&
               (((*(uint *)(out + 0xc) = *(uint *)(ctx + 0x10) ^ *(uint *)(ctx + 0x70), iVar5 != 4
                 && (*(uint *)(out + 0x10) = *(uint *)(ctx + 0x14) ^ *(uint *)(ctx + 0x74),
                    iVar5 != 5)) &&
                ((*(uint *)(out + 0x14) = *(uint *)(ctx + 0x18) ^ *(uint *)(ctx + 0x78), iVar5 != 6
                 && (*(uint *)(out + 0x18) = *(uint *)(ctx + 0x1c) ^ *(uint *)(ctx + 0x7c),
                    iVar5 != 7)))))) {
              *(uint *)(out + 0x1c) = *(uint *)(ctx + 0x20) ^ *(uint *)(ctx + 0x80);
            }
            if (inl != uVar4) {
              out[iVar5 * 4] = (byte)ctx[uVar4 + 4] ^ (byte)ctx[uVar4 + 100];
              if ((int)(uVar4 + 1) < (int)inl) {
                out[uVar4 + 1] = (byte)ctx[uVar4 + 5] ^ (byte)ctx[uVar4 + 0x65];
                if ((int)(uVar4 + 2) < (int)inl) {
                  out[uVar4 + 2] = (byte)ctx[uVar4 + 6] ^ (byte)ctx[uVar4 + 0x66];
                }
              }
            }
          }
        }
      }
      else {
        ctx[uVar4 + 100] = (CMAC_CTX)0x80;
        if (1 < (int)(inl - uVar4)) {
          memset(ctx + uVar4 + 0x65,0,(inl - uVar4) - 1);
        }
        if (0 < (int)inl) {
          bVar7 = out <= ctx + 0x68;
          bVar6 = ctx + 0x68 == (CMAC_CTX *)out;
          if (bVar7 && !bVar6) {
            bVar7 = ctx + 0x24 <= (CMAC_CTX *)(out + 4);
            bVar6 = (CMAC_CTX *)(out + 4) == ctx + 0x24;
          }
          if (inl < 6 || (((uint)out & 3) != 0 || bVar7 && !bVar6)) {
            pCVar3 = ctx + 0x23;
            pbVar1 = out + -1;
            pCVar2 = ctx + 99;
            do {
              pCVar3 = pCVar3 + 1;
              pCVar2 = pCVar2 + 1;
              pbVar1 = pbVar1 + 1;
              *pbVar1 = (byte)*pCVar3 ^ (byte)*pCVar2;
            } while (pCVar3 != ctx + inl + 0x23);
          }
          else {
            iVar5 = (inl - 4 >> 2) + 1;
            *(uint *)out = *(uint *)(ctx + 100) ^ *(uint *)(ctx + 0x24);
            uVar4 = iVar5 * 4;
            if ((((iVar5 != 1) &&
                 (*(uint *)(out + 4) = *(uint *)(ctx + 0x28) ^ *(uint *)(ctx + 0x68), iVar5 != 2))
                && ((*(uint *)(out + 8) = *(uint *)(ctx + 0x2c) ^ *(uint *)(ctx + 0x6c), iVar5 != 3
                    && (((*(uint *)(out + 0xc) = *(uint *)(ctx + 0x30) ^ *(uint *)(ctx + 0x70),
                         iVar5 != 4 &&
                         (*(uint *)(out + 0x10) = *(uint *)(ctx + 0x34) ^ *(uint *)(ctx + 0x74),
                         iVar5 != 5)) &&
                        (*(uint *)(out + 0x14) = *(uint *)(ctx + 0x38) ^ *(uint *)(ctx + 0x78),
                        iVar5 != 6)))))) &&
               (*(uint *)(out + 0x18) = *(uint *)(ctx + 0x3c) ^ *(uint *)(ctx + 0x7c), iVar5 != 7))
            {
              *(uint *)(out + 0x1c) = *(uint *)(ctx + 0x40) ^ *(uint *)(ctx + 0x80);
            }
            if (inl != uVar4) {
              out[iVar5 * 4] = (byte)ctx[uVar4 + 0x24] ^ (byte)ctx[uVar4 + 100];
              if ((int)(uVar4 + 1) < (int)inl) {
                out[uVar4 + 1] = (byte)ctx[uVar4 + 0x25] ^ (byte)ctx[uVar4 + 0x65];
                if ((int)(uVar4 + 2) < (int)inl) {
                  out[uVar4 + 2] = (byte)ctx[uVar4 + 0x26] ^ (byte)ctx[uVar4 + 0x66];
                }
              }
            }
          }
        }
      }
      iVar5 = EVP_Cipher(*(EVP_CIPHER_CTX **)ctx,out,out,inl);
      if (iVar5 == 0) {
        OPENSSL_cleanse(out,inl);
        return 0;
      }
    }
    iVar5 = 1;
  }
  return iVar5;
}

