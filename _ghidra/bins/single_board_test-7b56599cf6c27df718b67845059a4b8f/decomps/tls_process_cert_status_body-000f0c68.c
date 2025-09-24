
undefined4 tls_process_cert_status_body(int param_1,int *param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  void *__dest;
  char *pcVar5;
  int iVar6;
  undefined4 uVar7;
  uint __n;
  undefined4 uVar8;
  
  iVar6 = param_2[1];
  if (iVar6 != 0) {
    pcVar5 = (char *)*param_2;
    cVar4 = *pcVar5;
    param_2[1] = iVar6 - 1U;
    *param_2 = (int)(pcVar5 + 1);
    if (cVar4 == '\x01') {
      if (2 < iVar6 - 1U) {
        bVar1 = pcVar5[2];
        bVar2 = pcVar5[1];
        bVar3 = pcVar5[3];
        param_2[1] = iVar6 - 4U;
        *param_2 = (int)(pcVar5 + 4);
        __n = (uint)bVar1 << 8 | (uint)bVar2 << 0x10 | (uint)bVar3;
        if (__n == iVar6 - 4U) {
          __dest = CRYPTO_malloc(__n,"ssl/statem/statem_clnt.c",0xadb);
          *(void **)(param_1 + 0x554) = __dest;
          if (__dest == (void *)0x0) {
            *(undefined4 *)(param_1 + 0x558) = 0;
            ossl_statem_fatal(param_1,0x50,0x1ef,0x41,"ssl/statem/statem_clnt.c",0xadf);
            return 0;
          }
          *(uint *)(param_1 + 0x558) = __n;
          if ((uint)param_2[1] < __n) {
            ossl_statem_fatal(param_1,0x32,0x1ef,0x9f,"ssl/statem/statem_clnt.c",0xae5);
            return 0;
          }
          memcpy(__dest,(void *)*param_2,__n);
          *param_2 = *param_2 + __n;
          param_2[1] = param_2[1] - __n;
          return 1;
        }
      }
      uVar8 = 0xad8;
      uVar7 = 0x9f;
      goto LAB_000f0c98;
    }
  }
  uVar8 = 0xad2;
  uVar7 = 0x149;
LAB_000f0c98:
  ossl_statem_fatal(param_1,0x32,0x1ef,uVar7,"ssl/statem/statem_clnt.c",uVar8);
  return 0;
}

