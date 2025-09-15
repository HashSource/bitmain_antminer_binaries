
work * make_clone(work *work)

{
  work *pwVar1;
  work *work_local;
  work *work_clone;
  
  pwVar1 = copy_work_noffset(work,0);
  pwVar1->clone = true;
  cgtime(&pwVar1->tv_cloned);
  pwVar1->longpoll = false;
  pwVar1->mandatory = false;
  (pwVar1->tv_staged).tv_sec = (pwVar1->tv_staged).tv_sec + -1;
  return pwVar1;
}

