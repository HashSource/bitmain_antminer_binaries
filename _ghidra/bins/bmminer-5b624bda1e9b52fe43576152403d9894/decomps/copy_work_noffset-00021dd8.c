
/* WARNING: Unknown calling convention */

work * copy_work_noffset(work *base_work,int noffset)

{
  work *work;
  
  work = make_work();
  _copy_work(work,base_work,noffset);
  return work;
}

