
void ssl_prf_md(void)

{
  undefined4 extraout_r2;
  undefined4 in_r3;
  undefined8 uVar1;
  
  uVar1 = ssl_get_algorithm2();
  ssl_md((int)uVar1 >> 8,(int)((ulonglong)uVar1 >> 0x20),extraout_r2,in_r3);
  return;
}

