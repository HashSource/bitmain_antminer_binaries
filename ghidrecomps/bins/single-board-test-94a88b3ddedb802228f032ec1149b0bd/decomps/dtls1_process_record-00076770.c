
undefined4 dtls1_process_record(int param_1)

{
  EVP_MD *pEVar1;
  uint len;
  ulong uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  undefined *b;
  undefined auStack_a0 [64];
  undefined auStack_60 [68];
  
  iVar6 = *(int *)(param_1 + 0x58);
  iVar7 = *(int *)(param_1 + 0xc0);
  iVar5 = *(int *)(param_1 + 0x4c) + 0xd;
  *(int *)(iVar6 + 0x11c) = iVar5;
  if (0x4540 < *(uint *)(iVar6 + 0x110)) {
    ERR_put_error(0x14,0x101,0x96,DAT_00076964,0x1ab);
    uVar3 = 0x16;
    goto LAB_000767a8;
  }
  iVar4 = *(int *)(param_1 + 8);
  *(int *)(iVar6 + 0x118) = iVar5;
  iVar5 = (***(code ***)(iVar4 + 100))(param_1,0);
  if (iVar5 == 0) {
    *(undefined4 *)(iVar6 + 0x110) = 0;
    *(undefined4 *)(param_1 + 0x50) = 0;
    return 0;
  }
  if (((iVar7 != 0) && (*(int *)(param_1 + 0x80) != 0)) &&
     (pEVar1 = EVP_MD_CTX_md(*(EVP_MD_CTX **)(param_1 + 0x84)), pEVar1 != (EVP_MD *)0x0)) {
    pEVar1 = EVP_MD_CTX_md(*(EVP_MD_CTX **)(param_1 + 0x84));
    len = EVP_MD_size(pEVar1);
    if (0x40 < len) {
      OpenSSLDie(DAT_00076964,0x1d0,DAT_00076968);
    }
    uVar8 = *(int *)(iVar6 + 0x110) + (*(uint *)(iVar6 + 0x10c) >> 8);
    if ((uVar8 < len) ||
       ((uVar2 = EVP_CIPHER_CTX_flags(*(EVP_CIPHER_CTX **)(param_1 + 0x80)), (uVar2 & 0xf0007) == 2
        && (uVar8 < len + 1)))) {
      ERR_put_error(0x14,0x101,0xa0,DAT_00076964,0x1e2);
      uVar3 = 0x32;
      goto LAB_000767a8;
    }
    uVar2 = EVP_CIPHER_CTX_flags(*(EVP_CIPHER_CTX **)(param_1 + 0x80));
    if ((uVar2 & 0xf0007) == 2) {
      b = auStack_60;
      uVar9 = 0;
      ssl3_cbc_copy_mac(b,iVar6 + 0x10c,len,uVar8);
      *(uint *)(iVar6 + 0x110) = *(int *)(iVar6 + 0x110) - len;
    }
    else {
      iVar7 = *(int *)(iVar6 + 0x110) - len;
      b = (undefined *)(*(int *)(iVar6 + 0x118) + iVar7);
      *(int *)(iVar6 + 0x110) = iVar7;
      if (b == (undefined *)0x0) {
        uVar9 = 1;
      }
      else {
        uVar9 = 0;
      }
    }
    uVar8 = (**(code **)(*(int *)(*(int *)(param_1 + 8) + 100) + 4))(param_1,auStack_a0,0);
    if ((uVar9 | uVar8 >> 0x1f) == 0) {
      iVar7 = CRYPTO_memcmp(auStack_a0,b,len);
      if (iVar7 != 0) {
        iVar5 = -1;
      }
    }
    else {
      iVar5 = -1;
    }
    if (len + 0x4400 < *(uint *)(iVar6 + 0x110)) goto LAB_00076874;
  }
  if (iVar5 < 0) {
LAB_00076874:
    *(undefined4 *)(iVar6 + 0x110) = 0;
    *(undefined4 *)(param_1 + 0x50) = 0;
    return 0;
  }
  if (*(int *)(param_1 + 0x88) != 0) {
    if (0x4400 < *(uint *)(iVar6 + 0x110)) {
      ERR_put_error(0x14,0x101,0x8c,DAT_00076964,0x20e);
      uVar3 = 0x16;
      goto LAB_000767a8;
    }
    iVar5 = ssl3_do_uncompress(param_1);
    if (iVar5 == 0) {
      ERR_put_error(0x14,0x101,0x6b,DAT_00076964,0x213);
      uVar3 = 0x1e;
      goto LAB_000767a8;
    }
  }
  if (*(uint *)(iVar6 + 0x110) < 0x4001) {
    *(undefined4 *)(iVar6 + 0x114) = 0;
    *(undefined4 *)(param_1 + 0x50) = 0;
    return 1;
  }
  ERR_put_error(0x14,0x101,0x92,DAT_00076964,0x21a);
  uVar3 = 0x16;
LAB_000767a8:
  ssl3_send_alert(param_1,2,uVar3);
  return 0;
}

