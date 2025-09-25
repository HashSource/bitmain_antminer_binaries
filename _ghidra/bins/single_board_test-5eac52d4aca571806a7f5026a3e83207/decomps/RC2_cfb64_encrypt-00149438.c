
void RC2_cfb64_encrypt(uchar *in,uchar *out,long length,RC2_KEY *schedule,uchar *ivec,int *num,
                      int enc)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  ulong local_30;
  undefined4 uStack_2c;
  
  uVar3 = *num;
  if (enc == 0) {
    if (length != 0) {
      do {
        if (uVar3 == 0) {
          local_30 = *(ulong *)ivec;
          uStack_2c = *(undefined4 *)(ivec + 4);
          RC2_encrypt(&local_30,schedule);
          *ivec = (uchar)local_30;
          ivec[4] = (uchar)uStack_2c;
          ivec[1] = (uchar)(local_30 >> 8);
          ivec[2] = (uchar)(local_30 >> 0x10);
          ivec[3] = (uchar)(local_30 >> 0x18);
          ivec[5] = (uchar)((uint)uStack_2c >> 8);
          ivec[6] = (uchar)((uint)uStack_2c >> 0x10);
          ivec[7] = (uchar)((uint)uStack_2c >> 0x18);
        }
        bVar1 = ivec[uVar3];
        length = length + -1;
        bVar2 = *in;
        ivec[uVar3] = bVar2;
        uVar3 = uVar3 + 1 & 7;
        *out = bVar1 ^ bVar2;
        in = in + 1;
        out = out + 1;
      } while (length != 0);
    }
  }
  else if (length != 0) {
    do {
      if (uVar3 == 0) {
        local_30 = *(ulong *)ivec;
        uStack_2c = *(undefined4 *)(ivec + 4);
        RC2_encrypt(&local_30,schedule);
        *ivec = (uchar)local_30;
        ivec[4] = (uchar)uStack_2c;
        ivec[1] = (uchar)(local_30 >> 8);
        ivec[2] = (uchar)(local_30 >> 0x10);
        ivec[3] = (uchar)(local_30 >> 0x18);
        ivec[5] = (uchar)((uint)uStack_2c >> 8);
        ivec[6] = (uchar)((uint)uStack_2c >> 0x10);
        ivec[7] = (uchar)((uint)uStack_2c >> 0x18);
      }
      bVar1 = ivec[uVar3];
      length = length + -1;
      bVar2 = *in;
      *out = bVar1 ^ bVar2;
      ivec[uVar3] = bVar1 ^ bVar2;
      uVar3 = uVar3 + 1 & 7;
      in = in + 1;
      out = out + 1;
    } while (length != 0);
  }
  *num = uVar3;
  return;
}

