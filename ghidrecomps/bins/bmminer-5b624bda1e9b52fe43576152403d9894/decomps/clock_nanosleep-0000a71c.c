
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int clock_nanosleep(clockid_t __clock_id,int __flags,timespec *__req,timespec *__rem)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0000a724. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_LAB_0005f38c)();
  return iVar1;
}

