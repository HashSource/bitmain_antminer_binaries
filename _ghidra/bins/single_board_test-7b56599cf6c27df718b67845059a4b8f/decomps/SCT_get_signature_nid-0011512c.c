
undefined4 SCT_get_signature_nid(int *param_1)

{
  undefined4 uVar1;
  
  if (*param_1 != 0) {
    return 0;
  }
  if ((char)param_1[10] != '\x04') {
    return 0;
  }
  if (*(char *)((int)param_1 + 0x29) != '\x01') {
    uVar1 = 0x31a;
    if (*(char *)((int)param_1 + 0x29) != '\x03') {
      uVar1 = 0;
    }
    return uVar1;
  }
  return 0x29c;
}

