
undefined4 dtls1_process_record(int param_1,undefined4 param_2)

{
  char cVar1;
  EVP_MD *pEVar2;
  uint uVar3;
  int iVar4;
  EVP_CIPHER *pEVar5;
  ulong uVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  code *pcVar12;
  bool bVar13;
  undefined4 uVar14;
  undefined1 *local_b0;
  undefined1 auStack_a8 [64];
  undefined1 auStack_68 [68];
  
  iVar7 = *(int *)(param_1 + 0xef8) + 0xd;
  iVar11 = *(int *)(param_1 + 0x474);
  *(int *)(param_1 + 0x910) = iVar7;
  if (0x4540 < *(uint *)(param_1 + 0x900)) {
    ossl_statem_fatal(param_1,0x16,0x101,0x96,"ssl/record/ssl3_record.c",0x66f);
    return 0;
  }
  *(int *)(param_1 + 0x90c) = iVar7;
  *(uint *)(param_1 + 0x904) = *(uint *)(param_1 + 0x900);
  iVar7 = param_1 + 0x8f8;
  if ((**(int **)(param_1 + 0x7c) << 0x17 < 0) &&
     (*(EVP_MD_CTX **)(param_1 + 0x3e0) != (EVP_MD_CTX *)0x0)) {
    pEVar2 = EVP_MD_CTX_md(*(EVP_MD_CTX **)(param_1 + 0x3e0));
    uVar3 = EVP_MD_size(pEVar2);
    if (0x40 < uVar3) {
      ossl_statem_fatal(param_1,0x50,0x101,0x44,"ssl/record/ssl3_record.c",0x67c);
      return 0;
    }
    if (*(uint *)(param_1 + 0x904) < uVar3) {
      ossl_statem_fatal(param_1,0x32,0x101,0xa0,"ssl/record/ssl3_record.c",0x681);
      return 0;
    }
    iVar9 = *(int *)(param_1 + 0x900) - uVar3;
    iVar10 = *(int *)(param_1 + 0x90c);
    pcVar12 = *(code **)(*(int *)(*(int *)(param_1 + 4) + 100) + 4);
    *(int *)(param_1 + 0x900) = iVar9;
    iVar4 = (*pcVar12)(param_1,iVar7,auStack_a8,0);
    if ((iVar4 == 0) ||
       (iVar4 = CRYPTO_memcmp(auStack_a8,(void *)(iVar10 + iVar9),uVar3), iVar4 != 0)) {
      ossl_statem_fatal(param_1,0x14,0x101,0x119,"ssl/record/ssl3_record.c",0x689);
      return 0;
    }
  }
  iVar4 = (*(code *)**(undefined4 **)(*(int *)(param_1 + 4) + 100))(param_1,iVar7,1,0);
  if (iVar4 == 0) {
    iVar7 = ossl_statem_in_error(param_1);
    if (iVar7 != 0) {
      return 0;
    }
LAB_000e2914:
    *(undefined4 *)(param_1 + 0x900) = 0;
    *(undefined4 *)(param_1 + 0xefc) = 0;
    return 0;
  }
  if ((((iVar11 != 0) && (-1 < **(int **)(param_1 + 0x7c) << 0x17)) &&
      (*(int *)(param_1 + 0x3cc) != 0)) &&
     (pEVar2 = EVP_MD_CTX_md(*(EVP_MD_CTX **)(param_1 + 0x3e0)), pEVar2 != (EVP_MD *)0x0)) {
    pEVar2 = EVP_MD_CTX_md(*(EVP_MD_CTX **)(param_1 + 0x3e0));
    uVar3 = EVP_MD_size(pEVar2);
    if ((int)uVar3 < 0) {
      ossl_statem_fatal(param_1,0x50,0x101,6,"ssl/record/ssl3_record.c",0x6b4);
      return 0;
    }
    if (0x40 < (int)uVar3) {
      uVar8 = 0x6ba;
LAB_000e2978:
      ossl_statem_fatal(param_1,0x50,0x101,0x44,"ssl/record/ssl3_record.c",uVar8);
      return 0;
    }
    if (*(uint *)(param_1 + 0x904) < uVar3) {
LAB_000e299c:
      ossl_statem_fatal(param_1,0x32,0x101,0xa0,"ssl/record/ssl3_record.c",0x6c9);
      return 0;
    }
    pEVar5 = EVP_CIPHER_CTX_cipher(*(EVP_CIPHER_CTX **)(param_1 + 0x3cc));
    uVar6 = EVP_CIPHER_flags(pEVar5);
    if (((uVar6 & 0xf0007) == 2) && (*(uint *)(param_1 + 0x904) < uVar3 + 1)) goto LAB_000e299c;
    pEVar5 = EVP_CIPHER_CTX_cipher(*(EVP_CIPHER_CTX **)(param_1 + 0x3cc));
    uVar6 = EVP_CIPHER_flags(pEVar5);
    if ((uVar6 & 0xf0007) == 2) {
      local_b0 = auStack_68;
      iVar11 = ssl3_cbc_copy_mac(local_b0,iVar7,uVar3);
      if (iVar11 == 0) {
        uVar8 = 0x6d7;
        goto LAB_000e2978;
      }
      bVar13 = false;
      *(uint *)(param_1 + 0x900) = *(int *)(param_1 + 0x900) - uVar3;
    }
    else {
      iVar11 = *(int *)(param_1 + 0x900) - uVar3;
      local_b0 = (undefined1 *)(*(int *)(param_1 + 0x90c) + iVar11);
      bVar13 = local_b0 == (undefined1 *)0x0;
      *(int *)(param_1 + 0x900) = iVar11;
    }
    iVar11 = (**(code **)(*(int *)(*(int *)(param_1 + 4) + 100) + 4))(param_1,iVar7,auStack_a8,0);
    if (iVar11 == 0) {
      bVar13 = true;
    }
    if ((bVar13) || (iVar11 = CRYPTO_memcmp(auStack_a8,local_b0,uVar3), iVar11 != 0)) {
      iVar4 = -1;
    }
    if (uVar3 + 0x4400 < *(uint *)(param_1 + 0x900)) goto LAB_000e2914;
  }
  if (iVar4 < 0) goto LAB_000e2914;
  if (*(int *)(param_1 + 1000) != 0) {
    if (0x4400 < *(uint *)(param_1 + 0x900)) {
      uVar14 = 0x6f8;
      uVar8 = 0x8c;
      goto LAB_000e2954;
    }
    iVar7 = ssl3_do_uncompress(param_1,iVar7);
    if (iVar7 == 0) {
      ossl_statem_fatal(param_1,0x1e,0x101,0x6b,"ssl/record/ssl3_record.c",0x6fd);
      return 0;
    }
  }
  if ((*(int *)(param_1 + 0x474) == 0) ||
     (cVar1 = *(char *)(*(int *)(param_1 + 0x474) + 0x1ec), 3 < (byte)(cVar1 - 1U))) {
    uVar3 = 0x4000;
  }
  else {
    uVar3 = 0x200 << (uint)(byte)(cVar1 - 1);
  }
  if (*(uint *)(param_1 + 0x900) <= uVar3) {
    *(undefined4 *)(param_1 + 0x908) = 0;
    *(undefined4 *)(param_1 + 0xefc) = 0;
    dtls1_record_bitmap_update(param_1,param_2);
    return 1;
  }
  uVar14 = 0x709;
  uVar8 = 0x92;
LAB_000e2954:
  ossl_statem_fatal(param_1,0x16,0x101,uVar8,"ssl/record/ssl3_record.c",uVar14);
  return 0;
}

