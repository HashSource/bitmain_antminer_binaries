
void xxtea_decode(uint32_t *v,uint32_t n,uint32_t *key)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint32_t *key_local;
  uint32_t n_local;
  uint32_t *v_local;
  char time_stamp [48];
  char tmp1 [2048];
  uint32_t z;
  uint32_t e;
  uint32_t rounds;
  uint32_t p;
  uint32_t sum;
  uint32_t y;
  
  if (n < 2) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s:  xxtea decode input data length <= 1\n","xxtea_decode");
    builtin_strncpy(tmp1," xxtea decode input data length <= 1",0x24);
    tmp1[0x24] = '\0';
    log_to_file(tmp1,time_stamp);
  }
  else {
    iVar1 = __aeabi_uidiv(0x34,n);
    rounds = iVar1 + 6;
    sum = rounds * -0x61c88647;
    y = *v;
    do {
      uVar2 = sum >> 2 & 3;
      for (p = n - 1; p != 0; p = p - 1) {
        uVar3 = v[p + 0x3fffffff];
        v[p] = v[p] - ((uVar3 ^ key[uVar2 ^ p & 3]) + (sum ^ y) ^
                      (uVar3 >> 5 ^ y << 2) + (uVar3 << 4 ^ y >> 3));
        y = v[p];
      }
      uVar3 = v[n + 0x3fffffff];
      *v = *v - ((uVar3 ^ key[uVar2]) + (sum ^ y) ^ (uVar3 >> 5 ^ y << 2) + (uVar3 << 4 ^ y >> 3));
      y = *v;
      sum = sum + 0x61c88647;
      rounds = rounds - 1;
    } while (rounds != 0);
  }
  return;
}

