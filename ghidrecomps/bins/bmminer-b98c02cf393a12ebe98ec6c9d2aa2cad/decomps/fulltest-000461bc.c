
int fulltest(uint *param_1,uint *param_2)

{
  void *__ptr;
  void *__ptr_00;
  uint *puVar1;
  uint *puVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint local_858;
  uint local_854;
  uint local_850;
  uint local_84c;
  uint local_848;
  uint local_844;
  uint local_840;
  uint local_83c;
  uint local_838;
  uint local_834;
  uint local_830;
  uint local_82c;
  uint local_828;
  uint local_824;
  uint local_820;
  uint local_81c;
  char acStack_818 [2048];
  
  puVar2 = param_1 + 8;
  puVar1 = param_2 + 8;
  do {
    puVar2 = puVar2 + -1;
    puVar1 = puVar1 + -1;
    if (*puVar1 < *puVar2) {
      iVar4 = 0;
      goto LAB_000461e2;
    }
  } while ((*puVar1 <= *puVar2) && (puVar2 != param_1));
  iVar4 = 1;
LAB_000461e2:
  if (opt_debug != '\0') {
    uVar7 = param_1[7];
    uVar6 = param_1[6];
    uVar5 = param_1[5];
    local_858 = uVar7 << 0x18 | (uVar7 >> 8 & 0xff) << 0x10 | (uVar7 >> 0x10 & 0xff) << 8 |
                uVar7 >> 0x18;
    local_854 = uVar6 << 0x18 | (uVar6 >> 8 & 0xff) << 0x10 | (uVar6 >> 0x10 & 0xff) << 8 |
                uVar6 >> 0x18;
    uVar7 = param_1[3];
    local_850 = uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                uVar5 >> 0x18;
    uVar5 = param_1[2];
    uVar6 = param_1[4];
    local_848 = uVar7 << 0x18 | (uVar7 >> 8 & 0xff) << 0x10 | (uVar7 >> 0x10 & 0xff) << 8 |
                uVar7 >> 0x18;
    uVar7 = *param_1;
    uVar8 = param_1[1];
    local_844 = uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                uVar5 >> 0x18;
    uVar5 = param_2[6];
    local_84c = uVar6 << 0x18 | (uVar6 >> 8 & 0xff) << 0x10 | (uVar6 >> 0x10 & 0xff) << 8 |
                uVar6 >> 0x18;
    local_83c = uVar7 << 0x18 | (uVar7 >> 8 & 0xff) << 0x10 | (uVar7 >> 0x10 & 0xff) << 8 |
                uVar7 >> 0x18;
    uVar6 = param_2[7];
    local_834 = uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                uVar5 >> 0x18;
    local_840 = uVar8 << 0x18 | (uVar8 >> 8 & 0xff) << 0x10 | (uVar8 >> 0x10 & 0xff) << 8 |
                uVar8 >> 0x18;
    uVar5 = param_2[4];
    local_838 = uVar6 << 0x18 | (uVar6 >> 8 & 0xff) << 0x10 | (uVar6 >> 0x10 & 0xff) << 8 |
                uVar6 >> 0x18;
    uVar6 = param_2[5];
    local_82c = uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                uVar5 >> 0x18;
    local_830 = uVar6 << 0x18 | (uVar6 >> 8 & 0xff) << 0x10 | (uVar6 >> 0x10 & 0xff) << 8 |
                uVar6 >> 0x18;
    uVar6 = param_2[2];
    uVar7 = param_2[3];
    uVar5 = param_2[1];
    local_824 = uVar6 << 0x18 | (uVar6 >> 8 & 0xff) << 0x10 | (uVar6 >> 0x10 & 0xff) << 8 |
                uVar6 >> 0x18;
    uVar6 = *param_2;
    local_828 = uVar7 << 0x18 | (uVar7 >> 8 & 0xff) << 0x10 | (uVar7 >> 0x10 & 0xff) << 8 |
                uVar7 >> 0x18;
    local_820 = uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                uVar5 >> 0x18;
    local_81c = uVar6 << 0x18 | (uVar6 >> 8 & 0xff) << 0x10 | (uVar6 >> 0x10 & 0xff) << 8 |
                uVar6 >> 0x18;
    __ptr = (void *)bin2hex(&local_858,0x20);
    __ptr_00 = (void *)bin2hex(&local_838,0x20);
    if ((opt_debug != '\0') &&
       (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      pcVar3 = "YES (hash <= target)";
      if (iVar4 == 0) {
        pcVar3 = "no (false positive; hash > target)";
      }
      snprintf(acStack_818,0x800," Proof: %s\nTarget: %s\nTrgVal? %s",__ptr,__ptr_00,pcVar3);
      _applog(7,acStack_818,0);
    }
    free(__ptr);
    free(__ptr_00);
    return iVar4;
  }
  return iVar4;
}

