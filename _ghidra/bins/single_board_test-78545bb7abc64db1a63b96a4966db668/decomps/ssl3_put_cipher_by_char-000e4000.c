
int ssl3_put_cipher_by_char(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  
  if ((*(uint *)(param_1 + 0xc) & 0xff000000) == 0x3000000) {
    iVar1 = WPACKET_put_bytes__(param_2,param_2,*(uint *)(param_1 + 0xc) & 0xffff,0,2);
    if (iVar1 != 0) {
      *param_3 = 2;
      return 1;
    }
  }
  else {
    iVar1 = 1;
    *param_3 = 0;
  }
  return iVar1;
}

