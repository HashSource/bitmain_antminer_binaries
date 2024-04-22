
/* WARNING: Unknown calling convention */

int thr_info_create(thr_info *thr,pthread_attr_t *attr,_func_void_ptr_void_ptr *start,void *arg)

{
  int iVar1;
  
  _cgsem_init(&thr->sem,"util.c",DAT_00012478,0x4a7);
                    /* WARNING: Could not recover jumptable at 0x0000a35c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_LAB_0005f258)(&thr->pth,attr,start,arg);
  return iVar1;
}

