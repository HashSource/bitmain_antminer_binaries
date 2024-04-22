
/* WARNING: Unknown calling convention */

_Bool fulltest(uchar *hash,uchar *target)

{
  bool bVar1;
  char *pcVar2;
  uint *hash32;
  uint t32tmp;
  char *__ptr;
  char *hash_str;
  char *__ptr_00;
  char *target_str;
  uint *target32;
  int iVar3;
  int iVar4;
  uint *src;
  uint h32tmp;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uchar hash_swap [32];
  uchar target_swap [32];
  char tmp42 [2048];
  
  pcVar2 = DAT_000113b4;
  iVar3 = 0;
  do {
    iVar4 = iVar3 + -4;
    if (*(uint *)(target + iVar3 + 0x1c) < *(uint *)(hash + iVar3 + 0x1c)) {
      bVar1 = false;
      goto LAB_000112ae;
    }
  } while ((*(uint *)(target + iVar3 + 0x1c) <= *(uint *)(hash + iVar3 + 0x1c)) &&
          (iVar3 = iVar4, iVar4 != -0x20));
  bVar1 = true;
LAB_000112ae:
  if (*DAT_000113b4 != '\0') {
    uVar8 = *(uint *)(hash + 0x1c);
    uVar7 = *(uint *)(hash + 0x18);
    uVar6 = *(uint *)(hash + 0x14);
    uVar9 = *(uint *)(hash + 8);
    hash_swap._0_4_ =
         uVar8 << 0x18 | (uVar8 >> 8 & 0xff) << 0x10 | (uVar8 >> 0x10 & 0xff) << 8 | uVar8 >> 0x18;
    uVar8 = *(uint *)(hash + 0x10);
    hash_swap._4_4_ =
         uVar7 << 0x18 | (uVar7 >> 8 & 0xff) << 0x10 | (uVar7 >> 0x10 & 0xff) << 8 | uVar7 >> 0x18;
    uVar7 = *(uint *)hash;
    hash_swap._8_4_ =
         uVar6 << 0x18 | (uVar6 >> 8 & 0xff) << 0x10 | (uVar6 >> 0x10 & 0xff) << 8 | uVar6 >> 0x18;
    uVar6 = *(uint *)(hash + 0xc);
    uVar10 = *(uint *)(hash + 4);
    hash_swap._12_4_ =
         uVar8 << 0x18 | (uVar8 >> 8 & 0xff) << 0x10 | (uVar8 >> 0x10 & 0xff) << 8 | uVar8 >> 0x18;
    uVar8 = *(uint *)(target + 0x1c);
    hash_swap._20_4_ =
         uVar9 << 0x18 | (uVar9 >> 8 & 0xff) << 0x10 | (uVar9 >> 0x10 & 0xff) << 8 | uVar9 >> 0x18;
    hash_swap._28_4_ =
         uVar7 << 0x18 | (uVar7 >> 8 & 0xff) << 0x10 | (uVar7 >> 0x10 & 0xff) << 8 | uVar7 >> 0x18;
    hash_swap._16_4_ =
         uVar6 << 0x18 | (uVar6 >> 8 & 0xff) << 0x10 | (uVar6 >> 0x10 & 0xff) << 8 | uVar6 >> 0x18;
    target_swap._0_4_ =
         uVar8 << 0x18 | (uVar8 >> 8 & 0xff) << 0x10 | (uVar8 >> 0x10 & 0xff) << 8 | uVar8 >> 0x18;
    uVar8 = *(uint *)(target + 0x18);
    hash_swap._24_4_ =
         uVar10 << 0x18 | (uVar10 >> 8 & 0xff) << 0x10 | (uVar10 >> 0x10 & 0xff) << 8 |
         uVar10 >> 0x18;
    target_swap._4_4_ =
         uVar8 << 0x18 | (uVar8 >> 8 & 0xff) << 0x10 | (uVar8 >> 0x10 & 0xff) << 8 | uVar8 >> 0x18;
    uVar8 = *(uint *)(target + 0x14);
    uVar6 = *(uint *)(target + 8);
    target_swap._8_4_ =
         uVar8 << 0x18 | (uVar8 >> 8 & 0xff) << 0x10 | (uVar8 >> 0x10 & 0xff) << 8 | uVar8 >> 0x18;
    uVar8 = *(uint *)(target + 0x10);
    target_swap._20_4_ =
         uVar6 << 0x18 | (uVar6 >> 8 & 0xff) << 0x10 | (uVar6 >> 0x10 & 0xff) << 8 | uVar6 >> 0x18;
    target_swap._12_4_ =
         uVar8 << 0x18 | (uVar8 >> 8 & 0xff) << 0x10 | (uVar8 >> 0x10 & 0xff) << 8 | uVar8 >> 0x18;
    uVar6 = *(uint *)(target + 0xc);
    uVar8 = *(uint *)target;
    uVar7 = *(uint *)(target + 4);
    target_swap._16_4_ =
         uVar6 << 0x18 | (uVar6 >> 8 & 0xff) << 0x10 | (uVar6 >> 0x10 & 0xff) << 8 | uVar6 >> 0x18;
    target_swap._28_4_ =
         uVar8 << 0x18 | (uVar8 >> 8 & 0xff) << 0x10 | (uVar8 >> 0x10 & 0xff) << 8 | uVar8 >> 0x18;
    target_swap._24_4_ =
         uVar7 << 0x18 | (uVar7 >> 8 & 0xff) << 0x10 | (uVar7 >> 0x10 & 0xff) << 8 | uVar7 >> 0x18;
    __ptr = bin2hex(hash_swap,0x20);
    __ptr_00 = bin2hex(target_swap,0x20);
    if ((*pcVar2 != '\0') &&
       (((*DAT_000113b8 != '\0' || (*DAT_000113bc != '\0')) || (6 < *DAT_000113cc)))) {
      uVar5 = DAT_000113c4;
      if (!bVar1) {
        uVar5 = DAT_000113c0;
      }
      snprintf(tmp42,0x800,DAT_000113c8,__ptr,__ptr_00,uVar5);
      _applog(7,tmp42,false);
    }
    free(__ptr);
    free(__ptr_00);
  }
  return bVar1;
}

