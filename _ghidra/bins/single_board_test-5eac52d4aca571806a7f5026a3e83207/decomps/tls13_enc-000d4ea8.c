
undefined4 tls13_enc(int param_1,int *param_2,int param_3,int param_4)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  uint uVar7;
  byte bVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  size_t __n;
  undefined4 uVar12;
  uint *puVar13;
  EVP_CIPHER_CTX *ctx;
  void *__src;
  uint uVar14;
  undefined8 uVar15;
  int local_88;
  int local_84;
  int local_64;
  int local_60;
  int local_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  uchar auStack_50 [16];
  undefined1 auStack_40 [28];
  
  if (param_3 != 1) {
    ossl_statem_fatal(param_1,0x50,0x261,0x44,"ssl/record/ssl3_record_tls13.c",0x29);
    return 0xffffffff;
  }
  if (param_4 == 0) {
    ctx = *(EVP_CIPHER_CTX **)(param_1 + 0x3cc);
    __src = (void *)(param_1 + 0x3d0);
    puVar13 = (uint *)(param_1 + 0xf20);
  }
  else {
    ctx = *(EVP_CIPHER_CTX **)(param_1 + 0x3ec);
    __src = (void *)(param_1 + 0x3f0);
    puVar13 = (uint *)(param_1 + 0xf28);
  }
  if ((ctx == (EVP_CIPHER_CTX *)0x0) || (param_2[1] == 0x15)) {
    memmove((void *)param_2[5],(void *)param_2[6],param_2[2]);
    param_2[6] = param_2[5];
    return 1;
  }
  uVar7 = EVP_CIPHER_CTX_iv_length(ctx);
  if (*(int *)(param_1 + 0x68) - 3U < 2) {
    iVar10 = *(int *)(param_1 + 0x474);
    if (((iVar10 == 0) || (*(int *)(iVar10 + 0x1e0) == 0)) &&
       ((iVar10 = *(int *)(param_1 + 0x478), iVar10 == 0 || (*(int *)(iVar10 + 0x1e0) == 0)))) {
      uVar12 = 0x4d;
      goto LAB_000d517c;
    }
    uVar11 = *(uint *)(*(int *)(iVar10 + 0x1b8) + 0x18);
  }
  else {
    iVar10 = *(int *)(*(int *)(param_1 + 0x7c) + 0x210);
    if (iVar10 == 0) {
      uVar12 = 0x59;
      goto LAB_000d517c;
    }
    uVar11 = *(uint *)(iVar10 + 0x18);
  }
  if ((uVar11 & 0x3c000) == 0) {
    if ((uVar11 & 0x83000) == 0) {
      uVar12 = 0x70;
      goto LAB_000d517c;
    }
    local_84 = 0x10;
    if (param_4 == 0) {
      uVar9 = 0x11;
      local_88 = 0x10;
      goto LAB_000d4f1e;
    }
    local_88 = 0x10;
  }
  else {
    if ((uVar11 & 0x30000) == 0) {
      local_88 = 0x10;
      local_84 = 0x10;
      uVar9 = 0x11;
    }
    else {
      local_88 = 8;
      local_84 = 8;
      uVar9 = 9;
    }
    if (param_4 == 0) {
LAB_000d4f1e:
      if ((uint)param_2[2] < uVar9) {
        return 0;
      }
      param_2[2] = param_2[2] - local_88;
    }
    else {
      iVar10 = EVP_CIPHER_CTX_ctrl(ctx,0x11,local_84,(void *)0x0);
      if (iVar10 < 1) {
        uVar12 = 0x67;
        goto LAB_000d517c;
      }
    }
  }
  if (7 < uVar7) {
    __n = uVar7 - 8;
    memcpy(auStack_50,__src,__n);
    if ((((uint)(auStack_50 + __n) | (int)__src + __n | (uint)puVar13) & 3) == 0) {
      uVar14 = *(uint *)((int)__src + __n + 4);
      uVar9 = puVar13[1];
      bVar8 = *(byte *)((int)puVar13 + 7);
      *(uint *)(auStack_50 + __n) = *(uint *)((int)__src + __n) ^ *puVar13;
      *(uint *)(auStack_50 + (uVar7 - 4)) = uVar14 ^ uVar9;
    }
    else {
      bVar1 = *(byte *)((int)__src + (uVar7 - 7));
      bVar8 = *(byte *)((int)puVar13 + 1);
      *(byte *)((int)&uStack_58 + uVar7) = *(byte *)((int)__src + __n) ^ (byte)*puVar13;
      bVar2 = *(byte *)((int)__src + (uVar7 - 6));
      *(byte *)((int)&uStack_58 + uVar7 + 1) = bVar1 ^ bVar8;
      bVar8 = *(byte *)((int)__src + (uVar7 - 5));
      *(byte *)((int)&uStack_58 + uVar7 + 2) = bVar2 ^ *(byte *)((int)puVar13 + 2);
      bVar3 = *(byte *)((int)__src + (uVar7 - 4));
      uVar9 = puVar13[1];
      *(byte *)((int)&uStack_58 + uVar7 + 3) = *(byte *)((int)puVar13 + 3) ^ bVar8;
      bVar1 = *(byte *)((int)puVar13 + 5);
      bVar4 = *(byte *)((int)__src + (uVar7 - 3));
      bVar5 = *(byte *)((int)__src + (uVar7 - 1));
      bVar2 = *(byte *)((int)puVar13 + 6);
      bVar6 = *(byte *)((int)__src + (uVar7 - 2));
      auStack_50[uVar7 - 4] = bVar3 ^ (byte)uVar9;
      bVar8 = *(byte *)((int)puVar13 + 7);
      auStack_50[uVar7 - 3] = bVar1 ^ bVar4;
      auStack_50[uVar7 - 2] = bVar6 ^ bVar2;
      auStack_50[uVar7 - 1] = bVar5 ^ bVar8;
    }
    *(byte *)((int)puVar13 + 7) = bVar8 + 1;
    if ((((((byte)(bVar8 + 1) == 0) &&
          (bVar8 = *(byte *)((int)puVar13 + 6) + 1, *(byte *)((int)puVar13 + 6) = bVar8, bVar8 == 0)
          ) && (bVar8 = *(byte *)((int)puVar13 + 5) + 1, *(byte *)((int)puVar13 + 5) = bVar8,
               bVar8 == 0)) &&
        ((bVar8 = (byte)puVar13[1] + 1, *(byte *)(puVar13 + 1) = bVar8, bVar8 == 0 &&
         (bVar8 = *(byte *)((int)puVar13 + 3) + 1, *(byte *)((int)puVar13 + 3) = bVar8, bVar8 == 0))
        )) && ((bVar8 = *(byte *)((int)puVar13 + 2) + 1, *(byte *)((int)puVar13 + 2) = bVar8,
               bVar8 == 0 &&
               ((bVar8 = *(byte *)((int)puVar13 + 1) + 1, *(byte *)((int)puVar13 + 1) = bVar8,
                bVar8 == 0 && (bVar8 = (byte)*puVar13 + 1, *(byte *)puVar13 = bVar8, bVar8 == 0)))))
       ) {
      return 0xffffffff;
    }
    iVar10 = EVP_CipherInit_ex(ctx,(EVP_CIPHER *)0x0,(ENGINE *)0x0,(uchar *)0x0,auStack_50,param_4);
    if (iVar10 < 1) {
      return 0xffffffff;
    }
    if ((param_4 == 0) &&
       (iVar10 = EVP_CIPHER_CTX_ctrl(ctx,0x11,local_84,(void *)(param_2[2] + param_2[5])),
       iVar10 < 1)) {
      return 0xffffffff;
    }
    uVar15 = WPACKET_init_static_len(auStack_40,&uStack_58,5,0);
    if ((int)uVar15 != 0) {
      uVar15 = WPACKET_put_bytes__(auStack_40,(int)((ulonglong)uVar15 >> 0x20),param_2[1],
                                   param_2[1] >> 0x1f,1);
      if (((((int)uVar15 != 0) &&
           (iVar10 = WPACKET_put_bytes__(auStack_40,(int)((ulonglong)uVar15 >> 0x20),*param_2,
                                         *param_2 >> 0x1f,2), iVar10 != 0)) &&
          (iVar10 = WPACKET_put_bytes__(auStack_40,local_88,param_2[2] + local_88,0,2), iVar10 != 0)
          ) && (((iVar10 = WPACKET_get_total_written(auStack_40,&local_64), iVar10 != 0 &&
                 (local_64 == 5)) && (iVar10 = WPACKET_finish(auStack_40), iVar10 != 0)))) {
        if (((uVar11 & 0x3c000) != 0) &&
           (iVar10 = EVP_CipherUpdate(ctx,(uchar *)0x0,&local_60,(uchar *)0x0,param_2[2]),
           iVar10 < 1)) {
          return 0xffffffff;
        }
        iVar10 = EVP_CipherUpdate(ctx,(uchar *)0x0,&local_60,(uchar *)&uStack_58,5);
        if (iVar10 < 1) {
          return 0xffffffff;
        }
        iVar10 = EVP_CipherUpdate(ctx,(uchar *)param_2[5],&local_60,(uchar *)param_2[6],param_2[2]);
        if (iVar10 < 1) {
          return 0xffffffff;
        }
        iVar10 = EVP_CipherFinal_ex(ctx,(uchar *)(param_2[5] + local_60),&local_5c);
        if (iVar10 < 1) {
          return 0xffffffff;
        }
        if (local_5c + local_60 != param_2[2]) {
          return 0xffffffff;
        }
        if (param_4 == 0) {
          return 1;
        }
        iVar10 = EVP_CIPHER_CTX_ctrl(ctx,0x10,local_84,(void *)(param_2[5] + local_5c + local_60));
        if (0 < iVar10) {
          param_2[2] = param_2[2] + local_88;
          return 1;
        }
        uVar12 = 0xbd;
        goto LAB_000d517c;
      }
    }
    WPACKET_cleanup(auStack_40);
    return 0xffffffff;
  }
  uVar12 = 0x82;
LAB_000d517c:
  ossl_statem_fatal(param_1,0x50,0x261,0x44,"ssl/record/ssl3_record_tls13.c",uVar12);
  return 0xffffffff;
}

