
/* WARNING: Unknown calling convention */

work * __get_queued(cgpu_info *cgpu)

{
  _Bool _Var1;
  work *work;
  work *local_c;
  
  local_c = cgpu->unqueued_work;
  if (local_c != (work *)0x0) {
    _Var1 = stale_work(local_c,false);
    if (_Var1) {
      _discard_work(&local_c,DAT_000289e8,DAT_000289ec,0x2442);
      wake_gws();
    }
    else {
      __add_queued(cgpu,local_c);
    }
    cgpu->unqueued_work = (work *)0x0;
  }
  return local_c;
}

