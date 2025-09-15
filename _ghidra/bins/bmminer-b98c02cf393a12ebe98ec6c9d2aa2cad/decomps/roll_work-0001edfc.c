
void roll_work(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint local_810;
  char acStack_80c [2044];
  
  cVar1 = opt_debug;
  uVar3 = *(uint *)(param_1 + 0x44);
  uVar3 = (uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 | uVar3 >> 0x18
          ) + 1;
  local_work = local_work + 1;
  *(uint *)(param_1 + 0x44) =
       uVar3 * 0x1000000 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 | uVar3 >> 0x18
  ;
  *(int *)(param_1 + 0xf0) = *(int *)(param_1 + 0xf0) + 1;
  *(undefined4 *)(param_1 + 0xf8) = 0;
  if ((cVar1 != '\0') && (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))
     ) {
    local_810._0_1_ = 'S';
    local_810._1_1_ = 'u';
    local_810._2_1_ = 'c';
    local_810._3_1_ = 'c';
    builtin_strncpy(acStack_80c,"essfully rolled work",0x14);
    acStack_80c[0x14] = 0;
    _applog(7,&local_810,0);
  }
  iVar4 = *(int *)(param_1 + 0x134);
  if (iVar4 != 0) {
    hex2bin(&local_810,iVar4,4);
    uVar3 = (local_810 << 0x18 | (local_810 >> 8 & 0xff) << 0x10 | (local_810 >> 0x10 & 0xff) << 8 |
            local_810 >> 0x18) + 1;
    local_810 = uVar3 * 0x1000000 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 |
                uVar3 >> 0x18;
    __bin2hex(iVar4,&local_810,4);
  }
  uVar2 = total_work_inc();
  *(undefined4 *)(param_1 + 0x154) = uVar2;
  return;
}

