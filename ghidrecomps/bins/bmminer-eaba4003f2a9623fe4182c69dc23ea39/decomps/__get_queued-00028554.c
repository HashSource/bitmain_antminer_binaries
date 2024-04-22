
work * __get_queued(cgpu_info *cgpu)

{
  _Bool _Var1;
  cgpu_info *cgpu_local;
  work *work;
  
  work = (work *)0x0;
  if (cgpu->unqueued_work != (work *)0x0) {
    work = cgpu->unqueued_work;
    _Var1 = stale_work(work,false);
    if (_Var1) {
      _discard_work(&work,"cgminer.c","__get_queued",0x2449);
      wake_gws();
    }
    else {
      __add_queued(cgpu,work);
    }
    cgpu->unqueued_work = (work *)0x0;
  }
  return work;
}

