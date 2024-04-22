
work * get_queue_work(thr_info *thr,cgpu_info *cgpu,int thr_id)

{
  work *work_00;
  int thr_id_local;
  cgpu_info *cgpu_local;
  thr_info *thr_local;
  work *work;
  
  work_00 = get_work(thr,thr_id);
  add_queued(cgpu,work_00);
  return work_00;
}

