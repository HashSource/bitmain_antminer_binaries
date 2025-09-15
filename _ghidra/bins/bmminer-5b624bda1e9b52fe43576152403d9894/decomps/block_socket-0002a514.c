
/* WARNING: Unknown calling convention */

void block_socket(int fd)

{
  uint uVar1;
  undefined4 extraout_r3;
  undefined4 unaff_lr;
  
  uVar1 = fcntl(fd,3,0);
  (*(code *)(undefined *)0x0)(fd,4,uVar1 & 0xfffff7ff,extraout_r3,unaff_lr);
  return;
}

