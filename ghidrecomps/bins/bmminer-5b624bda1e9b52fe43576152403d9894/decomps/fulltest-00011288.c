
/* WARNING: Unknown calling convention */

_Bool fulltest(uchar *hash,uchar *target)

{
  bool bVar1;
  char *__ptr;
  char *__ptr_00;
  int iVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uchar hash_swap [32];
  uchar target_swap [32];
  char tmp42 [2048];
  
  iVar2 = 0;
  do {
    iVar3 = iVar2 + -4;
    if (*(uint *)(target + iVar2 + 0x1c) < *(uint *)(hash + iVar2 + 0x1c)) {
      bVar1 = false;
      goto LAB_000112ae;
    }
  } while ((*(uint *)(target + iVar2 + 0x1c) <= *(uint *)(hash + iVar2 + 0x1c)) &&
          (iVar2 = iVar3, iVar3 != -0x20));
  bVar1 = true;
LAB_000112ae:
  if (opt_debug) {
    uVar7 = *(uint *)(hash + 0x1c);
    uVar6 = *(uint *)(hash + 0x18);
    uVar5 = *(uint *)(hash + 0x14);
    uVar8 = *(uint *)(hash + 8);
    hash_swap._0_4_ =
         uVar7 << 0x18 | (uVar7 >> 8 & 0xff) << 0x10 | (uVar7 >> 0x10 & 0xff) << 8 | uVar7 >> 0x18;
    uVar7 = *(uint *)(hash + 0x10);
    hash_swap._4_4_ =
         uVar6 << 0x18 | (uVar6 >> 8 & 0xff) << 0x10 | (uVar6 >> 0x10 & 0xff) << 8 | uVar6 >> 0x18;
    uVar6 = *(uint *)hash;
    hash_swap._8_4_ =
         uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 | uVar5 >> 0x18;
    uVar5 = *(uint *)(hash + 0xc);
    uVar9 = *(uint *)(hash + 4);
    hash_swap._12_4_ =
         uVar7 << 0x18 | (uVar7 >> 8 & 0xff) << 0x10 | (uVar7 >> 0x10 & 0xff) << 8 | uVar7 >> 0x18;
    uVar7 = *(uint *)(target + 0x1c);
    hash_swap._20_4_ =
         uVar8 << 0x18 | (uVar8 >> 8 & 0xff) << 0x10 | (uVar8 >> 0x10 & 0xff) << 8 | uVar8 >> 0x18;
    hash_swap._28_4_ =
         uVar6 << 0x18 | (uVar6 >> 8 & 0xff) << 0x10 | (uVar6 >> 0x10 & 0xff) << 8 | uVar6 >> 0x18;
    hash_swap._16_4_ =
         uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 | uVar5 >> 0x18;
    target_swap._0_4_ =
         uVar7 << 0x18 | (uVar7 >> 8 & 0xff) << 0x10 | (uVar7 >> 0x10 & 0xff) << 8 | uVar7 >> 0x18;
    uVar7 = *(uint *)(target + 0x18);
    hash_swap._24_4_ =
         uVar9 << 0x18 | (uVar9 >> 8 & 0xff) << 0x10 | (uVar9 >> 0x10 & 0xff) << 8 | uVar9 >> 0x18;
    target_swap._4_4_ =
         uVar7 << 0x18 | (uVar7 >> 8 & 0xff) << 0x10 | (uVar7 >> 0x10 & 0xff) << 8 | uVar7 >> 0x18;
    uVar7 = *(uint *)(target + 0x14);
    uVar5 = *(uint *)(target + 8);
    target_swap._8_4_ =
         uVar7 << 0x18 | (uVar7 >> 8 & 0xff) << 0x10 | (uVar7 >> 0x10 & 0xff) << 8 | uVar7 >> 0x18;
    uVar7 = *(uint *)(target + 0x10);
    target_swap._20_4_ =
         uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 | uVar5 >> 0x18;
    target_swap._12_4_ =
         uVar7 << 0x18 | (uVar7 >> 8 & 0xff) << 0x10 | (uVar7 >> 0x10 & 0xff) << 8 | uVar7 >> 0x18;
    uVar5 = *(uint *)(target + 0xc);
    uVar7 = *(uint *)target;
    uVar6 = *(uint *)(target + 4);
    target_swap._16_4_ =
         uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 | uVar5 >> 0x18;
    target_swap._28_4_ =
         uVar7 << 0x18 | (uVar7 >> 8 & 0xff) << 0x10 | (uVar7 >> 0x10 & 0xff) << 8 | uVar7 >> 0x18;
    target_swap._24_4_ =
         uVar6 << 0x18 | (uVar6 >> 8 & 0xff) << 0x10 | (uVar6 >> 0x10 & 0xff) << 8 | uVar6 >> 0x18;
    __ptr = bin2hex(hash_swap,0x20);
    __ptr_00 = bin2hex(target_swap,0x20);
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      pcVar4 = "YES (hash <= target)";
      if (!bVar1) {
        pcVar4 = "no (false positive; hash > target)";
      }
      snprintf(tmp42,0x800," Proof: %s\nTarget: %s\nTrgVal? %s",__ptr,__ptr_00,pcVar4);
      _applog(7,tmp42,false);
    }
    free(__ptr);
    free(__ptr_00);
  }
  return bVar1;
}

