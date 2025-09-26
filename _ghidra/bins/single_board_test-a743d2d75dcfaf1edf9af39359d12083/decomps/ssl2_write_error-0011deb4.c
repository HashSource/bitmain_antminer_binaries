
void ssl2_write_error(undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 auStack_15 [5];
  
  uVar2 = param_1[0x35];
  local_16 = (undefined1)param_1[0x36];
  local_18 = 0;
  param_1[0x35] = 0;
  local_17 = (undefined1)((uint)param_1[0x36] >> 8);
  if (3 < uVar2) {
    OpenSSLDie("s2_lib.c",0x216,"error >= 0 && error <= (int)sizeof(buf)");
  }
  iVar1 = ssl2_write(param_1,auStack_15 + -uVar2,uVar2);
  if (iVar1 < 0) {
    param_1[0x35] = uVar2;
  }
  else {
    param_1[0x35] = uVar2 - iVar1;
    if ((uVar2 - iVar1 == 0) && ((code *)param_1[0x19] != (code *)0x0)) {
      (*(code *)param_1[0x19])(1,*param_1,0,&local_18,3,param_1,param_1[0x1a]);
    }
  }
  return;
}

