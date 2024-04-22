
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void roll_work(work *work)

{
  uint __bsx;
  uint uVar1;
  work *work_local;
  char tmp42 [2048];
  uint ntime;
  uint *work_ntime;
  
  uVar1 = *(uint *)(work->data + 0x44);
  uVar1 = (uVar1 << 0x18 | uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8) + 1;
  *(uint *)(work->data + 0x44) =
       uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 * 0x1000000;
  local_work = local_work + 1;
  work->rolls = work->rolls + 1;
  work->nonce = 0;
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    tmp42[0] = s_Successfully_rolled_work_00072f08[0];
    tmp42[1] = s_Successfully_rolled_work_00072f08[1];
    tmp42[2] = s_Successfully_rolled_work_00072f08[2];
    tmp42[3] = s_Successfully_rolled_work_00072f08[3];
    tmp42[4] = s_Successfully_rolled_work_00072f08[4];
    tmp42[5] = s_Successfully_rolled_work_00072f08[5];
    tmp42[6] = s_Successfully_rolled_work_00072f08[6];
    tmp42[7] = s_Successfully_rolled_work_00072f08[7];
    tmp42[8] = s_Successfully_rolled_work_00072f08[8];
    tmp42[9] = s_Successfully_rolled_work_00072f08[9];
    tmp42[10] = s_Successfully_rolled_work_00072f08[10];
    tmp42[11] = s_Successfully_rolled_work_00072f08[11];
    tmp42[12] = s_Successfully_rolled_work_00072f08[12];
    tmp42[13] = s_Successfully_rolled_work_00072f08[13];
    tmp42[14] = s_Successfully_rolled_work_00072f08[14];
    tmp42[15] = s_Successfully_rolled_work_00072f08[15];
    tmp42[16] = s_Successfully_rolled_work_00072f08[16];
    tmp42[17] = s_Successfully_rolled_work_00072f08[17];
    tmp42[18] = s_Successfully_rolled_work_00072f08[18];
    tmp42[19] = s_Successfully_rolled_work_00072f08[19];
    tmp42[20] = s_Successfully_rolled_work_00072f08[20];
    tmp42[21] = s_Successfully_rolled_work_00072f08[21];
    tmp42[22] = s_Successfully_rolled_work_00072f08[22];
    tmp42[23] = s_Successfully_rolled_work_00072f08[23];
    tmp42[24] = (char)ram0x00072f20;
    _applog(7,tmp42,false);
  }
  if (work->ntime != (char *)0x0) {
    modify_ntime(work->ntime,1);
  }
  uVar1 = total_work_inc();
  work->id = uVar1;
  return;
}

