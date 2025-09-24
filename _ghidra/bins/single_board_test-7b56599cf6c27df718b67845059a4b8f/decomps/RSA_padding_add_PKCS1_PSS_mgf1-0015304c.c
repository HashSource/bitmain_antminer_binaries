
int RSA_padding_add_PKCS1_PSS_mgf1
              (RSA *rsa,uchar *EM,uchar *mHash,EVP_MD *Hash,EVP_MD *mgf1Hash,int sLen)

{
  EVP_MD_CTX *pEVar1;
  uint *puVar2;
  uint *puVar3;
  size_t cnt;
  int iVar4;
  int iVar5;
  EVP_MD_CTX *ctx;
  EVP_MD_CTX *pEVar6;
  uint *puVar7;
  byte *pbVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  _func_1230 **pp_Var12;
  EVP_MD_CTX *buf;
  uint uVar13;
  uint uVar14;
  uint *puVar15;
  uint *puVar16;
  uint uVar17;
  
  if (mgf1Hash == (EVP_MD *)0x0) {
    mgf1Hash = Hash;
  }
  cnt = EVP_MD_size(Hash);
  if ((int)cnt < 0) {
    buf = (EVP_MD_CTX *)0x0;
    pEVar6 = buf;
    ctx = buf;
    goto LAB_00153102;
  }
  uVar9 = cnt;
  if (sLen == -1) {
LAB_00153088:
    sLen = uVar9;
    iVar4 = BN_num_bits(rsa->n);
    uVar9 = iVar4 - 1U & 7;
    iVar4 = RSA_size(rsa);
    if (uVar9 == 0) {
      iVar4 = iVar4 + -1;
      *EM = '\0';
      EM = EM + 1;
      if ((int)(cnt + 1) < iVar4) goto LAB_001530ac;
LAB_00153132:
      iVar4 = 0xbb;
    }
    else {
      if (iVar4 <= (int)(cnt + 1)) goto LAB_00153132;
LAB_001530ac:
      iVar10 = iVar4 - cnt;
      if (sLen == 0xfffffffd) {
        sLen = iVar10 - 2;
LAB_001530c2:
        if (sLen < 1) {
          buf = (EVP_MD_CTX *)0x0;
        }
        else {
          buf = (EVP_MD_CTX *)CRYPTO_malloc(sLen,"crypto/rsa/rsa_pss.c",0xc6);
          if (buf == (EVP_MD_CTX *)0x0) {
            ERR_put_error(4,0x98,0x41,"crypto/rsa/rsa_pss.c",0xc9);
            pEVar6 = (EVP_MD_CTX *)0x0;
            ctx = (EVP_MD_CTX *)0x0;
            goto LAB_00153102;
          }
          iVar5 = RAND_bytes((uchar *)buf,sLen);
          if (iVar5 < 1) {
            pEVar6 = (EVP_MD_CTX *)0x0;
            ctx = (EVP_MD_CTX *)0x0;
            goto LAB_00153102;
          }
        }
        ctx = (EVP_MD_CTX *)EVP_MD_CTX_new();
        pEVar6 = ctx;
        if (((((ctx != (EVP_MD_CTX *)0x0) &&
              (pEVar6 = (EVP_MD_CTX *)EVP_DigestInit_ex(ctx,Hash,(ENGINE *)0x0),
              pEVar6 != (EVP_MD_CTX *)0x0)) &&
             (pEVar6 = (EVP_MD_CTX *)EVP_DigestUpdate(ctx,&zeroes,8), pEVar6 != (EVP_MD_CTX *)0x0))
            && (pEVar6 = (EVP_MD_CTX *)EVP_DigestUpdate(ctx,mHash,cnt), pEVar6 != (EVP_MD_CTX *)0x0)
            ) && ((sLen == 0 ||
                  (pEVar6 = (EVP_MD_CTX *)EVP_DigestUpdate(ctx,buf,sLen),
                  pEVar6 != (EVP_MD_CTX *)0x0)))) {
          pEVar6 = (EVP_MD_CTX *)EVP_DigestFinal_ex(ctx,EM + iVar10 + -1,(uint *)0x0);
          if (pEVar6 != (EVP_MD_CTX *)0x0) {
            iVar10 = PKCS1_MGF1(EM,iVar10 + -1,EM + iVar10 + -1,cnt,mgf1Hash);
            pEVar6 = (EVP_MD_CTX *)0x0;
            if (iVar10 == 0) {
              iVar10 = (iVar4 - sLen) - cnt;
              EM[iVar10 + -2] = EM[iVar10 + -2] ^ 1;
              if (0 < sLen) {
                puVar15 = (uint *)(EM + iVar10 + -1);
                if ((((uint)buf | (uint)puVar15) & 3) == 0 &&
                    (6 < (uint)sLen &&
                    (&buf->engine <= puVar15 || (EVP_MD_CTX *)(EM + iVar10 + 3) <= buf))) {
                  uVar11 = sLen - 4U >> 2;
                  uVar14 = uVar11 + 1;
                  iVar10 = uVar11 * 4;
                  if (uVar11 - 8 < 0xfffffff7) {
                    uVar13 = (uVar11 - 8 & 0xfffffff8) + 8;
                    uVar17 = 0;
                    puVar2 = puVar15 + 8;
                    puVar3 = puVar15 + 8;
                    pEVar1 = buf;
                    do {
                      puVar16 = puVar3;
                      puVar7 = puVar2;
                      pEVar6 = (EVP_MD_CTX *)&pEVar1[1].flags;
                      uVar17 = uVar17 + 8;
                      HintPreloadData(puVar7 + 0xc);
                      puVar16[-8] = puVar7[-8] ^ (uint)pEVar1->digest;
                      puVar16[-7] = puVar7[-7] ^ (uint)pEVar1->engine;
                      puVar16[-6] = puVar7[-6] ^ pEVar1->flags;
                      puVar16[-5] = puVar7[-5] ^ (uint)pEVar1->md_data;
                      puVar16[-4] = puVar7[-4] ^ (uint)pEVar1->pctx;
                      puVar16[-3] = puVar7[-3] ^ (uint)pEVar1->update;
                      puVar16[-2] = puVar7[-2] ^ (uint)pEVar1[1].digest;
                      puVar16[-1] = puVar7[-1] ^ (uint)pEVar1[1].engine;
                      puVar2 = puVar7 + 8;
                      puVar3 = puVar16 + 8;
                      pEVar1 = pEVar6;
                    } while (uVar17 != uVar13);
                  }
                  else {
                    uVar13 = 0;
                    puVar16 = puVar15;
                    puVar7 = puVar15;
                    pEVar6 = buf;
                  }
                  puVar7 = puVar7 + -1;
                  pp_Var12 = &pEVar6[-1].update;
                  do {
                    puVar7 = puVar7 + 1;
                    uVar13 = uVar13 + 1;
                    pp_Var12 = pp_Var12 + 1;
                    *puVar16 = (uint)*pp_Var12 ^ *puVar7;
                    puVar16 = puVar16 + 1;
                  } while (uVar13 < uVar14);
                  if (((sLen != iVar10 + 4U) &&
                      (*(byte *)(puVar15 + uVar14) =
                            (byte)puVar15[uVar14] ^ *(byte *)(&buf->engine + uVar11),
                      iVar10 + 5 < sLen)) &&
                     (*(byte *)((int)puVar15 + iVar10 + 5) =
                           *(byte *)((int)puVar15 + iVar10 + 5) ^
                           *(byte *)((int)&buf->engine + iVar10 + 1), iVar10 + 6 < sLen)) {
                    *(byte *)((int)puVar15 + iVar10 + 6) =
                         *(byte *)((int)puVar15 + iVar10 + 6) ^
                         *(byte *)((int)&buf->engine + iVar10 + 2);
                  }
                }
                else {
                  pbVar8 = (byte *)((int)&buf[-1].update + 3);
                  puVar7 = puVar15;
                  do {
                    pbVar8 = pbVar8 + 1;
                    puVar16 = (uint *)((int)puVar7 + 1);
                    *(byte *)puVar7 = *pbVar8 ^ (byte)*puVar7;
                    puVar7 = puVar16;
                  } while ((uint *)((int)puVar15 + sLen) != puVar16);
                }
              }
              if (uVar9 != 0) {
                *EM = (byte)(0xff >> (8 - uVar9 & 0xff)) & *EM;
              }
              EM[iVar4 + -1] = 0xbc;
              pEVar6 = (EVP_MD_CTX *)0x1;
            }
          }
        }
        goto LAB_00153102;
      }
      if (sLen < iVar10 + -1) goto LAB_001530c2;
      iVar4 = 0xc2;
    }
    iVar10 = 0x6e;
  }
  else {
    if (sLen == -2) {
      uVar9 = 0xfffffffd;
      goto LAB_00153088;
    }
    uVar9 = sLen;
    if (sLen + 3 < 0 == SCARRY4(sLen,3)) goto LAB_00153088;
    iVar4 = 0xaf;
    iVar10 = 0x88;
  }
  pEVar6 = (EVP_MD_CTX *)0x0;
  buf = (EVP_MD_CTX *)0x0;
  ERR_put_error(4,0x98,iVar10,"crypto/rsa/rsa_pss.c",iVar4);
  ctx = pEVar6;
LAB_00153102:
  EVP_MD_CTX_free(ctx);
  CRYPTO_clear_free(buf,sLen,"crypto/rsa/rsa_pss.c",0xf8);
  return (int)pEVar6;
}

