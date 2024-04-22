
/* WARNING: Unknown calling convention */

void adjust_quota_gcd(void)

{
  char *pcVar1;
  undefined4 uVar2;
  int extraout_r1;
  pool *pool;
  ulong quota;
  int *piVar3;
  pool *ppVar5;
  ulong gcd;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int *piVar11;
  int iVar12;
  char tmp42 [2048];
  int *piVar4;
  
  iVar9 = *DAT_0001ea48;
  if (iVar9 < 1) {
    ppVar5 = (pool *)0x1;
    iVar6 = DAT_0001ea64;
  }
  else {
    ppVar5 = (pool *)0xffffffff;
    piVar11 = *DAT_0001ea4c;
    piVar10 = piVar11 + iVar9;
    piVar3 = piVar11;
    do {
      piVar4 = piVar3 + 1;
      pool = *(pool **)(*piVar3 + 0x38);
      if ((pool != (pool *)0x0) && (pool <= ppVar5)) {
        ppVar5 = pool;
      }
      piVar3 = piVar4;
    } while (piVar4 != piVar10);
    piVar3 = piVar11;
    if (ppVar5 == (pool *)0xffffffff) {
      ppVar5 = (pool *)0x1;
    }
    else {
      do {
        while( true ) {
          piVar4 = piVar3 + 1;
          iVar6 = *(int *)(*piVar3 + 0x38);
          piVar3 = piVar4;
          if (iVar6 != 0) break;
          if (piVar4 == piVar10) goto LAB_0001e9c0;
        }
        while (__aeabi_uidivmod(iVar6,ppVar5), extraout_r1 != 0) {
          ppVar5 = (pool *)&ppVar5[-1].field_0x737;
        }
      } while (piVar4 != piVar10);
    }
LAB_0001e9c0:
    iVar6 = DAT_0001ea64;
    piVar11 = piVar11 + -1;
    iVar8 = 0;
    iVar12 = *(int *)(DAT_0001ea64 + 0x7e0);
    do {
      piVar11 = piVar11 + 1;
      iVar7 = *piVar11;
      iVar8 = iVar8 + 1;
      uVar2 = __aeabi_uidiv(*(int *)(iVar7 + 0x40) * iVar12,ppVar5);
      *(undefined4 *)(iVar7 + 0x40) = uVar2;
      uVar2 = __aeabi_uidiv(*(undefined4 *)(iVar7 + 0x38),ppVar5);
      *(undefined4 *)(iVar7 + 0x3c) = uVar2;
    } while (iVar8 < iVar9);
  }
  pcVar1 = DAT_0001ea50;
  *(pool **)(iVar6 + 0x7e0) = ppVar5;
  if ((*pcVar1 != '\0') &&
     (((*DAT_0001ea54 != '\0' || (*DAT_0001ea58 != '\0')) || (6 < *DAT_0001ea5c)))) {
    snprintf(tmp42,0x800,DAT_0001ea60,ppVar5);
    _applog(7,tmp42,false);
  }
  return;
}

