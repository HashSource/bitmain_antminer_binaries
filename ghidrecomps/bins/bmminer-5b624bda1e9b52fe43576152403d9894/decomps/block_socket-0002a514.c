
/* WARNING: Unknown calling convention */

void block_socket(int fd)

{
  uint uVar1;
  int flags;
  
  uVar1 = fcntl(fd,3,0);
                    /* WARNING: Could not recover jumptable at 0x0000a5c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_LAB_0005f31c)(fd,4,uVar1 & 0xfffff7ff);
  return;
}

