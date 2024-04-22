
int tls1_process_heartbeat(undefined4 *param_1)

{
  char cVar1;
  char cVar2;
  undefined *ptr;
  int iVar3;
  char *pcVar4;
  uint __n;
  uint num;
  
  iVar3 = param_1[0x16];
  pcVar4 = *(char **)(iVar3 + 0x118);
  if ((code *)param_1[0x19] != (code *)0x0) {
    (*(code *)param_1[0x19])
              (0,*param_1,0x18,pcVar4,*(undefined4 *)(iVar3 + 0x110),param_1,param_1[0x1a]);
    iVar3 = param_1[0x16];
  }
  if (0x12 < *(uint *)(iVar3 + 0x110)) {
    cVar1 = pcVar4[1];
    cVar2 = pcVar4[2];
    __n = (uint)CONCAT11(cVar1,cVar2);
    num = __n + 0x13;
    if (num <= *(uint *)(iVar3 + 0x110)) {
      if (*pcVar4 == '\x01') {
        ptr = (undefined *)CRYPTO_malloc(num,DAT_00073378,0xf0d);
        *ptr = 2;
        ptr[1] = cVar1;
        ptr[2] = cVar2;
        memcpy(ptr + 3,pcVar4 + 3,__n);
        iVar3 = RAND_pseudo_bytes(ptr + 3 + __n,0x10);
        if (iVar3 < 0) {
          CRYPTO_free(ptr);
          return -1;
        }
        iVar3 = ssl3_write_bytes(param_1,0x18,ptr,num);
        if (-1 < iVar3) {
          if ((code *)param_1[0x19] != (code *)0x0) {
            (*(code *)param_1[0x19])(1,*param_1,0x18,ptr,num,param_1,param_1[0x1a]);
          }
          CRYPTO_free(ptr);
          return 0;
        }
        CRYPTO_free(ptr);
        return iVar3;
      }
      if (*pcVar4 == '\x02') {
        if ((__n == 0x12) && (param_1[99] == (uint)CONCAT11(pcVar4[3],pcVar4[4]))) {
          param_1[99] = param_1[99] + 1;
          param_1[0x62] = 0;
          return 0;
        }
      }
    }
  }
  return 0;
}

