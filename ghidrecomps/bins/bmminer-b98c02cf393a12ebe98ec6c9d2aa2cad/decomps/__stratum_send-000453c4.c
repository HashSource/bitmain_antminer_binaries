
/* WARNING: Removing unreachable block (ram,0x00045438) */

undefined4 __stratum_send(int param_1,char *param_2,int param_3)

{
  size_t sVar1;
  int iVar2;
  int *piVar3;
  ssize_t sVar4;
  __suseconds_t *p_Var5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint local_844;
  size_t local_840;
  timeval local_830;
  fd_set local_828 [16];
  
  uVar6 = *(uint *)(param_1 + 0x24c);
  if ((opt_protocol != '\0') &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (4 < opt_log_level)))) {
    snprintf((char *)local_828,0x800,"SEND: %s",param_2);
    _applog(5,local_828,0);
  }
  local_840 = param_3 + 1;
  sVar1 = strlen(param_2);
  *(undefined2 *)(param_2 + sVar1) = DAT_00065a34;
  if ((int)local_840 < 1) {
    local_844 = 0;
    iVar7 = 0;
  }
  else {
    uVar9 = uVar6 & 0x1f;
    if ((int)uVar6 < 1) {
      uVar9 = -(-uVar6 & 0x1f);
    }
    iVar7 = (int)(uVar6 + 0x1f & (int)uVar6 >> 0x20) >> 5;
    local_844 = 0;
    do {
      while( true ) {
        local_830.tv_sec = 1;
        local_830.tv_usec = 0;
        while( true ) {
          p_Var5 = &local_830.tv_usec;
          do {
            p_Var5 = p_Var5 + 1;
            *p_Var5 = 0;
          } while (local_828[0].fds_bits + 0x1f != p_Var5);
          local_828[0].fds_bits[iVar7] = local_828[0].fds_bits[iVar7] | 1 << (uVar9 & 0xff);
          iVar2 = select(uVar6 + 1,(fd_set *)0x0,local_828,(fd_set *)0x0,&local_830);
          if (0 < iVar2) break;
          piVar3 = __errno_location();
          if (*piVar3 != 4) {
            return 1;
          }
        }
        sVar4 = send(*(int *)(param_1 + 0x24c),param_2 + local_844,local_840,0x4000);
        if (-1 < sVar4) break;
        piVar3 = __errno_location();
        if (*piVar3 != 0xb) {
          return 2;
        }
      }
      local_840 = local_840 - sVar4;
      local_844 = local_844 + sVar4;
    } while (0 < (int)local_840);
    iVar7 = (int)local_844 >> 0x1f;
  }
  uVar6 = *(uint *)(param_1 + 0x1f0);
  uVar8 = *(uint *)(param_1 + 0x1f8);
  uVar9 = *(uint *)(param_1 + 0x200);
  *(uint *)(param_1 + 0x1f0) = uVar6 + 1;
  *(uint *)(param_1 + 500) = *(int *)(param_1 + 500) + (uint)(0xfffffffe < uVar6);
  *(uint *)(param_1 + 0x1f8) = uVar8 + local_844;
  *(uint *)(param_1 + 0x1fc) = *(int *)(param_1 + 0x1fc) + iVar7 + (uint)CARRY4(uVar8,local_844);
  *(uint *)(param_1 + 0x200) = local_844 + uVar9;
  *(uint *)(param_1 + 0x204) = iVar7 + *(int *)(param_1 + 0x204) + (uint)CARRY4(local_844,uVar9);
  return 0;
}

