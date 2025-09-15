
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void adjust_quota_gcd(void)

{
  ulong uVar1;
  int iVar2;
  int iVar3;
  int extraout_r1;
  uint uVar4;
  pool **pppVar5;
  uint uVar7;
  pool *ppVar8;
  int iVar9;
  pool **pppVar10;
  pool **pppVar11;
  char tmp42 [2048];
  pool **pppVar6;
  
  pppVar11 = pools;
  iVar2 = total_pools;
  if (total_pools < 1) {
    uVar7 = 1;
  }
  else {
    uVar7 = 0xffffffff;
    pppVar10 = pools + total_pools;
    pppVar5 = pools;
    do {
      pppVar6 = pppVar5 + 1;
      uVar4 = (*pppVar5)->quota;
      if ((uVar4 != 0) && (uVar4 <= uVar7)) {
        uVar7 = uVar4;
      }
      pppVar5 = pppVar6;
    } while (pppVar6 != pppVar10);
    pppVar5 = pools;
    if (uVar7 == 0xffffffff) {
      uVar7 = 1;
    }
    else {
      do {
        while( true ) {
          pppVar6 = pppVar5 + 1;
          iVar9 = (*pppVar5)->quota;
          pppVar5 = pppVar6;
          if (iVar9 != 0) break;
          if (pppVar6 == pppVar10) goto LAB_0001e9c0;
        }
        while (__aeabi_uidivmod(iVar9,uVar7), extraout_r1 != 0) {
          uVar7 = uVar7 - 1;
        }
      } while (pppVar6 != pppVar10);
    }
LAB_0001e9c0:
    uVar1 = global_quota_gcd;
    pppVar11 = pppVar11 + -1;
    iVar9 = 0;
    do {
      pppVar11 = pppVar11 + 1;
      ppVar8 = *pppVar11;
      iVar9 = iVar9 + 1;
      iVar3 = __aeabi_uidiv(ppVar8->quota_used * uVar1,uVar7);
      ppVar8->quota_used = iVar3;
      iVar3 = __aeabi_uidiv(ppVar8->quota,uVar7);
      ppVar8->quota_gcd = iVar3;
    } while (iVar9 < iVar2);
  }
  global_quota_gcd = uVar7;
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"Global quota greatest common denominator set to %lu",uVar7);
    _applog(7,tmp42,false);
  }
  return;
}

