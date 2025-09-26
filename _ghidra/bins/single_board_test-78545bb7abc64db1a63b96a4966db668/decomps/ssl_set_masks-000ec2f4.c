
void ssl_set_masks(SSL *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar6 = param_1[2].error;
  iVar7 = param_1->mac_flags;
  if (iVar6 == 0) {
    return;
  }
  if ((*(int *)(iVar6 + 4) == 0) && (*(int *)(iVar6 + 8) == 0)) {
    iVar8 = *(int *)(iVar6 + 0xc);
    if (iVar8 != 0) {
      iVar8 = 1;
    }
  }
  else {
    iVar8 = 1;
  }
  uVar3 = *(uint *)(iVar6 + 0x8c);
  uVar5 = *(uint *)(iVar7 + 0x284);
  uVar2 = *(uint *)(iVar7 + 0x288);
  uVar4 = uVar3;
  if ((uVar3 != 0) && (uVar3 = *(uint *)(iVar6 + 0x90), uVar4 = uVar3, uVar3 != 0)) {
    uVar3 = 0x10;
    uVar4 = 0x80;
  }
  if ((*(int *)(iVar6 + 0x78) != 0) && (*(int *)(iVar6 + 0x7c) != 0)) {
    uVar4 = 0x80;
    uVar3 = 0x10;
  }
  if ((*(int *)(iVar6 + 100) != 0) && (*(int *)(iVar6 + 0x68) != 0)) {
    uVar4 = uVar4 | 0x20;
    uVar3 = 0x10;
  }
  if ((*(uint *)(iVar7 + 0x27c) & 1) == 0) {
    if (iVar8 != 0) {
      uVar3 = uVar3 | 2;
    }
    if ((((*(int *)(iVar6 + 0x28) != 0) && (*(int *)(iVar6 + 0x2c) != 0)) &&
        (*(int *)(iVar7 + 0x280) << 0x17 < 0)) &&
       ((iVar8 = SSL_version(param_1), iVar8 >> 8 == 3 &&
        (iVar8 = SSL_version(param_1), iVar8 == 0x303)))) goto LAB_000ec3f2;
  }
  else {
    uVar1 = uVar3 | 1;
    uVar3 = uVar3 | 3;
    if (iVar8 == 0) {
      uVar3 = uVar1;
    }
LAB_000ec3f2:
    uVar4 = uVar4 | 1;
  }
  if ((uVar5 & 1) != 0) {
    uVar4 = uVar4 | 2;
  }
  uVar5 = uVar4 | 4;
  if (((uVar2 & 1) != 0) &&
     (iVar6 = X509_get_key_usage(*(undefined4 *)(iVar6 + 0x50)),
     ((uint)(iVar6 << 0x18) >> 0x1f & *(uint *)(iVar7 + 0x288) >> 1) != 0)) {
    uVar5 = uVar4 | 0xc;
  }
  if ((int)(uVar5 << 0x1c) < 0) goto LAB_000ec3b6;
  iVar6 = param_1[2].error;
  if (((*(int *)(iVar6 + 0xa0) == 0) || (*(int *)(iVar6 + 0xa4) == 0)) ||
     (-1 < *(int *)(iVar7 + 0x298) << 0x17)) {
LAB_000ec3a2:
    if (((*(int *)(iVar6 + 0xb4) == 0) || (*(int *)(iVar6 + 0xb8) == 0)) ||
       ((-1 < *(int *)(iVar7 + 0x29c) << 0x17 ||
        ((iVar6 = SSL_version(param_1), iVar6 >> 8 != 3 ||
         (iVar6 = SSL_version(param_1), iVar6 != 0x303)))))) goto LAB_000ec3b6;
  }
  else {
    iVar6 = SSL_version(param_1);
    if ((iVar6 >> 8 != 3) || (iVar6 = SSL_version(param_1), iVar6 != 0x303)) {
      iVar6 = param_1[2].error;
      goto LAB_000ec3a2;
    }
  }
  uVar5 = uVar5 | 8;
LAB_000ec3b6:
  iVar6 = param_1->mac_flags;
  if ((int)(uVar3 << 0x1f) < 0) {
    uVar3 = uVar3 | 0x4c;
  }
  else {
    uVar3 = uVar3 | 0xc;
  }
  if ((int)(uVar3 << 0x1e) < 0) {
    uVar3 = uVar3 | 0x100;
  }
  *(uint *)(iVar6 + 0x2a4) = uVar5 | 0x10;
  *(uint *)(iVar6 + 0x2a0) = uVar3 | 0x80;
  return;
}

