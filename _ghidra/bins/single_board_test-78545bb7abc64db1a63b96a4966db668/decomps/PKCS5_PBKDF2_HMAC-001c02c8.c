
int PKCS5_PBKDF2_HMAC(char *pass,int passlen,uchar *salt,int saltlen,int iter,EVP_MD *digest,
                     int keylen,uchar *out)

{
  size_t len;
  HMAC_CTX *ctx;
  int iVar1;
  HMAC_CTX *dctx;
  uint *puVar2;
  uint *puVar3;
  int extraout_r1;
  int iVar4;
  uint uVar5;
  int iVar6;
  size_t __n;
  int iVar7;
  int iVar8;
  byte *pbVar9;
  int local_80;
  uchar local_6c;
  undefined1 local_6b;
  undefined1 local_6a;
  byte local_69;
  undefined4 local_68;
  uint local_64;
  uint local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  
  len = EVP_MD_size(digest);
  if (-1 < (int)len) {
    ctx = (HMAC_CTX *)HMAC_CTX_new();
    if (ctx != (HMAC_CTX *)0x0) {
      if (pass == (char *)0x0) {
        pass = "";
        passlen = 0;
      }
      else if (passlen == -1) {
        passlen = strlen(pass);
      }
      iVar1 = HMAC_Init_ex(ctx,pass,passlen,digest,(ENGINE *)0x0);
      if (iVar1 == 0) {
LAB_001c0562:
        HMAC_CTX_free(ctx);
      }
      else {
        dctx = (HMAC_CTX *)HMAC_CTX_new();
        if (dctx == (HMAC_CTX *)0x0) {
          HMAC_CTX_free(ctx);
          iVar1 = 0;
        }
        else {
          if (keylen != 0) {
            local_80 = 1;
            do {
              local_69 = (byte)local_80;
              local_6a = (undefined1)((uint)local_80 >> 8);
              local_6c = (uchar)((uint)local_80 >> 0x18);
              local_6b = (undefined1)((uint)local_80 >> 0x10);
              __n = keylen;
              if ((int)len <= keylen) {
                __n = len;
              }
              iVar1 = HMAC_CTX_copy(dctx,ctx);
              if (iVar1 == 0) {
LAB_001c055a:
                HMAC_CTX_free(dctx);
                goto LAB_001c0562;
              }
              iVar1 = HMAC_Update(dctx,salt,saltlen);
              if (((iVar1 == 0) || (iVar1 = HMAC_Update(dctx,&local_6c,4), iVar1 == 0)) ||
                 (iVar1 = HMAC_Final(dctx,(uchar *)&local_68,(uint *)0x0), iVar1 == 0)) {
LAB_001c05c0:
                HMAC_CTX_free(dctx);
                HMAC_CTX_free(ctx);
                return 0;
              }
              memcpy(out,&local_68,__n);
              if (1 < iter) {
                iVar4 = extraout_r1;
                if (__n < 6) {
                  iVar4 = 0;
                }
                iVar8 = (__n - 4 >> 2) + 1;
                if (5 < __n) {
                  iVar4 = 1;
                }
                if (((uint)out & 3) != 0) {
                  iVar4 = 0;
                }
                iVar7 = 1;
                do {
                  while( true ) {
                    iVar1 = HMAC_CTX_copy(dctx,ctx);
                    if (iVar1 == 0) goto LAB_001c055a;
                    iVar1 = HMAC_Update(dctx,(uchar *)&local_68,len);
                    if ((iVar1 == 0) ||
                       (iVar1 = HMAC_Final(dctx,(uchar *)&local_68,(uint *)0x0), iVar1 == 0))
                    goto LAB_001c05c0;
                    if (0 < (int)__n) break;
LAB_001c0516:
                    iVar7 = iVar7 + 1;
                    if (iter == iVar7) goto LAB_001c0590;
                  }
                  if (iVar4 != 0) {
                    if (__n - 1 < 3) {
                      uVar5 = 0;
                    }
                    else {
                      *(uint *)out = *(uint *)out ^ local_68;
                      if (((((iVar8 != 1) &&
                            (*(uint *)((int)out + 4) = *(uint *)((int)out + 4) ^ local_64,
                            iVar8 != 2)) &&
                           ((*(uint *)((int)out + 8) = *(uint *)((int)out + 8) ^ local_60,
                            iVar8 != 3 &&
                            (((*(uint *)((int)out + 0xc) = *(uint *)((int)out + 0xc) ^ local_5c,
                              iVar8 != 4 &&
                              (*(uint *)((int)out + 0x10) = *(uint *)((int)out + 0x10) ^ local_58,
                              iVar8 != 5)) &&
                             (*(uint *)((int)out + 0x14) = *(uint *)((int)out + 0x14) ^ local_54,
                             iVar8 != 6)))))) &&
                          ((*(uint *)((int)out + 0x18) = *(uint *)((int)out + 0x18) ^ local_50,
                           iVar8 != 7 &&
                           (*(uint *)((int)out + 0x1c) = local_4c ^ *(uint *)((int)out + 0x1c),
                           iVar8 != 8)))) &&
                         ((*(uint *)((int)out + 0x20) = local_48 ^ *(uint *)((int)out + 0x20),
                          iVar8 != 9 &&
                          (((*(uint *)((int)out + 0x24) = local_44 ^ *(uint *)((int)out + 0x24),
                            iVar8 != 10 &&
                            (*(uint *)((int)out + 0x28) = local_40 ^ *(uint *)((int)out + 0x28),
                            iVar8 != 0xb)) &&
                           ((*(uint *)((int)out + 0x2c) = local_3c ^ *(uint *)((int)out + 0x2c),
                            iVar8 != 0xc &&
                            (((*(uint *)((int)out + 0x30) = local_38 ^ *(uint *)((int)out + 0x30),
                              iVar8 != 0xd &&
                              (*(uint *)((int)out + 0x34) = local_34 ^ *(uint *)((int)out + 0x34),
                              iVar8 != 0xe)) &&
                             (*(uint *)((int)out + 0x38) = local_30 ^ *(uint *)((int)out + 0x38),
                             iVar8 != 0xf)))))))))) {
                        *(uint *)((int)out + 0x3c) = local_2c ^ *(uint *)((int)out + 0x3c);
                      }
                      uVar5 = iVar8 * 4;
                      if (__n == iVar8 * 4) goto LAB_001c0516;
                    }
                    iVar1 = uVar5 + 1;
                    *(byte *)((int)out + uVar5) =
                         *(byte *)((int)out + uVar5) ^ *(byte *)((int)&local_68 + uVar5);
                    if (iVar1 < (int)__n) {
                      iVar6 = uVar5 + 2;
                      *(byte *)((int)out + iVar1) =
                           *(byte *)((int)out + iVar1) ^ *(byte *)((int)&local_68 + uVar5 + 1);
                      if (iVar6 < (int)__n) {
                        *(byte *)((int)out + iVar6) =
                             *(byte *)((int)&local_68 + uVar5 + 2) ^ *(byte *)((int)out + iVar6);
                      }
                    }
                    goto LAB_001c0516;
                  }
                  pbVar9 = &local_69;
                  puVar2 = (uint *)out;
                  do {
                    pbVar9 = pbVar9 + 1;
                    puVar3 = (uint *)((int)puVar2 + 1);
                    *(byte *)puVar2 = (byte)*puVar2 ^ *pbVar9;
                    puVar2 = puVar3;
                  } while (puVar3 != (uint *)((int)out + __n));
                  iVar7 = iVar7 + 1;
                } while (iter != iVar7);
              }
LAB_001c0590:
              out = (uchar *)((int)out + __n);
              local_80 = local_80 + 1;
              keylen = keylen - __n;
            } while (keylen != 0);
          }
          iVar1 = 1;
          HMAC_CTX_free(dctx);
          HMAC_CTX_free(ctx);
        }
      }
      return iVar1;
    }
  }
  return 0;
}

