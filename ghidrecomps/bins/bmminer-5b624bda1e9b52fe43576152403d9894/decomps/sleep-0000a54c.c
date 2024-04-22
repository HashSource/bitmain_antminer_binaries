
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint sleep(uint __seconds)

{
  uint uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0000a554. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)PTR_LAB_0005f2f8)();
  return uVar1;
}

