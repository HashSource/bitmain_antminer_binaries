
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void flush_queue(cgpu_info *cgpu)

{
  int iVar1;
  cgpu_info *cgpu_local;
  char tmp42 [2048];
  work *work;
  
  work = (work *)0x0;
  if ((cgpu != (cgpu_info *)0x0) &&
     (iVar1 = _wr_trylock(&cgpu->qlock,"cgminer.c","flush_queue",0x2520), iVar1 == 0)) {
    work = cgpu->unqueued_work;
    cgpu->unqueued_work = (work *)0x0;
    _wr_unlock(&cgpu->qlock,"cgminer.c","flush_queue",0x2527);
    if (((work != (work *)0x0) &&
        (_free_work(&work,"cgminer.c","flush_queue",0x252b), opt_debug != false)) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      tmp42[0] = s_Discarded_queued_work_item_000742f8[0];
      tmp42[1] = s_Discarded_queued_work_item_000742f8[1];
      tmp42[2] = s_Discarded_queued_work_item_000742f8[2];
      tmp42[3] = s_Discarded_queued_work_item_000742f8[3];
      tmp42[4] = s_Discarded_queued_work_item_000742f8[4];
      tmp42[5] = s_Discarded_queued_work_item_000742f8[5];
      tmp42[6] = s_Discarded_queued_work_item_000742f8[6];
      tmp42[7] = s_Discarded_queued_work_item_000742f8[7];
      tmp42[8] = s_Discarded_queued_work_item_000742f8[8];
      tmp42[9] = s_Discarded_queued_work_item_000742f8[9];
      tmp42[10] = s_Discarded_queued_work_item_000742f8[10];
      tmp42[11] = s_Discarded_queued_work_item_000742f8[11];
      tmp42[12] = s_Discarded_queued_work_item_000742f8[12];
      tmp42[13] = s_Discarded_queued_work_item_000742f8[13];
      tmp42[14] = s_Discarded_queued_work_item_000742f8[14];
      tmp42[15] = s_Discarded_queued_work_item_000742f8[15];
      tmp42[16] = s_Discarded_queued_work_item_000742f8[16];
      tmp42[17] = s_Discarded_queued_work_item_000742f8[17];
      tmp42[18] = s_Discarded_queued_work_item_000742f8[18];
      tmp42[19] = s_Discarded_queued_work_item_000742f8[19];
      tmp42[20] = s_Discarded_queued_work_item_000742f8[20];
      tmp42[21] = s_Discarded_queued_work_item_000742f8[21];
      tmp42[22] = s_Discarded_queued_work_item_000742f8[22];
      tmp42[23] = s_Discarded_queued_work_item_000742f8[23];
      tmp42._24_2_ = (undefined2)ram0x00074310;
      tmp42[26] = (char)((uint)ram0x00074310 >> 0x10);
      _applog(7,tmp42,false);
    }
  }
  return;
}

