
ushort Curl_ipv6_scope(short *param_1)

{
  ushort uVar1;
  ushort uVar2;
  
  if (*param_1 == 10) {
    uVar1 = CONCAT11(*(undefined *)(param_1 + 4),*(byte *)((int)param_1 + 9));
    uVar2 = uVar1 & 0xffc0;
    if (uVar2 == 0xfe80) {
      return 1;
    }
    if (uVar2 == 0xfec0) {
      return 2;
    }
    if ((uVar1 & 0xffc0) == 0) {
      if ((byte)(*(byte *)(param_1 + 0xb) |
                *(byte *)(param_1 + 5) | *(byte *)((int)param_1 + 9) | *(byte *)((int)param_1 + 0xb)
                | *(byte *)(param_1 + 6) | *(byte *)((int)param_1 + 0xd) | *(byte *)(param_1 + 7) |
                *(byte *)((int)param_1 + 0xf) | *(byte *)(param_1 + 8) |
                *(byte *)((int)param_1 + 0x11) | *(byte *)(param_1 + 9) |
                *(byte *)((int)param_1 + 0x13) | *(byte *)(param_1 + 10) |
                *(byte *)((int)param_1 + 0x15)) != 0) {
        return uVar2;
      }
      if (*(char *)((int)param_1 + 0x17) != '\x01') {
        return 0;
      }
      return 3;
    }
  }
  return 0;
}

