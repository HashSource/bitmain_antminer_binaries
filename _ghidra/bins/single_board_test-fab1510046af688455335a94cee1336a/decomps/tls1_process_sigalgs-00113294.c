
undefined4 tls1_process_sigalgs(int param_1)

{
  int iVar1;
  void *pvVar2;
  EVP_MD *pEVar3;
  uint uVar4;
  uint uVar5;
  undefined1 *puVar6;
  uint uVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int iVar12;
  
  iVar9 = *(int *)(param_1 + 0x98);
  uVar5 = *(uint *)(iVar9 + 0x38) & 0x30000;
  if (*(void **)(iVar9 + 0x13c) != (void *)0x0) {
    CRYPTO_free(*(void **)(iVar9 + 0x13c));
    *(undefined4 *)(iVar9 + 0x13c) = 0;
    *(undefined4 *)(iVar9 + 0x140) = 0;
  }
  if ((*(int *)(param_1 + 0x24) == 0) &&
     (puVar6 = *(undefined1 **)(iVar9 + 0x134), (undefined4 *)puVar6 != (undefined4 *)0x0)) {
    if (uVar5 == 0) {
      uVar10 = *(undefined4 *)(iVar9 + 0x138);
      goto LAB_001132d2;
    }
LAB_0011333c:
    iVar1 = *(int *)(param_1 + 0x98);
    uVar7 = *(uint *)(iVar1 + 0x38) & 0x30000;
    if (uVar7 == 0x20000) {
      puVar6 = (undefined1 *)0x24d32a;
      uVar10 = 2;
    }
    else if (uVar7 == 0x30000) {
      puVar6 = (undefined1 *)&suiteb_sigalgs;
      uVar10 = 4;
    }
    else if (uVar7 == 0x10000) {
      puVar6 = (undefined1 *)&suiteb_sigalgs;
      uVar10 = 2;
    }
    else if ((*(int *)(param_1 + 0x24) == 0) ||
            (puVar6 = *(undefined1 **)(iVar1 + 0x134), (undefined4 *)puVar6 == (undefined4 *)0x0)) {
      puVar6 = *(undefined1 **)(iVar1 + 300);
      if ((undefined4 *)puVar6 == (undefined4 *)0x0) {
        puVar6 = tls12_sigalgs;
        uVar10 = 0x1e;
      }
      else {
        uVar10 = *(undefined4 *)(iVar1 + 0x130);
      }
    }
    else {
      uVar10 = *(undefined4 *)(iVar1 + 0x138);
    }
    if ((-1 < *(int *)(param_1 + 0x100) << 9) && (uVar5 == 0)) goto LAB_00113400;
  }
  else {
    puVar6 = *(undefined1 **)(iVar9 + 300);
    if (((undefined4 *)puVar6 == (undefined4 *)0x0) || (uVar5 != 0)) goto LAB_0011333c;
    uVar10 = *(undefined4 *)(iVar9 + 0x130);
LAB_001132d2:
    if (-1 < *(int *)(param_1 + 0x100) << 9) {
LAB_00113400:
      uVar11 = *(undefined4 *)(iVar9 + 0x128);
      puVar8 = *(undefined4 **)(iVar9 + 0x124);
      goto LAB_001132e4;
    }
  }
  puVar8 = (undefined4 *)puVar6;
  uVar11 = uVar10;
  puVar6 = (undefined1 *)*(undefined4 **)(iVar9 + 0x124);
  uVar10 = *(undefined4 *)(iVar9 + 0x128);
LAB_001132e4:
  iVar1 = tls12_do_shared_sigalgs(0,puVar8,uVar11,puVar6,uVar10);
  if (iVar1 == 0) {
    *(undefined4 *)(iVar9 + 0x13c) = 0;
    *(undefined4 *)(iVar9 + 0x140) = 0;
  }
  else {
    pvVar2 = CRYPTO_malloc(iVar1 << 4,"t1_lib.c",0xe56);
    if (pvVar2 == (void *)0x0) {
      return 0;
    }
    uVar5 = tls12_do_shared_sigalgs(pvVar2,puVar8,uVar11,puVar6,uVar10);
    *(void **)(iVar9 + 0x13c) = pvVar2;
    *(uint *)(iVar9 + 0x140) = uVar5;
    if (uVar5 != 0) {
      uVar7 = 0;
      do {
        uVar4 = *(byte *)((int)pvVar2 + 0xc) - 1 & 0xff;
        if (((uVar4 < 3) && (iVar1 = *(int *)(&CSWTCH_132 + uVar4 * 4), 0 < iVar1)) &&
           (*(int *)(iVar9 + iVar1 * 0x1c + 0x44) == 0)) {
          HintPreloadData((int)pvVar2 + 0x3d);
          switch(*(undefined1 *)((int)pvVar2 + 0xd)) {
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
          iVar12 = iVar9 + iVar1 * 0x1c;
          uVar5 = *(uint *)(iVar9 + 0x140);
          *(EVP_MD **)(iVar12 + 0x44) = pEVar3;
          *(undefined4 *)(iVar12 + 0x54) = 0x100;
          if (iVar1 == 1) {
            *(EVP_MD **)(iVar9 + 0x44) = pEVar3;
          }
          if (iVar1 == 1) {
            *(undefined4 *)(iVar9 + 0x54) = 0x100;
          }
        }
        uVar7 = uVar7 + 1;
        pvVar2 = (void *)((int)pvVar2 + 0x10);
      } while (uVar7 < uVar5);
    }
  }
  if ((*(uint *)(*(int *)(param_1 + 0x98) + 0x38) & 0x30001) == 0) {
    if (*(int *)(iVar9 + 0x7c) == 0) {
      pEVar3 = EVP_sha1();
      *(EVP_MD **)(iVar9 + 0x7c) = pEVar3;
    }
    if (*(int *)(iVar9 + 0x60) == 0) {
      pEVar3 = EVP_sha1();
      *(EVP_MD **)(iVar9 + 0x60) = pEVar3;
      pEVar3 = EVP_sha1();
      *(EVP_MD **)(iVar9 + 0x44) = pEVar3;
    }
    if (*(int *)(iVar9 + 0xd0) == 0) {
      pEVar3 = EVP_sha1();
      *(EVP_MD **)(iVar9 + 0xd0) = pEVar3;
      return 1;
    }
  }
  return 1;
}

