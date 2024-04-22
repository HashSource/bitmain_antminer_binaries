
undefined4 ssl3_send_cert_status(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined *puVar3;
  
  if (*(int *)(param_1 + 0x34) == 0x2200) {
    iVar2 = BUF_MEM_grow(*(BUF_MEM **)(param_1 + 0x3c),*(int *)(param_1 + 0x13c) + 8);
    if (iVar2 == 0) {
      *(undefined4 *)(param_1 + 0x34) = 5;
      return 0xffffffff;
    }
    puVar3 = *(undefined **)(*(int *)(param_1 + 0x3c) + 4);
    *puVar3 = 0x16;
    puVar3[1] = (char)((uint)(*(int *)(param_1 + 0x13c) + 4) >> 0x10);
    puVar3[2] = (char)((uint)(*(int *)(param_1 + 0x13c) + 4) >> 8);
    puVar3[3] = (char)*(undefined4 *)(param_1 + 0x13c) + '\x04';
    puVar3[4] = (char)*(undefined4 *)(param_1 + 0x128);
    puVar3[5] = (char)*(undefined2 *)(param_1 + 0x13e);
    puVar3[6] = (char)((uint)*(undefined4 *)(param_1 + 0x13c) >> 8);
    puVar3[7] = (char)*(undefined4 *)(param_1 + 0x13c);
    memcpy(puVar3 + 8,*(void **)(param_1 + 0x138),*(size_t *)(param_1 + 0x13c));
    *(undefined4 *)(param_1 + 0x34) = 0x2201;
    *(undefined4 *)(param_1 + 0x48) = 0;
    *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x13c) + 8;
  }
  uVar1 = ssl3_do_write(param_1,0x16);
  return uVar1;
}

