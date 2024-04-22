
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int putchar(int __c)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0000a140. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_LAB_0005f1ac)();
  return iVar1;
}

