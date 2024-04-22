
undefined4 tls1_process_sigalgs(int param_1)

{
  int iVar1;
  void *pvVar2;
  EVP_MD *pEVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  undefined4 uVar11;
  
  iVar8 = *(int *)(param_1 + 0x98);
  uVar5 = *(uint *)(iVar8 + 0x38) & 0x30000;
  if (*(void **)(iVar8 + 0x13c) != (void *)0x0) {
    CRYPTO_free(*(void **)(iVar8 + 0x13c));
    *(undefined4 *)(iVar8 + 0x13c) = 0;
    *(undefined4 *)(iVar8 + 0x140) = 0;
  }
  if ((*(int *)(param_1 + 0x24) == 0) && (iVar6 = *(int *)(iVar8 + 0x134), iVar6 != 0)) {
    if (uVar5 != 0) goto LAB_00072fac;
    uVar9 = *(undefined4 *)(iVar8 + 0x138);
LAB_00072f42:
    if (-1 < *(int *)(param_1 + 0x100) << 9) goto LAB_00073070;
  }
  else {
    iVar6 = *(int *)(iVar8 + 300);
    if ((iVar6 != 0) && (uVar5 == 0)) {
      uVar9 = *(undefined4 *)(iVar8 + 0x130);
      goto LAB_00072f42;
    }
LAB_00072fac:
    iVar10 = *(int *)(param_1 + 0x98);
    uVar7 = *(uint *)(iVar10 + 0x38) & 0x30000;
    if (uVar7 == 0x20000) {
      uVar9 = 2;
      iVar6 = DAT_0007310c;
    }
    else {
      iVar6 = DAT_00073108;
      if (uVar7 == 0x30000) {
        uVar9 = 4;
      }
      else if (uVar7 == 0x10000) {
        uVar9 = 2;
      }
      else if ((*(int *)(param_1 + 0x24) == 0) || (*(int *)(iVar10 + 0x134) == 0)) {
        if (*(int *)(iVar10 + 300) == 0) {
          uVar9 = 0x1e;
          iVar6 = DAT_00073110;
        }
        else {
          uVar9 = *(undefined4 *)(iVar10 + 0x130);
          iVar6 = *(int *)(iVar10 + 300);
        }
      }
      else {
        uVar9 = *(undefined4 *)(iVar10 + 0x138);
        iVar6 = *(int *)(iVar10 + 0x134);
      }
    }
    if ((-1 < *(int *)(param_1 + 0x100) << 9) && (uVar5 == 0)) {
LAB_00073070:
      uVar11 = *(undefined4 *)(iVar8 + 0x128);
      iVar10 = *(int *)(iVar8 + 0x124);
      goto LAB_00072f54;
    }
  }
  iVar10 = iVar6;
  uVar11 = uVar9;
  iVar6 = *(int *)(iVar8 + 0x124);
  uVar9 = *(undefined4 *)(iVar8 + 0x128);
LAB_00072f54:
  iVar1 = tls12_do_shared_sigalgs(0,iVar10,uVar11,iVar6,uVar9);
  if (iVar1 == 0) {
    *(undefined4 *)(iVar8 + 0x13c) = 0;
    *(undefined4 *)(iVar8 + 0x140) = 0;
  }
  else {
    pvVar2 = CRYPTO_malloc(iVar1 << 4,DAT_00073104,0xe56);
    if (pvVar2 == (void *)0x0) {
      return 0;
    }
    uVar5 = tls12_do_shared_sigalgs(pvVar2,iVar10,uVar11,iVar6,uVar9);
    *(void **)(iVar8 + 0x13c) = pvVar2;
    *(uint *)(iVar8 + 0x140) = uVar5;
    iVar6 = DAT_00073114;
    if (uVar5 != 0) {
      uVar7 = 0;
      do {
        uVar4 = *(byte *)((int)pvVar2 + 0xc) - 1 & 0xff;
        if (((uVar4 < 3) && (iVar10 = *(int *)(iVar6 + uVar4 * 4), 0 < iVar10)) &&
           (*(int *)(iVar8 + iVar10 * 0x1c + 0x44) == 0)) {
          HintPreloadData((int)pvVar2 + 0x3d);
          switch(*(undefined *)((int)pvVar2 + 0xd)) {
          case 1:
            pEVar3 = EVP_md5();
            break;
          case 2:
            pEVar3 = EVP_sha1();
            break;
          case 3:
            pEVar3 = EVP_sha224();
            break;
          case 4:
            pEVar3 = EVP_sha256();
            break;
          case 5:
            pEVar3 = EVP_sha384();
            break;
          case 6:
            pEVar3 = EVP_sha512();
            break;
          default:
            pEVar3 = (EVP_MD *)0x0;
          }
          iVar1 = iVar8 + iVar10 * 0x1c;
          uVar5 = *(uint *)(iVar8 + 0x140);
          *(EVP_MD **)(iVar1 + 0x44) = pEVar3;
          *(undefined4 *)(iVar1 + 0x54) = 0x100;
          if (iVar10 == 1) {
            *(EVP_MD **)(iVar8 + 0x44) = pEVar3;
          }
          if (iVar10 == 1) {
            *(undefined4 *)(iVar8 + 0x54) = 0x100;
          }
        }
        uVar7 = uVar7 + 1;
        pvVar2 = (void *)((int)pvVar2 + 0x10);
      } while (uVar7 < uVar5);
    }
  }
  if ((*(uint *)(*(int *)(param_1 + 0x98) + 0x38) & 0x30001) == 0) {
    if (*(int *)(iVar8 + 0x7c) == 0) {
      pEVar3 = EVP_sha1();
      *(EVP_MD **)(iVar8 + 0x7c) = pEVar3;
    }
    if (*(int *)(iVar8 + 0x60) == 0) {
      pEVar3 = EVP_sha1();
      *(EVP_MD **)(iVar8 + 0x60) = pEVar3;
      pEVar3 = EVP_sha1();
      *(EVP_MD **)(iVar8 + 0x44) = pEVar3;
    }
    if (*(int *)(iVar8 + 0xd0) == 0) {
      pEVar3 = EVP_sha1();
      *(EVP_MD **)(iVar8 + 0xd0) = pEVar3;
      return 1;
    }
  }
  return 1;
}

