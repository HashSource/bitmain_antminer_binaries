
undefined4 dtls1_process_record(int param_1)

{
  bool bVar1;
  EVP_MD *pEVar2;
  uint len;
  ulong uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined1 *b;
  undefined1 auStack_a0 [64];
  undefined1 auStack_60 [68];
  
  iVar7 = *(int *)(param_1 + 0x58);
  iVar8 = *(int *)(param_1 + 0xc0);
  iVar6 = *(int *)(param_1 + 0x4c) + 0xd;
  *(int *)(iVar7 + 0x11c) = iVar6;
  if (0x4540 < *(uint *)(iVar7 + 0x110)) {
    ERR_put_error(0x14,0x101,0x96,"d1_pkt.c",0x1ab);
    uVar4 = 0x16;
    goto LAB_0012beb0;
  }
  iVar5 = *(int *)(param_1 + 8);
  *(int *)(iVar7 + 0x118) = iVar6;
  iVar6 = (*(code *)**(undefined4 **)(iVar5 + 100))(param_1,0);
  if (iVar6 == 0) {
    *(undefined4 *)(iVar7 + 0x110) = 0;
    *(undefined4 *)(param_1 + 0x50) = 0;
    return 0;
  }
  if (((iVar8 != 0) && (*(int *)(param_1 + 0x80) != 0)) &&
     (pEVar2 = EVP_MD_CTX_md(*(EVP_MD_CTX **)(param_1 + 0x84)), pEVar2 != (EVP_MD *)0x0)) {
    pEVar2 = EVP_MD_CTX_md(*(EVP_MD_CTX **)(param_1 + 0x84));
    len = EVP_MD_size(pEVar2);
    if (0x40 < len) {
      OpenSSLDie("d1_pkt.c",0x1d0,"mac_size <= EVP_MAX_MD_SIZE");
    }
    uVar9 = *(int *)(iVar7 + 0x110) + (*(uint *)(iVar7 + 0x10c) >> 8);
    if ((uVar9 < len) ||
       ((uVar3 = EVP_CIPHER_CTX_flags(*(EVP_CIPHER_CTX **)(param_1 + 0x80)), (uVar3 & 0xf0007) == 2
        && (uVar9 < len + 1)))) {
      ERR_put_error(0x14,0x101,0xa0,"d1_pkt.c",0x1e2);
      uVar4 = 0x32;
      goto LAB_0012beb0;
    }
    uVar3 = EVP_CIPHER_CTX_flags(*(EVP_CIPHER_CTX **)(param_1 + 0x80));
    if ((uVar3 & 0xf0007) == 2) {
      b = auStack_60;
      bVar1 = false;
      ssl3_cbc_copy_mac(b,iVar7 + 0x10c,len,uVar9);
      *(uint *)(iVar7 + 0x110) = *(int *)(iVar7 + 0x110) - len;
    }
    else {
      iVar8 = *(int *)(iVar7 + 0x110) - len;
      b = (undefined1 *)(*(int *)(iVar7 + 0x118) + iVar8);
      *(int *)(iVar7 + 0x110) = iVar8;
      if (b == (undefined1 *)0x0) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    iVar8 = (**(code **)(*(int *)(*(int *)(param_1 + 8) + 100) + 4))(param_1,auStack_a0,0);
    if (bVar1 || iVar8 < 0) {
      iVar6 = -1;
    }
    else {
      iVar8 = CRYPTO_memcmp(auStack_a0,b,len);
      if (iVar8 != 0) {
        iVar6 = -1;
      }
    }
    if (len + 0x4400 < *(uint *)(iVar7 + 0x110)) goto LAB_0012bf7c;
  }
  if (iVar6 < 0) {
LAB_0012bf7c:
    *(undefined4 *)(iVar7 + 0x110) = 0;
    *(undefined4 *)(param_1 + 0x50) = 0;
    return 0;
  }
  if (*(int *)(param_1 + 0x88) != 0) {
    if (0x4400 < *(uint *)(iVar7 + 0x110)) {
      ERR_put_error(0x14,0x101,0x8c,"d1_pkt.c",0x20e);
      uVar4 = 0x16;
      goto LAB_0012beb0;
    }
    iVar6 = ssl3_do_uncompress(param_1);
    if (iVar6 == 0) {
      ERR_put_error(0x14,0x101,0x6b,"d1_pkt.c",0x213);
      uVar4 = 0x1e;
      goto LAB_0012beb0;
    }
  }
  if (*(uint *)(iVar7 + 0x110) < 0x4001) {
    *(undefined4 *)(iVar7 + 0x114) = 0;
    *(undefined4 *)(param_1 + 0x50) = 0;
    return 1;
  }
  ERR_put_error(0x14,0x101,0x92,"d1_pkt.c",0x21a);
  uVar4 = 0x16;
LAB_0012beb0:
  ssl3_send_alert(param_1,2,uVar4);
  return 0;
}

