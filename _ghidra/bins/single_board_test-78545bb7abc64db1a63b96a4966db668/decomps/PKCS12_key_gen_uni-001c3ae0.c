
int PKCS12_key_gen_uni(uchar *pass,int passlen,uchar *salt,int saltlen,int id,int iter,int n,
                      uchar *out,EVP_MD *md_type)

{
  EVP_MD_CTX *ctx;
  size_t cnt;
  size_t cnt_00;
  int iVar1;
  byte *pbVar2;
  int extraout_r1;
  int extraout_r1_00;
  int extraout_r1_01;
  uint uVar3;
  size_t sVar4;
  size_t sVar5;
  uchar *md;
  uchar *puVar6;
  uchar *puVar7;
  byte *ptr;
  int iVar8;
  uchar *d;
  byte *pbVar9;
  byte *pbVar10;
  void *local_4c;
  int local_40;
  uchar *local_3c;
  
  ctx = (EVP_MD_CTX *)EVP_MD_CTX_new();
  if (ctx != (EVP_MD_CTX *)0x0) {
    cnt = EVP_MD_block_size(md_type);
    cnt_00 = EVP_MD_size(md_type);
    sVar5 = cnt;
    if (0 < (int)cnt) {
      sVar5 = cnt_00;
    }
    if (0 < (int)sVar5) {
      local_4c = CRYPTO_malloc(cnt,"crypto/pkcs12/p12_key.c",0x6a);
      md = (uchar *)CRYPTO_malloc(cnt_00,"crypto/pkcs12/p12_key.c",0x6b);
      ptr = (byte *)CRYPTO_malloc(cnt + 1,"crypto/pkcs12/p12_key.c",0x6c);
      iVar8 = __aeabi_idiv(cnt + saltlen + -1,cnt);
      iVar8 = cnt * iVar8;
      if (passlen == 0) {
        local_40 = 0;
      }
      else {
        local_40 = __aeabi_idiv(cnt + passlen + -1,cnt);
        local_40 = cnt * local_40;
      }
      sVar5 = local_40 + iVar8;
      d = (uchar *)CRYPTO_malloc(sVar5,"crypto/pkcs12/p12_key.c",0x73);
      if ((md != (uchar *)0x0 && local_4c != (void *)0x0) &&
         (d != (uchar *)0x0 && ptr != (byte *)0x0)) {
        sVar4 = cnt;
        if ((int)cnt < 1) {
          sVar4 = 1;
        }
        memset(local_4c,id & 0xff,sVar4);
        local_3c = d;
        if (0 < iVar8) {
          local_3c = d + iVar8;
          puVar6 = d;
          do {
            __aeabi_idivmod((int)puVar6 - (int)d,saltlen);
            puVar7 = puVar6 + 1;
            *puVar6 = salt[extraout_r1];
            puVar6 = puVar7;
          } while (puVar7 != local_3c);
        }
        if (0 < local_40) {
          puVar6 = local_3c;
          do {
            __aeabi_idivmod((int)puVar6 - (int)local_3c,passlen);
            puVar7 = puVar6 + 1;
            *puVar6 = pass[extraout_r1_00];
            puVar6 = puVar7;
          } while (puVar7 != local_3c + local_40);
        }
        while ((((iVar8 = EVP_DigestInit_ex(ctx,md_type,(ENGINE *)0x0), iVar8 != 0 &&
                 (iVar8 = EVP_DigestUpdate(ctx,local_4c,cnt), iVar8 != 0)) &&
                (iVar8 = EVP_DigestUpdate(ctx,d,sVar5), iVar8 != 0)) &&
               (iVar8 = EVP_DigestFinal_ex(ctx,md,(uint *)0x0), iVar8 != 0))) {
          if (1 < iter) {
            iVar8 = 1;
            do {
              iVar8 = iVar8 + 1;
              iVar1 = EVP_DigestInit_ex(ctx,md_type,(ENGINE *)0x0);
              if (((iVar1 == 0) || (iVar1 = EVP_DigestUpdate(ctx,md,cnt_00), iVar1 == 0)) ||
                 (iVar1 = EVP_DigestFinal_ex(ctx,md,(uint *)0x0), iVar1 == 0)) goto LAB_001c3b16;
            } while (iter != iVar8);
          }
          sVar4 = n;
          if ((int)cnt_00 <= n) {
            sVar4 = cnt_00;
          }
          memcpy(out,md,sVar4);
          if (n <= (int)cnt_00) {
            iVar8 = 1;
            goto LAB_001c3b2a;
          }
          n = n - cnt_00;
          pbVar9 = ptr + -1;
          iVar8 = 0;
          out = out + cnt_00;
          do {
            __aeabi_idivmod(iVar8,cnt_00);
            iVar8 = iVar8 + 1;
            pbVar9 = pbVar9 + 1;
            *pbVar9 = md[extraout_r1_01];
          } while (iVar8 < (int)cnt);
          if (0 < (int)sVar5) {
            pbVar9 = d + (cnt - 1);
            do {
              uVar3 = 1;
              pbVar2 = pbVar9;
              pbVar10 = ptr + cnt;
              do {
                pbVar10 = pbVar10 + -1;
                iVar8 = *pbVar2 + uVar3 + (uint)*pbVar10;
                *pbVar2 = (byte)iVar8;
                uVar3 = (uint)(iVar8 * 0x100) >> 0x10;
                pbVar2 = pbVar2 + -1;
              } while (ptr != pbVar10);
              pbVar9 = pbVar9 + cnt;
            } while ((int)(pbVar9 + ((1 - cnt) - (int)d)) < (int)sVar5);
          }
        }
      }
      goto LAB_001c3b16;
    }
  }
  md = (uchar *)0x0;
  d = (uchar *)0x0;
  ptr = (byte *)0x0;
  local_4c = (void *)0x0;
LAB_001c3b16:
  iVar8 = 0;
  ERR_put_error(0x23,0x6f,0x41,"crypto/pkcs12/p12_key.c",0xa5);
LAB_001c3b2a:
  CRYPTO_free(md);
  CRYPTO_free(ptr);
  CRYPTO_free(local_4c);
  CRYPTO_free(d);
  EVP_MD_CTX_free(ctx);
  return iVar8;
}

