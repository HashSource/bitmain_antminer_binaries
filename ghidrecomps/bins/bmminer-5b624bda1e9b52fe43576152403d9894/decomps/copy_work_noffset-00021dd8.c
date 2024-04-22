
/* WARNING: Unknown calling convention */

work * copy_work_noffset(work *base_work,int noffset)

{
  work *work_00;
  work *work;
  
  work_00 = make_work();
  _copy_work(work_00,base_work,noffset);
  return work_00;
}

