
/* WARNING: Unknown calling convention */

int thr_info_create(thr_info *thr,pthread_attr_t *attr,_func_void_ptr_void_ptr *start,void *arg)

{
  int iVar1;
  undefined4 unaff_lr;
  
  _cgsem_init(&thr->sem,"util.c","thr_info_create",0x4a7);
  iVar1 = (*(code *)(undefined *)0x0)(&thr->pth,attr,start,arg,unaff_lr);
  return iVar1;
}

