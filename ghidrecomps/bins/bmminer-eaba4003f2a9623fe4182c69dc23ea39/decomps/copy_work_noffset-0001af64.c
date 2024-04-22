
work * copy_work_noffset(work *base_work,int noffset)

{
  work *work_00;
  int noffset_local;
  work *base_work_local;
  work *work;
  
  work_00 = make_work();
  _copy_work(work_00,base_work,noffset);
  return work_00;
}

