
/* WARNING: Unknown calling convention */

send_ret __stratum_send(pool *pool,char *s,ssize_t len)

{
  uint64_t *puVar1;
  uint64_t *puVar2;
  uint64_t *puVar3;
  size_t sVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  size_t __n;
  int iVar12;
  uint local_83c;
  timeval timeout;
  fd_set wd;
  
  uVar7 = pool->sock;
  if (((opt_protocol) && (opt_debug)) && ((use_syslog || ((opt_log_output || (6 < opt_log_level)))))
     ) {
    snprintf((char *)&wd,0x800,"SEND: %s",s);
    _applog(7,(char *)&wd,false);
  }
  __n = len + 1;
  sVar4 = strlen(s);
  (s + sVar4)[0] = '\n';
  (s + sVar4)[1] = '\0';
  if (0 < (int)__n) {
    uVar8 = uVar7 + 0x1f & (int)uVar7 >> 0x20;
    if (((uint)((int)uVar7 >> 0x1f) >> 0x1a & 1) == 0) {
      uVar8 = uVar7;
    }
    local_83c = 0;
LAB_00010d04:
    uVar10 = 0;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    do {
      if (0x1f < uVar10) {
        ((fd_set *)&wd)->fds_bits[(int)uVar8 >> 5] =
             1 << ((int)uVar7 % 0x20 & 0xffU) | ((fd_set *)&wd)->fds_bits[(int)uVar8 >> 5];
        iVar5 = select(uVar7 + 1,(fd_set *)0x0,(fd_set *)&wd,(fd_set *)0x0,(timeval *)&timeout);
        if (0 < iVar5) goto LAB_00010d46;
        piVar6 = __errno_location();
        uVar10 = 0;
        if (*piVar6 != 4) {
          return SEND_SELECTFAIL;
        }
      }
      ((fd_set *)&wd)->fds_bits[uVar10] = 0;
      uVar10 = uVar10 + 1;
    } while( true );
  }
  local_83c = 0;
  iVar5 = 0;
LAB_00010d74:
  puVar1 = &(pool->cgminer_pool_stats).times_sent;
  uVar7 = (uint)*puVar1;
  iVar9 = *(int *)((int)&(pool->cgminer_pool_stats).times_sent + 4);
  puVar2 = &(pool->cgminer_pool_stats).bytes_sent;
  uVar8 = (uint)*puVar2;
  iVar11 = *(int *)((int)&(pool->cgminer_pool_stats).bytes_sent + 4);
  puVar3 = &(pool->cgminer_pool_stats).net_bytes_sent;
  uVar10 = (uint)*puVar3;
  iVar12 = *(int *)((int)&(pool->cgminer_pool_stats).net_bytes_sent + 4);
  *(uint *)puVar1 = uVar7 + 1;
  *(uint *)((int)&(pool->cgminer_pool_stats).times_sent + 4) = iVar9 + (uint)(0xfffffffe < uVar7);
  *(uint *)puVar2 = uVar8 + local_83c;
  *(uint *)((int)&(pool->cgminer_pool_stats).bytes_sent + 4) =
       iVar11 + iVar5 + (uint)CARRY4(uVar8,local_83c);
  *(uint *)puVar3 = local_83c + uVar10;
  *(uint *)((int)&(pool->cgminer_pool_stats).net_bytes_sent + 4) =
       iVar5 + iVar12 + (uint)CARRY4(local_83c,uVar10);
  return SEND_OK;
LAB_00010d46:
  iVar5 = send(pool->sock,s + local_83c,__n,0x4000);
  if (iVar5 < 0) {
    piVar6 = __errno_location();
    if (*piVar6 != 0xb) {
      return SEND_SENDFAIL;
    }
    iVar5 = 0;
  }
  __n = __n - iVar5;
  local_83c = local_83c + iVar5;
  if ((int)__n < 1) goto code_r0x00010d70;
  goto LAB_00010d04;
code_r0x00010d70:
  iVar5 = (int)local_83c >> 0x1f;
  goto LAB_00010d74;
}

