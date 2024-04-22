
int dtls1_process_heartbeat(undefined4 *param_1)

{
  char cVar1;
  char cVar2;
  undefined *ptr;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  uint __n;
  uint num;
  
  iVar3 = param_1[0x16];
  pcVar5 = *(char **)(iVar3 + 0x118);
  if ((code *)param_1[0x19] != (code *)0x0) {
    (*(code *)param_1[0x19])
              (0,*param_1,0x18,pcVar5,*(undefined4 *)(iVar3 + 0x110),param_1,param_1[0x1a]);
    iVar3 = param_1[0x16];
  }
  uVar4 = *(uint *)(iVar3 + 0x110);
  if ((0x12 < uVar4) && (uVar4 < 0x4001)) {
    cVar1 = pcVar5[1];
    cVar2 = pcVar5[2];
    __n = (uint)CONCAT11(cVar1,cVar2);
    num = __n + 0x13;
    if (num <= uVar4) {
      if (*pcVar5 == '\x01') {
        ptr = (undefined *)CRYPTO_malloc(num,DAT_00079410,0x596);
        *ptr = 2;
        ptr[1] = cVar1;
        ptr[2] = cVar2;
        memcpy(ptr + 3,pcVar5 + 3,__n);
        iVar3 = RAND_pseudo_bytes(ptr + 3 + __n,0x10);
        if (-1 < iVar3) {
          iVar3 = dtls1_write_bytes(param_1,0x18,ptr,num);
          if (-1 < iVar3) {
            if ((code *)param_1[0x19] != (code *)0x0) {
              (*(code *)param_1[0x19])(1,*param_1,0x18,ptr,num,param_1,param_1[0x1a]);
            }
            iVar3 = 0;
          }
          CRYPTO_free(ptr);
          return iVar3;
        }
        CRYPTO_free(ptr);
        return -1;
      }
      if (*pcVar5 == '\x02') {
        if ((__n == 0x12) && (param_1[99] == (uint)CONCAT11(pcVar5[3],pcVar5[4]))) {
          dtls1_stop_timer(param_1);
          param_1[0x62] = 0;
          param_1[99] = param_1[99] + 1;
          return 0;
        }
      }
    }
  }
  return 0;
}

