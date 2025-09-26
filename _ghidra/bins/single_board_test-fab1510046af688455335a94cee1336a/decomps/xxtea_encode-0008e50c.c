
void xxtea_encode(uint32_t *v,uint32_t n,uint32_t *key)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint32_t *key_local;
  uint32_t n_local;
  uint32_t *v_local;
  char time_stamp [48];
  char tmp1 [2048];
  uint32_t y;
  uint32_t e;
  uint32_t rounds;
  uint32_t p;
  uint32_t sum;
  uint32_t z;
  
  if (n < 2) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s:  xxtea encode input data length <= 1\n","xxtea_encode");
    builtin_strncpy(tmp1," xxtea encode input data length <= 1",0x24);
    tmp1[0x24] = '\0';
    log_to_file(tmp1,time_stamp);
  }
  else {
    iVar1 = __aeabi_uidiv(0x34,n);
    rounds = iVar1 + 6;
    sum = 0;
    z = v[n + 0x3fffffff];
    do {
      sum = sum + 0x9e3779b9;
      uVar2 = sum >> 2 & 3;
      for (p = 0; p < n - 1; p = p + 1) {
        uVar3 = v[p + 1];
        v[p] = ((z ^ key[uVar2 ^ p & 3]) + (sum ^ uVar3) ^
               (z >> 5 ^ uVar3 << 2) + (z << 4 ^ uVar3 >> 3)) + v[p];
        z = v[p];
      }
      uVar3 = *v;
      v[n + 0x3fffffff] =
           ((z ^ key[uVar2 ^ p & 3]) + (sum ^ uVar3) ^ (z >> 5 ^ uVar3 << 2) + (z << 4 ^ uVar3 >> 3)
           ) + v[n + 0x3fffffff];
      z = v[n + 0x3fffffff];
      rounds = rounds - 1;
    } while (rounds != 0);
  }
  return;
}

