
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention */

work * make_work(void)

{
  work *pwVar1;
  uint uVar2;
  char tmp42 [2048];
  work *work;
  
  pwVar1 = (work *)_cgcalloc(1,0x1c0,"cgminer.c","make_work",0x896);
  if (pwVar1 == (work *)0x0) {
    tmp42[0] = s_Failed_to_calloc_work_in_make_wo_000728f0[0];
    tmp42[1] = s_Failed_to_calloc_work_in_make_wo_000728f0[1];
    tmp42[2] = s_Failed_to_calloc_work_in_make_wo_000728f0[2];
    tmp42[3] = s_Failed_to_calloc_work_in_make_wo_000728f0[3];
    tmp42[4] = s_Failed_to_calloc_work_in_make_wo_000728f0[4];
    tmp42[5] = s_Failed_to_calloc_work_in_make_wo_000728f0[5];
    tmp42[6] = s_Failed_to_calloc_work_in_make_wo_000728f0[6];
    tmp42[7] = s_Failed_to_calloc_work_in_make_wo_000728f0[7];
    tmp42[8] = s_Failed_to_calloc_work_in_make_wo_000728f0[8];
    tmp42[9] = s_Failed_to_calloc_work_in_make_wo_000728f0[9];
    tmp42[10] = s_Failed_to_calloc_work_in_make_wo_000728f0[10];
    tmp42[11] = s_Failed_to_calloc_work_in_make_wo_000728f0[11];
    tmp42[12] = s_Failed_to_calloc_work_in_make_wo_000728f0[12];
    tmp42[13] = s_Failed_to_calloc_work_in_make_wo_000728f0[13];
    tmp42[14] = s_Failed_to_calloc_work_in_make_wo_000728f0[14];
    tmp42[15] = s_Failed_to_calloc_work_in_make_wo_000728f0[15];
    tmp42[16] = s_Failed_to_calloc_work_in_make_wo_000728f0[16];
    tmp42[17] = s_Failed_to_calloc_work_in_make_wo_000728f0[17];
    tmp42[18] = s_Failed_to_calloc_work_in_make_wo_000728f0[18];
    tmp42[19] = s_Failed_to_calloc_work_in_make_wo_000728f0[19];
    tmp42[20] = s_Failed_to_calloc_work_in_make_wo_000728f0[20];
    tmp42[21] = s_Failed_to_calloc_work_in_make_wo_000728f0[21];
    tmp42[22] = s_Failed_to_calloc_work_in_make_wo_000728f0[22];
    tmp42[23] = s_Failed_to_calloc_work_in_make_wo_000728f0[23];
    tmp42[24] = s_Failed_to_calloc_work_in_make_wo_000728f0[24];
    tmp42[25] = s_Failed_to_calloc_work_in_make_wo_000728f0[25];
    tmp42[26] = s_Failed_to_calloc_work_in_make_wo_000728f0[26];
    tmp42[27] = s_Failed_to_calloc_work_in_make_wo_000728f0[27];
    tmp42[28] = s_Failed_to_calloc_work_in_make_wo_000728f0[28];
    tmp42[29] = s_Failed_to_calloc_work_in_make_wo_000728f0[29];
    tmp42[30] = s_Failed_to_calloc_work_in_make_wo_000728f0[30];
    tmp42[31] = s_Failed_to_calloc_work_in_make_wo_000728f0[31];
    tmp42._32_2_ = (undefined2)ram0x00072910;
    tmp42[34] = (char)((uint)ram0x00072910 >> 0x10);
    _applog(3,tmp42,true);
    _quit(1);
  }
  uVar2 = total_work_inc();
  pwVar1->id = uVar2;
  return pwVar1;
}

