
/* WARNING: Unknown calling convention */

work * get_queue_work(thr_info *thr,cgpu_info *cgpu,int thr_id)

{
  work *work;
  
  work = get_work(thr,thr_id);
  add_queued(cgpu,work);
  return work;
}

