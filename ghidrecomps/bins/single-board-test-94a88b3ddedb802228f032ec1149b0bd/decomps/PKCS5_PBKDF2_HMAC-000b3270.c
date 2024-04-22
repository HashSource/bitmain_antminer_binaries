
/* WARNING: Type propagation algorithm not settling */

int PKCS5_PBKDF2_HMAC(char *pass,int passlen,uchar *salt,int saltlen,int iter,EVP_MD *digest,
                     int keylen,uchar *out)

{
  uint *puVar1;
  size_t len;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  uint __n;
  uint uVar9;
  bool bVar10;
  int local_238;
  int local_220;
  uint local_21c;
  uchar local_20c;
  undefined local_20b;
  undefined local_20a;
  undefined local_209;
  uint auStack_208 [16];
  HMAC_CTX HStack_1c8;
  HMAC_CTX HStack_f8;
  
  len = EVP_MD_size(digest);
  if ((int)len < 0) {
    iVar2 = 0;
  }
  else {
    HMAC_CTX_init(&HStack_1c8);
    if (pass == (char *)0x0) {
      passlen = 0;
    }
    else if (passlen == -1) {
      passlen = strlen(pass);
    }
    iVar2 = HMAC_Init_ex(&HStack_1c8,pass,passlen,digest,(ENGINE *)0x0);
    if (iVar2 == 0) {
LAB_000b3500:
      HMAC_CTX_cleanup(&HStack_1c8);
      iVar2 = 0;
    }
    else {
      if (keylen != 0) {
        local_21c = keylen;
        local_220 = 1;
        do {
          local_209 = (undefined)local_220;
          local_20c = (uchar)((uint)local_220 >> 0x18);
          local_20b = (undefined)((uint)local_220 >> 0x10);
          __n = local_21c;
          if ((int)len <= (int)local_21c) {
            __n = len;
          }
          local_20a = (undefined)((uint)local_220 >> 8);
          iVar2 = HMAC_CTX_copy(&HStack_f8,&HStack_1c8);
          if (iVar2 == 0) goto LAB_000b3500;
          iVar2 = HMAC_Update(&HStack_f8,salt,saltlen);
          if (((iVar2 == 0) || (iVar2 = HMAC_Update(&HStack_f8,&local_20c,4), iVar2 == 0)) ||
             (iVar2 = HMAC_Final(&HStack_f8,(uchar *)auStack_208,(uint *)0x0), iVar2 == 0)) {
LAB_000b34f0:
            HMAC_CTX_cleanup(&HStack_1c8);
            HMAC_CTX_cleanup(&HStack_f8);
            return 0;
          }
          HMAC_CTX_cleanup(&HStack_f8);
          memcpy(out,auStack_208,__n);
          if (1 < iter) {
            bVar10 = ((uint)out & 3) != 0;
            uVar9 = __n >> 2;
            uVar7 = __n & 0xfffffffc;
            if (uVar9 == 0 || (__n < 4 || bVar10)) {
              uVar7 = 0;
            }
            local_238 = 1;
            do {
              iVar2 = HMAC_CTX_copy(&HStack_f8,&HStack_1c8);
              if (iVar2 == 0) goto LAB_000b3500;
              iVar2 = HMAC_Update(&HStack_f8,(uchar *)auStack_208,len);
              if ((iVar2 == 0) ||
                 (iVar2 = HMAC_Final(&HStack_f8,(uchar *)auStack_208,(uint *)0x0), iVar2 == 0))
              goto LAB_000b34f0;
              HMAC_CTX_cleanup(&HStack_f8);
              if (0 < (int)__n) {
                uVar5 = uVar7;
                if (uVar9 != 0 && (__n >= 4 && !bVar10)) {
                  if (uVar9 < 9) {
                    uVar4 = 0;
                    puVar3 = (uint *)out;
                    puVar6 = auStack_208;
                  }
                  else {
                    puVar6 = auStack_208;
                    uVar4 = 0;
                    puVar1 = (uint *)out;
                    do {
                      puVar6 = puVar6 + 8;
                      puVar3 = puVar1 + 8;
                      uVar8 = uVar4 + 9;
                      uVar4 = uVar4 + 8;
                      HintPreloadData(puVar1 + 0x14);
                      *puVar1 = *puVar1 ^ puVar6[-8];
                      puVar1[1] = puVar1[1] ^ puVar6[-7];
                      puVar1[2] = puVar1[2] ^ puVar6[-6];
                      puVar1[3] = puVar1[3] ^ puVar6[-5];
                      puVar1[4] = puVar1[4] ^ puVar6[-4];
                      puVar1[5] = puVar1[5] ^ puVar6[-3];
                      puVar1[6] = puVar1[6] ^ puVar6[-2];
                      puVar1[7] = puVar1[7] ^ puVar6[-1];
                      puVar1 = puVar3;
                    } while (uVar8 < uVar9 - 7);
                  }
                  iVar2 = 0;
                  do {
                    uVar4 = uVar4 + 1;
                    *(uint *)((int)puVar3 + iVar2) =
                         *(uint *)((int)puVar3 + iVar2) ^ *(uint *)((int)puVar6 + iVar2);
                    iVar2 = iVar2 + 4;
                  } while (uVar4 < uVar9);
                  if (__n == (__n & 0xfffffffc)) goto LAB_000b34b4;
                }
                do {
                  *(byte *)((int)out + uVar5) =
                       *(byte *)((int)out + uVar5) ^ *(byte *)((int)auStack_208 + uVar5);
                  uVar5 = uVar5 + 1;
                } while ((int)uVar5 < (int)__n);
              }
LAB_000b34b4:
              local_238 = local_238 + 1;
            } while (local_238 != iter);
          }
          out = (uchar *)((int)out + __n);
          local_21c = local_21c - __n;
          local_220 = local_220 + 1;
        } while (local_21c != 0);
      }
      HMAC_CTX_cleanup(&HStack_1c8);
      iVar2 = 1;
    }
  }
  return iVar2;
}

