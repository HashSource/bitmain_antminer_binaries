
/* WARNING: Unknown calling convention */

void adjust_quota_gcd(void)

{
  int iVar1;
  int extraout_r1;
  uint uVar2;
  pool *ppVar3;
  char tmp42 [2048];
  ulong quota;
  pool *pool;
  int i;
  ulong lowest_quota;
  ulong gcd;
  
  lowest_quota = 0xffffffff;
  for (i = 0; i < total_pools; i = i + 1) {
    uVar2 = pools[i]->quota;
    if ((uVar2 != 0) && (uVar2 < lowest_quota)) {
      lowest_quota = uVar2;
    }
  }
  if (lowest_quota == 0xffffffff) {
    gcd = 1;
  }
  else {
    gcd = lowest_quota;
    for (i = 0; i < total_pools; i = i + 1) {
      iVar1 = pools[i]->quota;
      if (iVar1 != 0) {
        while (__aeabi_uidivmod(iVar1,gcd), extraout_r1 != 0) {
          gcd = gcd - 1;
        }
      }
    }
  }
  for (i = 0; i < total_pools; i = i + 1) {
    ppVar3 = pools[i];
    ppVar3->quota_used = global_quota_gcd * ppVar3->quota_used;
    iVar1 = __aeabi_uidiv(ppVar3->quota_used,gcd);
    ppVar3->quota_used = iVar1;
    iVar1 = __aeabi_uidiv(ppVar3->quota,gcd);
    ppVar3->quota_gcd = iVar1;
  }
  global_quota_gcd = gcd;
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"Global quota greatest common denominator set to %lu",gcd);
    _applog(7,tmp42,false);
  }
  return;
}

