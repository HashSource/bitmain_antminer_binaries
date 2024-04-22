
void ssl_set_cert_masks(int param_1,int param_2)

{
  int iVar1;
  EVP_PKEY *pkey;
  ASN1_OBJECT *o;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  X509 *x;
  uint uVar10;
  bool bVar11;
  uint uVar12;
  uint uVar13;
  uint in_r12;
  uint local_44;
  int local_40;
  int local_3c;
  uint local_38;
  uint local_34;
  int local_30;
  int local_2c [2];
  
  local_30 = 0;
  local_2c[0] = 0;
  if (param_1 == 0) {
    return;
  }
  if ((*(uint *)(param_2 + 0x20) & 8) == 0) {
    iVar5 = 0x400;
  }
  else {
    iVar5 = 0x200;
  }
  if (*(RSA **)(param_1 + 0x1c) == (RSA *)0x0) {
    local_38 = *(uint *)(param_1 + 0x20);
    local_34 = local_38;
    if (local_38 != 0) goto LAB_0007b922;
  }
  else if ((*(int *)(param_1 + 0x20) == 0) &&
          (iVar1 = RSA_size(*(RSA **)(param_1 + 0x1c)),
          iVar5 + iVar1 * -8 < 0 != SBORROW4(iVar5,iVar1 * 8))) {
    local_34 = 1;
    local_38 = 0;
  }
  else {
LAB_0007b922:
    local_38 = 1;
    local_34 = local_38;
  }
  if (*(DH **)(param_1 + 0x24) == (DH *)0x0) {
    local_44 = *(int *)(param_1 + 0x28);
    local_3c = local_44;
    if (local_44 != 0) goto LAB_0007b7e0;
  }
  else if ((*(int *)(param_1 + 0x28) == 0) &&
          (iVar1 = DH_size(*(DH **)(param_1 + 0x24)),
          iVar5 + iVar1 * -8 < 0 != SBORROW4(iVar5,iVar1 * 8))) {
    local_44 = 1;
    local_3c = 0;
  }
  else {
LAB_0007b7e0:
    local_44 = 1;
    local_3c = local_44;
  }
  if ((*(int *)(param_1 + 0x2c) == 0) && (*(int *)(param_1 + 0x30) == 0)) {
    local_40 = *(int *)(param_1 + 0x34);
    if (local_40 != 0) {
      local_40 = 1;
    }
  }
  else {
    local_40 = 1;
  }
  uVar7 = *(uint *)(param_1 + 0x54) & 1;
  if (uVar7 == 0) {
    bVar11 = false;
  }
  else {
    iVar1 = EVP_PKEY_size(*(EVP_PKEY **)(param_1 + 0x40));
    bVar11 = iVar5 + iVar1 * -8 < 0 == SBORROW4(iVar5,iVar1 * 8);
  }
  uVar3 = *(uint *)(param_1 + 0x8c);
  uVar10 = *(uint *)(param_1 + 0xa8) & 1;
  if (uVar10 == 0) {
    in_r12 = 0;
  }
  uVar8 = *(uint *)(param_1 + 0x70) & 2;
  if (uVar10 != 0) {
    iVar1 = EVP_PKEY_size(*(EVP_PKEY **)(param_1 + 0x94));
    in_r12 = (uint)(iVar5 + iVar1 * -8 < 0 == SBORROW4(iVar5,iVar1 * 8));
    uVar9 = *(uint *)(param_1 + 0xc4) & 1;
    uVar2 = uVar9;
    if (uVar9 == 0) goto LAB_0007b830;
LAB_0007ba30:
    iVar1 = EVP_PKEY_size(*(EVP_PKEY **)(param_1 + 0xb0));
    uVar2 = (uint)(iVar5 + iVar1 * -8 < 0 == SBORROW4(iVar5,iVar1 * 8));
    uVar4 = *(uint *)(param_1 + 0xe0) & 1;
    if (*(int *)(param_1 + 0x100) == 0) goto LAB_0007ba5c;
LAB_0007b842:
    if (*(int *)(param_1 + 0x104) == 0) goto LAB_0007ba5c;
    iVar5 = *(int *)(param_1 + 0xe4);
    uVar12 = 0x300;
    uVar6 = 0x200;
  }
  else {
    uVar9 = *(uint *)(param_1 + 0xc4) & 1;
    uVar2 = uVar9;
    if (uVar9 != 0) goto LAB_0007ba30;
LAB_0007b830:
    uVar4 = *(uint *)(param_1 + 0xe0) & 1;
    uVar9 = uVar2;
    if (*(int *)(param_1 + 0x100) != 0) goto LAB_0007b842;
LAB_0007ba5c:
    iVar5 = *(int *)(param_1 + 0xe4);
    uVar12 = 0x100;
    uVar6 = 0;
  }
  uVar13 = uVar6;
  if ((iVar5 != 0) && (*(int *)(param_1 + 0xe8) != 0)) {
    uVar6 = 0x200;
    uVar13 = uVar12;
  }
  if (uVar7 == 0) {
    if (uVar8 == 0) {
      local_34 = 0;
    }
    else {
      local_34 = local_34 & 1;
    }
    if (local_34 == 0) goto LAB_0007b882;
  }
  uVar6 = uVar6 | 1;
LAB_0007b882:
  if (bVar11) {
    uVar12 = 1;
  }
  else if (local_38 == 0) {
    uVar12 = 0;
  }
  else {
    uVar12 = (uint)((uVar7 | uVar8) != 0);
  }
  uVar7 = uVar7 | uVar8;
  if (local_3c != 0) {
    uVar12 = uVar12 | 8;
  }
  if (local_44 != 0) {
    uVar6 = uVar6 | 8;
  }
  if (uVar10 != 0) {
    uVar6 = uVar6 | 2;
  }
  if (in_r12 != 0) {
    uVar12 = uVar12 | 2;
  }
  if (uVar9 != 0) {
    uVar6 = uVar6 | 4;
  }
  if (uVar2 != 0) {
    uVar12 = uVar12 | 4;
  }
  if ((uVar6 & 6) != 0) {
    uVar13 = uVar13 | 8;
  }
  if (uVar7 != 0) {
    uVar13 = uVar13 | 1;
    uVar7 = 1;
  }
  if ((uVar3 & 2) != 0) {
    uVar13 = uVar13 | 2;
    uVar7 = uVar7 | 2;
  }
  uVar3 = uVar13 | 4;
  uVar10 = uVar7 | 4;
  if (uVar4 != 0) {
    x = *(X509 **)(param_1 + 200);
    X509_check_purpose(x,-1,0);
    if ((int)(x->ex_flags << 0x1e) < 0) {
      local_44 = x->ex_kusage & 8;
      uVar8 = x->ex_kusage & 0x80;
    }
    else {
      uVar8 = 1;
      local_44 = 1;
    }
    if ((*(uint *)(param_1 + 0xe0) & 2) == 0) {
      uVar8 = 0;
    }
    pkey = X509_get_pubkey(x);
    if (pkey == (EVP_PKEY *)0x0) {
      local_3c = 0;
    }
    else {
      local_3c = EVP_PKEY_bits(pkey);
    }
    EVP_PKEY_free(pkey);
    if ((x->sig_alg != (X509_ALGOR *)0x0) && (o = x->sig_alg->algorithm, o != (ASN1_OBJECT *)0x0)) {
      iVar5 = OBJ_obj2nid(o);
      OBJ_find_sigid_algs(iVar5,local_2c,&local_30);
    }
    if (local_44 != 0) {
      if (local_30 == 6 || local_30 == 0x13) {
        uVar6 = uVar6 | 0x20;
        uVar3 = uVar13 | 0x14;
        if (local_3c < 0xa4) {
          uVar12 = uVar12 | 0x20;
          uVar10 = uVar7 | 0x14;
        }
      }
      if (local_30 == 0x198) {
        uVar6 = uVar6 | 0x40;
        uVar3 = uVar3 | 0x10;
        if (local_3c < 0xa4) {
          uVar12 = uVar12 | 0x40;
          uVar10 = uVar10 | 0x10;
        }
      }
    }
    if (uVar8 != 0) {
      uVar3 = uVar3 | 0x40;
      uVar10 = uVar10 | 0x40;
    }
  }
  if (local_40 != 0) {
    uVar6 = uVar6 | 0x80;
    uVar12 = uVar12 | 0x80;
  }
  *(uint *)(param_1 + 8) = uVar6 | 0x100;
  *(uint *)(param_1 + 0xc) = uVar3 | 0x80;
  *(uint *)(param_1 + 0x10) = uVar12 | 0x100;
  *(uint *)(param_1 + 0x14) = uVar10 | 0x80;
  *(undefined4 *)(param_1 + 4) = 1;
  return;
}

