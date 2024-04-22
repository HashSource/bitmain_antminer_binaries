
/* WARNING: Unknown calling convention */

uchar set_iic(uint data)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_0002cc74;
  *(uint *)(*(int *)(DAT_0002cc74 + 0x8d4) + 0x30) = data & 0x7fffffff;
  do {
    usleep(1000);
    iVar2 = *(int *)(*(int *)(iVar1 + 0x8d4) + 0x30);
  } while (-1 < iVar2);
  return (uchar)iVar2;
}

