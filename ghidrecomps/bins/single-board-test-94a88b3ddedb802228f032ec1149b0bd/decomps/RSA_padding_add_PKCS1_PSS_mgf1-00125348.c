
int RSA_padding_add_PKCS1_PSS_mgf1
              (RSA *rsa,uchar *EM,uchar *mHash,EVP_MD *Hash,EVP_MD *mgf1Hash,int sLen)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  size_t cnt;
  int iVar4;
  uint *buf;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  int len;
  uint cnt_00;
  uint uVar9;
  uint *puVar10;
  uint *puVar11;
  byte *mask;
  uint uVar12;
  uint uVar13;
  byte *local_58;
  EVP_MD_CTX EStack_40;
  
  if (mgf1Hash == (EVP_MD *)0x0) {
    mgf1Hash = Hash;
  }
  cnt = EVP_MD_size(Hash);
  if ((int)cnt < 0) {
    return 0;
  }
  cnt_00 = cnt;
  if (sLen != -1) {
    cnt_00 = sLen;
    if ((sLen != -2) && (sLen + 2 < 0 != SCARRY4(sLen,2))) {
      ERR_put_error(4,0x94,0x88,DAT_00125654,0xd7);
      return 0;
    }
  }
  iVar4 = BN_num_bits(rsa->n);
  uVar12 = iVar4 - 1U & 7;
  iVar4 = RSA_size(rsa);
  mask = EM;
  if (uVar12 == 0) {
    iVar4 = iVar4 + -1;
    mask = EM + 1;
    *EM = '\0';
  }
  if (cnt_00 == 0xfffffffe) {
    cnt_00 = (iVar4 - cnt) - 2;
  }
  else if (iVar4 <= (int)(cnt + cnt_00 + 1)) {
    ERR_put_error(4,0x94,0x6e,DAT_00125654,0xe5);
    return 0;
  }
  if ((int)cnt_00 < 1) {
    buf = (uint *)0x0;
  }
  else {
    buf = (uint *)CRYPTO_malloc(cnt_00,DAT_00125654,0xe9);
    if (buf == (uint *)0x0) {
      ERR_put_error(4,0x94,0x41,DAT_00125654,0xec);
      return 0;
    }
    iVar5 = RAND_bytes((uchar *)buf,cnt_00);
    if (iVar5 < 1) {
      iVar5 = 0;
      goto LAB_001253e8;
    }
  }
  EVP_MD_CTX_init(&EStack_40);
  iVar5 = EVP_DigestInit_ex(&EStack_40,Hash,(ENGINE *)0x0);
  if ((((iVar5 == 0) || (iVar5 = EVP_DigestUpdate(&EStack_40,DAT_00125658,8), iVar5 == 0)) ||
      (iVar5 = EVP_DigestUpdate(&EStack_40,mHash,cnt), iVar5 == 0)) ||
     ((cnt_00 != 0 && (iVar5 = EVP_DigestUpdate(&EStack_40,buf,cnt_00), iVar5 == 0)))) {
LAB_001253e0:
    iVar5 = 0;
  }
  else {
    len = (iVar4 - cnt) + -1;
    iVar5 = EVP_DigestFinal_ex(&EStack_40,mask + len,(uint *)0x0);
    if (iVar5 == 0) goto LAB_001253e0;
    EVP_MD_CTX_cleanup(&EStack_40);
    iVar5 = PKCS1_MGF1(mask,len,mask + len,cnt,mgf1Hash);
    if (iVar5 != 0) goto LAB_001253e0;
    iVar5 = (iVar4 - cnt_00) - cnt;
    local_58 = mask + iVar5 + -1;
    mask[iVar5 + -2] = mask[iVar5 + -2] ^ 1;
    if (0 < (int)cnt_00) {
      puVar10 = (uint *)(mask + iVar5 + -1);
      uVar7 = cnt_00 >> 2;
      uVar8 = cnt_00 & 0xfffffffc;
      if (uVar7 == 0 ||
          ((((uint)puVar10 | (uint)buf) & 3) != 0 ||
          (cnt_00 < 4 || buf < mask + iVar5 + 3 && puVar10 < buf + 1))) {
        uVar8 = 0;
        uVar7 = uVar8;
      }
      else {
        if (uVar7 < 9) {
          uVar13 = 0;
          puVar6 = buf;
          puVar11 = puVar10;
        }
        else {
          uVar13 = 0;
          puVar2 = (uint *)(mask + iVar5 + 0x1f);
          puVar3 = (uint *)(mask + iVar5 + 0x1f);
          puVar1 = buf;
          do {
            puVar10 = puVar3;
            puVar11 = puVar2;
            puVar6 = puVar1 + 8;
            uVar9 = uVar13 + 9;
            uVar13 = uVar13 + 8;
            HintPreloadData(puVar11 + 0xc);
            puVar10[-8] = *puVar1 ^ puVar11[-8];
            puVar10[-7] = puVar1[1] ^ puVar11[-7];
            puVar10[-6] = puVar1[2] ^ puVar11[-6];
            puVar10[-5] = puVar1[3] ^ puVar11[-5];
            puVar10[-4] = puVar1[4] ^ puVar11[-4];
            puVar10[-3] = puVar1[5] ^ puVar11[-3];
            puVar10[-2] = puVar1[6] ^ puVar11[-2];
            puVar10[-1] = puVar1[7] ^ puVar11[-1];
            puVar2 = puVar11 + 8;
            puVar3 = puVar10 + 8;
            puVar1 = puVar6;
          } while (uVar9 < uVar7 - 7);
        }
        iVar5 = 0;
        do {
          uVar13 = uVar13 + 1;
          *(uint *)((int)puVar10 + iVar5) =
               *(uint *)((int)puVar11 + iVar5) ^ *(uint *)((int)puVar6 + iVar5);
          iVar5 = iVar5 + 4;
        } while (uVar13 < uVar7);
        local_58 = local_58 + uVar8;
        uVar7 = uVar8;
        if (cnt_00 == uVar8) goto LAB_0012560a;
      }
      do {
        local_58[uVar8 - uVar7] = local_58[uVar8 - uVar7] ^ *(byte *)((int)buf + uVar8);
        uVar8 = uVar8 + 1;
      } while ((int)uVar8 < (int)cnt_00);
    }
LAB_0012560a:
    if (uVar12 != 0) {
      *mask = (byte)(0xff >> (8 - uVar12 & 0xff)) & *mask;
    }
    iVar5 = 1;
    mask[iVar4 + -1] = 0xbc;
  }
  if (buf == (uint *)0x0) {
    return iVar5;
  }
LAB_001253e8:
  CRYPTO_free(buf);
  return iVar5;
}

