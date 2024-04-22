
undefined4 file_disconnect(int *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(*param_1 + 0x14c);
  if (puVar1 != (undefined4 *)0x0) {
    (**DAT_00059d54)(puVar1[1]);
    puVar1[1] = 0;
    *puVar1 = 0;
    if (puVar1[2] != -1) {
      close(puVar1[2]);
    }
    puVar1[2] = 0xffffffff;
  }
  return 0;
}

