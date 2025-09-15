
void adjust_quota_gcd(void)

{
  int iVar1;
  undefined4 uVar2;
  int extraout_r1;
  int extraout_r1_00;
  int *piVar3;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int *piVar11;
  char acStack_820 [2048];
  int *piVar4;
  
  piVar10 = pools;
  iVar1 = total_pools;
  if (total_pools < 1) {
    uVar6 = 1;
  }
  else {
    uVar6 = 0xffffffff;
    piVar11 = pools + total_pools;
    piVar3 = pools;
    do {
      piVar4 = piVar3 + 1;
      uVar5 = *(uint *)(*piVar3 + 0x38);
      if (uVar5 != 0 && uVar5 < uVar6) {
        uVar6 = uVar5;
      }
      piVar3 = piVar4;
    } while (piVar4 != piVar11);
    piVar3 = pools;
    if (uVar6 == 0xffffffff) {
      uVar6 = 1;
    }
    else {
      do {
        piVar4 = piVar3 + 1;
        iVar7 = *(int *)(*piVar3 + 0x38);
        if (iVar7 != 0) {
          __aeabi_uidivmod(iVar7,uVar6);
          iVar9 = extraout_r1;
          while (iVar9 != 0) {
            uVar6 = uVar6 - 1;
            __aeabi_uidivmod(iVar7,uVar6);
            iVar9 = extraout_r1_00;
          }
        }
        piVar3 = piVar4;
      } while (piVar4 != piVar11);
    }
    iVar7 = global_quota_gcd;
    piVar10 = piVar10 + -1;
    iVar9 = 0;
    do {
      piVar10 = piVar10 + 1;
      iVar8 = *piVar10;
      iVar9 = iVar9 + 1;
      uVar2 = __udivsi3(*(int *)(iVar8 + 0x40) * iVar7,uVar6);
      *(undefined4 *)(iVar8 + 0x40) = uVar2;
      uVar2 = __udivsi3(*(undefined4 *)(iVar8 + 0x38),uVar6);
      *(undefined4 *)(iVar8 + 0x3c) = uVar2;
    } while (iVar9 < iVar1);
  }
  global_quota_gcd = uVar6;
  if ((opt_debug != '\0') &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
    snprintf(acStack_820,0x800,"Global quota greatest common denominator set to %lu",uVar6);
    _applog(7,acStack_820,0);
  }
  return;
}

