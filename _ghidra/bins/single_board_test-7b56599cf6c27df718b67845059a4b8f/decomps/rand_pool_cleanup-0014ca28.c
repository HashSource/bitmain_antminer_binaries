
void rand_pool_cleanup(void)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  stat local_70;
  
  piVar2 = (int *)random_devices;
  do {
    if ((((*piVar2 != -1) && (iVar1 = __fxstat(3,*piVar2,&local_70), iVar1 != -1)) &&
        (piVar2[3] == local_70.st_dev._4_4_ && piVar2[2] == (int)local_70.st_dev)) &&
       (((piVar2[4] == local_70.st_ino && (((local_70.st_mode ^ piVar2[5]) & 0xfffffe00) == 0)) &&
        (piVar2[7] == local_70.st_rdev._4_4_ && piVar2[6] == (int)local_70.st_rdev)))) {
      close(*piVar2);
    }
    piVar3 = piVar2 + 8;
    *piVar2 = -1;
    piVar2 = piVar3;
  } while (piVar3 != (int *)&m_7250);
  return;
}

