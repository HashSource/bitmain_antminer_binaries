
/* WARNING: Unknown calling convention */

work * get_queue_work(thr_info *thr,cgpu_info *cgpu,int thr_id)

{
  work *work_00;
  work *work;
  
  work_00 = get_work(thr,thr_id);
  add_queued(cgpu,work_00);
  return work_00;
}

